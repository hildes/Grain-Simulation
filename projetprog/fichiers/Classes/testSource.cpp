#include"Source.hpp"
#include"Grain.hpp"
#include"GrainLJTUn.hpp"
#include"Vecteur3D.hpp"
#include<iostream>
#include<iomanip>
#include "GrainLJ.hpp"
using namespace std;

int main(){
    cout<<"testSource.cpp"<<endl<<endl;
    
    GrainLJ*  m = new GrainLJ(Vecteur3D(2.0,4.0,6.0), Vecteur3D(6.0,4.0,2.0), 4.0, 1.0, Vecteur3D(0.0,0.0,0.0));
    
    Source s(m, Vecteur3D(0.0, 0.0, 1), Vecteur3D(1.0,0.5,0)/*vitesse moyenne*/, 5/*e_t_vitesse*/, 2/*e_t_rayon*/, 500/*debit*/, true);
    //Source (Grain* modele_, Vecteur3D position_, Vecteur3D vitesse_iMoyenne_, double ecart_typevitesse_, double ecart_typeRayon_, double debit_, bool etat_, SupportADessin* vue= nullptr);
    GrainLJ m1(Vecteur3D(0.0,0.0,0.0), Vecteur3D(0.0,0.0,0.0), 1.0, 1.0, Vecteur3D(0.0,0.0,0.0));
    vector<Grain*> grain({new GrainLJ(m1), new GrainLJ(m1), new GrainLJ(m1) }); //il y a, avant la creation, 3 grains independants.
    double dt(0.01);
    //vector<Grain*> v = s.creation(grain, dt);//
    
    
    
    for(int j(0); j<5; ++j){// une source activee pendant 6 pas de temps
    
        for(size_t i(0); i<grain.size(); ++i){
        
            cout<<setw(2)<<i<<" "<<*grain[i]<<endl;
        }
        cout<<endl<<endl;
        s.affiche(cout);
        s.creation(grain, dt);
    }
}

//verifier si les valeurs sont bonnes
