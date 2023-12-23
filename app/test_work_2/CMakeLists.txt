set(TARGET TestWork2)

set(SOURCES
    main.cpp
)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

find_package(Qt6 REQUIRED COMPONENTS Widgets Core Gui)

qt_standard_project_setup()

qt_add_executable(${TARGET} WIN32 ${SOURCES})

target_link_libraries(${TARGET} PRIVATE Qt6::Widgets Qt6::Core Qt6::Gui d3d12.lib)
