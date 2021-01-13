set(SOURCE sort.cpp
           interview.cpp)

message("building libalgorithm.so")
add_library(${PROJECT_NAME} SHARED ${SOURCE})