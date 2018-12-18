//
//  testPlan.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 31.03.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "Vecteur3D.hpp"
#include "Plan.hpp"
#include <array>

using namespace std;



int main()
{
    cout<<"testPlan.cpp"<<endl<<endl;
    
    Vecteur3D vectNul; // nul par defaut
    Plan p1(vectNul, Vecteur3D ( 0, 0, 2)), p2(vectNul, Vecteur3D( 0, 1, 0)), p3( vectNul, Vecteur3D( 1, 0, 0));
    Plan p4(vectNul, Vecteur3D(1,1,1)),  p5(Vecteur3D(1,2,3), Vecteur3D( 1.1, 3.3, 2.2));
    
    
    //On teste la distance aux suivants points
    
    
    Vecteur3D v1( 0, 7, 0), v2( 0, 0, 10), v3( 2, 0, 0),v4( 5, -4, 6);
    
    //On teste la methode point plus proche pour le plan p1 et les 4 points de R^3
    
   
    array<Plan, 5> tab{p1,p2,p3,p4,p5};
    
    for(size_t i(0); i < tab.size(); i++)
    {
    
    cout<<" Plan d´origine "<<tab[i].get_position()<<" et de vecteur normale "<<tab[i].get_VecteurNormal()<<"  : "<< endl;
    cout<< endl;
    cout<<" distance a  "<<v1<<" : "<<tab[i].PointPlusProche(v1)<< endl;
    cout<<" distance a  "<<v2<<" : "<<tab[i].PointPlusProche(v2)<< endl;
    cout<<" distance a  "<<v3<<" : "<<tab[i].PointPlusProche(v3)<< endl;
    cout<<" distance a  "<<v4<<" : "<<tab[i].PointPlusProche(v4)<< endl;
        
        cout<< endl;
        cout<< endl;
    
    
    }
    
    
    
    
    
    
    
    
    return 0;
}
