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
#include <string>
#include <cstdio>
#include <eigen3/Eigen/src/Core/Matrix.h>
#include "BitmapImage.h"

using namespace std;
using namespace Eigen;

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
        readTrack();
        isNew = false;
    }
    return trackMap;
}

void TrackReader::changeMap(const string& mapName)
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
    vector<MapEntity::EntityType> enumMap(imgHeight*imgWidth);
    int p1[255][2]; 
    int p2[255][2]; 
    rgb_t colour;
    int checkpoint = 0;

    for (int y = 0; y < imgHeight; ++y)
    {
        for (int x = 0; x < imgWidth; ++x)
        {
            //Features of map (Green chanel)
            image.get_pixel(x, y, colour);
            enumMap(y*imgHeight + x) = colour.green;
            
            //Checkpoints (Red chanel)
            if(colour.red > 0)
            {
                if(p1[checkpoint] == 0)
                {
                    p1[checkpoint] = colour.red;
                }
                else
                {
                    p2[checkpoint] = colour.red;
                }
                checkpoint++;
            }
        }
    }
    vector<Checkpoint> checkpoints(checkpoint);
    for(int i = 0; i < checkpoint; i++)
        checkpoints.emplace_back(Vector2i(p1[i][0],p1[i][1]), Vector2i(p2[i][0],p2[i][1]));
    trackMap = Map(imgWidth, imgHeight, enumMap, checkpoints);
}