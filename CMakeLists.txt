cmake_minimum_required(VERSION 3.19 FATAL_ERROR)

project(ysff 
    VERSION 2.3
    LANGUAGES C
)

file(GLOB_RECURSE HEADERS ${PROJECT_SOURCE_DIR}/inc/${PROJECT_NAME}/*.h)
file(GLOB_RECURSE SOURCES ${PROJECT_SOURCE_DIR}/src/*.c)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} "main.c")

target_include_directories(${PROJECT_NAME} PUBLIC ${PROJECT_SOURCE_DIR}/inc)
set_target_properties(${PROJEC_NAME} PROPERTIES C_STANDARD 23)