#include "Input.hpp"
#include "Utils.h"
#include <iostream>
#include <algorithm>
#include <fstream>

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
					std::cout << "identification { name : " << sf::Joystick::getIdentification(i).name.toAnsiString()<<", productId : " << sf::Joystick::getIdentification(i).productId <<", manufaturerId : " << sf::Joystick::getIdentification(i).vendorId <<"}"<< std::endl;
					parseGamePadDB(sf::Joystick::getIdentification(i).name.toAnsiString());
				}
			}
		}
	}
}

Input & Input::instance()
{
	static Input instance;
	return instance;
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

void Input::traceJoystick()
{
	for (int i = 0; i < sf::Joystick::Count; i++)
	{
		if (sf::Joystick::isConnected(i))
		{
			for (int joystick = 0; joystick < sf::Joystick::AxisCount; joystick++)
			{
				if (sf::Joystick::hasAxis(i, static_cast<sf::Joystick::Axis>(joystick)))
					if(abs(sf::Joystick::getAxisPosition(i, static_cast<sf::Joystick::Axis>(joystick))) > 10)
						std::cout << "Joystick " << joystick << " moved on controller " << i << std::endl;
			}
		}
	}
}

int Input::getAxisPosition(int player, std::string button)
{
	if (player < connected_.size()) {
		std::string id = gamePadMap_[sf::Joystick::getIdentification(connected_[player]).name.toAnsiString()][button];
		if (id[0] == 'a')
		{
			sf::Joystick::Axis axis = static_cast<sf::Joystick::Axis>(id[1] - '0');
			//std::cout << sf::Joystick::hasAxis(connected_[player], axis) << std::endl;
			return sf::Joystick::getAxisPosition(connected_[player], axis);
		}
			
	}
	return false;
}

bool Input::isButtonPressed(int player, std::string button)
{
	if (player < connected_.size()) {
		std::string id = gamePadMap_[sf::Joystick::getIdentification(connected_[player]).name.toAnsiString()][button];

		if(id[0] == 'b')
			return sf::Joystick::isButtonPressed(connected_[player], id[1] - '0');
		else if (id[0] == 'a')
			return abs(sf::Joystick::getAxisPosition(connected_[player], static_cast<sf::Joystick::Axis>(id[1] - '0'))) == 100;
	}
	return false;
}

void Input::parseGamePadDB(std::string name)
{
	if (gamePadMap_.find(name) == gamePadMap_.end())
	{
		std::ifstream fichier("../../rc/gamepadDB.txt", std::ios::in);
		bool found = false;

		if (!fichier) {
			std::cerr << "rc/gamepadDB not found" << std::endl;
			return;
		}

		std::string ligne;
		while (std::getline(fichier, ligne))
		{
			if (ligne.find(name) != std::string::npos)
			{
				found = true;
				auto controls = Utils::split(ligne, ",");

				for (size_t i = 2; i < controls.size() - 2; i++)
				{
					auto elem = Utils::split(controls[i], ":");
					gamePadMap_[name][elem[0]] = elem[1];
					std::cout << name << " " << elem[0] << " " << gamePadMap_[name][elem[0]] << std::endl;
				}
			}
		}

		if (!found)
		{
			gamePadMap_[name]["a"] = "b0";
			gamePadMap_[name]["b"] = "b1";
			gamePadMap_[name]["x"] = "b2";
			gamePadMap_[name]["y"] = "b3";
			gamePadMap_[name]["leftshoulder"] = "b4";
			gamePadMap_[name]["rightshoulder"] = "b5";
			gamePadMap_[name]["back"] = "b6";
			gamePadMap_[name]["start"] = "b7";
			gamePadMap_[name]["leftstick"] = "b8";
			gamePadMap_[name]["rightstick"] = "b9";
			gamePadMap_[name]["leftx"] = "a0";
			gamePadMap_[name]["lefty"] = "a1";
			gamePadMap_[name]["lefttrigger"] = "a2";
			gamePadMap_[name]["righttrigger"] = "a3";
			gamePadMap_[name]["rightx"] = "a4";
			gamePadMap_[name]["righty"] = "a5";
		}

	}
		
}
