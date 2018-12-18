//
//  Brique.cpp
//  ProjetProg
//
//  Created by alex bonell on 10/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Brique.hpp"
#include <iostream>
using namespace std;


Brique::Brique( Vecteur3D origine, Vecteur3D vect_normal_, double hauteur_, double longueur_, double largeur_, Vecteur3D direction_longueur_)
: Obstacle(origine), vecteurNormal(vect_normal_), hauteur(hauteur_), longueur(longueur_),largeur(largeur_), direction_longueur(direction_longueur_)
{
    direction_longueur.normalise();
    if(direction_longueur*vect_normal_ != 0){ std::cerr<<" Erreur pas orthogonaux "<< std::endl;}
    
}





Brique::~Brique() {}





void Brique::affiche(std::ostream &out) const
{
    out<<" Cette brique est composée des six faces suivantes :"<< endl;
    for (auto const & face : get_plans())
    {
        face.affiche(out);
    }

}



Vecteur3D Brique::get_el() const { return (vecteurNormal^direction_longueur).get_normale();}


std::array<PortionPlan, 6> Brique::get_plans() const
{
    
    PortionPlan p1  (origine, vecteurNormal,  longueur ,largeur, direction_longueur);
    
    PortionPlan p2(origine, -get_el(),hauteur,longueur,-1*vecteurNormal);
    
    PortionPlan p3(origine, -1*direction_longueur,largeur,hauteur,get_el());
    
    PortionPlan p4 (origine + longueur*direction_longueur, direction_longueur ,hauteur,largeur, -1*vecteurNormal);
    
    PortionPlan p5 (origine + largeur*get_el(),get_el(), longueur,hauteur, direction_longueur);
    
    PortionPlan p6(origine -hauteur*vecteurNormal,-1*vecteurNormal, largeur, longueur,get_el());
        
    return std::array<PortionPlan, 6> {p1,p2,p3,p4,p5,p6};
    
}



Vecteur3D Brique::PointPlusProche(Vecteur3D const & point) const
{
    Vecteur3D x(get_plans()[0].PointPlusProche(point));
    for (auto const & plan : get_plans())
    {
        Vecteur3D x1(plan.PointPlusProche(point));
        
        if( (x-point).norme()> (x1-point).norme())
        {
            x = x1;
        }
        
    }
    
    return x;
}



Obstacle* Brique::clone() const { return new Brique(*this);}




void Brique::dessine() const{  support->dessine(*this); }


