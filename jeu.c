#include "jeu.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


//fonction utilisées dans la focntion jouer:
void doMove (Jeu * ptr , int dep , int arr){
   ColorCode c ;
   printf("on fait le mouvement de %d vers %d\n", dep, arr);
   extraireTube (ptr -> tubes+dep , &c);
   insererTube(ptr -> tubes+arr , c);
   ptr-> num_tour ++;
}




bool isValide(Jeu * ptr , int dep , int arr){
   if((dep<0) || (dep>= ptr-> nbTubes)) return false;
   if ((arr<0) || (arr>= ptr -> nbTubes)) return false ;
  if (dep ==arr) return false;
   if(isTubeVide(ptr -> tubes+dep)) return false;
  if (isTubePlein(ptr -> tubes+arr)) return false;
  return true ;
}


bool isFini(Jeu * ptr ){
  for (int t = 0 ; t < ptr -> nbTubes ;++t){
      Tube * tube = ptr->tubes+t;
      if (!isTubeVide(tube)){
         for (int l = 1 ; l < tube -> capacite ; ++l){
            if(tube -> couches[0] != tube -> couches[l]) return false;
         }
      }
   }
   return true;
}

void creerJeu(Jeu * ptr , int nbr_tubes, int nbr_couches, int nbr_couleurs){
   ptr -> nbTubes = nbr_tubes;
   ptr -> nb_couleurs = nbr_couleurs;
   ptr -> nb_couches = nbr_couches;
   ptr -> tubes = malloc( nbr_tubes * sizeof(Tube));
   for (int t = 0; t < nbr_tubes; ++t)
      creerTube(ptr->tubes+t, t, nbr_couches);
   ptr -> num_tour = 0;
}


void detruireJeu(Jeu * ptr ){
   free (ptr->tubes);
}

void afficherJeu(Jeu * ptr){
   printf("tour = %d \n" , ptr->num_tour);
   for (int t = 0 ; t < ptr->nbTubes; ++t){
      //afficherTubeCouleur(ptr->tubes+t);
      afficherTube(ptr->tubes+t);
   }
}

void chargerJeu(Jeu * ptr , char * filename){
   FILE * f = fopen(filename,"rt");
   if (f == NULL)
   {
      fprintf(stderr, "erreur: fichier %s pas ouvert\n", filename);
      exit(1);
   }
   fscanf(f,"%d%d%d",&(ptr->nbTubes),&(ptr->nb_couleurs),&(ptr->nb_couches));

   creerJeu(ptr,ptr->nbTubes,ptr->nb_couleurs,ptr->nb_couches);

   for (int t = 0; t < ptr->nbTubes; ++t) {
      for (int l=0; l<ptr->tubes->capacite; ++l) {
      ColorCode c;
      fscanf(f,"%u",&c);
      if (c != BLACK) {
         insererTube(ptr->tubes+t,c);
      }
   }
   }
   fclose(f);
} 


void jouer(Jeu * ptr ) {
   ptr->num_tour = 0;
   afficherJeu (ptr );
   while (!isFini(ptr)){
      int dep,arr;

      do{
         scanf ("%d%d", &dep , &arr);

      }while (!isValide(ptr,dep,arr));
       
      doMove(ptr , dep ,arr);
      afficherJeu(ptr);

   }  

   printf("Victoire !\n");
}





