/* 
 * ExternalProtocol.cpp
 *
 * @author Markus Günther
 * @author Robert Lauer
 */

#include "ExternalProtocol.h"

ExternalProtocol::ExternalProtocol(PowerFunctionsAdapter *adapter)
{
    _adapter = adapter;
}

void ExternalProtocol::onReceive(char *data, int len) {
    
    if (len != 2)
    {
        return;
    }
    
    byte opcode = data[0] & 0xF;
    uint8_t value = data[1] & 0xF;
    
    switch (opcode) {
        case OPCODE_STEER_LEFT:
            _adapter->steerLeft(value);
            break;
        case OPCODE_STEER_RIGHT:
            _adapter->steerRight(value);
            break;
        case OPCODE_NEUTRAL:
            _adapter->center();
            break;
        case OPCODE_ACCELERATE:
            _adapter->accelerate(value);
            break;
        case OPCODE_REVERSE_ACCELERATE:
            _adapter->reverseAccelerate(value);
            break;
        case OPCODE_BRAKE:
            _adapter->stop();
            break;
    }
}