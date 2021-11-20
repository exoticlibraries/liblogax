/*!gcc {0} -I. -I../include/ -o out; ./out --cester-verbose */

#include <exotic/logax.h>

/* TODO fix issue if pre option not set and there is extra space or comma before next option */
int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");
}

