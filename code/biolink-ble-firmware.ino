#include <Adafruit_ATParser.h>
#include <Adafruit_BLE.h>
#include <Adafruit_BLEBattery.h>
#include <Adafruit_BLEEddystone.h>
#include <Adafruit_BLEGatt.h>
#include <Adafruit_BLEMIDI.h>
#include <Adafruit_BluefruitLE_SPI.h>
#include <Adafruit_BluefruitLE_UART.h>
#include <Arduino.h>
#include <SPI.h>

#include "config.h"

#define encoderPinA 2
#define encoderPinB 4
#define encoderCPR 1000 // how many counts per revolution?

#define FACTORYRESET_ENABLE         1
#define MINIMUM_FIRMWARE_VERSION    "0.6.6"
#define MODE_LED_BEHAVIOUR          "MODE"

// Bluetooth shield configuration
#define bleCSPin 8
#define bleIRQPin 7
#define bleRSTPin 4

Adafruit_BluefruitLE_SPI ble(bleCSPin, bleIRQPin, bleRSTPin);

int emgInput = A0;

volatile unsigned int encoderPos = 0;

void setup() {
    Serial.begin(9600);
    if (!ble.begin(VERBOSE_MODE)) {
      Serial.print(F("No ble module!"));
      return;
    }
    if (FACTORYRESET_ENABLE) {
      Serial.println(F("Perofmring a factory reset: "));
      if (!ble.factoryReset()) {
        Serial.print(F("factory reset failed!"));
      }
    }
    ble.echo(false);
    ble.info();

    Serial.println(F("Connect app in UART mode"));
    Serial.println();

    ble.verbose(false);

    while (!ble.isConnected()) {
      delay(500);
    }
    Serial.println(F("******** CONNECTED ********"));
    if (ble.isVersionAtLeast(MINIMUM_FIRMWARE_VERSION)) {
      ble.sendCommandCheckOK("AT+HWModeLED=" MODE_LED_BEHAVIOUR);
    }
    ble.setMode(BLUEFRUIT_MODE_DATA);
    
    pinMode(encoderPinA, INPUT);
    digitalWrite(encoderPinA, HIGH); // enable pull-up resistor
    pinMode(encoderPinB, INPUT);
    digitalWrite(encoderPinB, HIGH);
    attachInterrupt(0, doEncoder, CHANGE);
    Serial.println("start");
}

void loop() {
    int sensorValue = analogRead(emgInput);
    float volt = sensorValue * (5.0 / 1023.0); // sensor is scaled to 1023.0
    String buf;
    buf += F("volts: ");
    buf += String(volt, 6);
    ble.print(buf);
}

void doEncoder() {
    /* If pinA and pinB are both high or both low, it is spinning
    * forward. If they're different, it's going backward.
    *
    * For more information on speeding up this process, see
    * [Reference/PortManipulation], specifically the PIND register.
    */
    if (digitalRead(encoderPinA) == digitalRead(encoderPinB)) {
        encoderPos++;
    } else {
        encoderPos--;
    }
    // Let's actually calculate the current # of degrees
    float deg = encoderPos * 360.0 / encoderCPR;
    // If our degrees value is negative, let's convert it to positive degrees that will decrease
    // Negative degrees don't make sense to use.
    float absDeg = abs(deg);
    String buf;
    buf += F("angle: ");
    buf += String(absDeg, 6);
    ble.print(buf);
}
