//
//  GrainLJ.cpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "GrainLJ.hpp"
using namespace std;



const double GrainLJ::epsilon(25.0);
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
    return ((24*epsilon)/pow(sigma,2))*y;
}

void GrainLJ::ajouteForce(Grain* grain)
{
    Vecteur3D position_ = position - grain -> getPosition();
    
    force += forceLJ(position_.norme()/sigma) * position_.normalise();

}

 void GrainLJ:: ajouteForce(Obstacle* obstacle)
    {

        //F=2×σ2 f(σ) ei,k 1

        Vecteur3D direction = position - obstacle->PointPlusProche(position);
        double distance;
        distance = (direction).norme();

        force += (2/sigma)*24*epsilon*(*this).forceLJ(distance/sigma)*direction.normalise();

    }







void GrainLJ::ajouteForce(Vecteur3D vecteur)
{
    force += vecteur;
}


void GrainLJ::affiche(ostream& out) const
{
    
    //out<<" Grain LJ : ";
    Grain::affiche(out);

}




Grain* GrainLJ::clone() const
{
    return new GrainLJ(*this);
}

