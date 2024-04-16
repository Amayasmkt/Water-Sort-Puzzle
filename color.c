#include "color.h"

#include <stdio.h>



void clearScreen ()
{
  printf("\e[1;1H\e[2J");
}


void afficheCouleur (ColorCode fg, ColorCode bg, char c)
{
  printf("\033[%d;%dm%c\033[m", FG_SHIFT + fg, BG_SHIFT + bg, c);
}