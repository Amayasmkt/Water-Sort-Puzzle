#ifndef __TUBE_H__
#define __TUBE_H__
#include "color.h"
#include <stdbool.h>

typedef struct {
  int id;
  int capacite;
  ColorCode * couches;
  int sommet;
} Tube;


void creerTube(Tube * ptr , int id, int capacite);
void detruireTube(Tube * ptr);
bool isTubeVide(Tube * ptr);
bool isTubePlein(Tube * ptr);
ColorCode getSommet(Tube * ptr);
void afficherTube(Tube * ptr);
bool insererTube(Tube * ptr , ColorCode c );
bool extraireTube( Tube * ptr , ColorCode * c);
void afficherTubeCouleur(Tube * ptr);

#endif
