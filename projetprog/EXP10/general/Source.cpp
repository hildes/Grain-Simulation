//
//  Source.cpp
//  ProjetProg
//
//  Created by alex bonell on 31/3/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Source.hpp"
#include<iostream>
#include<vector>

using namespace std;


//Constructeur

Source::Source ( Grain* modele_, Vecteur3D position_, Vecteur3D vitesse_iMoyenne_, double ecart_typevitesse_, double ecart_typeRayon_, double debit_, bool etat_,SupportADessin* vue)
: Dessinable(vue),modele(modele_), position(position_), vitesse_iMoyenne(vitesse_iMoyenne_), ecart_typeVitesse(ecart_typevitesse_), ecart_typeRayon(ecart_typeRayon_), debit(debit_), etat(etat_)
{}

//Destructeur

Source::~Source() {}


//Methodes

void Source::on() {this->etat = true;}
void Source::off() {this->etat = false;}

std::vector<Grain*> Source::creation( std::vector<Grain*> grains, double dt){
    vector<Grain*> vect; //vide par defaut
    Aleatoire generateur(1);
    generateur.gaussienne(1.5, 0.5);//moyenne, ecart type
    
    //determiner nombre de grains a generer:
    double fraction = debit*dt; // fraction = debit "vrai", mais a priori non entier
    int nombre(fraction);      // partie entière
    fraction -= nombre;        // partie fractionnaire
    // on ajoute 1 au hasard, proportionnellement à la partie fractionnaire :
    if ( generateur.uniforme(0.0, 1.0) < fraction ) ++nombre;
    
    
    double x, y,z;
    
    for(size_t i = 0; i<nombre; ++i){//PROBLEME: pour un pas de temps le tableau de *grains est repli avec tous les memes grains (ils devaient etre tous un peu differents)
        vect.push_back(modele);
        x = generateur.gaussienne(vitesse_iMoyenne.getCoord_x(), ecart_typeVitesse);
        y = generateur.gaussienne(vitesse_iMoyenne.getCoord_y(), ecart_typeVitesse);
        z = generateur.gaussienne(vitesse_iMoyenne.getCoord_z(), ecart_typeVitesse);
        vect[i]->setVitesse(Vecteur3D(x,y,z));
        //vitesse du nouveau grain modifiee
        vect[i]->setRayon(generateur.gaussienne(modele->getRayon(), ecart_typeRayon));
        
    }
    
    

    
 
    //r: -3.382017,m_v: 1 ,p: 0 0 0      ,v: 0.9655899 3.245828 -0.05006769  ,f: -7806.865 -26242.75 1993.847 pour generateur(1)
    //r: 16.56377,m_v: 1 ,p: 0 0 0      ,v: 4.000869 -9.82128 -4.543238  ,f: -775898.8 1904666 694406.5 pour generateur;
    //r: -21.40864,m_v: 1 ,p: 0 0 0      ,v: -2.110129 2.097962 3.911529  ,f: 683627.1 -679685.6 -864168.3 pour generateur
    //r: -3.382017,m_v: 1 ,p: 0 0 0      ,v: 0.9655899 3.245828 -0.05006769  ,f: -7806.865 -26242.75 1993.847 pour generateur
    //A chaque compilation le tableau de *grains contient que les memes grains mais c'est toujours un tableau rempli sur un autre "model" du grain.
    //Ceci est du a la nature reellement aleatoire des nombres generes par le generateur qui ne prend PAS de graine en argument
    
    return vect;
}

//Affichage

Vecteur3D Source::get_Position() const {return position;}


void Source::affiche(ostream& sortie) const
{
    sortie<<" Grain modele : "<<*modele<< endl;
    sortie<<" position source : "<<position<< endl;
    sortie<<" Vitesse moyenne : "<<vitesse_iMoyenne<< endl;
    sortie<<" ecart type vitesse : "<<ecart_typeVitesse<< " ecart type rayon : "<<ecart_typeRayon<< endl;
    sortie<<" debit : "<<debit<< endl;
    sortie<<" etat : ";
    if (etat){ sortie<<"on";}
    else{sortie<<"off";}
    sortie<< endl;
    
    
}


ostream& operator<<(ostream& sortie, Source const& source)
{
    source.affiche(sortie);
    return sortie;
}





void Source::dessine() const { support->dessine(*this); }



Source* Source::clone() const { return new Source(*this);}






