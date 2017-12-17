include($$PRI_PATH/defines.pri)

TEMPLATE = subdirs
CONFIG  += ordered

SUBDIRS += $$SRC_PATH/receptor
receptor.subdir  = $$SRC_PATH/receptor

SUBDIRS += $$SRC_PATH/simulator
simulator.subdir  = $$SRC_PATH/simulator
simulator.depends = receptor

SUBDIRS += $$SRC_PATH/emitter
emitter.subdir   = $$SRC_PATH/emitter
emitter.depends  = receptor simulator
