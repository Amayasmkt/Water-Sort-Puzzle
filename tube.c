#include "tube.h" 
#include <stdio.h>
#include <stdlib.h>

void creerTube(Tube * ptr , int id , int capacite ){
    ptr -> id = id ;
    ptr -> capacite = capacite ;
    ptr -> couches = malloc (capacite * sizeof (ColorCode));
    for(int i = 0; i < ptr->capacite; ++i)  ptr->couches[i] = BLACK;
    ptr -> sommet = 0;
}


void detruireTube(Tube * ptr){
    free(ptr -> couches );
    ptr-> id = ptr -> capacite = ptr -> sommet = 0;
    ptr -> couches = NULL;
}


bool isTubeVide(Tube * ptr ) {
    return (ptr -> sommet == 0);
}


bool isTubePlein(Tube * ptr){
     return (ptr -> sommet == ptr -> capacite);
}


ColorCode getSommet(Tube * ptr ){
    if (isTubeVide(ptr)){
        return 0 ;
    }else{
        return ptr -> couches [ptr -> sommet -1];
    } 
}




bool insererTube(Tube * ptr , ColorCode c ){
    if( isTubePlein(ptr)){
        return false;
    }else {
        ptr -> couches[ptr->sommet] = c;
        ptr -> sommet ++;
        return true ;
    }
}


void afficherTube(Tube * ptr ){
    printf( "Tube  %d : %d / %d [" , ptr -> id , ptr -> sommet , ptr -> capacite );
   
    for (int l = 0 ; l < ptr -> capacite ; ++l){
        printf(" %d" , ptr -> couches[l]);
    } 
    printf("] \n");
}

void afficherTubeCouleur(Tube * ptr ) {
    printf ("Tube %d : %d /%d [ " ,ptr -> id , ptr->sommet , ptr->capacite );
    for (int l = 0 ; l < ptr->capacite ; ++l){
        afficheCouleur (0,ptr->couches[l] ,' ');
    }
    printf ("] \n ");
}



bool extraireTube(Tube * ptr , ColorCode * c){
    if (isTubeVide(ptr)){
        return false ; 
    }
    else {
        ptr -> sommet --;
        *c = ptr -> couches [ptr -> sommet ];
        ptr -> couches [ptr -> sommet ] = 0;
        return true ;
    }
}


