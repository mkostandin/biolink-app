# Bluetooth LE
The programmable circuit board has a Bluetooth Low Energy module(BLE). Instead of a two-way connection like the normal Bluetooth communication protocol, BLE uses services with characteristics that can be subscribed to by devices. Changes are broadcast so that a constant connection is not required. BLE provides more power efficiency and better battery life, which is essential for the IoT wearable.
``` c++
BLEService encoderService("EncoderA"); // BLE Service Name

// BLE Service Characteristic - Read a by central
BLEAnalogCharacteristic switchCharacteristic("A_Channel", BLERead);
```
# EasyEDA
After we won the competition, we were awarded $6,0000, and we used it to form a start-up called BioLink Devices. The original prototype was improved on in a variety of ways. The breadboard used during the competition was replaced with a custom PCB made using EasyEDA.
<p align="center">
<img src="https://github.com/mkostandin/mkostandin/blob/main/biolink-pcb.gif" style="display:block;margin:auto;" alt="BioLink PCB" width="75%"/>
</p>

# React
The application was written in React using IONIC 5 and TypeScript. The code below is TSX, which is a combination of TypeScript and HTML. It creates an Ionic 5 component called a card. The main part of the card is the IonCardContent, which is resizable. The size is sent to the component by properties in a similar way that HTML attributes are set.

``` TSX
<IonCard>
    <IonCardHeader>
      <IonCardTitle>Progress</IonCardTitle>
    </IonCardHeader>
    <IonCardContent>
      <Resizable
          defaultSize={{
          width:339,
          height:200,
          }}
      >
          <BioLinkGraph />
      </Resizable>
    </IonCardContent>
    </IonCard>
```
# Azure and Netlify Demo

[BioLink App Live Demo](https://gray-sky-03af52a10.3.azurestaticapps.net)

There are two versions of the demo: one hosted on Azure and the other on Netlify. The application is designed for mobile devices. In the Azure deployment, a basic JavaScript function checks the screen size and opens an iframe pointing to the Netlify version. If the user is viewing it on a mobile device, they are directed to the Netlify deployment where the app is running.

``` javascript
function checkScreen() {
    var screenWidth = window.screen.width;
    var mobileURL = "https://biolink-app-demo.netlify.app/";
    if (screenWidth <= 720) {
      window.location = mobileURL;
    }
  }
  
  window.onload = checkScreen;
  ```
