add_library(Core STATIC)

file(GLOB_RECURSE CORE_SOURCES CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.cpp")
file(GLOB_RECURSE CORE_HEADERS CONFIGURE_DEPENDS "${CMAKE_CURRENT_LIST_DIR}/Source/*.h")

target_sources(Core PRIVATE 
	${CORE_SOURCES} 
	${CORE_HEADERS} 
	"Source/Animation/AnimationStateMachine/AnimationStateMachine.cpp" 
	"Source/Animation/Animatable.cpp" 
	"Source/Audio/AudioSource.cpp"
	"Source/CoreObject/GameObject.cpp"
	"Source/CoreObject/Renderable.cpp" 
	"Source/Game/Game.cpp" 
	"Source/Patterns/Command/CommandInvoker.cpp" 
	"Source/Scene/Manager/SceneManager.cpp" 
	"Source/Scene/Layer.cpp" 
	"Source/Serialization/FileManager.cpp"
	"Source/UI/Button/UIButton.cpp"
	"Source/UI/UIComponent.cpp"
	"Source/UI/UILabel.cpp"
	"Source/Utils/FullScreenToggle.cpp"
)
target_include_directories(Core PUBLIC "${CMAKE_CURRENT_LIST_DIR}/Source")
target_link_libraries(Core PUBLIC raylib raygui fmt nlohmann_json)
target_compile_features(Core PUBLIC cxx_std_17)
set_target_properties(Core PROPERTIES LINKER_LANGUAGE CXX)
