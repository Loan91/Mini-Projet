#include "Grid.hpp"

Grid::Grid() {
    grid.resize(GRID_HEIGHT, std::vector<int>(GRID_WIDTH, 0));

    for (int i = 5; i < 15; i++) {
        grid[5][i] = 1;
    }
}

void Grid::handleClick(sf::RenderWindow& window) {
    sf::Vector2i mousePos = sf::Mouse::getPosition(window);
    int gridX = mousePos.x / CELL_SIZE;
    int gridY = mousePos.y / CELL_SIZE;
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        grid[gridY][gridX] = 1;
    }
    else if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
    {
        grid[gridY][gridX] = 0;
    }
}

void Grid::draw(sf::RenderWindow& window) {
    for (int y = 0; y < GRID_HEIGHT; y++) {
        for (int x = 0; x < GRID_WIDTH; x++) {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(x * CELL_SIZE, y * CELL_SIZE);
            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::Black);

            if (grid[y][x] == 1) {
                cell.setFillColor(sf::Color::Black);
            }
            else if (grid[y][x] == 2) {
                cell.setFillColor(sf::Color::Red);
            }
            else {
                cell.setFillColor(sf::Color::White);
            }

            window.draw(cell);
        }
    }
}
