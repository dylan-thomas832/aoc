# Create executable targets -- must have unique names
add_executable(
    22_d2_v2_p1
    part1.cpp
)

add_executable(
    22_d2_v2_p2
    part2.cpp
)

# Change output name. Target name must be unique, so this
#   allows less obtuse naming conventions. Only useful for
#   this specific configuration.
set_property(
    TARGET 22_d2_v2_p1
    PROPERTY
    OUTPUT_NAME run_part1.exe
)

set_property(
    TARGET 22_d2_v2_p2
    PROPERTY
    OUTPUT_NAME run_part2.exe
)

# Install the targets in place, which is bad 99% of the time
install(
    TARGETS 22_d2_v2_p1 22_d2_v2_p2
    RUNTIME
    DESTINATION ${CMAKE_CURRENT_SOURCE_DIR}
)
