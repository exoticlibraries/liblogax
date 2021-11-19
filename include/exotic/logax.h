
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
    #define LOGAX_NULL 0L
#else 
    #define __LOGAX_FUNCTION__ __func__
    #define LOGAX_NULL NULL
#endif

#if defined(_WIN32) && defined(LOGAX_USE_OLD_CONSOLE_MODE)

#define LOGAX_RESET_TERMINAL           15                                                /**< reset the terminal color. Nothing          */
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
typedef void (*logax_callback)(const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *fmt, ...);
#endif

/**
    
*/
enum LogaxOption {
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
enum LogaxLevel {
    LOGAX_LEVEL_TRACE   = 1 << 10, /**<  ? */
    LOGAX_LEVEL_DEBUG   = 1 << 11, /**<  ? */
    LOGAX_LEVEL_INFO    = 1 << 12, /**<  ? */
    LOGAX_LEVEL_WARN    = 1 << 13,
    LOGAX_LEVEL_ERROR   = 1 << 14,
    LOGAX_LEVEL_FATAL   = 1 << 15
};

/**
    
*/
enum LogaxFormatter {
    LOGAX_FORMATTER_TEXT         = 1 << 20, /**<  ? */
    LOGAX_FORMATTER_KEY_VALUE    = 1 << 21, /**<  ? */
    LOGAX_FORMATTER_JSON         = 1 << 23 /**<  ? */
};

/**
    
*/
struct logax_logger_s {
    int flags;                /**<  ? */
#if !defined(LOGAX_NO_OUTPUT_STREAM)
    FILE *output_stream;        /**<  ? */
#endif
#ifndef LOGAX_NO_CALLBACK
    logax_callback callbacks[LOGAX_MAX_CALLBACKS];
#endif
};

/**

*/
typedef struct logax_logger_s LogaxLogger;

/**

*/
static void logax_init_logger(LogaxLogger *logax_logger) {
    logax_logger->flags = LOGAX_FORMATTER_TEXT | LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_LINE_NUMBER;
#ifndef LOGAX_NO_TIME
    logax_logger->flags |= LOGAX_OPTION_DATE_TIME;
#endif
#if defined(stdout) && !defined(LOGAX_NO_OUTPUT_STREAM)
    logax_logger->output_stream = stdout;
#endif
#ifndef LOGAX_NO_CALLBACK
    for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {
        logax_logger->callbacks[index] = LOGAX_NULL;
    }
#endif
}

#if !defined(LOGAX_NO_OUTPUT_STREAM)
/**

*/
static void logax_init_logger_ws(LogaxLogger *logax_logger, FILE *output_stream) {
    logax_logger->flags = LOGAX_FORMATTER_TEXT | LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_LINE_NUMBER;
#ifndef LOGAX_NO_TIME
    logax_logger->flags |= LOGAX_OPTION_DATE_TIME;
#endif
    logax_logger->output_stream = output_stream;
#ifndef LOGAX_NO_CALLBACK
    for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {
        logax_logger->callbacks[index] = LOGAX_NULL;
    }
#endif
}
#endif

/**

*/
static unsigned logax_logger_add_callback(LogaxLogger *logax_logger, logax_callback callback) {
    for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {
        if (logax_logger->callbacks[index] == LOGAX_NULL) {
            logax_logger->callbacks[index] = callback;
            return index;
        }
    }
    return -1;
}

/**

*/
#define logax_add_flag(flags, flag) flags |= flag;

/**

*/
#define logax_set_flag logax_add_flag

/**

*/
#define logax_remove_flag(flags, flag) flags &= ~flag;

/**

*/
#define logax_clear_flag logax_remove_flag

/**

*/
#define logax_set_formatter(logax_logger, new_formatter) {\
        if ((logax_logger)->flags & LOGAX_FORMATTER_TEXT) logax_remove_flag((logax_logger)->flags, LOGAX_FORMATTER_TEXT);\
        if ((logax_logger)->flags & LOGAX_FORMATTER_KEY_VALUE) logax_remove_flag((logax_logger)->flags, LOGAX_FORMATTER_KEY_VALUE);\
        if ((logax_logger)->flags & LOGAX_FORMATTER_JSON) logax_remove_flag((logax_logger)->flags, LOGAX_FORMATTER_JSON);\
        logax_add_flag((logax_logger)->flags, new_formatter);\
    }

