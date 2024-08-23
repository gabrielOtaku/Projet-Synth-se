#include "mesFonctions.h"
using namespace std;

int DeAleatoire(int max, int min)
{
	return rand() % max + (min);
}

bool verifieFin(vector<vector<int>> choix)
{
	if (choix[0][0] == -1 && choix[0][1] == -1 && choix[0][2] == -1)
	{
		return true;
	}
	return false;
}



