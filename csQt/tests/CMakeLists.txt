macro(cs_test target)
  set(sources ${ARGN})
  add_executable(${target} ${sources})
  format_output_name(${target} ${target})
  target_include_directories(${target}
    PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
    )
  target_link_libraries(${target} csQt)
  set_target_properties(${target} PROPERTIES
    AUTOMOC ON
    AUTORCC ON
    AUTOUIC ON
    AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms
    )
endmacro()

### Tests ####################################################################

cs_test(test_hl include/hlModel.h include/ProxyDelegate.h src/hlModel.cpp src/ProxyDelegate.cpp src/test_hl.cpp)
cs_test(test_imagetip include/imagetip.h src/imagetip.cpp src/test_imagetip.cpp)
cs_test(test_tree src/test_tree.cpp)
