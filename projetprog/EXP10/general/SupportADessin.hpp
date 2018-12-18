//
//  SupportADessin.hpp
//  ProjetProg
//
//  Created by alex bonell on 5/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef SupportADessin_hpp
#define SupportADessin_hpp

#include <stdio.h>

class Grain;
class Plan;
class Obstacle;
class Source;
class Dessinable;
class Systeme;


class SupportADessin
{
public:
    virtual ~SupportADessin();
    
   // virtual void dessine(Dessinable   const&) = 0;
    
    
    virtual void dessine(Grain   const&) = 0;
    virtual void dessine(Systeme const &) = 0;
    virtual void dessine(Plan    const&) = 0;
    
    /* ... etc. pour toutes les autres choses que
     * ... vous voudriez dessiner.
     */
    
    virtual void dessine(Source const&) = 0;
    
    
};

#endif /* SupportADessin_hpp */
