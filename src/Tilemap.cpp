//
// Created by caleb on 2/12/21.
//

#include "Tilemap.h"

Tilemap::Tilemap() {

    is_assigned_color = false;

    mCurrentRectangle.setSize(sf::Vector2f(30.f,30.f));
    mCurrentRectangle.setFillColor(sf::Color(112, 163, 204, 200));

}

void Tilemap::SwitchRectType(int type) {

    switch (type){

        case STRAIGHT_X:
            mRoadColor = sf::Color::Red;
            break;
        case STRAIGHT_Y:
            mRoadColor = sf::Color::Blue;
            break;
        case FIRST_CORNER:
            mRoadColor = sf::Color::White;
            break;
        case SECOND_CORNER:
            mRoadColor = sf::Color::Yellow;
            break;
        case THIRD_CORNER:
            mRoadColor = sf::Color::Green;
            break;
        case FOURTH_CORNER:
            mRoadColor = sf::Color::Cyan;
            break;
        default:
            break;
    }

}




void Tilemap::MoveCurrentRect(sf::RenderWindow& rEventHandler) {


    for(unsigned int y = 0.f; y < SCREEN_RESOLUTION.height; y += SCREEN_RESOLUTION.height/36){

        if(sf::Mouse::getPosition().y - 65 > y) {
            mCurrentRectangle.setPosition(mCurrentRectangle.getPosition().x, y);

        }

    }

    for(unsigned int x = 0.f; x < SCREEN_RESOLUTION.width; x += SCREEN_RESOLUTION.height/36){

        if(sf::Mouse::getPosition().x > x) {
            mCurrentRectangle.setPosition(x, mCurrentRectangle.getPosition().y);
        }

    }

    while(rEventHandler.pollEvent(mMouseEvent)){

        if(mMouseEvent.type == sf::Event::MouseButtonPressed && mMouseEvent.mouseButton.button == sf::Mouse::Left)
        {
            PushRectToVector(mCurrentRectangle);
        }

        else if(mMouseEvent.type == sf::Event::MouseButtonPressed && mMouseEvent.mouseButton.button == sf::Mouse::Right)
        {
            Undo();
        }

        else if(mMouseEvent.type == sf::Event::TextEntered){
            mType = (int)static_cast<char>(mMouseEvent.text.unicode) - 48;
            SwitchRectType(mType);
            sf::Color newColor = mRoadColor;
            newColor.a = 150;
            mCurrentRectangle.setFillColor(newColor);
            is_assigned_color = true;
        }

        else if(mMouseEvent.type == sf::Event::KeyPressed && mMouseEvent.key.code == sf::Keyboard::C)
        {
            Clear();
        }

        else if(mMouseEvent.type == sf::Event::Closed)exit(0);
    }


}

void Tilemap::DrawAll(sf::RenderWindow &rWindow) {

    rWindow.clear();
    for(sf::RectangleShape& rRect : tilemap)rWindow.draw(rRect);
    rWindow.draw(mCurrentRectangle);
    rWindow.display();
}

void Tilemap::PushRectToVector(sf::RectangleShape rect) {

    if(is_assigned_color) {
        rect.setFillColor(mRoadColor);
        tilemap.push_back(rect);
        types.push_back(mType);
    }

}

void Tilemap::Undo() {

    if(!tilemap.empty())
    {
        tilemap.pop_back();
    }

}

void Tilemap::Clear() {

    mCurrentRectangle.setFillColor(sf::Color(112, 163, 204, 200));
    tilemap.clear();
    types.clear();
}


void Tilemap::SaveMap() {

    if(!tilemap.empty()) {
        std::ofstream output("../other/Tilemap.rmp");
        for (int i = 0; i < tilemap.size(); i++) {
            output << tilemap[i].getPosition().x << ' ' << tilemap[i].getPosition().y << ' ' << types[i] << std::endl;

        }
    }


}

void Tilemap::LoadMap() {

    std::ifstream input("../other/Tilemap.rmp");
    std::string line;
    float x, y;
    int type;
    sf::RectangleShape rect;

    while(input >> x >> y >> type) {
        rect.setSize(sf::Vector2f(30,30));
        rect.setPosition(x, y);
        SwitchRectType(type);
        rect.setFillColor(mRoadColor);
        tilemap.push_back(rect);
        types.push_back(type);
    }

    for(sf::RectangleShape i: tilemap){
        std::cout<<i.getPosition().x << "  " << i.getPosition().y << std::endl;
    }
    input.close();
}



