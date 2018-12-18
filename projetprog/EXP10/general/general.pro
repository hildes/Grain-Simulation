QMAKE_CXXFLAGS += -std=c++11

TEMPLATE = lib

CONFIG = staticlib

SOURCES = \
    Grain.cpp \
    Obstacle.cpp \
    Plan.cpp \
    Source.cpp \
    SupportADessin.cpp \
    Systeme.cpp \
    Vecteur3D.cpp \
    GrainLJTDeux.cpp \
    GrainLJTUn.cpp \
    Dessinable.cpp \
    GrainLJ.cpp \
    Aleatoire.cpp

HEADERS += \
    GrainLJTDeux.hpp \
    GrainLJTUn.hpp \
    Plan.hpp \
    Aleatoire.hpp \
    Dessinable.hpp \
    Obstacle.hpp \
    Source.hpp \
    SupportADessin.hpp \
    Systeme.hpp \
    Vecteur3D.hpp \
    Grain.hpp \
    GrainLJ.hpp
