************************************************************
//****Prototype///*** fonction poussee_etre_valide*******//
***********************************************************
poussee_etre_valide(jeu,int x,int y,orientation)
{
 assert(jeu!=NULL);
 assert(type_etre_integre(type)!=0);
 assert(orientation_etre_integre_deplacement(orientation)!=0);
 assert(coordonnees_etre_dans_plateau(x,y)!=0);
 if((animal1->orientation==animal2->orientation) && (orientation==haut) && (type_etre_animal(animal)==1 +****truc à rejouter voir en bas ) //Ici je voulais dire que les 2 animaux ne doivent pas être face à face pour effectuer une poussée et que l'on ne peut effectuer une poussée seulement vers le haut.Et seul les animaux peuvent effectuer une poussée les rocher ne poussent pas d'ou l'appel de la fonction type être animal.
{                                                                                                  
 return 1;
}
 else
{
 return 0;
}
}
****************************************************************************************
//Il y a une autre conditions à placer dans le if mais je ne sais pas comment faire.Unrhino et un éléphant ont la même force de poussee donc pour pousser un éléphant ou un rhino il doit y avoir 2 animaux en face (éléphant ou rhino peu importe) et etc.Voila voila encore désolé de t'abbandoner j'en ferais plus pour le prochain tp d'info.Biz bon week end.
