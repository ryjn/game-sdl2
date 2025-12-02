#include <SDL.h>
#include <stdio.h>
#include <iostream>

// Screen dimension constants
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

// Starts SDL and creates window
bool init();

// Load media
bool load_media();

// Frees media and shuts down SDL
void close();

int main(int argc, char* args[]) {
  // Window
  SDL_Window* window = NULL;

  // Surface contained by window
  SDL_Surface* screen_surface = NULL;

  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize. SDL_Error: " << SDL_GetError() << '\n';
  }
  else {
    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(window == NULL) {
      std::cout << "Window could not be created. SDL_ERROR: " << SDL_GetError() << '\n';
    }
    else {
      // Get window surface
      screen_surface = SDL_GetWindowSurface(window);

      // Fill surface white
      SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xFF, 0xFF, 0xFF));

      // Update surface
      SDL_UpdateWindowSurface(window);

      // Keep window up
      SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    }
  }
  // Destroy window
  SDL_DestroyWindow(window);

  // Quit SDL subsystems
  SDL_Quit();

  return 0;
}
