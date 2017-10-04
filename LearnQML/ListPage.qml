import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.LocalStorage 2.0
import CongLibs 1.0

Item {
    property string title: "Lessons"
    objectName: "ListPage"

    anchors.fill: parent



    Component.onCompleted: {
       var lessons = backend.getAllLesson();
        console.log("Count: "+lessons.length);
        for(var idx = 0; idx < lessons.length; idx++)
        {
            //console.log(lessons[idx].title());
            listView.model.append({number: lessons[idx].id(), title: lessons[idx].title()});
        }

    }

    Backend{
        id: backend
    }

    ListModel{
        id: lessonModel
        ListElement{
            number: 1
            title: "bai 1"
        }
    }

    Component{
        id: lessonDelegate
        Row{
           spacing: 5
            Text{ text: number }
            Text{ text: title }
        }
    }


    ListView{
        anchors.fill: parent
        id: listView
        model: lessonModel
        spacing: 5
        delegate: lessonDelegate
    }

}
