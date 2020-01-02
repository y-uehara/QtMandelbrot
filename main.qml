import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.12
import QtQuick.Layouts 1.12

Window
{
    visible: true
    width: 1280
    height: 960
    title: qsTr("Hello Fractal")

    property double mouseRe: 0.0
    property double mouseIm: 0.0

    RowLayout
    {
        anchors.fill: parent
        spacing: 5
        Image
        {
            id: drawnImage
            Layout.maximumHeight: 960
            Layout.maximumWidth: 960
            //width: 960
            //height: 960
            //source: "qrc:/images/tree.jpg"
            source: "image://fractalDrawer/hoge"

            MouseArea
            {
                anchors.fill: parent
                hoverEnabled: true
                onPositionChanged:
                {
                    mouseRe = fractalDrawer.getRe(mouse.x)
                    mouseIm = fractalDrawer.getIm(mouse.y)
                }
            }
        }
        ColumnLayout
        {
            id: inputPain
            anchors.top: parent.top
            anchors.topMargin: 10

            spacing: 5
            Text
            {
                anchors.horizontalCenter: parent.horizontalCenter
                text: qsTr("Coordinates")
            }
            RowLayout
            {
                Text { text: qsTr("Real min") }
                TextField
                {
                    id: realMin
                    text: fractalDrawer.minX
                }
            }
            RowLayout
            {
                Text { text: qsTr("Real max") }
                TextField
                {
                    id: realMax
                    text: fractalDrawer.maxX
                }
            }
            RowLayout
            {
                Text { text: qsTr("Imaginary min") }
                TextField
                {
                    id: imaginaryMin
                    text: fractalDrawer.minY
                }
            }
            RowLayout
            {
                Text { text: qsTr("Imaginary max") }
                TextField
                {
                    id: imaginaryMax
                    text: fractalDrawer.maxY
                }
            }
            RowLayout
            {
                Button
                {
                    text: "Zoom In"
                    onClicked:
                    {
                        fractalDrawer.zoomIn()
                        drawnImage.source = "image://fractalDrawer/" + Math.random()
                    }
                }
                Button
                {
                    text: "Zoom Out"
                    onClicked:
                    {
                        fractalDrawer.zoomOut()
                        drawnImage.source = "image://fractalDrawer/" + Math.random()
                    }
                }
            }
            Text
            {
                id: positionIndicator
                anchors.bottom: inputPain.bottom
                anchors.right: inputPain.right
                text: "position: " + mouseRe + " + " + mouseIm + "i"
            }
        }
    }
}
