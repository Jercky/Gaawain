#include <SFML/Graphics.hpp>
#include "afficherPerso.hpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode(600, 600), "Densetsu no hero");
	afficherPerso Personnage;
	
	 while (window.isOpen())
    {
        // on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
        sf::Event event;
        while (window.pollEvent(event))
        {
            // évènement "fermeture demandée" : on ferme la fenêtre
            switch (event.type)
			{
			case sf::Event::MouseButtonPressed:
				window.close();
			
			case sf::Event::Closed:
				window.close();
				
			default:
				break;
			}
        }
		
			window.clear(sf::Color(0,0,0));
			window.display();
			window.draw(Personnage.GetSprite());
    }

    return 0;
}
