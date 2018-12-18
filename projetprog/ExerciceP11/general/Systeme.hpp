//
//  Systeme.hpp
//  ProjetProg
//
//  Created by alex bonell on 20/4/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Systeme_hpp
#define Systeme_hpp
#include "Grain.hpp"
#include "Source.hpp"
#include "Obstacle.hpp" // on devrait pouvoir mettre Obstacle.hpp au lieu de Plan.hpp sans que cela ne cree d'erreur dans chute libre
#include <vector>
#include <stdio.h>

#include <algorithm>
#include <cstdlib>
#include <iostream>


class Systeme : public Dessinable{


public:

    Systeme(/*std::vector<Grain*> grains_ , std::vector<Obstacle*> plans_ ,std::vector<Source*> sources_ ,*/SupportADessin* support = nullptr);


    Systeme (Systeme const & s);

    //Getteurs



    std::vector<Grain*> get_Grain() const;
    std::vector<Source*> get_Source() const;
    std::vector<Obstacle*> get_Obstacle() const;


    void affiche(std::ostream& sortie) const;

    void ajouterGrain(Grain* grain);
    void ajouterObstacle(Obstacle* obstacle);
    void ajouterSource(Source* source);



    void viderSysteme();
    void evolue(double dt);
    void evolue_MonteCarlo(double dt);


    //Dessinable
    void dessine() const override;
    void setSupport(SupportADessin* vue) override;



private:

    static const double frontiere;

    Systeme& operator=(Systeme const& s) = delete;
    //Systeme( Systeme const & s) = delete;


    std::vector<Grain*> grains;
    std::vector<Obstacle*> obstacles;     //Plus tard on doit changer par obstacles
    std::vector<Source*> sources;



};


std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);


#endif /* Systeme_hpp */
