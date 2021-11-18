
/**
    \copyright MIT License Copyright (c) 2021, Adewale Azeez 
    \author Adewale Azeez <iamthecarisma@gmail.com>
    \date 18 Nov 2021
    \file logax.h
*/

#ifndef EXOTIC_LOGAX_H
#define EXOTIC_LOGAX_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

#ifndef LOGAX_NO_TIME
#include <time.h>
#endif

/** 
    The inline keyword to optimize the function. In 
    C89 and C90 the inline keyword semantic is 
    different from current C standard semantic hence 
    for compilation targeting C89 or C99 the inline 
    keyword is ommited.
*/
#ifdef __STDC_VERSION__
    #define __LOGAX_STDC_VERSION__ __STDC_VERSION__
#else
    #ifdef __cplusplus
        #if __cplusplus > 199711L
            #define __LOGAX_STDC_VERSION__ __cplusplus
        #endif
    #endif
#endif
#ifndef __LOGAX_STDC_VERSION__
    #ifdef __FUNCTION__ 
        #define __LOGAX_FUNCTION__ __FUNCTION__
    #else
        #define __LOGAX_FUNCTION__ "<unknown>"
    #endif
    #define CESTER_NULL 0L
#else 
    #define __LOGAX_FUNCTION__ __func__
    #define CESTER_NULL NULL
#endif

#if defined(_WIN32) && defined(LOGAX_USE_OLD_CONSOLE_MODE)

#define LOGAX_RESET_TERMINAL           15                                                /**< reset the terminal color //Nothing     */
#define LOGAX_FOREGROUND_TRACE         11                                                /**< trace terminal foreground color - cyan     */
#define LOGAX_FOREGROUND_DEBUG         2                                                 /**< debug terminal foreground color - green    */
#define LOGAX_FOREGROUND_INFO          5                                                 /**< info terminal foreground color - magenta   */
#define LOGAX_FOREGROUND_WARN          6                                                 /**< warn terminal foreground color - yellow    */
#define LOGAX_FOREGROUND_ERROR         4                                                 /**< error terminal foreground color - red      */
#define LOGAX_FOREGROUND_FATAL         4                                                 /**< fatal terminal foreground color - red      */
#define LOGAX_RESET_TERMINAL_ATTR()    SetConsoleTextAttribute(hConsole, default_color); /**< reset the terminal color                   */

#else

#define LOGAX_RESET_TERMINAL           "\x1B[0m"                                         /**< reset the terminal color                   */
#define LOGAX_FOREGROUND_TRACE         "\x1B[36m"                                        /**< trace terminal foreground color - cyan     */
#define LOGAX_FOREGROUND_DEBUG         "\x1B[32m"                                        /**< debug terminal foreground color - green    */
#define LOGAX_FOREGROUND_INFO          "\x1B[35m"                                        /**< info terminal foreground color - magenta   */
#define LOGAX_FOREGROUND_WARN          "\x1B[33m"                                        /**< warn terminal foreground color - yellow    */
#define LOGAX_FOREGROUND_ERROR         "\x1B[31m"                                        /**< error terminal foreground color - red      */
#define LOGAX_FOREGROUND_FATAL         "\x1B[31m"                                        /**< fatal terminal foreground color - red      */
#define LOGAX_RESET_TERMINAL_ATTR()                                                      /**< reset the terminal color                   */

#endif

#ifndef LOGAX_NO_CALLBACK
/**
    
*/
#define LOGAX_MAX_CALLBACKS 20

/*
    
*/
typedef void (*logax_callback)(int level, const char *file_path, size_t line, const char *data);
#endif

/**
    
*/
enum LogaxOption
{
    LOGAX_OPTION_QUITE           = 1 << 1, /**<  binary 0010 */
#ifndef LOGAX_NO_TIME
    LOGAX_OPTION_DATE            = 1 << 2, /**<  binary 0100 */
    LOGAX_OPTION_TIME            = 1 << 3, /**<  binary 1000 */
    LOGAX_OPTION_DATE_TIME       = 1 << 4,
#endif
    LOGAX_OPTION_FILE_PATH       = 1 << 5,
    LOGAX_OPTION_FILE_NAME_ONLY  = 1 << 6,
    LOGAX_OPTION_LINE_NUMBER     = 1 << 7,
    LOGAX_OPTION_COLORED         = 1 << 8,
    LOGAX_OPTION_FUNCTION        = 1 << 9
};

