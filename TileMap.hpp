#ifndef TILEMAP_HPP
#define TILEMAP_HPP

#include <string>
#include <SFML/Graphics.hpp>

class TileMap: public sf::Drawable, public sf::Transformable
{
private:
	
virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // on applique la transformation
    states.transform *= getTransform();

    // on applique la texture du tileset
    states.texture = &m_tileset;

    // et on dessine enfin le tableau de vertex
    target.draw(m_vertices, states);
}
	sf::VertexArray 	m_vertices;
	sf::Texture 		m_tileset;

public:
	TileMap():m_vertices(),m_tileset(){}
	~TileMap(){}
	bool 				load(const std::string& tileset, sf::Vector2u tileSize, 
						const char* tiles, unsigned width, unsigned height);

};

#endif