/**

*/
#define logax_set_quite(logax_logger, make_quite) {\
        if (!make_quite && ((logax_logger)->flags & LOGAX_OPTION_QUITE)) { logax_remove_flag((logax_logger)->flags, LOGAX_OPTION_QUITE); }\
        else if (make_quite && !((logax_logger)->flags & LOGAX_OPTION_QUITE)) { logax_add_flag((logax_logger)->flags, LOGAX_OPTION_QUITE); }\
    }

/*

*/
static size_t logax_cstr_length(char char_array[]) {
    size_t length = 0;
    if (char_array == LOGAX_NULL) { return length; }
    while(char_array[length] != '\0') {
        length++;
    }
    return length;
}

/**

*/
static void logax_replace_char(char const* const file_path, char formatted_file_name[], char old_char, char new_char) {
    unsigned i = 0, j = -1;
    while (file_path[i] != '\0') {
        if (file_path[i] == old_char) {
            formatted_file_name[i] = new_char;
        } else {
            formatted_file_name[i] = file_path[i];
        }
        ++i;
    }
    formatted_file_name[i] = '\0';
}

/**

*/
static void logax_extract_name_only(char const* const file_path, char formatted_file_name[]) {
    unsigned i = 0, j = -1;
    while (file_path[i] != '\0') {
        if (file_path[i] == '\\' || file_path[i] == '/') {
            j = 0;
        } else if (j != -1) {
            formatted_file_name[j] = file_path[i];
            j++;
        }
        ++i;
    }
    formatted_file_name[j] = '\0';
}

#if defined(_WIN32) && defined(LOGAX_USE_OLD_CONSOLE_MODE)

/**

*/
#define LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(flags)
#else

/**

*/
#define LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(prefix_value, level, suffix_value)\
    if (is_colored) fprintf(stream, "%s%s%s%s%s", prefix_value, LOGAX_FOREGROUND_##level, #level, LOGAX_RESET_TERMINAL, suffix_value);\
    else fprintf(stream, "%s%s%s", prefix_value, #level, suffix_value);
#endif

/**

*/
static void logax_write_text_format_to_stream_final__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, va_list va_args) {
    if (flags & LOGAX_OPTION_QUITE) return;
    unsigned is_colored = (flags & LOGAX_OPTION_COLORED);
    /* date and time */
#ifndef LOGAX_NO_TIME
    time_t time_raw = time(LOGAX_NULL);
    struct tm *current_time = localtime(&time_raw);
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
        char date_buffer[16];
        date_buffer[strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", current_time)] = '\0';
        fprintf(stream, "%s", date_buffer);
    }
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_TIME)) {
        char time_buffer[16];
        time_buffer[strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time)] = '\0';
        if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
            fprintf(stream, " ");
        }
        fprintf(stream, "%s", time_buffer);
    }
#endif
    /* logging level */
    if (flags & LOGAX_LEVEL_TRACE) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", TRACE, "");
    } else if (flags & LOGAX_LEVEL_DEBUG) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", DEBUG, "");
    } else if (flags & LOGAX_LEVEL_INFO) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__("  ", INFO, "");
    } else if (flags & LOGAX_LEVEL_WARN) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__("  ", WARN, "");
    } else if (flags & LOGAX_LEVEL_ERROR) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", ERROR, "");
    } else if (flags & LOGAX_LEVEL_FATAL) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" ", FATAL, "");
    }
    /* file path and line number */
    if ((flags & LOGAX_OPTION_FILE_PATH) || (flags & LOGAX_OPTION_FILE_NAME_ONLY)) {
        char formatted_file_name[logax_cstr_length((char *)file_path)];
        if (flags & LOGAX_OPTION_FILE_PATH) {
            logax_replace_char((char *)file_path, formatted_file_name, '\\', '/');
            fprintf(stream, " %s", formatted_file_name);
        } else {
            logax_extract_name_only(file_path, formatted_file_name);
            fprintf(stream, " %s", formatted_file_name);
        }
    }
    if (flags & LOGAX_OPTION_LINE_NUMBER) {
        if (!((flags & LOGAX_OPTION_FILE_PATH) || (flags & LOGAX_OPTION_FILE_NAME_ONLY))) {
            fprintf(stream, " ");
        }
        fprintf(stream, ":%zu", line_number);
    }
    if (flags & LOGAX_OPTION_FUNCTION) {
        fprintf(stream, " --- [%s\t]", function_name);
    }
    fprintf(stream, " ");
    vfprintf(stream, fmt, va_args);
    fprintf(stream, "\n");
}

