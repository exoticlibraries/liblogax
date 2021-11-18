/*!gcc {0} -I. -I../include/ -o out; ./out --cester-verbose */

#include <exotic/cester.h>
#include <exotic/logax.h>

CESTER_TEST(test_stdout, test_inst, 
    //CESTER_CAPTURE_STDOUT();

    int options = 0;
	//options = LOGAX_OPTION_DATE_TIME >> options;
	options = LOGAX_OPTION_DATE | LOGAX_OPTION_TIME;

	//printf("%d->%d\n", options, options & LOGAX_OPTION_DATE);
	//logax_write_to_stream(stdout, options, "Log%s\n", "Yahoo");

    //CESTER_RELEASE_STDOUT();
)
