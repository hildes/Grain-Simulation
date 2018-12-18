CXX = g++
CC  = $(CXX)

CXXFLAGS = -std=c++11  # C++11

# Partie commentée : choisissez les options que vous voulez avoir
#                    en décommentant la/les lignes correspondantes
#
CXXFLAGS += -pedantic -Wall       # pour les purs et durs
CXXFLAGS += -g                    # pour debugger
 CXXFLAGS += -pg                 # pour profiler
 LDFLAGS  += -pg                 # pour profiler
 CXXFLAGS += -O2                 # pour optimiser la vitesse


all:: testVecteur3D testGrain testSource testPlan testPortionPlan testBrique testCylindre testSphere exerciceP8 exerciceP9 chute_libre


# On écrit toutes les dépendances

Vecteur3D.o: Vecteur3D.cpp Vecteur3D.hpp

Dessinable.o: Dessinable.hpp Dessinable.cpp

SupportADessin.o: SupportADessin.hpp SupportADessin.cpp

Grain.o: Grain.cpp Grain.hpp Dessinable.hpp Vecteur3D.hpp Obstacle.hpp

GrainLJ.o: GrainLJ.cpp GrainLJ.hpp Grain.hpp Dessinable.hpp Vecteur3D.hpp Obstacle.hpp

GrainLJTUn.o: GrainLJTUn.cpp GrainLJTUn.hpp GrainLJ.hpp Grain.hpp Dessinable.hpp Vecteur3D.hpp Obstacle.hpp


GrainLJTDeux.o: GrainLJTDeux.cpp GrainLJTDeux.hpp GrainLJ.hpp Grain.hpp Dessinable.hpp Vecteur3D.hpp Obstacle.hpp

Source.o: Source.cpp Source.hpp Vecteur3D.hpp Grain.hpp GrainLJ.hpp Aleatoire.hpp Dessinable.hpp

Plan.o: Plan.cpp Plan.hpp Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp

Portion_Plan.o: Portion_Plan.cpp Portion_Plan.hpp Plan.hpp Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp

Sphere.o: Sphere.cpp Sphere.hpp Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp

Brique.o: Brique.cpp Brique.hpp Plan.hpp Portion_Plan.hpp Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp


Cylindre.o: Cylindre.hpp Cylindre.cpp  Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp

text_viewer.o: text_viewer.hpp text_viewer.cpp SupportADessin.hpp Grain.hpp Source.hpp Obstacle.hpp Plan.hpp Portion_Plan.hpp Brique.hpp Cylindre.hpp Vecteur3D.hpp Dessinable.hpp


Systeme.o: Systeme.cpp Systeme.hpp Grain.hpp Vecteur3D.hpp Source.hpp Obstacle.hpp Dessinable.hpp 






# Ici on écrit les dépendances des tests


testVecteur3D.o: testVecteur3D.cpp Vecteur3D.hpp

testGrain.o: testGrain.cpp Grain.hpp GrainLJ.hpp Vecteur3D.hpp Dessinable.hpp

testSource.o: testSource.cpp Source.hpp Grain.hpp GrainLJTUn.hpp Vecteur3D.hpp GrainLJ.hpp Dessinable.hpp

testPlan.o: testPlan.cpp Plan.hpp Obstacle.hpp Vecteur3D.hpp Dessinable.hpp Grain.hpp

testPortionPlan.o: testPortionPlan.cpp Portion_Plan.hpp Plan.hpp Obstacle.hpp Vecteur3D.hpp Grain.hpp Dessinable.hpp

testBrique.o: testBrique.cpp Brique.hpp Portion_Plan.hpp Plan.hpp Obstacle.hpp Vecteur3D.hpp Grain.hpp Dessinable.hpp

testCylindre.o: testCylindre.cpp Cylindre.hpp Obstacle.hpp Dessinable.hpp Grain.hpp Vecteur3D.hpp 

testSphere.o: testSphere.cpp Sphere.hpp Obstacle.hpp Dessinable.hpp Grain.hpp Vecteur3D.hpp Aleatoire.hpp


exerciceP8.o: exerciceP8.cpp Systeme.hpp Plan.hpp Obstacle.hpp  Vecteur3D.hpp GrainLJTUn.hpp GrainLJTDeux.hpp  GrainLJ.hpp Grain.hpp Dessinable.hpp Source.hpp Aleatoire.hpp

exerciceP9.o: exerciceP9.cpp Systeme.hpp Plan.hpp Obstacle.hpp  Vecteur3D.hpp GrainLJTUn.hpp GrainLJTDeux.hpp  GrainLJ.hpp Grain.hpp Dessinable.hpp Source.hpp text_viewer.hpp SupportADessin.hpp

chute_libre.o: chute_libre.cpp Systeme.hpp Plan.hpp Obstacle.hpp  Vecteur3D.hpp GrainLJTUn.hpp GrainLJTDeux.hpp  GrainLJ.hpp Grain.hpp Dessinable.hpp Source.hpp text_viewer.hpp SupportADessin.hpp


testVecteur3D: testVecteur3D.o Vecteur3D.o

testGrain : testGrain.o Grain.o GrainLJ.o Obstacle.o Vecteur3D.o Dessinable.o

testSource : testSource.o Source.o Vecteur3D.o Grain.o Dessinable.o GrainLJTUn.o GrainLJ.o Aleatoire.o

testPlan : testPlan.o Plan.o Obstacle.o Vecteur3D.o Grain.o Dessinable.o

testPortionPlan : testPortionPlan.o Portion_Plan.o Plan.o Obstacle.o Vecteur3D.o Grain.o Dessinable.o

testBrique: testBrique.o Brique.o Portion_Plan.o Plan.o Obstacle.o Vecteur3D.o Grain.o Dessinable.o

testCylindre: testCylindre.o Cylindre.o Vecteur3D.o Obstacle.o Grain.o Dessinable.o

exerciceP8: exerciceP8.o Systeme.o Plan.o Obstacle.o Vecteur3D.o GrainLJTUn.o GrainLJTDeux.o GrainLJ.o Grain.o Dessinable.o Source.o Aleatoire.o

exerciceP9: exerciceP9.o Systeme.o Plan.o Obstacle.o Vecteur3D.o GrainLJTUn.o GrainLJTDeux.o GrainLJ.o Grain.o Dessinable.o Source.o Aleatoire.o text_viewer.o SupportADessin.o

chute_libre : chute_libre.o Systeme.o Plan.o Obstacle.o Vecteur3D.o GrainLJTUn.o GrainLJTDeux.o GrainLJ.o Grain.o Dessinable.o Source.o Aleatoire.o text_viewer.o SupportADessin.o




testSphere : testSphere.o Sphere.o Vecteur3D.o Obstacle.o Grain.o Dessinable.o









