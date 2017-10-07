import QtQuick 2.0

Item {
    id: item1
    objectName: "TestPage"
    property string title: ""

    Component.onCompleted: {
        title = myMainWindow.selectedLessonTitle
    }

    Text {
        id: txtStt
        text: "Question 01"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: 12
    }

    Text {
        id: txtContentQuestion
        height: 15
        text: qsTr("Noi dung cau hoi")
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: txtStt.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 15
        font.pixelSize: 12
    }



}
