#pragma once
#include"maStructure.h"
#include<string>
using namespace std;

struct NoeudListe
{
	NoeudListe* suivant;
	NoeudListe* precedent;
	string histoire;

	NoeudListe();		// Constructeur
};

