/*
    Copyright (C) 2020 Robert J. Joynt.

    This software uses the QT (https://www.qt.io/) GPLv3 Open Source License
    (https://doc.qt.io/qt-5/gpl.html).

    This software is distributed under the GNU General Public License Version 3.

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    (https://www.gnu.org/licenses/).
*/

#include "controller.h"

Controller::Controller(QObject *parent)
    : QObject(parent)
{
    QCommandLineParser parser;

  // Set up the parser.

    parser.setApplicationDescription("Find album art using SACAD(Smart Automatic Cover Art Downloader) with a GUI front end.");

     // Set up the various command options allowed in the parser.

    const QCommandLineOption helpOption = parser.addHelpOption();
    const QCommandLineOption versionOption = parser.addVersionOption();

    const QCommandLineOption albumArtistOption(QStringList() << "a" << "artist",
           "Specify album artist.", "albumArtist");
    parser.addOption(albumArtistOption);

    const QCommandLineOption albumOption(QStringList() << "l" << "album",
          "Specify album.", "album");
    parser.addOption(albumOption);

    const QCommandLineOption sizeOption(QStringList() << "s" << "size",
          "Specify size in pixels.", "size");
    parser.addOption(sizeOption);

    const QCommandLineOption finalPathOption(QStringList() << "i" << "image",
          "Specify path to save album art image file.", "finalPath");
    parser.addOption(finalPathOption);

    const QCommandLineOption noGuiOption(QStringList() << "n" << "no-gui",
          "The output will be displayed to the console, not using a GUI.");
    parser.addOption(noGuiOption);

    const QCommandLineOption wineOption(QStringList() << "w" << "wine",
          "The album art path is a WINE (Windows) path and will be converted using winepath.");
    parser.addOption(wineOption);

    const QCommandLineOption sacadPathOption (QStringList() << "p" << "sacad-path",
          "Specify the full sacad command path.","sacadPath");
    parser.addOption(sacadPathOption);

    const QCommandLineOption sacadOptionOption(QStringList() << "o" << "sacad-option",
        "Specify sacad command options. Split arguments (with quotes) into separate options "  \
        " incuding the splitting of options with arguments. eg. -o \"-v\" -o \"quiet\""  \
          ,"sacadCommand");

    parser.addOption(sacadOptionOption);

    // Parce the parser to extract all the command line options.

    bool fParseError = !parser.parse(QCoreApplication::arguments());

    // Assign all the command line options to variables.

    bool hasHelpOption = parser.isSet(helpOption);
    bool hasVersionOption = parser.isSet(versionOption);
    bool hasNoGui = parser.isSet(noGuiOption);

    _albumArtist = parser.value(albumArtistOption);
    _album = parser.value(albumOption);
    _size = parser.value(sizeOption).toInt();

    if (_size == 0)
      _size = DEFAULT_SIZE;

    _finalPath = parser.value(finalPathOption);
    _isWineFile = parser.isSet(wineOption);

    _sacadOptionPath = parser.value(sacadPathOption);
    _sacadCommandOptionsList = parser.values(sacadOptionOption);

    if (_isWineFile)
    {
      QString command = "winepath";
      QStringList arguments;
      arguments << "-u" << _finalPath;

      QProcess winepathProcess;
      winepathProcess.start(command, arguments);
      winepathProcess.waitForFinished(10000);


      QByteArray output = winepathProcess.readAllStandardOutput();
      _finalPath = output;
      _finalPath = _finalPath.simplified();
    }


    if (_finalPath.isEmpty())
      _finalPath = "cover.jpg";
    else if (QFileInfo::exists(_finalPath) && not(QFileInfo(_finalPath).isFile()))
      _finalPath = _finalPath + "/cover.jpg";


    _finalPath = QFileInfo(_finalPath).QFileInfo::absoluteFilePath();


    // construct the view

    if (hasNoGui || hasHelpOption || hasVersionOption)
     _view = new ConsoleView();
    else
     _view = new GuiView();

    // Check if the parser had errors or requested help or verion

    if (fParseError) {
        _view->showError(parser.errorText());
        _view->setExecutable(false);
    } else if (hasHelpOption) {
         _view->showInformation(parser.helpText());
         _view->setExecutable(false);
    } else if (hasVersionOption) {
       QString versionText = QString("") + \
           QCoreApplication::applicationName() + " " + \
           QCoreApplication::applicationVersion();

       _view->showInformation(versionText);
       _view->setExecutable(false);
    } else {

        _view->setAlbumDetails(_albumArtist, _album, _size, _finalPath);
        setSacadFilePath();
        _view->setSacadCommand(_sacadFilePath);
        _view->setSacadCommandOptionsList(_sacadCommandOptionsList);
    }
}


Controller::~Controller()
{
    delete (_view);
}

View* Controller::view()
{
    return _view;
}

