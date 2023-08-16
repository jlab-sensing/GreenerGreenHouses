
#include <Wire.h>

volatile float HumidityReading, TempReading;
//  Constants for setting measurement resolution
#define FOURTEEN_BIT 0
#define ELEVEN_BIT 1
#define NINE_BIT 2

//  Constants for setting sensor mode
#define TEMP_AND_HUMID 0
#define TEMP_ONLY 1
#define HUMID_ONLY 2
#define ACTIVE_LOW 0
#define ACTIVE_HIGH 1
#define LEVEL_MODE 0
#define COMPARATOR_MODE 1

//  Constants for setting sample rate
#define MANUAL 0
#define TWO_MINS 1
#define ONE_MINS 2
#define TEN_SECONDS 3
#define FIVE_SECONDS 4
#define ONE_HZ 5
#define TWO_HZ 6
#define FIVE_HZ 7

#define HDC2021_ADDRESS 0x40
#define TEMP_LO_REG 0x00
#define TEMP_HI_REG 0x01
#define HUMIDITY_LO_REG 0x02
#define HUMIDITY_HI_REG 0x03
#define CONFIG 0x0E
#define MEAS_CONFIG 0x0F

void Sensor_Reset();
void Sensor_Begin();
float Sensor_ReadTemp();
float Sensor_ReadHumidity();
uint8_t Sensor_ReadRegister(uint8_t Register);
void Sensor_WriteRegister(uint8_t Register, uint8_t Data);
void Sensor_TriggerMeasurement();
void Sensor_SetMeasurementRate(int Rate);
void Sensor_SetMeasurementMode(int Mode);
void Sensor_SetHumidityResolution(int Resolution);
void Sensor_SetTempResolution(int Resolution);

void Sensor_Reset() {

  uint8_t configContents;
  configContents = Sensor_ReadRegister(CONFIG);

  configContents = (configContents | 0x80);
  Sensor_WriteRegister(CONFIG, configContents);
  delay(50);

}

void Sensor_Begin() {
  Wire.begin();
}

float Sensor_ReadTemp() {
  uint8_t data[2];
  uint16_t temp;
  data[0] = Sensor_ReadRegister(TEMP_LO_REG);
  data[1] = Sensor_ReadRegister(TEMP_HI_REG);
  temp = data[1];
  temp = (temp << 8) | data[0];
  float f = temp;
  f = ((f * 165.0f) / 65536.0f) - 40.0f;
  return f;
}

float Sensor_ReadHumidity() {
  uint8_t data[2];
  uint16_t humidity;
  data[0] = Sensor_ReadRegister(HUMIDITY_LO_REG);
  data[1] = Sensor_ReadRegister(HUMIDITY_HI_REG);
  humidity = data[1];
  humidity = (humidity << 8) | data[0];
  float f = humidity;
  f = (f / 65536.0f) * 100.0f;

  return f;
}

uint8_t Sensor_ReadRegister(uint8_t Register) {
  uint8_t Data;
  Wire.beginTransmission(HDC2021_ADDRESS);
  Wire.write(Register);
  Wire.endTransmission();
  Wire.requestFrom(0x40, 1);
  if (Wire.available() == 0)
  {
    Data = 0;
  }
  else {
    Data = Wire.read();
  }
  return Data;
}

void Sensor_WriteRegister(uint8_t Register, uint8_t Data) {

  Wire.beginTransmission(HDC2021_ADDRESS);
  Wire.write(Register);
  Wire.write(Data);
  Wire.endTransmission();

}

void Sensor_TriggerMeasurement() {
  uint8_t configContents;
  configContents = Sensor_ReadRegister(MEAS_CONFIG);

  configContents = (configContents | 0x01);
  Sensor_WriteRegister(MEAS_CONFIG, configContents);
}
void Sensor_SetMeasurementRate(int Rate) {
  uint8_t configContents;
  configContents = Sensor_ReadRegister(CONFIG);

  switch (Rate)
  {
    case MANUAL:
      configContents = (configContents & 0x8F);
      break;

    case TWO_MINS:
      configContents = (configContents & 0x9F);
      configContents = (configContents | 0x10);
      break;

    case ONE_MINS:
      configContents = (configContents & 0xAF);
      configContents = (configContents | 0x20);
      break;

    case TEN_SECONDS:
      configContents = (configContents & 0xBF);
      configContents = (configContents | 0x30);
      break;

    case FIVE_SECONDS:
      configContents = (configContents & 0xCF);
      configContents = (configContents | 0x40);
      break;

    case ONE_HZ:
      configContents = (configContents & 0xDF);
      configContents = (configContents | 0x50);
      break;

    case TWO_HZ:
      configContents = (configContents & 0xEF);
      configContents = (configContents | 0x60);
      break;

    case FIVE_HZ:
      configContents = (configContents | 0x70);
      break;

    default:
      configContents = (configContents & 0x8F);
  }

  Sensor_WriteRegister(CONFIG, configContents);
}
void Sensor_SetMeasurementMode(int Mode) {
  uint8_t configContents;
  configContents = Sensor_ReadRegister(MEAS_CONFIG);

  switch (Mode)
  {
    case TEMP_AND_HUMID:
      configContents = (configContents & 0xF9);
      break;

    case TEMP_ONLY:
      configContents = (configContents & 0xFC);
      configContents = (configContents | 0x02);
      break;

    case HUMID_ONLY:
      configContents = (configContents & 0xFD);
      configContents = (configContents | 0x04);
      break;

    default:
      configContents = (configContents & 0xF9);
  }

  Sensor_WriteRegister(MEAS_CONFIG, configContents);
}
void Sensor_SetHumidityResolution(int Resolution) {
  uint8_t configContents;
  configContents = Sensor_ReadRegister(MEAS_CONFIG);

  switch (Resolution)
  {
    case FOURTEEN_BIT:
      configContents = (configContents & 0xCF);
      break;

    case ELEVEN_BIT:
      configContents = (configContents & 0xDF);
      configContents = (configContents | 0x10);
      break;

    case NINE_BIT:
      configContents = (configContents & 0xEF);
      configContents = (configContents | 0x20);
      break;

    default:
      configContents = (configContents & 0xCF);
  }

  Sensor_WriteRegister(MEAS_CONFIG, configContents);
}
void Sensor_SetTempResolution(int Resolution) {
  uint8_t configContents;
  configContents = Sensor_ReadRegister(MEAS_CONFIG);

  switch (Resolution)
  {
    case FOURTEEN_BIT:
      configContents = (configContents & 0x3F);
      break;

    case ELEVEN_BIT:
      configContents = (configContents & 0x7F);
      configContents = (configContents | 0x40);
      break;

    case NINE_BIT:
      configContents = (configContents & 0xBF);
      configContents = (configContents | 0x80);
      break;

    default:
      configContents = (configContents & 0x3F);
  }

  Sensor_WriteRegister(MEAS_CONFIG, configContents);
}



void setup() {


  Serial.begin(9600);
  Sensor_Begin();
  Sensor_Reset();
  Sensor_SetMeasurementMode(TEMP_AND_HUMID);
  Sensor_SetMeasurementRate(ONE_HZ);
  Sensor_SetTempResolution(FOURTEEN_BIT);
  Sensor_SetHumidityResolution(FOURTEEN_BIT);
  Sensor_TriggerMeasurement();

}

void loop() {

  HumidityReading = Sensor_ReadHumidity();
  TempReading = Sensor_ReadTemp();
  Serial.print("Temperature (C): "); Serial.print(TempReading);
  Serial.print("\t\tHumidity (%): "); Serial.println(HumidityReading);

  delay(1000);
}
