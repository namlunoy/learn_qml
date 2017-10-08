import QtQuick 2.0
import QtQuick.Controls 2.2
import QtQuick.Dialogs 1.2

Item {
    id: item1
    objectName: "TestPage"
    property string title: ""
    property int stt: 0
    property int count: 0
    property variant questions: []
    property variant buttons: []
    property variant answers: []

    //------------- logic ------------

    Component.onCompleted: {
        count = 0
        title = myMainWindow.selectedLessonTitle
        buttons[0] = button1
        buttons[1] = button2
        buttons[2] = button3
        buttons[3] = button4
        buttons[4] = button5

        questions = backend.getAllQuestions(myMainWindow.selectedLessonId)

        stt = 0
        updateUI()
    }

    function updateUI(){
        if(stt < questions.length){
            console.log("Update Q-"+(stt+1)+" | id : " + questions[stt].id)

            txtContentQuestion.text = questions[stt].content
            txtStt.text = "Question " + (stt+1).toString() + ":"
            answers = []
            answers = backend.getAllAnswers(questions[stt].id)
            var i = 0;
            for(i = 0; i<answers.length; i++){
                buttons[i].visible = true;
                buttons[i].text = answers[i].content
            }

            for( ; i<5; i++){
                buttons[i].visible = false
            }
            stt++
        }else if(stt == questions.length){
            stt++
            dlgHint.title = "Result:"
            dlgHint.text = "" + count + "/" + questions.length
            dlgHint.open()

        }else{
            stackView.pop()
        }
    }

    function clickAnswer(num){
        if(answers[num].isCorrect){
            updateUI()
            count++
        }else{
            dlgHint.text = answers[num].hint
            dlgHint.open()
        }
    }

    //------------- logic ------------

    Text {
        id: txtStt
        text: "Question 01"
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.top: parent.top
        anchors.topMargin: 10
        font.pixelSize: 15
    }

    Text {
        id: txtContentQuestion
        height: 138
        text: qsTr("Noi dung cau hoi krjwkejrwer skdjfsjdf sdf sdkjfskdjfks djfs sdfkjsdfjskdfj sdkfj skdjfksdjf sdfkjskdjfs df ")
        wrapMode: Text.WordWrap
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: txtStt.bottom
        anchors.topMargin: 5
        anchors.left: parent.left
        anchors.leftMargin: 15
        font.pixelSize: 20
    }

    Button {
        id: button
        x: 235
        y: 322
        width: 38
        height: 38
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10

        background:  Image {
            id: image
            anchors.fill: parent
            source: "icons/icon_next.png"
        }

        onClicked: {
            console.log("Click Next!");
            updateUI()
        }
    }

    AnswerButton {
        id: button1
        y: 192
        onClicked: clickAnswer(0)
    }

    AnswerButton {
        id: button2
        y: 246
        onClicked: clickAnswer(1)
    }

    AnswerButton {
        id: button3
        y: 300
        onClicked: clickAnswer(2)
    }

    AnswerButton {
        id: button4
        y: 354
        onClicked: clickAnswer(3)
    }

    AnswerButton {
        id: button5
        y: 408
        onClicked: clickAnswer(4)
    }


    MessageDialog{
        id: dlgHint
        title: "Hint"
        onAccepted: updateUI()
    }

}
