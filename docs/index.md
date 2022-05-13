


.. toctree::
   :hidden:
   :glob:
   :maxdepth: 1
   :caption: Documentation
   :name: docs-nav

   /docs/*


.. toctree::
   :hidden:
   :glob:
   :maxdepth: 1
   :caption: How it works
   :name: docs-how_it_works

   /how_it_works/*


liblogax is a blazing fast, simple and modular header-only logging library with zero allocation for C and C++, implemented in C90. Allow logging into various output formats such as Key-Value and JSON.

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

![liblogax test result](https://raw.githubusercontent.com/exoticlibraries/exoticlibraries.github.io/main/assets/images/liblogax/crash_test_output.png)

## Features

- Single header only, just download logax.h and you are good to go.
- Speed. logax was developed with speed and zero performance intrusion in mind.
- Modular, excluded un-used features from your test, [modularity](https://exoticlibraries.github.io/liblogax/docs/modularity.html).
- Zero allocation, No memory allocation.
- Levelled logging to customize and differentiate the outputs.
- Support for callbacks and hooks.
- Very portable, compatible with ANSI C and C++98 without any trade off in functionalities.
- Output log in text, key-value and JSON encoding formats.
- Pretty logging for all supported output formats.
- Simple method to achieve options in the logging system using bitwise operations.
- Detail documentation with examples and API references.

## Installation

If you install the library file `logax.h` using any of the commands below, it can be included in your test like `<exotic/logax.h>`.

### Windows

Install the library using powershell. It auto detect your installed C and C++ compilers include directory and install liblogax into the include folder. Execute the command in powershell as admin.

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

