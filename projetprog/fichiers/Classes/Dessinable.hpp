#ifndef Dessinable_hpp
#define Dessinable_hpp

#include "SupportADessin.hpp"

class SupportADessin;

class Dessinable{
public:
    
    Dessinable(SupportADessin* support_ = nullptr);
    
    virtual ~Dessinable();
    
    virtual void dessine() const = 0;
    
    virtual void setSupport(SupportADessin* vue);

protected:
    
    SupportADessin* support;
};
#endif /* Dessinable_hpp */