/**

*/
static void logax_write_text_format_to_stream__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, ...) {
    va_list va_args;
    va_start(va_args, fmt);
    logax_write_text_format_to_stream_final__internal__(stream, flags, file_path, line_number, function_name, fmt, va_args);
    va_end(va_args);
}

/**

*/
#define logax_write_text_format_to_stream(stream, flags, fmt, ...) logax_write_text_format_to_stream__internal__(stream, flags, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__)

/**

*/
static void logax_write_key_value_format_to_stream_final__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, va_list va_args) {
    if (flags & LOGAX_OPTION_QUITE) return;
    unsigned is_colored = 0;
    /* date and time */
#ifndef LOGAX_NO_TIME
    time_t time_raw = time(LOGAX_NULL);
    struct tm *current_time = localtime(&time_raw);
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
        char date_buffer[16];
        date_buffer[strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", current_time)] = '\0';
        fprintf(stream, "date=\"%s\"", date_buffer);
    }
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_TIME)) {
        char time_buffer[16];
        time_buffer[strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time)] = '\0';
        if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
            fprintf(stream, " ");
        }
        fprintf(stream, "time=\"%s\"", time_buffer);
    }
#endif
    /* logging level */
    if (flags & LOGAX_LEVEL_TRACE) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", TRACE, "\"");
    } else if (flags & LOGAX_LEVEL_DEBUG) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", DEBUG, "\"");
    } else if (flags & LOGAX_LEVEL_INFO) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", INFO, "\"");
    } else if (flags & LOGAX_LEVEL_WARN) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", WARN, "\"");
    } else if (flags & LOGAX_LEVEL_ERROR) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", ERROR, "\"");
    } else if (flags & LOGAX_LEVEL_FATAL) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(" level=\"", FATAL, "\"");
    }
    /* file path and line number */
    if ((flags & LOGAX_OPTION_FILE_PATH) || (flags & LOGAX_OPTION_FILE_NAME_ONLY)) {
        char formatted_file_name[logax_cstr_length((char *)file_path)];
        if (flags & LOGAX_OPTION_FILE_PATH) {
            logax_replace_char((char *)file_path, formatted_file_name, '\\', '/');
            fprintf(stream, " file=\"%s\"", formatted_file_name);
        } else {
            logax_extract_name_only(file_path, formatted_file_name);
            fprintf(stream, " file=\"%s\"", formatted_file_name);
        }
    }
    if (flags & LOGAX_OPTION_LINE_NUMBER) {
        fprintf(stream, " line_number=%zu", line_number);
    }
    if (flags & LOGAX_OPTION_FUNCTION) {
        fprintf(stream, " function=\"%s\"", function_name);
    }
    fprintf(stream, " message=\"");
    vfprintf(stream, fmt, va_args);
    fprintf(stream, "\"\n");
}

/**

*/
static void logax_write_key_value_format_to_stream__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, ...) {
    va_list va_args;
    va_start(va_args, fmt);
    logax_write_key_value_format_to_stream_final__internal__(stream, flags, file_path, line_number, function_name, fmt, va_args);
    va_end(va_args);
}

