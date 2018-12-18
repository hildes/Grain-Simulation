#ifndef Systeme_hpp
#define Systeme_hpp
#include "Grain.hpp"
#include "Source.hpp"
#include "Obstacle.hpp"
#include <vector>


#include <algorithm>
#include <cstdlib>
#include <iostream>


class Systeme : public Dessinable{

    
public:
    //Constructeurs
    Systeme(SupportADessin* support = nullptr);
    
    Systeme (Systeme const & s);//Constructeur de copie (profonde)
    
    virtual ~Systeme();//Destructeur

    
    
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
    
    
    std::vector<Grain*> grains;
    std::vector<Obstacle*> obstacles;     //Plus tard on doit changer par obstacles
    std::vector<Source*> sources;
    
    
    
};


std::ostream& operator<<(std::ostream& sortie, Systeme const& systeme);


#endif /* Systeme_hpp */
