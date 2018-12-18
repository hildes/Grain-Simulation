//
//  Portion_Plan.hpp
//  ProjetProg
//
//  Created by alex bonell on 9/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Portion_Plan_hpp
#define Portion_Plan_hpp

#include <stdio.h>
#include"Plan.hpp"


//Une portion de plan est un obstacle mais est-ce un plan ??
class PortionPlan : public Plan
{
public:
    
    PortionPlan( Vecteur3D position_, Vecteur3D vectuerNormale_, double longueur_, double larguer_, Vecteur3D direction_longueur_);
   
    
    virtual ~PortionPlan();
    

    virtual void affiche(std::ostream& out) const override;

    
    Vecteur3D get_eL() const;
    Vecteur3D get_el() const;
    double get_largeur() const;
    double get_longueur() const;
    
    
    Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;

    
    
    
    //Dessinable
    
    
    
private:
    
    double longueur;
    double largeur;
    Vecteur3D direction_longueur; 
    
    
};







#endif /* Portion_Plan_hpp */
