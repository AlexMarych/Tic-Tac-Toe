file(GLOB_RECURSE GAME_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.cpp" "${CMAKE_CURRENT_LIST_DIR}/Source/*.h")

add_executable(Tic-Tac-Toe ${GAME_SOURCES})


target_include_directories(Tic-Tac-Toe PRIVATE "${CMAKE_CURRENT_LIST_DIR}/Source")
target_link_libraries(Tic-Tac-Toe PRIVATE Core raylib raygui fmt nlohmann_json)
target_compile_features(Tic-Tac-Toe PRIVATE cxx_std_17)

target_compile_definitions(Tic-Tac-Toe PUBLIC
    $<$<CONFIG:Debug>:ASSETS_PATH="${CMAKE_SOURCE_DIR}/assets/">
    $<$<CONFIG:Release>:ASSETS_PATH="./assets/">
)

if(WIN32 AND MSVC)
    set_target_properties(Tic-Tac-Toe PROPERTIES
        LINK_FLAGS_RELEASE "/SUBSYSTEM:WINDOWS /ENTRY:mainCRTStartup"
    )
endif()

set_target_properties(Tic-Tac-Toe PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY_DEBUG   "${CMAKE_BINARY_DIR}/bin/Debug"
    RUNTIME_OUTPUT_DIRECTORY_RELEASE "${CMAKE_BINARY_DIR}/bin/Release"
)
