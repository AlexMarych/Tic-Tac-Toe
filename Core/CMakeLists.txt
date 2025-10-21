add_library(Core STATIC)

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.cpp")
file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.hpp")

target_sources(Core PRIVATE ${CORE_SOURCES} ${CORE_HEADERS})
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Source")
target_link_libraries(Core PUBLIC raylib raygui fmt nlohmann_json)
target_compile_features(Core PUBLIC cxx_std_17)
set_target_properties(Core PROPERTIES LINKER_LANGUAGE CXX)
