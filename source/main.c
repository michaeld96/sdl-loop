#include <stdio.h>
#include <SDL2/SDL.h>
#include "constants.h"

SDL_Window *window = NULL;
SDL_Renderer* renderer = NULL;
uint32_t game_is_running = FALSE;

struct ball
{
    float x;
    float y;
    float width;
    float height;
} ball;

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
    ball.x = 20;
    ball.y = 20;
    ball.width = 15;
    ball.height = 15;
}

void update()
{
    // TODO:
}

void render()
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    // clear the context of what we just created.
    SDL_RenderClear(renderer);

    // Start drawing game objects.
    

    // Draw a rectangle.
    SDL_Rect ball_rect = {ball.x, ball.y, ball.width, ball.height};
    // Drawing the ball as white.
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    // fill the ball.
    SDL_RenderFillRect(renderer, &ball_rect);
    // Double buffer.
    SDL_RenderPresent(renderer);
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