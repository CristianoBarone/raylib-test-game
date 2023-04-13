#pragma once

Texture2D 
textureAudio,
textureSave,
textureLoad;

Texture2D
background;

void setTextures() {
    textureSave = LoadTexture("resources/graphical/save.png");
    textureLoad = LoadTexture("resources/graphical/load.png");
    textureAudio = LoadTexture("resources/graphical/audio.png");
}