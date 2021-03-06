#ifndef POUSSEE_H
#define POUSSEE_H


#include "plateau_siam.h"
#include "condition_victoire_partie.h"
#include "coordonnees_plateau.h"


/***
* Fonction poussee_etre_valide:
*******************************
* Vérifie si il est possible de réaliser une poussee qui débute aux cordonées (x,y) dans l'orientation definie;
* Note: Les coordonées (x,y) designent la premiere piece rencontree dans la poussee.
*
*
*  Necessite :
*    -Un pointeur non NULL vers un plateau integre non modifiable
*    - Deux coordonnes entieres (x,y) designant une piece non vide integre du plateau
*    -Une orientation de poussee designant une direction integre
*   Garantie:
*    -Un retour valant 1 si la poussee est possible
*    -Un retour valant 0 sinon
*
*/

int poussee_etre_valide (const plateau_siam* plateau,
			 int x,
			 int y,
			 orientation_deplacement deplacement);


/**
*Fonction poussee_realiser:
***************************
*   Realise une poussee sur un plateau en supposant que celle-ci est réalisable.
*
* Necessite:
*-Un pointeur non NULL vers un plateau integre modifiable
*-Deux coordonnees entieres (x,y) designant une piece non vide integre du plateau.
*-Un type d'animal à déplacer.
*-Une orientation de poussee designant une direction integre.
*-Un pointeur non NULL vers une condition de victoire modifiable.
*
*Garantie:
*-Un plateau integre mis a jour en ayant la poussee
*
*/

void poussee_realiser (plateau_siam* plateau,
		       int x,
		       int y,
		       type_piece animal,
		       orientation_deplacement deplacement,
		       condition_victoire_partie* condition_victoire);

#endif
