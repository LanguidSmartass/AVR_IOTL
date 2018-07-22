#[[
I can't quite get if it is ok for a non-interface (library with .cpp files) to be included inside another library
which is a pure INTERFACE (headers only), so I'll leave the commented section in case something goes wrong
]]
add_library(
        with_cpp
        STATIC
        header.hpp
        source.cpp
)
#add_library(
#        with_cpp
#        INTERFACE
#)
#target_sources(
#        with_cpp
#        INTERFACE
#        ${CMAKE_CURRENT_SOURCE_DIR}/header.hpp
#        ${CMAKE_CURRENT_SOURCE_DIR}/source.cpp
#)