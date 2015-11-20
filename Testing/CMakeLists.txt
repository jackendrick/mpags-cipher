
add_executable(testHello testHello.cpp)
add_test(NAME test-hello COMMAND testHello)


add_executable(testCatch testCatch.cpp)
target_include_directories(testCatch PRIVATE ${CMAKE_CURRENT_LIST_DIR})
add_test(NAME test-catch COMMAND testCatch)
