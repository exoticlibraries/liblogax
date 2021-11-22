
# How it works

These three internal functions are responsible for the actual logging to output stream,
- logax_write_text_format_to_stream
- logax_write_key_value_format_to_stream
- logax_write_json_format_to_stream

The functions accept variadic parameters, the first 3 parameters are culmpulsory and the followed X parameters are for the vfprintf function for formating. The first parameter is the output stream `FILE *`, the second parameters is the flags to customize the outputs, the third parameter is the fmt to processes the variadic values. 

`LogaxLogger` struct allows logging properties and output stream to be shared across function calls, it internally uses the 3 functions above to otput the log. The special feature of LogaxLogger is the callback. On new log entry all the registered callbacks are invoked with the log event. 

See the pages at [how it works](https://exoticlibraries.github.io/liblogax/how_it_works/index.html) for more explanation.


(too lazy to continue)

