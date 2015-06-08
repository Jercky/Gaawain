#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>

const sf::Time		TimePerFrame = sf::seconds(1.f / 60.f);

class Game
{
    public:
    	Game();
    	~Game();
        void             run();

    private:

    
    	bool			mIsMovingUp;
		bool 			mIsMovingDown;
		bool 			mIsMovingLeft;
		bool 			mIsMovingRight;

    	void 			 handlePlayerInput(sf::Keyboard::Key key,bool isPressed);
        void             processEvents();
        void             update(sf::Time);
        void             render();

        sf::RenderWindow mWindow;
        sf::Sprite  	 mPlayer;
        sf::Texture		 mTexture;
};

#endif