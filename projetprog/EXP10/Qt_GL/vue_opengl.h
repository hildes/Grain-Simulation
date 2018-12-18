#ifndef VUEOPENGL_H
#define VUEOPENGL_H

#include <QGLShaderProgram> // Classe qui regroupe les fonctions OpenGL liées aux shaders
#include <QMatrix4x4>
#include "SupportADessin.hpp"
#include "Obstacle.hpp"
#include "Grain.hpp"
#include "GrainLJ.hpp"
#include "GrainLJTUn.hpp"
#include "GrainLJTDeux.hpp"
#include "Plan.hpp"
#include "glsphere.h"
#include "Systeme.hpp"


class VueOpenGL : public SupportADessin {
 public:


  // méthode(s) de dessin (héritée(s) de SupportADessin)
  virtual void dessine(Grain  const&) override;
  virtual void dessine(Systeme const &) override;
  virtual void dessine(Plan    const&) override;
  virtual void dessine(Source const &) override;





  // méthodes de (ré-)initialisation
  void init();
  void initializePosition();

  // méthode set
  void setProjection(QMatrix4x4 const& projection)
  { prog.setUniformValue("projection", projection); }

  // Méthodes set
  void translate(double x, double y, double z);
  void rotate(double angle, double dir_x, double dir_y, double dir_z);
  
  // méthode utilitaire offerte pour simplifier
  void dessineCube(QMatrix4x4 const& point_de_vue = QMatrix4x4() );
  void dessineAxes(QMatrix4x4 const& point_de_vue, bool en_couleur = true);
  void dessineSphere(QMatrix4x4 const& point_de_vue, double rouge = 1.0, double vert = 1.0, double bleu = 1.0);
  void dessineTriangle(QMatrix4x4 const& point_de_vue = QMatrix4x4() );

 private:
  // Un shader OpenGL encapsulé dans une classe Qt
  QGLShaderProgram prog;

  // Caméra
  QMatrix4x4 matrice_vue;
  GLSphere sphere;
};

#endif
