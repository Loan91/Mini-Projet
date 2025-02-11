#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <SFML/Graphics.hpp>

const int GRID_WIDTH = 20;
const int GRID_HEIGHT = 15;
const int CELL_SIZE = 40;

class Grid {
public:
    std::vector<std::vector<int>> grid;

    Grid();
    void draw(sf::RenderWindow& window);
    void handleClick(sf::RenderWindow& window);
};

#endif