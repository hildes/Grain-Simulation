//
//  GrainLJTUn.cpp
//  ProjetProg
//
//  Created by alex bonell on 5/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "GrainLJTUn.hpp"
using namespace std;



void GrainLJTUn::affiche(ostream& sortie) const
{
    sortie<<" Grain de type 1 : ";
    GrainLJ::affiche(sortie);
    
}
