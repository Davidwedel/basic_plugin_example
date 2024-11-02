# Copyright (C) 2022 The Qt Company Ltd.
# SPDX-License-Identifier: BSD-3-Clause

qt_add_executable(echoproject
    echointerface.h
    echowindow.cpp echowindow.h
    main.cpp
)

set_target_properties(echoproject PROPERTIES
    WIN32_EXECUTABLE TRUE
    MACOSX_BUNDLE TRUE
)

target_link_libraries(echoproject PRIVATE
    Qt6::Core
    Qt6::Gui
    Qt6::Widgets
    p_echoplugin
)

#if(QT6_IS_SHARED_LIBS_BUILD)
    # Build the shared plugin too when building this example target.
#    add_dependencies(echoproject echoplugin)
#else()
    # Link the echoplugin if Qt is built statically.
#    target_link_libraries(echoproject PRIVATE
#        echoplugin
#    )
#endif()

install(TARGETS echoproject
    RUNTIME DESTINATION "${INSTALL_EXAMPLEDIR}"
    BUNDLE DESTINATION "${INSTALL_EXAMPLEDIR}"
    LIBRARY DESTINATION "${INSTALL_EXAMPLEDIR}"
)
