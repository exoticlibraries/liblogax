
# Output Formats

liblogax currently support only three output format, which are text, key-value and json. To set the output format of a LogaxLogger struct use the function `logax_set_formatter`. The following are the format options:

- LOGAX_FORMATTER_TEXT
- LOGAX_FORMATTER_KEY_VALUE
- LOGAX_FORMATTER_JSON

## Text

Output as text using `logax_write_text_format_to_stream`

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}
```
```
2021-11-21 08:41:19 TRACE crash_test.c:6  --- [main     ] Enemy approching from X=108,Y=877
```

Output as text using the `LOGAX_FORMATTER_TEXT` option with LogaxLogger.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;

	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_TEXT);
	logax_logger_trace(&logax_logger, "%s", "Enemy approching from X=108,Y=877");
}
```
```
2021-11-21 08:38:38 TRACE crash_test.c:10 Enemy approching from X=108,Y=877
```

## Key Value

Output as key value using `logax_write_key_value_format_to_stream`

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}
```
```
date="2021-11-21" time="08:43:59" level="TRACE" file="crash_test.c" line_number=6 function="main" message="Enemy approching from X=108,Y=877"
```

Output as key value using the `LOGAX_FORMATTER_KEY_VALUE` option with LogaxLogger.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;

	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_KEY_VALUE);
	logax_logger_trace(&logax_logger, "%s", "Enemy approching from X=108,Y=877");
}
```
```
date="2021-11-21" time="08:46:00" level="TRACE" file="crash_test.c" line_number=10 message="Enemy approching from X=108,Y=877"
```

## JSON

Output as json using `logax_write_json_format_to_stream`

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_json_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}
```
```json
{"date":"2021-11-21","time":"08:44:58","level":"TRACE","file":"crash_test.c","line_number":6,"function":"main","message":"Enemy approching from X=108,Y=877"},
```

Output as json using the `LOGAX_FORMATTER_JSON` option with LogaxLogger.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	LogaxLogger logax_logger;

	logax_init_logger(&logax_logger);
	logax_set_formatter(&logax_logger, LOGAX_FORMATTER_JSON);
	logax_logger_trace(&logax_logger, "%s", "Enemy approching from X=108,Y=877");
}
```
```
{"date":"2021-11-21","time":"08:45:36","level":"TRACE","file":"crash_test.c","line_number":10,"message":"Enemy approching from X=108,Y=877"},
```

