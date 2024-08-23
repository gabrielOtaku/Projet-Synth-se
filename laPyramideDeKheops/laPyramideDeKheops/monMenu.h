#include <iomanip>
#include <iostream>
#include <regex>
#include <fstream>
#include <sstream>
#include <string>
#include <Windows.h>
#include"maStructure.h"
#include "MonJeu.h"


using namespace std;
extern void Tapping(const char data[], int speed);

void positionCurseur(int x, int y);
void afficherMsgErreur(string msg);
void afficherMenuPrincipal(bool siAfficherMenu);
bool siChoixMenuValide(int choixMenu, int valeurMax);
void gestionFichiers();
void afficherMenuFichiers();
void actionFichier(string nomFichier);
void afficherSousMenuFichiers();
void afficherContenuFichier(string nomFichier);

//Ajout 
void AjoutPerso(string nomFichier);
void ajouterObjet(string objetFichier);
void ajouterLieu(string nomFichier);

//Modification
void modifierNom(string nomFichier);

//Supprimer
void supprimerNom(string nomFichier);

//Relire l'histiore
void relireUneHistoire(string nomFichier);
