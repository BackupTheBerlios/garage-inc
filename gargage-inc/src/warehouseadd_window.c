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

SDL_Surface *WarehouseAdd;

SDL_Font *LargeBoldFont;

int warehouseadd_EventHandler(SDL_Event event);

Window WAREHOUSEADD={ warehouseadd_EventHandler };

int test;
char a[12] = {'S','-','t','-','r','-','i','-','n','-','g','\0'};
char savedpartnumber[100];
char saveddescription[100];
char savedsectionnumber[100];
char savedsellprice[100];
char savedorderprice[100];
char savedorderunit[100];

void WAREHOUSEADD_Init()
{
    WarehouseAdd = NULL;
    test=0;
}

void WAREHOUSEADD_Open()
{
    if(WarehouseAdd == NULL)
    {
      WarehouseAdd=Window_CreateWarehouseadd();
    }
    SDL_WidgetUseSurface(WarehouseAdd);
    WNDMGR_Open(&WAREHOUSEADD);
}

struct tablerow
 {
char partnumber[100];
char description[100];
char sectionnumber[100];
float orderprice[100];
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
int btw = 2;
int sellprice;
int sellwithbtw;
FILE *fp; 
long filesize;
long row;
int column;
void *table;
char *string;

void tablestring(long row,int column,char *string)
{

  if(row == test-1 && column == 0)
  {
 sprintf(string,"%s",tablerow->partnumber);
  }
  else
 if(row == test-1 && column == 1)
  sprintf(string,"%s",tablerow->description);
    else
 if(row == test-1 && column == 2)
  sprintf(string,"%s",tablerow->sectionnumber);
  else
    // if(row == test-1 && column == 3)
   //   sprintf(string,"%s",sellprice);
    // else
 if(row == test-1 && column == 4)
  sprintf(string,"%s",tablerow->orderprice);
   else
 if(row == test-1 && column == 5)
   sprintf(string,"%s",tablerow->orderunit);
   }

SDL_Surface *Window_CreateWarehouseadd()
  {
    SDL_Surface *WarehouseaddWindow;

    WarehouseaddWindow = SDL_CreateRGBSurface(SDL_SWSURFACE,1000,680,32,0xff0000,0x00ff00,0x0000ff,0x000000);
    SDL_WidgetUseSurface(WarehouseaddWindow);
    
    SDL_WidgetCreate(SDL_PANEL,0,0,1000,680);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
     
    SDL_WidgetCreate(SDL_LABEL,0,0,1000,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0e00b2);
    SDL_WidgetProperties(SET_CAPTION, "Hoofdmenu - Magazijn - Onderdelen toevoegen");

    /* adding labels to see what you must fill in */

    SDL_WidgetCreate(SDL_LABEL,50,50,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"Onderdeel nummer: ");

    SDL_WidgetCreate(SDL_LABEL,50,80,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"Omschrijving: ");
  
    SDL_WidgetCreate(SDL_LABEL,50,110,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"vaknummer: ");

    SDL_WidgetCreate(SDL_LABEL,50,140,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"verkoop prijs: ");

    SDL_WidgetCreate(SDL_LABEL,400,50,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"inkoop prijs: ");

    SDL_WidgetCreate(SDL_LABEL,400,80,150,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0x000000);
    SDL_WidgetProperties(SET_FG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_CAPTION,"bestel eenheid: ");

   
    /* adding editwidgets to add parts in the warehouse */
    wid_partnumber=SDL_WidgetCreate(SDL_EDIT,200,50,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_partnumber,GET_CAPTION,&tablerow->partnumber);
   
    
    wid_description=SDL_WidgetCreate(SDL_EDIT,200,80,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_description,GET_CAPTION,&tablerow->description);

    wid_sectionnumber=SDL_WidgetCreate(SDL_EDIT,200,110,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_sectionnumber,GET_CAPTION,&tablerow->sectionnumber);

    wid_sellprice=SDL_WidgetCreate(SDL_EDIT,200,140,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_sellprice,GET_CAPTION,&sellprice);

    wid_orderprice=SDL_WidgetCreate(SDL_EDIT,550,50,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_orderprice,GET_CAPTION,&tablerow->orderprice);
   
    wid_orderunit=SDL_WidgetCreate(SDL_EDIT,550,80,100,20);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0xff0000);
    SDL_WidgetProperties(SET_CAPTION,"");
    SDL_WidgetPropertiesOf(wid_orderunit,GET_CAPTION,&tablerow->orderunit);

  SDL_WidgetCreate(SDL_LABEL,38,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"onderdeel nr:");
  SDL_WidgetCreate(SDL_LABEL,158,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"omschrijving:");
  SDL_WidgetCreate(SDL_LABEL,278,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"vaknummer:");
  SDL_WidgetCreate(SDL_LABEL,398,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"verkoop prijs:");
  SDL_WidgetCreate(SDL_LABEL,518,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"inkoop prijs:");
  SDL_WidgetCreate(SDL_LABEL,638,185,120,15);
    SDL_WidgetProperties(SET_FONT,LargeBoldFont);
    SDL_WidgetProperties(SET_BG_COLOR,0xffffff);
    SDL_WidgetProperties(SET_FG_COLOR,0x0000ff);
    SDL_WidgetProperties(SET_CAPTION,"besteleenheid:");

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

    /* set table */

table=SDL_WidgetCreate(SDL_TABLE,38,200,720,300);/*x y w h */
        SDL_WidgetProperties(SET_VISIBLE_ROWS,    30);
        SDL_WidgetProperties(SET_VISIBLE_COLUMNS, 6);
        SDL_WidgetProperties(COLUMN_WIDTH, 1, 120 );
	SDL_WidgetProperties(SET_BG_COLOR,0x000000);
        SDL_WidgetProperties(SET_FONT,LargeBoldFont);
        SDL_WidgetProperties(SET_DATA_RETREIVAL_FUNCTION,tablestring);


return WarehouseaddWindow;		     
}  

int warehouseadd_EventHandler(SDL_Event event)
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
	    
	case SDLK_RETURN:
	  {
	    test++;
  SDL_WidgetPropertiesOf(wid_partnumber,GET_CAPTION,&tablerow->partnumber);
  SDL_WidgetPropertiesOf(wid_description,GET_CAPTION,&tablerow->description);
  SDL_WidgetPropertiesOf(wid_sectionnumber,GET_CAPTION,&tablerow->sectionnumber);
  SDL_WidgetPropertiesOf(wid_sellprice,GET_CAPTION,&sellprice);
  printf("%c\n",&sellprice);
  printf("%d\n",btw);
  // sellwithbtw = sellprice * btw;
  // printf("%d\n",sellwithbtw);
  SDL_WidgetPropertiesOf(wid_orderprice,GET_CAPTION,&tablerow->orderprice);
  SDL_WidgetPropertiesOf(wid_orderunit,GET_CAPTION,&tablerow->orderunit);
 
  SDL_WidgetPropertiesOf(wid_partnumber,SET_CAPTION,"");
  SDL_WidgetPropertiesOf(wid_description,SET_CAPTION,"");
  SDL_WidgetPropertiesOf(wid_sectionnumber,SET_CAPTION,"");
  SDL_WidgetPropertiesOf(wid_sellprice,SET_CAPTION,"");
  SDL_WidgetPropertiesOf(wid_orderprice,SET_CAPTION,"");
  SDL_WidgetPropertiesOf(wid_orderunit,SET_CAPTION,"");	
 
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
fwrite(&sellprice,1,strlen(&sellprice),fp); 
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


