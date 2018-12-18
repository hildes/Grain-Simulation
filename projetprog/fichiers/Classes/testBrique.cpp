//
//  testBrique.cpp
//  ProjetProg
//
//  Created by alex bonell on 27/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//


#include <iostream>
#include "Brique.hpp"
using namespace std;


int main(){
    
    Brique b(Vecteur3D(0,0,0), Vecteur3D(1,0,0), 3,5,4,Vecteur3D(0,0,1));
    
    cout<<" On a l´obstacle suivant : "<< endl;
    cout<<b<<endl ;
    
    
    Vecteur3D v1(10,10,-10);
    
    cout<<" Le point plus proche de est  (10 10 10) est : "<<endl;
    cout<<b.PointPlusProche(v1)<< endl;
    
    
    
    
    return 0;
}


