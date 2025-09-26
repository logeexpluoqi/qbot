file(GLOB_RECURSE SRC
    *.c
    *.cpp
    *.h
)

add_library(qshell STATIC
    ${SRC}
)