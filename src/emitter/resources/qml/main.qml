import QtQuick 2.9
import QtQuick.Controls 2.2
import QtQuick.Layouts 1.3

ApplicationWindow {
    visible: true
    width: 480
    height: 640
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height
    title: qsTr("ShiftRay Emitter")

    header: MainTabBar {
        id: mainTabBar
        currentIndex: mainSwipeView.currentIndex
    }

    MainSwipeView {
        id: mainSwipeView
        currentIndex: mainTabBar.currentIndex
    }
}
