#include"Systeme.hpp"
#include "SupportADessin.hpp"
#include "GrainLJ.hpp"
#include "text_viewer.hpp"
using namespace std;


int main(){
    cout<<"chute_libre.cpp"<<endl<<endl;
    
    TextViewer textviewer(cout);
    Systeme s(&textviewer);

    
    
    GrainLJ* g = new GrainLJ(Vecteur3D(0,0,0), Vecteur3D(5.0,0.0,7.0), 0.0, 0.4, Vecteur3D(0.0,0.0,0.0));
    
    g->masseVolumique(0.268083);
    
    s.ajouterGrain(g);
    
    s.setSupport(&textviewer);
    
    
    
    cout<<" Position initiale : "<< endl;
    s.dessine();
    cout<<g->masse()<<endl;
    
    
    cout<<" Boucle for avec evolue() :  "<<endl;
    for(int i(0); i<100; ++i){
        double k(i);
        cout<<" à temps "<<0.01+(k/100)<< endl;
        s.evolue(0.01);
        s.dessine();
    }
    
}

/*
 Le système est composé des 1 grains suivants :
 Grain L-J de type 1 : [ pos= (0 0 0), v= (5 0 7), m= 0.268083, r= 0.4 ]
 puis l'évolution (détaillée dans ce fichier ci) :
 
 Grain L-J de type 1 : [ pos= (0 0 0), v= (5 0 7), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.0497469 0 -0.911354), v= (4.97469 0 -91.1354), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.0992419 0 -2.7991), v= (4.9495 0 -188.774), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.148486 0 -5.65828), v= (4.92445 0 -285.918), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.197482 0 -9.48399), v= (4.89952 0 -382.571), m= 0.268083, r= 0.4 ]
 Grain L-J de type 1 : [ pos= (0.246229 0 -14.2713), v= (4.87471 0 -478.734), m= 0.268083, r= 0.4 ]
 ...
 Pensez également à tester plusieurs cas : vitesse initiale nulle, uniquement vers le haut, λ non nul...
 */
