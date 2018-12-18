//
//  Sphere.cpp
//  ProjetProg
//
//  Created by alex bonell on 9/5/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Sphere.hpp"



Sphere::Sphere(Vecteur3D position_, double rayon_, SupportADessin* support_)
:Obstacle(position_, support_), rayon(rayon_)
{}


Sphere::~Sphere() {}


double Sphere::get_rayon() const{ return rayon;}


Vecteur3D Sphere::PointPlusProche(Vecteur3D const& x) const
{
    
    return ( position + rayon*(x - position).get_normale());
    
}

void Sphere::affiche(std::ostream& out) const{
    out<<"Sphere de centre : "<<position<<" et de rayon : "<<rayon<<std::endl;
}


Obstacle* Sphere::clone() const{return new Sphere(*this);}

void Sphere::dessine() const{support->dessine(*this);}
