#include <QApplication>
#include "glwidget.h"

int main(int argc, char* argv[])
{
  QApplication a(argc, argv);

  //Systeme s;


  //Obstacle* p1 = new Plan((0,0,0), (1,0,0));

  //GrainLJ* g1 = new GrainLJ( Vecteur3D(0,0,0), Vecteur3D(0,0,0), 2.0, 0.4);
  // GrainLJ* g2 = new GrainLJ( Vecteur3D(1,0,0), Vecteur3D(0,0,0), 1.0, 0.4);
   //GrainLJ* g3 = new GrainLJ( Vecteur3D(0.5,0.866025),Vecteur3D(0,0,0),1.0, 0.4);
   //GrainLJ* g4 = new GrainLJ( Vecteur3D(0.5,0.288675,0.816497), Vecteur3D(0,0,0), 1.0, 0.4);


  //s.ajouterSource(so);
  //s.ajouterGrain(g2);
  //s.ajouterGrain(g3);
  //s.ajouterGrain(g4);

   //s.ajouterObstacle(p1);



  //Grain(Vecteur3D p, Vecteur3D v, double m, double r, Vecteur3D f, SupportADessin* support)



  GLWidget w;
  w.show();


  return a.exec();
}
