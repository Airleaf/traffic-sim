/* C++ traffic-sim logger namespace, which wraps around the C  
 * functions in t_log.h. You can use this to get a C++ interface,
 * but it works just as well as the C interface.
 */
#ifndef LOG_H
#define LOG_H

#include <string>

extern "C" {
#include "ctlog.h"
}

namespace Log
{
    /* The log handle structure. Check TLogHandle for better
     * documentation on this structure.
     */
    typedef TLogHandle Handle;

    /* This is the initializer for a single log handle. Writes
     * the logs to the chosen file.
     */
    Handle *init(std::string prefix, std::string outfile);

    /* This is the initializer for a single log handle. This
     * version does not write anything to the outfile.
     */
    Handle *init(std::string prefix);

    /* Close the log handle flushing the remaining messages in the
     * buffer, free-ing all allocated memory and closing the file 
     * pointer. Be sure to call this at the end! 
     */
    void close(Handle* lh);

}

#endif // LOG_H