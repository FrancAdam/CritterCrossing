#include "GameObject.h"
#include <iostream>

GameObject::GameObject() : visible(true)
{
    sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
    if (sprite != nullptr)
    {
        delete sprite;
        sprite = nullptr;
    }
}

void GameObject::init() {}

bool GameObject::initialiseSprite(sf::Texture& texture, std::string filename)
{
    if (!texture.loadFromFile(filename))
    {
        std::cerr << "Failed to load " << filename << std::endl;
        return false;
    }

    sprite->setTexture(texture);
    return true;
}

sf::Sprite* GameObject::getSprite()
{
    if (!sprite)
    {
        std::cerr << "Warning: sprite is null\n";
    }
    return sprite;
}


void GameObject::setVisible(bool visibility)
{
    visible = visibility;
}

bool GameObject::getVisible()
{
    return visible;
}



int GameObject::getRandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

//bool GameObject::checkCollision(GameObject& other)
//{
//    if (!sprite || !other.sprite || !other.getVisible())
//        return false;
//
//    // bounds
//    sf::FloatRect Bounds1 = sprite->getGlobalBounds();
//    sf::FloatRect Bounds2 = other.sprite->getGlobalBounds();
//
//    // overlap check
//    bool overlapX = (Bounds1.left < Bounds2.left + Bounds2.width) &&
//        (Bounds1.left + Bounds1.width > Bounds2.left);
//
//    bool overlapY = (Bounds1.top < Bounds2.top + Bounds2.height) &&
//        (Bounds1.top + Bounds1.height > Bounds2.top);
//
//    return overlapX && overlapY; // True if both X and Y overlap
//}