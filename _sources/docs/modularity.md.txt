
# Modularity

liblogax is big on modularity, each component of the library can be excluded at compile time. The following macros if defined will exclude some component from the library:

- LOGAX_USE_OLD_CONSOLE_MODE
- LOGAX_NO_OUTPUT_STREAM
- LOGAX_LOGGER_NO_OUTPUT_STREAM
- LOGAX_LOGGER_NO_CALLBACK
- LOGAX_NO_COLORING
- LOGAX_NO_TIME

## LOGAX_USE_OLD_CONSOLE_MODE

If this macro is define the library will use the Windows API to color the log outputs, this macro is only effective on Windows system. This macro is most useful for old windows platform which the console cannot process the ANSI Color Codes.

```
#define LOGAX_USE_OLD_CONSOLE_MODE
#include <exotic/logax.h>

//...
```

> Note that there might slight different in the color variation between using Windows Console attributes and ANSI Color codes

## LOGAX_NO_OUTPUT_STREAM

If this macro is defined the library will not be compiled with the writing to stream feature, both explicit write to streams function `logax_write_*_format_to_stream` and LogaxLogger loggers will not write to stream, but the callback will still be invoked is any is registered.

```c
#define LOGAX_NO_OUTPUT_STREAM
#include <exotic/logax.h>

//...
```

## LOGAX_LOGGER_NO_OUTPUT_STREAM

If this macro is defined the LogaxLogger struct will not be compiled with the writing to stream capability, but the explicit writing to stream functions `logax_write_*_format_to_stream` will be have the write to stream capability.

```c
#define LOGAX_LOGGER_NO_OUTPUT_STREAM
#include <exotic/logax.h>

//...
```

## LOGAX_LOGGER_NO_CALLBACK

Define this macro to exclude the callback and hook feature of the library, this does not affect the writing to output stream. You can still write the statement to register hook if needed but it ll have no effect unless this macro is removed.

```c
#define LOGAX_LOGGER_NO_CALLBACK
#include <exotic/logax.h>

//...
```

## LOGAX_NO_COLORING

If this macro is define the library will not be compiled with pretty print capability. The flag `LOGAX_OPTION_COLORED` will also not be available for use to customize the output.

```c
#define LOGAX_NO_COLORING
#include <exotic/logax.h>

//...
```

## LOGAX_NO_TIME

On a system that does not have floating point capability or the time headers are not available this macro can be defined to exclude adding data and time capability to the logging. Defining this macro will make the following macros unavailable `LOGAX_OPTION_DATE`, `LOGAX_OPTION_TIME`, `LOGAX_OPTION_DATE_TIME`.

```c
#define LOGAX_NO_TIME
#include <exotic/logax.h>

//...
```

