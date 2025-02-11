#include "PNJ.hpp"

PNJ::PNJ(sf::Vector2i startCell) {
    gridPosition = startCell;
    shape.setRadius(10.f);
    shape.setFillColor(sf::Color::Red);
    shape.setPosition(gridPosition.x * CELL_SIZE, gridPosition.y * CELL_SIZE);
}

void PNJ::setPath(std::vector<sf::Vector2i> newPath)
{
    path = newPath;
    currentIndexPath = 0;
    timer = 0.f;
}

void PNJ::update(float deltaTime)
{
    if (currentIndexPath >= path.size()) return;
    timer += deltaTime;
    if (timer >= cooldown) {
        timer = 0.f;

        gridPosition = path[currentIndexPath];
        shape.setPosition(gridPosition.x * CELL_SIZE, gridPosition.y * CELL_SIZE);
        currentIndexPath++;
    }
}