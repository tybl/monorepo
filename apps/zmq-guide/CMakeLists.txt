
find_package(cppzmq REQUIRED)

add_executable(hwclient)
target_link_libraries(hwclient PRIVATE cppzmq)
target_sources(hwclient PRIVATE src/hwclient.cpp)

add_executable(hwserver)
target_link_libraries(hwserver PRIVATE cppzmq)
target_sources(hwserver PRIVATE src/hwserver.cpp)
