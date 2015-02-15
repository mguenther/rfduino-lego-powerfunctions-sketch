/*
 * This sketch implements logic for controlling LEGO Technic Power Functions
 * based LEGO models. The implementation essentially works as a protocol
 * translator between a high-level application protocol for controlling the
 * motors and a low-level communications protocol which is used to trigger
 * the respective actions at the LEGO Power Functions motor controller.
 *
 * The implementation of the low-level communication is provided by the
 * <code>Arduino-PowerFunctions</code> library.
 *
 * A first working prototype of this sketch was implemented during the
 * Accso Hackathon 2015, in which we got the chance to tinker around with 
 * RFduino units. Although fully working, said prototype was more of a 
 * quick-and-dirty solution. Hence, we did some refactoring to improve the 
 * overall design of the sketch and its code quality. 
 *
 * @author Markus Günther
 * @author Robert Lauer
 */ 

#include <RFduinoBLE.h>
#include <PowerFunctions.h>
#include "PowerFunctionsAdapter.h"
#include "ExternalProtocol.h"

const uint8_t PIN_IR_LED = 3;

PowerFunctionsAdapter adapter(PIN_IR_LED);
ExternalProtocol protocol(&adapter);

void setup()
{
    pinMode(PIN_IR_LED, OUTPUT);
    
    RFduinoBLE.advertisementData = "pfcontr";
    RFduinoBLE.deviceName = "pfcontr";
    RFduinoBLE.begin();
    
    Serial.begin(9600);
}

void loop()
{
}

void RFduinoBLE_onDisconnect()
{
    digitalWrite(PIN_IR_LED, LOW);
}

void RFduinoBLE_onReceive(char *data, int len)
{
    protocol.onReceive(data, len);
}