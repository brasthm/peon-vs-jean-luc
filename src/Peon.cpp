#include "Peon.h"
#include "Input.hpp"
#include "Utils.h"
#include "GlobalClock.hpp"

Peon::Peon()
{
	speed_ = 200;
	rect_.setSize({ 50, 50 });
	x_ = 0; y_ = 0;
	playerID_ = -1;
}

void Peon::draw(sf::RenderWindow & window)
{
	if (playerID_ != -1)
		window.draw(rect_);
}

void Peon::update()
{
	if (playerID_ != -1)
	{
		sf::Vector2f v;
		v.x = Input::instance().getAxisPosition(playerID_, "leftx");
		v.y = Input::instance().getAxisPosition(playerID_, "lefty");
		v = Utils::normalize(v);

		x_ += speed_ * v.x * GlobalClock::lapTime().asSeconds();
		y_ += speed_ * v.y * GlobalClock::lapTime().asSeconds();

		rect_.setPosition(x_, y_);
	}
}

void Peon::connectPlayer(int id)
{
	playerID_ = id;
}
