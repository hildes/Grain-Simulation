//
//  Obstacle.cpp
//  ProjetProg
//
//  Created by alex bonell on 26/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//
//
//  Obstacle.cpp
//  ProjetProg
//
//  Created by alex bonell on 26/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Obstacle.hpp"

using namespace std;

//Constructeurs Destructeurs

Obstacle::Obstacle (Vecteur3D position_,SupportADessin* vue)
: Dessinable(vue), position(position_)
{}

Obstacle::~Obstacle() {}


bool Obstacle::chevauchement(Grain* g) const{
    double d_min(g->getRayon());
    return ((PointPlusProche(g->getPosition()) - g->getPosition()).norme() < d_min); //ici PointPlusProche specifique a l'obstacle sera appellee
}

ostream& operator<<(ostream& sortie, Obstacle const& o)
{
    o.affiche(sortie);
    return sortie;
}

Vecteur3D Obstacle::get_position() const{return position;}


void Obstacle::affiche(std::ostream &sortie) const
{
    sortie<<" Obstacle avec caracteristiques suivantes : "<< endl;
    sortie<<" Position :"<<position<< endl;

}

