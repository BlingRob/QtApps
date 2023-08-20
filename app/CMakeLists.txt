set(TARGET QtApplication)

set(SOURCES
    main.cpp
)

find_package(Qt6 REQUIRED COMPONENTS Widgets)

add_executable(${TARGET} ${SOURCES})
target_link_libraries(${TARGET} PRIVATE Qt6::Widgets)
