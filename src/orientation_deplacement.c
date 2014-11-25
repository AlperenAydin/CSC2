#include "orientation_deplacement.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

int orientation_etre_integre(orientation_deplacement orientation)
{
    // L'enumeration designe une orientation integre si elle est compris
    //  entre 0 et 5.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 5 pour designer un type valide.

    if(orientation<5)
        return 1;
    return 0;
}

int orientation_etre_integre_deplacement(orientation_deplacement direction_deplacement)
{
 // L'enumeration designe un deplacement integre si il  est compris entre 0 et 4.
    // Une enumeration etant un type non signee, il est forcement positif.
    // Il suffit donc que type soit < 4 pour designer un type valide.
  if(orientations_deplacement<4)
    return 1;
  else
    return 0;
}

const char* orientation_nommer(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere correspondante.

    switch(orientation)
    {
    case haut:
        return "haut";
    case bas:
        return "bas";
    case gauche:
        return "gauche";
    case droite:
        return "droite";
    case aucune_orientation:
        return "aucune";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



const char* orientation_nommer_nom_cours(orientation_deplacement orientation)
{
    // "Look up table" (LUT) convertissant une orientation vers
    //    la chaine de caractere courte correspondante.

    switch(orientation)
    {
    case haut:
        return "^";
    case bas:
        return "v";
    case gauche:
        return "<";
    case droite:
        return ">";
    case aucune_orientation:
        return "????";
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}

orientation_deplacement orientation_inverser(orientation_deplacement orientation)
{
    assert(orientation_etre_integre_deplacement(orientation));

    // "Look up table" (LUT) convertissant une orientation vers
    //    son oppose
    // haut   <-> bas
    // droite <-> gauche


    switch(orientation)
    {
    case haut:
        return bas;
    case bas:
        return haut;
    case gauche:
        return droite;
    case droite:
        return gauche;
    default:
        printf("Erreur, orientation piece %d non reconnue",orientation);
        abort();
    }

    puts("Ne devrait jamais entrer sur cette ligne");
    abort();
}



int orientation_caractere_etre_integre(char orientation)
{
    if(orientation=='<' || orientation=='>' || orientation=='^' || orientation=='v')
        return 1;
    return 0;
}


orientation_deplacement orientation_correspondre_caractere(char orientation)
{
  assert (orientation_caractere_etre_integre( orientation));
 
  orientation_deplacement deplacement = haut;

  switch (orientation)
    {
    case '<': 
      deplacement = gauche;

    case '>': 
      deplacement = droit;

    case '^': 
      deplacement = haut;
    case 'v': 
      deplacement = bas;
      
    }
 
  return deplacement;
}
