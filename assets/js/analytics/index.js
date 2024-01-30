/*
    KSmart JavaScript
    Copyright 2024 by CusMeDroid
    DO NOT REMOVE THIS
    Don't modify or duplicate without our permission, we are law-abiding citizens.
*/
// Import the functions you need from the SDKs you need
import { initializeApp } from "https://www.gstatic.com/firebasejs/10.7.2/firebase-app.js";
import { getAnalytics } from "https://www.gstatic.com/firebasejs/10.7.2/firebase-analytics.js";
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseAnalytics = {
  apiKey: "AIzaSyDdQcUUmk0Eh1rO-jE4yy9jt2GQ6Rktcho",
  authDomain: "klati-smart.firebaseapp.com",
  databaseURL: "https://klati-smart-default-rtdb.asia-southeast1.firebasedatabase.app",
  projectId: "klati-smart",
  storageBucket: "klati-smart.appspot.com",
  messagingSenderId: "299766895569",
  appId: "1:299766895569:web:51e11003406102f76806f0",
  measurementId: "G-S32XV6Q1WT"
};

// Initialize Firebase
const app = initializeApp(firebaseAnalytics);
const analytics = getAnalytics(app);
