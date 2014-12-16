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


  int puissance_poussee=0;
  //Algorithme:
  //  Nous allons traverser a long de la directions de la poussee 
  //  Si on rencontre une animal qui pousse vers deplacement;
  //               On augmente la puissance
  //  sinon, on diminue la puissance

  int x0 = x;
  int y0 = y;
  const piece_siam* marqueur = NULL;
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
		       condition_victoire_partie condition_victoire)
{
  //Conditions:
  assert (plateau!=NULL);
  assert (coordonnees_etre_dans_plateau(x,y)== 1);
  assert (orientation_etre_integre_deplacement(deplacement) ==1);

  assert(poussee_etre_valide(plateau,x,y,deplacement));

  // Les modification:

  piece_siam* this = NULL, *next = NULL;
  int x0=x,y0=y;
  int x1=x,y1=y;

if(coordonnees_etre_dans_plateau(x0,y0)==1 && plateau_exister_piece(plateau,x0,y0) )
    {
      coordonnees_appliquer_deplacement(&x1,&y1,deplacement);
      poussee_realiser(plateau,x1,y1,animal,deplacement,condition_victoire);
      
      this = plateau_obtenir_piece(plateau,x0,y0);
      
      if ( coordonnees_etre_dans_plateau(x1,y1)==1) // Si on  reste dans le plateau on bouge
	{
	  next = plateau_obtenir_piece(plateau,x0,y0);
	  piece_definir(next,this->type,this->orientation);
	}
      piece_definir_case_vide(this); // dans tout les cas , on bouge.
      
    }

  

  //Post-conditions
  assert(plateau_etre_integre(plateau)==1);
}
