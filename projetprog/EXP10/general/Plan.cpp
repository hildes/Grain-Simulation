//
//  Plan.cpp
//  ProjetProg
//
//  Created by alex bonell on 25/3/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Plan.hpp"
#include <iostream>
using namespace std;

Plan::Plan(Vecteur3D position_, Vecteur3D vecteurNormal_,SupportADessin*support)
:  Obstacle(support),position(position_), vecteurNormal(vecteurNormal_.normalise())
{
    cout<<position_<<"  "<<vecteurNormal<<endl;
}




Vecteur3D Plan::get_position() const{return position;}
Vecteur3D Plan::get_VecteurNormal() const{return vecteurNormal;}





Vecteur3D Plan::PointPlusProche(const Vecteur3D &x_i) const
{
    
    return (x_i + ( ( position - x_i) * vecteurNormal)*vecteurNormal);
    
}



void Plan::affiche(ostream& sortie) const
{
    sortie<<" position : "<<position<<"     vecteur Normale : "<<vecteurNormal<< endl;
}


void Plan::dessine() const
{support->dessine(*this);}


ostream& operator<<(ostream& sortie, Plan const& plan)
{
    plan.affiche(sortie);
    return sortie;
}


Obstacle* Plan::clone() const{ return new Plan(*this);}




