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
  if(direction_deplacement<4)
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

  switch (orientation)
    {
    case '<': 
      return  gauche;
    case '>': 
      return droite;
    case '^': 
      return haut;
    case 'v': 
      return bas;
      
    }
 
  return aucune_orientation;
}

/***********************************************************************************
 *        Les Tests
 ***********************************************************************************/


void test_orientation_etre_integre_deplacement()
{

  //On teste pour chaque valeur associée au 4 déplacements que la fonction retourne 1
  //Si il n'y a pas de déplacement la fonction retourne 0
  puts("Test orientation_etre_integre_deplacement ");

  if(orientation_etre_integre_deplacement(haut) !=1)
    puts("haut KO");

  if(orientation_etre_integre_deplacement(bas) !=1)
    puts("bas KO");

  if(orientation_etre_integre_deplacement(droite) !=1)
    puts("droite KO");

  if(orientation_etre_integre_deplacement(gauche) !=1)
    puts("gauche KO");

  if(orientation_etre_integre_deplacement(aucune_orientation) != 0)
    puts("aucune_orientation KO");

  int k= 0;
  // On teste pour les non deplacements
  for(k=5;k<20;++k)
    if(orientation_etre_integre_deplacement(k)!=0)
      printf("valeur %d KO \n",k);
}



void test_orientation_correspondre_caractere()
{

    puts("Test orientation_correspondre_caractere ");

    // On place les différents caractères dans un tableau de caractère
    // afin de pouvoir les comparer plus aisément dans notre boucle for
    char liste[5] = "^v<>";
    unsigned int i = 0;
    for(i=0; i<4; i++)
      if(orientation_correspondre_caractere(liste[i]) != i)
	printf("%c KO. \n",liste[i]);

}
