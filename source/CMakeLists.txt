# Build example
add_executable(aufgabe2bis4 aufgabe2bis4.cpp)
target_link_libraries(aufgabe2bis4 m)

add_executable(aufgabe5 aufgabe5.cpp)
target_link_libraries(aufgabe5 m)

add_executable(bsp bsp.cpp)
target_link_libraries(bsp m)

add_executable(aufgabe7 aufgabe7.cpp circle.cpp vec2.cpp mat2.cpp)




# Build tests
#add_executable(tests tests.cpp )
#target_link_libraries(tests m)


	