# Build example
add_executable(aufgaben
  aufgabe2bis4.cpp)
target_link_libraries(aufgaben
  glfw
  ${GLFW_LIBRARIES}
  m)
add_dependencies(aufgaben glfw ${COPY_BINARY})

# Build tests
add_executable(tests
  aufgabe10.cpp)
target_link_libraries(tests
)
