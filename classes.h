#pragma once

#include "textures.h"
#include <utility>
#include <iostream>
#include <fstream>

unsigned char gamedata[1024];
int scene = 0;

class Blinker
{
public:
    std::pair<int, int> coords;
    unsigned char opacity;
    float radius;
};

class SaveHandler
{
public:
    void Save() {
        std::fstream savegame;
        savegame.open("sv.bin", std::ios::out);
        if (!savegame) {
            std::cout<<" an error occurred while creating the savegame file, this game won't be saved" << std::endl;
        } else {
            int i;
            while (i<1024) {         
                savegame<<gamedata[i];
                i++;
            }
            savegame.close();
        }
    }
    void Load() {
        std::fstream savegame;
        savegame.open("sv.bin", std::ios::in);
        if (!savegame) {
            std::cout<<" an error occurred while loading the savegame file, this game won't be loaded" << std::endl;
        } else {
            char x;                     
            while (!savegame.eof()) {         
                savegame>>gamedata;         
            }
            savegame.close();
            scene = gamedata[0];
        }
    }
};