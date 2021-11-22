#!cmake CMakeLists.txt -G"Unix Makefiles"; make
cmake_minimum_required(VERSION 3.17)
project(libfio_tests VERSION 1.0)

set(FILE_EXT "")
set(INCLUDE_PATHS -I${PWD}/../../include/ -I${PWD}/../include/ -I../../include/ -I../include/)
include_directories(${PWD}/../../include/ ${PWD}/../include/ ../../include/ ../include/)
add_executable(logax_test ./empty_c_file.c)
set_target_properties(logax_test PROPERTIES RUNTIME_OUTPUT_DIRECTORY ./build/ )

IF (WIN32)
    set(FILE_EXT ".exe")
ENDIF()

# build and run the tests
file(GLOB files "./test_*.c" "./*/test_*.c" "./*/*/test_*.c")
foreach(filepath ${files})
    set(clang_m32 "-m32")
    message(STATUS "FilePath: " ${filepath}  )
    get_filename_component(filename ${filepath} NAME)
    get_filename_component(filenameonly ${filepath} NAME_WLE)
    #if(WIN32)
    #    set(clang_m32 "")
	#endif (WIN32)
    
    add_custom_target(${filenameonly}__
        
        COMMAND echo -------------------------------------------
        COMMAND echo Compiling ${filenameonly} 
        COMMAND echo -------------------------------------------
        
        # clang 
        COMMAND clang -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang${FILE_EXT}
        COMMAND clang -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_ansi${FILE_EXT}
        COMMAND clang++ -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_cpp${FILE_EXT}
        COMMAND clang++ -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_cpp_ansi${FILE_EXT}
        COMMAND clang ${clang_m32} -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_32${FILE_EXT}
        COMMAND clang ${clang_m32} -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_ansi_32${FILE_EXT}
        COMMAND clang++ ${clang_m32} -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_cpp_32${FILE_EXT}
        COMMAND clang++ ${clang_m32} -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_clang_cpp_ansi_32${FILE_EXT}
    
        # gcc
        COMMAND gcc -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc${FILE_EXT}
        COMMAND gcc -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_ansi${FILE_EXT}
        COMMAND g++ -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_cpp${FILE_EXT}
        COMMAND g++ -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_cpp_ansi${FILE_EXT}
        COMMAND gcc -m32 -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_32${FILE_EXT}
        COMMAND gcc -m32 -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_ansi_32${FILE_EXT}
        COMMAND g++ -m32 -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_cpp_32${FILE_EXT}
        COMMAND g++ -m32 -ansi -pedantic-errors -I. ${INCLUDE_PATHS} ${filepath} -o ./build/${filenameonly}_gcc_cpp_ansi_32${FILE_EXT}
    )
    
    add_custom_command(TARGET logax_test
        POST_BUILD
        
        COMMAND echo -------------------------------------------
        COMMAND echo Running ${filenameonly} 
        COMMAND echo -------------------------------------------
        
        # clang
        COMMAND ./build/${filenameonly}_clang${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_ansi${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_cpp${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_cpp_ansi${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_ansi_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_cpp_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_clang_cpp_ansi_32${FILE_EXT}
        
        # gcc
        COMMAND ./build/${filenameonly}_gcc${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_ansi${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_cpp${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_cpp_ansi${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_ansi_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_cpp_32${FILE_EXT}
        COMMAND ./build/${filenameonly}_gcc_cpp_ansi_32${FILE_EXT}
    )
    
    add_dependencies(logax_test ${filenameonly}__)
endforeach()

