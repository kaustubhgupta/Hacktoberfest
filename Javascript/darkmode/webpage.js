var name = prompt("Please enter your name");

if (name != null) {
  document.getElementById("welcome").innerHTML =
    "Hello " + name + "! Welcome to my Webpage";

  const ctime = document.getElementById("time");

  function clock() {
    let date = new Date();
    let time = date.toLocaleTimeString();
    ctime.innerText = time;
  }

  // clock();

  setInterval(clock, 1000);
}
function dark() {
  var element = document.body;
  element.classList.toggle("dark-mode");
}
