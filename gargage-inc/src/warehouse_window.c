#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>
#include "main_ui.h"

SDL_Font *LargeBoldFont;

int magazijnwindow_EventHandler(SDL_Event event);

SDL_Surface *MagazijnWindow;
SDL_Surface *WarehouseAdd;
SDL_Surface *MainWindow;

Window MAGAZIJNWINDOW={ magazijnwindow_EventHandler };

void MAGAZIJNWINDOW_Init()
{
    MagazijnWindow = NULL;
}

void MAGAZIJNWINDOW_Open()
{
    if(MagazijnWindow == NULL)
    {
        MagazijnWindow=Window_CreateMagazijnWindow();
    }
    SDL_WidgetUseSurface(MagazijnWindow);
    WNDMGR_Open(&MAGAZIJNWINDOW);
}


SDL_Surface *Window_CreateMagazijnWindow()
{
    SDL_Surface *MagazijnWindow;
          
    MagazijnWindow = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(MagazijnWindow);

    SDL_WidgetCreate(SDL_PANEL,0,0,1000,680);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);

/* show the menu */
    
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu - Magazijn");

    SDL_WidgetCreate(SDL_LABEL,200,170,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Magazijn");

    SDL_WidgetCreate(SDL_LABEL,250,200,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Toevoegen");
   SDL_WidgetCreate(SDL_LABEL,225,200,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[t]");

  SDL_WidgetCreate(SDL_LABEL,250,225,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Verwijderen");
   SDL_WidgetCreate(SDL_LABEL,225,225,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[v]");

  SDL_WidgetCreate(SDL_LABEL,250,250,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Zoeken");
   SDL_WidgetCreate(SDL_LABEL,225,250,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[z]");

  SDL_WidgetCreate(SDL_LABEL,250,275,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Bewerken");
   SDL_WidgetCreate(SDL_LABEL,225,275,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[b]");

  SDL_WidgetCreate(SDL_LABEL,250,300,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Factuur maken");
   SDL_WidgetCreate(SDL_LABEL,225,300,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[f]");

    SDL_WidgetCreate(SDL_LABEL,200,330,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkplaats");

    SDL_WidgetCreate(SDL_LABEL,200,360,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Showroom");

    SDL_WidgetCreate(SDL_LABEL,200,390,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Basis gegevens");
  
    SDL_WidgetCreate(SDL_LABEL,200,420,300,19);
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
   

return MagazijnWindow;
        }   
        
int magazijnwindow_EventHandler(SDL_Event event)
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
     
	case SDLK_t:
	     WAREHOUSEADD_Open();
            break;

	    //	case SDLK_v:
	    //  WAREHOUSEREMOVE_Open();
	    //  break;

	case SDLK_f:
	     WAREHOUSEINVOICE_Open();
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

