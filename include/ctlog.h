/**
 * traffic-sim logging system, with a backend written in C
 * with C++ wrappers.
 *
 * bellrise
 */
#ifndef T_LOG_H_
#define T_LOG_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/* Size of the message buffer. This is the amount of messages
 * that will be collected in the buffer before sending them 
 * to a file.
 */
#ifndef T_LOG_BUFSIZE
# define T_LOG_BUFSIZE 50
#endif

/* This is the tlog macro used as a wrapper for the t_log_push
 * function. This is turned into a macro in order to automatically
 * pass the __FILE__ and __LINE__ macros.
 */
#define tlog(LH, ...) t_log_push(LH, TLog_Info, __FILE__, __LINE__, \
        __VA_ARGS__)

/* terr macro, which is the same as the normal tlog but sets
 * the message type to error.
 */
#define terr(LH, ...) t_log_push(LH, TLog_Error, __FILE__, __LINE__, \
        __VA_ARGS__)

typedef enum
{
    TLog_Info,      // white
    TLog_Error,     // red
    TLog_Warn,      // yellow
    TLog_Ok         // green

} TLog_Type;

/* The log handle structure. Stores the file pointer and buffer,
 * along with additional information about the file option, 
 * size of filled buffer, and a thread lock. Actually using the
 * thread lock is a bad idea, as each thread should have its 
 * own log handle. 
 * Important: each log handle _MUST_ be initialized with the 
 * t_log_init function to set the base parameters and to allocate
 * enough memory.
 */
typedef struct 
{
    char prefix[5]; // 5 letter prefix
    char** mbuf;    // message buffer
    FILE* fp;       // file pointer
    uint tlock;     // thread lock                   
    uint bsize;     // buffer size
    char wf;        // with file option

} TLogHandle;

/* This is the initializer for a single log handle. Writes
 * the logs to the chosen file. Select an empty or invalid
 * filename to turn off the file option.
 */
extern TLogHandle *t_log_init(const char prefix[], const char* filename);

/* Close the log handle flushing the remaining messages in the
 * buffer, free-ing all allocated memory and closing the file 
 * pointer. Be sure to call this at the end! 
 */
extern void t_log_close(TLogHandle* lh);

/* Push a message to the given log handle. Uses the printf 
 * message formatting style, meaning you can pass a format 
 * string and any amount of arguments. Using this is done by
 * a macro inserting the __FILE__ and __LINE__ macros for
 * better logging.
 */
extern void t_log_push(TLogHandle* lh, TLog_Type type, const char* file, 
            long line, const char* fmt, ...);

/* Check the state of the buffer of the log handle, flush 
 * all messages to the file if it reaches T_LOG_BUFSIZE.
 */
static void t_log_check(TLogHandle* lh);

/* Flush all messages in the buffer to the opened file. The
 * buffer checks are done in t_log_check, not here. 
 */
static void t_log_flush(TLogHandle* lh);

/* Get status type from the TLog_Type.
 */
static char t_log_get_type(TLog_Type type);

/* Print the message to stdout using the specified colour
 * passed as the tlog type.
 */
static void t_log_printclr(TLog_Type type, char* msg);

#endif // T_LOG_H_