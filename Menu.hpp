#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>

#define MAX_NUMBER_OF_ITEMS 2

class Menu {
private:
	int selectedItemIndex;
	sf::Font font;
	sf::Text menut[MAX_NUMBER_OF_ITEMS];

public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow&);
	void MoveLeft();
	void MoveRight();
};

#endif