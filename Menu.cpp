#include "Menu.hpp"

#include <iostream>

Menu::Menu(float width, float height, unsigned max, std::string* textmenu) : MAX_NUMBER_OF_ITEMS(max), selectedItemIndex(0)
{
	if (!font.loadFromFile("Data/Font/TerminusTTF-4.39.ttf"))
		std::cerr << "Error.";

	menu_option = new sf::Text[MAX_NUMBER_OF_ITEMS];

	for (unsigned i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++)
	{	
		menu_option[i].setFont(font);
		menu_option[i].setColor(sf::Color::White);
		menu_option[i].setString(textmenu[i]);
		menu_option[i].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1.5) * (i+1), height / 2));
	}

	menu_option[0].setColor(sf::Color::Blue);
}

Menu::~Menu()
{
	delete[] menu_option;
}

	void Menu::draw(sf::RenderWindow& window)
	{

		for (unsigned i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++)
			window.draw(menu_option[i]);
	}

	void Menu::MoveLeft()
	{
		if (selectedItemIndex - 1 >= 0)
		{
			menu_option[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex--;
			menu_option[selectedItemIndex].setColor(sf::Color::Blue);
		}

	}
	void Menu::MoveRight()
	{
		if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
		{
			menu_option[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menu_option[selectedItemIndex].setColor(sf::Color::Blue);
		}

	}

