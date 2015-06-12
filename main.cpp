#include <fstream>
#include <string>
#include <iostream>
#include <SFML/Graphics.hpp>
using namespace std;
using namespace sf;

#include "TileMap.hpp"
#include "Menu.hpp"

int main()
{
    ///Create the Game Window.
    RenderWindow window(sf::VideoMode(1080, 700), "Gaawain");
    
    unsigned nbrmenus = 3;
    string* textmenu = new string[nbrmenus];
    textmenu[0] = "NEW GAME";
    textmenu[1] = "LOAD GAME";
    textmenu[2] = "OPTIONS";
    
    ///Create the Game Menu
    Menu menu(window.getSize().x,window.getSize().y, nbrmenus, textmenu);
    delete[] textmenu;

    TileMap mytilemap;
    if (!mytilemap.loadFile("Data/Map/Level/level1.txt"))
        return -1;

    string GAME = "MENU";

    /*/While the Game Window is open : we check at each event if the user try to close the window.
    If he does, we close the window.*/
    while (window.isOpen())
    {
        Event event;
        while(GAME == "MENU")
        {
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                        switch (event.key.code)
                        {
                            case Keyboard::Up : case Keyboard::Left :
                                menu.MoveLeft();
                                break;
                            case Keyboard::Down : case Keyboard::Right :
                                menu.MoveRight();
                                break;
                            case Keyboard::Return:
                                switch (menu.GetPressedItem())
                                {
                                    case 0:
                                        GAME = "ON";
                                        break;
                                    case 1:
                                        cout << "Load an existing game." << endl;
                                        break;
                                    case 2:
                                        cout << "Change parameters." << endl;
                                        break;
                                    default:
                                        break;
                                }
                                break;
                            case Keyboard::Escape:
                                window.close();
                                break;  
                            default:
                                break;
                        }
                    break;

                    case Event::Closed :
                        window.close();
                        break;
                    default:
                        break;
                }
                window.clear();
                menu.draw(window);
                window.display();
            }
        }

        while(GAME == "ON")
        {
            while (window.pollEvent(event))
            {
                switch (event.type)
                {
                    case sf::Event::KeyReleased:
                        switch (event.key.code)
                        {
                            case Keyboard::Escape:
                                GAME = "MENU";
                                break;  
                            default:
                                break;
                        }
                    break;

                    case Event::Closed :
                        window.close();
                        break;
                    default:
                        break;
                }
                window.clear();
                window.draw(mytilemap);
                window.display();
            }
        }
    }



}



/*
int main()
{
    sf::RenderWindow window(sf::VideoMode(1080, 700), "Gaawain");

    TileMap mytilemap;
    if (!mytilemap.loadFile("Data/Map/Level/level1.txt"))
        return -1;

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
        window.draw(mytilemap);
        window.display();
    }

    return 0;
}

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