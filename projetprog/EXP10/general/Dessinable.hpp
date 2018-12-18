//
//  Dessinable.hpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Dessinable_hpp
#define Dessinable_hpp

#include <stdio.h>
#include "SupportADessin.hpp"


class SupportADessin;



class Dessinable{
    
public:
    Dessinable(SupportADessin* support_ = nullptr);
    virtual void dessine() const = 0;
    virtual ~Dessinable();


    //Setters

    virtual void setSupport(SupportADessin* vue);

    
    
protected:
    
    SupportADessin* support;
};



#endif /* Dessinable_hpp */
