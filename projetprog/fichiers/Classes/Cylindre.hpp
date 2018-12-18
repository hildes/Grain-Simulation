//
//  Cylindre.hpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 26.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Cylindre_hpp
#define Cylindre_hpp


#include "Dessinable.hpp"
#include "Obstacle.hpp"


class Cylindre : public Obstacle{
    
public:
    
    Cylindre(Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vecteurNormal = Vecteur3D(1,0,0), double hauteur_ = 5.0, double rayon = 1.0, SupportADessin* support = nullptr);
    
    virtual~Cylindre();
    
    //GETTEURS
    
    
    Vecteur3D get_VecteurNormal() const;
    
    
    
    
    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;
    
    void affiche (std::ostream& sortie) const override;
    
    virtual Obstacle* clone() const override;
    
    
    //Dessinable
    
    virtual void dessine() const override;
    
    
    
    
    
protected:
    //position heritee de Obstacle == centre O
    Vecteur3D vecteurNormal;
    double hauteur;
    double rayon;
};



#endif /* Cylindre_hpp */
