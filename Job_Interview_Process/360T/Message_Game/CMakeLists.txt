cmake_minimum_required(VERSION 3.10)
project(Message_Game)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add the executable
add_executable(Message_Game
    src/main.cpp
    src/player.cpp
)

# Include directories
target_include_directories(Message_Game PRIVATE
    ${PROJECT_SOURCE_DIR}/include
)

# Custom clean target
add_custom_target(clean-all
    COMMAND ${CMAKE_COMMAND} -E remove_directory ${CMAKE_BINARY_DIR}
    COMMENT "Removing build directory and all contents"
)