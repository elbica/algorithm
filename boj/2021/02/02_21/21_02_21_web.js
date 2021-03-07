function bling() {
    var blingCheck = document.getElementById("blingCheck");
    
    if (blingCheck.checked == true) 
    {
        document.getElementById("text").style.fontWeight = "bold";
        document.getElementById("text").style.color = "green";
        document.getElementById("text").style.textDecoration = "underline";
    } 
    else
    {
        document.getElementById("text").style.fontWeight = "normal";
        document.getElementById("text").style.color = "black";
        document.getElementById("text").style.textDecoration = "none";
    }
}

console.log("hello");
document.getElementById("blingCheck");