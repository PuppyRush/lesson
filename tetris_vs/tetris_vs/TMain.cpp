
#include "TFigureL.h"

#include "TBoardController.h"

#include <iostream>
#include <random>
#include <functional>

#include "SDL2/SDL.h"

#undef main


//global variable
SDL_Window *window;
SDL_Renderer *renderer;
bool quit = true;
auto ctl = tetris::BoardController::get();

Uint32 my_callbackfunc(Uint32 interval, void *param) {
    SDL_Event event;
    SDL_UserEvent userevent;

    userevent.type = SDL_USEREVENT;
    userevent.code = 0;

    event.type = SDL_USEREVENT;
    event.user = userevent;

    SDL_PushEvent(&event);
    return (interval);
}

void sdl_quit()
{
    // cleanup SDL
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

void sdl_init()
{
    srand((unsigned int)time(0));

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init error: " << SDL_GetError() << std::endl;
        return;
    }

    window =
        SDL_CreateWindow("SDL_TETRIS", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 600, 800, SDL_WINDOW_SHOWN);
    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    SDL_AddTimer(1000, my_callbackfunc, nullptr);
}

void sdl_draw()
{
    auto board = ctl->getGameBoard();
    for (int y = 0; y < board.size(); y++) {
        auto& row = board.at(y);
        for (int x = 0; x < row.size(); x++) {
            SDL_Point line[5];
            line[0].y = 50 + y * 30;
            line[0].x = 50 + x * 30;
            line[1].y = 50 + y * 30;
            line[1].x = 50 + x * 30 + 30;
            line[2].y = 50 + y * 30 + 30;
            line[2].x = 50 + x * 30 + 30;
            line[3].y = 50 + y * 30 + 30;
            line[3].x = 50 + x * 30;
            line[4].y = 50 + y * 30;
            line[4].x = 50 + x * 30;

            // Set render color to blue ( rect will be rendered in this color )
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            // Render rect
            SDL_RenderDrawLines(renderer, line, 5);
            // Render the rect to the screen

            if (board[y][x].getType() == tetris::UnitType::Fill) {
                SDL_Rect rect;
                rect.y = 50 + y * 30;
                rect.x = 50 + x * 30;
                rect.h = 30;
                rect.w = 30;

                SDL_RenderFillRect(renderer, &rect);
                SDL_SetRenderDrawColor(renderer, 0, 80, 60, 255);
                SDL_RenderDrawRect(renderer, &rect);
            }
        }
    }

    SDL_RenderPresent(renderer);
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
}

void sdl_event()
{
    SDL_Event event;
    SDL_WaitEvent(&event);
    switch (event.type) {
    case SDL_QUIT:
        quit = true;
        break;
    case SDL_KEYDOWN:
        switch (event.key.keysym.sym) {
        case SDLK_LEFT:
            ctl->goLeft();
            break;
        case SDLK_RIGHT:
            ctl->goRight();
            break;
        case SDLK_UP:
            ctl->rotate();
            break;
        case SDLK_DOWN:
            ctl->goDown();
            break;
        case SDLK_SPACE:
            ctl->goStraightDown();
            break;
        }
        break;
    default:;
    }

    SDL_PollEvent(&event);
    switch (event.type) {
        case SDL_USEREVENT: {
            /* and now we can call the function we wanted to call in the timer but couldn't because of the multithreading problems */
            ctl->goDown();
            break;
        }
    }
}

int main() 
{
    sdl_init();

    while (quit) {
        sdl_draw();
        sdl_event();
    }

    sdl_quit();

    return 0;
}

