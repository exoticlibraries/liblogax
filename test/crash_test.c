/*!gcc {0} -I. -I../include/ -o out; ./out --cester-verbose */

//#define LOGAX_NO_TIME
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);

	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_TEXT);
	logax_logger_trace(&logax_logger, "%s", "Logging from logax");

	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_KEY_VALUE);
	logax_logger_trace(&logax_logger, "%s", "Logging from logax");

	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_JSON);
	logax_logger_trace(&logax_logger, "%s", "Logging from logax");
}

