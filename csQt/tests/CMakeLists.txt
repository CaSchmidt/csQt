macro(cs_test target)
  set(sources ${ARGN})
  add_executable(${target} ${sources})
  format_output_name(${target} ${target})
  target_compile_definitions(${target} PRIVATE
    QT_NO_CAST_FROM_ASCII
    QT_NO_CAST_TO_ASCII
    )
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

cs_test(test_hl include/ProxyDelegate.h src/ProxyDelegate.cpp src/test_hl.cpp)
cs_test(test_imagetip include/imagetip.h src/imagetip.cpp src/test_imagetip.cpp)
cs_test(test_tree src/test_tree.cpp)
