#include "Peon.h"
#include "Input.hpp"
#include "Utils.h"
#include "GlobalClock.hpp"

#include <utility>

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
		sf::Vector2f vn = Utils::normalize(v);


		float factor = std::max(abs(v.x), abs(v.y)) > 0.1 ? std::max(abs(v.x), abs(v.y)) / 100.f : 0;


		x_ += factor * speed_ * vn.x * GlobalClock::lapTime().asSeconds();
		y_ += factor * speed_ * vn.y * GlobalClock::lapTime().asSeconds();

		rect_.setPosition(x_, y_);
	}
}

void Peon::connectPlayer(int id)
{
	playerID_ = id;
}
