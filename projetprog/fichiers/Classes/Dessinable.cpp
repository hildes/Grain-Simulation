#include "Dessinable.hpp"

Dessinable::Dessinable(SupportADessin* support_)
:support(support_)
{}

Dessinable::~Dessinable() {}

void Dessinable::setSupport(SupportADessin* vue){
    support = vue;
}
