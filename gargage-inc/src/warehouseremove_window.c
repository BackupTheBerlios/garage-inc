#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#define maxsize 1000

#include <SDL/SDL.h>
#include <SDL_Widget.h>
#include <SDL_Font.h>
#include <SDL_Edit.h>
#include <SDL_Stack.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "main_ui.h"

SDL_Surface *WarehouseRemove;

SDL_Font *LargeBoldFont;

int warehouseremove_EventHandler(SDL_Event event);

Window WAREHOUSEREMOVE={ warehouseremove_EventHandler };

int test;
char savedpartnumber[100];
char saveddescription[100];
char savedsectionnumber[100];
char savedsellprice[100];
char savedorderprice[100];
char savedorderunit[100];

void WAREHOUSEREMOVE_Init()
{
    WarehouseRemove = NULL;
    test=0;
}

void WAREHOUSEREMOVE_Open()
{
    if(WarehouseRemove == NULL)
    {
      WarehouseRemove=Window_CreateWarehouseremove();
    }
    SDL_WidgetUseSurface(WarehouseRemove);
    WNDMGR_Open(&WAREHOUSEREMOVE);
}

struct tablerow
 {
char partnumber[100];
char description[100];
char sectionnumber[100];
char sellprice[100];
char orderprice[100];
char orderunit[100];
} tablerow[maxsize];

char *dist;
char *ptr_char; // a pointer to a char
char c[10]; // to read alle lines in warehouse.db
char buffer[1000]; 
void *wid_partnumber;
void *wid_description;
void *wid_sectionnumber;
void *wid_sellprice;
void *wid_orderprice;
void *wid_orderunit;
FILE *fp; 
long filesize;
long row;
int column;
void *table;
char *string;


void tablestring1(long row,int column,char *string)
{   
  if(row == test-1 && column == 0)
  {
 sprintf(string,"%s\n",buffer);
  }
   }

SDL_Surface *Window_CreateWarehouseremove()
  {
    SDL_Surface *WarehouseremoveWindow;

    WarehouseremoveWindow = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(WarehouseremoveWindow);
    
    SDL_WidgetCreate(SDL_PANEL,0,0,1000,680);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
     
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu - Magazijn - Onderdelen verwijderen");

    /* adding labels to see what you must fill in */

    SDL_WidgetCreate(SDL_LABEL,50,50,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"Onderdeel nummer: ");
    
    
    /* adding editwidgets to add parts in the warehouse */
    wid_partnumber=SDL_WidgetCreate(SDL_EDIT,200,50,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_partnumber,GET_CAPTION,&tablerow->partnumber);
   
  SDL_WidgetCreate(SDL_LABEL,38,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"onderdeel nr:");

    SDL_WidgetCreate(SDL_LABEL,158,185,600,15);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);

 
    SDL_WidgetCreate(SDL_LABEL,30,185,3,315);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
 
    SDL_WidgetCreate(SDL_LABEL,33,185,5,15);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);

    SDL_WidgetCreate(SDL_LABEL,758,185,3,315);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);

/* show the info */

    SDL_WidgetCreate(SDL_LABEL,200,550,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F6 om een stap terug te gaan");

    SDL_WidgetCreate(SDL_LABEL,200,580,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F7 om terug te gaan naar het hoofdmenu");

  SDL_WidgetCreate(SDL_LABEL,200,610,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "ENTER om het onderdeel op te slaan");

 SDL_WidgetCreate(SDL_LABEL,200,640,400,19);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION, "F2 om het bestand te lezen");
    /* set table */

table=SDL_WidgetCreate(SDL_TABLE,38,200,720,300);/*x y w h */
        SDL_WidgetProperties(SET_VISIBLE_ROWS,    30);
        SDL_WidgetProperties(SET_VISIBLE_COLUMNS, 1);
	//  SDL_WidgetProperties(COLUMN_WIDTH, 1, 120 );
	SDL_WidgetProperties(SET_BG_COLOR,0x000000);
        SDL_WidgetProperties(SET_FONT,LargeBoldFont);
        SDL_WidgetProperties(SET_DATA_RETREIVAL_FUNCTION,tablestring1);


return WarehouseremoveWindow;		     
}  

int warehouseremove_EventHandler(SDL_Event event)
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

	   case SDLK_F2:
	     {
	       printf("warehouse.db lezen\n");
fp=fopen(THEME_DIR"/garage-inc/warehouse.db","r+"); // open warehouse.db to update
if(fp==NULL) {
    printf("Error: can't open file.\n");
    /* fclose(fp); DON'T PASS A NULL POINTER TO fclose !! */
    return 1;
}

fseek(fp,0,SEEK_END); // go to the end of file
filesize=ftell(fp);   // say how long the file is
fseek(fp,0,SEEK_SET); // go to the bigin of file
fread(buffer,1,filesize,fp); // buffer = filesize x 1
	     }
fclose(fp);
                 break;   

	case SDLK_RETURN:
	  {
	    test++;
  SDL_WidgetPropertiesOf(wid_partnumber,GET_CAPTION,&tablerow->partnumber);
  SDL_WidgetPropertiesOf(wid_partnumber,SET_CAPTION,"");

fp=fopen(THEME_DIR"/garage-inc/warehouse.db","r+"); // open warehouse.db to update
if(fp==NULL) {
    printf("Error: can't open file.\n");
    /* fclose(fp); DON'T PASS A NULL POINTER TO fclose !! */
    return 1;
}
fseek(fp,0,SEEK_END); // go to the end of file
filesize=ftell(fp);   // say how long the file is
fseek(fp,0,SEEK_SET); // go to the bigin of file
fread(buffer,1,filesize,fp); // buffer = filesize x 1
fseek(fp,0,SEEK_SET);  //go back to the begin of file
fwrite(&tablerow->partnumber,1,strlen(tablerow->partnumber),fp); 
fwrite("-",1,1,fp); 
fwrite(&tablerow->description,1,strlen(tablerow->description),fp);  
fwrite("-",1,1,fp); 
fwrite(&tablerow->sectionnumber,1,strlen(tablerow->sectionnumber),fp);  
fwrite("-",1,1,fp);
fwrite(&tablerow->sellprice,1,strlen(tablerow->sellprice),fp); 
fwrite("-",1,1,fp);
fwrite(&tablerow->orderprice,1,strlen(tablerow->orderprice),fp); 
fwrite("-",1,1,fp); 
fwrite(&tablerow->orderunit,1,strlen(tablerow->orderunit),fp);  
fwrite("\n",1,1,fp); // add new line
fwrite(buffer,1,filesize,fp);  //write old file back
printf("Waarden opgeslagen\n");
fclose(fp);
	  }
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


