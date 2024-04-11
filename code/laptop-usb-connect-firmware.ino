#include <Arduino.h> //need fix
#include <SPI.h> //need fix

//Serial In: "Start" and "Stop"
//Serial OUT: "emg_value, emg_time, encoder_value, encoder_time"

//Need to figuere out how to use with vscode extension
//Need add rtc
#define encoderPinA 2
#define encoderPinB 4
#define encoderCPR 1000 // how many counts per revolution?


const int emgInput = A0;

volatile unsigned int encoderPos = 0;
String cmd;



void setup() {
    Serial.begin(9600);

    pinMode(encoderPinA, INPUT);
    digitalWrite(encoderPinA, HIGH); // enable pull-up resistor
    pinMode(encoderPinB, INPUT);
    digitalWrite(encoderPinB, HIGH);
    attachInterrupt(0, doEncoder, CHANGE);
    Serial.println("start");
    
    cmd = "init";
}

void loop() {
    //String cmd; //need to make state persist

    if ( Serial.available() )
  {
    // Handle remote request
    cmd = Serial.readStringUntil('\n');
  }
    //change state
        //ready state
        //idle state, low power
        //running state
        //stopping state

    int emgInputValue = analogRead(emgInput);
    //float volt = sensorValue * (5.0 / 1023.0); // sensor is scaled to 1023.0   //needs to be mapped using map()

    int emgValue = (int)map( emgInputValue, 0, 1023, 0, 100 ); //Map EMG analog data

    String buf;
    buf += F("volts: ");
    buf += String(volt, 6);

    if ( cmd == "start") {
        Serial.println( emgValue + "," + emgTime + "," + encoderValue + "," encoderTime );
    } else { //"stop"
        Serial.println("ready");
    }

    //need delay
}

void doEncoder() { //Need to map 0-100
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
