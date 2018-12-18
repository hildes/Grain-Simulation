//
//  GrainLJ.hpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef GrainLJ_hpp
#define GrainLJ_hpp

#include <stdio.h>
#include "Grain.hpp"
#include <cmath>
#include"Obstacle.hpp"



class GrainLJ : public Grain{
    
public:
    //Constructeur
    
    using Grain::Grain;
    
    //using Grain::ajouteForce; // pour les forces independantes (gravite et frottement)
    
    
    virtual ~GrainLJ();
    
    double forceLJ(double const& x) const;
    
    
    
    void ajouteForce(Grain* grain) override;

    void ajouteForce(Obstacle* obstacle) override;
    
    void ajouteForce( Vecteur3D vecteur) override;
    
    
    void affiche(std::ostream& sortie) const override;
    
    virtual Grain* clone() const override;
    
    
    
    
    
    
private:
    
    static const double epsilon;
    
    static const double sigma;
    
    
    
    
    
    
};






#endif /* GrainLJ_hpp */
