//
//  Portion_Plan.cpp
//  ProjetProg
//
//  Created by alex bonell on 9/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Portion_Plan.hpp"
#include <iostream>

using namespace std;

PortionPlan::PortionPlan( Vecteur3D position_, Vecteur3D vecteurNormale_, double longueur_, double larguer_, Vecteur3D direction_longueur_)
:Plan(position_, vecteurNormale_), longueur(longueur_),largeur(larguer_),direction_longueur(direction_longueur_)
{
    direction_longueur.normalise();

    if(direction_longueur_*vecteurNormale_!=0)
 {
     cerr<<" Erreur: n et eL pas orthogonaux "<< endl;
 }
}


PortionPlan::~PortionPlan() {}

void PortionPlan::affiche(std::ostream& out) const
{
    Plan::affiche(out);
    out<<" longueur : "<<longueur<<"   et eL : "<<direction_longueur<< endl;
    out<<" largeur  : "<<largeur<< endl;
    
    
}



Vecteur3D PortionPlan::get_el() const
{
    
    return( vecteurNormal^direction_longueur).get_normale();
    
}



Vecteur3D PortionPlan::PointPlusProche( Vecteur3D const& x) const
{
    
    Vecteur3D xf = Plan::PointPlusProche(x);
    double l1 = ( xf - position)*direction_longueur;
    double l2 = ( xf - position)*(*this).get_el();
    
    if(l1>longueur) { xf -= (l1-longueur)*direction_longueur;}
    else { xf -= l1*direction_longueur;}
    
    if(l2>largeur) { xf -= (l2 - largeur)*(*this).get_el();}
    else { xf -= l2*(*this).get_el();}

    
    return xf;
}



void PortionPlan::dessine() const
{support->dessine(*this);}
