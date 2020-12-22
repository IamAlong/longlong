set(SOURCE sort.cpp
           interview.cpp)

message("building libalgrithm.so")
add_library(${PROJECT_NAME} SHARED ${SOURCE})