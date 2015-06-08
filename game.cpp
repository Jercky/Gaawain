#include <iostream>
#include <stdexcept>

#include "game.hpp"

Game::Game()
: mWindow(sf::VideoMode(1080, 700), "Project Gaawain")
, mPlayer()
, mTexture()
{
    if (!mTexture.loadFromFile("Data/Textures/Herso.png"))
    {
        throw std::runtime_error("TextureHolder::load - Failed to load Data/Textures/Herso.png");
    }
    mPlayer.setTexture(mTexture);
    mPlayer.setPosition(100.f, 100.f);
}

Game::~Game(){}

void Game::handlePlayerInput(sf::Keyboard::Key key,bool isPressed)
{  
    switch (key)
    {
        case sf::Keyboard::Z:
            mIsMovingUp = isPressed;
            break;
        case sf::Keyboard::S:
            mIsMovingDown = isPressed;
            break;
        case sf::Keyboard::Q:
            mIsMovingLeft = isPressed;
            break;
        case sf::Keyboard::D:
            mIsMovingRight = isPressed;
            break;
        default:
            break;
    }
}

void Game::processEvents()
{
    sf::Event event;
    while (mWindow.pollEvent(event))
    {
        switch (event.type) 
        {
            case sf::Event::KeyPressed:
                handlePlayerInput(event.key.code, true);
                break;

            case sf::Event::KeyReleased:
                handlePlayerInput(event.key.code, false);
                break;

            case sf::Event::Closed:
                mWindow.close();
                break;

            default:
                break;
        }
    }
}

void Game::update(sf::Time deltaTime)
{
    sf::Vector2f movement(0.f, 0.f);

    if (mIsMovingUp)
        movement.y -= 1.f;
    if (mIsMovingDown)
        movement.y += 1.f;
    if (mIsMovingLeft)
        movement.x -= 1.f;
    if (mIsMovingRight)
        movement.x += 1.f;

    mPlayer.move(movement * deltaTime.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}

void Game::run()
{
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while (mWindow.isOpen())
    {
        processEvents();
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -= TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}
