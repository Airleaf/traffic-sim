//
// Created by caleb on 2/12/21.
//

/*
    This is just a basic tilemap editor that we will use to create the roads of the program.
    It simply pushes rectangles to a vector and saves the attributes of position and type
    to a file that is loaded upon program execution. The colors can be switched through keys 1-6 and
    the entire map can be cleared with the 'C' key. The enter key saves the data and continues the execution
    of the program.
 */


#ifndef TRAFFIC_TILEMAP_H
#define TRAFFIC_TILEMAP_H
#include <vector>
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <SFML/Graphics.hpp>

class Tilemap {


    public:
    const sf::VideoMode SCREEN_RESOLUTION = sf::VideoMode::getDesktopMode();



    Tilemap();

    void MoveCurrentRect(sf::RenderWindow& rEventHandler);
    void DrawAll(sf::RenderWindow& rWindow);
    void SaveMap();
    void LoadMap();

    std::vector<sf::RectangleShape> tilemap;
    std::vector<int> types;

    private:

    sf::Event mMouseEvent;
    void SwitchRectType(int type);
    void PushRectToVector(sf::RectangleShape rect);
    void Undo();
    void Clear();
    sf::RectangleShape mCurrentRectangle;
    sf::Color mRoadColor;
    int mType;
    bool mIs_assigned_color;

    enum types{
        STRAIGHT_X = 1,
        STRAIGHT_Y,
        FIRST_CORNER,
        SECOND_CORNER,
        THIRD_CORNER,
        FOURTH_CORNER
    };




};


#endif //TRAFFIC_TILEMAP_H
