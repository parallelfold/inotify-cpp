cmake_minimum_required(VERSION 3.8)
project(inotify-cpp)

if (INOTIFY_CPP_USE_CXX17)
    set (CMAKE_CXX_STANDARD 17)
endif()

add_subdirectory(src)

add_subdirectory(example)

enable_testing()
add_subdirectory(test)

