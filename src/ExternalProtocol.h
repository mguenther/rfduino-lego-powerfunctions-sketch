/* 
* ExternalProtocol.h
*
* @author Markus Günther
* @author Robert Lauer
*/

#ifndef __EXTERNALPROTOCOL_H__
#define __EXTERNALPROTOCOL_H__

#include "PowerFunctionsAdapter.h"

const uint8_t OPCODE_SPEED = 1;
const uint8_t OPCODE_STEERING = 2;

const byte OPCODE_STEER_LEFT = 0x01;
const byte OPCODE_STEER_RIGHT = 0x02;
const byte OPCODE_NEUTRAL = 0x03;
const byte OPCODE_ACCELERATE = 0x04;
const byte OPCODE_REVERSE_ACCELERATE = 0x05;
const byte OPCODE_BRAKE = 0x06;

// Implements the external application protocol which is exposed via the
// RFduino. A message with regard to this protocol is comprised of 2 bytes,
// where byte 1 contains information on the operation that is to be executed
// (opcode) and byte 0 contains additional data that is used to parameterize
// that operation.
//
// The protocol is not optimized for efficiency. Using 2 bytes seems wasteful,
// but nonetheless convenient, since we do not have to do bit-fiddling on
// either receiver- nor transmitter-side, which eases client development
// as well.
class ExternalProtocol
{
    private:
        PowerFunctionsAdapter* _adapter;
    
    public:
        // The constructor consumes a reference to the PowerFunctionsAdapter
        // which is used to transmit operations of the application protocol
        // to the LEGO motor controller via IR.
        ExternalProtocol(PowerFunctionsAdapter*);
        
        /// Handles incoming data. Extracts the opcode and additional
        // value data and delegates to the appropriate adapter method.
        void onReceive(char*, int);
};

#endif //__EXTERNALPROTOCOL_H__