#ifndef AFFICHER_PERSO_HPP
#define AFFICHER_PERSO_HPP
#include <iostream>
#include <SFML/Graphics.hpp>


class afficherPerso	{
	public:
		afficherPerso(); //constructeur
		~afficherPerso(); //destructeur
		float get_posx() const;     //récupère la position Y du personnage
        float get_posy() const;     //récupère la position X du personnage
        sf::Sprite GetSprite() const; //récupère le sprite du personnage
		sf::Texture texture;
		sf::Sprite sprite;
	private:
		sf::Texture Texture_Player; //Texture du perso
        sf::Sprite spritePerso;     //Sprite du perso
        float posx;                   //Position X du perso
        float posy;                   //Position Y du perso


};

#endif