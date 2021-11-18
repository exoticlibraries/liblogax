/*!gcc {0} -I. -I../../include/ -I../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!g++ -ansi -pedantic-errors {0} -I. -I../../include/ -I../../../libxtd/include/ -I../include/ -I../../../libcester/include -o out; ./out */
/*!gcc {0} -I. -I../../include/ -I../../../libcester/include -I../include/ -o out; ./out */
/*!g++ -std=c++11 {0} -I. -I../../include/ -I../include/ -I../../../libcester/include -o out; ./out */

#include <exotic/cester.h>
#include <exotic/logax.h>

CESTER_TEST(init_logax_default_stdout, test_inst, {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);

	cester_assert_int_eq(logax_logger.level, 0);
	cester_assert_int_eq(logax_logger.options, 0);
	cester_assert_int_eq(logax_logger.formatter, LOGAX_FORMATTER_PLAIN_TEXT);
	cester_assert_ptr_eq(logax_logger.output_stream, stdout);
})

CESTER_TEST(init_logax_with_stream, test_inst, {
	LogaxLogger logax_logger_stdout;
	LogaxLogger logax_logger_stderr;
	LogaxLogger logax_logger_custom_stream;

	FILE *file;
	logax_init_logger_ws(&logax_logger_stdout, stdout);
	logax_init_logger_ws(&logax_logger_stderr, stderr);
	logax_init_logger_ws(&logax_logger_custom_stream, file);

	cester_assert_ptr_eq(logax_logger_stdout.output_stream, stdout);
	cester_assert_ptr_eq(logax_logger_stderr.output_stream, stderr);
	cester_assert_ptr_eq(logax_logger_custom_stream.output_stream, file);
})

CESTER_OPTIONS(
    CESTER_VERBOSE_LEVEL(3);
)

