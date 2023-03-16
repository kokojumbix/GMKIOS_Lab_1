#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>
#include <math.h>

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
		hexagon.setRotation(30.0f);

		RectangleShape line_with_thickness(Vector2f(2560.f, 2.f));
		line_with_thickness.rotate(60.f);
		line_with_thickness.setFillColor(Color::Black);
		line_with_thickness.setPosition(0, 0);


		for (int i = 0; i < 1 + window.getSize().x / (distance / 1.5); i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance ); y++) {
				hexagon.setPosition(-circleradius + i * circleradius * 1.5, y  * distance - circleradius + ((i + 1) % 2 * distance / 2));				
				window.draw(hexagon);
				hexagon.setOutlineThickness(1.0f);
			}
		}

		for (int i = 0; i < 1 + window.getSize().x / (distance/3.0); i++) {
			line_with_thickness.setPosition(i * circleradius  - 16 - circleradius, 0);
			window.draw(line_with_thickness);
			
		}

		for (int y = 0; y < 2 + window.getSize().y / (distance); y++) {
			line_with_thickness.setPosition(0, y * distance + 1.5 * distance - 15 );
			window.draw(line_with_thickness);
		}
		
		line_with_thickness.rotate(30.f);
		for (int i = 0; i < 1 + 2 * window.getSize().x / distance; i++) {
			line_with_thickness.setPosition(i * circleradius * 1.5 - 30, 0);
			window.draw(line_with_thickness);
		}

		line_with_thickness.rotate(30.f);
		for (int i = 0; i < 1 + window.getSize().x / (distance / 3.0); i++) {
			line_with_thickness.setPosition(i * circleradius - 45 - circleradius, 0);
			window.draw(line_with_thickness);

		}

		line_with_thickness.rotate(30.f);
		for (int i = 0; i < 1 + window.getSize().x / (distance / 3.0); i++) {
			line_with_thickness.setPosition(i * circleradius * 3 - 22 - circleradius, 0);
			window.draw(line_with_thickness);

		}

		line_with_thickness.rotate(-150.f);
		for (int y = 0; y < 2 + window.getSize().y / (distance / 2); y++) {
			line_with_thickness.setPosition(0, y * distance / 2 - 26);
			window.draw(line_with_thickness);
		}

		line_with_thickness.rotate(30.f);
		for (int i = 0; i < 1 + window.getSize().x / (distance / 3.0); i++) {
			line_with_thickness.setPosition(i * circleradius * 3 + 14, 0);
			window.draw(line_with_thickness);
		}

		for (int y = 0; y < 2 + window.getSize().y / (distance); y++) {
			line_with_thickness.setPosition(0, y * distance + 1.5 * distance - circleradius );
			window.draw(line_with_thickness);
		}


		hexagon.setRadius(circleradius - 2);
		hexagon.setFillColor(Color::White);
		for (int i = 0; i < 1 + window.getSize().x / (distance / 1.5); i++) {
			for (int y = 0; y < 2 + window.getSize().y / (distance); y++) {
				if ((i+(y%2)*2 ) % 4 == 0) {
					hexagon.setPosition(-circleradius + i * circleradius * 1.5 + 0.75, 2.75 + y * distance - circleradius + ((i + 1) % 2 * distance / 2));

					window.draw(hexagon);
					hexagon.setOutlineThickness(1.0f);
				}
			}
		}


		
		





		window.display();
	}

	return 0;
}