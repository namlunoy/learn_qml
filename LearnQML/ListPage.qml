import QtQuick 2.0
import QtQuick.Controls 2.2

Item {
    id: thisItem
    anchors.fill: parent
    Rectangle{
        color: "#A00000"
        anchors.fill: parent
    }

    Text {
        id: title
        text: qsTr("ListPage")
    }

    Button{
        text: "click me"
        onClicked: thisItem.visible = false
    }
}
