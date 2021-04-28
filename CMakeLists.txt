cmake_minimum_required(VERSION 3.20)

project(MatrixMultiplier VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(config.h.in config.h)

add_subdirectory(external/glm)

# add the executable
add_executable(${PROJECT_NAME} main.cpp)

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
target_include_directories(${PROJECT_NAME} 
        PUBLIC 
        ${PROJECT_BINARY_DIR}
        external/glm/glm
)

# This enables you to include your library without the path to the library. This is for header files.*
target_include_directories(${PROJECT_NAME} 
	PUBLIC 
        external/glm/glm
)

# This is for the actual source of your libraries, as opposed to header files.*
target_link_directories(${PROJECT_NAME}
	PRIVATE
        external/glm/glm
)

# Link library to project.
target_link_libraries(${PROJECT_NAME}
    PRIVATE
    glm::glm
)