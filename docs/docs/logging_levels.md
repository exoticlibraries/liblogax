
## Logging levels

There are five logging levels in the library:

- TRACE
- DEBUG
- INFO
- WARN
- ERROR
- FATAL

# TRACE

Trace is a verbose basic logging level and the default logging level, the color format is blue, ASCII color code `\x1B[36m`, windows console attribute `11`. The option name is `LOGAX_LEVEL_TRACE` with bit value of `1 << 16`.

# DEBUG

Trace is a verbose basic logging level and the default logging level, the color format is green, ASCII color code `\x1B[32m`, windows console attribute `2`. The option name is `LOGAX_LEVEL_DEBUG` with bit value of `1 << 17`.

# INFO

Trace is a verbose basic logging level and the default logging level, the color format is magenta, ASCII color code `\x1B[35m`, windows console attribute `5`. The option name is `LOGAX_LEVEL_INFO` with bit value of `1 << 18`.

# WARN

Trace is a verbose basic logging level and the default logging level, the color format is yellow, ASCII color code `\x1B[33m`, windows console attribute `6`. The option name is `LOGAX_LEVEL_WARN` with bit value of `1 << 19`.

# ERROR

Trace is a verbose basic logging level and the default logging level, the color format is red, ASCII color code `\x1B[31m`, windows console attribute `4`. The option name is `LOGAX_LEVEL_ERROR` with bit value of `1 << 20`.

# FATAL

Trace is a verbose basic logging level and the default logging level, the color format is red, ASCII color code `\x1B[31m`, windows console attribute `4`. The option name is `LOGAX_LEVEL_FATAL` with bit value of `1 << 21`.


# Example

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Enemy approching from X=108,Y=877");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_DEBUG, "%s", "Enemy approching from X=108,Y=877");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_INFO, "%s", "Enemy approching from X=108,Y=877");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_WARN, "%s", "Enemy approching from X=108,Y=877");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_ERROR, "%s", "Enemy approching from X=108,Y=877");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_FATAL, "%s", "Enemy approching from X=108,Y=877");
}
```

The example above log the same value but with different logging level.

