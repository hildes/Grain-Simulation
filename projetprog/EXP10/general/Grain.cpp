#include "Grain.hpp"
#include <math.h>
#include <vector>
#include <string>
#include <iostream>
#include<iomanip>

using namespace std;


//const Vecteur3D e_x(1,0,0), e_y(0,1,0), e_z(0,0,1); x vers nous, y vers la droite, z vers le haut

const Vecteur3D Grain::vect_grav(0,0,-9.81e3);

static double const eta_milieu(1.8e-2); // air
static double const rho_milieu(1.3e-3);  //air


// Constructeurs

Grain::Grain(Vecteur3D p, Vecteur3D v, double m, double r, Vecteur3D f, SupportADessin* support)
: Dessinable(support),position(p), vitesse(v), m_volumique(m), rayon(r),
force(f) {}

Grain::~Grain(){}



double Grain::masse() const {
    return (m_volumique*4.0*M_PI*rayon*rayon*rayon)/3.0;
}


double Grain::lambda() const {
    if ( vitesse.norme() <= 80*eta_milieu/(3*rho_milieu*rayon) ) return 6*M_PI*rayon*eta_milieu;
    else return (M_PI*rayon*rayon*rho_milieu*(vitesse).norme())*9/40;
}



Vecteur3D Grain::calcule_force() const {
    Vecteur3D force_frot = lambda()*vitesse;
    //Vecteur3D archimede = -rho_milieu* (double(4/3)*M_PI*pow(rayon, 3)) *vect_grav; //P=-rho V g, ou V est le volume deplace (ici la sphere est 100% submergee dans le fluide)
    return masse()*vect_grav - force_frot /* +archimede*/;
}


void Grain::ajouteForce(){
    force += calcule_force();
}

void Grain::bouger(double pas){// actualise vitesse et position

    vitesse += (pas/(*this).masse()) * (force);
    position += pas*vitesse;  //ici c'est deja la vitesse actualisee
    force = Vecteur3D(0.0,0.0,0.0);
}

void Grain::affiche(std::ostream& out) const
{
    Vecteur3D f1((*this).masse()*vect_grav);
    Vecteur3D tmp(vitesse);
    Vecteur3D f2(lambda()*(tmp.normalise())); //f1-f2 est la force qui sera exercee sur le grain
    out <<"r: "<< rayon<<setw(8)<<",m_v: "<<setfill(' ')<<m_volumique<<setw(7)<<" ,p: "<<setfill(' ')<<position <<setw(8)<<"  ,v: "<<vitesse<<"  ,f: "<<f1-f2;
}

void Grain::setVitesse(Vecteur3D const& v){
    (*this).vitesse = v;
}

void Grain::setPosition(Vecteur3D const& p){
    (*this).position = p;
}

void Grain::setRayon(double const& r){
    rayon = r;
}

double Grain::getRayon() const{
    return rayon;
}


Vecteur3D Grain::getPosition() const
{
    return position;
}




std::ostream& operator<<(std::ostream& sortie, Grain const& g)  //surcharge operateur <<
{
    g.affiche(sortie);
    return sortie;
}

void Grain::dessine() const {support->dessine(*this);}



void Grain::masseVolumique(double masse)
{
    m_volumique = masse/volume();
}

double Grain::volume() const
{
    return 4*M_PI*pow(rayon, 3)/3;
}



//void Grain::dessine() {support -> dessine();}






