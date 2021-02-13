//
// Created by Dogbone on 2/12/21.
//

#include "Application.h"


Application::Application() {
    
    mScreenResolution = sf::VideoMode::getDesktopMode();
    InitWindow();

}

Application::~Application() {

    delete this->pWindow;

}

void Application::InitWindow() {

    pWindow = new sf::RenderWindow(mScreenResolution, "Traffic Simulator", sf::Style::Default);

}


void Application::Render() {

    this->pWindow->clear();


    this->pWindow->display();

}

<<<<<<< HEAD
void Application::Update() {
=======
void Application::Render(const sf::Drawable& rObject) {
>>>>>>> origin/beta

    this->UpdateSfmlEvents();

}

void Application::UpdateSfmlEvents() {

    while(this->pWindow->pollEvent(mUserCloseEvent)){
        if(mUserCloseEvent.type == sf::Event::Closed)this->pWindow->close();
    }


}

void Application::Run() {

    while(this->pWindow->isOpen()) {
        this->Update();
        this->Render();
    }
}



