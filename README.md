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
