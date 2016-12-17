cmake_minimum_required(VERSION 2.8.11)

set(CMAKE_CXX_FLAGS
  "${CMAKE_CXX_FLAGS} ${Qt5Widgets_EXECUTABLE_COMPILE_FLAGS}"
  )

SET(SRC_FILES
  qMOOSObject.cpp
  window.cpp
  main.cpp
  )

include_directories(
  ${MOOS_INCLUDE_DIRS}
  ${MOOS_DEPEND_INCLUDE_DIRS}
  ${Qt5Widgets_INCLUDES}
  ${Qt5Core_INCLUDES}
  )

add_executable(  qMOOSTest
  ${SRC_FILES}
  )

target_link_libraries(  qMOOSTest
  ${MOOS_LIBRARIES}
  ${MOOS_DEPEND_LIBRARIES}
  Qt5::Widgets
  Qt5::Core
  )
