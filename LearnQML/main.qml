import QtQuick 2.0
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3
import QtQuick.Dialogs 1.2

ApplicationWindow {
    id: thisWindow
    visible: true
    width: 640/2
    height: 1136/2
    title: qsTr("Basic English Grammar")

    property string selectedPage: ""

    header: ToolBar{
        id: toolBar
        visible: false
        RowLayout {
                   anchors.fill: parent
                   ToolButton {
                       contentItem: Image {
                           id: name
                           source: "icons/icon_back.png"
                       }
                       onClicked: {
                           stackView.pop()
                           if(stackView.currentItem.objectName == "StartPage"){
                               toolBar.visible = false
                           }
                       }

                   }
                   Label {
                       id: toolBarTitle
                       text: "Title"
                       elide: Label.ElideRight
                       horizontalAlignment: Qt.AlignHCenter
                       verticalAlignment: Qt.AlignVCenter
                       Layout.fillWidth: true
                   }
                   ToolButton {
                       text: qsTr("⋮")
                       onClicked: menu.open()
                   }
               }

    }

    StackView{
        id: stackView
        anchors.fill: parent
        initialItem: StartPage{
            btTheory.onClicked: {
                selectedPage = "TheoryPage.qml"
                toolBar.visible = true
                stackView.push("ListPage.qml")
            }

            btTest.onClicked: {
                selectedPage = "TestPage.qml"
                toolBar.visible = true
                stackView.push("ListPage.qml")
            }
        }
    }

}
