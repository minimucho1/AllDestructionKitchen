#include <SDL.h>
#include <iostream>

#include <Game.hpp>
#include <SplashScreen.hpp>

/*
    Created By: JR - 6/3/2016
*/

/*
 * Game::Loop()
 * The backbone of the game.
 * Begins startup of systems and handles game loop.
 * If a system fails, returns 1.
 */
bool Game::Loop() {
    // Call Game::Start() to initialize systems.
    if (gameState_ == Game::Uninitialized) {
        if (Game::Start()) {
            return 1;
        }
    }

    // Show Splash Screen
    if (gameState_ == Game::Splash) {
        if (Game::ShowSplash()) {
            return 1;
        }
    }

    // Main Game Loop
    while (gameState_ != Game::Exiting && gameState_ != Game::Fatal) {
        gameState_ = Game::Exiting;
    }

    // Exit Game
    if (gameState_ == Game::Exiting || gameState_ == Game::Fatal) {
        Game::Quit();
    }
    return 0;
}

/*
 * Game::Start()
 * Exists only to initialize systems.
 * Window and Rendering Surface are initialized here.
 */
bool Game::Start() {
    // Initialize SDL
    // SDL_INIT throws 0 on success
    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER)) {
        std::cout << "ERROR: SDL could not initialize.\n%s" << SDL_GetError();
        gameState_ = Game::Fatal;
        return 1;
    }

    // Create Window
    // SDL_Window throws NULL on failure
    SDL_Window *aWindow = getMainWindow();
    aWindow = SDL_CreateWindow(
        "All Destruction Kitchen: MUH FUCKIN GREATEST", // Window Title
        SDL_WINDOWPOS_UNDEFINED,                        // Undefined initial pos x
        SDL_WINDOWPOS_UNDEFINED,                        // Undefined initial pos y
        SCREEN_WIDTH,                                   // Screen Width
        SCREEN_HEIGHT,                                  // Screen Height
        SDL_WINDOW_OPENGL                               // Flags
    );

    if (getMainWindow() == NULL) {
        std::cout << "ERROR: Could not create window\n%s" << SDL_GetError();
        gameState_ = Game::Fatal;
        return 1;
    }

    // Apply mainWindow_ surface to rendering scene, currentScene_
    SDL_Surface *aScene = getCurrentScene();
    aScene = SDL_GetWindowSurface(getMainWindow());

    gameState_ = Game::Splash;
    return 0;
}

/*
 * Game::Splash()
 * Function handles everything related to splash screen.
 * Only initialize splash screen here.
 */
bool Game::ShowSplash() {
    SplashScreen splashScreen;
    if (splashScreen.Show(getCurrentScene(), getMainWindow())) {
        return 1;
    }
    SDL_Delay(2000); // Show Splash Screen for 2 seconds.
    gameState_ = Game::MainMenu;
    return 0;
}

/*
 * Game::Quit()
 * Quits all systems.
 * Deallocates and destroys Window and Rendering Surface here.
 */
void Game::Quit() {
    if (gameState_ == Game::Exiting) {
        SDL_FreeSurface(getCurrentScene());
        currentScene_ = NULL;

        SDL_DestroyWindow(getMainWindow());
        mainWindow_ = NULL;
    }

    // Quit SDL
    SDL_QUIT;
}

// -----------------------------------
Game::GameState Game::gameState_ = Uninitialized;
SDL_Window *Game::mainWindow_ = NULL;
SDL_Surface *Game::currentScene_ = NULL;
