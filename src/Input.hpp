#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <map>
#include <string>

#define JOYSTICK_LEFT_X sf::Joystick::Axis::X
#define JOYSTICK_LEFT_Y sf::Joystick::Axis::Y

class Input {
	private:
		std::vector<int> connected_;
		std::map<std::string, std::map<std::string, std::string>> gamePadMap_;

		Input();
	public:
		int waitForConnection();
		static Input &instance();
		int const getConnectedPlayer();
		static void tracePressedButton();
		static void traceJoystick();
		static void traceConnectedPlayer();
		int getAxisPosition(int player, std::string button);
		bool isButtonPressed(int player, std::string button);
		void parseGamePadDB(std::string name);
};


#endif // !INPUT_H
