#include <SFML/Graphics.hpp>
#include "Grid.hpp"
#include "Pathfinding.hpp"
#include "PNJ.hpp"

int main() {
    sf::RenderWindow window(sf::VideoMode(GRID_WIDTH * CELL_SIZE, GRID_HEIGHT * CELL_SIZE), "Mini Projet");
    window.setFramerateLimit(60);
    sf::Clock clock;

    Grid grid;
    Pathfinding pathfinding;
    PNJ pnj(sf::Vector2i(5, 2));

    std::vector<sf::Vector2i> path = pathfinding.findPath(grid, sf::Vector2i(5, 2), sf::Vector2i(9, 11));
    pnj.setPath(path);
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();
        pnj.update(deltaTime);

        window.clear();
        grid.handleClick(window);
        grid.draw(window);
        window.draw(pnj.shape);
        window.display();
    }
    return 0;
}