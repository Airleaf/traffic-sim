/**
 * The car class
 *
 * Airleaf, 2021
 */
#ifndef TRAFFIC_CAR_H
#define TRAFFIC_CAR_H

#include "Tilemap.h"
#include "Log.h"
#include <SFML/System/Vector2.hpp>
#include <vector>

/* This class represents a single car that has its own intelligence 
 * in order to pick the best path to move.
 * 
 * People who worked on this:
 *  bellrise
 */
class Car
{
public:

    /* Car constructor, takes the ID which should be unique for this 
     * particular car and shouldn't be found anywhere else.
     */
    Car(uint id);

    /* Destructor. De-allocates all allocated memory and flushes any 
     * created buffers.
     */
    ~Car();

    /* Refresh the current selected path with a new one found from the 
     * current tile. 
     */
    void PathFind(Tilemap &map);

    /* Return the Car ID. This is used for identifying a car instance
     * to later use it in the map.
     */
    uint GetID();

private:

    uint id;
    bool hasPath = false;
    std::vector<sf::Vector2<int>> path;

    // Log handle for all car instances
    static Log::Handle *log;

};


#endif // TRAFFIC_CAR_H