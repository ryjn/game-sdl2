# Game Programming with C++ and SDL2

## Setup
### SDL2 Installation
#### MacOS
Install SDL2 using Homebrew
```
brew install sdl2
```

Include SDL header file:
```cpp
#include <SDL.h>
```

When compiling, include following flags to let compiler know where SDL files are
```
g++ main.cpp -o main $(pkg-config --cflags --libs sdl2)
```

> [!NOTE]
> If compiling does not work, check to make sure `pkg-config` is installed
> Can be installed via `brew install pkg-config`

#### Linux
TBD
## The Code
### Initialize SDL
```cpp

int main(int argc, char* args[]) {
  // Window
  SDL_Window* window = NULL;

  // Surface contained by window
  SDL_Surface* screen_surface = NULL;

  // Initialize SDL
  if(SDL_Init(SDL_INIT_VIDEO) < 0) {
    std::cout << "SDL could not initialize. SDL_Error: " << SDL_GetError() << '\n';
  }
```
SDL requires the arguments of the `main` function to be an integer, followed by a `char*` array.  
The window is then declared - to be defined later  
Then define the surface, which will be contained by the window. In SDL, a surface is just a 2D image.  
After declaring a window and screen surface, SDL is initialized.  
  - Because we are only using SDL's video subsystem, we are only passing the `SDL_INIT_VIDEO` flag
  - If there is an error, `SDL_Init` returns `-1`. `SDL_GetError` returns the latest error produced by the SDL function.

### Window
```cpp
  else {
    // Create window
    window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
    if(window == NULL) {
      std::cout << "Window could not be created. SDL_ERROR: " << SDL_GetError() << '\n';
    }
```
If SDL initializes successfully, a window is created using `SDL_CreateWindow`
- First argument is the title of the window
- Next two arguments define the window's position, x and y coordinates. `SDL_WINDOWPOS_UNDEFINED` is used as placeholders since we are not concerned with the window's position.
- Next two arguments are the window's size, width and height.
- Last argument is the creation flags - `SDL_WINDOW_SHOWN` ensures the window is shown when created.
If there is an error when creating the window, `SDL_CreateWindow` returns `NULL`. The `if` statement checks for this and prints a message if there is an error.

### Window Surface
Once the window is successfully created, we need to get the window's surface to write to it.
```cpp
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
```

