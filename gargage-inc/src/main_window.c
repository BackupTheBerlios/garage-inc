#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>
#include <SDL_Panel.h>
#include "SDL_Tab.h"
#include "main_ui.h"
SDL_Font *LargeBoldFont;

char buffer[100];
void *editding;
void *labelding;
void *timewidget;
void *panel;


int mainwindow_EventHandler(SDL_Event event);

SDL_Surface *mainwindow_CreateWindow();
SDL_Surface *MainWindow;

Window MAINWINDOW={ mainwindow_EventHandler,NULL };

void MAINWINDOW_Init()
{
  
    MainWindow = NULL;
}


void MAINWINDOW_Open()
{
    if(MainWindow == NULL)
    {
        MainWindow=mainwindow_CreateWindow();
    }
    SDL_WidgetUseSurface(MainWindow);
    WNDMGR_Open(&MAINWINDOW);
}


SDL_Surface *mainwindow_CreateWindow()
{
    SDL_Surface *MainWindow;

    MainWindow = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(MainWindow);
 
    SDL_WidgetCreate(SDL_PANEL,20,0,1000,20);
    
    /* show the menu */
    
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu");

    SDL_WidgetCreate(SDL_LABEL,200,170,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Magazijn");
   SDL_WidgetCreate(SDL_LABEL,175,170,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[m]");

    SDL_WidgetCreate(SDL_LABEL,200,200,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkplaats");
   SDL_WidgetCreate(SDL_LABEL,175,200,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[w]");

    SDL_WidgetCreate(SDL_LABEL,200,230,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Showroom");
   SDL_WidgetCreate(SDL_LABEL,175,230,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[s]");

    SDL_WidgetCreate(SDL_LABEL,200,260,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "basis gegevens");
   SDL_WidgetCreate(SDL_LABEL,175,260,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[b]");

    SDL_WidgetCreate(SDL_LABEL,200,290,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Administratie");
   SDL_WidgetCreate(SDL_LABEL,175,290,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[a]");

    /* show the info */

    SDL_WidgetCreate(SDL_LABEL,600,400,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "ESC om het programma af te sluiten");

  SDL_WidgetCreate(SDL_LABEL,600,430,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F1 voor hulp en info");
   
  SDL_WidgetCreate(SDL_LABEL,600,460,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "Een rode letter intoetsen om het menu uit te vouwen");
return MainWindow;
}


int mainwindow_EventHandler(SDL_Event event)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
        switch( event.key.keysym.sym ) 
        {
        case SDLK_ESCAPE:
	  printf("exit\n");
            WNDMGR_Exit();
            break;
	    
	case SDLK_m:
            MAGAZIJNWINDOW_Open();
            break;

	case SDLK_w:
            WORKSHOPWINDOW_Open();
            break;

	    
        default:
            break;
            
        }
        break;

    }
    return 0;
}
