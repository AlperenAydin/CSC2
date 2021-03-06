#include "piece_siam.h"

#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int piece_etre_integre(const piece_siam* piece)
{
  assert (piece!= NULL); // On verifie que le pointeur est valide
  //On verifie que on a des types valides
  assert (type_etre_integre        (piece -> type)        == 1);
  assert (orientation_etre_integre (piece -> orientation) == 1);

  // Si piece est un animal et possede un deplacement comme orientation
  // Il est valide
  if(type_etre_animal(piece->type) == 1) 
    {
      if(orientation_etre_integre_deplacement(piece ->orientation) == 1)
	return 1;
    }
  //Si piece n'est pas un animal et aucune deplacement
  //Il est valide
  else
    {
      if(orientation_etre_integre_deplacement(piece ->orientation) == 0)
	return 1;
    }

  return 0;
}

void piece_initialiser(piece_siam* piece)
{
    assert(piece!=NULL);

    piece_definir(piece,case_vide,aucune_orientation);

    assert(piece_etre_integre(piece));
}


int piece_etre_animal(const piece_siam* piece)
{
  assert(piece!=NULL);
  if(piece->type<3)
    {
      return 1;
    }
  else
    {
      return 0;
    }
}


int piece_etre_rocher(const piece_siam* piece)
{
  assert(piece!=NULL);
  if(piece->type==3)
    {
      return 1;
    }
  else{return 0;}

}
 

int piece_etre_case_vide(const piece_siam* piece)
{
  assert(piece!=NULL);
  if(piece->type==4)
    {
      return 1;
    } 
  else{return 0;}
}






void piece_definir(piece_siam* piece,type_piece type,orientation_deplacement orientation)
{
  assert (piece != NULL);
  piece->type=type;
  piece->orientation=orientation;
}


void piece_definir_rocher(piece_siam* piece)
{
  assert(piece!=NULL);
  piece_definir(piece,rocher,aucune_orientation);
  assert(piece_etre_integre(piece));
}

void piece_definir_case_vide(piece_siam* piece)
{
  assert(piece!=NULL);
  piece_definir(piece,case_vide,aucune_orientation);
  assert(piece_etre_integre(piece));
}





orientation_deplacement piece_recuperer_orientation_animal(const piece_siam* piece)
{
  assert(piece!=NULL);
  assert(piece_etre_integre(piece));
  assert(piece_etre_animal(piece));

  return piece->orientation;
}


void piece_afficher(const piece_siam* piece)
{
  assert(piece!=NULL);

  printf("%s,%s",type_nommer(piece->type),orientation_nommer(piece->orientation));
}

void piece_afficher_nom_cours(const piece_siam* piece)
{
  assert(piece!=NULL);

  printf("%s",type_nommer_nom_cours(piece->type));
  if(piece_etre_animal(piece))
    printf("-%s",orientation_nommer_nom_cours(piece->orientation));
}


piece_siam piece_correspondre_nom_cours(const char* nom_cours)
{
  assert(nom_cours!=NULL);
  assert(strlen(nom_cours)==3);

  //Possibilites:
  //
  // - nom vaut "***" -> case vide
  // - nom vaut "RRR" -> rocher
  // - nom commence par "e-" ou "r-"
  //     Alors il s'agit d'un animal.
  //     -> Recuperer le 3eme caractere
  //     -> Le convertir dans l'orientation de l'animal.
  //  - Si aucun des cas precedent, alors affiche erreur.

  piece_siam piece;
  piece_initialiser(&piece);


  if(strncmp(nom_cours,"***",3)==0)
    {
      piece_definir_case_vide(&piece);
    }
  else if(strncmp(nom_cours,"RRR",3)==0)
    {
      piece_definir_rocher(&piece);
    }
  else if((nom_cours[0]=='e' || nom_cours[0]=='r') && nom_cours[1]=='-')
    {
      const type_piece type=type_correspondre_caractere_animal(nom_cours[0]);
      const orientation_deplacement orientation=orientation_correspondre_caractere(nom_cours[2]);

      piece_definir(&piece,type,orientation);
    }
  else
    {
      printf("Erreur fonction %s\n",__FUNCTION__);
      abort();
    }

  return piece;

}


/************************************************************************
 *                               Tests 
 *************************************************************************/

void test_piece_etre_integre()
{
  piece_siam* piece  = malloc(sizeof(piece_siam)) ; // Allocation dynamique de notre piece de test
  piece -> type       = elephant;
  piece ->orientation = haut;

  char* validite        = NULL;
  
  int i=0;
  int j=0;

  //Nous allons tester pour les 20 combinaisons possibles 
  //et nous afficherons la validite
  for (i=0; i<4; i++)
    {
      piece->orientation = haut;
      for (j=0; j<5; j++ )
	{
	 
	  if(piece_etre_integre(piece) == 1)
	    validite = "valide";
	  else validite = "pas valide";

	  printf("%d vers %d est %s  \n"
		 ,piece->type
		 ,piece->orientation
		 , validite);
	  
	  piece->orientation ++; 
	}
      piece->type ++;
    }

  free(piece); // Liberation de l'espace

}

void test_piece_etre_animal()
{ 
  piece_siam* piece  = malloc(sizeof(piece_siam)) ;
  piece->type        =elephant;
  piece->orientation =0;
  int i;
  for(i=1;i<=4;i++)
    {
      if(piece_etre_integre(piece)==1)
	{
	  if(piece->type <3)
	    {
	      if(piece_etre_animal(piece)==1)
		{printf("Test ok");}
	      else{printf("Test ko");}
	    }
	}
      piece++;
    }
}

void test_piece_etre_rocher()
{ 
  piece_siam* piece= malloc(sizeof(piece_siam)) ;
  piece->type=elephant;
  piece->orientation =0;
  int i;
  for(i=1;i<=4;i++)
    {
      if(piece_etre_integre(piece)==1)
	{
	  if(piece->type==3)
	    {
	      if(piece_etre_rocher(piece)==1)
		{printf("Test ok");}
	      else{printf("Test ko");}
	    }
	}
      piece++;
    }
}

void test_piece_etre_cas_vide()
{ 
  piece_siam* piece= malloc(sizeof(piece_siam)) ;
  piece->type=elephant;
  piece->orientation =0;
  int i;
  for(i=1;i<=4;i++)
    {
      if(piece_etre_integre(piece)==1)
	{
	  if(piece->type==4)
	    {
	      if(piece_etre_case_vide(piece)==1)
		{printf("Test ok");}
	      else{printf("Test ko");}
	    }
	}
      piece++;
    }
}
