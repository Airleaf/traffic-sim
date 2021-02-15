//
// Created by caleb on 2/14/21.
//

#ifndef TRAFFIC_TILE_H
#define TRAFFIC_TILE_H
#include <SFML/Graphics.hpp>

class Tile: public sf::RectangleShape {

public:
    int getType();
    void setType(int type);

private:

    int mType = 0;

};


#endif //TRAFFIC_TILE_H
