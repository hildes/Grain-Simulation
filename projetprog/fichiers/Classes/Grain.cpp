#include "Grain.hpp"
#include <cmath>
#include <vector>
#include <string>
#include <iostream>
#include <iomanip>
#include "Obstacle.hpp"

using namespace std;

// On exprime la masse en mg et la mesure en mm
//const Vecteur3D e_x(1,0,0), e_y(0,1,0), e_z(0,0,1); x vers nous, y vers la droite, z vers le haut
const Vecteur3D Grain::vect_grav(0,0,-9.81e3);

static double const eta_milieu(1.8e-2); // air
static double const rho_milieu(1.3e-3);  //air


// Constructeurs

Grain::Grain(Vecteur3D p, Vecteur3D v, double m, double r, Vecteur3D f, SupportADessin* support)
: Dessinable(support),position(p), vitesse(v), m_volumique(abs(m)), rayon(abs(r)),force(f)
{}

Grain::~Grain(){}

double Grain::masse() const{
    return (m_volumique*4.0*M_PI*rayon*rayon*rayon)/3.0;//calcule la masse du grain a partir de son rayon et de sa masse volumique
}
double Grain::lambda() const{
    if ( vitesse.norme() <= 80*eta_milieu/(3*rho_milieu*rayon) ) return 6*M_PI*rayon*eta_milieu;
    else return (M_PI*rayon*rayon*rho_milieu*(vitesse).norme())*9/40;
}
Vecteur3D Grain::calcule_force() const{
    Vecteur3D force_frot = lambda()*vitesse;
    Vecteur3D archimede = -rho_milieu* (double(4/3)*M_PI*pow(rayon, 3)) *vect_grav;//P=-rho V g, ou V est le volume deplace (ici la sphere est 100% submergee dans le fluide)
    return masse()*vect_grav - force_frot + archimede;
}
void Grain::ajouteForce(){
    force += calcule_force();
}
void Grain::bouger(double pas){// actualise vitesse et position
    vitesse += (pas/masse()) * (force);
    position += pas*vitesse;  //ici c'est deja la vitesse actualisee
    force = Vecteur3D(0.0,0.0,0.0);
}

void Grain::affiche(std::ostream& out) const
{
    out <<"p: "<<position <<setfill(' ')<<setw(15)<<" ,v: "<<vitesse<<" ,m_v: "<<setfill(' ')<<m_volumique<<setw(8)<<", r: "<< rayon<<setw(7)<<endl;
}

void Grain::setVitesse(Vecteur3D const& v){
    vitesse = v;
}
void Grain::setPosition(Vecteur3D const& p){
    position = p;
}
void Grain::setRayon(double const& r){
    rayon = r;
}
double Grain::getRayon() const{
    return rayon;
}
Vecteur3D Grain::getPosition() const{
    return position;
}
Vecteur3D Grain::getVitesse() const{
    return vitesse;
}

double Grain::volume() const
{
    return 4*M_PI*pow(rayon, 3)/3;
}
void Grain::masseVolumique(double masse)
{
    m_volumique = masse/volume();
}


bool Grain::chevauchement(Grain* g)const{
    double d_min(rayon + g->getRayon());
    return( (position - g->getPosition()).norme() < d_min );
}


bool Grain::trop_loin(double frontiere)const{
    return (position.norme()>frontiere);
}
void Grain::bouger_arti(Grain* g){
    double d_min = g->getRayon() + rayon;
    Vecteur3D e_ij = g->getPosition() - position;
    Vecteur3D u = (e_ij);
    u.normalise();
    Vecteur3D p_avant = position;
    setPosition(p_avant - (d_min - e_ij.norme())*u);
    Vecteur3D v_avant = vitesse;
    setVitesse(v_avant - (v_avant*u)*u);
}
void Grain::bouger_arti(Obstacle* o){
    double d_min = rayon;
    Vecteur3D e_ij = o->PointPlusProche(position) - position;
    Vecteur3D u = (e_ij);
    u.normalise();
    Vecteur3D p_avant = position;
    setPosition(p_avant - (d_min - e_ij.norme())*u);
    Vecteur3D v_avant = vitesse;
    setVitesse(v_avant - (v_avant*u)*u);
}
std::ostream& operator<<(std::ostream& sortie, Grain const& g)  //surcharge operateur <<
{
    g.affiche(sortie);
    return sortie;
}

void Grain::dessine() const {support->dessine(*this);}


