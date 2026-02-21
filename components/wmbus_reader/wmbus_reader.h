#pragma once
#include "esphome.h"
#include <SPI.h>

// Przykładowa klasa obsługująca WMBus IZAR T1/T2
class WMBusReader : public Component {
 public:
  Sensor *water_total;
  Sensor *water_rssi;

  void setup() override {
    SPI.begin();
    // Tutaj możesz inicjalizować radio CC1101 / SX1276, np:
    // radio.begin();
    ESP_LOGD("wmbus", "WMBusReader setup complete");
  }

  void loop() override {
    // Tutaj odbierasz ramkę WMBus
    // Przykład symulowany, w praktyce musisz podłączyć radio:
    
    // --- PRZYKŁAD --- odczyt danych
    static unsigned long last = 0;
    if (millis() - last > 5000) { // co 5s
      last = millis();

      // Przykładowe dane
      float total = 12.345;   // m³
      int rssi = -70;          // dBm

      // Publikacja do ESPHome
      if (water_total) water_total->publish_state(total);
      if (water_rssi) water_rssi->publish_state(rssi);

      ESP_LOGD("wmbus", "Published WMBus values: total=%.3f rssi=%d", total, rssi);
    }
  }
};