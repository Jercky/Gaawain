#include "Menu.hpp"

#include <iostream>
#include <string>

Menu::Menu(float width, float height) : selectedItemIndex(0)
{
	if (!font.loadFromFile("Data/Font/TerminusTTF-4.39.ttf"))
		std::cerr << "Error.";

	std::string textmenu[MAX_NUMBER_OF_ITEMS];
	textmenu[0] = "NEW GAME";
	textmenu[1] = "LOAD GAME";

	for (unsigned i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++)
	{	
		menut[i].setFont(font);
		menut[i].setColor(sf::Color::White);
		menut[i].setString(textmenu[i]);
		menut[i].setPosition(sf::Vector2f(width / (MAX_NUMBER_OF_ITEMS + 1.5) * (i+1), height / 2));
	}

	menut[0].setColor(sf::Color::Blue);
}

Menu::~Menu()
{}

	void Menu::draw(sf::RenderWindow& window)
	{
		for (unsigned i = 0 ; i < MAX_NUMBER_OF_ITEMS ; i++)
			window.draw(menut[i]);
	}

	void Menu::MoveLeft()
	{
		if (selectedItemIndex - 1 >= 0)
		{
			menut[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex--;
			menut[selectedItemIndex].setColor(sf::Color::Blue);
		}

	}
	void Menu::MoveRight()
	{
		if (selectedItemIndex + 1 < MAX_NUMBER_OF_ITEMS)
		{
			menut[selectedItemIndex].setColor(sf::Color::White);
			selectedItemIndex++;
			menut[selectedItemIndex].setColor(sf::Color::Blue);
		}

	}

