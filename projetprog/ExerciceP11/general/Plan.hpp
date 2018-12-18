//
//  Plan.hpp
//  ProjetProg
//
//  Created by alex bonell on 25/3/17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#ifndef Plan_hpp
#define Plan_hpp

#include "Dessinable.hpp"
#include "Obstacle.hpp"


class Plan : public Obstacle{

public:

    Plan(Vecteur3D position = Vecteur3D(0,0,0), Vecteur3D vecteurNormal = Vecteur3D(0,0,0), SupportADessin* support = nullptr);

    virtual~Plan();

    //GETTEURS

    Vecteur3D get_VecteurNormal() const;

    virtual Vecteur3D PointPlusProche(Vecteur3D const& x_i) const override;


    void affiche (std::ostream& sortie) const override;

    virtual Obstacle* clone() const override;


    //Dessinable

    virtual void dessine() const override;





protected:


    Vecteur3D vecteurNormal;
};




#endif /* Plan_hpp */
