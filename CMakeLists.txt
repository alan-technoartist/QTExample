# CMakeList.txt : CMake project for QTExample, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("QTExample")

find_package(Qt6 6.5 REQUIRED COMPONENTS Core Widgets)

# Habilitar herramientas de meta-compilación de Qt
set(CMAKE_AUTOMOC ON) 
set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTORCC ON)

# Add source to this project's executable.
add_executable (QTExample
"QTExample.cpp"
"QTExample.h"
"VentanaPrincipal.cpp"
"VentanaPrincipal.hpp"
"DialogoNuevoContacto.cpp"
"DialogoNuevoContacto.hpp")

target_link_libraries(QTExample PRIVATE Qt6::Core Qt6::Widgets)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET QTExample PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
