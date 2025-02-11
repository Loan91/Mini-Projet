#ifndef PNJ_HPP
#define PNJ_HPP

#include <SFML/Graphics.hpp>
#include <cmath>
#include "Pathfinding.hpp"
#include "Grid.hpp"

class PNJ {
public:
    sf::Vector2f position;
    float speed = 50.f;
    sf::CircleShape shape;
    sf::Vector2i gridPosition;
    std::vector<sf::Vector2i> path;
    int currentIndexPath = 0;
    float cooldown = 0.2f;
    float timer = 0.f;
    PNJ(sf::Vector2i startCell);
    void setPath(std::vector<sf::Vector2i> newPath);
    void update(float deltaTime);
};
#endif