#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>

using namespace sf;

float circletouch(float radius, Vector2i mousepoint, Vector2f targetpoint, float min = 1, float max = 5) {
	float distance = sqrt(pow(mousepoint.x - targetpoint.x, 2.0f) + pow(mousepoint.y - targetpoint.y, 2.0f));
	if (distance < 50.0f) {
		return min;
	}
	else if (distance > radius) {
		return max;
	}
	else {
		return min + (max - min) * distance / radius;
	}
}


int main()
{
	sf::ContextSettings settings = sf::ContextSettings();
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(1920, 1080), "Lab 1", 7U, settings);
	window.setFramerateLimit(60);
	bool lock = false;

	sf::RenderTexture text;
	text.create(window.getSize().x, window.getSize().y);

	sf::Clock clock;

	while (window.isOpen())
	{

		sf::Vector2i position = sf::Mouse::getPosition(window);




		Event event;
		while (window.pollEvent(event))
		{


			if (event.mouseButton.button == sf::Mouse::Left) {

			}

			if (event.type == Event::Closed)
				window.close();
		}


		window.clear(Color(255, 255, 255, 0));

		float circleradius = 50.0f;
		float distance = circleradius * sqrt(3.0f);
		CircleShape hexagon(circleradius, 6);
		hexagon.setFillColor(Color::Transparent);
		hexagon.setOutlineColor(Color::Black);
		hexagon.setOutlineThickness(1.0f);


		for (int i = 0; i < 1 + window.getSize().x / distance; i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance / 1.5); y++) {
				hexagon.setPosition(-circleradius + i * distance + ((y + 1) % 2 * distance / 2), y * circleradius * 1.5 - circleradius);

				//if (hexagon.getGlobalBounds().contains(position.x, position.y) ) {
				//	hexagon.setOutlineThickness(3.0f);
				//}

				window.draw(hexagon);
				hexagon.setOutlineThickness(1.0f);
			}
		}

		hexagon.setRadius(35.0f);
		hexagon.setOutlineThickness(5.0f);

		for (int i = 0; i < 1 + window.getSize().x / distance; i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance / 1.5); y++) {

				hexagon.setPosition(-circleradius + i * distance + ((y + 1) % 2 * distance / 2) + (circleradius - hexagon.getRadius()), y * circleradius * 1.5 - circleradius + (circleradius - hexagon.getRadius()));
				hexagon.setOutlineThickness(abs(sin(clock.getElapsedTime().asSeconds() + i / 6.0f + i / 4 + y / 6.0f) * 10) + 1);
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(25.0f + sin(clock.getElapsedTime().asSeconds()) * 5);
		hexagon.setOutlineThickness(1);

		for (int i = 0; i < 1 + window.getSize().x / distance; i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance / 1.5); y++) {
				hexagon.setPosition(-circleradius + i * distance + ((y + 1) % 2 * distance / 2) + (circleradius - hexagon.getRadius()), y * circleradius * 1.5 - circleradius + (circleradius - hexagon.getRadius()));
				hexagon.setOutlineThickness(abs(sin(clock.getElapsedTime().asSeconds() + i / 3 + y / 3)));
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(10.0f);
		hexagon.setOutlineThickness(5.0f);

		for (int i = 0; i < 1 + window.getSize().x / distance; i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance / 1.5); y++) {
				hexagon.setPosition(-circleradius + i * distance + ((y + 1) % 2 * distance / 2) + (circleradius - hexagon.getRadius()), y * circleradius * 1.5 - circleradius + (circleradius - hexagon.getRadius()));
				float thickness = circletouch(250.0f, position, hexagon.getPosition());
				hexagon.setOutlineThickness(thickness);
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(5.0f);
		hexagon.setOutlineThickness(5.0f);


		for (int i = 0; i < 1 + window.getSize().x / distance; i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance / 1.5); y++) {
				hexagon.setPosition(-circleradius + i * distance + ((y + 1) % 2 * distance / 2) + (circleradius - hexagon.getRadius()), y * circleradius * 1.5 - circleradius + (circleradius - hexagon.getRadius()));
				window.draw(hexagon);
			}
		}





		window.display();
	}

	return 0;
}