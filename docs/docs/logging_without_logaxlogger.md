
# Logging without LogaxLogger

The library can be used to output log without need to setup the `LogaxLogger` struct, this will require the platform to have output stream or can write to file. If the macro LOGAX_NO_LOGGER is defined before including the logax.h geader file, the LogaxLogger struct and all related functions will not be compiled. The following functions provides the API to write to output stream in the supported formats

- logax_write_text_format_to_stream
- logax_write_key_value_format_to_stream
- logax_write_json_format_to_stream

`logax_write_text_format_to_stream` write the output in plain text format, the first paramater is the stream, followed by the options, the options is the combinations of any of the LOGAX_OPTION_*, LOGAX_LEVEL_* and LOGAX_FORMATTER_* macros.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}

// output
// 2021-11-21 06:34:07 TRACE crash_test.c:13 Logging the test for TRACE
```

`logax_write_key_value_format_to_stream` write the output in a key-value format coloring is ignored in this format, the first paramater is the stream, followed by the options, the options is the combinations of any of the LOGAX_OPTION_*, LOGAX_LEVEL_* and LOGAX_FORMATTER_* macros.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_key_value_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}

// output
// date="2021-11-21" time="06:41:34" level="TRACE" file="crash_test.c" line_number=8 function="main" message="This is a trace output"
```

`logax_write_json_format_to_stream` write the output in a json format, the first paramater is the stream, followed by the options, the options is the combinations of any of the LOGAX_OPTION_*, LOGAX_LEVEL_* and LOGAX_FORMATTER_* macros.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_json_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
}

// output
// {"date":"2021-11-21","time":"06:42:25","level":"TRACE","file":"crash_test.c","line_number":8,"function":"main","message":"This is a trace output"},
```

