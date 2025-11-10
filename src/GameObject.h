#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SFML/Graphics.hpp>

class GameObject
{
public:
    GameObject();
    ~GameObject() = default;
    void init();
    bool initialiseSprite(sf::Texture& texture, std::string filename);

    bool initTextures(std::vector<std::unique_ptr<sf::Texture>>& texture_vector,
        const std::vector<std::string>& texture_location_vector);

    void render(sf::RenderWindow& window);

    sf::Sprite* getSprite();
    //bool checkCollision(GameObject& other);

    void setVisible(bool visibility);
    bool getVisible();


    int getRandInt(int min, int max);

    // debug
    void coutVector(std::vector<std::string>& vector);

protected:
    std::unique_ptr<sf::Sprite> sprite;
    bool visible = true;

};

#endif 