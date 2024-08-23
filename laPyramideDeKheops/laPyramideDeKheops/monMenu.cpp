#include "mesFonctions.h"
#include "monMenu.h"
#include "maStructure.h"
using namespace std;

void positionCurseur(int x, int y)
{
	HANDLE manipConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coordonnees{};
	coordonnees.X = x; //Lignes
	coordonnees.Y = y; //Colonnes
	SetConsoleCursorPosition(manipConsole, coordonnees);
}

void afficherMsgErreur(string msg)
{
	system("cls");
	HANDLE manipConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(manipConsole, 12);
	positionCurseur(25, 28);
	cout << msg;
	SetConsoleTextAttribute(manipConsole, 7);
}

void afficherMenuPrincipal(bool siEffacerEcran)
{
	if (siEffacerEcran)
	{
		system("cls");
	}
	positionCurseur(50, 12);
	cout << "1 - Gestion des fichiers";
	positionCurseur(50, 14);
	cout << "2 - Jouer";
	positionCurseur(50, 16);
	cout << "3 - Relire une histoire";
	positionCurseur(50, 18);
	cout << "99 - Exit";
}

bool siChoixMenuValide(int choixMenu, int valeurMax)
{
	bool siValide = false;
	if (choixMenu == 99 || (choixMenu >= 1 && choixMenu <= valeurMax))
	{
		siValide = true;
	}

	return siValide;
}

void gestionFichiers()
{
	int choix = -1;
	int nbEssais = 3;
	int essai = 0;
	bool choixValide = false;
	do
	{
		afficherMenuFichiers();
		positionCurseur(35, 29);
		cout << "Votre choix : \t";

		// Boucle pour la saisie utilisateur
		do {
			cin >> choix;
			essai++;

			if (choix == 1 || choix == 2 || choix == 3 || choix == 99) {
				choixValide = true;
			}
			else {
				positionCurseur(35, 30);
				cout << "Choix invalide. Il vous reste " << nbEssais - essai << " essais.";
				positionCurseur(50, 29);
				cout << "   ";
				positionCurseur(50, 29);
			}

		} while (!choixValide && essai < nbEssais);
		// switch pour action
		switch (choix)
		{
		case 1:
			actionFichier("personnage.dat");
			break;
		case 2:
			actionFichier("lieux.dat");
			break;
		case 3:
			actionFichier("objet.dat");
			break;
		default:
			break;
		}

		choixValide = false;
		essai = 0;

	} while (choix != 99);
}

void afficherMenuFichiers()
{
	system("cls");

	positionCurseur(50, 12);
	cout << "1 - Gérer les fichiers des noms de personnages";
	positionCurseur(50, 14);
	cout << "2 - Gérer les fichiers des noms de lieux";
	positionCurseur(50, 16);
	cout << "3 - Gérer les fichiers des objets";
	positionCurseur(50, 18);
	cout << "99 -Retour";
	positionCurseur(50, 20);
	cout << "Votre choix : \t";
}

void actionFichier(string nomFichier)
{
	int choix = -1;
	int nbEssais = 3;
	int essai = 0;
	bool choixValide = false;
	do
	{
		afficherSousMenuFichiers();
		positionCurseur(35, 29);
		cout << "Votre choix : \t";
		do {
			cin >> choix;
			essai++;

			if (choix == 1 || choix == 2 || choix == 3 || choix == 4 || choix == 99) {
				choixValide = true;
			}
			else {
				positionCurseur(35, 30);
				cout << "Choix invalide. Il vous reste " << nbEssais - essai << " essais.";
				positionCurseur(50, 29);
				cout << "   ";
				positionCurseur(50, 29);
			}

		} while (!choixValide && essai < nbEssais);

		switch (choix)
		{
		case 1:
			afficherContenuFichier(nomFichier);
			break;
		case 2:
			if (nomFichier == "personnage.dat")
			{
				AjoutPerso(nomFichier);
			}
			if (nomFichier == "lieux.dat")
			{
				ajouterLieu(nomFichier);
			}
			if (nomFichier == "objet.dat")
			{
				ajouterObjet(nomFichier);
			}
			break;
		case 3:
			modifierNom(nomFichier);
			break;
		case 4:
			supprimerNom(nomFichier);
			break;
		default:
			break;
		}

		choixValide = false;
		essai = 0;

	} while (choix != 99);
}

void afficherSousMenuFichiers()
{
	system("cls");
	positionCurseur(50, 12);
	cout << "1 - Afficher";
	positionCurseur(50, 14);
	cout << "2 - Ajouter";
	positionCurseur(50, 16);
	cout << "3 - Modifier";
	positionCurseur(50, 18);
	cout << "4 - Supprimer ";
	positionCurseur(50, 20);
	cout << "99 - Retour";
}

void afficherContenuFichier(string nomFichier)
{
	system("cls");
	ifstream fichier(nomFichier);
	if (fichier.is_open()) {
		string ligne;
		while (getline(fichier, ligne)) {
			cout << ligne << endl;
		}
		fichier.close();
	}
	else {
		cout << "Erreur : impossible d'ouvrir le fichier " << nomFichier << endl;
	}
	system("pause");
}

