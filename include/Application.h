//
// Created by Dogbone on 2/12/21.
//

#ifndef TRAFFIC_APPLICATION_H
#define TRAFFIC_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>

class Application {


    public:

        Application();
        ~Application();

        void Run();

        const sf::VideoMode &getScreenResolution() const;


private:

        void SfmlEvents();

        sf::RenderWindow *pWindow;
        sf::VideoMode mScreenResolution;

        sf::Event mUserCloseEvent;
};


#endif //TRAFFIC_APPLICATION_H
