if (UNIX AND NOT APPLE)
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++20")
endif()

if (NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
  message(STATUS "setting build type to 'Debug' as none specified")
  set(CMAKE_BUILD_TYPE Debug
    CACHE STRING "choose the type of build" FORCE)
  set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug" "Release")
endif()

find_program(CCACHE ccache)
if (CCACHE)
  message(STATUS "using ccache")
  set(CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE})
else()
  message(STATUS "ccache not found")
endif()

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

option(DEBUG "enable debug statements" OFF)
if (DEBUG OR CMAKE_BUILD_TYPE STREQUAL "Debug")
  add_compile_definitions(APP_DEBUG APP_ENABLE_ASSERTS APP_PROFILE)
endif()

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
  set(CMAKE_CXX_EXTENSIONS OFF)
  set_property(GLOBAL PROPERTY USE_FOLDERS ON)
  include(CTest)
endif()
