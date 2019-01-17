#include <SFML/Graphics.hpp>
#include "Input.hpp"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Péon vs Jean Luc");

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		Input::instance().waitForConnection();
		if (Input::instance().getConnectedPlayer() == 3)
			Input::tracePressedButton();

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}