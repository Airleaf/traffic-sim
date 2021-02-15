//
// Created by Dogbone on 2/12/21.

//The basic application class that will power the program

//

#ifndef TRAFFIC_APPLICATION_H
#define TRAFFIC_APPLICATION_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Tilemap.h"
#include "Log.h"


class Application {

public:

        Application();
        ~Application();

        void Run();
        void Render();
        void Update();
        void UpdateSfmlEvents();
        void RunTilemap();
        static void Exit();


private:

        void InitWindow();
        sf::RenderWindow *pWindow;
        sf::VideoMode mScreenResolution;
        sf::Event mUserCloseEvent;

        Tilemap mTilemap;

        static Log::Handle *log;
};


#endif //TRAFFIC_APPLICATION_H
