#ifndef TEXTUREMANAGER_HPP
#define TEXTUREMANAGER_HPP

#include "SFML/Graphics.hpp"
#include "ResourceManager.hpp"

class TextureManager : public ResourceManager<TextureManager, sf::Texture>
{
public:
    TextureManager() : ResourceManager("textures.txt")
    {

    }

    sf::Texture* load(const std::string & fileName);
};

#endif // TEXTUREMANAGER_HPP
