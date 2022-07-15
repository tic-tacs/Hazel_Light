cmake_minimum_required(VERSION 3.21.4)

# Application Name and Platform
set(CMAKE_GENERATOR_PLATFORM x64)
set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_STANDARD 17)
project(Sandbox) 

# Link To Hazel
add_executable(${PROJECT_NAME} ./Sandbox/src/SandboxApp.cpp)
add_subdirectory(./Hazel)

# Set Output Directories
set_target_properties(${PROJECT_NAME} PROPERTIES ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin/${CMAKE_GENERATOR_PLATFORM})

target_link_libraries(${PROJECT_NAME} 
	PRIVATE HAZEL_LIGHT)
target_include_directories(${PROJECT_NAME} 
	PRIVATE "${PROJECT_SOURCE_DIR}/Hazel/src"
	)

# Copy Hazel dll on build
add_custom_command(
	TARGET ${PROJECT_NAME} POST_BUILD
	COMMAND ${CMAKE_COMMAND} -E copy_if_different
	"${PROJECT_BINARY_DIR}/Hazel/bin/${CMAKE_GENERATOR_PLATFORM}/${CMAKE_BUILD_TYPE}/HAZEL_LIGHT.dll"
	${PROJECT_BINARY_DIR}
	COMMENT "Copying Hazel dll into ${PROJECT_NAME} binary folder"
)

# Macro Definitions
add_compile_definitions(HZ_PLATFORM_WINDOWS)