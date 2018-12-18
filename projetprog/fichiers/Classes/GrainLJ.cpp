//
//  GrainLJ.cpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "GrainLJ.hpp"
#include <iostream>
using namespace std;




//Initialisation des static attribut il faudra modifier les valeurs

const double GrainLJ::epsilon(25);
const double GrainLJ::sigma(0.885);





//Methodes


GrainLJ::~GrainLJ(){}

double GrainLJ::forceLJ(double const& x) const
{
    double y(0);
    
    if (x<=1)
    {
        y = -1;
    }
    
    else if ((x>1) and (x<2))
    {
        y =  (pow(x, 6)-2) / pow(x,13);
    }
    
    else{
        
        y = 0;
    }
    return ((24*epsilon * y)/pow(sigma,2)) ;
}


void GrainLJ::ajouteForce(Grain* grain)
{
    Vecteur3D position_ = grain -> getPosition() - position;
    Vecteur3D v = (forceLJ(1.09 + (position_.norme() - rayon - grain->getRayon())/sigma) * position_.get_normale());//Grains moins ponctuels
    force += v;
}

void GrainLJ:: ajouteForce(Obstacle* obstacle)
{
    Vecteur3D direction = obstacle->PointPlusProche(position) - position;
    double distance;
    distance = (direction).norme();
    Vecteur3D v((2*forceLJ(1.09 + (distance - rayon)/sigma)*direction.get_normale()));//Grains moins ponctuels
    force += v;
}


void GrainLJ::ajouteForce(Vecteur3D vecteur)
{
    force += vecteur;
}

Grain* GrainLJ::clone() const{
    return new GrainLJ(*this);
}

void GrainLJ::affiche(ostream& out) const
{
    out<<" Grain LJ : ";
    Grain::affiche(out);

}






