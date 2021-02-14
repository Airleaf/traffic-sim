//
// Created by caleb on 2/12/21.
//

#include "../include/Tilemap.h"

Tilemap::Tilemap()
{

    mIs_assigned_color = false;

    mCurrentRectangle.setSize(sf::Vector2f(30.f,30.f));
   //mCurrentRectangle.setFillColor(sf::Color(112, 163, 204, 255));

    if(!XRoad.loadFromFile("./other/assets/road_X.png"))exit(1);
    if(!YRoad.loadFromFile("./other/assets/road_Y.png"))exit(1);
    if(!URRoad.loadFromFile("./other/assets/road_UR.png"))exit(1);
    if(!ULRoad.loadFromFile("./other/assets/road_UL.png"))exit(1);
    if(!DLRoad.loadFromFile("./other/assets/road_DL.png"))exit(1);
    if(!DRRoad.loadFromFile("./other/assets/road_DR.png"))exit(1);


}

void Tilemap::SwitchRectType(int type)
{

    switch (type)
    {

        case STRAIGHT_X:
            mpRoadTexture = &XRoad;
            break;
        case STRAIGHT_Y:
            mpRoadTexture = &YRoad;
            break;
        case FIRST_CORNER:
            mpRoadTexture = &URRoad;
            break;
        case SECOND_CORNER:
            mpRoadTexture = &ULRoad;
            break;
        case THIRD_CORNER:
            mpRoadTexture = &DRRoad;
            break;
        case FOURTH_CORNER:
            mpRoadTexture = &DLRoad;
            break;
        default:
            break;
    }

}


void Tilemap::MoveCurrentRect(sf::RenderWindow& rEventHandler) {


    for (unsigned int y = 0.f; y < SCREEN_RESOLUTION.height; y += SCREEN_RESOLUTION.height / 36) {

        if (sf::Mouse::getPosition().y - 65 > y) {
            mCurrentRectangle.setPosition(mCurrentRectangle.getPosition().x, y);
        }

    }

    for (unsigned int x = 0.f; x < SCREEN_RESOLUTION.width; x += SCREEN_RESOLUTION.height / 36) {

        if (sf::Mouse::getPosition().x > x) {
            mCurrentRectangle.setPosition(x, mCurrentRectangle.getPosition().y);
        }

    }

    ManageEvents(rEventHandler);
    }



void Tilemap::DrawAll(sf::RenderWindow &rWindow)
{
    rWindow.clear(sf::Color::Green);
    for(sf::RectangleShape& rRect : tilemap)rWindow.draw(rRect);
    rWindow.draw(mCurrentRectangle);
    rWindow.display();
}

void Tilemap::PushRectToVector(const sf::RectangleShape &rect)
{

    if(mIs_assigned_color)
    {
        tilemap.push_back(rect);
        types.push_back(mType);
    }

}

void Tilemap::Undo()
{

    if(!tilemap.empty())
    {
        tilemap.pop_back();
        types.pop_back();
    }

}

void Tilemap::Clear()
{
    tilemap.clear();
    types.clear();
}


void Tilemap::SaveMap()
{

    if(!tilemap.empty())
    {
        std::ofstream output("./other/Tilemap.rmp");
        if(!output.is_open()){
            std::cout<<"Failed to open map file!";
            exit(1);
        }
        for (int i = 0; i < tilemap.size(); i++) {
            output << tilemap[i].getPosition().x << ' ' << tilemap[i].getPosition().y << ' ' << types[i] << std::endl;

        }
    }


}

void Tilemap::LoadMap()
{

    std::ifstream input("./other/Tilemap.rmp");
    if(!input.is_open()){
        std::cout<<"Failed to open map file!";
        exit(1);
    }
    std::string line;
    float x, y;
    int type;
    sf::RectangleShape rect;

    while(input >> x >> y >> type)
    {
        rect.setSize(sf::Vector2f(30,30));
        rect.setPosition(x, y);
        SwitchRectType(type);
        rect.setTexture(mpRoadTexture);
        tilemap.push_back(rect);
        types.push_back(type);
    }

    for(sf::RectangleShape i: tilemap)
    {
        std::cout<<i.getPosition().x << "  " << i.getPosition().y << std::endl;
    }
    input.close();
}

void Tilemap::ManageEvents(sf::RenderWindow& rEventHandler) {

    while (rEventHandler.pollEvent(mMouseEvent)) {

        switch (mMouseEvent.type) {

            case sf::Event::KeyPressed:

                if (mMouseEvent.key.code == sf::Keyboard::C)
                    Clear();
                break;

            case sf::Event::Closed:
                exit(0);
                break;

            case sf::Event::MouseButtonPressed:
                if (mMouseEvent.mouseButton.button == sf::Mouse::Left) {
                    PushRectToVector(mCurrentRectangle);
                }

                if (mMouseEvent.mouseButton.button == sf::Mouse::Right) {
                    Undo();
                }
                break;

            case sf::Event::TextEntered:

                mType = (int) static_cast<char>(mMouseEvent.text.unicode) - 48;
                SwitchRectType(mType);
                mCurrentRectangle.setTexture(mpRoadTexture);
                mIs_assigned_color = true;
                break;


        }
    }

}



