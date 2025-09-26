add_subdirectory(qshell)

add_library(3rd INTERFACE)

target_link_libraries(3rd INTERFACE
    qshell
)
