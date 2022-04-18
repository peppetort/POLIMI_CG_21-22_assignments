cmake_minimum_required(VERSION 3.10)

project(A00)
find_package(Vulkan REQUIRED FATAL_ERROR)
find_package(glfw3 REQUIRED FATAL_ERROR)
add_executable(A00 Assignment0.cpp)

target_include_directories (A00
    PUBLIC ${GLFW_INCLUDE_DIRS}
    PUBLIC ${SFML_INCLUDE_DIR}
    PUBLIC ${Vulkan_INCLUDE_DIRS}
)

include_directories(headers)
target_compile_features(A00 PRIVATE cxx_std_17)

target_link_libraries (A00 glfw)
target_link_libraries (A00 ${Vulkan_LIBRARIES})
target_link_libraries (A00 ${SFML_LIBRARIES})