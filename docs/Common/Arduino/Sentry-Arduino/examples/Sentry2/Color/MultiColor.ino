#include <Arduino.h>
#include <Sentry.h>

typedef Sentry2 Sentry;

#define SENTRY_I2C
// #define SENTRY_UART

#define ROWS 5
#define COLS 5

#ifdef SENTRY_I2C
#include <Wire.h>
#endif
#ifdef SENTRY_UART
#include <SoftwareSerial.h>
#define TX_PIN 11
#define RX_PIN 10
SoftwareSerial mySerial(RX_PIN, TX_PIN);
#endif

#define VISION_TYPE Sentry::kVisionColor
Sentry sentry;

void setup() {
  sentry_err_t err = SENTRY_OK;

  Serial.begin(9600);

  Serial.println("Waiting for sentry initialize...");
#ifdef SENTRY_I2C
  Wire.begin();
  while (SENTRY_OK != sentry.begin(&Wire)) { yield(); }
#endif  // SENTRY_I2C
#ifdef SENTRY_UART
  mySerial.begin(9600);
  while (SENTRY_OK != sentry.begin(&mySerial)) { yield(); }
#endif  // SENTRY_UART
  Serial.println("Sentry begin Success.");
  int param_num = ROWS * COLS;       // 1~SENTRY_MAX_RESULT
  sentry.SetParamNum(VISION_TYPE, param_num);
  int index;
  sentry_object_t param;
  param.width = 4;
  param.height = 3;
  for (size_t row = 1; row <= ROWS; ++row)
  {
    for (size_t col = 1; col <= COLS; ++col)
    {
      /* Set x/y/w/h */
      param.x_value = 100 * col / (COLS + 1);
      param.y_value = 100 * row / (ROWS + 1);
      index = (row - 1) * COLS + col;
      err = sentry.SetParam(VISION_TYPE, &param, index);
      if (err) {
        Serial.print("sentry.SetParam");
        Serial.print(index);
        Serial.print(" Error: 0x");
        Serial.println(err, HEX);
        for (;;);
      }
    }
  }
  err = sentry.VisionBegin(VISION_TYPE);
  Serial.print("sentry.VisionBegin(kVisionColor) ");
  if (err) {
    Serial.print("Error: 0x");
  } else {
    Serial.print("Success: 0x");
  }
  Serial.println(err, HEX);
}

void loop() {
  int obj_num = sentry.GetValue(VISION_TYPE, kStatus);
  if (obj_num) {
    Serial.print("Totally ");
    Serial.print(obj_num);
    Serial.println(" objects");
    for (int i = 1; i <= obj_num; ++i) {
      int l = sentry.GetValue(VISION_TYPE, kLabel, i);
      Serial.print('|');
      Serial.print(l);
    }
    Serial.println("|\n");
  }
}
