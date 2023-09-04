
find_package(cppzmq REQUIRED)

add_executable(hwclient)
target_link_libraries(hwclient PRIVATE cppzmq)
target_sources(hwclient PRIVATE src/hwclient.cpp)
