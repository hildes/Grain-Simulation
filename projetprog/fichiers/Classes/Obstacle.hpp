//
//  Obstacle.hpp
//  ProjetProg
//
//  Created by alex bonell on 26/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//
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
#include "Grain.hpp"

#include <ostream>

#include <stdio.h>


class Obstacle : public Dessinable{
public:
    
    virtual void affiche(std::ostream& sortie) const;
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const = 0;
    
    Obstacle( Vecteur3D centre_ = Vecteur3D(0,0,0), SupportADessin* vue = nullptr);
    
    virtual ~Obstacle();
    
    Vecteur3D get_position() const;
    
    
    bool chevauchement(Grain* g) const;
    
    virtual Obstacle* clone() const = 0;
    
protected:
    Vecteur3D position;
    
};


std::ostream& operator<<(std::ostream& sortie,Obstacle const & o);




#endif /* Obstacle_hpp */
