set(CMAKE_GENERATOR_PLATFORM x64)
project(HAZEL_LIGHT) #light version of the Hazel Game Engine By @TheCherno

add_library(${PROJECT_NAME} 
	./src/Hazel/Core.h
	./src/Hazel/Application.cpp
	./src/Hazel/Log.cpp
	./src/Hazel/EntryPoint.h
	./src/Hazel/Layer.cpp
	./src/Hazel/LayerStack.cpp
	./src/Hazel/Events/Event.h
	./src/Hazel/Events/ApplicationEvent.h
	./src/Hazel/Events/MouseEvent.h
	./src/Hazel/Events/KeyEvent.h
	./src/Hazel/Renderer/GraphicsContext.h
	./src/Hazel/ImGui/ImGuiBuild.cpp
	./src/Hazel/ImGui/ImGuiLayer.cpp
	./src/Hazel.h
	./src/Hazel/Window.h
	./src/Hazel/Input.h
	./src/Hazel/KeyCodes.h
	./src/Hazel/MouseButtonCodes.h
	./src/Platform/Windows/WindowsWindow.cpp
	./src/Platform/Windows/WindowsInput.cpp
	./src/Platform/OpenGL/OpenGLContext.cpp
)

target_precompile_headers(${PROJECT_NAME}
	PUBLIC	./src/hzpch.h)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})

# Engine Dependencies
add_subdirectory(./vendor/spdlog)
add_subdirectory(./vendor/glfw)
add_subdirectory(./vendor/glad)
add_subdirectory(./vendor/imgui)
add_subdirectory(./vendor/glm)

target_include_directories(${PROJECT_NAME}
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/spdlog/include"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/glfw/include"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/glad/include"
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/imgui"	
	PUBLIC "${PROJECT_SOURCE_DIR}/src/Hazel"
	PUBLIC "${PROJECT_SOURCE_DIR}/src"
)
target_link_directories(${PROJECT_NAME}
	PUBLIC "${PROJECT_BINARY_DIR}/vendor/spdlog/${CMAKE_BUILD_TYPE}"
	PUBLIC "${PROJECT_BINARY_DIR}/vendor/glfw/src/${CMAKE_BUILD_TYPE}"
)
target_link_libraries(${PROJECT_NAME}
	PUBLIC glad
	PUBLIC glfw3
	PUBLIC imgui
	PUBLIC spdlog
)

# Macro definitions
add_compile_definitions(HZ_PLATFORM_WINDOWS)
add_compile_definitions(HZ_BUILD_DLL)