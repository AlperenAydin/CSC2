#include "api_siam.h"
#include "plateau_modification.h"
#include "joueur.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

coup_jeu api_siam_tenter_introduire_nouvelle_piece_si_possible(jeu_siam* jeu,
                                                               int x,int y,
                                                               orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
    //coder cette fonction
    coup_jeu coup;
    coup_jeu_initialiser(&coup);
    return coup;
}



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
 

  assert(jeu!=NULL);
 
  int Valid=1;

  const piece_siam* piece = plateau_obtenir_piece_info(&jeu->plateau,x,y);

  if(coordonnees_etre_dans_plateau(x,y)==0)//On vérifie que les coordonées sont valides
    {
      Valid=0;
    }  
  
  if(plateau_exister_piece(&(jeu->plateau),x,y)==0){Valid=0;} //On vérifie que la pièce existe sur ce plateau
  
  if(joueur_etre_type_animal(jeu->joueur,piece->type)==0){Valid=0;}//On vérifie que le type du joueur correspond bien au type de la pièce
    
  if (plateau_modification_changer_orientation_piece_etre_possible(&(jeu->plateau),x,y,orientation)==1){Valid =0;}

  if(Valid==1)
    {
      plateau_modification_changer_orientation_piece(&(jeu->plateau),x,y,orientation);
      coup_jeu coup;
      coup_jeu_initialiser(&coup);
      coup.valide = 1;
      printf("Le coup est valide \n");
      return coup;

    }
  else
    {
      coup_jeu coup;
      coup_jeu_initialiser(&coup);
      coup.valide = 0;
      printf("Le coup n'est pas valide \n");
      return coup;
      
    }
}

