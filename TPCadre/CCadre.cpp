#include "CCadre.h"

#define _USE_MATH_DEFINES
#include <math.h>


CCadre::CCadre(float X, float Y, float largeur, char motif)
{
	this->m_fX = X;
	this->m_fY = Y;
	this->m_fLongueur = largeur * 2;
	this->m_fLargeur = largeur;
	this->m_cMotif = motif;
}

CCadre::~CCadre()
{
	cout << "Destruction du cadre" << endl;
}

float CCadre::getLongueur() const
{
	return this->m_fLongueur;
}

float CCadre::getLargeur() const
{
	return this->m_fLargeur;
}

char CCadre::getMotif() const
{
	return this->m_cMotif;
}

void CCadre::setLongueur(float longueur)
{
	this->m_fLongueur = longueur;
}

void CCadre::setLargeur(float largeur)
{
	this->m_fLargeur = largeur;
}

void CCadre::setMotif(char motif)
{
	this->m_cMotif = motif;
}

bool CCadre::IsCarre() const
{
	if (this->m_fLongueur == this->m_fLargeur) {
		return true;
	}
	else {
		return false;
	}
}

void CCadre::ToString()
{
	cout << "Coord X : " << this->m_fX << endl << "Coord Y : " << this->m_fY << endl << "Longueur : " << this->m_fLongueur << endl << "Largeur : " << this->m_fLargeur << endl << "Motif : " << m_cMotif << endl;
}

float CCadre::Perimetre() const
{
	float perimetre = this->m_fLargeur * 2 + this->m_fLongueur * 2;
	return perimetre;
}

float CCadre::Surface() const
{
	float surface = this->m_fLargeur * this->m_fLongueur;
	return surface;
}

void CCadre::Rotation(float angle)
{
	float coords[3][2] = {0};
	coords[0][0] = this->m_fX + this->m_fLongueur;
	coords[0][1] = this->m_fY;
	
	coords[1][0] = this->m_fX;
	coords[1][1] = this->m_fY + this->m_fLargeur;

	coords[2][0] = this->m_fX + this->m_fLongueur;
	coords[2][1] = this->m_fY + this->m_fLargeur;

	angle = angle * M_PI / 180.0;

	for (int i = 0; i < 3; i++) {
		coords[i][0] = cos(angle) * (coords[i][0] - this->m_fX) - sin(angle) * (coords[i][1] - this->m_fY) + this->m_fX;
		coords[i][1] = sin(angle) * (coords[i][0] - this->m_fX) + cos(angle) * (coords[i][1] - this->m_fY) + this->m_fY;
	}
}

void CCadre::Afficher()
{
	for (int i = 0; i < this->m_fLargeur; i++) {
		for (int j = 0; j < this->m_fLongueur; j++) {
			if (i == 0 || i == this->m_fLargeur - 1) {
				cout << this->m_cMotif;
			}
			else if (j == 0 || j == this->m_fLongueur-1) {
				cout << this->m_cMotif;
			}
			else {
				cout << " ";
			}
		}
		cout << endl;
	}
}
