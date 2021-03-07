
var fs = document.getElementById("text").fontSize;

function hello(){
    document.getElementById("text").style.fontSize = "24px";
    document.getElementById("text").style.backgroundColor = "red";
}

function snoopify(){
    if(!fs) fs = '12pt';
    var content = document.getElementById("text").value;
    console.log(fs);
    var li = content.split('.');
    var result = li.join('-izzle.');
    document.getElementById("text").value = result;
}