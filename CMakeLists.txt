

###############################################################################
# CMake settings
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
# set project's name
PROJECT(CannyPF)

# this command finds OpenCV libraries and sets all required variables
FIND_PACKAGE(OpenCV REQUIRED)

FILE(GLOB_RECURSE HDRS_FILES src/*.h src/*.hpp)
FILE(GLOB_RECURSE SRCS_FILES src/*.c src/*.cpp)

ADD_EXECUTABLE(CannyPF ${SRCS_FILES} ${HDRS_FILES})
TARGET_LINK_LIBRARIES(CannyPF ${OpenCV_LIBS})