/**

*/
#define logax_write_key_value_format_to_stream(stream, flags, fmt, ...) logax_write_key_value_format_to_stream__internal__(stream, flags, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__)

/**

*/
static void logax_write_json_format_to_stream_final__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, va_list va_args) {
    if (flags & LOGAX_OPTION_QUITE) return;
    unsigned is_colored = 0;
    unsigned print_with_colored = (flags & LOGAX_OPTION_COLORED);
    /* date and time */
    fprintf(stream, "{");
#ifndef LOGAX_NO_TIME
    time_t time_raw = time(LOGAX_NULL);
    struct tm *current_time = localtime(&time_raw);
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
        char date_buffer[16];
          date_buffer[strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", current_time)] = '\0';
        fprintf(stream, "\"date\":\"%s\"", date_buffer);
    }
    if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_TIME)) {
        char time_buffer[16];
          time_buffer[strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time)] = '\0';
        if ((flags & LOGAX_OPTION_DATE_TIME) || (flags & LOGAX_OPTION_DATE)) {
            fprintf(stream, ",");
        }
        fprintf(stream, "\"time\":\"%s\"", time_buffer);
    }
#endif
    /* logging level */
    if (flags & LOGAX_LEVEL_TRACE) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", TRACE, "\"");
    } else if (flags & LOGAX_LEVEL_DEBUG) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", DEBUG, "\"");
    } else if (flags & LOGAX_LEVEL_INFO) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", INFO, "\"");
    } else if (flags & LOGAX_LEVEL_WARN) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", WARN, "\"");
    } else if (flags & LOGAX_LEVEL_ERROR) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", ERROR, "\"");
    } else if (flags & LOGAX_LEVEL_FATAL) {
        LOGAX_WRITE_LEVEL_COLOR__INTERNALL__(",\"level\":\"", FATAL, "\"");
    }
    /* file path and line number */
    if ((flags & LOGAX_OPTION_FILE_PATH) || (flags & LOGAX_OPTION_FILE_NAME_ONLY)) {
        char formatted_file_name[logax_cstr_length((char *)file_path)];
        if (flags & LOGAX_OPTION_FILE_PATH) {
            logax_replace_char((char *)file_path, formatted_file_name, '\\', '/');
            fprintf(stream, ",\"file\":\"%s\"", formatted_file_name);
        } else {
            logax_extract_name_only(file_path, formatted_file_name);
            fprintf(stream, ",\"file\":\"%s\"", formatted_file_name);
        }
    }
    if (flags & LOGAX_OPTION_LINE_NUMBER) {
        fprintf(stream, ",\"line_number\":%zu", line_number);
    }
    if (flags & LOGAX_OPTION_FUNCTION) {
        fprintf(stream, ",\"function\":\"%s\"", function_name);
    }
    fprintf(stream, ",\"message\":\"");
    vfprintf(stream, fmt, va_args);
    fprintf(stream, "\"}\n");
}

/**

*/
static void logax_write_json_format_to_stream__internal__(FILE *stream, int flags, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, ...) {
    va_list va_args;
    va_start(va_args, fmt);
    logax_write_json_format_to_stream_final__internal__(stream, flags, file_path, line_number, function_name, fmt, va_args);
    va_end(va_args);
}

/**

*/
#define logax_write_json_format_to_stream(stream, flags, fmt, ...) logax_write_json_format_to_stream__internal__(stream, flags, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__)

/**
    
*/
#ifndef LOGAX_NO_FUNCTIONAL_LOGGING

