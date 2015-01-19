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
 

  assert(jeu!=NULL);
 
  int Valid=1;

  type_piece piece_du_joueur = joueur_obtenir_animal (jeu->joueur);

  if(coordonnees_etre_dans_plateau(x,y)==0)//On vérifie que les coordonées sont valides
    {
      puts("Coordonnees pas le plateau");
      Valid=0;
    }  
  
  if(plateau_exister_piece(&(jeu->plateau),x,y)==1)
    {
      puts("Il ya deja quelque chose");
      Valid=0;
    } //On vérifie que la pièce existe sur ce plateau
  
  if (plateau_modification_introduire_piece_etre_possible(&(jeu->plateau),x,y,piece_du_joueur,orientation)==0)
    {
      puts("modifcation pas possible");
      Valid =0;
    }

  if(Valid==1)
    {
      plateau_modification_introduire_piece(&(jeu->plateau),x,y,piece_du_joueur,orientation,NULL);
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



coup_jeu api_siam_tenter_deplacer_piece_si_possible(jeu_siam* jeu,
                                                    int x,int y,
                                                    orientation_deplacement deplacement,
                                                    orientation_deplacement orientation)
{
   

  assert(jeu!=NULL);
 
  int Valid=1;
  int poussee = 0;

  const piece_siam* piece = plateau_obtenir_piece_info(&jeu->plateau,x,y);

  if(coordonnees_etre_dans_plateau(x,y)==0)//On vérifie que les coordonées sont valides
    {
      Valid=0;
    }  
  
  else if(plateau_exister_piece(&(jeu->plateau),x,y)==0)
    {
      Valid=0;
    } //On vérifie que la pièce existe sur ce plateau
  
  else if(joueur_etre_type_animal(jeu->joueur,piece->type)==0)
    {
      Valid=0;
    }//On vérifie que le type du joueur correspond bien au type de la pièce
    
  else if (plateau_modification_deplacer_piece_etre_possible(&(jeu->plateau),x,y,deplacement,orientation)==0) // Le deplacement n'est pas possible
    {
      if (poussee_etre_valide (&(jeu->plateau),x,y,deplacement) ==1)
	{
	  poussee = 1;
	}
      else 
	{
	  Valid = 0;
	}
    }

  if(Valid==1)
    {
      if(poussee ==1)
	{
	  condition_victoire_partie condition_victoire;
	  condition_victoire_initialiser (&condition_victoire);
	  poussee_realiser(&(jeu->plateau),x,y,jeu->joueur,deplacement,condition_victoire);
	}
      else
	{
	  plateau_modification_deplacer_piece(&(jeu->plateau),x,y,deplacement,orientation,NULL);
	}
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



coup_jeu api_siam_tenter_changer_orientation_piece_si_possible(jeu_siam* jeu,int x,int y,orientation_deplacement orientation)
{
 

  assert(jeu!=NULL);
 
  int Valid=1;

  const piece_siam* piece = plateau_obtenir_piece_info(&jeu->plateau,x,y);

  if(coordonnees_etre_dans_plateau(x,y)==0)//On vérifie que les coordonées sont valides
    {
      Valid=0;
    }  
 
  else if(plateau_exister_piece(&(jeu->plateau),x,y)==0) //On vérifie que la pièce existe sur ce plateau
    {
      Valid=0;
    } 
  
  else if(joueur_etre_type_animal(jeu->joueur,piece->type)==0) //On vérifie que le type du joueur correspond bien au type de la pièce
    {
      Valid=0;
    }
    
  else if (plateau_modification_changer_orientation_piece_etre_possible(&(jeu->plateau),x,y,orientation)==0)
    {
      Valid =0;
    }

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

