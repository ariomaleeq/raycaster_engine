cmake_minimum_required(VERSION 2.8.3)

project(raycaster_engine)

add_executable(main src/main.cpp src/glad.c)

find_package(OpenGL REQUIRED)

include_directories($(OPENGL_INCUDE_DIRS))

find_package(glfw3 3.3 REQUIRED)
find_package(Boost REQUIRED COMPONENTS system)

include_directories(
    include
    $(GLFW_INCLUDE_DIRS) $(Boost INCLUDE_DIRS))
set(ENTITY_HEADER include/entity.h)
set(MAP_HEADER include/map.h)
set(PLAYER_HEADER include/player.h)
set(GAME_HEADER include/game.h)
set(SHADER_HEADER include/shader.h)
set(RAY_HEADER include/ray.h)
set(RENDERER_HEADER include/renderer.h)
set(MAP_RENDERER_HEADER include/maprenderer.h)
set(RAY_RENDERER_HEADER include/rayrenderer.h)
set(COLOR_HEADER include/colorsettings.h
    )
set(BACKGROUND_HEADER include/background.h)
set(STB_HEADER include/stb_image.h)
set(TEXTURE_HEADER include/texture.h)
set(SOUND_HEADER include/sound.h)
set(SDLAPP_HEADER include/SDLapp.h)

add_library(texture ${TEXTURE_HEADER} src/texture.cpp)
add_library(stb_image src/stb_image.cpp ${STB_HEADER})
add_library(background src/background.cpp ${BACKGROUND_HEADER})
add_library(map src/map.cpp ${MAP_HEADER})
add_library(player src/player.cpp ${PLAYER_HEADER})
add_library(game src/game.cpp ${GAME_HEADER})
add_library(shader src/shader.cpp ${SHADER_HEADER})
add_library(entity src/entity.cpp ${ENTITY_HEADER})
add_library(color src/colorsettings.cpp ${COLOR_HEADER})
add_library(ray src/ray.cpp ${RAY_HEADER})
add_library(renderer src/renderer.cpp ${RENDERER_HEADER})
add_library(maprenderer src/maprenderer.cpp ${MAP_RENDERER_HEADER})
add_library(playerrenderer src/playerrenderer.cpp include/playerrenderer.h)
add_library(rayrenderer src/rayrenderer.cpp ${RAY_RENDERER_HEADER})
add_library(sound src/sound.cpp ${SOUND_HEADER})
add_library(SDLapp src/SDLapp.cpp ${SDLAPP_HEADER})

add_library(X11 SHARED IMPORTED)
set_property(TARGET X11 PROPERTY IMPORTED_LOCATION "/usr/include/X11/Xlib.h")

add_library(dl SHARED IMPORTED)
set_property(TARGET dl PROPERTY IMPORTED_LOCATION "/usr/lib/x86_64-linux-gnu/libdl.so")

add_library(pthread SHARED IMPORTED)
set_property(TARGET pthread PROPERTY IMPORTED_LOCATION "/usr/include/pthread.h")

add_library(glad SHARED IMPORTED)
set_property(TARGET glad PROPERTY IMPORTED_LOCATION "/usr/include/glad/glad.h")

add_library(glm SHARED IMPORTED)
set_property(TARGET glm PROPERTY IMPORTED_LOCATION "/usr/include/glm/glm.hpp")

add_library(SDL SHARED IMPORTED)
set_property(TARGET SDL PROPERTY IMPORTED_LOCATION "/usr/local/lib/libSDL2.so")

target_link_libraries(sound SDL)
target_link_libraries(SDLapp SDL)
target_link_libraries(renderer shader texture stb_image)
target_link_libraries(rayrenderer renderer glm)
target_link_libraries(playerrenderer renderer stb_image)
target_link_libraries(background shader color)
target_link_libraries(maprenderer renderer)
target_link_libraries(ray renderer rayrenderer map entity player glm)
target_link_libraries(player entity color shader playerrenderer)

target_link_libraries(map entity player color shader maprenderer)

target_link_libraries(game OpenGL::GL glfw GL X11 dl pthread glad map player shader color ray renderer rayrenderer maprenderer playerrenderer background)

target_link_libraries(main OpenGL::GL glfw GL X11 dl pthread glad map player game shader color ${Boost_LIBRARIES} ray SDL sound SDLapp)

set(DCMAKE_EXPORT_COMPILE_COMMANDS 1 )
set(DCMAKE_EXPORT_COMPILE_COMMANDS "${CMAKE_EXPORT_COMPILE_COMMANDS}" CACHE STRING "export compile_commands.json")
