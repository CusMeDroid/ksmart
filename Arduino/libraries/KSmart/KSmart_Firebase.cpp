#include "KSmart_Firebase.h"

Firebase::Firebase(String referenceURL) {
	_host = referenceURL;

  if (_host.startsWith("https://")) {
    _host.remove(0, 8);
  }

  if (_host.endsWith("/")) {
    _host.remove(_host.length() - 1);
  }
  
	_httpsClient.setInsecure();
}

int Firebase::setString(String path, String data) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");
  String msg = "\"" + data + "\"";

  _httpsClient.print(String("PUT ") + jsonObject + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: " + msg.length() + "\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200; // Success
  }

  return 400;     // Failed
}

int Firebase::setInt(String path, int data) {
  String Data = String(data);
  return Firebase::setNum(path, Data);
}

int Firebase::setFloat(String path, float data) {
  String Data = String(data);
  return Firebase::setNum(path, Data);
}

int Firebase::setNum(String path, String msg) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("PUT ") + jsonObject + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: " + msg.length() + "\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200; // Success
  }

  return 400;     // Failed
}

int Firebase::pushString(String path, String data) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  String msg = "\"" + data + "\"";

  _httpsClient.print(String("POST ") + jsonObject + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: " + msg.length() + "\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200; // Success
  }

  return 400;     // Failed
}

int Firebase::pushInt(String path, int data) {
  String Data = String(data);
  return Firebase::pushNum(path, Data);
}

int Firebase::pushFloat(String path, float data) {
  String Data = String(data);
  return Firebase::pushNum(path, Data);
}

int Firebase::pushNum(String path, String msg) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("POST ") + jsonObject + " HTTP/1.1\r\n" +
          "Host: " + _host + "\r\n" +
          "Connection: close\r\n" +
          "Accept: */*\r\n" +
          "User-Agent: Mozilla/4.0 (compatible; esp8266 Lua; Windows NT 5.1)\r\n" +
          "Content-Type: application/json;charset=utf-8\r\n" +
          "Content-Length: " + msg.length() + "\r\n" +
          "\r\n" +
          msg + "\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200; // Success
  }

  return 400;     // Failed
}

String Firebase::getString(String path) {
  Firebase::getData(path);
  return _String;
}

int Firebase::getInt(String path) {
  Firebase::getData(path);
  return _int;
}

float Firebase::getFloat(String path) {
  Firebase::getData(path);
  return _float;
}

void Firebase::getData(String path) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("GET ") + jsonObject + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +
               "Connection: close\r\n\r\n");


  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    _int = line.toInt();
    _float = line.toFloat();
    if (_json == false)
      _String = line.substring(1,line.length()-1);
    else
      _String = line;
  }
}

int Firebase::deleteData(String path) {
	Connect_to_host();
  String jsonObject = String("/") + path + String(".json");

  _httpsClient.print(String("DELETE ") + jsonObject + " HTTP/1.1\r\n" +
               "Host: " + _host + "\r\n" +
               "Connection: close\r\n\r\n");

  while (_httpsClient.connected()) {
    String line = _httpsClient.readStringUntil('\n');
    if (line == "\r") {
      break;
    }
  }

  String line;
  while(_httpsClient.available()) {
    line = _httpsClient.readStringUntil('\n');
    if (line.length() > 0)
      return 200; // Success
  }

  return 400;     // Failed
}

void Firebase::json(bool json) {
  _json = json;
}

void Firebase::Connect_to_host() {
	int r=0;
  while((!_httpsClient.connect(_host, PORT)) && (r < 30)) {
      delay(100);
      r++;
  }
}
