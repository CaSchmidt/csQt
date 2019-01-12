macro(cs_test target)
  set(sources ${ARGN})
  add_executable(${target} ${sources})
  format_output_name(${target} ${target})
  target_include_directories(${target} PRIVATE
    ${csQt_SOURCE_DIR}/include
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
  target_link_libraries(${target} csQt)
  set_target_properties(${target} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${csQt_BINARY_DIR})
endmacro()

### Tests ####################################################################

set(CMAKE_AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms)

cs_test(test_imagetip include/imagetip.h src/imagetip.cpp src/test_imagetip.cpp)
cs_test(test_tree src/test_tree.cpp)
