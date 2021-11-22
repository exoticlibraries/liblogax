/*!gcc {0} -I. -I../../include/ -I../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!g++ -ansi -pedantic-errors {0} -I. -I../../include/ -I../../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!gcc {0} -I. -I../../include/ -I../../../libcester/include -I../include/ -o out; ./out */
/*!g++ -std=c++11 {0} -I. -I../../include/ -I../include/ -I../../../libcester/include -o out; ./out */

#include <exotic/cester.h>
#include <exotic/logax.h>

CESTER_TEST(logger_log_text_format, test_inst, {
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

	cester_assert_stdout_stream_content_contain((char *) "\x1B[36mTRACE\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32mDEBUG\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[35mINFO\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[33mWARN\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[31mERROR\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[31mFATAL\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for TRACE\n");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for DEBUG\n");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for INFO\n");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for WARN\n");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for ERROR\n");
	cester_assert_stdout_stream_content_contain((char *) " Logging the test for FATAL\n");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logger_log_key_value_format, test_inst, {
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

	cester_assert_stdout_stream_content_contain((char *) "level=\"TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"FATAL\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"Logging the test for FATAL\"");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logger_log_json_format, test_inst, {
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

	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"TRACE\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"DEBUG\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"INFO\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"WARN\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"ERROR\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"level\"\x1B[0m:\x1B[36m\"FATAL\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for TRACE\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for DEBUG\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for INFO\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for WARN\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for ERROR\"\x1B[0m");
	cester_assert_stdout_stream_content_contain((char *) "\x1B[32m\"message\"\x1B[0m:\x1B[36m\"Logging the test for FATAL\"\x1B[0m");

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

