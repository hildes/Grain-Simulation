//
//  Cylindre.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 26.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Cylindre.hpp"
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

Cylindre::Cylindre(Vecteur3D position_, Vecteur3D vecteurNormal_, double hauteur_, double rayon_, SupportADessin* support)
: Obstacle(position_, support), vecteurNormal(vecteurNormal_.normalise()), hauteur(hauteur_), rayon(rayon_)
{
    cout<<"Cylindre constructeur"<<endl;
    //cout<<"p =  "<<position<<", n = "<<vecteurNormal<<", h = "<<hauteur<<endl;
}

Cylindre::~Cylindre() {}

Vecteur3D Cylindre::get_VecteurNormal() const{return vecteurNormal;}

Vecteur3D Cylindre::PointPlusProche(Vecteur3D const& x_i) const{
    Vecteur3D x_k;
    Vecteur3D e = x_i - position;
    Vecteur3D e_n = (e*vecteurNormal)*vecteurNormal;
    Vecteur3D n_star = e_n.normalise();
    Vecteur3D e_u = e - e_n;
    Vecteur3D u = e_u.normalise();
    if( !( abs(e*vecteurNormal) >= (hauteur/2.0) || e_u.norme2() == e.norme2()-pow(e*vecteurNormal,2) ) ){
        cerr<<"Erreur : grain a l'interueur du cylindre"<<endl;
    }
    if(abs(e*vecteurNormal)<hauteur/2.0){
        x_k = position + e_n - rayon*u;
    }
    else{
        x_k = position + (hauteur/2.0)*n_star + (rayon<=e_u.norme() ? rayon : e_u.norme()) * u;
    }
    return x_k;
    //(a<=b?a:b)
    //min(rayon, e_u.norme())
}




void Cylindre::affiche (std::ostream& sortie) const{
    sortie<<"Cylindre : "<<"p =  "<<position<<", n = "<<vecteurNormal<<", h = "<<hauteur<<endl;
}

Obstacle* Cylindre::clone() const{
    return new Cylindre(*this);
}

//Dessinable

void Cylindre::dessine() const {support->dessine(*this);}




