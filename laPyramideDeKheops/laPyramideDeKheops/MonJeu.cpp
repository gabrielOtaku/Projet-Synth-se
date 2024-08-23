#include"monMenu.h"
#include "MonJeu.h"

using namespace std;



void Jouer() {
	int choix = -1;
	int nbEssais = 3; // Nombre d'essais
	int essai = 0; // Compteur d'essais
	bool choixValide = false; // Indique si le choix est valide

	do {
		afficherChoixJeu();
		positionCurseur(35, 29);
		cout << "Votre choix : \t";

		// Boucle pour la saisie utilisateur
		do {
			cin >> choix;
			essai++; // Incr�mente le compteur d'essais

			if (choix == 1 || choix == 2 || choix == 99) {
				choixValide = true;
			}
			else {
				positionCurseur(35, 30);
				cout << "Choix invalide. Il vous reste " << nbEssais - essai << " essais.";
				positionCurseur(50, 29);
				cout << "   "; // Efface la ligne de saisie
				positionCurseur(50, 29);
			}

		} while (!choixValide && essai < nbEssais);

		// switch pour action
		switch (choix) {
		case 1:
			PyramideKheops(true);
			break;
		case 2:
			DoraBaboucheMagique(true);
			break;
		default:
			break;
		}

		choixValide = false; // R�initialise la variable pour la prochaine saisie
		essai = 0; // R�initialise le compteur d'essais

	} while (choix != 99);
}


void afficherChoixJeu() {
	system("cls");

	positionCurseur(50, 12);
	cout << "1 - La Pyramide de Kh�ops";
	positionCurseur(50, 14);
	cout << "2 - Dora et la babouche magique";
	positionCurseur(50, 18);
	cout << "99 - Retour";
}



void PyramideKheops(bool random) {
	system("cls");
	SetConsoleCP(1252);
	SetConsoleOutputCP(1252);

	Tapping("Bonjour jeune aventurier ! Apr�s avoir accompli\n", 5);
	Tapping("de nombreux exploits, vous avez d�cid� de relever le d�fi\n", 5);
	Tapping("de d�couvrir les plus grands secrets de la Pyramide de Kh�ops\n\n", 5);

	system("pause");
	system("cls");

	positionCurseur(1, 1);
	string reponse = "";
	Tapping("�tes-vous pr�t � commencer cette aventure ? : ", 5);
	cin >> reponse;

	regex regexOui("[oO]|Oui|oui|OUI");
	if (regex_match(reponse, regexOui)) {
		// L'utilisateur a r�pondu oui
		system("cls");
		string name;
		Tapping("Veuillez choisir un nom : ", 5);
		positionCurseur(1, 2);
		cout << "Veuillez appuyer sur la touche [D] pour g�n�rer un nom al�atoire : ";

		if (random) {
			char choice;
			cin >> choice;
			if (choice == 'D' || choice == 'd') {
				ifstream file("personnage.dat");
				if (file.is_open()) {
					// Lire les noms du fichier dans un vecteur
					vector<string> names;
					string line;
					while (getline(file, line)) {
						names.push_back(line);
					}
					file.close();

					// G�n�rer un index al�atoire
					int index = rand() % names.size();

					name = names[index];
				}
			}
		}
		if (name.empty()) {
			cin.ignore(10000, '\n');
			getline(cin, name);
		}



		system("cls");

		Tapping("Bienvenue ", 5);
		cout << name << "\n\n";
		system("pause");
	}
}

