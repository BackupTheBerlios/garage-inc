#include <SDL/SDL.h>

#ifndef __WNDMGR_UI_H__
#define __WNDMGR_UI_H__

typedef struct Window
{
    int (*EventHandler)(SDL_Event event);
    int (*NotifyRedraw)();
}Window;

void WNDMGR_Init();
void WNDMGR_Open(Window *window);
int  WNDMGR_Main();
void WNDMGR_CloseWindow();
void WNDMGR_Exit();

void WNDMGR_DisableEventhandler();
void WNDMGR_EnableEventhandler();

#endif __WNDMGR_H__
