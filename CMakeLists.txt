CMAKE_MINIMUM_REQUIRED(VERSION 2.8)
PROJECT(application)


# does this system provide the log and exp functions?
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
check_function_exists (log HAVE_LOG)
check_function_exists (exp HAVE_EXP)


# The version number.
set (Tutorial_VERSION_MAJOR 1)
set (Tutorial_VERSION_MINOR 0)

option (USE_MYMATH "Use tutorial provided math implementation" ON)


# configure a header file to pass some of the CMake settings
# to the source code
configure_file ("${PROJECT_SOURCE_DIR}/src/TutorialConfig.h.in" "${PROJECT_BINARY_DIR}/TutorialConfig.h")

# add the binary tree to the search path for include files
# so that we will find TutorialConfig.h
include_directories("${PROJECT_BINARY_DIR}")


# configuration tests
INCLUDE(TestForSTDNamespace)
IF (CMAKE_NO_STD_NAMESPACE)
  MESSAGE(FATAL_ERROR "** El compilador no soporta std:: en clases STL")
ENDIF()
 
INCLUDE(CheckIncludeFileCXX)
CHECK_INCLUDE_FILE_CXX(iostream IS_OSTREAM)
 
IF(NOT IS_OSTREAM)
  MESSAGE(FATAL_ERROR "** No se encuentra la cabecera 'iostream'")
ENDIF()


# include (and compile) libraries
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/lib")
  add_subdirectory (lib) 
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# compiling and linking application
ADD_EXECUTABLE(executable src/source.cpp)
target_link_libraries (executable ${EXTRA_LIBS})

# installation directory
SET(CMAKE_INSTALL_PREFIX /home/ruben/usr)

# add the install targets
install (TARGETS executable DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/TutorialConfig.h" DESTINATION include)


### application tests
# does the usage message work?
add_test (executablelUsage executable)
set_tests_properties (executablelUsage
  PROPERTIES 
  PASS_REGULAR_EXPRESSION "Usage:.*number"
  )
 
 
#define a macro to simplify adding tests
macro (do_test arg result)
  add_test (executableComp${arg} executable ${arg})
  set_tests_properties (executableComp${arg}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result}
    )
endmacro (do_test)
 
# do a bunch of result based tests
do_test (4 "4 is 2")
do_test (9 "9 is 3")
do_test (5 "5 is 2.236")
do_test (7 "7 is 2.645")
do_test (25 "25 is 5")
do_test (-25 "-25 is 0")
do_test (0.0001 "0.0001 is 0.01")




# build a CPack driven installer package
include (InstallRequiredSystemLibraries)
set (CPACK_RESOURCE_FILE_LICENSE "${CMAKE_CURRENT_SOURCE_DIR}/License.txt")
set (CPACK_PACKAGE_VERSION_MAJOR "${Tutorial_VERSION_MAJOR}")
set (CPACK_PACKAGE_VERSION_MINOR "${Tutorial_VERSION_MINOR}")

# add the generation of a .deb package 
set (CPACK_PACKAGE_NAME "sqrt-app") # Nombre del paquete. Se convierte a minusculas. Obligatorio
set (CPACK_PACKAGE_VERSION  1.0) # Version del paquete. Obligatorio
set (CPACK_DEBIAN_PACKAGE_MAINTAINER "Ruben Gomez <ruben.gomez@enigmedia.es>") #required
set(CPACK_GENERATOR "DEB")

include (CPack)

