//
// Created by Dogbone on 2/12/21.

//The basic application class that will power the program

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
        void Render();
        void Update();
        void UpdateSfmlEvents();
        void Render(const sf::Drawable& rObject);




private:

        void InitWindow();
        sf::RenderWindow *pWindow;
        sf::VideoMode mScreenResolution;
        sf::Event mUserCloseEvent;


};


#endif //TRAFFIC_APPLICATION_H
