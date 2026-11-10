
#include <Arduino.h>
#include <Wire.h>
#include <WiFi.h>
#include <esp_now.h>
#include <Adafruit_PWMServoDriver.h>

#define NUM_SERVOS 15
#define SERVO_MIN 110
#define SERVO_MAX 510
#define PWM_FREQUENCY 50

Adafruit_PWMServoDriver pwm(0x40);

struct MotionPacket {
  uint16_t angles[NUM_SERVOS];
};

MotionPacket receivedMotion;
volatile bool newMotion = false;

void onDataReceived(
  const esp_now_recv_info_t *info,
  const uint8_t *data,
  int len
) {
  if (len != sizeof(MotionPacket)) return;

  memcpy(&receivedMotion, data, sizeof(MotionPacket));
  newMotion = true;
}

void moveServo(uint8_t channel, int angle) {
  angle = constrain(angle, 0, 180);

  int pulse = map(
    angle,
    0,
    180,
    SERVO_MIN,
    SERVO_MAX
  );

  pwm.setPWM(channel, 0, pulse);
}

void setup() {
  Serial.begin(115200);

  Wire.begin();
  pwm.begin();
  pwm.setPWMFreq(PWM_FREQUENCY);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != ESP_OK) {
    Serial.println("ESP-NOW initialization failed");
    return;
  }

  esp_now_register_recv_cb(onDataReceived);

  Serial.println("Robotic hand controller ready");
}

void loop() {
  if (newMotion) {
    newMotion = false;

    for (int i = 0; i < NUM_SERVOS; i++) {
      moveServo(i, receivedMotion.angles[i]);
    }
  }

  delay(10);
}