void Controller::setSacadFilePath() {

    bool fFound = false;
    QStringList filters;
    filters << "sacad*";

    if (_sacadOptionPath != "") {

        // Check the sacad path set in the command options. If
        // it exists, set it as the sacad command

        QFileInfo sacadOptionPathFileInfo(_sacadOptionPath);
        if (sacadOptionPathFileInfo.exists()) {

           // Check if the sacad path is file or directory

           if (sacadOptionPathFileInfo.isFile()) {

               // Check if the sacad path file is executable

               if (!sacadOptionPathFileInfo.isExecutable()) {
                   QString msg = QString("") + "The sacad command specified using the options -p or --sacad-path " +
                           " is not an exectable command. The command given was:\n\n" + \
                          _sacadOptionPath;

                   _view->showError(msg);
                   _view->setExecutable(false);
                } else {
                    _sacadFilePath = _sacadOptionPath;
                    fFound = true;

                }
            } else {

               // Check if the sacad path directory contains an executable

               QStringList paths;
               paths << _sacadOptionPath;
               QString filePath = QStandardPaths::findExecutable( "sacad", paths);
               if (filePath == "") {
                   QString msg = QString("") + "The sacad command specified using the options -p or --sacad-path " +
                           " does not contain an exectable sacad command. The path given was:\n\n" + \
                          _sacadOptionPath;

                   _view->showError(msg);
                   _view->setExecutable(false);

               } else {
                   _sacadFilePath = filePath;
                   fFound = true;
               }
           }

       } else {
           QString msg = QString("") + "The sacad command specified using the options -p or --sacad-path " +
                   " does not exist. The command given was:\n\n" + \
                  _sacadOptionPath;

           _view->showError(msg);
           _view->setExecutable(false);
       }

    }

    // Check if the Sacad command is in the application directory or one of its
    // children, or siblings.
    // If the parent starts with "sacada", add the grandparent and its children.

    if (!fFound) {
         QStringList paths;

        // Add all the application directory itself to the seach path

        paths << QCoreApplication::applicationDirPath();


        // Add all the children dirs to the search paths

        QDir dir(QCoreApplication::applicationDirPath());

        dir.setNameFilters(filters);

        QFileInfoList dirList;
        dirList = dir.entryInfoList(filters, QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
        if (!dirList.isEmpty())
           for( int i = 0 ; i < dirList.count(); ++i )
                paths << dirList[i].absoluteFilePath();


        // Add all the silbling dirs to the search paths

        QDir parentDir(QCoreApplication::applicationDirPath() + "/..");
        if (parentDir.exists()) {
            paths << parentDir.absolutePath();
            QFileInfoList parentDirList;
            parentDirList = parentDir.entryInfoList(filters, QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
            if (!parentDirList.isEmpty())
                for( int i = 0 ; i < parentDirList.count(); ++i )
                    paths << parentDirList[i].absoluteFilePath();


            // if the parent directory starts with "sacada",
            // add its parent directory (the granbdparent) and all of its
            // siblings (the grandparent's children) to the search paths

            QFileInfo parentFileInfo(parentDir.absolutePath());
            if (parentFileInfo.fileName().startsWith("sacada", Qt::CaseInsensitive)) {

                // get the grandparent directory

                QDir grandParentDir(QCoreApplication::applicationDirPath() + "/../..");
                if (grandParentDir.exists()) {

                    // Add the grandparent directory to the search path

                    paths << grandParentDir.absolutePath();
                    QFileInfoList grandParentDirList;

                    // Add all the grandparent's chidlren to the search path

                    grandParentDirList = grandParentDir.entryInfoList(filters, QDir::Dirs | QDir::NoDotAndDotDot, QDir::Name);
                    if (!grandParentDirList.isEmpty())
                        for( int i = 0 ; i < grandParentDirList.count(); ++i )
                            paths << grandParentDirList[i].absoluteFilePath();
                }
            }
        }

       // Search the paths that were set to find the sacad command

        QString filePath = QStandardPaths::findExecutable("sacad", paths);

        if (filePath != "") {
            _sacadFilePath = filePath;
            fFound = true;
        }


        // The findExecutable function doesn't search in /usr/local/bin, etc on macOS, so do a manual search

         #ifdef Q_OS_MACX
         if (!fFound) {
            QStringList dirList;
            dirList.append("/usr/local/bin");
            dirList.append("/usr/local/sbin");
            dirList.append("/usr/bin");
            dirList.append("/usr/sbin");
            QString filePath = QStandardPaths::findExecutable("sacad", dirList);

          if (filePath != "") {
              _sacadFilePath = filePath;
              fFound = true;
          }
        }
        #endif




    }

    // Search for the sacad command in the standard paths set by the operating system

    if (!fFound) {


      QString filePath = QStandardPaths::findExecutable("sacad");
      if (filePath != "") {
          _sacadFilePath = filePath;
          fFound = true;
      }
    }

    // Sacad command not found, so show error

    if (!fFound)
       {
        QString appPath = QDir::toNativeSeparators(QCoreApplication::applicationDirPath());
        QString msg = QString("") + "The executable command \"sacad\" cannot be found." + \
                " It needs to be in:\n\n" + \
                "  A subfolder of this application's folder\n" + \
                "  with the name starting with sacad.\n" + \
                "\n    OR \n\n" + \
                "  This application's folder.\n" + \
                "\n    OR \n\n" + \
                "  The standard paths of the operating system." + \
                "\n\n(Note that this application's folder is:\n" + appPath + " )" + \
                "";


        _view->showError(msg);
        _view->setExecutable(false);


        }

    if (!fFound)
        _isValid = false;
}


