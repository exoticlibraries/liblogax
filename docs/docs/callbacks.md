
# Callback and Hook

LogaxLogger supports callback (or hook), the callbacks are invoked when a new log is sent. The callback can be used to create a custom output format or used to changed out the log is processed (e.g. blink bulb on andruino e.t.c). The output stream can be completely disabled by defining the macro `LOGAX_NO_OUTPUT_STREAM` or setiing the option to QUITE using the function `logax_set_quite`, in this case if callbacks are registered they will be invoked with the log event.

The callback function signature is

```c
typedef void (*logax_callback)(const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *fmt, ...);
```

The example belows shows how to register a callback which is invoked when there is a new log

```c
#include <exotic/logax.h>

void on_new_log_callback(const char *date, const char *time, const int level, const char *file, const size_t line_number, const char *function_name, const char *fmt, ...) {
	va_list args;
	printf("<logevent>");
	printf("\n  <date>%s</date>", date);
	printf("\n  <time>%s</time>", time);
	printf("\n  <level>%s</level>", GET_LEVEL_STRING(level));
	printf("\n  <file>%s</file>", file);
	printf("\n  <line_number>%d</line_number>", line_number);
	printf("\n  <function_name>%s</function_name>", function_name);
	printf("\n  <message>");
	va_start(args, fmt);vfprintf(stdout, fmt, args);va_end(args);
	printf("</message>\n</logevent>\n");
}

int main(int argc, char **argv) {
	LogaxLogger logax_logger;

	logax_init_logger(&logax_logger);
	logax_set_quite(&logax_logger, 1);
	logax_logger_add_callback(&logax_logger, on_new_log_callback);
	logax_logger_trace(&logax_logger, "%s", "Logging the test for TRACE");
	logax_logger_debug(&logax_logger, "%s", "Logging the test for DEBUG");
	logax_logger_info(&logax_logger, "%s", "Logging the test for INFO");
	logax_logger_warn(&logax_logger, "%s", "Logging the test for WARN");
	logax_logger_error(&logax_logger, "%s", "Logging the test for ERROR");
	logax_logger_fatal(&logax_logger, "%s", "Logging the test for FATAL");
}
```

This gives the following outputs the in XML format as defined in the `on_new_log_callback` function:

```xml
<logevent>
  <date>2021-11-21</date>
  <time>07:26:02</time>
  <level>TRACE</level>
  <file>C:\Users\azeez\Documents\OPEN_SOURCE\EXOTIC_LIBRARIES\liblogax\test\crash_test.c</file>
  <line_number>25</line_number>
  <function_name>main</function_name>
  <message>Logging the test for TRACE</message>
</logevent>
<logevent>
  <date>2021-11-21</date>
  <time>07:26:02</time>
  <level>DEBUG</level>
  <file>C:\Users\azeez\Documents\OPEN_SOURCE\EXOTIC_LIBRARIES\liblogax\test\crash_test.c</file>
  <line_number>26</line_number>
  <function_name>main</function_name>
  <message>Logging the test for DEBUG</message>
</logevent>
...
```

