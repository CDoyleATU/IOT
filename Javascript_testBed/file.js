function myFunction() {


var TotalAmount = 12.35;
  var TwoEuro = 4;
  var OneEuro = 2;
  var FiftyCent = 4;

let notificationMessage =  `Total: € ${TotalAmount} \n \
  €2 x ${TwoEuro} \n \
  €1 x ${OneEuro} \n \
  €0.50 x ${FiftyCent} \n \
  €0.20 x {1}\n \
  €0.10 x {1}\n \
  €0.05 x {1}\n \
  `;

var title = "Coin Counter";
var message = notificationMessage;
var sound = '2';
var vibration = '1';
var icon = '1';
var iconcolor = 'red';
var device = 'Laptop';
var url = 'https://www.pushsafer.com';
var urltitle = 'Open Pushsafer';
var private_key = "aR0r0uGnTKP2p5XE1UzQ";

var xhttp = new XMLHttpRequest();
xhttp.open('POST', 'https://www.pushsafer.com/api', true);
xhttp.setRequestHeader('Content-type', 'application/x-www-form-urlencoded');
xhttp.send('t=' + title + '&m=' + message +  '&k=' + private_key);

console.log("Complete.")
}
function sendPushNotification(){
  let title = 'Test';
  let message = 'Hello world noti';
  let sound = '8';
  let vibration = '2';
  let icon = '31';
  let iconcolor = '2';
  let device = '64558';
  let url = 'maldicky@protonmail.com';
  let urltitle = 'Username';
  let private_key = 'aR0r0uGnTKP2p5XE1UzQ';

  var xhttp;
if (window.XMLHttpRequest) {
    xhttp = new XMLHttpRequest();
    } else {
    // code for IE6, IE5
    xhttp = new ActiveXObject("Microsoft.XMLHTTP");
}
xhttp.open("POST", "https://www.pushsafer.com/api", true);
xhttp.setRequestHeader("Content-type", "application/x-www-form-urlencoded");
xhttp.send("t="+escape(title)+"&m="+escape(message)+"&s="+sound+"&v="+vibration+"&i="+icon+"&c="+iconcolor+"&d="+device+"&u="+escape(url)+"&ut="+escape(urltitle)+"&k="+private_key);
}
sendPushNotification();
myFunction();