/**
    
*/
static void logax_logger_write(LogaxLogger *logax_logger, int level, const char *file_path, const size_t line_number, const char *function_name, const char *fmt, ...) {
    logax_logger->flags |= level;
    va_list args;

    va_start(args, fmt);
    if (logax_logger->flags & LOGAX_FORMATTER_JSON) {
        logax_write_json_format_to_stream_final__internal__(logax_logger->output_stream, logax_logger->flags, file_path, line_number, function_name, fmt, args);
    } else if (logax_logger->flags & LOGAX_FORMATTER_KEY_VALUE) {
        logax_write_key_value_format_to_stream_final__internal__(logax_logger->output_stream, logax_logger->flags, file_path, line_number, function_name, fmt, args);
    } else {
        logax_write_text_format_to_stream_final__internal__(logax_logger->output_stream, logax_logger->flags, file_path, line_number, function_name, fmt, args);
    }
    va_end(args);
    logax_logger->flags &= ~level;
#ifndef LOGAX_NO_TIME
    time_t time_raw = time(LOGAX_NULL);
    struct tm *current_time = localtime(&time_raw);
    char date_buffer[16];
    date_buffer[strftime(date_buffer, sizeof(date_buffer), "%Y-%m-%d", current_time)] = '\0';
    char time_buffer[16];
    time_buffer[strftime(time_buffer, sizeof(time_buffer), "%H:%M:%S", current_time)] = '\0';
#else
    char *date_buffer = "";
    char *time_buffer = "";
#endif
    /*for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {
        logax_callback callback = logax_logger->callbacks[index];
        if (callback != LOGAX_NULL) {
            //const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *message
            callback(date_buffer, time_buffer, level, file_path, line_number, function_name, "Yahoo");
        }
    }*/
}

#ifndef LOGAX_NO_CALLBACK
/**
    
*//* TODO: Refractor to a function */
#ifndef LOGAX_NO_TIME
    #define logax_logger_report_to_callback(logax_logger, level, fmt, ...) {\
            time_t time_raw__logax_tmp_var__ = time(LOGAX_NULL);\
            struct tm *current_time__logax_tmp_var__ = localtime(&time_raw__logax_tmp_var__);\
            char date_buffer__logax_tmp_var__[16];\
            date_buffer__logax_tmp_var__[strftime(date_buffer__logax_tmp_var__, sizeof(date_buffer__logax_tmp_var__), "%Y-%m-%d", current_time__logax_tmp_var__)] = '\0';\
            char time_buffer__logax_tmp_var__[16];\
            time_buffer__logax_tmp_var__[strftime(time_buffer__logax_tmp_var__, sizeof(time_buffer__logax_tmp_var__), "%H:%M:%S", current_time__logax_tmp_var__)] = '\0';\
            for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {\
                logax_callback callback = (logax_logger)->callbacks[index];\
                if (callback != LOGAX_NULL) {\
                    callback(date_buffer__logax_tmp_var__, time_buffer__logax_tmp_var__, level, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
                }\
            }\
        }
    #endif
#else
    #define logax_logger_report_to_callback(logax_logger, level, fmt, ...) {\
            char *date_buffer = "";\
            char *time_buffer = "";\
            for (int index = 0; index < LOGAX_MAX_CALLBACKS; index++) {\
                logax_callback callback = (logax_logger)->callbacks[index];\
                if (callback != LOGAX_NULL) {\
                    callback(date_buffer__logax_tmp_var__, time_buffer__logax_tmp_var__, level, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
                }\
            }\
        }
#endif


/**
    
*/
#define logax_logger_trace(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_TRACE, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_TRACE, fmt, __VA_ARGS__)

/**
    
*/
#define logax_logger_debug(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_DEBUG, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_DEBUG, fmt, __VA_ARGS__)

/**
    
*/
#define logax_logger_info(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_INFO, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_INFO, fmt, __VA_ARGS__)

/**
    
*/
#define logax_logger_warn(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_WARN, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_WARN, fmt, __VA_ARGS__)

/**
    
*/
#define logax_logger_error(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_ERROR, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_ERROR, fmt, __VA_ARGS__)

/**
    
*/
#define logax_logger_fatal(logax_logger, fmt, ...) logax_logger_write(logax_logger, LOGAX_LEVEL_FATAL, __FILE__, __LINE__, __LOGAX_FUNCTION__, fmt, __VA_ARGS__);\
    logax_logger_report_to_callback(logax_logger, LOGAX_LEVEL_FATAL, fmt, __VA_ARGS__)
#endif


#ifdef __cplusplus
}
#endif

#endif