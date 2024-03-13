#include "mysdl.h"
#include <SDL2/SDL.h>
#include "rsi_login.h"
#include <stdio.h>

const int screen_width = 640;
const int screen_height = 480;

bool init();
bool loadmedia();
void close();

SDL_Window *gwindow = NULL;
SDL_Surface *gscreensurface = NULL;
SDL_Surface *ghelloworld = NULL;


MYSDL::MYSDL()
{
    qDebug()<<"vikas in mysdl.cpp";
    if(!init()){
        qDebug()<<"failed to initialise";
    }
    else
    {
        if(!loadmedia())
        {
            qDebug()<<"failed to load media";
        }
        else
        {
            SDL_BlitSurface(ghelloworld,NULL,gscreensurface,NULL);
            SDL_UpdateWindowSurface(gwindow);
            SDL_Delay(5000);
        }
    }
    close();
}


bool init()
{
    bool success = true;
    if(SDL_Init(SDL_INIT_VIDEO)<0)
    {
        qDebug()<<"sdl fail";
        success = false;
    }
    else
    {
        qDebug()<<"vikas, sdl pass";
        gwindow = SDL_CreateWindow("SDL tutorial",SDL_WINDOWPOS_UNDEFINED,SDL_WINDOWPOS_UNDEFINED,screen_width,screen_height,SDL_WINDOW_SHOWN);
        if(gwindow==NULL)
        {
            qDebug()<<"window cannot be created";
            success = false;
        }
        else
        {
            gscreensurface = SDL_GetWindowSurface(gwindow);
        }
    }

    return success;
}

bool loadmedia()
{
    bool success = true;
    ghelloworld = SDL_LoadBMP("/home/kodiak/Desktop/Vikas/hello_world.bmp");
    if(ghelloworld==NULL)
    {
        qDebug()<<"unable to load image";
        success = false;
    }
    return success;
}

void close()
{
    SDL_FreeSurface(ghelloworld);
    ghelloworld = NULL;
    SDL_DestroyWindow(gwindow);
    gwindow = NULL;
    SDL_Quit();
}
