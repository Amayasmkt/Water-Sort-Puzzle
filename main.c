#include "jeu.h"
#include <string.h>

int main(int argc , char ** argr){
  Jeu jeu ;
  char filename[255] = "level1.txt";

  if (argc > 1) strcpy(filename,argr[1]);
  chargerJeu (&jeu , filename);
  jouer(&jeu);
  detruireJeu(&jeu);
  return 0;
}
