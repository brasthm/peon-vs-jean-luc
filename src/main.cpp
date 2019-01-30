#include <SFML/Graphics.hpp>
#include <iostream>

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

		//Input::instance().tracePressedButton();

		int position = Input::instance().getAxisPosition(0, "rightx");
		if (position != 0)
			std::cout << "Joueur 1 : " << position << std::endl;


		for (size_t i = 0; i < Input::instance().getConnectedPlayer(); i++)
		{
			if (Input::instance().isButtonPressed(i, "a"))
				std::cout << "Joueur " << i << " : A" << std::endl;
			if (Input::instance().isButtonPressed(i, "b"))
				std::cout << "Joueur " << i << " : B" << std::endl;
			if (Input::instance().isButtonPressed(i, "x"))
				std::cout << "Joueur " << i << " : X" << std::endl;
			if (Input::instance().isButtonPressed(i, "y"))
				std::cout << "Joueur " << i << " : Y" << std::endl;
			if (Input::instance().isButtonPressed(i, "leftshoulder"))
				std::cout << "Joueur " << i << " : L1" << std::endl;
			if (Input::instance().isButtonPressed(i, "rightshoulder"))
				std::cout << "Joueur " << i << " : R1" << std::endl;
			if (Input::instance().isButtonPressed(i, "lefttrigger"))
				std::cout << "Joueur " << i << " : L2" << std::endl;
			if (Input::instance().isButtonPressed(i, "righttrigger"))
				std::cout << "Joueur " << i << " : R2" << std::endl;
		}

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}