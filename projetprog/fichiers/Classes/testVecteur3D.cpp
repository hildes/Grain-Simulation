#ifndef PRJ_VECTEUR_H
#define PRJ_VECTEUR_H
#include <iostream>
#include "Vecteur3D.hpp"
using namespace std;



int main() {
    cout<<"testVecteur3D.cpp"<<endl<<endl;
    
    Vecteur3D v1(1.0, 2.0 ,-0.1); //un vecteur
    
    Vecteur3D v2( 2.6, 3.5, 4.1); //un autre
    
    Vecteur3D v3(v1); //Copie de v1
    
    Vecteur3D v4; //Apelle le constructeur par defaut -> vecteur nul!
    
    
    //On teste l´affichage !
    
    cout<<" le vecteur v1 : "<<v1<< endl;
    cout<<" le vecteur v2 : "<<v2<< endl;
    cout<<" le vecteur v3 : "<<v3<< endl;
    cout<<" le vecteur v4 (par defaut) : "<<v4<< endl;
    
    //On teste operateur == et !=
    
    cout<<" Le vecteur v1 est ";
    if ( v1 == v2){ cout<<"egal a v2 "<< endl;}
    else { cout<< "different de v2 "<< endl;}
    
    
    cout<<" Le vecteur v1 est ";
    if(v1!=v3){cout<<"different de v3"<< endl;}
    else{ cout<<"est egal a v3"<< endl;}
    
    //On teste surcharge interne algebrique
    
    cout<<" Apres chaque operation on retourne a v1 ses valeurs initiales "<< endl;
    cout<< " v1 += v2  donne comme resultat v1 = "<<(v1+=v2)<< endl;
    v1=v3;
    cout<<" v1 -= v2 donne comme resultat v1 = "<<(v1-=v2)<< endl;
    v1=v3;
    cout<<v2<< endl;
    cout<<" v1 ^= v2 donne comme resultat v1 = "<<(v1^=v2)<< endl;
    v1=v3;
    cout<<" v1*=3 donne comme resultat v1 = "<<( v1*=3)<< endl;
    v1=v3;
    cout<<" -v1 donne comme resultat v1 = "<<(-v1)<< endl;
    v1=v3;
    
    cout<< endl;
    
    
    //On teste surcharge externe
    
    cout<<" v1 + v2 = "<<(v1 + v2)<< endl;
    cout<<" v1 - v2 = "<<(v1 - v2)<< endl;
    cout<<" v1 ^ v2 = "<<(v1 ^ v2)<< endl;
    cout<<" v1 * v2 = "<<(v1 * v2)<< endl;
    cout<<" v1 * 3  = "<<(v1 * 3)<< endl;
    cout<<" 4  * v1 = "<<(4 * v1)<< endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    return 0;
}


#endif // PRJ_VECTEUR_H
