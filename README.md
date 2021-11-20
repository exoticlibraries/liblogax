
![](https://github.com/exoticlibraries/liblogax/raw/main/docs/liblogax.png)

# liblogax

Blazing fast, simple and modular header-only logging library with zero allocation for C and C++, implemented in C90. Allow logging into various output formats such as Key-Value and JSON.

Time and space are very important concepts in programming, a logging library should slow down the program or add to the memory ussage hence why logax's API is designed with speed and modularity in mind, each components can be removed to adjust to an environment or increase compile/runtime speed by defining the [exclusion macro](#exclusion-macros) for that component.

```c
#include <exotic/logax.h>

int main(int argc, char **argv) {
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_TRACE, "%s", "This is a trace output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_DEBUG, "%s", "This is a debug output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_INFO, "%s", "This is an info output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_WARN, "%s", "This is a warning output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_ERROR, "%s", "This is an error output");
	logax_write_text_format_to_stream(stdout, LOGAX_OPTION_ALL | LOGAX_LEVEL_FATAL, "%s", "This is a fatal output");
}
```

Output

![](https://raw.githubusercontent.com/exoticlibraries/exoticlibraries.github.io/main/assets/images/liblogax/crash_test_output.png)


The log oputput can be formatted to the following output [text](#text), [key value](#key_value) and [json](#json), and in case where the output is not required or the platform does not have any output stream (e.g. andruino, stm32) a callback can be registered that will receive the log event to be processed whichever way.

___

## Table of content
- [Features](#features)
- [Standards Compliance and Portability](#standards-compliance-and-portability)
- [Installation](#installation)
    - [Install](#install)
        - [Windows](#windows)
        - [Unix, Linux, Mac](#unix-linux-mac)
        - [Other platforms](#other-platforms)
- [Documentation](#documentation)
- [Usage](#usage)
    - [Logging without LogaxLogger](#logging-without-logaxLogger)
    - [Logging with LogaxLogger](#logging-with-logaxLogger)
		- [Initialize LogaxLogger](#initialize-logaxLogger)
		- [LogaxLogger Loggers](#logaxLogger-loggers)
    - [Callbacks](#callbacks)
    - [Output Formats](#output-formats)
		- [Text](#text)
		- [Key Value](#key-value)
		- [JSON](#json)
- [Modularity](#modularity)
- [How it works](#how-it-works)
- [Contributing](#contributing)
- [References](#references)
- [License](#license)

## Features

- Single header only, just download logax.h and you are good to go.
- Speed. logax was developed with speed and zero performance intrusion in mind.
- Modular, excluded un-used features from your test, [modularity](https://exoticlibraries.github.io/liblogax/docs/modularity.html).
- Zero allocation, No memory allocation.
- Levelled logging to customize and differenciate the outputs.
- Support for callbacks and hooks.
- Very portable, compatiple with ANSI C and C++98 without any trade off in functionalities.
- Output log in text, key-value and JSON encoding formats.
- Pretty logging for all supported output formats.
- Simple method to achive options in the logging system using bitwise operations.
- Detail docuentation with examples and API references.

## Standards Compliance and Portability

The project is compliant with the original C language specification ISO/IEC 9899:1990 and the first POSIX specification IEEE Std 1003.1-1988 which ensures the project compatibility in various environments.

Even though the project is designed for C, but also works with C++ as it is compatible with C++98 Standard (ISO/IEC 14882:1998), C++03 Standard (ISO/IEC 14882:2003) and C++11 Standard (ISO/IEC 14882:2011).

The project can be used with any C or C++ compiler. There are optional macros and options that can be used to attain the desired output in the case of undesired results.

## Installation

If you install the library file `logax.h` using any of the commands below, it can be included in your test like `<exotic/logax.h>`.

### Windows

Install the library using powershell. It auto detect your insalled C and C++ compilers include directory and install liblogax into the include folder. Execute the command in powershell as admin.

```powershell
& $([scriptblock]::Create((New-Object Net.WebClient).DownloadString("https://exoticlibraries.github.io/magic/install.ps1"))) liblogax
```

### Unix, Linux, Mac

Use the remote installation script to install liblogax with bash. If the command is executes with super user priviledge (sudo) it will be installed in the folder /usr/include else it will be installed in the folder /usr/local/include. Or you can specify where to install it using the option `--installfolder=./` 

```bash
bash <(curl -s https://exoticlibraries.github.io/magic/install.sh) liblogax
```

### Other platforms

You can simply download the header file `logax.h` from the repo into your project source folder and include it in your project. Download the file from [here](https://github.com/exoticlibraries/liblogax/blob/main/include/exotic/logax.h). Then you can include it in your test relatively like `#include "logax.h"`.

## Documentation

The [documentation](https://exoticlibraries.github.io/liblogax/docs/) provides several examples, tutorials, and detailed guides for using the library. While [reference](https://exoticlibraries.github.io/liblogax/reference/) provides a low-level overview of all the implemented APIs in the library. 

Some of the documentation pages are listed below:

 - [Logging without LogaxLogger](https://exoticlibraries.github.io/liblogax/docs/logging_without_logaxlogger.html)
 - [Logging with LogaxLogger](https://exoticlibraries.github.io/liblogax/docs/logging_with_logaxlogger.html)
 - [Modularity](https://exoticlibraries.github.io/liblogax/modularity.html)
 - [Logging levels](https://exoticlibraries.github.io/liblogax/logging_levels.html)
 - [Output Formats](https://exoticlibraries.github.io/liblogax/docs/output_formats.html)
 - [Callback and Hook](https://exoticlibraries.github.io/liblogax/docs/callback.html)
 - [Options](https://exoticlibraries.github.io/liblogax/docs/options.html)
 - [How it works](https://exoticlibraries.github.io/liblogax/how_it_works/index.html)

## Usage
it allows the log to be reported to custom function with optional printing to output stream. The default maximum number of callback that can be registered is 5.

### Logging without LogaxLogger

### Logging with LogaxLogger

#### Initialize LogaxLogger

#### LogaxLogger Loggers

### Callbacks

### Output Formats

#### Text

#### Key Value

#### JSON

## Modularity

## How it works

These three internal functions are responsible for the actual logging to output stream,
- logax_write_text_format_to_stream
- logax_write_key_value_format_to_stream
- logax_write_json_format_to_stream

The functions accept variadic parameters, the first 3 parameters are culmpulsory and the followed X parameters are for the vfprintf function for formating. The first parameter is the output stream `FILE *`, the second parameters is the flags to customize the outputs, the third parameter is the fmt to processes the variadic values. 

`LogaxLogger` struct allows logging properties and output stream to be shared across function calls, it internally uses the 3 functions above to otput the log. The special feature of LogaxLogger is the callback. On new log entry all the registered callbacks are invoked with the log event. 

See the pages at [how it works](https://exoticlibraries.github.io/liblogax/how_it_works/index.html) for more explanation.

## Contributing

If you have any issue or you want to request a feature you can open a request [here](https://github.com/exoticlibraries/liblogax/issues/new/choose) anytime and if you made some changes that should be added to the main project send in a [pull request](https://github.com/exoticlibraries/liblogax/compare). 

## References

 - [ANSI C](https://en.wikipedia.org/wiki/ANSI_C)
 - [Exotic Libraries](https://exoticlibraries.github.io/)
 - [Author](https://thecarisma.github.io/)
 - <a target="_blank" href="https://icons8.com/icon/84401/login">Login</a> icon by <a target="_blank" href="https://icons8.com">Icons8</a>

## License

MIT License Copyright (c) 2021, Adewale Azeez 
