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
    sf::Sprite* getSprite();
    //bool checkCollision(GameObject& other);

    void setVisible(bool visibility);
    bool getVisible();


    int getRandInt(int min, int max);



protected:
    sf::Sprite* sprite = nullptr;
    bool visible = true;

};

#endif // SPACEINVADERS_GAME_H