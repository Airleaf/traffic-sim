/**
 * traffic-sim logging system source
 *
 * bellrsie
 */
#include "../include/ctlog.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <time.h>

/* This is the initializer for a single log handle. Writes
 * the logs to the chosen file. Select an empty or invalid
 * filename to turn off the file option.
 */
TLogHandle *t_log_init(const char prefix[], const char* filename)
{
    TLogHandle *lh = (TLogHandle*) malloc(sizeof(TLogHandle));

    if (strlen(prefix) > 6)
    {
        printf("Log prefix is too long. (max 6 chars)\n");
        exit(1);
    }
    strncpy(lh->prefix, prefix, 7);

    lh->mbuf = (char**) malloc(sizeof(char*) * T_LOG_BUFSIZE);
    for (int i = 0; i < T_LOG_BUFSIZE; i++) 
    {
        lh->mbuf[i] = (char*) malloc(sizeof(char) * 255);
    }
    // Open file
    if (strcmp(filename, "") != 0)
    {
        lh->fp = fopen(filename, "w");
        if (!lh->fp) 
        {   
            printf("Cannot open log file. Closing program.\n");
            exit(1);
        }
        lh->wf = 1;
    }
    else
        lh->wf = 0;
    lh->bsize = 0;
    lh->tlock = 0;
    return lh;
}

/* Close the log handle flushing the remaining messages in the
 * buffer, free-ing all allocated memory and closing the file 
 * pointer. Be sure to call this at the end! 
 */
void t_log_close(TLogHandle* lh)
{
    if (lh->wf == 1)
    {
        t_log_flush(lh);
        fclose(lh->fp);
    }

    free(lh->mbuf);
    
    lh->tlock = 0;
    lh->bsize = 0;
    lh->wf = 0;
}

/* Push a message to the given log handle. Uses the printf 
 * message formatting style, meaning you can pass a format 
 * string and any amount of arguments.
 */
void t_log_push(TLogHandle *lh, TLog_Type type, const char *file, 
     long line, const char *fmt, ...)
{
    va_list _args;
    va_start(_args, fmt);

    time_t time_ = time(NULL);
    struct tm t = *localtime(&time_);
    
    // Collect to buffer
    char* cst = (char*) calloc(sizeof(char), 233);
    vsnprintf(cst, 233, fmt, _args);

    char* msg = (char*) calloc(sizeof(char), 255);
    snprintf(msg, 255, "%02d:%02d:%02d %c [ %6s ] %s", t.tm_hour, t.tm_min, 
        t.tm_sec, t_log_get_type(type), lh->prefix, cst);

    if (lh->wf == 1)
    {
        lh->mbuf[lh->bsize] = msg;
        lh->bsize++;
    }
    
    t_log_printclr(type, msg);
    t_log_check(lh);

    va_end(_args);
}

/* Print the given message to standard out without using the log
 * handle buffers. Prints the file and line number where the exception
 * happened, making debugging a lot easier. After that it calls 
 * t_log_close on the handle and exits the program with 1.
 */
void t_log_except(TLogHandle* lh, const char* file, long line,
     const char* fmt, ...)
{
    va_list _args;
    va_start(_args, fmt);

    char with_file[4] = "no\0\0";
    if (lh->wf)
        strncpy(with_file, "yes\0", 4);

    // Formatting
    printf("\033[31m\nAn exception occured in '%s' on line %ld:\n", 
           file, line);
    printf("   logdump of: [ %6s ] wf: %s | buf: %d | tlock: %d\n\n ~ ", 
           lh->prefix, with_file, lh->bsize, lh->tlock);
    
    vprintf(fmt, _args);

    printf("\033[0m\n\n");
    t_log_close(lh);
    va_end(_args);
}

/* Check the state of the buffer of the log handle, flush 
 * all messages to the file if it reaches T_LOG_BUFSIZE.
 */
void t_log_check(TLogHandle* lh)
{
    if (lh->wf == 0)
        return;
    
    if (lh->bsize == T_LOG_BUFSIZE)
        t_log_flush(lh);
}

/* Flush all messages in the buffer to the opened file. The
 * buffer checks are done in t_log_check, not here. 
 */
void t_log_flush(TLogHandle* lh)
{
    for (int i = 0; i < lh->bsize; i++)
    {
        fprintf(lh->fp, "%s\n", lh->mbuf[i]);
    }
    lh->mbuf = 0;
}

/* Get status type from the TLog_Type.
 */
static char t_log_get_type(TLog_Type type)
{
    switch (type) {
        case TLog_Info:  return 'I';
        case TLog_Error: return 'E';
        case TLog_Warn:  return 'W';
    }
    return '-';
}

/* Print the message to stdout using the specified colour
 * passed as a single char.
 */
static void t_log_printclr(TLog_Type type, char* msg)
{
    switch (type) {
        case TLog_Info:  printf("\033[0m");  break;
        case TLog_Error: printf("\033[31m"); break;
        case TLog_Warn:  printf("\033[93m"); break;
    }

    printf("%s\033[0m\n", msg);
}
