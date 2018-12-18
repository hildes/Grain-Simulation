//
//  Brique.hpp
//  ProjetProg
//
//  Created by alex bonell on 10/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Brique_hpp
#define Brique_hpp
#include "Portion_Plan.hpp"
#include <stdio.h>
#include <array>


class Brique : public Obstacle
{
    
public:
    
    
    virtual ~Brique();
    
    Brique( Vecteur3D origine, Vecteur3D vect_normal_, double hauteur_, double longueur_, double largeur, Vecteur3D direction_longueur_);
    
    Vecteur3D get_el() const;
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    
    
    void affiche(std::ostream& out) const override;
    
    virtual Obstacle* clone() const override;
    
    

    
    std::array<PortionPlan, 6> get_plans() const;
    
    
    
    void dessine() const override;
    
    
    
    
private:
    
    Vecteur3D vecteurNormal;
    Vecteur3D origine;
    double hauteur;    // en mm
    double longueur;   // en mm
    Vecteur3D direction_longueur;
    double largeur;
    
    
    
    
    
};










#endif /* Brique_hpp */
