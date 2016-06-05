#include <iostream>
#include <SDL_surface.h>
#include <SDL_video.h>
#include <SDL_image.h>

#include <SplashScreen.hpp>

/*
    Created By: JR - 6/4/2016
*/

bool SplashScreen::Show(SDL_Surface *renderSurface, SDL_Window *renderWindow) {
    // Load Splash Image to surface.
    // Returns NULL on failure.
    const char* splashImageLocation = "resources/images/ShoryuStudios.png";
    splashImage = IMG_Load(splashImageLocation);
    if (splashImage == NULL) {
        std::cout << "ERROR: Splash image could not be loaded.\n%s" << SDL_GetError();
        return 1;
    }

    // Blit image to window
    if (SDL_BlitSurface(
        splashImage,    // Source Surface
        NULL,           //
        renderSurface,  // Destination Surface
        NULL            //
    )) {
        std::cout << "ERROR: Could not blit splash image to render surface. \n%s" << SDL_GetError();
        return 1;
    }

    // Update the window to show images.
    SDL_UpdateWindowSurface(renderWindow);
}

// -----------------------------------
SDL_Surface *splashImage = NULL;
