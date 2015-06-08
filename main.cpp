#include <fstream>
#include <string>
#include <iostream>
using namespace std;
#include "game.hpp"
#include "TileMap.hpp"

int main()
{
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    ifstream file;

    file.open("Data/Map/Level/level1.txt");


    unsigned count = 0, xmax, ymax;
    string line;
    string later;
    string pathtotiles;
    char nono;

    file >> later;
    file >> later;
    file >> pathtotiles;
    file >> ymax >> xmax >> nono;

    char *level = new char[xmax*ymax]; 

    for (unsigned i = 0 ; i < ymax ; i++)
    {
    	getline(file, line);

    	for (unsigned j = 0 ; j < xmax ; j++)
    	{
   			level[count] = line[j];
    		count++;
    	}

    }

    unsigned nbtiles;
    file >> nbtiles;

    for (unsigned i = 0 ; i < nbtiles ; i++)
    {
    	
    }

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load(pathtotiles, sf::Vector2u(16, 16), level, xmax, ymax))
        return -1;

    cerr << later << endl << endl;

    for (unsigned i = 0 ; i < xmax*ymax ; i++)
    	cerr << level[i] << endl;

    delete[] level;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}

/*
int main()
{
    // on crée la fenêtre
    sf::RenderWindow window(sf::VideoMode(512, 256), "Tilemap");

    // on définit le niveau à l'aide de numéro de tuiles
    const int level[] =
    {
        0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
        0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0,
        1, 1, 0, 0, 0, 0, 0, 0, 3, 3, 3, 3, 3, 3, 3, 3,
        0, 1, 0, 0, 2, 0, 3, 3, 3, 0, 1, 1, 1, 0, 0, 0,
        0, 1, 1, 0, 3, 3, 3, 0, 0, 0, 1, 1, 1, 2, 0, 0,
        0, 0, 1, 0, 3, 0, 2, 2, 0, 0, 1, 1, 1, 1, 2, 0,
        2, 0, 1, 0, 3, 0, 2, 2, 2, 0, 1, 1, 1, 1, 1, 1,
        0, 0, 1, 0, 3, 2, 2, 2, 0, 0, 0, 0, 1, 1, 1, 1,
    };

    // on crée la tilemap avec le niveau précédemment défini
    TileMap map;
    if (!map.load("Data/Textures/tile.png", sf::Vector2u(16, 16), level, 16, 8))
        return -1;

    // on fait tourner la boucle principale
    while (window.isOpen())
    {
        // on gère les évènements
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)
                window.close();
        }

        // on dessine le niveau
        window.clear();
        window.draw(map);
        window.display();
    }

    return 0;
}


int main()
{
    Game game;
    game.run();
}

//Mettre un return 0; enclanche des erreurs : 
//Dans un premier temps, le personnage commence en allant à droite sans déclancher la 
//fonction void Game::handlePlayerInput(sf::Keyboard::Key key,bool isPressed)
//(test faits pour afficher une lettre et jamais déclanché).
//Deuxièmement, la fermeture de la fenêtre manuellement s'accompagne d'un crash du .exe.
//Il faut donc enlever cette ligne. Du moins, temporairement.



//Fonction de test pour SFML

int main()
{
	sf::RenderWindow window(sf::VideoMode(1080, 700), "SFML works!");
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	return 0;
}
*/