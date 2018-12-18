//
//  Grain.hpp
//  Vecteur3D
//
//  Created by Stanislas Hildebrandt on 17.03.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Grain_hpp
#define Grain_hpp
#include "Vecteur3D.hpp"
#include "Dessinable.hpp"



class Grain : public Dessinable {
public:
    Grain(Vecteur3D p={0.0,0.0,0.0}, Vecteur3D v={0.0,0.0,0.0}, double m = 1.0, double r = 1.0, Vecteur3D f = {0.0,0.0,0.0}, SupportADessin* support = nullptr );
    
    virtual ~Grain();
    
    double masse() const;
    
    //eta_milieu est la constante de viscosite du milieu
    
    double lambda() const; //coef de frottement fluide
    
    void ajouteForce();
    
    void bouger(double pas);
    
    virtual void affiche(std::ostream& sortie) const ;
    
    void setVitesse(Vecteur3D const& v);
    
    void setPosition(Vecteur3D const& p);
    
    void setRayon(double const& r);
    
    Vecteur3D getPosition() const;
    
    double getRayon() const;

    Vecteur3D getVitesse() const;
    
    Vecteur3D calcule_force() const;

    virtual Grain* clone() const = 0;

    
    bool chevauchement(Grain* g)const;

    bool trop_loin(double frontiere) const;


       void bouger_arti(Grain*);

       void bouger_arti(Obstacle*);
    

       double distance(Grain const& autre) const;
    
    //Methodes forces virtuelles
    
    virtual void ajouteForce(Obstacle* obstacle) = 0;
    
    virtual void ajouteForce(Grain* grain) = 0;


    

    
    virtual void dessine() const override;

    void masseVolumique(double masse);

    double volume() const;
    
    
    
protected:
    
    Vecteur3D position;
    
    Vecteur3D vitesse;
    
    double m_volumique;
    
    double rayon;
    
    Vecteur3D force;

    static const Vecteur3D vect_grav;


    
    
};

std::ostream& operator<<(std::ostream& sortie, Grain const& g) ;











#endif /* Grain_hpp */
