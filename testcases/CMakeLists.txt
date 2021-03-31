# Sources that contain the tests
add_executable(catch2Test testmain.cpp) # Just this one contains BOOST_TEST_MAIN
target_sources(catch2Test PRIVATE
        #testMyFraction.cpp
        test_linkedlist.cpp)

# Libraries used in the tests
target_link_libraries(catch2Test)

# Including headers
target_include_directories(catch2Test PRIVATE
        ../headers) # Including this allows to simply write #include "funcs.h"

# Including sources
target_sources(catch2Test PRIVATE
        ../headers_files/linked_list.cpp)

#target_compile_options(catch2Test PRIVATE -Wa,-mbig-obj) # Solves assembler error of file too big
