cmake_minimum_required(VERSION 3.5)

project(atomic)
include_directories(/usr/include)
include_directories(/usr/include/glew/build/cmake/)
include_directories(/home/adam/glew-2.0.0/build)
include_directories(/home/adam/workspace/openGL/games/engine)
set(CMAKE_CXX_STANDARD 14)

find_package(GLEW REQUIRED COMPONENTS -lglew)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})

#add_subdirectory(lib)
add_executable(atomic src/main.cpp 
			   src/vertex_array.h		src/vertex_array.cpp
			   src/vertex_buffer.h		src/vertex_buffer.cpp
			   src/element_buffer.h		src/element_buffer.cpp
			   src/shader.h				src/shader.cpp
			   src/texture.h			src/texture.cpp
			   src/color.h				src/color.cpp
			   src/point.h				src/point.cpp
			   src/rectangle_parent.h	src/rectangle_parent.cpp
			   src/rectangle.h			src/rectangle.cpp
			   src/bordered_rectangle.h src/bordered_rectangle.cpp
			   src/square.h				src/square.cpp
			   src/window.h				src/window.cpp
			   )

target_link_libraries(atomic GLEW::GLEW)

set(GLFW_BUILD_DOCS		OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS	OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(/usr/include/glfw-3.2.1 bin)
add_subdirectory(/usr/include/glew/build/cmake bin2)
target_link_libraries(atomic glfw glew)

install(TARGETS "${PROJECT_NAME}" DESTINATION bin)
install(FILES "main.cpp" DESTINATION src)
