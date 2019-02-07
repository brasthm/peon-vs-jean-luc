#ifndef PEON_H
#define PEON_H

#include <SFML/Graphics.hpp>

class Peon
{
	private:
		sf::RectangleShape rect_;
		float x_, y_;
		float speed_;
		int playerID_;
	public:
		Peon();
		void draw(sf::RenderWindow &window);
		void update();
		void connectPlayer(int id);
};


#endif