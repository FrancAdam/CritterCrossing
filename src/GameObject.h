#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject();
    ~GameObject();
    void init();
    bool initialiseSprite(sf::Texture& texture, std::string filename);

    bool initTextures(std::vector<sf::Texture>& texture_vector, std::vector<std::string> texture_location_vector);

    void render(sf::RenderWindow& window);

    sf::Sprite* getSprite();
    //bool checkCollision(GameObject& other);

    void setVisible(bool visibility);
    bool getVisible();


    int getRandInt(int min, int max);

    // debug
    void coutVector(std::vector<std::string>& vector);

protected:
    sf::Sprite* sprite = nullptr;
    bool visible = true;

};

#endif 