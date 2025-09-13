#include <WiFi.h>

Struct WiFiWraps {
  char *staSSID;
  char *staPSK;
  bool connected;
} WifiWrap;

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      WiFiWrap.connected = true;
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      WiFiWrap.connected = false;
      WiFi.begin(UDisPlay.udp.staSSID, UDisPlay.udp.staPSK);
      break;
    default: break;
}

void WiFiWrapStart( char *SSID; char *PSK ) {
  UDisPlay.staSSID = *SSID;
  UDisPlay.staPSK = *PSK;
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(WiFiWrap.staSSID, WiFiWrap.staPSK);
}
