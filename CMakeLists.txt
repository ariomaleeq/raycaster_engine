cmake_minimum_version(VERSION 2.8.3)

project(raycaster_engine)

add_executable(main.cpp src/main.cpp src/glad.c)

find_package(OpenG REQUIRED)

incude_directories($(OPENG_INCUDE_DIRS))

find_package(glfw 3.3 REQUIRED)


add_library(X11 SHARED IMPORTED)
set_property(TARGET X11 PROPERTY IMPROTED_LOCATION "/usr/include/X11/Xlib.h")

add_library(dl SHARED IMPORTED)
set_property(TARGET dl PROPERTY IMPORTED_LOCATION "usr/lib/x86_64-linux-gnu/libdl.so")

add_library(pthread SHARED IMPORTED)
set_property(TARGET pthread PROPERTY IMPORT_LOCATION "usr/lib/include/pthread.h")

add_library(glad SHARED IMPORTED)
set_property(TARGET glad PROPERTY IMPORTED_LOCATION "usr/include/glad/glad.h")

target_link_libraries(main OpenGL::GL glfw GL X11 dl pthread glad)
