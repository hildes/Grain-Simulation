#include "Systeme.hpp"
#include <iostream>
#include<cstdlib>
#include<ctime>
#include <algorithm>

using namespace std;

const double Systeme::frontiere(500);


Systeme::Systeme(SupportADessin* support)
:Dessinable(support)
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

Systeme::~Systeme() {
    viderSysteme();
}


template<typename bidiiter> // Pour la methode evolue_MonteCarlo
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
    if(g != nullptr) grains.push_back(g);
}
void Systeme::ajouterObstacle(Obstacle* o){
    if(o != nullptr) obstacles.push_back(o);
}
void Systeme::ajouterSource(Source* s){
    if(s != nullptr) sources.push_back(s);
}





//EVOLUE
void Systeme::evolue(double dt){
    for(size_t i(0); i<grains.size(); ++i){
        if(grains[i]->trop_loin(frontiere)){ //si le grain est trop loin on le supprime
            delete grains[i];
            grains.erase(grains.begin() + i);
        }//fin du if
        grains[i]->ajouteForce();
        for(auto elem : obstacles){
            if(elem->chevauchement(grains[i])){// s'il y a chevauchement, bouger artificiellement le grain et modifier sa vitesse
                grains[i]->bouger_arti(elem);
            }
            grains[i]->ajouteForce(elem);
            
        }
        
        for(size_t j(0); j<grains.size(); ++j){
            if (i != j)
            {
                if(grains[i]->chevauchement(grains[j])){// s'il y a chevauchement, bouger artificiellement le grain et modifier sa vitesse
                    grains[i]->bouger_arti(grains[j]);
                }
                grains[i] -> ajouteForce(grains[j]);
            }
        }
        if(dt<grains[i]->getRayon()/(2.0*grains[i]->getVitesse().norme())){ //reajustement de dt pour ne jamais deplacer le grain de >= 0.5*(son rayon)
            grains[i]->bouger(dt);
        }else{
            dt = grains[i]->getRayon()/(2.0*grains[i]->getVitesse().norme()+1.0);
            grains[i]->bouger(dt);
        }
        
        
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


void Systeme::viderSysteme(){
    for(size_t i(0); i<grains.size(); ++i){
        delete grains[i];
        grains.pop_back();
    }
    for(size_t i(0); i<sources.size(); ++i){
        delete sources[i];
        sources.pop_back();
    }
    for(size_t i(0); i<obstacles.size(); ++i){
        delete obstacles[i];
        obstacles.pop_back();
    }
    grains.clear();
    sources.clear();
    obstacles.clear();
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






