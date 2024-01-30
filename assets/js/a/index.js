/*
    KSmart JavaScript
    Copyright 2024 by CusMeDroid
    DO NOT REMOVE THIS
    Don't modify or duplicate without our permission, we are law-abiding citizens.
*/
if (!sessionEmail && !sessionUid) {
  window.location.href = "login";
}

var refRelay = firebase.database().ref('users/' + sessionUid + '/relay');
refRelay.on('value', (snapshot) => {
  var dataRelay = snapshot.val();
  // console.log(dataRelay);
  if (dataRelay == "on") {
    document.getElementById("btnon").style.display = "none";
    document.getElementById("btnoff").style.display = "block";
    document.getElementById("btnoff").onclick = function () {
      var relaystat = "off";
      firebase
        .database()
        .ref("users/"+sessionUid)
        .update({
          relay: relaystat,
        });
    };
  }
  if (dataRelay == "off") {
    document.getElementById("btnon").style.display = "block";
    document.getElementById("btnoff").style.display = "none";
    document.getElementById("btnon").onclick = function () {
      var relaystat = "on";
      firebase
        .database()
        .ref("users/"+sessionUid)
        .update({
          relay: relaystat,
        });
    };
  }
});

var refDesc = firebase.database().ref('users/' + sessionUid + '/desc');
refDesc.on('value', (snapshot) => {
  var dataDesc = snapshot.val();
  document.getElementById("mydesc").placeholder = dataDesc;
});

document.getElementById("btnsave").onclick = function () {
  var mDesc = document.getElementById("mydesc").value;
  if (mDesc < 1) {
    alert("Do not be empty!");
  } else {
    firebase
      .database()
      .ref("users/"+sessionUid)
      .update({
        desc: mDesc,
      });
    alert("Success change message!");
    document.getElementById("mydesc").value="";
  }
};

document.getElementById("btnlogout").onclick = function () {
  firebase.auth().signOut().then(() => {
    var relaystat = "off";
    firebase
      .database()
      .ref("users/"+sessionUid)
      .update({
        relay: relaystat,
      });
    localStorage.clear();
    window.location.href = "";
  }).catch((error) => {
    // An error happened.
  });
};
