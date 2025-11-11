#include "GameObject.h"
#include <iostream>
using std::cout;
using std::endl;
using std::string;
using std::cerr;

GameObject::GameObject() : visible(true)
{
    sprite = std::make_unique<sf::Sprite>();
}

void GameObject::init() {}

bool GameObject::initialiseSprite(sf::Texture& texture, string filename)
{
    if (!texture.loadFromFile(filename))
    {
        cerr << "Failed to load " << filename << endl;
        return false;
    }

    sprite->setTexture(texture);
    return true;
}

bool GameObject::initTextures(std::vector<std::unique_ptr<sf::Texture>>& texture_vector,
    const std::vector<std::string>& texture_location_vector)
{
    int texture_size = texture_location_vector.size();
    texture_vector.resize(texture_size);

    for (int i = 0; i < texture_size; i++)
    {
        auto tex = std::make_unique<sf::Texture>();
        if (!tex->loadFromFile(texture_location_vector[i]))
        {
            std::cerr << "Failed to load " << texture_location_vector[i] << std::endl;
            return false;
        }
        texture_vector[i] = std::move(tex);
    }
    return true;
}

void GameObject::centerOrigin()
{
    sprite->setOrigin(sprite->getLocalBounds().width / 2, sprite->getLocalBounds().height / 2);
}


void GameObject::render(sf::RenderWindow& window)
{
    window.draw(*sprite);
}


sf::Sprite* GameObject::getSprite() //returns sprite, if sprite doens't exist, prints error message
{
    if (!sprite)
    {
        cerr << "Warning: sprite is null\n";
        return nullptr;
    }
    return sprite.get();
}

// getter and setter visibility boolean functions
void GameObject::setVisible(bool visibility)
{
    visible = visibility;
}

bool GameObject::getVisible()
{
    return visible;
}


// number rnadomiser
int GameObject::getRandInt(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

void GameObject::coutVector(std::vector<string>& vector)
{
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << std::endl;
    }
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