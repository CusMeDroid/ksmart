/*
    KSmart JavaScript
    Copyright 2024 by CusMeDroid
    DO NOT REMOVE THIS
    Don't modify or duplicate without our permission, we are law-abiding citizens.
*/
document.getElementById("btnmenu").onclick = function () {
  document.getElementById("btnmenu").style.display = "none";
  document.getElementById("btnmenuclose").style.display = "block";
  document.getElementById("btnedtdesc").style.display = "block";
  document.getElementById("btnlogout").style.display = "block";
};
document.getElementById("btnmenuclose").onclick = function () {
  document.getElementById("btnmenu").style.display = "block";
  document.getElementById("btnmenuclose").style.display = "none";
  document.getElementById("btnedtdesc").style.display = "none";
  document.getElementById("btnlogout").style.display = "none";
};
document.getElementById("btnedtdesc").onclick = function () {
  document.getElementById("edtdesk").style.display = "block";
};
document.getElementById("btnclose").onclick = function () {
  document.getElementById("edtdesk").style.display = "none";
};
