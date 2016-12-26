CMAKE_MINIMUM_REQUIRED (VERSION 3.4)

PROJECT (wsimg VERSION 0.0.1)

SET(BUILD_TESTING flase)


IF(PROJECT_ROOT_DIR)
ELSE()
    SET(PROJECT_ROOT_DIR ${PROJECT_SOURCE_DIR})
ENDIF()

#指定头文件路径-----------------------------------------
INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/deps)

INCLUDE_DIRECTORIES(${PROJECT_SOURCE_DIR}/include)

#读取Src目录--------------------------------------------
AUX_SOURCE_DIRECTORY(src DIR_SRCS)

#编译文件-----------------------------------------------
ADD_LIBRARY(${PROJECT_NAME} ${DIR_SRCS})
ADD_EXECUTABLE(wsimg_test ${PROJECT_SOURCE_DIR}/test/wsimg_test.c)

#输出路径-----------------------------------------------
SET(LIBRARY_OUTPUT_PATH ${PROJECT_ROOT_DIR}/build/bin)
SET(EXECUTABLE_OUTPUT_PATH ${PROJECT_ROOT_DIR}/build/bin/test/)

#链接库-------------------------------------------------
TARGET_LINK_LIBRARIES(wsimg_test ${PROJECT_NAME})

#设置编译选项-------------------------------------------
IF(WIN32)
    # DEBUG RELEASE
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -Wall")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -Wall")

ELSEIF(APPLE)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -m64 -O0 -Wall -g")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -m64 -O3 -Wall")

ELSEIF(UNIX)
    SET(CMAKE_CXX_FLAGS_DEBUG "$ENV{CXXFLAGS} -m64 -O0 -Wall -g")
    SET(CMAKE_CXX_FLAGS_RELEASE "$ENV{CXXFLAGS} -m64 -O3 -Wall")
ENDIF()
