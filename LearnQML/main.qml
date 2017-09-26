import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.3

ApplicationWindow {
    id: thisWindow
    visible: true
    width: 640/2
    height: 1136/2
    title: qsTr("Basic English Grammar")

    Text {
        id: txtTitle
        backgrou
        x: thisWindow/2 - width/2
        text: qsTr("Basic English Grammar")
        font.family: "Consolas"
    }


    Button{
        id: btTheory
        width:  100
        x: thisWindow.width/4 - width/2
        y: thisWindow.height/2 - height/2
        text: qsTr("Theory")
    }

    Button{
        id: btTest
        width: 100
        x: thisWindow.width*3/4 - width/2
        y: thisWindow.height/2 - height/2
        text: qsTr("Test")
    }

}
