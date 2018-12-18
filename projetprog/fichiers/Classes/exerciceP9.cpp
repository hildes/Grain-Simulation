//
//  exerciceP9.cpp
//  ProjetProg
//
//  Created by Stanislas Hildebrandt on 10.05.17.
//  Copyright © 2017 alex bonell. All rights reserved.
//

#include <stdio.h>
#include"Systeme.hpp"
#include "SupportADessin.hpp"
#include "GrainLJTUn.hpp"
#include "GrainLJTDeux.hpp"
#include "text_viewer.hpp"


using namespace std;






int main(){
    std::cout<<"exerciceP9.cpp"<<std::endl<<std::endl;
    
    
    
    TextViewer textviewer(cout);
    
    Systeme s(&textviewer);
    
    // Grain L-J de type 1 : [ pos= (0 0 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
    //Grain L-J de type 1 : [ pos= (1 0 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
    // Grain L-J de type 1 : [ pos= (0.5 0.866025 0), v= (0 0 0), m= 0.268083, r= 0.4 ]
    // Grain L-J de type 2 : [ pos= (0.5 0.288675 0.816497), v= (0 0 0), m= 0.268083, r= 0.4 ]
    
    
    GrainLJTUn* g1 = new GrainLJTUn( Vecteur3D(0,0,0), Vecteur3D(0,0,0), 2.0, 0.4);
    GrainLJTUn* g2 = new GrainLJTUn( Vecteur3D(1,0,0), Vecteur3D(0,0,0), 1.0, 0.4);
    GrainLJTUn* g3 = new GrainLJTUn( Vecteur3D(0.5,0.866025),Vecteur3D(0,0,0),1.0, 0.4);
    GrainLJTDeux* g4 = new GrainLJTDeux( Vecteur3D(0.5,0.288675,0.816497), Vecteur3D(0,0,0), 1.0, 0.4);
    
    
    array<GrainLJ*, 4> tab( {g1,g2,g3,g4});
    for (auto grainlj : tab)
    {
        grainlj -> masseVolumique(0.268083);
        s.ajouterGrain(grainlj);
    }
    
    Obstacle* p = new Plan(Vecteur3D(0,0,-0.9), Vecteur3D(0,0,2));
    std::cout<<std::endl;
    
    
    
    s.ajouterObstacle(p);
    
    s.setSupport(&textviewer);
    
    
    cout<<"Situation initiale : "<< endl;
    
    s.dessine();
    
    
    std::cout<<"========================================="<<std::endl;
    std::cout<<" Boucle for avec evolue() :  "<<std::endl;
    for(int i(0); i<100; ++i){
        double k(i);
        cout<<" Temps : "<< k/1000<< endl;
        s.evolue(0.001);
        //(s.get_Grain()[0])->affiche(std::cout);
        //std::cout<<i<<" : ";
        s.dessine();
        std::cout<<std::endl;
        std::cout<<std::endl<<std::endl;
    }
    
}
