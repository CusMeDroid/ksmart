#ifndef KSmart_Firebase_h
	#define KSmart_Firebase_h
	#include "Arduino.h"

	#if defined(ESP8266)
		#include <ESP8266WiFi.h>
	#else
		#error "Please select an ESP8266 board for this sketch."
	#endif

	#define PORT 443

	class Firebase
	{
		public:
			Firebase(String referenceURL);
			int setString(String path, String data);
			int setNum(String path, String data);
			int setInt(String path, int data);
			int setFloat(String path, float data);
			int pushString(String path, String data);
			int pushNum(String path, String data);
			int pushInt(String path, int data);
			int pushFloat(String path, float data);
			void getData(String path);
			String getString(String path);
			int getInt(String path);
			float getFloat(String path);
			int deleteData(String path);
			void json(bool json);
			void Connect_to_host();

		private:
			String _host;
			bool _json = false;
			String _String;
			int _int;
			float _float;
			WiFiClientSecure _httpsClient;
	};
#endif
