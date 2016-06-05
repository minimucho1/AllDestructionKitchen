#pragma once

#include <SDL_surface.h>

/*
    Created By: JR - 6/4/2016
*/

class SplashScreen {
public:
    SplashScreen();
    ~SplashScreen();

    static bool Show(SDL_Surface *renderSurface, SDL_Window *renderWindow);
private:
    static SDL_Surface *splashImage;
};
