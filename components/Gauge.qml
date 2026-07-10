import QtQuick 2.9
import QtQuick.Controls 2.12

import "../settings/colors.js" as Color

Item {
    width: visibleTicks ? 60 : 40
    height: 320

    property real min: 0
    property real max: 50
    property bool fLimMin: true
    property bool fLimMax: true
    property real limMin: 10
    property real limMax: 40
    property real value: 15.88

    property string indicatorMainColor: Color.BLUE1
    property color indicatorLightColor: "#fd5656"// Light color for the Thermometer used to create gradient
    property string lblColor: Color.GRAY_TEXT1
    property string tickColor: Color.GRAY_4

    property real tickInterval: 10
    property real tickStep: 5
    property int tickLength: 10
    property int scaleFontPixelSize: 15
    property string scaleFontFamily: "Ubuntu Condensed"
    property string scaleFontStyle: "normal"
    property string scaleFontColor: Color.GRAY_4
    property string scaleFontLimColor: Color.RED

    readonly property real heightAdjustment: scaleFontPixelSize/2
    readonly property real offset: (height - heightAdjustment*2) / (max - min)

    property int indicatorWidth: 25
    property bool firstPaint: true
    property bool visibleTicks: true

    onValueChanged: { canvas.requestPaint(); }

    Canvas{
        id: canvas
        width: parent.width
        height: parent.height
        anchors.centerIn: parent

        onPaint: {
            var val = value
            if (val < min) val = min;
            else if (val > max) val = max;

            var ctx = canvas.getContext("2d");
            var longestText = Math.max(ctx.measureText(min.toString()).width,
                                       ctx.measureText(max.toString()).width);
            if(!visibleTicks) longestText = 0
            var xPos = longestText + tickLength + 1;
            ctx.clearRect(xPos, heightAdjustment, width, height);

            if((fLimMin && val <= limMin) || (fLimMax && val >= limMax)) ctx.fillStyle = scaleFontLimColor;
            else ctx.fillStyle = indicatorMainColor;

            // Determine the pos to draw the indicator rectangle
            var widthOffset = (width - xPos - indicatorWidth)/2;
            ctx.fillRect(xPos+1 + widthOffset, ((max-val) * offset) + heightAdjustment , indicatorWidth, height);
            ctx.clearRect(xPos-1, height - heightAdjustment-1, width, heightAdjustment+2);

            if (visibleTicks){
                ctx.font = scaleFontStyle + " " + scaleFontPixelSize + "px '" + scaleFontFamily + "'";
                var pos = 0;

                for (var i = max; i >= min; i = i-tickInterval){
                    if((fLimMin && i <= limMin) || (fLimMax && i >= limMax)) ctx.fillStyle = scaleFontLimColor;
                    else ctx.fillStyle = scaleFontColor;
                    ctx.fillText(i.toString(), 0, pos*offset + heightAdjustment + 12/4);

                    //Tick marks
                    if((fLimMin && i <= limMin) || (fLimMax && i >= limMax)) ctx.strokeStyle = scaleFontLimColor;
                    else ctx.strokeStyle = scaleFontColor;

                    ctx.lineWidth = 2;
                    ctx.beginPath();
                    ctx.moveTo(longestText + 2, pos*offset + heightAdjustment);
                    ctx.lineTo(longestText + tickLength, pos*offset + heightAdjustment);
                    ctx.stroke();

                    pos += tickInterval;
                }

                pos = 0;
                for (var j = max; j >= min; j = j-tickInterval/tickStep){
                    //Tick marks
                    if((fLimMin && j <= limMin) || (fLimMax && j >= limMax)) ctx.strokeStyle = scaleFontLimColor;
                    else ctx.strokeStyle = scaleFontColor;

                    ctx.lineWidth = 1;
                    ctx.beginPath();
                    ctx.moveTo(longestText + tickLength/2+2, pos*offset + heightAdjustment);
                    ctx.lineTo(longestText + tickLength, pos*offset + heightAdjustment);
                    ctx.stroke();

                    pos += tickInterval/tickStep;
                }
            }
        }
    }


}
