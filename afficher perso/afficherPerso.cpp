#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "afficherPerso.hpp"

afficherPerso::afficherPerso(): posx(100), posy(100){ 
        
        if (!texture.loadFromFile("Hero.png"))
        {
                 std::cout << "Error loading hero.png" << std::endl;
        }
        spritePerso.setTexture(texture);
        spritePerso.setPosition(100, 100);
		
}
afficherPerso::~afficherPerso()	{

}
float afficherPerso::get_posx() const
{
    return posx;
}
 
float afficherPerso::get_posy() const
{
    return posy;
}
 
sf::Sprite afficherPerso::GetSprite() const
{
    return spritePerso;
}