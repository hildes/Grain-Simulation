#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>        // Classe pour faire une fenêtre OpenGL
#include <QTime>            // Classe pour gérer le temps
#include "vue_opengl.h"
#include "Systeme.hpp"


class GLWidget : public QGLWidget
/* La fenêtre hérite de QGLWidget ;
 * les événements (clavier, souris, temps) sont des méthodes virtuelles à redéfinir.
 */
{
public:
    //Grain(Vecteur3D p={0.0,0.0,0.0}, Vecteur3D v={0.0,0.0,0.0}, double m = 2.0, double r = 1.0, Vecteur3D f = {0.0,0.0,0.0},
  GLWidget( QWidget* parent = nullptr)
    : QGLWidget(parent), g1( Vecteur3D(0,0,0), Vecteur3D(0,0,0), 1.0, 0.4), g2( Vecteur3D(1,0,0), Vecteur3D(0,0,0), 1.0, 0.4)
    , g3( Vecteur3D(0.5,0.866025),Vecteur3D(0,0,0),1.0, 0.4)
  {

      g1.masseVolumique(0.268083);
      g2.masseVolumique(0.268083);
      g3.masseVolumique(0.268083);



     g1.setSupport(&vue);
     g2.setSupport(&vue);
     g3.setSupport(&vue);


     /*GrainLJTUn* g1 = new GrainLJTUn( Vecteur3D(0,0,0), Vecteur3D(0,0,0), 2.0, 0.4);
         GrainLJTUn* g2 = new GrainLJTUn( Vecteur3D(1,0,0), Vecteur3D(0,0,0), 1.0, 0.4);
         GrainLJTUn* g3 = new GrainLJTUn( Vecteur3D(0.5,0.866025),Vecteur3D(0,0,0),1.0, 0.4);
         GrainLJTDeux* g4 = new GrainLJTDeux( Vecteur3D(0.5,0.288675,0.816497), Vecteur3D(0,0,0), 1.0, 0.4);
         */



    s.ajouterGrain(&g1);
    s.ajouterGrain(&g2);
    s.ajouterGrain(&g3);

    s.setSupport(&vue);
  }
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
   GrainLJ g1;
   GrainLJ g2;
   GrainLJ g3;



};

#endif // GLWIDGET_H
