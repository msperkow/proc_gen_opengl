include_directories(imgui)

include_directories(${SDL2_INCLUDE_DIR})
include_directories(${SDL2_INCLUDE_DIR}/SDL2)
include_directories(${GLEW_INCLUDE_DIR})

set(
        IMGUI_SRC

        imgui/imgui.cpp
        imgui/imgui_draw.cpp
        imgui/imgui_widgets.cpp
        imgui/backends/imgui_impl_sdl.cpp
        imgui/backends/imgui_impl_opengl3.cpp
)
set(IMGUI_SRC ${IMGUI_SRC})
add_library(imgui ${IMGUI_SRC})

add_subdirectory(glm)

if (CMAKE_BUILD_TYPE MATCHES Debug)
    add_subdirectory(googletest)
endif()