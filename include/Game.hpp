#pragma once
#include <SDL_surface.h>
#include <SDL_video.h>

/*
    Created By: JR - 6/3/2016
*/

class Game {
public:
    static bool Loop();
    static bool Start();
    static bool ShowSplash();
    static void Quit();

    static SDL_Window *getMainWindow() { return mainWindow_; }
    static void setMainWindow(SDL_Window *aWindow) { mainWindow_ = aWindow; }
    static SDL_Surface *getCurrentScene() { return currentScene_; }
    static void setCurrentScene(SDL_Surface *aSurface) { currentScene_ = aSurface; }

private:
    Game(); // Unused
    ~Game(); // Unused

    static const int SCREEN_WIDTH = 1440;
    static const int SCREEN_HEIGHT = 960;
    static const int SCREEN_BPP = 32;

    // Possible states GameState could be in.
    // GameState will *always* begin Uninitialized but never return to it.
    enum GameState {
        Uninitialized, Splash, MainMenu, Playing, Paused, Exiting, Fatal
    };

    static GameState gameState_; // Holds the value for the current state (enum) of the game.
    static SDL_Window *mainWindow_; // Main game screen window.
    static SDL_Surface *currentScene_; // Render images to show to screen here.
};
