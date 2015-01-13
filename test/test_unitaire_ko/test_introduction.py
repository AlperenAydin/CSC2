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
    

def main(): 
    c = introduction_nouvelle_piece (1,1,'>')
    print ('Lets go')
    directions = ['<','>','v','^']
    for y in range(1,4):
        for x in range(1,4):
            d= random.randint(0,3)
            orientation = directions[d] 
            creer_fichier(x,y,orientation)
main()
