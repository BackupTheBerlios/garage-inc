#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>
#include "main_ui.h"

SDL_Font *LargeBoldFont;

int workshopwindow_EventHandler(SDL_Event event);

SDL_Surface *WorkshopWindow;
SDL_Surface *MainWindow;

Window WORKSHOPWINDOW={ workshopwindow_EventHandler };

void WORKSHOPWINDOW_Init()
{
    WorkshopWindow = NULL;
}

void WORKSHOPWINDOW_Open()
{
    if(WorkshopWindow == NULL)
    {
        WorkshopWindow=Window_CreateWorkshopWindow();
    }
    SDL_WidgetUseSurface(WorkshopWindow);
    WNDMGR_Open(&WORKSHOPWINDOW);
}


SDL_Surface *Window_CreateWorkshopWindow()
{
    SDL_Surface *WorkshopWindow;
          
    WorkshopWindow = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(WorkshopWindow);

    SDL_WidgetCreate(SDL_PANEL,0,0,1000,680);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);

/* show the menu */
    
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu - Werkplaats");

    SDL_WidgetCreate(SDL_LABEL,200,170,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Magazijn");

    SDL_WidgetCreate(SDL_LABEL,200,200,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkplaats");

    SDL_WidgetCreate(SDL_LABEL,250,225,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkorder Maken");
   SDL_WidgetCreate(SDL_LABEL,225,225,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[m]");

  SDL_WidgetCreate(SDL_LABEL,250,250,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkorder Bewerken");
   SDL_WidgetCreate(SDL_LABEL,225,250,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[b]");

  SDL_WidgetCreate(SDL_LABEL,250,275,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkorder Factureren");
   SDL_WidgetCreate(SDL_LABEL,225,275,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[f]");

    SDL_WidgetCreate(SDL_LABEL,200,305,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Showroom");

    SDL_WidgetCreate(SDL_LABEL,200,335,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Basis gegevens");
  
    SDL_WidgetCreate(SDL_LABEL,200,365,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Administratie");
 
    /* show the info */

    SDL_WidgetCreate(SDL_LABEL,600,400,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F6 om een stap terug te gaan");

    SDL_WidgetCreate(SDL_LABEL,600,430,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F7 om terug te gaan naar het hoofdmenu");

  SDL_WidgetCreate(SDL_LABEL,600,460,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "Een rode letter intoetsen om een keuze te maken");
   

return WorkshopWindow;
        }   
        
int workshopwindow_EventHandler(SDL_Event event)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
        switch( event.key.keysym.sym ) 
        {

        case SDLK_F6:
	     WNDMGR_CloseWindow();
            break;

        case SDLK_F7:
	     WNDMGR_CloseWindow();
            break;

	case SDLK_ESCAPE:
             printf("Eerst terug naar hoofdmenu! druk op F7\n");
            break;


        default:
            break;
            
        }
        break;

    }
    return 0;
}

