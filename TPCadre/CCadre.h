#pragma once

#include <iostream>

using namespace std;

class CCadre
{
private:
	float m_fX;
	float m_fY;
	float m_fLongueur;
	float m_fLargeur;
	char m_cMotif;

public:
	CCadre(const float X = 10, const float Y = 5, const float largeur = 5, const char motif = '*');
	~CCadre();

	float getLongueur() const;
	float getLargeur() const;
	char getMotif() const;

	void setLongueur(const float longueur);
	void setLargeur(const float largeur);
	void setMotif(const char motif);

	bool IsCarre() const;
	void ToString();
	float Perimetre() const;
	float Surface() const;

	void Rotation(const float angle);
	void Afficher();
};

