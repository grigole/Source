qt5_add_resources(graphics_SRCS resources.qrc)
add_executable(graphics main.cpp ${graphics_SRCS})
target_link_libraries(graphics Qt5::Qml Qt5::Gui)

