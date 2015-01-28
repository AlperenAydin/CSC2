#!/usr/bin/python

import os
import random

def introduction_nouvelle_piece(x,y,orientation):
    commande = "> n %d %d %c \n"%(x,y,orientation) 
    return commande


def creer_fichier(x,y,orientation):
    filename = 'test_unitaire_ko_introduction_piece_%d_%d.txt'%(x,y)
    fo = open( filename,"w")

    commande    = introduction_nouvelle_piece(x,y,orientation)
    description = "# " +filename +"\n# \n"+ "#Tenter d'introduire piece a (%d,%d) \n"%(x,y)
    attendu     = "#comportement attendu: \n"+ "#Le piece n'est pas introduit a (%d,%d) avec %s"%(x,y,orientation) 

    fo.write( description
              +"\n"
              +"> i \n"
              +commande
              +"> fin \n"
              +"\n"
              +attendu)
    
def sortie_introduction(x,y,orientation):
    sortie = "joueur 0 (elephant) \n"
    rocher= [(1,2),(2,2),(3,2)];

    l = range(0,5)
    list.reverse(l)

    for y_i in l:
        sortie = sortie + "[%d]"%(y_i,)

        for x_i in range(0,5):
            if ((x_i,y_i) in rocher):
                addition = " RRR |"
            else :
                addition = " *** |"
                
            sortie = sortie +addition;

        sortie = sortie + "\n"

    sortie = sortie+ "    [0]   [1]   [2]   [3]   [4]" + "\n"

    filename = 'test_unitaire_ko_introduction_piece_%d_%d_sortie.txt'%(x,y)
    fo = open( filename,"w")
    fo.write(sortie)
    fo.write("\n")

    
                

def main(): 
    c = introduction_nouvelle_piece (1,1,'>')
    print ('Lets go')
    directions = ['<','>','v','^']
    for y in range(1,4):
        for x in range(1,4):
            d= random.randint(0,3)
            orientation = directions[d] 
            creer_fichier(x,y,orientation)
            sortie_introduction(x,y,orientation)
main()
