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


    Connections
    {
        target: fractalDrawer
        onRedrawNeeded:
        {
            // redraw
            drawnImage.source = "image://fractalDrawer/" + Math.random()
        }
    }

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
                onPressed:
                {
                    dragFrame.x = mouse.x
                    dragFrame.y = mouse.y
                    dragFrame.visible = true
                }
                onReleased: { dragFrame.visible = false }
                onPositionChanged:
                {
                    mouseRe = fractalDrawer.getRe(mouse.x)
                    mouseIm = fractalDrawer.getIm(mouse.y)

                    if(pressed)
                    {
                        // TODO: drag
                    }
                }
            }
        }
        ColumnLayout
        {
            id: inputPain

            spacing: 5
            Text
            {
                text: qsTr("Coordinates")
            }
            RowLayout
            {
                Text { text: qsTr("Real min") }
                TextField
                {
                    id: realMin
                    text: fractalDrawer.minX
                    onEditingFinished: { fractalDrawer.minX = parseFloat(text)    }
                }
            }
            RowLayout
            {
                Text { text: qsTr("Real max") }
                TextField
                {
                    id: realMax
                    text: fractalDrawer.maxX
                    onEditingFinished: { fractalDrawer.maxX = parseFloat(text)    }
                }
            }
            RowLayout
            {
                Text { text: qsTr("Imaginary min") }
                TextField
                {
                    id: imaginaryMin
                    text: fractalDrawer.minY
                    onEditingFinished: { fractalDrawer.minY = parseFloat(text)    }
                }
            }
            RowLayout
            {
                Text { text: qsTr("Imaginary max") }
                TextField
                {
                    id: imaginaryMax
                    text: fractalDrawer.maxY
                    onEditingFinished: { fractalDrawer.maxY = parseFloat(text)    }
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
                    }
                }
                Button
                {
                    text: "Zoom Out"
                    onClicked:
                    {
                        fractalDrawer.zoomOut()
                    }
                }
            }
            Text
            {
                id: positionIndicator
                text: "position: " + mouseRe + " + " + mouseIm + "i"
            }
        }
    }

    // drag frame
    Rectangle
    {
        id: dragFrame
        visible: false
        x: 100; y: 100
        width: 100; height: 100
        color: "#00000000"
        border.color: "white"
        border.width: 1
    }
}
