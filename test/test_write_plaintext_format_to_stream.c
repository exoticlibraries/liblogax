/*!gcc {0} -I. -I../../include/ -I../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!g++ -ansi -pedantic-errors {0} -I. -I../../include/ -I../../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!gcc {0} -I. -I../../include/ -I../../../libcester/include -I../include/ -o out; ./out */
/*!g++ -std=c++11 {0} -I. -I../../include/ -I../include/ -I../../../libcester/include -o out; ./out */

#include <exotic/cester.h>
#include <exotic/logax.h>

#define LOGAX_OPTIONS_VERBOSE LOGAX_OPTION_DATE_TIME | LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_PATH | LOGAX_OPTION_LINE_NUMBER | LOGAX_OPTION_FUNCTION
#define LOGAX_OPTIONS_MINIMAL LOGAX_OPTION_DATE_TIME | LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_LINE_NUMBER
#define LOGAX_OPTIONS_VERBOSE_NO_COLOR LOGAX_OPTION_DATE_TIME | LOGAX_OPTION_FILE_PATH | LOGAX_OPTION_LINE_NUMBER | LOGAX_OPTION_FUNCTION
#define LOGAX_OPTIONS_MINIMAL_NO_COLOR LOGAX_OPTION_DATE_TIME | LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_LINE_NUMBER

CESTER_TEST(logax_write_plaintext_format_to_stream_verbose, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");


	cester_assert_stdout_stream_content_contain("\x1B[36mTRACE\x1B[0m");
	cester_assert_stdout_stream_content_contain("\x1B[32mDEBUG\x1B[0m");
	cester_assert_stdout_stream_content_contain("\x1B[35mINFO\x1B[0m");
	cester_assert_stdout_stream_content_contain("\x1B[33mWARN\x1B[0m");
	cester_assert_stdout_stream_content_contain("\x1B[31mERROR\x1B[0m");
	cester_assert_stdout_stream_content_contain("\x1B[31mFATAL\x1B[0m");
	cester_assert_stdout_stream_content_contain(".c:17 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is a trace output\n");
	cester_assert_stdout_stream_content_contain(".c:18 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is a debug output\n");
	cester_assert_stdout_stream_content_contain(".c:19 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is an info output\n");
	cester_assert_stdout_stream_content_contain(".c:20 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is a warning output\n");
	cester_assert_stdout_stream_content_contain(".c:21 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is an error output\n");
	cester_assert_stdout_stream_content_contain(".c:22 --- [cester_test_logax_write_plaintext_format_to_stream_verbose\t] This is a fatal output\n");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_plaintext_format_to_stream_minimal, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain("\x1B[36mTRACE\x1B[0m test_write_plaintext_format_to_stream.c:44 This is a trace output\n");
	cester_assert_stdout_stream_content_contain("\x1B[32mDEBUG\x1B[0m test_write_plaintext_format_to_stream.c:45 This is a debug output\n");
	cester_assert_stdout_stream_content_contain("\x1B[35mINFO\x1B[0m test_write_plaintext_format_to_stream.c:46 This is an info output\n");
	cester_assert_stdout_stream_content_contain("\x1B[33mWARN\x1B[0m test_write_plaintext_format_to_stream.c:47 This is a warning output\n");
	cester_assert_stdout_stream_content_contain("\x1B[31mERROR\x1B[0m test_write_plaintext_format_to_stream.c:48 This is an error output\n");
	cester_assert_stdout_stream_content_contain("\x1B[31mFATAL\x1B[0m test_write_plaintext_format_to_stream.c:49 This is a fatal output\n");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_plaintext_format_to_stream_verbose_no_color, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");


	cester_assert_stdout_stream_content_contain("TRACE");
	cester_assert_stdout_stream_content_contain("DEBUG");
	cester_assert_stdout_stream_content_contain("INFO");
	cester_assert_stdout_stream_content_contain("WARN");
	cester_assert_stdout_stream_content_contain("ERROR");
	cester_assert_stdout_stream_content_contain("FATAL");
	cester_assert_stdout_stream_content_contain(".c:64 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is a trace output\n");
	cester_assert_stdout_stream_content_contain(".c:65 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is a debug output\n");
	cester_assert_stdout_stream_content_contain(".c:66 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is an info output\n");
	cester_assert_stdout_stream_content_contain(".c:67 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is a warning output\n");
	cester_assert_stdout_stream_content_contain(".c:68 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is an error output\n");
	cester_assert_stdout_stream_content_contain(".c:69 --- [cester_test_logax_write_plaintext_format_to_stream_verbose_no_color\t] This is a fatal output\n");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_plaintext_format_to_stream_minimal_no_color, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_plaintext_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain("TRACE test_write_plaintext_format_to_stream.c:91 This is a trace output\n");
	cester_assert_stdout_stream_content_contain("DEBUG test_write_plaintext_format_to_stream.c:92 This is a debug output\n");
	cester_assert_stdout_stream_content_contain("INFO test_write_plaintext_format_to_stream.c:93 This is an info output\n");
	cester_assert_stdout_stream_content_contain("WARN test_write_plaintext_format_to_stream.c:94 This is a warning output\n");
	cester_assert_stdout_stream_content_contain("ERROR test_write_plaintext_format_to_stream.c:95 This is an error output\n");
	cester_assert_stdout_stream_content_contain("FATAL test_write_plaintext_format_to_stream.c:96 This is a fatal output\n");

	CESTER_RELEASE_STDOUT();
})

CESTER_OPTIONS(
    CESTER_VERBOSE_LEVEL(3);
)

