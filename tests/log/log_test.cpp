/* This is the test for the log module.
 *
 */
#include "../../include/Log.h"

int main()
{
    Log::Handle *lh = Log::init("test", "log_test.log");
    tlog(lh, "info fourteen = %d", 14);
    twarn(lh, "warn string = %s", "string");
    terr(lh, "error two point three = %f", 2.3f);
    return 0;
}