import QtQuick 2.9
import QtQuick.Controls 2.2

import "pages"

SwipeView {

    anchors.fill: parent

    SensorsPage {
        id: sensorsPage
    }

    StreamingPage {
        id: streamingPage
    }

    SettingsPage {
        id: settingsPage
    }
}
