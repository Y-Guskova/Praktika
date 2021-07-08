#include <SFML/Graphics.hpp>
#include <iostream>

//Вариант 2. Вращаем треугольник

int main()
{
	sf::RenderWindow window(sf::VideoMode(300, 300), "Window!");

	bool rotation = 0;


	while (window.isOpen())
	{
		sf::CircleShape triangle(65.f, 3);
        triangle.setPosition(125, 0); 
		triangle.setFillColor(Color::Blue); 
		window.draw(triangle);
		sf::Event event;
		
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::A) rotation = true;
				if (event.key.code == sf::Keyboard::D) rotation = false;
				break;
			}

		}

		if (rotation) rect.rotate(2);
	}

	return 0;
}
