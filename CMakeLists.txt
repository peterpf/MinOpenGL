cmake_minimum_required (VERSION 3.0)
project (MyApp)
set (APPLICATION MyApp)

option (GLFW_BUILD_DOCS OFF)
option (GLFW_BUILD_EXAMPLES OFF)
option (GLFW_BUILD_TESTS OFF)
add_subdirectory (${APPLICATION}/vendor/glfw)

if (MSVC)
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /W4")
else ()
    set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -Wpedantic -std=c++11")
    if (NOT WIN32)
        set (GLAD_LIBRARIES dl)
    endif()
endif()

include_directories (
    ${APPLICATION}/headers/
    ${APPLICATION}/vendor/glad_files/include/
    ${APPLICATION}/vendor/glfw/include/
    )

file (GLOB VENDORS_SOURCES ${APPLICATION}/vendor/glad_files/src/glad.c)
file (GLOB PROJECT_HEADERS ${APPLICATION}/headers/*.hpp)
file (GLOB PROJECT_SOURCES ${APPLICATION}/src/*.cpp)
file (GLOB PROJECT_CONFIGS 
    CMakeList.txt
    README.md
    .gitignore
    .gitmodules
    )

source_group ("headers" FILES ${PROJECT_HEADERS})
source_group ("sources" FILES ${PROJECT_SOURCES})
source_group ("vendors" FILES ${VENDORS_SOURCES})

add_definitions (
    -DGLFW_INCLUDE_NONE
    -DPROJECT_SOURCE_DIR=\"${PROJECT_SOURCE_DIR}\"
    )
add_executable(
    ${PROJECT_NAME}
    ${PROJECT_SOURCES}
    ${PROJECT_HEADERS}
    ${PROJECT_CONFIGS}
    ${VENDORS_SOURCES}
    )
target_link_libraries(
    ${PROJECT_NAME} glfw 
    ${GLFW_LIBRARIES}
    ${GLAD_LIBRARIES}
    )
set_target_properties(
    ${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY
    ${CMAKE_BINARY_DIR}/${PROJECT_NAME}
    )
