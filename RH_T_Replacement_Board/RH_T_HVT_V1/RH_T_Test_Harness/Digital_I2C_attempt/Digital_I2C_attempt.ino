#include <SoftWire.h>
#include <AsyncDelay.h>

 int sdaPin = 2;
  int sclPin = 4;

  const uint8_t I2C_ADDRESS = 0x40;
  
  char swTxBuffer[16];
  char swRxBuffer[16];

  SoftWire sw(sdaPin, sclPin);

  AsyncDelay samplingInterval;

  float readTemp() {
    sw.beginTransmission(I2C_ADDRESS);
    sw.write(uint8_t(0)); // Access the first register
    sw.endTransmission();

    uint8_t registers[20]; // There are 7 registers we need to read from to get the date and time.
    int numBytes = sw.requestFrom(I2C_ADDRESS, (uint8_t)20);
    for (int i = 0; i < numBytes; ++i) {
      registers[i] = sw.read();
    }

    int temp_low = registers[0];
    int temp_high = registers[1];
    int temp = (temp_high << 8) | temp_low;
    float f = temp;
    f = ((f * 165.0f) / 65536.0f) - 40.0f;
    return f;
  }

  float readHumidity() {
    sw.beginTransmission(I2C_ADDRESS);
    sw.write(uint8_t(0)); // Access the first register
    sw.endTransmission();

    uint8_t registers[20]; // There are 7 registers we need to read from to get the date and time.
    int numBytes = sw.requestFrom(I2C_ADDRESS, (uint8_t)20);
    for (int i = 0; i < numBytes; ++i) {
      registers[i] = sw.read();
    }

    int humidity_low = registers[2];
    int humidity_high = registers[3];
    int humidity = (humidity_high << 8) | humidity_low;

    float f = humidity;
	  f = (f / 65536.0f) * 100.0f;
    return f;  
  }

void setup() {

  Serial.begin(9600);

  sw.setTxBuffer(swTxBuffer, sizeof(swTxBuffer));
  sw.setRxBuffer(swRxBuffer, sizeof(swRxBuffer));

  sw.begin();

}

void loop() {

  float temperature = readTemp();
  float humidity  = readHumidity();
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.print(" (C)\t");
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" (%)\n\n");

  delay(1000);
}
