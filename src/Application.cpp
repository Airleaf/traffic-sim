//
// Created by Dogbone on 2/12/21.
//

#include "../include/Application.h"
#include "../include/Log.h"

// Initialze static logger for app class
Log::Handle *Application::log = Log::init("app", "app.log");

Application::Application() 
{
    mScreenResolution = sf::VideoMode::getDesktopMode();
    InitWindow();
}

Application::~Application() 
{
    delete this->pWindow;
}

void Application::InitWindow() 
{
    pWindow = new sf::RenderWindow(mScreenResolution, "Traffic Simulator", sf::Style::Default);
}


void Application::Render() 
{
    this->pWindow->clear();
    this->pWindow->display();
}

void Application::Update() 
{
    this->UpdateSfmlEvents();
}

void Application::UpdateSfmlEvents() 
{
    while (this->pWindow->pollEvent(mUserCloseEvent)) 
    {
        if (mUserCloseEvent.type == sf::Event::Closed) 
        {
            this->Exit();
        }
    }
}

void Application::Run() 
{
    while (this->pWindow->isOpen()) 
    {
        this->Update();
        this->Render();
    }
}

void Application::RunTilemap() 
{
    mTilemap.LoadMap();

    while (!sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) 
    {
        mTilemap.MoveCurrentRect(*pWindow);
        mTilemap.DrawAll(*pWindow);
    }

    mTilemap.SaveMap();
    Run();
}

void Application::Exit()
{
    tlog(this->log, "Exiting window");
    
    // Deconstruct objects
    Log::close(this->log);

    this->pWindow->close();
    exit(0);
}