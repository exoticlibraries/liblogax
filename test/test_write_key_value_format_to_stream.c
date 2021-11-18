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

CESTER_TEST(logax_write_key_value_format_to_stream_verbose, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain((char *) "level=\"TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"FATAL\"");
	cester_assert_stdout_stream_content_contain((char *) "line_number=17");
	cester_assert_stdout_stream_content_contain((char *) "line_number=18");
	cester_assert_stdout_stream_content_contain((char *) "line_number=19");
	cester_assert_stdout_stream_content_contain((char *) "line_number=20");
	cester_assert_stdout_stream_content_contain((char *) "line_number=21");
	cester_assert_stdout_stream_content_contain((char *) "line_number=22");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a trace output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a debug output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an info output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a warning output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an error output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a fatal output\"");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_key_value_format_to_stream_minimal, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain((char *) "level=\"TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"FATAL\"");
	cester_assert_stdout_stream_content_contain((char *) "file=\"test_write_key_value_format_to_stream.c\"");
	cester_assert_stdout_stream_content_contain((char *) "line_number=49");
	cester_assert_stdout_stream_content_contain((char *) "line_number=50");
	cester_assert_stdout_stream_content_contain((char *) "line_number=51");
	cester_assert_stdout_stream_content_contain((char *) "line_number=52");
	cester_assert_stdout_stream_content_contain((char *) "line_number=53");
	cester_assert_stdout_stream_content_contain((char *) "line_number=54");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a trace output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a debug output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an info output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a warning output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an error output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a fatal output\"");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_key_value_format_to_stream_verbose_no_color, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_VERBOSE_NO_COLOR | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain((char *) "level=\"TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"FATAL\"");
	cester_assert_stdout_stream_content_contain((char *) "line_number=82");
	cester_assert_stdout_stream_content_contain((char *) "line_number=83");
	cester_assert_stdout_stream_content_contain((char *) "line_number=84");
	cester_assert_stdout_stream_content_contain((char *) "line_number=85");
	cester_assert_stdout_stream_content_contain((char *) "line_number=86");
	cester_assert_stdout_stream_content_contain((char *) "line_number=87");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a trace output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a debug output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an info output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a warning output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an error output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a fatal output\"");

	CESTER_RELEASE_STDOUT();
})

CESTER_TEST(logax_write_key_value_format_to_stream_minimal_no_color, test_inst, {
    CESTER_CAPTURE_STDOUT();

	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTIONS_MINIMAL_NO_COLOR | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");

	cester_assert_stdout_stream_content_contain((char *) "level=\"TRACE\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"DEBUG\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"INFO\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"WARN\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"ERROR\"");
	cester_assert_stdout_stream_content_contain((char *) "level=\"FATAL\"");
	cester_assert_stdout_stream_content_contain((char *) "file=\"test_write_key_value_format_to_stream.c\"");
	cester_assert_stdout_stream_content_contain((char *) "line_number=114");
	cester_assert_stdout_stream_content_contain((char *) "line_number=115");
	cester_assert_stdout_stream_content_contain((char *) "line_number=116");
	cester_assert_stdout_stream_content_contain((char *) "line_number=117");
	cester_assert_stdout_stream_content_contain((char *) "line_number=118");
	cester_assert_stdout_stream_content_contain((char *) "line_number=119");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a trace output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a debug output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an info output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a warning output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is an error output\"");
	cester_assert_stdout_stream_content_contain((char *) "message=\"This is a fatal output\"");

	CESTER_RELEASE_STDOUT();
})

CESTER_OPTIONS(
    CESTER_VERBOSE_LEVEL(3);
)

