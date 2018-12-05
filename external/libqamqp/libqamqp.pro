TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += $$PWD/qamqp/src
src.subdir = $$PWD/qamqp/src

# Copy libqamqp.so and links into target library directory
copylibrary.commands = cp $$ROOT_BUILD/external/libqamqp/qamqp/src/libqamqp.so* $$ROOT_BUILD/libs
first.depends = $(first) copylibrary
export(first.depends)
export(copylibrary.commands)
QMAKE_EXTRA_TARGETS += first copylibrary
