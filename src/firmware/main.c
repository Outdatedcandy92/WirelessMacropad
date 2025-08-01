//VIBECODED FIRMWARE!


#include <WiFi.h>

#define WIFI_SSID "your_wifi_ssid"
#define WIFI_PASSWORD "your_wifi_password"
#define BUTTON_PIN 8

void setup() {
    // Initialize Serial Monitor
    Serial.begin(115200);

    // Configure GPIO 8 as input with pull-up
    pinMode(BUTTON_PIN, INPUT_PULLUP);

    // Connect to Wi-Fi
    Serial.print("Connecting to Wi-Fi");
    WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
    while (WiFi.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    Serial.println("\nConnected to Wi-Fi");
    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());
}

void loop() {
    // Check if GPIO 8 is pulled low
    if (digitalRead(BUTTON_PIN) == LOW) {
        Serial.println("Click");
        delay(200); // Debounce delay
    }
}