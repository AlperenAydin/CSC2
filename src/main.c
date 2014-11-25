
#include "piece_siam.h"
#include "plateau_siam.h"
#include "jeu_siam.h"
#include "api_siam.h"
#include "mode_interactif.h"

#include <stdio.h>


void test_lancer()
{
  test_type_etre_animal();
  test_type_correspondre_caractere_animal(); 
  test_orientation_correspondre_caractere();
  test_orientation_etre_integre_deplacement();
}


int main()
{

  test_lancer();
  return 0 ;
}
