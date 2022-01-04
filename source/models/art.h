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

   ------------------------------------------------------------------------------------

   The Art class allows an album to be stored and given art. The subclass location
   stores information on  a particular location for the art.

*/

#ifndef ART_H
#define ART_H


#include <QDebug>
#include <QPointer>


class Location; //Forward Declaration

class Art : public QObject
{
    Q_OBJECT


public:
    explicit Art(QObject *parent = nullptr);
    ~Art();

    void updateArtDetails(const QString& albumArtist, const QString& album, int size);
    void addLocation(const QString& path, const QString& relationship, bool hasExistingArt);
    void deleteLocations();


    QStringList pathList();
    QStringList relationshipList();
    QList<bool> hasExistingArtList();
    QList<bool> isApprovedList();
    QList<bool> isSavedList();

    QString getAlbumArtist();
    void setAlbumArtist(const QString& albumArtist);

    QString getAlbum();
    void setAlbum(const QString& album);

    int getSize();
    void setSize(int size);
    

    QString getFinalPath();
    void setFinalPath(const QString& finalPath);

    QString getTempPath();
    void setTempPath(const QString& tempPath);

    QString getSacadCommand();
    void setSacadCommand(const QString& sacadCommand);

    QStringList getSacadCommandOptionsList();
    void setSacadCommandOptionsList(const QStringList& sacadCommandOptionsList);

    int locationCount();

    QPointer<Location> location(int i);

private:
    QString _albumArtist;
    QString _album;
    int _size;
    QString _finalPath;
    QString _tempPath;

    QList<QPointer<Location>> _locations;

    QString sacadCommand;
    QStringList sacadCommandOptionsList;

};

class Location : public QObject
{
    Q_OBJECT

public:
    explicit Location(QObject *parent = nullptr);

    QString getPath();
    void setPath(const QString& path);

    QString getRelationship();
    void setRelationship(const QString& relationship);

    bool hasExistingArt();
    void setHasExistingArt(bool hasExistingArt);

    bool isApproved();
    void setIsApproved(bool isApproved);

    bool isProcessed();
    void setIsProcessed(bool isProcessed);

    bool isSaved();
    void setIsSaved(bool isSaved);

 private:
    QString _path;
    QString _relationship;
    bool _hasExistingArt;
    bool _isApproved = false;
    bool _isProcessed = false;
    bool _isSaved = false;

};

#endif

