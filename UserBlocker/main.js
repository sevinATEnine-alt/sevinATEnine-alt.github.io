function parseBlocked(data, userAgent, IPv4, IPv6) {
    var blockedBecause = [];
    var lines = data.split('\n');
    lines.filter(a => a.length>0);
    try {
    var blocked = lines.filter(a => a.trimStart().toLowerCase().slice(0,5)=='block').map(a => String(a.slice(6)).trimStart());
    } catch {}
    var allowed = lines.filter(a => a.trimStart().toLowerCase().slice(0,5)=='allow').map(a => String(a.slice(6)).trimStart());

    console.log(blocked);

    for (i of blocked) {
        var iData = i.split(':');
        iData.map(e=>e.trimStart().trimEnd());
        console.log(iData);

        if (iData[0].trimStart().trimEnd().toLowerCase() === 'User-agent') {
            if (iData[1].trimStart().trimEnd().toLowerCase() === 'String') {
                console.log(iData[2].trimStart().trimEnd())
                if (iData[2].trimStart().trimEnd() === userAgent.trimStart().trimEnd()) {
                    blockedBecause.push(iData[2].trimStart().trimEnd());
                }
                
            }
        }
    }

    console.log(blockedBecause);

    return false;
}

function main() {
var blockedItems = `
Block: User-agent: String: Mozilla/5.0 (Macintosh; Intel Mac OS X 10_15_7) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/122.0.0.0 Safari/537.36
`;


var userAgent = window.navigator.userAgent;
var IPv6 = null;

var IPv4 = null;

try {

ajax = new XMLHttpRequest();
if(ajax!=null){
    ajax.open("GET","https://europe-west3-devrcc.cloudfunctions.net/whatismyip",true);
    ajax.onreadystatechange = function() {
        if(this.readyState == 4) {
            if(this.status == 200) {
                IPv6=JSON.parse(this.responseText)["ip"];
            }
        }
    }
    ajax.send(null);
}

} catch(err) {
    console.log(err);
}



if (parseBlocked(blockedItems, (userAgent || window.navigator.userAgent), (IPv4 || ""), (IPv6 || ""))) {
    document.body.innerHTML = forbiddenHTML;

    document.querySelectorAll('style').forEach(e => e.remove());

    var style = `
    * {
        color: red;
        background: black;
        font-family: monospace;

    }

    button {
        color: lightblue;
        background: grey;
    }
    `;
    var styleElement = document.createElement('style');
    styleElement.textContent = style;

    var head = document.querySelector('head');
    head.appendChild(styleElement);

}


elementToObserve = document.body;

// create a new instance of 'MutationObserver' named 'observer', 
// passing it a callback function
observer = new MutationObserver(function(mutationsList, observer) {
    try {document.querySelector('div').remove();} catch{}
});

// call 'observe' on that MutationObserver instance, 
// passing it the element to observe, and the options object
observer.observe(elementToObserve, {characterData: false, childList: true, attributes: false});






};

main();