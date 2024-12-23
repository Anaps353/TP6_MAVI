#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    const float step = 50.00;
    const float circleRadius = 30.00;

    RenderWindow window(VideoMode(800, 600), "Space");

    sf::CircleShape circle(circleRadius);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition((window.getSize().x - 2 * circleRadius) / 2, (window.getSize().y - 2 * circleRadius) / 2);

    sf::Vector2f speed(0.0f, 0.0f);
    sf::Vector2f acceleration(0.0f, 0.0f);
    sf::Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }
        acceleration.x = 0.0f;
        acceleration.y = 0.0f;
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
            acceleration.x += step;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
            acceleration.x -= step;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
            acceleration.y -= step;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
            acceleration.y += step;
        }

        float deltaTime = clock.restart().asSeconds();

        speed += acceleration * deltaTime;

        sf::Vector2f circlePosition = circle.getPosition();
        circlePosition += speed * deltaTime;

        if (circlePosition.x < 0) {
            circlePosition.x = 0;
            speed.x = 0;
        }
        else if (circlePosition.x + 2 * circleRadius > window.getSize().x) {
            circlePosition.x = window.getSize().x - 2 * circleRadius;
            speed.x = 0;
        }

        if (circlePosition.y < 0) {
            circlePosition.y = 0;
            speed.y = 0;
        }
        else if (circlePosition.y + 2 * circleRadius > window.getSize().y) {
            circlePosition.y = window.getSize().y - 2 * circleRadius;
            speed.y = 0;
        }

        circle.setPosition(circlePosition);

        window.clear();
        window.draw(circle);
        window.display();
    }

    return 0;

}