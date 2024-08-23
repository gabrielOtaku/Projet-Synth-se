#include "LectureHistoire.h"

LectureHistoire::LectureHistoire()
{
	NoeudListe* TETE = new NoeudListe();
	NoeudListe* Queue = new NoeudListe();

	debutListe = TETE;
	TETE->suivant = nullptr;
	TETE->precedent = Queue;
	Queue->precedent = TETE;

	noeudCourant = nullptr;
	nombreBulles = 0;
}

LectureHistoire::~LectureHistoire()
{
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	

	delete TETE;
	delete QUEUE;
	debutListe = nullptr;
}

bool LectureHistoire::empty()
{
	bool siVide = false;
	NoeudListe* TETE = debutListe;
	if (TETE->suivant == TETE->precedent)
	{
		siVide = true;
	}
	return siVide;
}

void LectureHistoire::push_Back(const string& texte_)
{
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	NoeudListe* dernierNoeud = QUEUE->precedent;
	NoeudListe* nouveauNoeud = new NoeudListe();

	nouveauNoeud->suivant = QUEUE;
	nouveauNoeud->precedent = QUEUE->precedent;
	nouveauNoeud->histoire = texte_;

	QUEUE->precedent->suivant = nouveauNoeud;
	QUEUE->precedent = nouveauNoeud;

	nombreBulles++;
}

string LectureHistoire::pop_back()
{
	string histoire;
	if (!empty())
	{
		NoeudListe* TETE = debutListe;
		NoeudListe* QUEUE = TETE->precedent;
		NoeudListe* dernierNoeud = QUEUE->precedent;
		NoeudListe* avantDernierNoeud = dernierNoeud->precedent;

		histoire = dernierNoeud->histoire;
		nombreBulles--;

		QUEUE->precedent = avantDernierNoeud;
		avantDernierNoeud->suivant = QUEUE;

		delete dernierNoeud;
	}
	return histoire;
}

bool LectureHistoire::debut()
{
	bool isSuccess = false;

	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	if (TETE->suivant != QUEUE)
	{
		noeudCourant = TETE->suivant;
		isSuccess = true;
	}
	return isSuccess;
}

void LectureHistoire::avancer()
{
	if (noeudCourant != nullptr)
	{
		if (!estNoeudDeQueue())
		{
			noeudCourant = noeudCourant->suivant;
		}
	}
	else if (!empty())
	{
		NoeudListe* TETE = debutListe;
		noeudCourant = TETE->suivant;
	}
}

string LectureHistoire::monHistoire()
{
	if (noeudCourant != nullptr)
	{
		return noeudCourant->histoire;
	}
	else
	{
		return "";
	}
}

bool LectureHistoire::estNoeudDeQueue()
{
	bool estQueue = false;
	NoeudListe* TETE = debutListe;
	NoeudListe* QUEUE = TETE->precedent;

	if (noeudCourant == QUEUE)
	{
		estQueue = true;
	}

	return estQueue;
}

string LectureHistoire::pop_front()
{
	string histoire;

	if (!empty())
	{
		NoeudListe* TETE = debutListe;
		NoeudListe* QUEUE = TETE->precedent;
		NoeudListe* premierNoeud = TETE->suivant;
		NoeudListe* deuxiemeNoeud = premierNoeud->suivant;

		histoire = premierNoeud->histoire;
		nombreBulles--;

		TETE->suivant = deuxiemeNoeud;
		deuxiemeNoeud->precedent = TETE;

		delete premierNoeud;
	}
	return histoire;
}

void LectureHistoire::push_front(const string& texte_)
{
	NoeudListe* TETE = debutListe;
	NoeudListe* premierNoeud = TETE->suivant;
	NoeudListe* nouveauNoeud = new NoeudListe();

	nouveauNoeud->precedent = TETE;
	nouveauNoeud->suivant = premierNoeud;
	nouveauNoeud->histoire = texte_;

	TETE->suivant = nouveauNoeud;
	premierNoeud->precedent = nouveauNoeud;

	nombreBulles++;
}
