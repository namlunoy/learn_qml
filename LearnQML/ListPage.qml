import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.LocalStorage 2.0

Item {
    property string title: "Lessons"
    objectName: "ListPage"

    anchors.fill: parent

    ListView{
        id: listLesson
    }


    Component.onCompleted: {
        loadDatabase()

    }

    function loadDatabase(){
        var db = LocalStorage.openDatabaseSync("data/basic_english_grammar.db","1.0","StorageDatabase","100000")
        db.transaction(
                    function(tx){
                        var rs = tx.executeSql("select * from Lesson")
                        console.log("count: ", rs.rows.length)
                    }
                    )


    }
}
