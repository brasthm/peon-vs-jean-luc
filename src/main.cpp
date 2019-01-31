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

		Input::instance().tracePressedButton();

		/*for (size_t i = 0; i < Input::instance().getConnectedPlayer(); i++)
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
			if (Input::instance().isButtonPressed(i, "start"))
				std::cout << "Joueur " << i << " : Start" << std::endl;
			if (Input::instance().isButtonPressed(i, "back"))
				std::cout << "Joueur " << i << " : Back" << std::endl;
			if (Input::instance().isButtonPressed(i, "leftstick"))
				std::cout << "Joueur " << i << " : Left stick click" << std::endl;
			if (Input::instance().isButtonPressed(i, "rightstick"))
				std::cout << "Joueur " << i << " : Right stick click" << std::endl;

			int position;

			position = Input::instance().getAxisPosition(i, "rightx");
			if (abs(position) > 10)
				std::cout << "Joueur " << i << " : Joystick Droit X - " << position << std::endl;
			position = Input::instance().getAxisPosition(i, "righty");
			if (abs(position) > 10)
				std::cout << "Joueur " << i << " : Joystick Droit Y - " << position << std::endl;

			position = Input::instance().getAxisPosition(i, "leftx");
			if (abs(position) > 10)
				std::cout << "Joueur " << i << " : Joystick Gauche X - " << position << std::endl;
			position = Input::instance().getAxisPosition(i, "lefty");
			if (abs(position) > 10)
				std::cout << "Joueur " << i << " : Joystick Gauche Y - " << position << std::endl;
		}*/

		window.clear(sf::Color::Black);
		window.display();
	}

	return 0;
}