include($$PRI_PATH/defines.pri)

TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += $$SRC_PATH/receptor-bridge
receptor-bridge.subdir = $$SRC_PATH/receptor-bridge

SUBDIRS += $$SRC_PATH/simulator
simulator.subdir  = $$SRC_PATH/simulator
simulator.depends = receptor-bridge

SUBDIRS += $$EXTERNAL_PATH/libqamqp
libqamqp.subdir = $$EXTERNAL_PATH/libqamqp

SUBDIRS += $$SRC_PATH/emitter
emitter.subdir   = $$SRC_PATH/emitter
emitter.depends  = receptor-bridge simulator libqamqp
