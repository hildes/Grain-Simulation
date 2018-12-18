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

Obstacle::Obstacle(SupportADessin* vue)
: Dessinable(vue)
{}

Obstacle::~Obstacle() {}


ostream& operator<<(ostream& sortie, Obstacle const& o)
{
    o.affiche(sortie);
    return sortie;
}
