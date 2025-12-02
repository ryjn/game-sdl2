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
### SDL Windows
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


