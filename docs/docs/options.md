
# Options

liblogax uses the bitwise arithmetic to manage the options and flags, the flag variable is defined as an int which is 32 bits on most platform hence any flag or option must not be more than 32 bit in size. There are 3 enum which are used to group the options, `LogaxOption`, `LogaxLevel` and `LogaxFormatter`.

## LogaxOption 

This enum is used to declare the basic options for the library, the bit size from (1 << 1) to (1 << 9) and (1 << 15>>) are used, (1 << 10) to (1 << 14) are reserved in case a new option is needed to be added. The following options are declared in the LogaxOption enum

- LOGAX_OPTION_QUITE
- LOGAX_OPTION_DATE
- LOGAX_OPTION_TIME
- LOGAX_OPTION_DATE_TIME
- LOGAX_OPTION_FILE_PATH
- LOGAX_OPTION_FILE_NAME_ONLY
- LOGAX_OPTION_LINE_NUMBER
- LOGAX_OPTION_COLORED
- LOGAX_OPTION_FUNCTION
- LOGAX_OPTION_ALL

### LOGAX_OPTION_QUITE

### LOGAX_OPTION_DATE

### LOGAX_OPTION_TIME

### LOGAX_OPTION_DATE_TIME

### LOGAX_OPTION_FILE_PATH

### LOGAX_OPTION_FILE_NAME_ONLY

### LOGAX_OPTION_LINE_NUMBER

### LOGAX_OPTION_COLORED

### LOGAX_OPTION_FUNCTION

### LOGAX_OPTION_ALL