/**
    
*/
enum LogaxLevel
{
    LOGAX_LEVEL_TRACE   = 1 << 10, /**<  ? */
    LOGAX_LEVEL_DEBUG   = 1 << 11, /**<  ? */
    LOGAX_LEVEL_INFO    = 1 << 12, /**<  ? */
    LOGAX_LEVEL_WARN    = 1 << 13,
    LOGAX_LEVEL_ERROR   = 1 << 14,
    LOGAX_LEVEL_FATAL   = 1 << 15
};

/**
    
*/
enum LogaxFormatter
{
    LOGAX_FORMATTER_PLAIN_TEXT   = 1 << 20, /**<  ? */
    LOGAX_FORMATTER_TEXT         = 1 << 21, /**<  ? */
    LOGAX_FORMATTER_JSON         = 1 << 23 /**<  ? */
};

/**
    
*/
struct logax_logger_s {
    int level;                  /**<  ? */
    int options;                /**<  ? */// use bitwize for options like quiet, time, long date, shortdate, e.t.c
    int formatter;              /**<  ? */// external formatter should begin from 100
#if !defined(LOGAX_NO_OUTPUT_STREAM)
    FILE *output_stream;        /**<  ? */
#endif
#ifndef LOGAX_NO_CALLBACK
    logax_callback callbacks[LOGAX_MAX_CALLBACKS];
#endif
#ifndef LOGAX_FUNCTIONAL_LOGGING_ONLY
    void  (*write) (const char *fmt, ...);
    void  (*trace) (const char *fmt, ...);
    void  (*debug) (const char *fmt, ...);
    void  (*info)  (const char *fmt, ...);
    void  (*warn)  (const char *fmt, ...);
    void  (*error) (const char *fmt, ...);
    void  (*fatal) (const char *fmt, ...);
#endif
};

/**

*/
typedef struct logax_logger_s LogaxLogger;

/**

*/
static void logax_init_logger(LogaxLogger *logax_logger) {
    logax_logger->level = 0;
    logax_logger->options = 0;
    logax_logger->formatter = LOGAX_FORMATTER_PLAIN_TEXT;
#if defined(stdout) && !defined(LOGAX_NO_OUTPUT_STREAM)
    logax_logger->output_stream = stdout;
#endif
}

#if !defined(LOGAX_NO_OUTPUT_STREAM)
/**

*/
static void logax_init_logger_ws(LogaxLogger *logax_logger, FILE *output_stream) {
    logax_logger->level = 0;
    logax_logger->options = 0;
    logax_logger->formatter = LOGAX_FORMATTER_PLAIN_TEXT;
    logax_logger->output_stream = output_stream;
}
#endif

/*

*/
static size_t logax_cstr_length(char char_array[]) {
    size_t length = 0;
    if (char_array == NULL) { return length; }
    while(char_array[length] != '\0') {
        length++;
    }
    return length;
}

/**

*/
static void logax_extract_name_only(char const* const file_path, char file_name_only[]) {
    unsigned i = 0, j = -1;
	while (file_path[i] != '\0') {
        if (file_path[i] == '\\' || file_path[i] == '/') {
            j = 0;
        } else if (j != -1) {
            file_name_only[j] = file_path[i];
            j++;
        }
        ++i;
    }
	file_name_only[j] = '\0';
}

