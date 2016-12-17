# General project-wide config

SET(CMAKE_AUTOMOC ON)
SET(CMAKE_INCLUDE_CURRENT_DIR ON)

find_package(Qt5 COMPONENTS Widgets Core REQUIRED)

find_package(MOOS 10 REQUIRED)

########################################
# Build uMSv2
SET(BUILD_uMSv2 OFF CACHE BOOL "Build Graphical Tools (scope and playback)?")
IF(BUILD_uMSv2)
    ADD_SUBDIRECTORY(uMSv2)
ENDIF(BUILD_uMSv2)

ADD_SUBDIRECTORY(qMOOSTest)
