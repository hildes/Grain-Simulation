//
//  Sphere.hpp
//  ProjetProg
//
//  Created by alex bonell on 9/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Sphere_hpp
#define Sphere_hpp
#include "Obstacle.hpp"
#include <stdio.h>



class Sphere : public Obstacle{
public:
    
    
    Sphere( Vecteur3D position_ , double rayon_ = 0, SupportADessin* support_ = nullptr);
    
    virtual ~Sphere();
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    
    void affiche(std::ostream& out) const override;

    Obstacle* clone() const override;
    
    virtual void dessine() const override;
    
private:
    
    double rayon;
    
    
    
};







#endif /* Sphere_hpp */
