cmake_minimum_required(VERSION 2.8.3)

project(raycaster_engine)

add_executable(main src/main.cpp src/glad.c)

find_package(OpenGL REQUIRED)

include_directories($(OPENGL_INCUDE_DIRS))

find_package(glfw3 3.3 REQUIRED)

include_directories(
    include
    $(GLFW_INCLUDE_DIRS))
set(ENTITY_HEADER include/entity.h)
set(MAP_HEADER include/map.h)
set(PLAYER_HEADER include/player.h)
set(GAME_HEADER include/game.h)
set(SHADER_HEADER include/shader.h)
add_library(map src/map.cpp ${MAP_HEADER})
add_library(player src/player.cpp ${PLAYER_HEADER})
add_library(game src/game.cpp ${GAME_HEADER})
add_library(shader src/shader.cpp ${SHADER_HEADER})
add_library(entity src/entity.cpp ${ENTITY_HEADER})
add_library(color include/colorsettings.h)

add_library(X11 SHARED IMPORTED)
set_property(TARGET X11 PROPERTY IMPORTED_LOCATION "/usr/include/X11/Xlib.h")

add_library(dl SHARED IMPORTED)
set_property(TARGET dl PROPERTY IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libdl.so")

add_library(pthread SHARED IMPORTED)
set_property(TARGET pthread PROPERTY IMPORTED_LOCATION "/usr/include/pthread.h")

add_library(glad SHARED IMPORTED)
set_property(TARGET glad PROPERTY IMPORTED_LOCATION "/usr/include/glad/glad.h")

target_link_libraries(player entity color shader)

target_link_libraries(map entity player color shader)

target_link_libraries(game OpenGL::GL glfw GL X11 dl pthread glad map player game shader color)

target_link_libraries(main OpenGL::GL glfw GL X11 dl pthread glad map player game shader colorl)

set(DCMAKE_EXPORT_COMPILE_COMMANDS 1 )
set(DCMAKE_EXPORT_COMPILE_COMMANDS "${CMAKE_EXPORT_COMPILE_COMMANDS}" CACHE STRING "export compile_commands.json")
