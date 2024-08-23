#include <iostream>
#include "mesFonctions.h"
#include "MonJeu.h"
#include "monMenu.h"


using namespace std;

int main(string monFichier) {

    srand(time(nullptr));
    SetConsoleCP(1252);
    SetConsoleOutputCP(1252);

    int choixMenu = -1;

    

        // boucle validation
    do
    {

    


        afficherMenuPrincipal(true);
        positionCurseur(35, 29);
        cout << "Votre choix : \t";
        cin >> choixMenu;

       // fin boucle

        switch (choixMenu) {
        case 1:
            gestionFichiers();
            break;
        case 2:
            Jouer();

        case 3: 
            relireUneHistoire(monFichier);
        case 99:
            break;
        default:
            afficherMsgErreur("Choix invalide. Veuillez r�essayer.");
            break;
        }
  
    } while (choixMenu != 99);

    return 0;
}
