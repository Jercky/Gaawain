#ifndef MENU_HPP
#define MENU_HPP

#include <SFML/Graphics.hpp>
#include <string>

class Menu {
private:
	unsigned MAX_NUMBER_OF_ITEMS;
	int selectedItemIndex;
	sf::Text* menu_option;
	sf::Font font;

public:
	Menu(float width, float height, unsigned max, std::string* tmenu);
	~Menu();

	void draw(sf::RenderWindow&);
	void MoveLeft();
	void MoveRight();
	inline int GetPressedItem() {return selectedItemIndex;}
};

#endif