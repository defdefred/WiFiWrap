#include <WiFi.h>

struct WiFiWraps {
  bool connected;
} WiFiWrap;

void WiFiEvent(WiFiEvent_t event) {
  switch (event) {
    case ARDUINO_EVENT_WIFI_STA_GOT_IP:
      WiFiWrap.connected = true;
      break;
    case ARDUINO_EVENT_WIFI_STA_DISCONNECTED:
      WiFiWrap.connected = false;
      WiFi.reconnect();
      break;
    default: break;
  }
}

void WiFiWrapStart( char *SSID, char *PSK) {
  WiFiWrap.connected = false;
  WiFi.mode(WIFI_STA);
  WiFi.disconnect(true);
  WiFi.onEvent(WiFiEvent);
  WiFi.begin(SSID, PSK);
}
