file(GLOB SRC
    ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp
    ${CMAKE_CURRENT_SOURCE_DIR}/*.h
    ${CMAKE_CURRENT_SOURCE_DIR}/*.hpp
)

add_library(qbot)

target_sources(qbot PRIVATE ${SRC})
target_include_directories(qbot PRIVATE 
    ${CMAKE_SOURCE_DIR}/3rd
)
