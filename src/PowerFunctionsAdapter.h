/* 
 * PowerFunctionsAdapter.h
 *
 * @author Markus Günther
 * @author Robert Lauer
 */

#ifndef __POWERFUNCTIONSADAPTER_H__
#define __POWERFUNCTIONSADAPTER_H__

#include <PowerFunctions.h>

const uint8_t PF_CHANNEL = 0;
const uint8_t MAX_VALUE_SPEED = 15;
const uint8_t MAX_VALUE_ORIENTATION = 15;
const uint8_t NEUTRAL_VALUE = 8;

// Integrates the PowerFunctions library and exposes a higher-level
// API which abstracts over the IR communication.
class PowerFunctionsAdapter
{
    private:
        PowerFunctions* _powerFunctions;

    public:
        // The constructor consumes the number of the pin to which
        // the infrared emitter diode is connected to.
	    PowerFunctionsAdapter(uint8_t);
        
        // Adjusts the orientation of the LEGO motor to the left.
        // The given value represents the extent to which the axis
        // moves to the left. Values must be in range [1; 7] in
        // order to be admissible. A value of 1 (minimum) results
        // in a minor adjustment of the axis, while a value of 7
        // (maximum) adjusts the axis to the left to full extent.
        // If the given value is either below the minimum or above
        // the maximum, it will get capped to the respective
        // extrema.
        void steerLeft(uint8_t);
        
        // Adjusts the orientation of the LEGO motor to the right.
        // The given value represents the extent to which the axis
        // moves to the right. Values must be in range [1; 7] in order
        // to be admissible. A value of 1 (minimum) results in a minor
        // adjustment of the axis, while a value of 7 (maximum) adjusts
        // the axis to the right to full extent. If the given value is
        // either below the minimum or above the maximum, it will get
        // capped to the respective extrema.
        void steerRight(uint8_t);
        
        // Adjusts the orientation of the LEGO motor by resetting
        // it to its center position.
        void center();
        
        // Adjusts the forward speed of the LEGO motor. The given value
        // represents the desired velocity, where admissible values
        // must be in range [1; 7]. A value of 1 (minimum) results in
        // a slow forward motion, while a value of 7 (maximum) results
        // in the fastest forward motion possible. If the given value
        // is either below the minimum or above the maximum, it will get
        // capped to the respective extrema.
        void accelerate(uint8_t);
        
        // Adjusts the backward speed of the LEGO motor. The given value
        // represents the desired velocity, where admissible values
        // must be in range [1; 7]. A value of 1 (minimum) results in
        // a slow backward motion, while a value of 7 (maximum) results
        // in the fastest backward motion possible. If the given value
        // is either below the minimum or above the maximum, it will get
        // capped to the respective extrema.
        void reverseAccelerate(uint8_t);
        
        // Stops the LEGO motor.
        void stop();
};

#endif //__POWERFUNCTIONSADAPTER_H__