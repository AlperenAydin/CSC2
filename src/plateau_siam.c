#include "plateau_siam.h"
#include "entree_sortie.h"

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>



void plateau_initialiser(plateau_siam* plateau)
{
    // Initialise l'ensemble des cases du plateau a piece_vide
    // sauf les 3 cases du milieu avec un rocher (2,1), (2,2) et (2,3)
    //
    // L'etat de l'echiquier initial est le suivant:
    //
    // [4] *** | *** | *** | *** | *** |
    // [3] *** | *** | *** | *** | *** |
    // [2] *** | RRR | RRR | RRR | *** |
    // [1] *** | *** | *** | *** | *** |
    // [0] *** | *** | *** | *** | *** |
    //     [0]   [1]   [2]   [3]   [4]
    //


    int kx=0;
    for(kx=0;kx<NBR_CASES;++kx)
    {
        int ky=0;
        for(ky=0;ky<NBR_CASES;++ky)
        {
            piece_siam* piece=plateau_obtenir_piece(plateau,kx,ky);
            assert(piece!=NULL);

            if(ky==2 && (kx>=1 && kx<=3) )
                piece_definir_rocher(piece);
            else
                piece_definir_case_vide(piece);
        }
    }

    assert(plateau_etre_integre);
}


int plateau_denombrer_type(const plateau_siam* plateau,type_piece type)
{
  assert(plateau!=NULL);


  // Algorithme:
  //
  //  Initialiser compteur <- 0
  //  Pour toutes les cases du tableau
  //     Si case courante est du type souhaite
  //        Incremente compteur
  //  Renvoie compteur


  int compteur=0;
  int kx=0;

  for(kx=0;kx<NBR_CASES;++kx)
    {
      int ky=0;
      for(ky=0;ky<NBR_CASES;++ky)
        {
	  const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);

	  if(piece->type==type)
	    compteur++;
        }
    }

  return compteur;
}

int plateau_etre_integre(const plateau_siam* plateau)
{
  assert(plateau!=NULL);


  // Verification de l'integrite en 4 etapes:
  //  1. Verification que l'ensemble des pieces du plateau
  //     sont integres.
  //  2. Verification du nombre d'elephants.
  //  3. Verification du nombre de rhinoceros.
  //  4. Verification du nombre de rochers.


  int kx=0;
  for(kx=0;kx<NBR_CASES;++kx)
    {
      int ky=0;
      for(ky=0;ky<NBR_CASES;++ky)
        {
	  const piece_siam* piece=plateau_obtenir_piece_info(plateau,kx,ky);
	  assert(piece!=NULL);

	  if(piece_etre_integre(piece)==0)
	    return 0;
        }
    }

  int nbr_elephant=plateau_denombrer_type(plateau,elephant);
  int nbr_rhino=plateau_denombrer_type(plateau,rhinoceros);
  int nbr_rocher=plateau_denombrer_type(plateau,rocher);

  if(nbr_elephant<0 || nbr_elephant>NBR_ANIMAUX)
    return 0;
  if(nbr_rhino<0 || nbr_rhino>NBR_ANIMAUX)
    return 0;
  if(nbr_rocher<0 || nbr_rocher>NBR_ROCHERS)
    return 0;



  return 1;
}

piece_siam* plateau_obtenir_piece(plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));

    piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}

const piece_siam* plateau_obtenir_piece_info(const plateau_siam* plateau,int x,int y)
{
    assert(plateau!=NULL);
    assert(coordonnees_etre_dans_plateau(x,y));

    const piece_siam* piece=&(plateau->piece[x][y]);

    return piece;
}

int plateau_exister_piece(const plateau_siam* plateau,int x,int y)
{
  assert(plateau!=NULL);
  assert(coordonnees_etre_dans_plateau(x,y));

  const piece_siam* piece=plateau_obtenir_piece_info(plateau,x,y);
  assert(piece!=NULL);

  if(piece->type!=case_vide)
    return 1;
  return 0;
}

void plateau_afficher(const plateau_siam* plateau)
{
  assert(plateau!=NULL);

  //utilisation d'une fonction generique d'affichage
  // le parametre stdout permet d'indiquer que l'affichage
  // est realise sur la ligne de commande par defaut.
  entree_sortie_ecrire_plateau_pointeur_fichier(stdout,plateau);

}



