
find_package(SFML COMPONENTS graphics REQUIRED)
find_package(Threads REQUIRED)
add_executable(GUI main.cpp)
target_link_libraries(GUI sfml-graphics Threads::Threads)
