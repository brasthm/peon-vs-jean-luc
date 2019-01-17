#ifndef INPUT_H
#define INPUT_H

#include <SFML/Graphics.hpp>
#include <vector>

class Input {
	private:
		std::vector<int> connected_;
	public:
		Input();
		void waitForConnection();
		static Input &instance();
		int const getConnectedPlayer();
		static void tracePressedButton();
};

static Input inputInstance;

#endif // !INPUT_H
