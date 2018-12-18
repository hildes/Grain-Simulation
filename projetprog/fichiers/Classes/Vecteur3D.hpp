#ifndef Vecteur3D_hpp
#define Vecteur3D_hpp

#include<array>

class Vecteur3D{
    
public:
    //Constructeurs
    Vecteur3D(double x=0.0, double y=0.0, double z=0.0);
    
   ~Vecteur3D();
    
    //Methodes
    //Getters
    double getCoord_x() const;
    double getCoord_y() const;
    double getCoord_z() const;
    Vecteur3D get_normale() const;

    void set_coord(size_t position, double coordonnee );
    
    void affiche(std::ostream& out) const;
    
    bool compare(Vecteur3D vecteur) const;
    
    Vecteur3D oppose() const;
    
    Vecteur3D mult(double scalaire) const;
    
    double norme() const;
    
    double norme2() const;
    
    double produitScalaire( Vecteur3D autre) const;
    
    Vecteur3D produitVectoriel(Vecteur3D autre) const;
        
    const Vecteur3D& normalise();

    //Operator interne
    
    Vecteur3D& operator *=(double const & scalar);
    
    bool operator==(Vecteur3D const& autre) const; //utilise compare
    
    bool operator != (Vecteur3D const & autre) const;
    
    Vecteur3D& operator+=(Vecteur3D const& autre);
    
    Vecteur3D& operator-=(Vecteur3D const& autre);
    
    Vecteur3D& operator^=(Vecteur3D const& autre);
    
    Vecteur3D& operator-() ;
    
private:
    
    std::array<double,3> coordonnees;
    
};

//Operateur externe

const Vecteur3D operator*(Vecteur3D const& x, double autre);//Multiplication par une scalaire a droite

const Vecteur3D operator*(double autre, Vecteur3D const& x) ;//Multiplication par une scalaire a gauche

const double operator*(Vecteur3D x, Vecteur3D const& y);//Produit scalaire

std::ostream& operator<<(std::ostream& sortie, Vecteur3D const& v);//Operateur d'affichage

const Vecteur3D operator+(Vecteur3D  x, Vecteur3D const& y); //utilise addition

const Vecteur3D operator-(Vecteur3D x,Vecteur3D const& y); //utilise soustraction

const  Vecteur3D operator^(Vecteur3D x, const Vecteur3D& autre);

#endif /* Vecteur3D_hpp */
