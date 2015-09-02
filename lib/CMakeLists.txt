# first we add the executable that generates the table
add_executable(MakeTable MakeTable.cpp)
 
MESSAGE(${CMAKE_CURRENT_BINARY_DIR})

# add the command to generate the source code
add_custom_command (
  OUTPUT ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  COMMAND MakeTable ${CMAKE_CURRENT_BINARY_DIR}/Table.h
  DEPENDS MakeTable
  )
 
# add the binary tree directory to the search path for 
# include files
include_directories( ${CMAKE_CURRENT_BINARY_DIR} )

# add the main library
ADD_LIBRARY(MathFunctions STATIC mysqrt.cpp ${CMAKE_CURRENT_BINARY_DIR}/Table.h)

install (TARGETS MathFunctions DESTINATION bin)
install (FILES mysqrt.h DESTINATION include)
