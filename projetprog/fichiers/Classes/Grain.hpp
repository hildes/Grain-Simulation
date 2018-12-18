#ifndef Grain_hpp
#define Grain_hpp
#include "Vecteur3D.hpp"
#include "Dessinable.hpp"

class Grain : public Dessinable {
public:
    
    Grain(Vecteur3D p={0.0,0.0,0.0}, Vecteur3D v={0.0,0.0,0.0}, double m = 2.0, double r = 1.0, Vecteur3D f = {0.0,0.0,0.0}, SupportADessin* support = nullptr );
    
    virtual ~Grain();
    
    double masse() const;
    
    //eta_milieu est la constante de viscosite du milieu
    
    double lambda() const; //coef de frottement fluide
    
    Vecteur3D calcule_force() const;
    
    void ajouteForce();
    
    void bouger(double pas);
    
    //setters
    void setVitesse(Vecteur3D const& v);
    void setPosition(Vecteur3D const& p);
    void setRayon(double const& r);
    
    //getters
    Vecteur3D getVitesse() const;
    Vecteur3D getPosition() const;
    double getRayon() const;
    
    
    void masseVolumique( double masse) ; //Calcule masse volumique a partir masse
    
    double volume() const;
    
    bool chevauchement(Grain* g)const;
    
    bool trop_loin(double frontiere) const;
    
    void bouger_arti(Grain*);//Bouge artificiellement pour empecher le chevauchement de grains
    
    void bouger_arti(Obstacle*);//Bouge artificiellement pour empecher le chevauchement entre grains et obstacles
    
    //Methodes forces virtuelles
    
    virtual void affiche(std::ostream& sortie) const;
    
    //pures
    
    virtual void ajouteForce(Obstacle* obstacle) = 0;
    
    virtual void ajouteForce(Grain* grain) = 0;
    
    virtual void ajouteForce(Vecteur3D) = 0;

    virtual Grain* clone() const = 0;//retourne un pointeur vers l'instance de la copie de l'objet courant

    //Dessinable
    
    Grain(SupportADessin* vue)
    : Dessinable(vue)
    {}
    
    virtual void dessine() const override;

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
