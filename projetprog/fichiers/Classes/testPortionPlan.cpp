//
//  testPortionPlan.cpp
//  ProjetProg
//
//  Created by alex bonell on 27/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Portion_Plan.hpp"
using namespace std;
#include <iostream>



int main()
{
    
    PortionPlan p1(Vecteur3D(0,0,0), Vecteur3D(1,0,0), 3.0, 4.0, Vecteur3D(0,1,0));
    Vecteur3D point ( 10, 10, 10);
    
    
    cout<<"On va tester l´Obstacle suivant"<< endl;
    cout<<p1<< endl;
    cout<<" Son vecteur qui donne la direction de la largeur est : "<<p1.get_el()<< endl;
    
    cout<<" On va maintenant calculer sa distance au point (10 10 10) qui est : "<<p1.PointPlusProche(point)<< endl;
    
    
    
    
    
    return 0;
}
