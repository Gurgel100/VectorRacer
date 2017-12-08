/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TrackReader.cpp
 * Author: dario
 * 
 * Created on December 8, 2017, 11:28 AM
 */

#include "TrackReader.h"
#include <iostream>
#include <fstream>
#include <cstdio>
#include "BitmapImage.h"

using namespace std;

TrackReader::TrackReader(const string& mapName)
{
    imgHeight = 0;
    imgWidth = 0;
    changeMap(mapName);
}

TrackReader::~TrackReader()
{
    delete Map;
}

Map TrackReader::getMap()
{
    if (isNew)
    {
        if (trackMap) delete trackMap;
        trackMap = new Map();
        readTrack();
    }
    return trackMap;
}

void TrackReader::changeMap(const std::string& mapName)
{
    fileName = mapName.c_str() << ".bmp";
    isNew = true;
}

void TrackReader::readTrack()
{
    bitmap_image image(fileName);

    if (!image || !trackMap)
    {
        printf("Error");
        return;
    }

    imgHeight = image.height();
    imgWidth = image.width();
    rgb_t colour;

    for (int y = 0; y < imgHeight; ++y)
    {
        for (int x = 0; x < imgWidth; ++x)
        {
            image.get_pixel(x, y, colour);

            //Set features of Map
        }
    }
    isNew = false;
}