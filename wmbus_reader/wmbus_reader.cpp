#include "wmbus_reader.h"

// Tutaj możesz dodać kod inicjalizacji SPI/radio
void WMBusReader::setup() {
  SPI.begin();
  ESP_LOGD("wmbus", "WMBusReader setup complete");
}

void WMBusReader::loop() {
  // Tutaj logika odczytu ramki WMBus IZAR
  static unsigned long last = 0;
  if (millis() - last > 5000) {
    last = millis();

    // Tutaj wstaw prawdziwy odczyt z CC1101/SX1276
    float total = 12.345;
    int rssi = -70;

    if (water_total) water_total->publish_state(total);
    if (water_rssi) water_rssi->publish_state(rssi);

    ESP_LOGD("wmbus", "Published WMBus values: total=%.3f rssi=%d", total, rssi);
  }
}