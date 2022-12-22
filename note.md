# Creating a Game Loop in C
## Introduction

These notes are just reference material to the Pikuma course named "Creating a Game Loop in C." 

## Dependencies

We will be using SDL (Simple Design Layer) to open a window, display objects to a window, etc. We will use this framework because it will communicate directly with the operating system to display what we want to the screen.

## Creating an SDL Window.

Since we are working in pure C, it is important to remember some things that we will need. To have input/output to the terminal we need `#include <stdio.h>`.

Since we will be concentrating on the use of SDL, we want to import its functions. To do this we will call `#include <SDL2/SDL.h>`. This will let us call any of the functions we want to.

In C, its important to know that if we want a function to accept nothing in its parameters, we want to have its parameters say `void`, because in C if we have `()`, this means that we can any amount of items passed into the function. Below is a little example of the difference.

```c
// Cannot have any parameters.
void function(void);
// Can have any amount of parameters.
void function();
```

To get started with SDL, we need it initialize elements inside of the library. A quite and easy way to do this is to initialize everything. The way to do this is to call the function `SDL_Init()`, and then use a constant called `SDL_INIT_EVERYTHING`. If something failed to initialize, then it will not return `0`. An example is below:

```c
if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
{
    fprintf(stderr, "Error initializing SDL.\n");
}
```

Now that everything is initialized, we will create a window.

Making the window in SDL is quite easy. We will first make an instance of: `SDL_Window *window = NULL`. Then we will call a function called `SDL_CreateWindow()`. Below is our example with the parameters filled.

```c
uint32_t initialize_window(void)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }

    window = SDL_CreateWindow(
        NULL,
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_FULLSCREEN
    );

    if(!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }

    return TRUE;
}
```

Displaying images to the screen, we need to use a renderer. In the SDL library, we will use a function called `SDL_CreateRenderer()`, and this function accepts three parameters: the window, driver number, and any special flags. For the window parameter, we can pass in the window we have just created. We will pass is `-1` for the driver parameter; this tells SDL that it can use a default driver. 

## Polling SDL Events

When we are making our game loop we need to consider these functions in every loop we write.

```c
int main()
{
    init_window();
    set_up();
    while(game_state == true)
    {
        process_input();
        update();
        render();
    }
    clean_up();
}
```
1. `init_window()` is something we have already done. We are creating the window and initializing everything in SDL.
2. `set_up()` is setting the environment for the game.
3. `game_state` is where the game is in good shape to still be running, or the user wants to exit the game loop.
4. `process_input()` is when the user is putting input into the game and it changes objects inside of the game.
5. `update()` takes the changes from `process_input()` and updates variables and objects inside of the game.
6. `render()` updates the sprites/images that are in the game winddow.
7. `clean_up()` frees the memory that was allocated by SDL.

### Linker

When we run the make command we will see there is a linker command failure. The reason for this error is that we did not call the SDL library when we are compiling our program.

When we call make on our `.c` files it goes through a preprocessor which modifies the original program according to the directives that start with `#` like our include files. Then the compiler translates the program into an object file containing machine language code. Lastly, the linker merges and makes executable files.

When the preprocessor looks at our included files it only sees the header files that have the definition of the functions.

The linker bundles the libraries with their actual implementation.

To make the SDL library work with our program we will add the following linker flag `clang -Wall -std=c99 ./source/*.c -g3 -lSDL2 -o  main`. Notice that we have `-lSDL2` before the `-o`.