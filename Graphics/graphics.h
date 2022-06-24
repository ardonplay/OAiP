//
// Created by vladimir on 8.05.22.
//

#ifndef LAB8_GRAPHICS_H
#define LAB8_GRAPHICS_H
#include <fstream>
#include <iostream>
#include <filesystem>
#include <regex>
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <cmath>
class graphics {
private:
public:
    void gif (unsigned int delay, std::string  directory_of_first_image,sf::RenderWindow &window);
    void graph(sf::RenderWindow &window,float wight, float height);
    void renaming(std::string Directory);
};


#endif //LAB8_GRAPHICS_H
