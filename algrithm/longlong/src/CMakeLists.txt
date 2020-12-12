set(SOURCE sort.cpp)

message("building libalgrithm.so")
add_library(${PROJECT_NAME} SHARED ${SOURCE})