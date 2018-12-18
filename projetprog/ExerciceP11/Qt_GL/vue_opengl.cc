#include "vue_opengl.h"
#include "vertex_shader.h" // Identifiants Qt de nos différents attributs
#include "Systeme.hpp"


void VueOpenGL::dessine(Grain const& grain)
{
    QMatrix4x4 matrice;

    Vecteur3D position(grain.getPosition());
    Vecteur3D vitesse(grain.getVitesse());
    matrice.translate(position.getCoord_x(),position.getCoord_y(),position.getCoord_z());
    matrice.scale(grain.getRayon());
    //glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
    //Un grain on le dessine en jaune alors:
    double p(position.getCoord_x()/50 + 0.1);
    int pp(p);
    p -=pp;
    double q(position.getCoord_y()/50+0.2);
    int qq(q);
    q-=qq;
    double r(position.getCoord_z()/20+0.3);
    int rr(r);
    r-=rr;

    dessineSphere(matrice, p*1.0, q*1.0, r*1.0);

}

void VueOpenGL::dessine( Plan const & plan)
{

      QMatrix4x4 matrice;
      Vecteur3D position(plan.get_position());
      matrice.translate(position.getCoord_x(),position.getCoord_y(),position.getCoord_z());
      matrice.scale(10);
      dessinePlan(matrice, plan.get_VecteurNormal());

}




void VueOpenGL::dessine( Source const& source)
{
    QMatrix4x4 matrice;
    Vecteur3D position(source.get_Position());
    matrice.translate(position.getCoord_x(),position.getCoord_y(),position.getCoord_z());
    matrice.scale(5.0);
    dessineSphere(matrice,1.0,0.0,0.0);
}

void VueOpenGL::dessine(PortionPlan const& planp)
{
    QMatrix4x4 matrice;
    Vecteur3D position(planp.get_position());
    matrice.translate(position.getCoord_x(),position.getCoord_y(),position.getCoord_z());

    dessinePlanfini(matrice, planp.get_VecteurNormal(),planp.get_eL(), planp.get_longueur(),planp.get_largeur());


}

void VueOpenGL::dessine(Brique const& brique){

    for ( auto const & plan : brique.get_plans())
    {
        dessine(plan);
    }

}

void VueOpenGL::dessine(Cylindre const&){

}

void VueOpenGL::dessine(Sphere const& s){

    QMatrix4x4 matrice;
    Vecteur3D position(s.get_position());
    matrice.translate(position.getCoord_x(),position.getCoord_y(),position.getCoord_z());
    matrice.scale(s.get_rayon());
    double p(position.getCoord_x()/50 + 0.1);
    int pp(p);
    p -=pp;
    double q(position.getCoord_y()/50+0.2);
    int qq(q);
    q-=qq;
    double r(position.getCoord_z()/20+0.3);
    int rr(r);
    r-=rr;
    dessineSphere(matrice, p*1.0, q*1.0, r*1.0);



    }





void VueOpenGL::dessine( Systeme const& s)
{   s.dessine(); }







// ======================================================================

