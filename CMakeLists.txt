
cmake_minimum_required(VERSION 3.12)
set(NAME choreodaemonic-robot-osc)

project(${NAME} CXX)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "-g -O0")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")
add_compile_options(-Wall)

# Build oscpack as a static library
add_library(oscpack STATIC
    lib/oscpack/osc/OscTypes.cpp
    lib/oscpack/osc/OscReceivedElements.cpp
    lib/oscpack/osc/OscPrintReceivedElements.cpp
    lib/oscpack/osc/OscOutboundPacketStream.cpp
    lib/oscpack/ip/IpEndpointName.cpp
    lib/oscpack/ip/posix/NetworkingUtils.cpp
    lib/oscpack/ip/posix/UdpSocket.cpp
)

target_include_directories(oscpack PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/lib/oscpack
)

# Add our executable
add_executable(${NAME}
    src/receive-robot-osc.cpp
)

# Include directories for our executable
target_include_directories(${NAME} PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Link against oscpack
target_link_libraries(${NAME} PRIVATE
    oscpack
)
