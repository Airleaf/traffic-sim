/**
 * Traffic Simulator 
 *
 * This is a simple traffic simulator mostly written in C++
 * using the SFML library. The main function is located here.
 *
 *
 * Airleaf, 2021
 */
#include "../include/Application.h"
#include "../include/Log.h"

/* Global log handle instance, should only be used on the main
 * thread as it's not thread-safe yet. This is intialized in 
 * the main function.
 */
static Log::Handle *g_log;

int main() 
{
    // Initialzation
    g_log = Log::init("main", "traffic.log");

    tlog(g_log, "Starting application...");
    Application app;

    tlog(g_log, "Running tilemap");
    app.RunTilemap();

    // ..

    tlog(g_log, "Closing app");
    // Deconstruction
    Log::close(g_log);

    return 0;
}
