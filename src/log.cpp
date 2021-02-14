/**
 * C++ wrapper implementation
 */
#include "../include/log.h"

/* This is the initializer for a single log handle. Writes
 * the logs to the chosen file.
 */
Log::Handle *Log::init(std::string prefix, std::string outfile)
{ return t_log_init(prefix.c_str(), outfile.c_str()); }

/* This is the initializer for a single log handle. This
 * version does not write anything to the outfile.
 */
Log::Handle *Log::init(std::string prefix)
{ return t_log_init(prefix.c_str(), ""); }

/* Close the log handle flushing the remaining messages in the
 * buffer, free-ing all allocated memory and closing the file 
 * pointer. Be sure to call this at the end! 
 */
void Log::close(Log::Handle* lh)
{ t_log_close(lh); }
