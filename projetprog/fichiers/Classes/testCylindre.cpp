//
//  testCylindre.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 26.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include <iostream>
#include "Cylindre.hpp"
using namespace std;

int main(){
    Cylindre c(Vecteur3D(-0.3,0,0), Vecteur3D(2.1,0.5,0), 2.0, 1.0);//position vecteur normal hauteur rayon
    Vecteur3D point (2,2,3);
    cout<<c;
    cout<<"Le point plus proche a "<<point<<" est "<<c.PointPlusProche(point)<<endl;
    
    return 0;
}
