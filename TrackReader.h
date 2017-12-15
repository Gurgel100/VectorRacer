/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TrackReader.h
 * Author: dario
 *
 * Created on December 8, 2017, 11:28 AM
 */
#include <vector>
#include <string>
#include "Map.h"

#ifndef TRACKREADER_H
#define TRACKREADER_H

class TrackReader
{
public:
    TrackReader(const std::string& mapName);
    ~TrackReader();
    Map TrackReader::getMap();
    void TrackReader::changeMap(const std::string& mapName);
private:
    Map trackMap;
    char fileName[]; 
    int imgHeight;
    int imgWidth;
    bool isNew;
    void readTrack();
};

#endif /* TRACKREADER_H */

