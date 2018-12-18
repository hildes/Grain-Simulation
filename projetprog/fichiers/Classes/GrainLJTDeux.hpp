//
//  GrainLJTDeux.hpp
//  ProjetProg
//
//  Created by alex bonell on 5/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef GrainLJTDeux_hpp
#define GrainLJTDeux_hpp
#include "GrainLJ.hpp"
#include <stdio.h>

#endif /* GrainLJTDeux_hpp */

class GrainLJTDeux : public GrainLJ
{
public:
    
    using GrainLJ::GrainLJ;
    
    virtual ~GrainLJTDeux() {}
    
    void affiche(std::ostream& sortie) const override;
};
