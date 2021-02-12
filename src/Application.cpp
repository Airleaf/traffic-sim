//
// Created by Dogbone on 2/12/21.
//

#include "Application.h"


//Global app class instance
Application app;


Application::Application() {
    
    mScreenResolution = sf::VideoMode::getDesktopMode();
    pWindow = new sf::RenderWindow(mScreenResolution, "Traffic Simulator", sf::Style::Default);

}

Application::~Application() {

    delete this->pWindow;

}

void Application::Run() {

    while(this->pWindow->isOpen()){

        SfmlEvents();
        this->pWindow->clear();




        this->pWindow->display();

    }


}

void Application::Render(const sf::Drawable& rObject) {

    this->pWindow->draw(object);

}




void Application::SfmlEvents() {

    while (this->pWindow->pollEvent(mUserCloseEvent)){
        if(mUserCloseEvent.type == sf::Event::Closed)this->pWindow->close();
    }



}

const sf::VideoMode &Application::getScreenResolution() const {
    return mScreenResolution;
}

