import QtQuick 2.9
import QtQuick.Controls 2.2

import "pages"

SwipeView {

    id: swipeView
    anchors.fill: parent

    SensorsPage {
        id: sensorsPage
        onNavigateTo: {
            swipeView.setCurrentIndex(pageIndex);
        }
        onLoadReceptor: {
            streamingPage.loadReceptor(receptorName, receptorProps)
        }
    }

    StreamingPage {
        id: streamingPage
    }

    SettingsPage {
        id: settingsPage
    }

    RegistrationPage {
        id: registrationPage
    }
}
