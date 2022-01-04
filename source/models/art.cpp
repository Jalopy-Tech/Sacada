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

#include "art.h"

#include <QList>

Art::Art(QObject *parent)
    : QObject(parent)
{
 
}

Art::~Art()
{
    deleteLocations();
}

QString Art::getAlbumArtist() { return _albumArtist; }
void Art::setAlbumArtist(const QString& albumArtist) { _albumArtist = albumArtist; }

QString Art::getAlbum() { return _album; }
void Art::setAlbum(const QString& album) { _album = album; }


int Art::getSize() { return _size; }
void Art::setSize(int size) { _size = size; }

QString Art::getFinalPath() { return _finalPath; }
void Art::setFinalPath(const QString& finalPath) { _finalPath = finalPath; }

QString Art::getTempPath() { return _tempPath; }
void Art::setTempPath(const QString& tempPath) { _tempPath = tempPath; }

QString Art::getSacadCommand() { return sacadCommand; }
void Art::setSacadCommand(const QString& sacadCommand) { this->sacadCommand = sacadCommand; }

QStringList Art::getSacadCommandOptionsList() { return sacadCommandOptionsList; }

void Art::setSacadCommandOptionsList(const QStringList& sacadCommandOptionsList)
{
    this->sacadCommandOptionsList = sacadCommandOptionsList;
}

int Art::locationCount() { return _locations.size(); }

void Art::updateArtDetails(const QString& albumArtist, const QString& album, int size)
{

    // Update the member fields.

    _albumArtist = albumArtist;
    _album = album;
    _size = size;
}

QPointer<Location> Art::location(int i) { return _locations[i]; }


void Art::addLocation(const QString& path, const QString& relationship, bool hasExistingArt)
{

    Location *location = new Location(this);
    location->setPath(path);
    location->setRelationship(relationship);
    location->setHasExistingArt(hasExistingArt);

    _locations << location;
}

void Art::deleteLocations()
{
    for (int i = 0; i < _locations.size(); ++i)
        _locations[i]->deleteLater();

    _locations = QList<QPointer<Location>>();

}

QStringList Art::pathList()
{
    QStringList list;
        for (int i = 0; i < _locations.size(); ++i)
            list << _locations[i]->getPath();


   return list;
}

QStringList Art::relationshipList()
{
    QStringList list;
        for (int i = 0; i < _locations.size(); ++i)
            list << _locations[i]->getRelationship();

   return list;

}

QList<bool> Art::hasExistingArtList()
{
    QList<bool> list;
        for (int i = 0; i < _locations.size(); ++i)
            list << _locations[i]->hasExistingArt();

   return list;

}

QList<bool> Art::isApprovedList()
{
    QList<bool> list;
        for (int i = 0; i < _locations.size(); ++i)
            list << _locations[i]->isApproved();

   return list;

}

QList<bool> Art::isSavedList()
{
    QList<bool> list;
        for (int i = 0; i < _locations.size(); ++i)
            list << _locations[i]->isSaved();

   return list;

}



Location::Location(QObject *parent)
    : QObject(parent)
{

}


QString Location::getPath() { return _path; }
void Location::setPath(const QString& path) { _path = path; }

QString Location::getRelationship() { return _relationship; }
void Location::setRelationship(const QString& relationship)  { _relationship = relationship; }

bool Location::hasExistingArt()  { return _hasExistingArt; }
void Location::setHasExistingArt(bool hasExistingArt) { _hasExistingArt = hasExistingArt; }

bool Location::isApproved()  { return _isApproved; }
void Location::setIsApproved(bool isApproved) { _isApproved = isApproved; }

bool Location::isProcessed()  { return _isProcessed; }
void Location::setIsProcessed(bool isProcessed) { _isProcessed = isProcessed; }

bool Location::isSaved() { return _isSaved; }
void Location::setIsSaved(bool isSaved)  { _isSaved = isSaved; }
