import QtQuick 2.13
import QtQuick.Window 2.13
import QtQuick.Controls 2.5
import QtQuick.Controls.Universal 2.12
import QtQuick.Layouts 1.13
import Calculator 1.0

ApplicationWindow {
    Root { id: root }

    Universal.theme: Universal.Dark
    Universal.accent: Universal.Violet

    visible: true
    title: root.title
    x: Screen.width / 2 - width / 2
    y: Screen.height / 2 - height / 2
    width: 300
    height: 400
    minimumWidth: width
    minimumHeight: height
    maximumWidth: width
    maximumHeight: height


    GridLayout {
        anchors.fill: parent
        columnSpacing: 1
        rowSpacing: 1
        columns: 4
        rows: 5

        TextField {
            Layout.fillWidth: true
            Layout.columnSpan: 4
            Layout.column: 0
            Layout.row: 0

            padding: 10
            implicitHeight: 70
            enabled: false
            text: root.input
        }

        CButton {
            Layout.column: 0
            Layout.row: 1
            text: "7"
        }
        CButton {
            Layout.column: 1
            Layout.row: 1
            text: "8"
        }
        CButton {
            Layout.column: 2
            Layout.row: 1
            text: "9"
        }
        CButton {
            Layout.column: 3
            Layout.row: 1
            text: "/"
        }
        CButton {
            Layout.column: 0
            Layout.row: 2
            text: "4"
        }
        CButton {
            Layout.column: 1
            Layout.row: 2
            text: "5"
        }
        CButton {
            Layout.column: 2
            Layout.row: 2
            text: "6"
        }
        CButton {
            Layout.column: 3
            Layout.row: 2
            text: "*"
        }
        CButton {
            Layout.column: 0
            Layout.row: 3
            text: "1"
        }
        CButton {
            Layout.column: 1
            Layout.row: 3
            text: "2"
        }
        CButton {
            Layout.column: 2
            Layout.row: 3
            text: "3"
        }
        CButton {
            Layout.column: 3
            Layout.row: 3
            text: "-"
        }
        CButton {
            Layout.column: 0
            Layout.row: 4
            text: "C"
        }
        CButton {
            Layout.column: 1
            Layout.row: 4
            text: "0"
        }
        CButton {
            Layout.column: 2
            Layout.row: 4
            text: "="
        }
        CButton {
            Layout.column: 3
            Layout.row: 4
            text: "+"
        }
    }
}
