cmake_minimum_required(VERSION 3.23)


# Disable in-source builds to prevent source tree corruption.
if(" ${CMAKE_SOURCE_DIR}" STREQUAL " ${CMAKE_BINARY_DIR}")
    message(FATAL_ERROR "
FATAL: In-source builds are not allowed.
       You should create a separate directory for build files.
")
endif()

project(ctrtc)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_INSTALL_PREFIX ${CMAKE_BINARY_DIR}/install)


message("${CMAKE_INSTALL_PREFIX}")

set(TRTC_ARCH Win64)
set(PROJECT_3RDParty_DIR "${CMAKE_CURRENT_SOURCE_DIR}/3rdparty")


include(3rdparty/TXLiteAVSDK/avsdk.cmake)

add_subdirectory(ctrtc)
add_subdirectory(example)

