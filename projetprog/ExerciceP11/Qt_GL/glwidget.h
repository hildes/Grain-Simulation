#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.hpp"
#include <vector>

class GLWidget : public QGLWidget
/* La fenêtre hérite de QGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
    //Grain(Vecteur3D p={0.0,0.0,0.0}, Vecteur3D v={0.0,0.0,0.0}, double m = 2.0, double r = 1.0, Vecteur3D f = {0.0,0.0,0.0},


  GLWidget(QWidget* parent = nullptr)
    : QGLWidget(parent),
      vect({}),
      vp({}),
      vs({}), b(Vecteur3D (0,0, -3), Vecteur3D(1,0,0), 2, 5, 4, Vecteur3D(0,1,0)),
      vsp({Sphere(Vecteur3D(-2, 2, 3), 2)})
{


      double d(15);
      double depth(-0.1);
      double rayon_petit(0.4);
      double rayon_grand(1.0);

      double x(0.0), y(0.0), z(1.0);

      //vect.push_back(GrainLJ( Vecteur3D(0,0,1), Vecteur3D(0.0,0.0,0.5), 1.0, 0.5));
     // vect.push_back(GrainLJ( Vecteur3D(1,0,0), Vecteur3D(0,1,0), 1.0, 0.6));
     // vect.push_back(GrainLJ( Vecteur3D(x,y,rayon_grand - depth+z),Vecteur3D(0,0,0),2.0, rayon_grand));
      vect.push_back(GrainLJ( Vecteur3D(-2.1,2.0,5.5), Vecteur3D(0.01,0.01,0), 1.5, 1.4));

      int nombre(5);

for(int i(-nombre); i<nombre; ++i){
    for(int j(-nombre); j<nombre; ++j){
        for(int k(0); k<j; ++k){
            vect.push_back( GrainLJ(Vecteur3D(2.0*i, 2.0*j, 2.0*k+0.0+4.0), Vecteur3D(20.184*i+1,30.836*k+1,0.6538*j+1), 1.0, 0.4));
            //vect.push_back( GrainLJ(Vecteur3D(2*nombre+2.0*i, 2.0*j, 2*nombre+2.0*k+0.0+3.0), Vecteur3D(2.81384*(i+j+k),3.683*k,1.358*j), 1.0, 0.26));
        }
    }
}

/*
for(int i(-nombre); i<nombre; ++i){
    for(int j(-i); j<i; ++j){
        for(int k(0); k<j; ++k){
            vect.push_back( GrainLJ(Vecteur3D(6.0*i, -6.0*j, 2.0*k+0.0+3.0), Vecteur3D(0.184*i,0.836*k,0.6538*j), 1.0, 0.4));
        }
    }
}
*/

vect.push_back( GrainLJ(Vecteur3D(0,0,2), Vecteur3D(0,30,200), 1.0, 0.4));


for(int i(0); i<1; ++i){//plan horizontal
    vp.push_back( Plan(Vecteur3D(0.0,0.0,depth-0.01*i), Vecteur3D(0,0,2)));
}

for(int i(0); i<1; ++i){//mur 1
    vp.push_back( Plan(Vecteur3D(d,0.0,depth-0.01*i), Vecteur3D(1,0,0)));
}
for(int i(0); i<1; ++i){//mur 2
    vp.push_back( Plan(Vecteur3D(0.0,d,depth-0.01*i), Vecteur3D(0,1,0)));
}
for(int i(0); i<1; ++i){//mur 3
    vp.push_back( Plan(Vecteur3D(-d,0.0,depth-0.01*i), Vecteur3D(1,0,0)));
}
for(int i(0); i<1; ++i){//mur 4
    vp.push_back( Plan(Vecteur3D(0.0,-d,depth-0.01*i), Vecteur3D(0,1,0)));
}



for(size_t j(0); j<vect.size(); ++j){
      //vect[j].masseVolumique(0.468083);
      vect[j].setSupport(&vue);
}
for(int i(-nombre); i<nombre; ++i){
    for(int j(-nombre); j<nombre; ++j){
        vsp.push_back(Sphere(Vecteur3D(2*i,2*j,0), 1.0));
    }
}

for(size_t j(0); j<vsp.size(); ++j){
      vsp[j].setSupport(&vue);
}


// Source ( Grain* modele_, Vecteur3D position_, Vecteur3D vitesse_iMoyenne_, double ecart_typevitesse_,
 //double ecart_typeRayon_, double debit_, bool etat_, SupportADessin* vue= nullptr);
//Grain* m = new GrainLJ(Vecteur3D(0,0,2), Vecteur3D(0,60,200), 1.0, 0.4);
//vs.push_back( Source(m, Vecteur3D(0,0,5), Vecteur3D(30,400,50), 1.0, 0.4, 1000.0, true));



     /*GrainLJTUn* g1 = new GrainLJTUn( Vecteur3D(0,0,0), Vecteur3D(0,0,0), 2.0, 0.4);
         GrainLJTUn* g2 = new GrainLJTUn( Vecteur3D(1,0,0), Vecteur3D(0,0,0), 1.0, 0.4);
         GrainLJTUn* g3 = new GrainLJTUn( Vecteur3D(0.5,0.866025),Vecteur3D(0,0,0),1.0, 0.4);
         GrainLJTDeux* g4 = new GrainLJTDeux( Vecteur3D(0.5,0.288675,0.816497), Vecteur3D(0,0,0), 1.0, 0.4);
         */

for(size_t i(0); i<vs.size(); ++i){//ajouter les sources au systeme
    s.ajouterSource(&vs[i]);
}
for(size_t i(0); i<vect.size(); ++i){//ajouter les grains au systeme
    s.ajouterGrain(&vect[i]);
}
for(size_t i(0); i<vp.size(); ++i){//ajouter les obstacles au systeme
    s.ajouterObstacle(&vp[i]);
}

s.ajouterObstacle(&b);

for(size_t i(0); i<vsp.size(); ++i){
    s.ajouterObstacle(&vsp[i]);
}



s.setSupport(&vue);

}//FIN CONSTRUCTEUR



void ajouterGrainLJ(GrainLJ g);


  virtual ~GLWidget() {}

private:
  // Les 3 méthodes clés de la classe QGLWidget à réimplémenter
  virtual void initializeGL()                  override;
  virtual void resizeGL(int width, int height) override;
  virtual void paintGL()                       override;

  // Méthodes de gestion d'évènements
  virtual void keyPressEvent(QKeyEvent* event) override;
  virtual void timerEvent(QTimerEvent* event)  override;

  // Méthodes de gestion interne
  void pause();

  // Vue : ce qu'il faut donner au contenu pour qu'il puisse se dessiner sur la vue
  VueOpenGL vue;

  // Timer
  int timerId;
  // pour faire évoluer les objets avec le bon "dt"
  QTime chronometre;

  // objets à dessiner, faire évoluer
   Systeme s;
   std::vector<GrainLJ> vect; //grains
    std::vector<Plan> vp;//plans
    Brique b;
    std::vector<Source> vs;//sources
    std::vector<Sphere> vsp;

};

#endif // GLWIDGET_H
