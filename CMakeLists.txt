# SPDX-License-Identifier: BSD-3-Clause
cmake_minimum_required(VERSION 3.16)
project(echoplugin LANGUAGES CXX)

# Set the example installation directory if not defined
if(NOT DEFINED INSTALL_EXAMPLESDIR)
    set(INSTALL_EXAMPLESDIR "examples")
endif()
set(INSTALL_EXAMPLEDIR "${INSTALL_EXAMPLESDIR}/widgets/tools/echoplugin")

# Find required Qt packages
find_package(Qt6 REQUIRED COMPONENTS Core Gui Widgets)

# Standard Qt project setup
qt_standard_project_setup()

# Define the main executable
qt_add_executable(echopluginwindow
    echointerface.h
    echowindow.cpp
    echowindow.h
    main.cpp
)

# Set executable properties
set_target_properties(echopluginwindow PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

# Link Qt libraries to the main executable
target_link_libraries(echopluginwindow PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
)

# Add the plugin directory as a subdirectory
add_subdirectory(plugin)

# Conditionally handle plugin linkage based on Qt's build type
if(QT6_IS_SHARED_LIBS_BUILD)
    add_dependencies(echopluginwindow echoplugin)  # Ensure echoplugin is built first in shared builds
else()
    target_link_libraries(echopluginwindow PRIVATE echoplugin)  # Link statically if Qt is static
endif()

# Install the main executable
install(TARGETS echopluginwindow
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)

