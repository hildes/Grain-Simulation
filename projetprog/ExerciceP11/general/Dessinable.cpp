//
//  Dessinable.cpp
//  ProjetProg
//
//  Created by alex bonell on 6/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Dessinable.hpp"


Dessinable::Dessinable(SupportADessin* support_)
:support(support_)
{}

Dessinable::~Dessinable() {}

void Dessinable::setSupport(SupportADessin* vue)
{
    support = vue;
}
