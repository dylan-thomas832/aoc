add_executable(
    22_d1_v1_p1
    part1.cpp
)
set_property(
    TARGET 22_d1_v1_p1
    PROPERTY
    OUTPUT_NAME run.exe
)
set_property(
    INSTALL run.exe
    PROPERTY
    CMAKE_INSTALL_PREFIX WORKING_DIRECTORY
)
