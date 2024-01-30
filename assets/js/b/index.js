/*
    KSmart JavaScript
    Copyright 2024 by CusMeDroid
    DO NOT REMOVE THIS
    Don't modify or duplicate without our permission, we are law-abiding citizens.
*/
if (sessionEmail && sessionUid) {
  window.location.href = "../";
}
document.getElementById("btn-login").onclick = function () {
  var mEmail_login = document.getElementById("email-login").value;
  var mPass_login = document.getElementById("pass-login").value;
  if (mEmail_login < 1 || mPass_login < 1) {
    alert("Do not be empty!");
  } else {
    firebase.auth().signInWithEmailAndPassword(mEmail_login, mPass_login)
    .then((userCredential) => {
      // Signed in
      var user = userCredential.user;
      sessionEmail = mEmail_login;
      localStorage.setItem("email", JSON.stringify(sessionEmail));
      sessionUid = user.uid;
      localStorage.setItem("uid", JSON.stringify(sessionUid));
      alert("Wellcome back!");
      window.location.href = "../";
    })
    .catch((error) => {
      var errorCode = error.code;
      var errorMessage = error.message;
      alert("Error! "+errorMessage);
      document.getElementById("email-login").value="";
      document.getElementById("pass-login").value="";
    });
  }
};

document.getElementById("btn-regis").onclick = function () {
  var mEmail_regis = document.getElementById("email-regis").value;
  var mPass_regis = document.getElementById("pass-regis").value;
  if (mEmail_regis < 1 || mPass_regis < 1) {
    alert("Do not be empty!");
  } else {
    firebase.auth().createUserWithEmailAndPassword(mEmail_regis, mPass_regis)
    .then((userCredential) => {
      // Signed in 
      var user = userCredential.user;
      firebase
        .database()
        .ref("users/"+user.uid)
        .update({
          email: mEmail_regis,
        });
      alert("Wellcome!");
      sessionEmail = mEmail_regis;
      localStorage.setItem("email", JSON.stringify(sessionEmail));
      sessionUid = user.uid;
      localStorage.setItem("uid", JSON.stringify(sessionUid));
      window.location.href = "../";
    })
    .catch((error) => {
      var errorCode = error.code;
      var errorMessage = error.message;
      alert("Error! "+errorMessage);
      document.getElementById("email-regis").value="";
      document.getElementById("pass-regis").value="";
    });
  }
};

document.getElementById("btnsignup").onclick = function () {
  document.getElementById("laysignin").style.display = "none";
  document.getElementById("laysignup").style.display = "block";
};

document.getElementById("btnsignin").onclick = function () {
  document.getElementById("laysignin").style.display = "block";
  document.getElementById("laysignup").style.display = "none";
};