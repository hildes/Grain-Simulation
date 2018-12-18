//
//  GrainLJTDeux.cpp
//  ProjetProg
//
//  Created by alex bonell on 5/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "GrainLJTDeux.hpp"
using namespace std;


void GrainLJTDeux::affiche(ostream& sortie) const
{
    sortie<<" Grain de type 2 : ";
    GrainLJ::affiche(sortie);
    
}
