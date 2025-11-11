#ifndef PASSPORT_H
#define PASSPORT_H
#define PASSPORT_SCALE 0.6

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Passport : public GameObject
{
public:
	~Passport();
	bool initPassportTextures();
	void changePassport(int random_index);
	int getPassportSize();
	sf::Vector2f getPosition();
private:
	//sf::Texture* passport_textures = new sf::Texture[3];
	std::vector<std::unique_ptr<sf::Texture>> passport_textures;
	std::vector<std::string> passport_texture_location;


};

#endif
