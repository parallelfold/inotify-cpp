cmake_minimum_required(VERSION 3.8)
project(inotify-cppExample)

###############################################################################
# INOTIFY-CPP
###############################################################################
if(NOT TARGET inotify-cpp::inotify-cpp)
    find_package(inotify-cpp CONFIG REQUIRED)
endif()

if(NOT INOTIFY_CPP_USE_CXX17)
    ###############################################################################
    # Boost
    ###############################################################################
    find_package(
            Boost 1.54.0
            COMPONENTS unit_test_framework system filesystem
            REQUIRED
    )
    set(INOTIFY_CPP_ADDITIONAL_LIBS
        Boost::unit_test_framework
        Boost::system
        Boost::filesystem)
endif()

###############################################################################
# Thread
###############################################################################
find_package(Threads)

###############################################################################
# Target
###############################################################################
add_executable(inotify_example main.cpp)
target_link_libraries(inotify_example
        PRIVATE
        inotify-cpp::inotify-cpp
        ${INOTIFY_CPP_ADDITIONAL_LIBS}
        ${CMAKE_THREAD_LIBS_INIT})
