//
//  exerciceP8.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 15.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include <stdio.h>

#include"Systeme.hpp"
#include "GrainLJTUn.hpp"
#include "GrainLJTDeux.hpp"
#include "Plan.hpp"

int main(){
    std::cout<<"exerciceP8.cc"<<std::endl;
    
    
    Systeme s;
    Grain* g1 = new GrainLJTUn(Vecteur3D(0.0,0.0,0.0),Vecteur3D(0.0,0.0,0.0),1,0.4); //p,v,m_v,r,f
    Grain* g2 = new GrainLJTUn(Vecteur3D(1.0,0.0,0.0),Vecteur3D(0.0,0.0,0.0),1,0.4);
    Grain* g3 = new GrainLJTUn(Vecteur3D(0.5,sqrt(3)/2,0.0),Vecteur3D(0.0,0.0,0.0),1,0.4);
    Grain* g4 = new GrainLJTDeux(Vecteur3D(0.5,sqrt(3)/6,sqrt(6)/3),Vecteur3D(0.0,0.0,0.0),1,0.4);
    Obstacle* p = new Plan(Vecteur3D(0,0,-0.9), Vecteur3D(0,0,1));
    
    g1->masseVolumique(0.268083);
    g2->masseVolumique(0.268083);
    g3->masseVolumique(0.268083);
    g4->masseVolumique(0.268083);
    
    s.ajouterGrain(g1);
    s.ajouterGrain(g2);
    s.ajouterGrain(g3);
    s.ajouterGrain(g4);
    
    s.ajouterObstacle(p);
    
    s.affiche(std::cout);
}

/*
 ./exerciceP8
 Grain L-J de type 1 : [ pos= (0 0 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (1 0 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.5 0.866025 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
 Grain L-J de type 2 : [ pos= (0.5 0.288675 0.816497), v= (0 0 0), m= 0.268083, r= 0.4 ]
 et des 1 obstacles suivants :
 Plan d'origine (0 0 -0.9) et de normale (0 0 1)
 */
