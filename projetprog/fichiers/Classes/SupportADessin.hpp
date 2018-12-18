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
class Brique;
class Cylindre;
class Sphere;
class PortionPlan;


class SupportADessin
{
public:
    virtual ~SupportADessin();
    
    //virtual void dessine(Dessinable   const&) = 0; -> ??
    
    
    virtual void dessine(Grain   const&)   = 0;
    virtual void dessine(Systeme const&)   = 0;
    virtual void dessine(Plan    const&)   = 0;
    virtual void dessine(Source const&)    = 0;
    virtual void dessine(Brique const&)    =0;
    virtual void dessine(Cylindre const&)  = 0;
     virtual void dessine(Sphere const&)  = 0;
    virtual void dessine(PortionPlan const& a_dessiner) = 0;


    
    
};

#endif /* SupportADessin_hpp */
