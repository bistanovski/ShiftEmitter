linux:!android {
    include($$PRI_PATH/platform/linux.pri)
}

android {
    include($$PRI_PATH/platform/android.pri)
}

macx {
    include($$PRI_PATH/platform/mac.pri)
}

windows {
    include($$PRI_PATH/platform/windows.pri)
}
