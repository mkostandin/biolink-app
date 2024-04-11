# Bluetooth LE
The programmable circuit board has a Bluetooth Low Energy module(BLE). Instead of a two-way connection like the normal Bluetooth communication protocol, BLE uses services with characteristics that can be subscribed to by devices. Changes are broadcast so that a constant connection is not required. BLE provided more power efficiency and better battery life which is essential for the IOT wearable.
``` c++
BLEService encoderService("EncoderA"); // BLE Service Name

// BLE Service Characteristic - Read a by central
BLEAnalogCharacteristic switchCharacteristic("A_Channel", BLERead);
```
# EasyEDA
After we won the competition, we formed a start-up called BioLink Devices. The original prototype was improved on in a variety of ways. The breadboard used during the competition was replaced with a custom PCB made using EasyEDA.
<p align="center">
<img src="https://github.com/mkostandin/mkostandin/blob/main/biolink-pcb.gif" style="display:block;margin:auto;" alt="BioLink PCB" width="75%"/>
</p>

# React

# PWA
