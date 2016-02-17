cmake_minimum_required (VERSION 2.6)
project (pas_lab1)

add_definitions( -D_VERBOSE_MODE_)

set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

include_directories("${PROJECT_BINARY_DIR}/include")

#Make a library from the classes
add_library(mdp_action src/action.cpp)
add_library(mdp_state src/state.cpp)

add_executable(pas_lab1 src/main.cpp)
target_link_libraries(pas_lab1 mdp_state mdp_action)