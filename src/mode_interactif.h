
/**
 * **************************************************
 * **************************************************
 *   _____ _____  ______   _
 *  / ____|  __ \|  ____| | |
 * | |    | |__) | |__    | |    _   _  ___  _ __
 * | |    |  ___/|  __|   | |   | | | |/ _ \| '_ \
 * | |____| |    | |____  | |___| |_| | (_) | | | |
 *  \_____|_|    |______| |______\__, |\___/|_| |_|
 *                                __/ |
 *                               |___/
 * **************************************************
 * **************************************************
 *
 *
 * Role general de ce fichier
 * --------------------------------------------------------------
 * Le mode interactif permet d'interfacer le jeu de siam avec
 *  la commande d'utilisateur en ligne de commande.
 *
 * Role des fonctions et note d'implementation
 * --------------------------------------------------------------
 * Les fonctions proposee dans le mode interactifs permettent de
 *  demarer le controle du jeu en ligne de commande.
 * Les fonctions du mode interactif ont pour but de dialoguer avec
 *  un utilisateur (potentiellement non programmeur). Elles
 *  affichent donc les messages de dialogue avec l'utilisateur.
 * Le mode interactif vient egalement realiser la synchronisation
 *  des fonctions de gestion du jeu (demande d'action, realisation
 *  d'actions, affichage informatif, enregistrement et lecture
 *  a partir de fichiers et affichage du vainqueur).
 * Comme les fonctions traitent de demandent utilisateurs elles
 *  ne peuvent pas presuposer de contraintes de type "assertions"
 *  sur les variables completees interactivement.
 *
 *
 * Notion d'abstraction
 * --------------------------------------------------------------
 * Ce niveau d'abstraction a pour role de realiser l'interface entre
 *  une entree sous forme de demande utilisateur vers l'API du programme.
 * Le mode interactif ne vient utiliser que des fonctions de hauts
 *  niveaux du jeu qu'il utilise comme une librairie externe.
 */



#ifndef MODE_INTERACTIF_H
#define MODE_INTERACTIF_H

#include "jeu_siam.h"
#include "joueur.h"



/**
 * Fonction mode_interactif_lancer():
 * *************************
 *    Permet d'effectuer des lancers à travers l'utilisation de toutes les fonctions qui figurent après celle-ci.
 *
 *    Necessite:
 *      - Rien du tout
 *    Garantie:
 *      - Le bon déroulement des lancers tant que personne n'a gagné
 */


void mode_interactif_lancer();

/**
 * Fonction mode_interactif_introduire_nouvelle_piece:
 * *************************
 *  Permet d'introduire une nouvelle pièce sur le plateau  
 *
 *    Necessite:
 *      - Deux coordonnees entieres,une orientation,un jeu siam et un pointeur sur entier
 *    Garantie:
 *      - L'introduction d'une nouvelle pièce si les coordonnees sont dans [0,NBR_CASES]x[0,NBR_CASES] et que l'orientation correspond bien à une orientation intègre
 *        c'est à dire que les paramètres sont valides puis la réalisation d'un coup si celui ci est "valide" et enfin la fin du jeu si le coup précédant est "victorieux".
 *      - Un message d'erreur si il est impossible d'introduire une pièce aux coordonnées indiquées un autre message d'erreur si le coup n'est pas "valide".
 */


void mode_interactif_introduire_nouvelle_piece(jeu_siam* jeu,int x,int y,orientation_deplacement orientation,int* victoire);

/**
 * Fonction mode_interactif_deplacer_piece:
 * *************************
 *    Permet de déplacer une pièce 
 *
 *    Necessite:
 *      - Deux coordonnees entieres,une orientation,un jeu siam,un pointeur sur entier 
 *    Garantie:
 *      - Le déplacement d'une pièce si les paramètres sont "valides" la sauvegarde du déplacement si le coup est dit "valide" et le changement d'état de la variable victoire dans le cas d'un coup victorieux
 *      - L'affichage de message d'erreurs dans le cas ou les paramètres ne sont pas valides (ex coordoonées en dehors du plateau)
 *        et un second message d'erreur dans le cas ou c'est le coup qui n'est pas valide.
 */

void mode_interactif_deplacer_piece(jeu_siam* jeu,int x,int y,orientation_deplacement deplacement,orientation_deplacement orientation,int* victoire);
/**
 * Fonction mode_interactif_changer_orientation:
 * *************************
 *    Permet de changer l'orientation d'une pièce 
 *
 *    Necessite:
 *      - Deux coordonnees entieres,un jeu siam et une varaibale de type orientation
 *    Garantie:
 *      - Le changement d'orienation d'une pièce si les paramètres sont "valides" ainsi que la sauvegarde du déplacement si le coup est dit "valide".
 *      - L'affichage de message d'erreurs dans le cas ou les paramètres ne sont pas valides (ex coordoonées en dehors du plateau)
 *        et un second message d'erreur dans le cas ou c'est le coup qui n'est pas valide.
 */

void mode_interactif_changer_orientation(jeu_siam* jeu,int x,int y,orientation_deplacement orientation);
/**
 * Fonction mode_interactif_sauvegarder_jeu_fichier:
 * *************************
 *    Permet de sauvegarder le jeu dans son état actuel (l'état juste avant l'appel de cette fonction).
 *
 *    Necessite:
 *      -Un jeu Siam
 *    Garantie:
 *      - La sauvegarde du jeu dans le cas ou le pointeur sur le jeu est non NULL et également "intègre". 
 */     

void mode_interactif_sauvegarder_jeu_fichier(const jeu_siam* jeu);

/**
 * Fonction mode_interactif_lire_fichier:
 * *************************
 *    Permet de lire fichier
 *
 *    Necessite:
 *      -Un pointeur sur un jeu Siam et un pointeur sur une chaîne de caractère
 *    Garantie:
 *      - La lecture du fichier puis la sauvegarde du jeu dans le cas ou le fichier existe et est "accessible"
 *   - L'affichage de message d'erreur dans le cas contraire spécifiant que le fichier n'est pas accessible.
 * */


void mode_interactif_lire_fichier(jeu_siam* jeu,const char* filename);


/**
 * Fonction mode_interactif_parametres_etre_valides:
 * *************************
 *    Verifie que les paramètres sont valides c'est à dire que les coordonnées tapées par l'utilisateur sont bien dans le plateau et que l'orientation demandée est intègre
 *
 *    Necessite:
 *      - Deux coordonnees entieres,une orientation,un jeu siam
 *    Garantie:
 *      - Un retour valant 1 si les coordonnees sont dans [0,NBR_CASES]x[0,NBR_CASES] et que l'orientation correspond bien à une orientation intègre
 *      - Un retour valant 0 sinon.
 */

int mode_interactif_parametres_etre_valides(const jeu_siam* jeu,int x,int y,orientation_deplacement orientation);


#endif
