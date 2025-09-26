cmake_minimum_required(VERSION 3.10)

project(qbot_)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_C_STANDARD 11)

message(STATUS "CMake version: ${CMAKE_VERSION}")
message(STATUS "CMake Platform: ${CMAKE_SYSTEM_NAME}")
message(STATUS "CMake Generator: ${CMAKE_GENERATOR}")
message(STATUS "CMake Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "C Standard: ${CMAKE_C_STANDARD}")
message(STATUS "CMake C++ Compiler: ${CMAKE_CXX_COMPILER}")
message(STATUS "CMake C Compiler: ${CMAKE_C_COMPILER}")
message(STATUS "Project name: ${PROJECT_NAME}")

option(CMAKE_EXPERIMENTAL_COMPILE_CACHE "Enable compile cache" ON)

file(GLOB SRC
    ${CMAKE_SOURCE_DIR}/*.cpp
    ${CMAKE_SOURCE_DIR}/*.h
    ${CMAKE_SOURCE_DIR}/*.hpp
)

add_executable(${PROJECT_NAME})

add_subdirectory(src)
add_subdirectory(3rd)

target_sources(${PROJECT_NAME} PRIVATE 
    ${SRC}
)

target_include_directories(${PROJECT_NAME} PRIVATE 
    ${CMAKE_SOURCE_DIR}
    ${CMAKE_SOURCE_DIR}/3rd
)

target_link_libraries(${PROJECT_NAME} PRIVATE
    3rd
)

if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE 
        winmm
        wsock32
        ws2_32
    )
endif()

if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE "/bigobj")

elseif(MINGW OR MSYS OR GNU)
    target_compile_options(${PROJECT_NAME} PRIVATE "-Wa,-mbig-obj")
endif()

if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU")
    # GCC 需要链接 libstdc++fs
    target_link_options(${PROJECT_NAME}  PRIVATE "-static-libstdc++")
    # target_link_libraries(${PROJECT_NAME} PRIVATE stdc++fs)
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # Clang 通常使用 libc++，无需额外链接
    # 但如果使用 libstdc++，可能需要链接 stdc++fs
    if(NOT USING_LIBCXX)
        target_link_options(${PROJECT_NAME}  PRIVATE "-static-libstdc++")
        # target_link_libraries(${PROJECT_NAME} PRIVATE stdc++fs)
    endif()
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC 无需额外操作
endif()
