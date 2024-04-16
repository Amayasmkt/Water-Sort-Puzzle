#ifndef __COLOR_H__
#define __COLOR_H__

// definition de couleurs
#define FG_SHIFT 30
#define BG_SHIFT 40
typedef enum {BLACK = 0, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE} ColorCode;


// prototypes
void clearScreen ();
void afficheCouleur (ColorCode, ColorCode, char); // FG, BG, char


#endif

