import QtQuick 2.9
import ShiftRayReceptor 1.0

ShiftReceptor {

    OrientationReceptor {

        Component.onCompleted: {
            connectReceptor();
            startListening();
        }

        onReadingChanged: {
            readingText = "Reading from: " + new Date().toLocaleTimeString(Qt.locale("de_DE"))
        }
    }
}
