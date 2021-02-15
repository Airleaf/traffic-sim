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
 
    tlog(lh, "sizeof(char**) = %ld", sizeof(char**));
    tlog(lh, "sizeof(TLogHandle) = %ld", sizeof(TLogHandle));
    tlog(lh, "sizeof(uint) = %ld", sizeof(uint));
    tlog(lh, "sizeof(FILE*) = %ld", sizeof(FILE*));

    texcept(lh, "Something went wrong");

    Log::close(lh);
    return 0;
}
