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
:  Obstacle(position_, support), vecteurNormal(vecteurNormal_.normalise())
{}

Plan::~Plan() {}




Vecteur3D Plan::get_VecteurNormal() const{return vecteurNormal;}





Vecteur3D Plan::PointPlusProche(const Vecteur3D &x_i) const
{
    //cout<<"Point plus proche au plan : "<<(x_i + ( ( position - x_i) * vecteurNormal)*vecteurNormal)<<endl;
    return (x_i + ( ( position - x_i) * vecteurNormal)*vecteurNormal);
}




void Plan::affiche(ostream& sortie) const
{
    Obstacle::affiche(sortie);
    sortie<<"normale : "<<vecteurNormal<< endl;
}




void Plan::dessine() const
{support->dessine(*this);}





Obstacle* Plan::clone() const{ return new Plan(*this);}


