var sliderX = document.getElementById("slXoff");
var offsetX = document.getElementById("lblXoff");
var sliderY = document.getElementById("slYoff");
var offsetY = document.getElementById("lblYoff");
var sliderAlpha = document.getElementById("slAlpha");
var tAlpha = document.getElementById("lblAlpha");
var sliderGrid = document.getElementById("slGridDim");
var tGridSize = document.getElementById("lblGridDim");
var sliderSpacing = document.getElementById("slSpacing");
var tSpacing = document.getElementById("lblSpacing");
var sliderAnimation = document.getElementById("slAnimation");
var tAnimation = document.getElementById("lblAnimation");
var sliderDecimals = document.getElementById("slDecimals");
var tDecimals = document.getElementById("lblDecimals");
var chkIndex = document.getElementById("chkIndex");
var gridData;
var iAnimDuration = 500;
var bGenIndex;

// for animation
var canvas = document.getElementById('canvas');
var ctx = canvas.getContext('2d');

// custom chart background
// Note: changes to the plugin code is not reflected to the chart, because the plugin is loaded at chart construction time and editor changes only trigger an chart.update().
const plugin = {
    id: 'custom_canvas_background_color',
    beforeDraw: (chart) => {
        const ctx = chart.canvas.getContext('2d');
        ctx.save();
        ctx.globalCompositeOperation = 'destination-over';
        ctx.fillStyle = '#FFE4C4';
        //ctx.fillStyle = 'lightYellow';
        ctx.fillRect(0, 0, chart.width, chart.height);
        ctx.restore();
    }
};

sliderX.oninput = function() {
    offsetX.innerHTML = this.value;
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

sliderY.oninput = function() {
    offsetY.innerHTML = this.value;
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

sliderAlpha.oninput = function() {
    tAlpha.innerHTML = this.value;
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

sliderGrid.oninput = function() {
    var N2 = Math.floor(parseInt(sliderGrid.value, 10));
    tGridSize.innerHTML = N2.toString() + "x" + N2.toString();
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

sliderDecimals.oninput = function() {
    tDecimals.innerHTML = this.value;
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
}

sliderSpacing.oninput = function() {
    var num = this.value;
    tSpacing.innerHTML = num
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

sliderAnimation.oninput = function() {
    tAnimation.innerHTML = this.value.toString() + "s";
    iAnimDuration = this.value * 1000;
    myScatter.options = {
        aspectRatio: 1,
        title: {
            display: true,
            text: 'Grid'
        },
        legend: {
            display: false
        },
        animation: {
            duration: iAnimDuration,
            xAxis: true,
            yAxis: true,
        },
        scales: {
            x: { type: 'linear' },
            xAxes: [{
                ticks: {
                    min: -12,
                    beginAtZero: true,
                    max: 12,
                    stepSize: 1
                }
            }],
            yAxes: [{
                ticks: {
                    min: -12,
                    beginAtZero: true,
                    max: 12,
                    stepSize: 1
                }
            }]
        }
    };
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    window.myScatter.update();
}

chkIndex.oninput = function() {
    bGenIndex = chkIndex.checked;
}

function randomArray(min, max) {
    return (new Array(max - min))
        .join(',').split(',')
        .map(function(v, i) { return [Math.random(), min + i]; })
        .sort().map(function(v) { return v[1]; });
}

var color = Chart.helpers.color;

function generateData() {
    //var data = [];
    //textData = "";
    gridData = [];
    var tmpData;
    tmpData = [];
    var x1;
    var y1;
    var Angle = parseInt(sliderAlpha.value, 10);
    var cosAngle = Math.cos(Angle * Math.PI / 180);
    var sinAngle = Math.sin(Angle * Math.PI / 180);
    var N = Math.floor(parseInt(sliderGrid.value, 10));
    var Nh = Math.floor(parseInt(sliderGrid.value, 10) / 2);
    if (Nh * 2 == N) Nh = Nh - 0.5;
    var precision = parseInt(sliderDecimals.value, 10);
    var spacing = parseFloat(sliderSpacing.value);
    var index = 0;
    for (var i = -Nh; i < Nh + 1; i++) {
        for (var j = -Nh; j < Nh + 1; j++) {
            x1 = i * cosAngle - j * sinAngle;
            y1 = i * sinAngle + j * cosAngle;
            var x2 = x1 * spacing + parseInt(sliderX.value, 10);
            var y2 = y1 * spacing + parseInt(sliderY.value, 10);
            tmpData.push({ x: x2, y: y2, idx: index++ });
            //textData += x2.toFixed(precision) + "," +
            //y2.toFixed(precision) + "\r\n";
        }
    }

    //gridData = tmpData;
    gridData = randomArray(0, tmpData.length).map(function(n) { return tmpData[n] });

    return gridData;
}

var scatterChartData = {
    datasets: [{
        label: '',
        borderColor: window.chartColors.blue,
        backgroundColor: color(window.chartColors.blue).alpha(1.0).rgbString(),
        data: generateData()
    }]
};

function textData() {
    var txtData = "";
    var precision = parseInt(sliderDecimals.value, 10);
    var spacing = parseFloat(sliderSpacing.value);
    var arrayLength = gridData.length;
    for (var i = 0; i < arrayLength; i++) {
        var idx2 = gridData[i].idx;
        var x2 = gridData[i].x;
        var y2 = gridData[i].y;
        if (bGenIndex) txtData += idx2 + ": ";
        txtData += x2.toFixed(precision) + "," +
            y2.toFixed(precision) + "\r\n";
    }
    return txtData;
}

function displayGridData() {
    //document.execCommand('copy');
    scatterChartData.datasets.forEach(function(dataset) {
        dataset.data = generateData();
    });
    var textarea = document.getElementById("griddata");
    textarea.value = textData();
}

window.onload = function() {
    var ctx = document.getElementById('canvas').getContext('2d');
    sliderX.value = 0;
    sliderY.value = 0;
    sliderAlpha.value = 0.0;
    bGenIndex = chkIndex.checked;
    var textarea = document.getElementById("griddata");
    textarea.value = "1. Choose a grid configuration from above. \r\n";
    textarea.value += "2. Specify a desired precision, below.\r\n";
    textarea.value += "3. Click 'Generate Data' button.\r\n";
    textarea.value += "4. Click 'Copy to Clipboard' to paste to notepad.\r\n";
    Chart.defaults.global.elements.point.radius = 1.5;
    //Chart.defaults.global.animation = true;
    var delayed;
    window.myScatter = Chart.Scatter(ctx, {
        data: scatterChartData,
        plugins: [plugin],
        options: {
            aspectRatio: 1,
            title: {
                display: true,
                text: 'Grid'
            },
            legend: {
                display: false
            },
            animation: {
                duration: iAnimDuration,
                xAxis: true,
                yAxis: true,
            },
            scales: {
                x: { type: 'linear' },
                xAxes: [{
                    ticks: {
                        min: -12,
                        beginAtZero: true,
                        max: 12,
                        stepSize: 1
                    }
                }],
                yAxes: [{
                    ticks: {
                        min: -12,
                        beginAtZero: true,
                        max: 12,
                        stepSize: 1
                    }
                }]
            }
        }
    });
    document.getElementById("copyBtn").onclick = function() {
        document.execCommand('copy');
    }
    document.addEventListener('copy', function(e) {
        var textarea = document.getElementById("griddata");
        textarea.value = textData();
        e.clipboardData.setData('text/plain', textData());
        e.preventDefault(); // default behaviour is to copy any selected text
    });
};