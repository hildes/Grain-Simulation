#include"Source.hpp"
#include"Grain.hpp"
#include"Vecteur3D.hpp"
#include<vector>
#include<iostream>
using namespace std;

int main(){
    
    Grain modele(Vecteur3D (0.0,0.0,0.0), Vecteur3D (0.0,0.0,0.0), 1.0, 1.0, Vecteur3D (0.0,0.0,0.0));
    Grain* m = &modele;
    
    Source s(m, Vecteur3D(0.0, 0.0, 1), Vecteur3D(0.0,0.0,0.0), 5, 3, 6, true);
    vector<Grain*> grain;
    double dt(0.01);
    vector<Grain*> v = s.creation(grain, dt);
    for(auto elem : v){
        cout<<&elem<< endl;
    }
    
    
}