// ======================================================================
void VueOpenGL::init()
{
  /* Initialise notre vue OpenGL.
   * Dans cet exemple, nous créons et activons notre shader.
   *
   * En raison du contenu des fichiers *.glsl, le shader de cet exemple
   * NE permet QUE de dessiner des primitives colorées 
   * (pas de textures, brouillard, reflets de la lumière ou autres).
   *
   * Il est séparé en deux parties VERTEX et FRAGMENT.
   * Le VERTEX :
   * - récupère pour chaque sommet des primitives de couleur (dans
   *     l'attribut couleur) et de position (dans l'attribut sommet)
   * - multiplie l'attribut sommet par les matrices 'vue_modele' et
   *     'projection' et donne le résultat à OpenGL
   *   - passe la couleur au shader FRAGMENT.
   *
   * Le FRAGMENT :
   *   - applique la couleur qu'on lui donne
   */

  prog.addShaderFromSourceFile(QGLShader::Vertex,   ":/vertex_shader.glsl");
  prog.addShaderFromSourceFile(QGLShader::Fragment, ":/fragment_shader.glsl");

  /* Identifie les deux attributs du shader de cet exemple
   * (voir vertex_shader.glsl).
   *
   * L'attribut identifié par 0 est particulier, il permet d'envoyer un
   * nouveau "point" à OpenGL
   * 
   * C'est pourquoi il devra obligatoirement être spécifié et en dernier 
   * (après la couleur dans cet exemple, voir plus bas).
   */

  prog.bindAttributeLocation("sommet",  SommetId);
  prog.bindAttributeLocation("couleur", CouleurId);
  
  // Compilation du shader OpenGL
  prog.link();

  // Activation du shader
  prog.bind();

  /* Activation du "Test de profondeur" et du "Back-face culling"
   * Le Test de profondeur permet de dessiner un objet à l'arrière-plan
   * partielement caché par d'autres objets.
   * 
   * Le Back-face culling consiste à ne dessiner que les face avec ordre 
   * de déclaration dans le sens trigonométrique.
   */
  glEnable(GL_DEPTH_TEST);
  glEnable(GL_CULL_FACE);

  sphere.initialize();                                      // initialise la sphère
  initializePosition();
}

// ======================================================================
void VueOpenGL::initializePosition()
{
  // position initiale
  matrice_vue.setToIdentity();
  matrice_vue.translate(0.0, 0.0, -20.0);
 // matrice_vue.rotate(60.0, 0.0, 1.0, 0.0);
  matrice_vue.rotate(50.0, 0.0, 0.0, 1.0);
  matrice_vue.rotate(90, 0.0, 1.0, 1.0);
}

// ======================================================================
void VueOpenGL::translate(double x, double y, double z)
{
  /* Multiplie la matrice de vue par LA GAUCHE.
   * Cela fait en sorte que la dernière modification apportée
   * à la matrice soit appliquée en dernier (composition de fonctions).
   */
  QMatrix4x4 translation_supplementaire;
  translation_supplementaire.translate(x, y, z);
  matrice_vue = translation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::rotate(double angle, double dir_x, double dir_y, double dir_z)
{
  // Multiplie la matrice de vue par LA GAUCHE
  QMatrix4x4 rotation_supplementaire;
  rotation_supplementaire.rotate(angle, dir_x, dir_y, dir_z);
  matrice_vue = rotation_supplementaire * matrice_vue;
}

// ======================================================================
void VueOpenGL::dessineCube (QMatrix4x4 const& point_de_vue)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_QUADS);
  // face coté X = +1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);




  // face coté X = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);

  // face coté Y = +1
  prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);

  // face coté Y = -1
  prog.setAttributeValue(CouleurId, 0.0, 1.0, 1.0); // cyan
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);

  // face coté Z = +1
  prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
  prog.setAttributeValue(SommetId, -1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, +1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, +1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, +1.0);

  // face coté Z = -1
  prog.setAttributeValue(CouleurId, 1.0, 0.0, 1.0); // magenta
  prog.setAttributeValue(SommetId, -1.0, -1.0, -1.0);
  prog.setAttributeValue(SommetId, -1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, +1.0, -1.0);
  prog.setAttributeValue(SommetId, +1.0, -1.0, -1.0);


  glEnd();
}



