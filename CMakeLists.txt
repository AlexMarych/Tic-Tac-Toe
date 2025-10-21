cmake_minimum_required(VERSION 3.22)
project(Tic-Tac-Toe CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

function(add_git_dependency libName gitURL gitTag)
    FetchContent_Declare(${libName}
        GIT_REPOSITORY ${gitURL}
        GIT_TAG        ${gitTag}
        GIT_SHALLOW    TRUE
        GIT_PROGRESS   TRUE
    )
    FetchContent_MakeAvailable(${libName})
    get_target_property(target_type ${libName} TYPE)
    if(target_type STREQUAL "INTERFACE_LIBRARY")
        target_compile_options(${libName} INTERFACE "-w")
    else()
        target_compile_options(${libName} PRIVATE "-w")
    endif()
endfunction()

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
set(BUILD_GAMES OFF CACHE BOOL "" FORCE)
add_git_dependency(raylib https://github.com/raysan5/raylib.git 5.5)

set(BUILD_RAYGUI_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_Declare(raygui
    GIT_REPOSITORY https://github.com/raysan5/raygui.git
    GIT_TAG 4.0
    GIT_SHALLOW TRUE
    GIT_PROGRESS TRUE
)
FetchContent_GetProperties(raygui)
if(NOT raygui_POPULATED)
    FetchContent_Populate(raygui)
    add_subdirectory(${raygui_SOURCE_DIR}/projects/CMake raygui)
    target_compile_options(raygui INTERFACE "-w")
endif()

add_git_dependency(fmt https://github.com/fmtlib/fmt.git 11.1.2)
add_git_dependency(nlohmann_json https://github.com/nlohmann/json.git v3.11.3)

add_subdirectory(Core)
add_subdirectory("Tic tac toe")

file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/sources/game/*.cpp")

if(CMAKE_CXX_COMPILER_ID MATCHES "MSVC")
    set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /ZI")
    set(CMAKE_SHARED_LINKER_FLAGS "${CMAKE_SHARED_LINKER_FLAGS} /SAFESEH:NO")
    set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} /SAFESEH:NO")
endif()
