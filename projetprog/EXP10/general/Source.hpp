//
//  Source.hpp
//  ProjetProg
//
//  Created by alex bonell on 31/3/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Source_hpp
#define Source_hpp

#include "Vecteur3D.hpp"
#include "Grain.hpp"
#include "Aleatoire.hpp"
#include <vector>

#include <stdio.h>




class Source : public Dessinable{
    
public:
    
    Source ( Grain* modele_, Vecteur3D position_, Vecteur3D vitesse_iMoyenne_, double ecart_typevitesse_, double ecart_typeRayon_, double debit_, bool etat_, SupportADessin* vue= nullptr);
    
    //~Source();
    
    void on();
    void off();
    
    std::vector<Grain*> creation(std::vector<Grain*> grains, double dt);
    
    
    virtual ~Source();

    Vecteur3D get_Position() const;

    
    void affiche(std::ostream& sortie) const;
    
    virtual void dessine() const override;

    Source* clone() const;

private:
    
    Grain*    modele;
    Vecteur3D position;
    Vecteur3D vitesse_iMoyenne;
    double    ecart_typeVitesse;
    double    ecart_typeRayon;
    double    debit;
    bool      etat;
    
};


std::ostream& operator<<(std::ostream & sortie, Source const& s);










#endif /* Source_hpp */
