
### Options

liblogax uses the bitwise arithmetic to manage the options and flags, the flag variable is defined as an int which is 32 bits on most platform hence any flag or option must not be more than 32 bit in size. There are 3 enum which are used to group the options, `LogaxOption`, `LogaxLevel` and `LogaxFormatter`.

## LogaxOption 

This enum is used to declare the basic options for the library, the bit size from (1 << 1) to (1 << 9) and (1 << 15) are used, (1 << 10) to (1 << 14) are reserved in case a new option is needed to be added. The following options are declared in the LogaxOption enum:

- LOGAX_OPTION_QUIET
- LOGAX_OPTION_DATE
- LOGAX_OPTION_TIME
- LOGAX_OPTION_DATE_TIME
- LOGAX_OPTION_FILE_PATH
- LOGAX_OPTION_FILE_NAME_ONLY
- LOGAX_OPTION_LINE_NUMBER
- LOGAX_OPTION_COLORED
- LOGAX_OPTION_FUNCTION
- LOGAX_OPTION_ALL

# LOGAX_OPTION_QUIET

This option disable writing the log to the output stream even if the program is compiled with write to output stream functionality. Bit value is `1 << 1`.

# LOGAX_OPTION_DATE

This option enable writing/setting the date of the log in the following format `yyyy-mm-ddd`. Bit value is `1 << 2`. If the macro **LOGAX_NO_TIME** is declared this option will not be available for use.

# LOGAX_OPTION_TIME

This option enable writing/setting the time of the log in the following format `hh:mm:ss`. Bit value is `1 << 3`. If the macro **LOGAX_NO_TIME** is declared this option will not be available for use.

# LOGAX_OPTION_DATE_TIME

This option enable writing/setting the time and date of the log regardless, even if the option **LOGAX_OPTION_DATE** and **LOGAX_OPTION_TIME** is not set. Bit value is `1 << 4`. If the macro **LOGAX_NO_TIME** is declared this option will not be available for use.

# LOGAX_OPTION_FILE_PATH

This option writes/set the full path to the file where the log event is sent from. Bit value is `1 << 5`.

# LOGAX_OPTION_FILE_NAME_ONLY

This option writes/set only the name of the file where the log event is sent from. Bit value is `1 << 6`.

# LOGAX_OPTION_LINE_NUMBER

This option writes/set the line number where the log event is sent from. Bit value is `1 << 7`.

# LOGAX_OPTION_COLORED

This option enable pretty printing/writing of the log. Bit value is `1 << 8`. If the macro **LOGAX_NO_COLORING** is declared this option will not be available for use.

# LOGAX_OPTION_FUNCTION

This option writes/set the name of the function where the log event is sent from. Bit value is `1 << 9`.

# LOGAX_OPTION_ALL

This option enabled all available (or compiled) option, it equivalent to setting each of the options from **(1 << 1)** to **(1 << 15)**. Only options declared in the LogaxOption are affected by this option.

# Example

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_json_format_to_stream(stdout, LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_NAME_ONLY, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_DATE_TIME, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_COLORED | LOGAX_OPTION_FILE_NAME_ONLY | LOGAX_OPTION_LINE_NUMBER| LOGAX_OPTION_FUNCTION, "%s", "Hello World");
}
```

## LogaxLevel 

This enum is used to declare the logging levels, if more than one of this option is set only the prevalent one will take effect. The bit size from (1 << 16) to (1 << 21) are used, the following options are declared in the LogaxLevel enum:

- LOGAX_LEVEL_TRACE
- LOGAX_LEVEL_DEBUG
- LOGAX_LEVEL_INFO
- LOGAX_LEVEL_WARN
- LOGAX_LEVEL_ERROR
- LOGAX_LEVEL_FATAL

> Prevalency is in the order at which it listed above

# LOGAX_LEVEL_TRACE

Mark the log event level as trace. 

# LOGAX_LEVEL_DEBUG

Mark the log event level as debug. 

# LOGAX_LEVEL_INFO

Mark the log event level as information. 

# LOGAX_LEVEL_WARN

Mark the log event level as warning. 

# LOGAX_LEVEL_ERROR

Mark the log event level as an error. 

# LOGAX_LEVEL_FATAL

Mark the log event level as a critical issue. 

# Example 

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_DEBUG, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_INFO, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_WARN, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_ERROR, "%s", "Hello World");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_FATAL, "%s", "Hello World");
}
```

## LogaxFormatter 

This enum is used to declare the output formats used for the logging, the bit size from (1 << 25) to (1 << 27) are used, the following options are declared in the LogaxFormatter enum:

- LOGAX_FORMATTER_TEXT
- LOGAX_FORMATTER_KEY_VALUE
- LOGAX_FORMATTER_JSON

```c
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
```

# LOGAX_FORMATTER_TEXT

This option writes the log as text. With the example above the following is written to the output

```
2021-11-22 23:08:49 TRACE crash_test.c:11 Logging from logax
```

# LOGAX_FORMATTER_KEY_VALUE

This option writes the log as key value. With the example above the following is written to the output

```
date="2021-11-22" time="23:08:49" level="TRACE" file="crash_test.c" line_number=14 message="Logging from logax"
```

# LOGAX_FORMATTER_JSON

This option writes the log as json. With the example above the following is written to the output

```
{"date":"2021-11-22","time":"23:08:50","level":"TRACE","file":"crash_test.c","line_number":17,"message":"Logging from logax"},
```