void VueOpenGL::dessinePlan(QMatrix4x4 const& point_de_vue, Vecteur3D const& normale)
{

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);




    double a(normale.getCoord_x());
    double b(normale.getCoord_y());
    double c(normale.getCoord_z());

    Vecteur3D v1(0,0,0);

    //On doit creer un vecteur perp au vect normal et non nul

    if ( (a==0) or (b==0) or (c==0))
    {
        if(a==0)
        {
            v1.set_coord(0, 1);
        }

        else if(b==0)
        {
            v1.set_coord(1,1);
        }

        else{v1.set_coord(2,1);}

    }

    else{

        v1.set_coord(0,-b);
        v1.set_coord(1,a);
    }



    //On a crée un vecteur orthogonal maintenant on cree le troisieme


    Vecteur3D v2;
    v2 = v1^normale;








    glBegin(GL_QUADS);



    std::cout<<v1<< std::endl;
    std::cout<<v2<<std::endl;
    std::cout<<v1+v2<< std::endl;

        prog.setAttributeValue(CouleurId, 1.0, 1.0, 0.0); // jaune
        prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
        prog.setAttributeValue(SommetId, v1.getCoord_x(), v1.getCoord_y(), v1.getCoord_z());
        prog.setAttributeValue(SommetId, v1.getCoord_x()+v2.getCoord_x(),  v1.getCoord_y()+v2.getCoord_y(), v1.getCoord_z()+v2.getCoord_z());
        prog.setAttributeValue(SommetId, v2.getCoord_x(),v2.getCoord_y(), v2.getCoord_z());
        glEnd();



}

void VueOpenGL::dessinePlanfini(const QMatrix4x4 &point_de_vue, const Vecteur3D &normale, Vecteur3D const& eL, double longueur, double largeur)
{


    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    //direction largeur

    Vecteur3D el(normale^eL);

    glBegin(GL_QUADS);
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0);
    prog.setAttributeValue(SommetId, 0.0,0.0,0.0);
    prog.setAttributeValue(SommetId, longueur* eL.getCoord_x(),longueur*eL.getCoord_y(),longueur*eL.getCoord_z() );
    prog.setAttributeValue(SommetId, largeur*el.getCoord_x()+longueur*eL.getCoord_x(),largeur*el.getCoord_y()+longueur*eL.getCoord_y(),largeur*el.getCoord_z()+longueur*eL.getCoord_z());
    prog.setAttributeValue(SommetId, largeur*el.getCoord_x(),largeur*el.getCoord_y(),largeur*el.getCoord_z());

    glEnd();

}



// Dessine triangle

void VueOpenGL::dessineTriangle(QMatrix4x4 const& point_de_vue)
{

    prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

    glBegin(GL_TRIANGLES);
      prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
      prog.setAttributeValue(SommetId,  0.0, 0.0, 0.0);

      prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
      prog.setAttributeValue(SommetId,  500.0, 0.0, 0.0);

      prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
      prog.setAttributeValue(SommetId,  500.0, 500.0, 0.0);
      glEnd();

}




//On dessine des axes
void VueOpenGL::dessineAxes (QMatrix4x4 const& point_de_vue, bool en_couleur)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);

  glBegin(GL_LINES);

  // axe X
  if (en_couleur) {
    prog.setAttributeValue(CouleurId, 1.0, 0.0, 0.0); // rouge
  } else {
    prog.setAttributeValue(CouleurId, 1.0, 1.0, 1.0); // blanc
  }
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 1.0, 0.0, 0.0);

  // axe Y
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 1.0, 0.0); // vert
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 1.0, 0.0);

  // axe Z
  if (en_couleur) prog.setAttributeValue(CouleurId, 0.0, 0.0, 1.0); // bleu
  prog.setAttributeValue(SommetId, 0.0, 0.0, 0.0);
  prog.setAttributeValue(SommetId, 0.0, 0.0, 1.0);
}


//dessine sphere

void VueOpenGL::dessineSphere (QMatrix4x4 const& point_de_vue,
                               double rouge, double vert, double bleu)
{
  prog.setUniformValue("vue_modele", matrice_vue * point_de_vue);
  prog.setAttributeValue(CouleurId, rouge, vert, bleu);  // met la couleur
  sphere.draw(prog, SommetId);                           // dessine la sphère
}



