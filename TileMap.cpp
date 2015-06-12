#include "TileMap.hpp"

TileMap::TileMap():m_vertices(),m_tileset(){}
TileMap::~TileMap(){}

bool TileMap::loadFile(const char* pathtolevel)
{
    ifstream file;
    file.open(pathtolevel);

    string line;
    char bin_var;

    ///Stocking level name and tower name (not implanted yet).
    file >> mapname;
    file >> towername;
    ///The path is usefull to create custom levels. With it you chose the 16x16 tileset you want.
    file >> pathtotiles;
    ///Before getting the whole level, we limitate the loops with the column and row values.
    file >> ymax >> xmax >> bin_var;
    char *level = new char[xmax*ymax]; 

    ///A simple loop to stock every tiles into a 1D table.
    for (unsigned i = 0 ; i < ymax ; i++)
    {
        getline(file, line);
        for (unsigned j = 0 ; j < xmax ; j++)
        {
            level[i*xmax+ j] = line[j];
        }
    }

    ///Reading the number of different tiles/item.
    unsigned nbtiles;
    file >> nbtiles;

    char tile_char;
    string tile_name;
    string tile_descr;

    for (unsigned i = 0 ; i < ymax ; i++)
        {for (unsigned j = 0 ; j < xmax ; j++)
            cerr << level[i*xmax + j ] << ' ';
            cerr << endl;}


    for (unsigned i = 0 ; i < nbtiles ; i++)
    {
        ///First, we load the char which will represent the tile/item. 
        file >> tile_char;
        file.get(bin_var);
        ///Then, we search how it is called in order to draw it at screen.
        ///We clear the name at each use and retire the and '(' at end.
        tile_name.clear();
        while (bin_var != '(')
        {
            file.get(bin_var);
            tile_name += bin_var;
        }
        tile_name.resize(tile_name.size()-1);
        ///Finally, we look after parameters for the tile/item. 
        ///The technique is the same as above.
        tile_descr.clear();
        while (bin_var != ')')
        {
            file.get(bin_var);
            tile_descr += bin_var;            
        }
        tile_descr.resize(tile_descr.size()-1);

        if (!load(tile_char, tile_name, level))
            return false;

    }

    delete[] level;
    return true;
}


bool TileMap::load(char tile_char, string tile_name, char* level)
{
    sf::Vector2u tileSize(32,32);

    if (!m_tileset.loadFromFile(pathtotiles))
        return false;
    
    m_vertices.setPrimitiveType(sf::Quads);
    m_vertices.resize(ymax * xmax * 4);

   if (tile_name == "Mur")
    {    for (unsigned i = 0 ; i < xmax ; i++)
            for (unsigned j = 0 ; j < ymax ; j++)
            {
                if (level [i + j* xmax ] == tile_char)
                {
                    int tu = 1 % (m_tileset.getSize().x / tileSize.x);
                    int tv = 1 / (m_tileset.getSize().x / tileSize.x);

                    sf::Vertex* quad = &m_vertices[(i + j * xmax) * 4];

                    quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                    quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                    quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                    quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                }

            }
    }
    else
    {    for (unsigned i = 0 ; i < xmax ; i++)
            for (unsigned j = 0 ; j < ymax ; j++)
            {
                if (level [i  + j* xmax ] == tile_char)
                {
                    int tu = 0 % (m_tileset.getSize().x / tileSize.x);
                    int tv = 0 / (m_tileset.getSize().x / tileSize.x);

                    sf::Vertex* quad = &m_vertices[(i + j* xmax ) * 4];

                    quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                    quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                    quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                    quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                    quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                    quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                    quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                    quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
                }
            }
    }
    return true;
}



/*
bool TileMap::load(	const std::string& tileset, sf::Vector2u tileSize, 
					const char* tiles, unsigned width, unsigned height)
    {
        // on charge la texture du tileset
        if (!m_tileset.loadFromFile(tileset))
            return false;

        // on redimensionne le tableau de vertex pour qu'il puisse contenir tout le niveau
        m_vertices.setPrimitiveType(sf::Quads);
        m_vertices.resize(width * height * 4);

        // on remplit le tableau de vertex, avec un quad par tuile
        for (unsigned int i = 0; i < width; ++i)
            for (unsigned int j = 0; j < height; ++j)
            {
                // on récupère le numéro de tuile courant
                int tileNumber = tiles[i + j * width];

                // on en déduit sa position dans la texture du tileset
                int tu = tileNumber % (m_tileset.getSize().x / tileSize.x);
                int tv = tileNumber / (m_tileset.getSize().x / tileSize.x);

                // on récupère un pointeur vers le quad à définir dans le tableau de vertex
                sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

                // on définit ses quatre coins
                quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
                quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
                quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
                quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

                // on définit ses quatre coordonnées de texture
                quad[0].texCoords = sf::Vector2f(tu * tileSize.x, tv * tileSize.y);
                quad[1].texCoords = sf::Vector2f((tu + 1) * tileSize.x, tv * tileSize.y);
                quad[2].texCoords = sf::Vector2f((tu + 1) * tileSize.x, (tv + 1) * tileSize.y);
                quad[3].texCoords = sf::Vector2f(tu * tileSize.x, (tv + 1) * tileSize.y);
            }

        return true;
    }
*/

