#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>
#include "main_ui.h"

SDL_Font *LargeBoldFont;

int warehouseinvoice_EventHandler(SDL_Event event);

SDL_Surface *WarehouseInvoice;
SDL_Surface *MainWindow;

Window WAREHOUSEINVOICE={ warehouseinvoice_EventHandler };

void WAREHOUSEINVOICE_Init()
{
    WarehouseInvoice = NULL;
}

void WAREHOUSEINVOICE_Open()
{
    if(WarehouseInvoice == NULL)
    {
        WarehouseInvoice=Window_CreateWarehouseInvoice();
    }
    SDL_WidgetUseSurface(WarehouseInvoice);
    WNDMGR_Open(&WAREHOUSEINVOICE);
}


SDL_Surface *Window_CreateWarehouseInvoice()
{
    SDL_Surface *WarehouseInvoice;
          
    WarehouseInvoice = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(WarehouseInvoice);

    SDL_WidgetCreate(SDL_PANEL,0,0,1000,680);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);

/* show the menu */
    
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu - Magazijn - Factuur maken");

    SDL_WidgetCreate(SDL_LABEL,200,170,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Magazijn");

    SDL_WidgetCreate(SDL_LABEL,225,200,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Toevoegen");

  SDL_WidgetCreate(SDL_LABEL,225,225,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Verwijderen");

  SDL_WidgetCreate(SDL_LABEL,225,250,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Zoeken");

  SDL_WidgetCreate(SDL_LABEL,225,275,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Onderdelen Bewerken");

  SDL_WidgetCreate(SDL_LABEL,225,300,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Factuur maken");

 SDL_WidgetCreate(SDL_LABEL,300,330,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Magazijnfactuur maken");
   SDL_WidgetCreate(SDL_LABEL,275,330,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[m]");

 SDL_WidgetCreate(SDL_LABEL,300,355,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Creditfactuur maken");
   SDL_WidgetCreate(SDL_LABEL,275,355,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[c]");

 SDL_WidgetCreate(SDL_LABEL,300,380,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Verkoopfactuur maken");
   SDL_WidgetCreate(SDL_LABEL,275,380,25,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION, "[v]");

    SDL_WidgetCreate(SDL_LABEL,200,410,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Werkplaats");

    SDL_WidgetCreate(SDL_LABEL,200,440,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Showroom");

    SDL_WidgetCreate(SDL_LABEL,200,470,300,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0x21c900);
    SDL_WidgetProperties(SET_CAPTION, "Basis gegevens");
  
    SDL_WidgetCreate(SDL_LABEL,200,500,300,19);
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

return WarehouseInvoice;
        }   
        
int warehouseinvoice_EventHandler(SDL_Event event)
{
    switch(event.type)
    {
    case SDL_KEYDOWN:
        switch( event.key.keysym.sym ) 
        {

        case SDLK_F7:
	     WNDMGR_CloseWindow();
            break;

   case SDLK_F6:
	     MAGAZIJNWINDOW_Open();
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

