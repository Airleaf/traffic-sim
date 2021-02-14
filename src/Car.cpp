/**
 * Car class implementation
 *
 * Airleaf, 2021
 */
#include "../include/Car.h"

Log::Handle *Car::log = Log::init("car-ai", "car-ai.log");

/* Car constructor, takes the ID which should be unique for this 
 * particular car and shouldn't be found anywhere else.
 */
Car::Car(uint id)
{
    this->id = id;
    tlog(this->log, "Initialized car, id: %d", id);
}

/* Destructor. De-allocates all allocated memory and flushes any 
 * created buffers.
 */
Car::~Car()
{
    this->path.clear();
}

/* Refresh the current selected path with a new one found from the 
 * current tile. 
 */
void Car::PathFind(Tilemap &map)
{
    // TODO: PATH FINDING ALGORITHM
}

/* Return the Car ID. This is used for identifying a car instance
 * to later use it in the map.
 */
uint Car::GetID()
{
    return this->id;
}
