#include <SFML/Graphics.hpp>
#include <iostream>
#include <SFML/Window/Mouse.hpp>

using namespace sf;

class ShapeObj
{
public:
	ShapeObj();
	~ShapeObj();

private:

};

ShapeObj::ShapeObj()
{
}

ShapeObj::~ShapeObj()
{
}

class ShapeGrid
{
public:
	ShapeGrid(float circumscribed_r, int anglescount, float angle );
	~ShapeGrid();

	void set_circumscribed_r(float r) {
		if (r < 10.0f) {
			this->circumscribed_r = 10.0f;
		}
		else {
			this->circumscribed_r = r;
		}
	}

	float get_circumscribed_r() {
		return circumscribed_r;
	}

	void set_anglescount(int anglescount) {
		if (anglescount < 3) {
			this->anglescount = 3;
		}
		else if (anglescount > 6) {
			this->anglescount = 6;
		}
		else {
			this->anglescount = anglescount;
		}
	}

	float get_anglescount() {
		return anglescount;
	}

	void set_angle(float angle) {
		this->angle = angle;
	}

	float get_angle() {
		return angle;
	}

	void set_limits(int x = 640, int y = 480) {
		this->limitx = x;
		this->limity = y;
	}

	

private:
	float circumscribed_r;
	int anglescount;
	float angle;
	int limitx;
	int limity;
};

ShapeGrid::ShapeGrid(float circumscribed_r = 50.0f, int anglescount = 6, float angle = 0.0f)
{
	this->set_circumscribed_r(circumscribed_r);
	this->set_anglescount(anglescount);
	this->set_angle(angle);
}

ShapeGrid::~ShapeGrid()
{
}


int main()
{
	sf::ContextSettings settings = sf::ContextSettings();
	settings.antialiasingLevel = 16;
	RenderWindow window(VideoMode(640, 480), "Udachi na interview", 7U, settings);
	window.setFramerateLimit(60);

	while (window.isOpen())
	{

		sf::Vector2i position = sf::Mouse::getPosition(window);

		std::cout << position.x << " " << position.y << "\n";

		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)

				window.close();
		}

		ConvexShape convex;

		window.clear(Color(255, 255, 255, 0));

		float circleradius = 50.0f;
		float distance = circleradius * sqrt(3.0f);
		CircleShape hexagon(circleradius, 4);
		hexagon.setFillColor(Color::Transparent);
		hexagon.setOutlineColor(Color::Black);
		hexagon.setOutlineThickness(1.0f);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 9; y++) {
				hexagon.setPosition(-50 + i * distance + ((y + 1) % 2 * distance / 2), y * circleradius * 1.5 - 50);

				if (hexagon.getGlobalBounds().contains(position.x, position.y) ) {
					hexagon.setOutlineThickness(3.0f);
				}


				window.draw(hexagon);
				hexagon.setOutlineThickness(1.0f);
			}
		}

		hexagon.setRadius(35.0f);
		hexagon.setOutlineThickness(5.0f);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 9; y++) {
				hexagon.setPosition(-50 + i * distance + ((y + 1) % 2 * distance / 2) + 15.0f, y * circleradius * 1.5 - 50 + 15.0f);
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(25.0f);
		hexagon.setOutlineThickness(1.0f);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 9; y++) {
				hexagon.setPosition(-50 + i * distance + ((y + 1) % 2 * distance / 2) + 25.0f, y * circleradius * 1.5 - 50 + 25.0f);
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(10.0f);
		hexagon.setOutlineThickness(5.0f);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 9; y++) {
				hexagon.setPosition(-50 + i * distance + ((y + 1) % 2 * distance / 2) + 40.0f, y * circleradius * 1.5 - 50 + 40.0f);
				window.draw(hexagon);
			}
		}

		hexagon.setRadius(5.0f);
		hexagon.setOutlineThickness(1.0f);

		for (int i = 0; i < 10; i++) {
			for (int y = 0; y < 9; y++) {
				hexagon.setPosition(-50 + i * distance + ((y + 1) % 2 * distance / 2) + 45.0f, y * circleradius * 1.5 - 50 + 45.0f);
				window.draw(hexagon);
			}
		}


		window.display();
	}

	return 0;
}