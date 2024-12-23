#include <SFML/Graphics.hpp>
using namespace sf;

int main() {
	const float v0 = 500.00;
	const float v1 = 2000.00;
	const float step = 50.00;
	const float circleRadius = 30.00;

	RenderWindow window(VideoMode(800, 600), "Fast & Furious");

	sf::CircleShape circle(circleRadius);
	circle.setFillColor(sf::Color::Green);
	circle.setPosition(0, (window.getSize().y - 2 * circleRadius) / 2);

	float speed = v0;
	sf::Clock clock;
	bool showCircle = true;

	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event)) {
			if (event.type == Event::Closed)
				window.close();
		}

		float deltaTime = clock.restart().asSeconds();

		sf::Vector2f posicion = circle.getPosition();
		posicion.x += speed * deltaTime;

		if (posicion.x - circleRadius > window.getSize().x) {
			posicion.x = -circleRadius;
			speed += step;

			if (speed >= v1) {
				showCircle = false;
			}
		}

		circle.setPosition(posicion);

		window.clear();
		if (showCircle)
		{
			window.draw(circle);
		}
		window.display();

	}

	return 0;

}