#if defined(_WIN32) && defined(LOGAX_USE_OLD_CONSOLE_MODE)
/**

*/
#define LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(options)
#else
/**

*/
#define LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(prefix_spaces, level) if (is_colored) fprintf(stream, "%s%s%s", prefix_spaces, LOGAX_FOREGROUND_##level, #level);\
	else fprintf(stream, "%s%s", prefix_spaces, #level);
#endif

/**

*/
static void logax_write_plaintext_format_to_stream__internal__(FILE *stream, int options, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, ...) {
	va_list va_arg;
	if (options & LOGAX_OPTION_QUITE) return;
	unsigned is_colored = (options & LOGAX_OPTION_COLORED);
    /* date and time */
#ifndef LOGAX_NO_TIME
	time_t current_time = time(NULL);
	current_time = localtime(&current_time);
    if ((options & LOGAX_OPTION_DATE_TIME) || (options & LOGAX_OPTION_DATE)) {
		char date_buffer[16];
  		date_buffer[strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", current_time)] = '\0';
        fprintf(stream, "%s", date_buffer);
    }
    if ((options & LOGAX_OPTION_DATE_TIME) || (options & LOGAX_OPTION_TIME)) {
		char time_buffer[16];
  		time_buffer[strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time)] = '\0';
		if ((options & LOGAX_OPTION_DATE_TIME) || (options & LOGAX_OPTION_DATE)) {
			fprintf(stream, " ");
		}
        fprintf(stream, "%s", time_buffer);
    }
#endif
    /* logging level */
    if (options & LOGAX_LEVEL_TRACE) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", TRACE);
    } else if (options & LOGAX_LEVEL_DEBUG) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", DEBUG);
    } else if (options & LOGAX_LEVEL_INFO) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__("  ", INFO);
    } else if (options & LOGAX_LEVEL_WARN) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__("  ", WARN);
    } else if (options & LOGAX_LEVEL_ERROR) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", ERROR);
    } else if (options & LOGAX_LEVEL_FATAL) {
		LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", FATAL);
    }
	if (is_colored) fprintf(stream, "%s", LOGAX_RESET_TERMINAL);
    /* file path and line number */
    if ((options & LOGAX_OPTION_FILE_PATH) || (options & LOGAX_OPTION_FILE_NAME_ONLY)) {
        if (options & LOGAX_OPTION_FILE_PATH) {
			fprintf(stream, " %s", file_path);
        } else {
			char file_name_only[logax_cstr_length((char *)file_path)];
			logax_extract_name_only(file_path, file_name_only);
			fprintf(stream, " %s", file_name_only);
		}
    }
    if (options & LOGAX_OPTION_LINE_NUMBER) {
		if (!((options & LOGAX_OPTION_FILE_PATH) || (options & LOGAX_OPTION_FILE_NAME_ONLY))) {
			fprintf(stream, " ");
		}
		fprintf(stream, ":%lld", line_number);
    }
	if (options & LOGAX_OPTION_FUNCTION) {
		fprintf(stream, " --- [%s\t]", function_name);
	}
    fprintf(stream, " ");
	va_start(va_arg, fmt);
	vfprintf(stream, fmt, va_arg);
	va_end(va_arg);
    fprintf(stream, "\n");
}

/**

*/
#define logax_write_plaintext_format_to_stream(stream, options, fmt, ...) logax_write_plaintext_format_to_stream__internal__(stream, options, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__)

#define logax_write_text_format_to_stream

/**
    
*/
#ifndef LOGAX_NO_FUNCTIONAL_LOGGING

/**
    
*/
static void logax_log_write(LogaxLogger logax_logger, const char *fmt, ...) {

}
#endif

// log_trace(const char *fmt, ...);
// log_debug(const char *fmt, ...);
// log_info(const char *fmt, ...);
// log_warn(const char *fmt, ...);
// log_error(const char *fmt, ...);
// log_fatal(const char *fmt, ...);

/**
    
*/
#ifndef LOGAX_DEBUG
/**

*/
static void logax_print_logger_info_internal__(FILE *stream, LogaxLogger logax_logger, const char *file_path, const size_t line_number) {
    fprintf(stream, "LOGAX_LOGGER %s:%d\n", file_path, line_number);
    fprintf(stream, "   output_stream=%p, level=%d, options=%d\n", logax_logger.output_stream, logax_logger.level, logax_logger.options);
}

/**

*/
#define logax_print_logger_info(stream, logax_logger) logax_print_logger_info_internal__(stream, logax_logger, __FILE__, __LINE__)
#else
/**

*/
#define logax_print_logger_info(stream, logax_logger)
#endif


#ifdef __cplusplus
}
#endif

#endif