void DoraBaboucheMagique(bool random)
{
    int var1 = 0;
    int var2 = 0;
    int var3 = 0;
    int var4 = 0;
    int var5 = 0;
    int var6 = 0;
    int var7 = 0;
    int var8 = 0;
    int var9 = 0;
    int var10 = 0;

    string name;
    string nx;
    string ox;
    string px;
    ifstream file("personnage.dat");
    if (file.is_open()) {
        // Lire les noms du fichier dans un vecteur
        vector<string> names;
        string line;
        while (getline(file, line)) {
            names.push_back(line);
        }
        file.close();

        // G�n�rer un index al�atoire
        int index = rand() % names.size();

        nx = names[index];

        ifstream file2("objet.dat");
        if (file2.is_open()) {
            // Lire les noms du fichier dans un vecteur
            vector<string> names2;
            string line2;
            while (getline(file2, line2)) {
                names2.push_back(line2);
            }
            file2.close();

            // G�n�rer un index al�atoire
            int index2 = rand() % names2.size();

            ox = names2[index2];

            ifstream file3("lieux.dat");
            if (file3.is_open()) {
                // Lire les noms du fichier dans un vecteur
                vector<string> names3;
                string line3;
                while (getline(file3, line3)) {
                    names3.push_back(line3);
                }
                file3.close();

                // G�n�rer un index al�atoire
                int index3 = rand() % names3.size();

                px = names3[index3];
                system("cls");

                SetConsoleCP(1252);
                SetConsoleOutputCP(1252);

                Tapping("Attention l'histoire qui va suivre est une parodie du dessin anim�.\n", 5);
                Tapping("Toutes les blagues faites et un peu borderline sont � prendre au second degr�.\n", 5);
                Tapping("Sur ce, profitez bien de l'histoire la miff ! \n\n", 5);

                system("pause");
                system("cls");

                Tapping("Wesh la street c'est Dora, comment �a va ?\n", 5);
                Tapping("Nous devons pr�server un tr�sor que le m�chant Chipeur d'origine Ar***. Hum hum veut voler.\n", 5);
                Tapping("Aidez-nous !\n\n", 5);

                system("pause");
                system("cls");

                positionCurseur(1, 1);
                string reponse = "";
                Tapping("�tes-vous prêt à commencer cette aventure ? : ", 5);
                cin >> reponse;

                regex regexOui("[oO]|Oui|oui|OUI");
                if (regex_match(reponse, regexOui)) {
                    // L'utilisateur a r�pondu oui
                    system("cls");

                    Tapping("Veuillez choisir un nom : ", 5);
                    positionCurseur(1, 2);
                    cout << "Veuillez appuyer sur la touche [D] pour générer un nom aléatoire : ";

                    if (random) {
                        char choice;
                        cin >> choice;
                        if (choice == 'D' || choice == 'd') {
                            ifstream file("personnage.dat");
                            if (file.is_open()) {
                                // Lire les noms du fichier dans un vecteur
                                vector<string> names;
                                string line;
                                while (getline(file, line)) {
                                    names.push_back(line);
                                }
                                file.close();

                                // G�n�rer un index al�atoire
                                int index = rand() % names.size();

                                name = names[index];
                            }
                        }
                    }
                    if (name.empty()) {
                        cin.ignore(); // Ignorer le reste de la ligne pr�c�dente
                        getline(cin, name); // Lire toute la ligne saisie par l'utilisateur
                    }

                    system("cls");
                    Tapping("Bienvenue ", 5);
                    cout << name << "\n\n";
                    system("pause");
                }
                system("cls");
                Tapping("Il y a 666 ans, la jungle de Dora a failli prendre feu à cause d'une nouvelle invention du peuple nommée ""ALKABOUL""... Cette invention dévastatrice est scellée dans un coffre-fort...\n", 5);
                system("pause");
                system("CLS");
                Tapping("Votre meilleur ami Chipper vient dormir à la maison ce soir...\n", 5);
                Tapping("Que d�cidez-vous de faire ? :\n 1 - Je vais pr�parer un bon repas aphrodisiaque pour passer une nuit de folie !\n 2 - Pas de repas ce soir... Je prépare le cannabis pour passer une soirée en folie !\n 3 - J'enfile ma tenue sexy, ça fera plaisir à mon amie !\n", 5);
                cin >> var1;

                switch (var1)
                {
                case 1:
                    system("CLS");
                    Tapping("Vous avez préparé le repas à base de gingembre, d'asperge et d'huître. Chipper arrive. Une fois le repas fini, vous d�cidez d'aller dormir. L'effet aphrodisiaque commence à prendre le dessus... Votre libido est au plus haut point... Chipper commence à se rapprocher..\n Que décidez-vous de faire ?\n 1 - Vous faites l'amour.. One Life\n 2 - Vous le rejetez, votre envie a chuté\n", 50);
                    cin >> var2;

                    switch (var2)
                    {
                    case 1:
                        system("CLS");
                        Tapping("Hop la... 30 secondes ont suffi... Vous avez un gros mal de t�te... Vous vous endormez instantan�ment...", 5);
                        system("pause");
                        system("CLS");
                        Tapping("La nuit vient de passer... Vous venez de vous r�veiller, Chipper a disparu... Vous d�cidez de regarder dans votre cachette secr�te pour v�rifier si votre coffre-fort est toujours � sa place.\n ", 5);
                        system("pause");
                        system("CLS");
                        Tapping("OOHH... le coffre-fort a disparu !!", 5);
                        Tapping("Que d�cidez-vous de faire ?\n", 5);
                        Tapping(" 1 - Vous d�cidez d'aller � sa recherche\n 2 - Vous avez la flemme et vous retournez dormir\n", 5);
                        cin >> var3;
                        system("pause");
                        

                        switch (var3)
                        {
                        case 1:
                            system("CLS");
                            Tapping("Vous partez � pied, sur le chemin vous croisez ", 5);
                            cout << nx << endl;
                            system("CLS");
                            cout << nx;
                            Tapping(" vous donne un objet...", 5);
                            cout << ox << " !!";
                            Tapping("Que voulez-vous faire avec ?\n 1 - Vous le gardez\n 2 - Vous vous suicidez.\n", 5);
                            cin >> var4;

                            switch (var4)
                            {
                            case 1:
                                system("CLS");
                                Tapping("Vous continuez votre marche.. Au loin, vous apercevez Chipper.. Vous d�cidez de courir pour le rattraper. Au bout de 5 minutes, vous arrivez � ", 5);
                                cout << px;
                                system("pause");
                                system("CLS");
                                Tapping("Vous attrapez Chipper, que d�cidez-vous de faire ?\n 1 - Vous le tuez avec l'objet\n 2 - Vous le laissez s'�chapper\n", 5);
                                cin >> var5;
                                switch (var5)
                                {
                                case 1:
                                    system("CLS");
                                    Tapping("Vous venez d'assassiner Chipper... Le monde est sauv�.", 5);
                                    break;

                                case 2:
                                    system("CLS");
                                    Tapping("Chipper vient de faire exploser la bombe... La jungle de Dora est an�antie.", 5);
                                }
                                break;
                            case 2:
                                break;
                            default:
                                break;
                            }
                        case 2:
                            system("CLS");
                            Tapping("Vous avez perdu", 5);
                            break;
                        default:
                            break;
                        }
                        break;
                    case 2:
                        system("CLS");
                        Tapping("Chipper arrive, Vous d�cidez de fumer du cannabis toute la soir�e.", 5);
                        Tapping("Chipper profite du fait que vous soyez compl�tement d�fonc� pour voler le coffre-fort... Il s'est �chapp� avec.\n", 5);
                        Tapping("Que voulez-vous faire ?\n 1 - Je vais redormir\n 2 - Je vais le poursuivre\n", 5);
                        cin >> var6;
                        switch (var6)
                        {
                        case 1:
                            system("CLS");
                            Tapping("Vous avez perdu, Chipper a tout fait exploser.", 5);
                            break;
                        case 2:
                            system("CLS");
                            Tapping("Vous d�cidez de courir pour partir � sa recherche... vous l'apercevez au loin.", 5);
                            Tapping("Que d�cidez-vous de faire ?\n", 5);
                            Tapping("1 - Vous vous battez contre lui\n 2 - Vous essayez de faire peur � Chipper\n", 5);
                            cin >> var7;
                            switch (var7)
                            {
                            case 1:
                                system("CLS");
                                Tapping("En vous battant, la bombe que Chipper a vol�e dans le coffre-fort a explos�...", 5);
                                break;
                            case 2:
                                system("CLS");
                                Tapping("Vous d�cidez de lui crier dessus... Chipper, pris de peur, fait exploser la bombe.", 5);
                                break;
                            default:
                                break;
                            }
                        default:
                            break;
                        }
                        break;
                    case 3:
                        system("CLS");
                        Tapping("Chipper arrive, il tombe directement amoureux de votre lingerie... vous faites l'amour.\n 20 minutes apr�s, Chipper s'endort, vous d�cidez de fouiller ses poches et vous trouvez une feuille de papier, que faites-vous ?\n", 5);
                        Tapping("1 - Vous l'ouvrez\n 2 - Vous la laissez ici\n", 5);
                        cin >> var8;
                        switch (var8)
                        {
                        case 1:
                            system("CLS");
                            Tapping("Sur la feuille est inscrit le code pour d�samorcer la bombe.", 5);
                            Tapping("Que d�cidez-vous de faire ?\n", 5);
                            Tapping("1 - Vous d�samorcez la bombe\n 2 - Vous laissez la bombe exploser\n", 5);
                            cin >> var9;
                            switch (var9)
                            {
                            case 1:
                                system("CLS");
                                Tapping("Vous avez d�samorc� la bombe.", 5);
                                break;
                            case 2:
                                system("CLS");
                                Tapping("Vous avez perdu, la jungle de Dora est an�antie.", 5);
                                break;
                            default:
                                break;
                            }
                        case 2:
                            system("CLS");
                            Tapping("Vous d�cidez de ne pas ouvrir la feuille...", 5);
                            Tapping("La jungle de Dora est an�antie.", 5);
                            break;
                        default:
                            break;
                        }
                        break;
                    default:
                        break;
                    }
                    break;
                case 2:
                    system("CLS");
                    Tapping("Pas de repas ce soir... Vous sortez votre cannabis pour passer une soir�e en folie.", 5);
                    Tapping("Chipper profite du fait que vous soyez compl�tement d�fonc� pour voler le coffre-fort... Il s'est �chapp� avec.\n", 5);
                    Tapping("Que voulez-vous faire ?\n 1 - Je vais redormir\n 2 - Je vais le poursuivre\n", 5);
                    cin >> var6;
                    switch (var6)
                    {
                    case 1:
                        system("CLS");
                        Tapping("Vous avez perdu, Chipper a tout fait exploser.", 5);
                        break;
                    case 2:
                        system("CLS");
                        Tapping("Vous d�cidez de courir pour partir � sa recherche... vous l'apercevez au loin.", 5);
                        Tapping("Que d�cidez-vous de faire ?\n", 5);
                        Tapping("1 - Vous vous battez contre lui\n 2 - Vous essayez de faire peur � Chipper\n", 5);
                        cin >> var7;
                        switch (var7)
                        {
                        case 1:
                            system("CLS");
                            Tapping("En vous battant, la bombe que Chipper a vol�e dans le coffre-fort a explos�...", 5);
                            break;
                        case 2:
                            system("CLS");
                            Tapping("Vous d�cidez de lui crier dessus... Chipper, pris de peur, fait exploser la bombe.", 5);
                            break;
                        default:
                            break;
                        }
                    default:
                        break;
                    }
                    break;
                case 3:
                    system("CLS");
                    Tapping("Vous enfilez votre tenue sexy pour faire plaisir � Chipper...", 5);
                    Tapping("Chipper arrive, il tombe directement amoureux de vous... vous faites l'amour.\n 20 minutes apr�s, Chipper s'endort, vous d�cidez de fouiller ses poches et vous trouvez une feuille de papier, que faites-vous ?\n", 5);
                    Tapping("1 - Vous l'ouvrez\n 2 - Vous la laissez ici\n", 5);
                    cin >> var8;
                    switch (var8)
                    {
                    case 1:
                        system("CLS");
                        Tapping("Sur la feuille est inscrit le code pour d�samorcer la bombe.", 5);
                        Tapping("Que d�cidez-vous de faire ?\n", 5);
                        Tapping("1 - Vous d�samorcez la bombe\n 2 - Vous laissez la bombe exploser\n", 5);
                        cin >> var9;
                        switch (var9)
                        {
                        case 1:
                            system("CLS");
                            Tapping("Vous avez d�samorc� la bombe.", 5);
                            break;
                        case 2:
                            system("CLS");
                            Tapping("Vous avez perdu, la jungle de Dora est an�antie.", 5);
                            break;
                        default:
                            break;
                        }
                    case 2:
                        system("CLS");
                        Tapping("Vous d�cidez de ne pas ouvrir la feuille...", 5);
                        Tapping("La jungle de Dora est an�antie.", 5);
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
            }
            else
            {
                Tapping("Reponse invalide.", 5);
            }
        }
       
    }

    string reponse;
    string filename;

    Tapping("Souhaitez-vous sauvegarder votre histoire dans un fichier ? (Oui/Non) : ", 5);
    cin >> reponse;

    regex regexOui("[oO]|Oui|oui|OUI");
    if (regex_match(reponse, regexOui))
    {
        Tapping("Veuillez entrer le nom du fichier de sauvegarde : ", 5);
        cin >> filename;

        ofstream outputFile(filename);
        outputFile << "Bienvenue " << name << "\n\n";
        outputFile << "Il y a 666 ans, la jungle de Dora a failli prendre feu � cause d'une nouvelle invention du peuple nomm� \"ALKABOUL\"... Cette invention d�vastatrice est scell�e dans un coffre-fort...\n";
        outputFile << "Votre meilleur ami Chipper vient dormir � la maison ce soir...\n";
        outputFile << "Que d�cidez-vous de faire ? :\n 1 - Je vais pr�parer un bon repas aphrodisiaque pour passer une nuit de folie !\n 2 - Pas de repas ce soir... Je pr�pare le cannabis pour passer une soir�e en folie !\n 3 - J'enfile ma tenue sexy �a fera plaisir � mon amie !\n";
        outputFile << var1 << "\n";

        switch (var1)
        {
        case 1:
            outputFile << "Vous avez pr�par� le repas � base de gingembre, d'asperge et d'hu�tre. Chipper arrive. Une fois le repas fini, vous d�cidez d'aller dormir. L'effet aphrodisiaque commence � prendre le dessus... Votre libido est au plus haut point... Chipper commence � se rapprocher..\n Que d�cidez-vous de faire?\n 1 - Vous faites l'amour.. One Life\n 2 - Vous le rejetez, votre envie a chut�\n";
            outputFile << var2 << "\n";

            switch (var2)
            {
            case 1:
                outputFile << "Hop la... 30 secondes ont suffi... Vous avez un gros mal de t�te... Vous vous endormez instantan�ment...\n";
                outputFile << "La nuit vient de passer... Vous venez de vous r�veiller, Chipper a disparu... Vous d�cidez de regarder dans votre cachette secr�te pour v�rifier si votre coffre-fort est toujours � sa place.\n";
                outputFile << "OOHH... le coffre-fort a disparu !!\n";
                outputFile << "Que d�cidez-vous de faire?\n";
                outputFile << " 1 -  Vous d�cidez d'aller � sa recherche\n 2 - Vous avez la flemme, vous retournez dormir\n";
                outputFile << var3 << "\n";

                switch (var3)
                {
                case 1:
                    outputFile << "Vous partez � pied, sur le chemin vous croisez ";
                    outputFile << nx << "\n";
                    outputFile << nx << " vous donne un objet...";
                    outputFile << ox << "!!\n";
                    outputFile << "Que voulez-vous faire avec ?\n";
                    outputFile << " 1 - Vous le gardez\n 2 - Vous vous suicidez.\n";
                    outputFile << var4 << "\n";

                    switch (var4)
                    {
                    case 1:
                        outputFile << "Vous continuez votre marche... Au loin... vous apercevez Chipper... Vous d�cidez de courir pour le rattraper. Au bout de 5 minutes, vous arrivez � ";
                        outputFile << px << "\n";
                        outputFile << "Vous attrapez Chipper, que d�cidez-vous de faire ?\n";
                        outputFile << " 1 - Vous le tuez avec l'objet\n";
                        break;
                    default:
                        break;
                    }
                    break;
                default:
                    break;
                }
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }


}
