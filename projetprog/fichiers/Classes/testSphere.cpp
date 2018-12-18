//
//  testSphere.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 28.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include <iostream>
#include "Sphere.hpp"
using namespace std;


int main(){
    double rayon(1.0);
    Sphere s0(Vecteur3D(0,0,0), rayon);
    
    s0.affiche(cout);
    
    Vecteur3D x(1,2,3);
    
    cout<<"Le point le plus proche de "<<x<<" sur la sphere est "<<s0.PointPlusProche(x)<<endl;
    
    Vecteur3D e(x-s0.get_position());
    Vecteur3D ee(e.normalise()*rayon);
    cout<<ee<<endl;
    
    
    
    return 0;
}
/*

 class Sphere : public Obstacle{
 public:
 
 
 Sphere( Vecteur3D position_ , double rayon_ = 0, SupportADessin* support_ = nullptr);
 
 virtual ~Sphere();
 
 virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
 
 void affiche(std::ostream& out) const override;
 
 
 
 
 private:
 
 double rayon;
 ...

*/
