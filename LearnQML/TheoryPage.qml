import QtQuick 2.0
import QtQuick.Controls 2.2
import QtWebView 1.1

Item {
    id: item1
    objectName: "TheoryPage"
    property string title: "Lessons"

    Component.onCompleted: {
        var htmlContent = backend.getContent(myMainWindow.selectedLessonId)
        console.log(htmlContent)
        title = myMainWindow.selectedLessonTitle
        webView.loadHtml(htmlContent)
    }

    WebView{
        anchors.fill: parent
        id: webView
    }

    Button {
        id: button
        x: 235
        y: 322
        width: 48
        height: 48
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        background:  Image {
            id: image
            anchors.fill: parent
            source: "icons/icon_test.png"
        }

        onClicked: {
            stackView.push("TestPage.qml")
        }
    }

}
