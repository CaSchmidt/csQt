cmake_minimum_required(VERSION 3.2 FATAL_ERROR)

### Project ##################################################################

project(csQt)

# Build Tests?
option(ENABLE_TESTS "Enable tests" OFF)

### Modules ##################################################################

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
include(FormatOutputName)

### Dependencies #############################################################

find_package(Qt5Widgets 5.6 REQUIRED)

### csQt #####################################################################

set(csQt_HEADERS
  include/csQt/csAbstractTreeItem.h
  include/csQt/csCollapser.h
  include/csQt/csColumnResizer.h
  include/csQt/csDialogButtonBox.h
  include/csQt/csFontResizer.h
  include/csQt/csHighlightingDelegate.h
  include/csQt/csImageTip.h
  include/csQt/csItemSearcher.h
  include/csQt/csMultiToolButton.h
  include/csQt/csNamespace.h
  include/csQt/csProgressLineEdit.h
  include/csQt/csQtUtil.h
  include/csQt/csSubstringHighlighter.h
  include/csQt/csTableCopier.h
  include/csQt/csTreeModel.h
  include/csQt/csqt_config.h
  include/QtCreator/HighlightingItemDelegate.h
  )

set(csQt_SOURCES
  src/csAbstractTreeItem.cpp
  src/csCollapser.cpp
  src/csColumnResizer.cpp
  src/csDialogButtonBox.cpp
  src/csFontResizer.cpp
  src/csHighlightingDelegate.cpp
  src/csImageTip.cpp
  src/csItemSearcher.cpp
  src/csMultiToolButton.cpp
  src/csProgressLineEdit.cpp
  src/csQtUtil.cpp
  src/csSubstringHighlighter.cpp
  src/csTableCopier.cpp
  src/csTreeModel.cpp
  src/QtCreator/HighlightingItemDelegate.cpp
  )

### Target ###################################################################

add_definitions(-DQT_NO_CAST_FROM_ASCII -DQT_NO_CAST_TO_ASCII)

add_library(csQt SHARED
  ${csQt_HEADERS} ${csQt_SOURCES}
  )

target_link_libraries(csQt Qt5::Widgets)

format_output_name(csQt "csQt")

target_compile_definitions(csQt PRIVATE CS_BUILD_QT_LIB)
target_include_directories(csQt PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(csQt PROPERTIES
  AUTOMOC ON
  AUTORCC ON
  AUTOUIC ON
  AUTOUIC_SEARCH_PATHS ${CMAKE_CURRENT_SOURCE_DIR}/forms
  )

install(TARGETS csQt
  ARCHIVE DESTINATION lib
  LIBRARY DESTINATION lib
  RUNTIME DESTINATION bin
  )

install(DIRECTORY include/
  DESTINATION include
  PATTERN "internal" EXCLUDE
  )

### Tests ####################################################################

if(ENABLE_TESTS)
  add_subdirectory(tests)
endif()
