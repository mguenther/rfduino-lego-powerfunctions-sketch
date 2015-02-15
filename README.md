# RFduino LEGO PowerFunctions - Sketch

Sketch for the RFduino which implements a high-level protocol between the mobile app and the RFduino unit and translates it to an IR-based low-level protocol which is used to communicate with a LEGO PowerFunctions motor controller. The implementation of the low-level communication is provided by the Arduino-PowerFunctions library.

A first working prototype of this sketch was implemented during the Accso Hackathon 2015, in which we got the chance to tinker around with RFduino units. Although fully working, said prototype was more of a quick-and-dirty solution. Hence, we did some refactoring afterwards as well as improvements to the high-level protocol which increased code quality and overall design.

The implementation is not optimized for efficiency. There is still room for lots of improvements with regard to battery efficiency of the RFduino unit itself or with regard to the implementation of the high-level protocol between the RFduino and a Bluetooth-enabled client (cf. project rfduino-lego-powerfunctions-app).
