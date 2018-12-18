//
//  Vecteur3D.cpp
//  Vecteur3D
//
//  Created by alex bonell on 8/3/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Vecteur3D.hpp"
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;


//methodes utiles


double Vecteur3D::getCoord_x() const{
    return coordonnees[0];
}
double Vecteur3D::getCoord_y() const{
        return coordonnees[1];
}
double Vecteur3D::getCoord_z() const{
        return coordonnees[2];
}


double Vecteur3D::norme2() const
{
    double norm2(0);
    for ( auto& coordonnee : coordonnees)
    {
        norm2+= pow(coordonnee, 2);
    }
    return norm2;
}

double Vecteur3D::norme() const
{
    
    return sqrt((*this).norme2());
    
}


void Vecteur3D::set_coord(size_t position, double coordonne)
{
    coordonnees[position]=coordonne;
}

void Vecteur3D::affiche(std::ostream& out) const
{
    out<<setprecision(6)<<coordonnees[0]<<" "<<setprecision(6)<<coordonnees[1]<<" "<<setprecision(6)<<coordonnees[2];
    
}


const Vecteur3D& Vecteur3D::normalise()
{
    double n = (*this).norme();
    for(auto& elem : (*this).coordonnees){
        elem = elem/n;
    }
    return *this;
}






//Definition methodes necessaire pour operateurs surcharge

bool Vecteur3D::compare(Vecteur3D vecteur) const
{
    
    
    for ( size_t i(0); i< 3; i++)
    {
        if( coordonnees[i]!= vecteur.coordonnees[i])
        {
            return false;
        }
        
    }
    
    return true;
}


Vecteur3D Vecteur3D::oppose() const
{
    Vecteur3D vect;
    for ( size_t i(0); i<3; i++)
    {
        vect.set_coord(i, -coordonnees[i]);
    }
    
    return vect;
}

Vecteur3D Vecteur3D::mult(double scalaire) const
{
    
    Vecteur3D vect;
    for (size_t i(0); i<3; i++)
    {
        vect.set_coord(i, scalaire*coordonnees[i]);
    }
    
    return vect;
}

double Vecteur3D::produitScalaire(Vecteur3D autre) const
{
    double produitScalaire(0);
    for ( size_t i(0); i< 3; i++)
    {
        produitScalaire+= coordonnees[i]*autre.coordonnees[i];
    }
    
    return produitScalaire;
}

Vecteur3D Vecteur3D::produitVectoriel(Vecteur3D autre) const
{
    Vecteur3D vect;
    vect.set_coord(0, coordonnees[1]*autre.coordonnees[2]-autre.coordonnees[1]*coordonnees[2]);
    vect.set_coord(1, coordonnees[0]*autre.coordonnees[2]-autre.coordonnees[0]*coordonnees[2]);
    vect.set_coord(2, coordonnees[0]*autre.coordonnees[1]-autre.coordonnees[0]*coordonnees[1]);
    
    return vect;
}

//Constructeurs



Vecteur3D::Vecteur3D(double x, double y, double z)
: coordonnees({x, y, z})
{} // constructeur (par defaut) double


Vecteur3D::~Vecteur3D(){}






//OPERATEURS INTERNES





bool Vecteur3D::operator==(Vecteur3D const& autre) const{
    return((*this).compare(autre));
}

bool Vecteur3D::operator != (Vecteur3D const & autre) const{
    return !((*this).compare(autre));
}

Vecteur3D& Vecteur3D::operator*=(double const & scalar)
{
    for (auto coordonne: coordonnees)
    {
        coordonne*=scalar;
    }
    
    return (*this);
    
}

Vecteur3D& Vecteur3D::operator+=(Vecteur3D const& autre)
{
    for (size_t i(0); i< 3; i++)
    {
        (*this).coordonnees[i]+=autre.coordonnees[i];
    }
    
    return *this;
}

Vecteur3D& Vecteur3D::operator-=(Vecteur3D const& autre)
{
    (*this) += autre.oppose();
    
    return *this;
    
}


Vecteur3D& Vecteur3D::operator^=(Vecteur3D const& autre){
    return (*this) = ((*this)^(autre)); //modifie l'instance courante de Vecteur3D
}

Vecteur3D& Vecteur3D::operator-()
{

    Vecteur3D vectNul;
    
    (*this)= vectNul - (*this);
    
    return (*this);
    
}






//OPERATEURS EXTERNES


const Vecteur3D operator*(double autre, Vecteur3D const& x)
{
    return x.mult(autre);
}

const Vecteur3D operator*(Vecteur3D const& x, double autre)
{
    return x.mult(autre);
}

const double operator*( Vecteur3D x, Vecteur3D const& y)
{
    return x.produitScalaire(y);
}



const Vecteur3D operator+(Vecteur3D  x, Vecteur3D const& y) //utilise addition
{
    return x+=y;
}





const Vecteur3D operator^(Vecteur3D x, Vecteur3D const& autre)
{
    return x.produitVectoriel(autre);
}


const Vecteur3D operator-(Vecteur3D x,Vecteur3D const& y)
{
    return x -=y;
}


std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& v)  //surcharge operateur <<
{
    v.affiche(sortie);
    return sortie;
}




