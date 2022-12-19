# Creating a Game Loop in C
## Introduction

These notes are just reference material to the Pikuma course named "Creating a Game Loop in C." 

## Dependencies

We will be using SDL (Simple Design Layer) to open a window, display objects to a window, etc. We will use this framework because it will communicate directly with the operating system to display what we want to the screen.

## Creating an SDL Window.

Since we are working in pure C, it is important to remember some things that we will need. To have input/output to the terminal we need `#include <stdio.h>`.

Since we will be concentrating on the use of SDL, we want to import its functions. To do this we will call `#include <SDL2/SDL.h>`. This will let us call any of the functions we want to.

In C, its important to know that if we want a fucntion to accept nothing in its parameters, we want to have its parameters say `void`, because in C if we have `()`, this means that we can any amount of items passed into the function. Below is a little example of the difference.

```c
// Cannot have any parameters.
void function(void);
// Can have any amount of parameters.
void function();
```