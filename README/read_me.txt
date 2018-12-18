
Bienvenue dans notre projet de programmation.

1. 
Nous sommes arrive jusqu’a l’exercice P11 (12?) avec la simulation qui marche en mode texte et graphique. 
Nous avons fait une methode creation qui fonctionne bien en mode texte mais nous n’avons pas reussi a l’integrer dans le graphisme. 
Les forces liees aux grains et aux obstacles s’ajoutent bien et sont bien integrees dans la simulation graphique. Nous avons rednu les grains moins ponctuels en introduisant les methodes bougerArti qui ne permettent pas le chevauchement entre objets. Tous les obstacles du complement mathematique ons ete implementes (Plan (infini), PortionPlan, Sphere, Brique, Cylindre). 
On a fait la readaptation du pas de temps en fonction de la vitesse pour ne pas permettre a un grain de bouger de plus que la moitie de son rayon.


2.
Nous avons une version graphique du projet avec la bibliotheque „Qt Creator 4.2.1 Basé sur Qt 5.8.0 (Clang 7.0 (Apple), 64 bit)”.

3.
Nous avons passe de plus en plus de temps sur le projet de semaine en semaine. En moyenne on a passe environ 4 heures par semaine par personne, mais nous avons aussi travaille pendant les vacances de paques. Cela fait un total d’environ 
72 heures.



Instructions:

Vous trouverez un dossier projetprog a la source, dans lequel il y a un dossier fichiers dans lequel il y a un dossier Classes. Ce dernier contient tous les fichiers .cpp et .hpp ainsi que les tests executables (testVecteur3D, testGrain, testSource, testSphere, testPlan …), sans oublier le Makefile. Les fichiers executables ont un logo noir et s’executent facilement, il suffit de double cliquer dessus. Vous pouvez les recreer grace au Makefile en executant plusieurs commandes dans le Terminal:

cd …/projetprog/fichiers/Classes [enter]

rm *.o [enter] (pour supprimer d’eventuels fichiers .o afin de reellement generer de nouveaux fichiers)

make testVecteur3D [enter] 

ou bien make testBrique [enter]

ou tout simplement make pour executer toutes les commandes du makefile et generer tous les fichiers a la fois.



Pour lancer la simulation graphique:

- Pour exercice P10:
rentrer dans le répertoire EXP10 (dans projetprog)
cd EXP10
tapez make
puis make
puis il y aura un exécutable dans fichier QT_GL appelée ex_05_gl


-Pour exercice P11:
rentrer dans le répertoire ExerciceP11
cd ExerciceP11
qmake
make
puis il y aura un exécutable dans un fichier QT_GL appelée ex_05_gl