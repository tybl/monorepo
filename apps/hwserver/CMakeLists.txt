
find_package(cppzmq REQUIRED)

add_executable(hwserver)
target_link_libraries(hwserver PRIVATE cppzmq)
target_sources(hwserver PRIVATE src/hwserver.cpp)
