import QtQuick 2.0
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.13
import Calculator 1.0

Button {
    property Root context: root

    Layout.fillWidth: true
    Layout.fillHeight: true

    onClicked: {
        if (text == "=")
            context.calculateInput();
        else if (text == "C")
            context.clearInput();
        else
            context.changeInput(text);
    }
}
