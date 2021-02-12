/**
 * Traffic Simulator 
 *
 * This is a simple traffic simulator mostly written in C++
 * using the SFML library. The main function is located here.
 *
 * Airleaf, 2021
 */
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>

/* This is the main window of the whole application, it has
 * been moved to a global scope variable so it can be accessed
 * anywhere. Just be aware that modifying this window should
 * happen on only one thread.
 */
static sf::RenderWindow win(sf::VideoMode(320, 180), "traffic-sim 0.1");

int main()
{
    
}