
# Logging with LogaxLogger

In a situation where callback is needed, no FILE* ability on the platform or the flags/options want to be shared across the log, the `LogaxLogger` struct can be used. No memory allocation is required when initaili

## Iinitialized LogaxLogger

To iinitialized the LogaxLogger the function `logax_init_logger` can be used, it not necessary to call the logax_init_logger function, all it does is set the LogaxLogger flags to default value, output_stream to stdout and fill the empty callbacks with NULL, these can be self-managed.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);
}
```

## LogaxLogger Loggers

For each of the logging level in logax a function is provider that accepts `LogaxLogger` struct as parameter:

- logax_logger_trace
- logax_logger_debug
- logax_logger_info
- logax_logger_warn
- logax_logger_error
- logax_logger_fatal

Each of the function above invoke the corresponding `logax_write_*_format_to_stream` respectively, the default formatter when LogaxLogger is initialized with the function logax_init_logger is `LOGAX_FORMATTER_TEXT`, the output format can be changed using the function `logax_set_formatter`.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;
	logax_init_logger(&logax_logger);

	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_TEXT);
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");
}
```

