#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window *window = NULL;
SDL_Renderer* renderer = NULL;
uint32_t game_is_running = FALSE;

uint32_t initialize_window(void)
{
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
    {
        fprintf(stderr, "Error initializing SDL.\n");
        return FALSE;
    }

    window = SDL_CreateWindow(
        "FIRST WINDOW",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        800,
        600,
        SDL_WINDOW_RESIZABLE
    );

    if(!window)
    {
        fprintf(stderr, "Error creating SDL window.\n");
        return FALSE;
    }

    renderer = SDL_CreateRenderer(window, -1, 0);
    
    if(!renderer)
    {
        fprintf(stderr, "Error creating SDL Renderer\n");
        return FALSE;
    }

    return TRUE;
}

void process_input()
{
    // create an instance of event struct.
    SDL_Event event;
    // Get the event from the event queue.
    SDL_PollEvent(&event);

    // now we need to see what kind of event was popped of the event queue.
    switch(event.type)
    {
        // When the "X" button is clicked on the window.
        case SDL_QUIT:
            game_is_running = FALSE;
            break;
        case SDL_KEYDOWN:
            if(event.key.keysym.sym == SDLK_ESCAPE)
            {
                game_is_running = FALSE;
            }
            break;
    }
}

void setup()
{
    // TODO
}

void update()
{
    // TODO
}

void render()
{
    // TODO
}

void destroy_window()
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

int main()
{
    game_is_running = initialize_window();

    setup();

    while(game_is_running)
    {
        
        process_input();
        update();
        render();
         
    }

    destroy_window();

    return 0;
}