void AjoutPerso(string nomFichier)
{
	system("cls");
	int e = 0;
	string prsn;
	ofstream fichierCible;

	cout << "Combien de personnage voulez-vous ajouter ? : ";
	cin >> e;

	fichierCible.open(nomFichier, ios::out | ios::app);

	for (int i = 0; i < e; i++) {
		cin.ignore();
		cout << "Quel personnage d�sirez-vous ajouter ? : ";
		getline(cin, prsn);
		fichierCible << prsn << endl;
	}

	fichierCible.close();
}

void ajouterObjet(string nomFichier)
{
	system("cls");
	int reponse;
	string obj;
	ofstream fichierCible;
	cout << "Combien d'objets voulez-vous ajouter ? : ";
	cin >> reponse;

	fichierCible.open(nomFichier, ios::out | ios::app);

	for (int i = 0; i < reponse; i++) {
		cin.ignore();
		cout << "Quel objet d�sirez-vous ajouter ? : ";
		getline(cin, obj);
		fichierCible << obj << endl;
	}

	fichierCible.close();
}

void ajouterLieu(string nomFichier)
{
	system("cls");
	int reponse;
	string lieu;
	ofstream fichierCible;
	cout << "Combien de lieu voulez-vous ajouter ? : ";
	cin >> reponse;

	fichierCible.open(nomFichier, ios::out | ios::app);

	for (int i = 0; i < reponse; i++) {
		cin.ignore();
		cout << "Quel lieu d�sirez-vous ajouter ? : ";
		getline(cin, lieu);
		fichierCible << lieu << endl;
	}

	fichierCible.close();
}

void modifierNom(string nomFichier)
{
	system("cls");
	ifstream fichierLecture(nomFichier);
	ofstream fichierTemp("temp.txt");

	string ligne;
	string ancienNom;
	string nouveauNom;

	cout << "Quel nom voulez-vous modifier ? : ";
	cin.ignore();
	getline(cin, ancienNom);

	cout << "Quel nouveau nom voulez-vous lui donner ? : ";
	getline(cin, nouveauNom);

	if (fichierLecture.is_open() && fichierTemp.is_open()) {
		while (getline(fichierLecture, ligne)) {
			if (ligne == ancienNom) {
				fichierTemp << nouveauNom << endl;
			}
			else {
				fichierTemp << ligne << endl;
			}
		}
		fichierLecture.close();
		fichierTemp.close();

		if (remove(nomFichier.c_str()) == 0 && rename("temp.txt", nomFichier.c_str()) == 0) {
			cout << "\nLe nom a �t� modifi� avec succ�s." << endl;
		}
		else {
			cout << "\nErreur : impossible de renommer le fichier." << endl;
		}
	}
	else {
		cout << "\nErreur : impossible d'ouvrir les fichiers." << endl;
	}

	system("pause");
}


void supprimerNom(string nomFichier)
{
	system("cls");
	ifstream fichierLecture(nomFichier);
	ofstream fichierTemp("temp.txt");

	string ligne;
	string nomASupprimer;

	cout << "Quel nom voulez-vous supprimer ? : ";
	cin.ignore();
	getline(cin, nomASupprimer);

	if (fichierLecture.is_open() && fichierTemp.is_open()) {
		while (getline(fichierLecture, ligne)) {
			if (ligne != nomASupprimer) {
				fichierTemp << ligne << endl;
			}
		}
		fichierLecture.close();
		fichierTemp.close();

		if (remove(nomFichier.c_str()) == 0 && rename("temp.txt", nomFichier.c_str()) == 0) {
			cout << "\nLe nom a �t� supprim� avec succ�s." << endl;
		}
		else {
			cout << "\nErreur : impossible de supprimer le fichier." << endl;
		}
	}
	else {
		cout << "\nErreur : impossible d'ouvrir les fichiers." << endl;
	}

	system("pause");
}

void relireUneHistoire(string nomFichier)
{
	ifstream fichierHistoires("histoires.dat");
	if (!fichierHistoires.is_open()) {
		cout << "Erreur : Impossible d'ouvrir le fichier des histoires." << endl;
		return;
	}

	vector<string> histoires;
	string ligne;
	while (getline(fichierHistoires, ligne)) {
		histoires.push_back(ligne);
	}

	fichierHistoires.close();

	if (histoires.empty()) {
		cout << "Aucune histoire disponible." << endl;
		return;
	}

	int choix = -1;
	int nbEssais = 3;
	int essai = 0;
	bool choixValide = false;

	do {
		system("cls");
		cout << "Histoires disponibles :" << endl;
		for (int i = 0; i < histoires.size(); i++) {
			cout << i + 1 << " - " << histoires[i] << endl;
		}
		cout << "99 - Retour" << endl;
		cout << "Votre choix : ";

		// Boucle pour la saisie utilisateur
		do {
			cin >> choix;
			essai++;

			if ((choix >= 1 && choix <= histoires.size()) || choix == 99) { 
				choixValide = true;
			}
			else {
				cout << "Choix invalide. Il vous reste " << nbEssais - essai << " essais." << endl;
			}

		} while (!choixValide && essai < nbEssais);

		if (choix != 99) {
			string nomFichierChoisi = histoires[choix - 1] + ".dat"; 
			relireUneHistoire(nomFichierChoisi);
			system("pause");
		}

		choixValide = false;
		essai = 0;

	} while (choix != 99);
}

