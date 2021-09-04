import QtQuick 2.11
import QtQuick.Controls 2.4
import QtQml.Models 2.3

ApplicationWindow {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    onClosing: main.shutdown()

    ComboBox {
        currentIndex: 2
        model: ListModel {
            id: cbItems
            ListElement { text: "Banana"; color: "Yellow" }
            ListElement { text: "Apple"; color: "Green" }
            ListElement { text: "Coconut"; color: "Brown" }
        }
        width: 200
        onCurrentIndexChanged: console.debug(cbItems.get(currentIndex).text + ", " + cbItems.get(currentIndex).color)
    }
}
