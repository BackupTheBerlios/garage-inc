#include "config.h"
#include <stdlib.h>

//SDL gui specific
#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>

#include "main_window.h"
#include "main_ui.h"

#define MODULE_ID WNDMGR

SDL_Surface *screen;
SDL_Font *LargeBoldFont;  
Window *CurWindow;
int WNDMGR_Running;

/* global variables */
int gEventsAllowed;
int windowswitch;


/* Local prototypes */
int wndmgr_Redraw(void *data);

void WNDMGR_CloseWindow()
{
    MAINWINDOW_Open(); //Always go back to main window

}

void WNDMGR_Init()
{
  
    LargeBoldFont=SDL_FontInit(THEME_DIR"/garage-inc/digital.fnt");

    {
        if ( SDL_Init(SDL_INIT_VIDEO|SDL_INIT_TIMER) < 0 ) 
        {
            fprintf(stderr, "Unable to init SDL: %s\n", SDL_GetError());
            exit(1);
        }
 
        screen = SDL_SetVideoMode(1000, 680, 32, SDL_SWSURFACE);
    
        if ( screen == NULL) 
        {
            fprintf(stderr, "Unable to set 1000x680 video: %s\n", SDL_GetError());
            exit(1);
        }

        atexit(SDL_Quit);

        SDL_WM_SetCaption("Garage Inc. ",NULL);
        windowswitch=0;
    }
}

void WNDMGR_Open(Window *window)
{

    CurWindow=window;
    windowswitch=1;
   
}

int WNDMGR_Main()
{
    SDL_Event test_event;
    
    int timer;
    SDL_TimerID SDL_AddTimer(Uint32 interval, SDL_NewTimerCallback callback, void *param);
    SDL_AddTimer(50,wndmgr_Redraw,NULL);

    WNDMGR_Running = 1;
    gEventsAllowed = 1;

    while(WNDMGR_Running)
    {
        while(SDL_PollEvent(&test_event)) 
        {
            if(gEventsAllowed)
                CurWindow->EventHandler(test_event);

            switch(test_event.type) 
            {
            case SDL_QUIT:
                WNDMGR_Running=0;
		printf("exit program\n");
                break;
            default:
                break;
            }
            if(windowswitch)
                windowswitch=0;
            else
                SDL_WidgetEvent(&test_event);
        }   
        SDL_Delay(25); /* To reduce CPU load */
    }

    return 1;
}

void WNDMGR_Exit()
{
    WNDMGR_Running=0;
}

int wndmgr_Redraw(void *data)
{
    if(CurWindow->NotifyRedraw)
        CurWindow->NotifyRedraw();
    SDL_DrawAllWidgets(screen);
    return 50; //redraw every 50ms 
}

/* disable sending events to the event handler of the current window
   this can be used when all events have to be send to a widget
   for example when the widget is in an edit state */
void WNDMGR_DisableEventhandler()
{
    gEventsAllowed=0;
}

void WNDMGR_EnableEventhandler()
{
    gEventsAllowed=1;
}

int main()
{
    MAINWINDOW_Init();
    WNDMGR_Init();
    MAINWINDOW_Open();
    WNDMGR_Main();
    return 1;
}
