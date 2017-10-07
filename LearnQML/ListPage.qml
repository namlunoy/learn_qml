import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.LocalStorage 2.0

Item {
    property string title: "Lessons"
    objectName: "ListPage"

    anchors.fill: parent

    Component.onCompleted: {
        var lessons = backend.getAllLesson();
        console.log("Count: "+lessons.length);
        for(var idx = 0; idx < lessons.length; idx++){
            //console.log(lessons[idx].title());
            listView.model.append({number: lessons[idx].id(), title: lessons[idx].title()});
        }
    }

    ListView{
        focus: true
        clip: true
        anchors.fill: parent
        id: listView
        model: ListModel{}
        spacing: 5
        delegate: ItemDelegate{
            text: "Bai " + number + " : " + title
            width: parent.width
            onClicked: {
                listView.currentIndex = index
                console.log("aloha" + index + " - " + model.title)
                myMainWindow.selectedLessonId = model.number
                myMainWindow.selectedLessonTitle = model.title
                stackView.push(myMainWindow.selectedPage)
            }
        }
    }
}
