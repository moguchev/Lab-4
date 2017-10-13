cmake_minimum_required (VERSION 2.8)

include_directories(SYSTEM
    ./
)

# enum your files
add_executable(executable
                Classwork4.cpp 
)

target_link_libraries(executable)
