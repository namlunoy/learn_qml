import QtQuick 2.0
import QtQuick.Layouts 1.3
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2
import CongLibs 1.0

Item {
    objectName: "StartPage"

    property int count: 0
    property alias btTest: btTest
    property alias btTheory: btTheory

    anchors.fill: parent
    ColumnLayout{
        id: layTitle
        anchors.top: parent.top
        anchors.topMargin: 22
        anchors.horizontalCenter: parent.horizontalCenter

        Backend{
            id: backend
            onUserNameChanged: {
                count++
                txtTitle_English.text = userName
            }
        }

        TitleText {
            id: txtTitle_Basic
            text: "Basic"
        }

        TitleText {
            id: txtTitle_English
            text: "English"
        }

        TitleText {
            id: txtTitle_Grammar
            text: "Grammar"
        }
    }

    Button{
        id: btTheory
        width:  100
        x: parent.width/4 - width/2
        y: parent.height/2 - height/2
        text: qsTr("Theory")
        font.family: "Courier"

    }

    Button{
        id: btTest
        width: 100
        x: parent.width*3/4 - width/2
        y: parent.height/2 - height/2
        text: qsTr("Test")
        font.family: "Courier"

    }

    Button{
        id: btQuestion
        width: 50
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        background: Image {
            id: imgQuestion
            source: "icons/icon_question_mark.png"
        }
        onClicked: {
            dlgQuestion.open()
        }
    }


    MessageDialog{
        id: dlgQuestion
        title: "About"
        text: "This app was made for testing!\nBut it still does the job!"
    }

}
