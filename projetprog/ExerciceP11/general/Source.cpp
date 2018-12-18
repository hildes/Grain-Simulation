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
bool Source::getEtat()const{return etat;}

std::vector<Grain*> Source::creation( std::vector<Grain*> &grains, double dt){
        Aleatoire generateur(1234);//avec graine = 1234

    //determiner nombre de grains a generer: DEBUT ALGO
    double fraction = debit*dt; // fraction = debit "vrai", mais a priori non entier
    int nombre(fraction);      // partie entière
    fraction -= nombre;        // partie fractionnaire
    // on ajoute 1 au hasard, proportionnellement à la partie fractionnaire :
    if ( generateur.uniforme(0.0, 1.0) < fraction ) ++nombre;
    //---FIN ALGO---
    cout<<"Pour un pas de temps "<<dt<<" et un debit de "<<debit<<" on genere "<<nombre<<" grains."<<endl;

    double x, y, z, r;
    size_t taille(grains.size());
    grains.resize(nombre+taille, modele->clone());

    for(size_t a(taille); a<grains.size(); ++a){
        grains[a] = modele->clone();
    }
    cout<< "APRES LA FONCTION RESIZE, la taille du tableau est : "<<grains.size()<<endl;

    for(int i(taille); i<taille+nombre; ++i){
        grains[i]->setPosition(position); //Le grain genere est genere a la position de la source
        x = generateur.gaussienne(vitesse_iMoyenne.getCoord_x(), ecart_typeVitesse);
//        cout<<"x = "<<setw(2)<<x<<" ";
        y = generateur.gaussienne(vitesse_iMoyenne.getCoord_y(), ecart_typeVitesse);
//        cout<<"y = "<<setw(2)<<y<<" ";
        z = generateur.gaussienne(vitesse_iMoyenne.getCoord_z(), ecart_typeVitesse);
//        cout<<"z = "<<setw(2)<<z<<" ";
//        Vecteur3D v(x,y,z);
//        cout<<"Le nouveau vecteur vitesse est : "<<setw(2)<<v<<" "<<endl;
        grains[i]->setVitesse(Vecteur3D(x,y,z));
//        cout<<"Le vecteur vitesse copie est : "<<setw(2)<<vect[i]->getVitesse()<<" "<<endl;

        r = generateur.gaussienne(modele->getRayon(), ecart_typeRayon);
//        cout<<"Le nouveau rayon est : "<<setw(2)<<r<<" "<<endl;
        grains[i]->setRayon(abs(r));
//        cout<<"Le rayon copie est : "<<vect[i]->getRayon()<<" "<<endl;

//        cout<<"Affichage dans la methode, dans la boucle for : "<<endl;
//        cout<<setw(2)<<i<<" "<<*(vect[i])<<endl;
//        cout<<endl;
    }

//    cout<<"Affichage dans la methode du vecteur de grains generes : "<<endl;
//    for(size_t j(0); j<vect.size(); ++j){
//        cout<<setw(2)<<j<<" "<<*(vect[j])<<endl;
//    }
//    cout<<endl;
    return grains;

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






