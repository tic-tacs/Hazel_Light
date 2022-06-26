set(CMAKE_GENERATOR_PLATFORM x64)
project(HAZEL_LIGHT) #light version of the Hazel Game Engine By @TheCherno

add_library(${PROJECT_NAME} SHARED 
	./src/Hazel/Application.cpp
	./src/Hazel/Log.cpp
	./src/Hazel/EntryPoint.h
	./src/Hazel/Events/Event.h
	./src/Hazel/Events/ApplicationEvent.h
	./src/Hazel/Events/MouseEvent.h
	./src/Hazel/Events/KeyEvent.h
	./src/Hazel.h
)

set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})

# Engine Dependencies
add_subdirectory(./vendor/spdlog)
target_include_directories(${PROJECT_NAME}
	PUBLIC "${PROJECT_SOURCE_DIR}/vendor/spdlog/include"
	PRIVATE "${PROJECT_SOURCE_DIR}/src/Hazel"
)
target_link_directories(${PROJECT_NAME}
	PRIVATE "${PROJECT_BINARY_DIR}/vendor/spdlog/${CMAKE_BUILD_TYPE}"
)
target_link_libraries(${PROJECT_NAME}
	PRIVATE spdlog
)

# Macro definitions
add_compile_definitions(HZ_PLATFORM_WINDOWS)
add_compile_definitions(HZ_BUILD_DLL)