#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#include "Menu.hpp"

int main()
{
	///Create the Game Window.
	RenderWindow window(VideoMode(1080,720),"Project Gaawain");

	///Create the Game Menu
	Menu menu(window.getSize().x,window.getSize().y);

	/*/While the Game Window is open : we check at each event if the user try to close the window.
	If he does, we close the window.*/
	while(window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
	        switch (event.type)
	        {
	        	case sf::Event::KeyReleased:
	        		switch (event.key.code)
	        		{
	        			case sf::Keyboard::Up : case sf::Keyboard::Left :
	        				menu.MoveLeft();
	        				break;
	        			case sf::Keyboard::Down : case sf::Keyboard::Right :
	        				menu.MoveRight();
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

}