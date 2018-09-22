import QtQuick 2.5
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.2

ApplicationWindow
{
    title: qsTr("Qt5 QtQuick Demo")
    width: 640
    height: 480
    color: "whitesmoke"

    onClosing: main.shutdown()

    ColumnLayout
    {
        id: mainLayout
        anchors.fill: parent
        spacing: 16

        GroupBox
        {
            id: infoGroup
            Layout.fillWidth: true

            ColumnLayout
            {
                id: infoLayout
                anchors.fill: parent

                Label
                {
                    id: pythonVersion
                    text: "Python version: " + main.python_version
                }

                Label
                {
                    id: qtVersion
                    text: "Qt version: " + main.qt_version
                }
            }
        }

        GroupBox
        {
            id: connectGroup
            Layout.fillWidth: true

            GridLayout
            {
                id: connectLayout
                rows: 3
                columns: 3
                anchors.fill: parent
                flow: GridLayout.TopToBottom

                Label { text: "IP Address" }
                Label { text: "Publisher Port" }
                Label { text: "Router Port" }

                TextField
                {
                    id: connectIP
                    text: main.ip_address
                    Layout.fillWidth: true

                    Binding
                    {
                        target: main
                        property: "ip_address"
                        value: connectIP.text
                    }
                }
                TextField
                {
                    id: connectPubPort
                    text: main.pub_port
                    Layout.fillWidth: true

                    Binding
                    {
                        target: main
                        property: "pub_port"
                        value: connectPubPort.text
                    }
                }
                TextField
                {
                    id: connectRouterPort
                    text: main.router_port
                    Layout.fillWidth: true

                    Binding
                    {
                        target: main
                        property: "router_port"
                        value: connectRouterPort.text
                    }
                }

                Button
                {
                    id: connectButton
                    text: "Connect"

                    Layout.column: 3
                    Layout.rowSpan: 3
                    Layout.fillHeight: true

                    onClicked: main.connect()
                }

            }  // GridLayout
        }  // publishGroup

        GroupBox
        {
            id: publishGroup
            Layout.fillWidth: true

            GridLayout
            {
                id: publishLayout
                rows: 2
                columns: 3
                anchors.fill: parent
                flow: GridLayout.TopToBottom

                Label { text: "Topic" }
                Label { text: "Message" }

                TextField
                {
                    id: publishTopic
                    Layout.fillWidth: true

                    enabled: main.connected
                }
                TextField
                {
                    id: publishMessage
                    Layout.fillWidth: true

                    enabled: main.connected

                    MouseArea
                    {
                        id: messageMouseArea

                        anchors.fill: parent
                        acceptedButtons: Qt.RightButton
                        onClicked:
                        {
                            if (mouse.button === Qt.RightButton)
                            {
                                messageMenu.popup()
                            }
                        }  // onClicked

                        onPressAndHold:
                        {
                            if (mouse.source === Qt.MouseEventNotSynthesized)
                            {
                                messageMenu.popup()
                            }
                        }  // onPressAndHold

                        Menu
                        {
                            id: messageMenu
                            MenuItem
                            {
                                text: "Exit"
                                onTriggered: publishMessage.text = "{\"message\": \"EXIT\"}"
                            }
                            MenuItem
                            {
                                text: "Configure Acquisition"
                                onTriggered: publishMessage.text = "{\"message\": \"ACQ_CONFIG\", \"data\": {\"TestName\": \"Sample Test\", \"TopicUUID\": \"14bb1a5afd7a4a3490c48cff8a5d2230\", \"CubeConfigs\": [ { \"SerialNumber\": \"cube1sn\", \"CardConfigs\": [ { \"Slot\": 1, \"Channels\": [3, 4, 10, 13] }, { \"Slot\": 3, \"Channels\": [0, 1] }, { \"Slot\": 4, \"Channels\": [4, 5, 18] } ] } ], \"SamplingRate\": 500, \"AcqRate\": 10, \"MaxDuration\": 90 } }"
                            }
                            MenuItem
                            {
                                text: "Cancel Acquisition"
                                onTriggered: publishMessage.text = "{\"message\": \"CANCEL\"}"
                            }
                            MenuItem
                            {
                                text: "Start Acquisition"
                                onTriggered: publishMessage.text = "{\"message\": \"ACQ_START\"}"
                            }
                            MenuItem
                            {
                                text: "Start Logging"
                                onTriggered: publishMessage.text = "{\"message\": \"LOG_START\"}"
                            }
                            MenuItem
                            {
                                text: "Stop Logging"
                                onTriggered: publishMessage.text = "{\"message\": \"LOG_STOP\"}"
                            }
                            MenuItem
                            {
                                text: "Stop Acquisition"
                                onTriggered: publishMessage.text = "{\"message\": \"ACQ_STOP\"}"
                            }
                            MenuItem
                            {
                                text: "Recover Data"
                                onTriggered: publishMessage.text = "{\"message\": \"DATA_RECOVERY\"}"
                            }
                            MenuItem
                            {
                                text: "Test Complete"
                                onTriggered: publishMessage.text = "{\"message\": \"TEST_COMPLETE\"}"
                            }
                            MenuItem
                            {
                                text: "Send Status"
                                onTriggered: publishMessage.text = "{\"message\": \"SEND_STATUS\"}"
                            }

                        }  // messageMenu

                    }  // messageMouseArea
                }

                Button
                {
                    id: publishButton
                    text: "Publish"

                    enabled: main.connected

                    Layout.column: 3
                    Layout.rowSpan: 2
                    Layout.fillHeight: true

                    onClicked: main.publish(publishTopic.text, publishMessage.text)
                }

            }  // GridLayout
        }  // publishGroup

        Text
        {
            id: logBox
            Layout.fillHeight: true

            font.family: "Monospace"
            font.pointSize: 12

            text: main.log_text
        }  // logBox

    }  // ColumnLayout
}  // ApplicationWindow



