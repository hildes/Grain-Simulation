//
//  Obstacle.hpp
//  ProjetProg
//
//  Created by alex bonell on 26/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Obstacle_hpp
#define Obstacle_hpp
#include "Dessinable.hpp"
#include "Vecteur3D.hpp"
#include <ostream>

#include <stdio.h>


class Obstacle : public Dessinable{
public:
    
    virtual void affiche(std::ostream& sortie) const = 0;
    
    Obstacle(SupportADessin* vue = nullptr);
  
    
    virtual ~Obstacle();
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;

    virtual Obstacle* clone() const = 0;


    
};


std::ostream& operator<<(std::ostream& sortie,Obstacle const & o);




#endif /* Obstacle_hpp */
