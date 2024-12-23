#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
    const float circleRadius = 30.00;

    RenderWindow window(VideoMode(800, 600), "Bounce");

    sf::CircleShape circle(circleRadius);
    circle.setFillColor(sf::Color::Green);
    circle.setPosition((window.getSize().x - 2 * circleRadius) / 2, (window.getSize().y - 2 * circleRadius) / 2);

    float speed = 0;
    float gravityAcceleration = 10000;
    float bounceAccelerationFactor = 0.7;
    sf::Clock clock;

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        float deltaTime = clock.restart().asSeconds();

        speed += gravityAcceleration * deltaTime;

        sf::Vector2f circlePosition = circle.getPosition();
        circlePosition.y += speed * deltaTime;

        if (circlePosition.y + circleRadius * 2 >= window.getSize().y) {
            circlePosition.y = window.getSize().y - circleRadius * 2;
            speed = -speed * bounceAccelerationFactor;
        }

        circle.setPosition(circlePosition);

        window.clear();
        window.draw(circle);
        window.display();
    }
    return 0;

}