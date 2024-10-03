# ------ Set Options for Projects --------------- #
MESSAGE(STATUS "Set Options for Project")

## CMake minimum version required
CMAKE_MINIMUM_REQUIRED(VERSION 3.24)

## Set CXX Compiler Version
SET(CMAKE_CXX_STANDARD 17)

SET(PROJECT_NAME "NewGLTF")
PROJECT( ${PROJECT_NAME} )

MESSAGE(STATUS "Setting Done")
# ----------------------------------------------- #


# ------ Set Files ------------------------------ #
MESSAGE(STATUS "Set Source File")

SET(MAIN_DIR ${CMAKE_CURRENT_SOURCE_DIR})
SET(SRC_DIR ${MAIN_DIR}/src )

LIST(APPEND INCS
    ${MAIN_DIR}/include
)

## Source Files
LIST(APPEND SRCS
    ${SRC_DIR}/main.cpp

    ${MAIN_DIR}/include/IStreamLoader.h ${SRC_DIR}/IStreamLoader.cpp
)

ADD_EXECUTABLE( ${PROJECT_NAME} ${SRCS} )

MESSAGE(STATUS "Setting Done ")
# ----------------------------------------------- #



# ------ Set Variables for Dependency ----------- #
MESSAGE( STATUS "Setting Variables for Dependency")

OPTION( BUILD_STATIC_LIBRARY "Set option for the library which is static or dynamic" OFF )
OPTION( INSTALL_DEMO_FILE "Install demofile for memorymanager" OFF )
## Set Option for install lib, header files' path
SET( PREFIX_DIR ${MAIN_DIR}/build/Prefix CACHE PATH "Prefix Path" )
SET( INCLUDE_DIR ${MAIN_DIR}/build/include CACHE PATH "Header files Path" )
SET( ARC_DIR ${MAIN_DIR}/build/arc CACHE PATH "Archieve files Path" )
SET( LIB_DIR ${MAIN_DIR}/build/lib CACHE PATH "Library files Path" )
SET( BIN_DIR ${MAIN_DIR}/build/bin CACHE PATH "Execute files Path" )
SET( CMAKE_BUILD_TYPE Debug CACHE STRING "Build Type" )

INCLUDE( Dependency.cmake )

IF ( WIN32 )
    MESSAGE( STATUS "Windows Platform for library")
    SET( CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS 1 )
ENDIF()


MESSAGE( STATUS "Setting Done")
# ----------------------------------------------- #



# ------ Link LogProject on Target  ------------- #
MESSAGE(STATUS "Set Options for Target Files")

TARGET_INCLUDE_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${DEP_INCLUDE} ${INCS} )
TARGET_LINK_DIRECTORIES( ${PROJECT_NAME} PUBLIC ${LIB_DIR} ${DEP_LIB_DIR} )
TARGET_LINK_LIBRARIES( ${PROJECT_NAME} PUBLIC ${DEP_LIBS} opengl32.lib gdi32.lib )

MESSAGE(STATUS "${DEP_INCLUDE}")

MESSAGE(STATUS "Setting Done ")
# ----------------------------------------------- #