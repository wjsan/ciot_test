# For more information about build system see
# https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html
# The following five lines of boilerplate have to be in your project's
# CMakeLists in this exact order for cmake to work correctly

cmake_minimum_required(VERSION 3.5)

set(CIOT_DIR ../ciot-c)
set(HDR_TYPES_DIR ../hdr_types_c)

if (UNIX)

    project(ciot_gnulinux)

    FILE(GLOB_RECURSE common ${CIOT_DIR}/src/common/*)
    FILE(GLOB_RECURSE mongoose ${CIOT_DIR}/src/mg/*)
    
    include_directories(
        ${CIOT_DIR}/src/mg
        ${CIOT_DIR}/include
        ${HDR_TYPES_DIR}/hg_types_c/include
        .
    )
    
    add_executable(${PROJECT_NAME}
        ${common}
        ${mongoose}
        main.c
    )
    

elseif (WIN32)

    project(ciot_win32)

    FILE(GLOB_RECURSE common ${CIOT_DIR}/src/common/*)
    FILE(GLOB_RECURSE mongoose ${CIOT_DIR}/src/mg/*)
    FILE(GLOB_RECURSE win ${CIOT_DIR}/src/win/*)

    include_directories(
        ${CIOT_DIR}/src/mg
        ${CIOT_DIR}/include
        ${HDR_TYPES_DIR}/hg_types_c/include
        .
    )

    add_executable(${PROJECT_NAME}
        ${common}
        ${mongoose}
        ${win}
        main.c
    )

    target_link_libraries(${PROJECT_NAME} ws2_32)

endif ()
