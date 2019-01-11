#ifndef GLOBALCLOCK_HPP
#define GLOBALCLOCK_HPP

#include <SFML/System/Clock.hpp>
#include <functional>
#include <vector>


class GlobalClock
{
    public:
        GlobalClock() = default;
        sf::Time restart() noexcept;
        sf::Time frameTime() const noexcept;
        void stop() noexcept;
        void start() noexcept;
        void changeSpeed(double speed) noexcept;
        sf::Time timeSinceStartup() const noexcept;
        
        void executeIn(sf::Time delay, std::function<void()> fun);
        
        static GlobalClock& getClock();
        

    private:
        sf::Clock clock;
        sf::Time frame = sf::Time::Zero;
        sf::Time global = sf::Time::Zero;
        double factor = 1;
        bool running = true;
        std::vector<std::pair<sf::Time, std::function<void()>>> callbacks;
};

static GlobalClock instance;

#endif // GLOBALCLOCK_HPP