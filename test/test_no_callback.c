/*!gcc {0} -I. -I../../include/ -I../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!g++ -ansi -pedantic-errors {0} -I. -I../../include/ -I../../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!gcc {0} -I. -I../../include/ -I../../../libcester/include -I../include/ -o out; ./out */
/*!g++ -std=c++11 {0} -I. -I../../include/ -I../include/ -I../../../libcester/include -o out; ./out */


#define LOGAX_LOGGER_NO_CALLBACK

#include <exotic/cester.h>
#include <exotic/logax.h>

CESTER_BODY(
void on_new_log_callback(const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *fmt, ...) {
    va_list args;
	printf("%s %s level=%d, file=%s, line_number=%zu, func=%s, message=", date, time, level, file, line_number, function_name);
    va_start(args, fmt);
	vfprintf(stdout, fmt, args);
    va_end(args);
	printf("\n");
}

void on_new_log_callback2(const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *fmt, ...) {
   printf("LOG:::%zu\n", line_number);
}
)

CESTER_TEST(logax_no_callback, test_inst, {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);

	logax_set_quiet(&logax_logger, 1);
	logax_logger_add_callback(&logax_logger, on_new_log_callback);
	logax_logger_add_callback(&logax_logger, on_new_log_callback2);

    CESTER_CAPTURE_STDOUT();
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");

	cester_assert_stdout_stream_content_not_contain((char *) "level=262144");
	cester_assert_stdout_stream_content_not_contain((char *) "level=524288");
	cester_assert_stdout_stream_content_not_contain((char *) "line_number=36");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::36\n");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::37\n");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::38\n");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::39\n");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::40\n");
	cester_assert_stdout_stream_content_not_contain((char *) "LOG:::41\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for TRACE\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for DEBUG\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for INFO\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for WARN\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for ERROR\n");
	cester_assert_stdout_stream_content_not_contain((char *) "message=Logging the test for FATAL\n");

	CESTER_RELEASE_STDOUT();
})

/* for now until test in clang win32 is re visited */
#if defined(_WIN32) && defined(__clang__)
CESTER_OPTIONS(
    CESTER_REPORT_SUCCESS_REGARDLESS();
    CESTER_VERBOSE_LEVEL(3);
)
#else
CESTER_OPTIONS(
    CESTER_VERBOSE_LEVEL(3);
)
#endif

