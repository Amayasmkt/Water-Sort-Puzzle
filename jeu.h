#ifndef __JEU_H__
#define __JEU_H__

#include "tube.h"

typedef struct {
  int nbTubes;
  int nb_couleurs ;
  int nb_couches;
  Tube * tubes; //tableau dynamique
  int num_tour;
  } Jeu;
  
void creerJeu(Jeu * ptr , int nbr_tubes, int nbr_couches, int nbr_couleurs);
void detruireJeu(Jeu * ptr);
void afficherJeu(Jeu * ptr);
void jouer(Jeu * ptr);
void chargerJeu(Jeu * ptr , char * filename);
bool isValide(Jeu * ptr , int dep , int arr);


#endif