//
//  GrainLJTUn.hpp
//  ProjetProg
//
//  Created by alex bonell on 5/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef GrainLJTUn_hpp
#define GrainLJTUn_hpp
#include "GrainLJ.hpp"
#include <stdio.h>

class GrainLJTUn : public GrainLJ
{
public:
    
    using GrainLJ::GrainLJ;
    
    virtual ~GrainLJTUn() {}
    
    void affiche(std::ostream& sortie) const override;
    
    
};
#endif /* GrainLJTUn_hpp */
