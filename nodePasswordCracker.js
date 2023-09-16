const arrDefault = [
    'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K',
    'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V',
    'W', 'X', 'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f', 'g',
    'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r',
    's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '0', '1', '2',
    '3', '4', '5', '6', '7', '8', '9', '!', '@', '#', '$',
    '%', '^', '&', '*', '(', ')', '-', '_', '+', '=', '[',
    ']', '{', '}', '\\', '|', ';', ':', '"', "'", ',', '<',
    '.', '>', '/', '?', '`', '~',' '
];
function encrypt() {
var input = document.getElementById("input").value;
var key = document.getElementById("key").value;
var key2 = key;
var output = "";
if(key.length != 0) {
while(key2.length < input.length) {
    key2 += key;
}
for(var i = 0; i < input.length; i++) {
    output += arrDefault[(arrDefault.indexOf(input[i])+arrDefault.indexOf(key2[i])) % arrDefault.length]
}
document.getElementById("output").textContent = output;
}
}
function decrypt() {
    var input = document.getElementById("input").value;
    var key = document.getElementById("key").value;
    var key2 = key;
    var output = "";
    if(key.length != 0) {
    while(key2.length < input.length) {
        key2 += key;
    }
    for(var i = 0; i < input.length; i++) {
        output += arrDefault[(arrDefault.indexOf(input[i])-arrDefault.indexOf(key2[i])) % arrDefault.length]
    }
    document.getElementById("output").textContent = output;
    }   
}