/*!gcc {0} -I. -I../../include/ -I../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!g++ -ansi -pedantic-errors {0} -I. -I../../include/ -I../../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!gcc {0} -I. -I../../include/ -I../../../libcester/include -I../include/ -o out; ./out */
/*!g++ -std=c++11 {0} -I. -I../../include/ -I../include/ -I../../../libcester/include -o out; ./out */


#define LOGAX_USE_OLD_CONSOLE_MODE

#include <exotic/cester.h>
#include <exotic/logax.h>

#ifdef _WIN32
CESTER_TEST(log_text_using_old_console_mode_text, test_inst, {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_TEXT);

    CESTER_CAPTURE_STDOUT();
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");

	cester_assert_stdout_stream_content_not_equal("");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[36mTRACE\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[32mDEBUG\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[35mINFO\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[33mWARN\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mERROR\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mFATAL\x1B[0m");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(log_key_value_using_old_console_mode_text, test_inst, {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_KEY_VALUE);

    CESTER_CAPTURE_STDOUT();
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");

	cester_assert_stdout_stream_content_not_equal("");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[36mTRACE\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[32mDEBUG\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[35mINFO\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[33mWARN\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mERROR\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mFATAL\x1B[0m");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(log_json_using_old_console_mode_text, test_inst, {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_JSON);

    CESTER_CAPTURE_STDOUT();
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");

	cester_assert_stdout_stream_content_not_equal("");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[36mTRACE\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[32mDEBUG\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[35mINFO\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[33mWARN\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mERROR\x1B[0m");
	cester_assert_stdout_stream_content_not_contain((char *) "\x1B[31mFATAL\x1B[0m");

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
#endif
