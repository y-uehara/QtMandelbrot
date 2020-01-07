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

    property point dragStart: Qt.point(0, 0)

    Connections
    {
        target: fractalDrawer
        onRedrawNeeded:
        {
            // redraw
            drawnImage.source = "image://fractalDrawer/" + Math.random()
        }
    }

    Image
    {
        id: drawnImage
        height: 960
        width: 960
        anchors.top: parent.top
        anchors.left: parent.left

        source: "image://fractalDrawer/hoge"

        MouseArea
        {
            anchors.fill: parent
            hoverEnabled: true
            onPressed:
            {
                dragStart.x = mouse.x
                dragStart.y = mouse.y

                dragFrame.x = mouse.x
                dragFrame.y = mouse.y
                dragFrame.width = 1
                dragFrame.height = 1
                dragFrame.visible = true
            }
            onReleased: { dragFrame.visible = false }
            onPositionChanged:
            {
                mouseRe = fractalDrawer.getRe(mouse.x)
                mouseIm = fractalDrawer.getIm(mouse.y)

                if(pressed)
                {
                    dragFrame.x = Math.min(dragStart.x, mouse.x)
                    dragFrame.y = Math.min(dragStart.y, mouse.y)
                    dragFrame.width = Math.abs(dragStart.x - mouse.x)
                    dragFrame.height = Math.abs(dragStart.y - mouse.y)
                }
            }
        }
    }
    Item
    {
        id: inputPain
        anchors.top: parent.top
        anchors.right: parent.right
        width: parent.width - drawnImage.width
        height: parent.height


        ColumnLayout
        {
            anchors.top: parent.top
            width: parent.width
            spacing: 10

            Text
            {
                Layout.topMargin: 10
                Layout.alignment: Qt.AlignCenter
                text: qsTr("Coordinates")
            }
            RowLayout
            {
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 10
                Text { text: qsTr("Real min") }
                TextField
                {
                    id: realMin
                    text: fractalDrawer.minX
                    onEditingFinished: { fractalDrawer.minX = parseFloat(text) }
                }
            }
            RowLayout
            {
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 10
                Text { text: qsTr("Real max") }
                TextField
                {
                    id: realMax
                    text: fractalDrawer.maxX
                    onEditingFinished: { fractalDrawer.maxX = parseFloat(text) }
                }
            }
            RowLayout
            {
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 10
                Text { text: qsTr("Imaginary min") }
                TextField
                {
                    id: imaginaryMin
                    text: fractalDrawer.minY
                    onEditingFinished: { fractalDrawer.minY = parseFloat(text) }
                }
            }
            RowLayout
            {
                Layout.alignment: Qt.AlignRight
                Layout.rightMargin: 10
                Text { text: qsTr("Imaginary max") }
                TextField
                {
                    id: imaginaryMax
                    text: fractalDrawer.maxY
                    onEditingFinished: { fractalDrawer.maxY = parseFloat(text)    }
                }
            }
            Button
            {
                Layout.alignment: Qt.AlignCenter
                text: qsTr("Reset")
            }

            Text
            {
                Layout.topMargin: 10
                Layout.alignment: Qt.AlignCenter
                text: qsTr("Zooming")
            }
            RowLayout
            {
                Layout.alignment: Qt.AlignCenter
                Button
                {
                    text: qsTr("Zoom In")
                    onClicked:
                    {
                        fractalDrawer.zoomIn()
                    }
                }
                Button
                {
                    text: qsTr("Zoom Out")
                    onClicked:
                    {
                        fractalDrawer.zoomOut()
                    }
                }
            }
        }
        Text
        {
            anchors.bottom: parent.bottom
            id: positionIndicator
            text: "position: " + mouseRe + " + " + mouseIm + "i"
        }
    }

    // drag frame
    Rectangle
    {
        id: dragFrame
        visible: false
        x: 100; y: 100
        width: 1; height: 1
        color: "#00000000"
        border.color: "white"
        border.width: 1
    }
}
