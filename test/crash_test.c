/*!gcc {0} -I. -I../include/ -o out; ./out --cester-verbose */

//#define LOGAX_NO_TIME
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;

	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_JSON);
	logax_logger_trace(&logax_logger, "%s", "Enemy approching from X=108,Y=877");
	logax_write_json_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}

