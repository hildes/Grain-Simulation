//
//  Systeme.cpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include "Systeme.hpp"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <algorithm>



using namespace std;




template<typename bidiiter> // Pour la methide evolue_MonteCarlo
bidiiter random_unique(bidiiter begin, bidiiter end, size_t num_random) {
    size_t left = std::distance(begin, end);
    while (num_random--) {
        bidiiter r = begin;
        std::advance(r, rand()%left);
        std::swap(*begin, *r);
        ++begin;
        --left;
    }
    return begin;
} // besoin de <algorithm> et <cstdlib>







//Getteurs


std::vector<Grain*> Systeme::get_Grain() const{return grains;}
std::vector<Source*>Systeme:: get_Source() const{return sources;}
std::vector<Obstacle*>Systeme:: get_Obstacle() const {return obstacles;}




Systeme::Systeme( /*vector<Grain*> grains_ , vector<Obstacle*> obstacles_ ,vector<Source*> sources_,*/SupportADessin* support)
:Dessinable(support)/*, grains(grains_), obstacles(obstacles_),sources(sources_)*/
{}

Systeme::Systeme(Systeme const& autre)
{
    for (auto const & grain : autre.grains)
    {
        grains.push_back(grain->clone());
    }


    for (auto const& obstacle : autre.obstacles)
    {
        obstacles.push_back(obstacle->clone());
    }

    for (auto const& source : autre.sources)
    {
        sources.push_back(source->clone());
    }
}



void Systeme::affiche(ostream& sortie) const
{
    //On affiche les grains
    sortie<< " le systeme est constitue des "<<grains.size()<<" grain(s) suivants : "<< endl;
    for ( auto grain : grains)
    {
        grain->affiche(sortie);
        cout<<endl;
    }
    sortie<< endl;

    //On affiche les plans
    sortie<<" le systeme est constitue des "<<obstacles.size()<<" obstacle(s) suivants : "<< endl;
    for ( auto obstacle : obstacles)
    {
        obstacle->affiche(sortie);
        cout<<endl;
    }
    //On affiche les sources

    sortie<<" le systeme est constitue des "<<sources.size()<<" source(s) suivantes : "<< endl;
    for( auto source : sources)
    {
        source->affiche(sortie);
        cout<<endl;
    }
}


void Systeme::ajouterGrain(Grain* g){
    if(g != nullptr)
    {grains.push_back(g);}
}
void Systeme::ajouterObstacle(Obstacle* o){
    if(o != nullptr)
    {obstacles.push_back(o);}
}
void Systeme::ajouterSource(Source* s){
    if(s != nullptr)
    {sources.push_back(s);}
}





void Systeme::evolue(double dt){
    for(size_t i(0); i<grains.size(); ++i){
        grains[i]->ajouteForce();
        for(auto elem : obstacles){
            grains[i]->ajouteForce(elem);
        }

        for(size_t j(0); j<grains.size(); ++j){
            if (i != j)
            {
            grains[i] -> ajouteForce(grains[j]);
            }
        }

        grains[i]->bouger(dt);

        
    }
}






void Systeme::evolue_MonteCarlo(double dt){
    for(size_t i=0; i<grains.size(); ++i)
        random_unique(grains.begin(), grains.end(), grains.size());
    for(size_t i(0); i<grains.size(); ++i){
        grains[i]->ajouteForce();
        for(auto elem : obstacles){
            grains[i]->ajouteForce(elem);
        }

        for(size_t j(0); j<grains.size(); ++j){
            if (i != j)
            {
                grains[i] -> ajouteForce(grains[j]);
            }
        }

        grains[i]->bouger(dt);

    }
  
    
}








ostream& operator<<(ostream& sortie, Systeme const& s)
{
    s.affiche(sortie);
    return sortie;
}




//Dessinable

void Systeme::dessine() const {


   for (auto const & grain : grains)
    {
        if (grain != nullptr)
        {
            grain->affiche(cout);
            cout<< endl;
            grain->dessine();
        }
    }



    for (auto const &  obstacle : obstacles)
    {
        obstacle -> dessine();
    }


    for (auto const & source : sources)
    {
        source-> dessine();
    }


}





void Systeme::setSupport(SupportADessin *vue)
{
    Dessinable::setSupport(vue);
    for (auto const & grain : grains)
    {
        grain->setSupport(vue);
    }

    for(auto const& obstacle : obstacles)
    {
        obstacle->setSupport(vue);
    }

    for(auto const& source : sources)
    {
        source->setSupport(vue);
    }
}





