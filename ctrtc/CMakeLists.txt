
project(ctrtc C CXX)

set(CMAKE_C_STANDARD 99)

include_directories(include)

add_compile_definitions(API_EXPORTS)

if(NOT MSVC)
    message(FATAL_ERROR "crtc module must be use msvc compiler")
endif()

file(GLOB SRC_CLASSES src/*.cpp)
file(GLOB PUBLIC_HEADER_FILES include/*.h)

add_library(ctrtc SHARED ${SRC_CLASSES})
set_target_properties(ctrtc PROPERTIES PUBLIC_HEADER "${PUBLIC_HEADER_FILES}")


install(TARGETS ctrtc)

file(GLOB TRTC_LIB_DLL_FILES ${TXLiteAVSDK_LIB_DIR}/*.dll)
install(FILES ${TRTC_LIB_DLL_FILES} DESTINATION bin)

