Copied from https://code.qt.io/cgit/qt/qtbase.git/tree/examples/widgets/tools/echoplugin/plugin?h=6.5. Put here for ease of use, and as an example on using Qt Plugins.

There are three separate branches here. Static, dynamic, and dynamic_likeQtAOG. 
The static is a statically loaded plugin example. Loaded at compilation. The dynamic branch is dynamically loaded(loaded from a .so file, at runtime). The dynamic_likeQtAOG is a dynamically loaded plugin example with the files structured like QTAOG, with the main application in the root dir, and the plugin in a "plugin" directory.
