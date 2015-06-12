#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;
using namespace std;

#include "Menu.hpp"

int main()
{
	///Create the Game Window.
	RenderWindow window(VideoMode(1080,720),"Project Gaawain");
	
	unsigned nbrmenus = 3;
	string* textmenu = new string[nbrmenus];
	textmenu[0] = "NEW GAME";
	textmenu[1] = "LOAD GAME";
	textmenu[2] = "OPTIONS";
	
	///Create the Game Menu
	Menu menu(window.getSize().x,window.getSize().y, nbrmenus, textmenu);
	delete[] textmenu;

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
	        						cout << "Starting a new game." << endl;
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
    return 0;

}