cmake_minimum_required(VERSION 3.10)

project(A01)
find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(glfw3 REQUIRED FATAL_ERROR)
add_executable(A01 Assignment01.cpp)

target_include_directories (A01
    PUBLIC ${GLFW_INCLUDE_DIRS}
    PUBLIC ${SFML_INCLUDE_DIR}
    PUBLIC ${Vulkan_INCLUDE_DIRS}
)

include_directories(headers)
target_compile_features(A01 PRIVATE cxx_std_17)

target_link_libraries (A01 glfw)
target_link_libraries (A01 ${Vulkan_LIBRARIES})
target_link_libraries (A01 ${SFML_LIBRARIES})