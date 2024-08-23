#pragma once
#include "NoeudListe.h"
#include <string>

using namespace std;

struct LectureHistoire
{
private:
	NoeudListe* debutListe;
	NoeudListe* noeudCourant;

public:
	unsigned int nombreBulles;
	LectureHistoire();
	~LectureHistoire();
	bool empty();
	void push_Back(const string& texte_);
	string pop_back();
	bool debut();
	void avancer();
	string monHistoire();
	bool estNoeudDeQueue();
	string pop_front();
	void push_front(const string& texte_);
};