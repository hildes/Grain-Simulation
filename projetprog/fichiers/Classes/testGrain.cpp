#include <iostream>
#include "GrainLJ.hpp"
#include "Grain.hpp"
using namespace std;

int main(){
    cout<<"testGrain.cpp"<<endl<<endl;
    
    
    
    //On teste avec grain LJ car Grain est une classe abstraite
    
    GrainLJ g (Vecteur3D(0.0,0.0,0.0), Vecteur3D(-0.5,-2.1,-1.0), 0.2 ,  0.4,  Vecteur3D(0.0,0.0,0.0));

    cout<<endl;
    
    cout<<g<<endl;
    
    //On teste la masse
    
    cout<<" La masse du grain est : "<<g.masse()<< endl;
    cout<<" Les frottements a la vitesse initiale sont : "<<g.lambda()<< endl;
    cout<<" La force à la vitesse initiale est : "<<g.calcule_force()<< endl;
    
    
    
    cout<<"---------BOUGER--------"<<endl;
    for(size_t t(1); t<=10; ++t){
        g.ajouteForce(g.calcule_force());
        g.bouger(0.01);
        cout<<g<<endl;
    }
    
    cout<<g<<endl;
    
    
    return 0;
    
}
