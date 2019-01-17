#include "Input.hpp"
#include "Utils.h"
#include <iostream>
#include <algorithm>

Input::Input()
{
	sf::Joystick::update();
	int nbConnected = 0;
	for (int i = 0; i < sf::Joystick::Count; i++)
		if (sf::Joystick::isConnected(i))
			nbConnected++;
	std::cout << nbConnected << " controllers connected." << std::endl;

}

void Input::waitForConnection()
{
	for (int i = 0; i < sf::Joystick::Count; i++)
	{
		if (!Utils::contains(connected_, i) && sf::Joystick::isConnected(i))
		{
			for (int button = 0; button < sf::Joystick::getButtonCount(i); button++)
			{
				if (sf::Joystick::isButtonPressed(i, button)) 
				{
					connected_.emplace_back(i);
					std::cout << "Player " << connected_.size() << " connected (controller " << i << ")" << std::endl;
				}
			}
		}
	}
}

Input & Input::instance()
{
	return inputInstance;
}

int const Input::getConnectedPlayer()
{
	return connected_.size();
}

void Input::tracePressedButton()
{
	for (int i = 0; i < sf::Joystick::Count; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			for (int button = 0; button < sf::Joystick::getButtonCount(i); button++)
			{
				if (sf::Joystick::isButtonPressed(i, button))
					std::cout << "Button " << button << " pressed on controller " << i << std::endl;
			}
		}
	}
}
