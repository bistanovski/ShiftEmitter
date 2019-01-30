TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += $$PWD/qtmqtt/src
src.subdir = $$PWD/qtmqtt/src

# Copy libQt5Mqtt.so and links into target library directory
copylibrary.commands = cp $$ROOT_BUILD/external/libqtmqtt/qtmqtt/lib/libQt5Mqtt.so* $$ROOT_BUILD/libs
first.depends = $(first) copylibrary
export(first.depends)
export(copylibrary.commands)
QMAKE_EXTRA_TARGETS += first copylibrary
