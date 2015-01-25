#include "poussee.h"


#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>


int poussee_etre_valide (const plateau_siam* plateau,
			 int x,
			 int y,
			 orientation_deplacement deplacement)
{
  assert (plateau!=NULL);
  assert (coordonnees_etre_dans_plateau(x,y)== 1);
  assert (orientation_etre_integre_deplacement(deplacement) ==1);


  //Algorithme:
  //  D'abord on verifie que, la piece point vers la bonne direction.
  // 
  //  Apres, nous allons traverser a long de la directions de la poussee 
  //  Si on rencontre une animal qui pousse vers deplacement;
  //               On augmente la puissance
  //  sinon, on diminue la puissance
  
  int puissance_poussee=0;
  int x0 = x;
  int y0 = y;
  const piece_siam* marqueur = NULL;

  marqueur = plateau_obtenir_piece_info (plateau,x0,y0);// L'animal au debut ne pousse pas vers la bonne direction 
  if(deplacement != marqueur -> orientation)
    return 0;
  
  while (coordonnees_etre_dans_plateau(x0,y0)== 1 && plateau_exister_piece(plateau,x0,y0))
    {
      marqueur = plateau_obtenir_piece_info (plateau,x0,y0);
      if(marqueur ->orientation == deplacement)
	puissance_poussee ++; // Animal donne du puissance
      if(marqueur -> orientation == orientation_inverser(deplacement))
	puissance_poussee --; // Animal resiste

      coordonnees_appliquer_deplacement(&x0,&y0,deplacement);
    }
  if(puissance_poussee > 0)
    return 1;

  else 
    return 0;  

}



void poussee_realiser (plateau_siam* plateau,
		       int x,
		       int y,
		       type_piece animal,
		       orientation_deplacement deplacement,
		       condition_victoire_partie* condition_victoire)
{
  //Conditions:
  assert (plateau!=NULL);
  assert (coordonnees_etre_dans_plateau(x,y)== 1);
  assert (orientation_etre_integre_deplacement(deplacement) ==1);
  assert (condition_victoire != NULL);
  
  assert(poussee_etre_valide(plateau,x,y,deplacement)==1);

  // Les modification:

  piece_siam* this = NULL, *next = NULL; // Pointeur qui seront utilise dans le deplacement
  int x0=x,y0=y;                         // Coordonnees a utiliser  
  
  int nb_pas = 0;                        // Un competeur pour determiner le nombre de piece a deplacer
  
 
  orientation_deplacement retour = orientation_inverser(deplacement);

  if(coordonnees_etre_dans_plateau(x0,y0)==1 && plateau_exister_piece(plateau,x0,y0) )
    {
      coordonnees_appliquer_deplacement(&x0,&y0,deplacement); 
      // On se met dans la derniere case dans le colonnes de poussee
      nb_pas++;
    }
  // On va bouger vers l'arrierre
  while(nb_pas >=0 )
    {
      this = plateau_obtenir_piece(plateau,x0,y0);

      int x1 =x0, y1 =y0;
      coordonnees_appliquer_deplacement(&x1,&y1,deplacement);
 
      if ( coordonnees_etre_dans_plateau(x1,y1)==1) 
	// Si on  reste dans le plateau, on bouge
    	{
    	  next = plateau_obtenir_piece(plateau,x1,y1);
    	  piece_definir(next,this->type,this->orientation);
    	}

      // dans tout les cas , on vide.
      piece_definir_case_vide(this);

      coordonnees_appliquer_deplacement(&x0,&y0,retour);// On retourne vers l'arriere
      nb_pas--;
    }

  //Post-conditions
  assert(plateau_etre_integre(plateau)==1);
}
