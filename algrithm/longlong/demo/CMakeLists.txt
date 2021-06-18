add_executable(${PROJECT_NAME}_sort_test sort_test.cpp)
target_link_libraries(${PROJECT_NAME}_sort_test ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_util_test util_test.cpp)

add_executable(${PROJECT_NAME}_interview_test interview_test.cpp)
target_link_libraries(${PROJECT_NAME}_interview_test ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_heap_test heap_test.cpp)
target_link_libraries(${PROJECT_NAME}_heap_test ${PROJECT_NAME})

add_executable(${PROJECT_NAME}_stack_test stack_test.cpp)
target_link_libraries(${PROJECT_NAME}_stack_test ${PROJECT_NAME})