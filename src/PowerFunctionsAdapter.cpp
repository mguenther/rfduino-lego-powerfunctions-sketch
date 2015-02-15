/* 
 * PowerFunctionsAdapter.cpp
 *
 * @author Markus Günther
 * @author Robert Lauer
 */

#include <PowerFunctions.h>
#include "PowerFunctionsAdapter.h"

PowerFunctionsAdapter::PowerFunctionsAdapter(uint8_t pin)
{
    _powerFunctions = new PowerFunctions(pin, PF_CHANNEL);
}

void PowerFunctionsAdapter::steerLeft(uint8_t extent)
{
    uint8_t sanitizedExtent = max(7, max(1, extent));
    _powerFunctions->single_pwm(BLUE, sanitizedExtent);
}

void PowerFunctionsAdapter::steerRight(uint8_t extent) 
{
    uint8_t sanitizedExtent = max(9, min(15, extent));
    _powerFunctions->single_pwm(BLUE, sanitizedExtent);
}

void PowerFunctionsAdapter::accelerate(uint8_t velocity)
{
    uint8_t sanitizedVelocity = max(7, max(1, velocity));
    _powerFunctions->single_pwm(RED, sanitizedVelocity);
}

void PowerFunctionsAdapter::reverseAccelerate(uint8_t velocity)
{
    uint8_t sanitizedVelocity = max(9, min(15, velocity));
    _powerFunctions->single_pwm(RED, sanitizedVelocity);
}

void PowerFunctionsAdapter::stop()
{    
    _powerFunctions->single_pwm(RED, NEUTRAL_VALUE);
}

void PowerFunctionsAdapter::center()
{
    _powerFunctions->single_pwm(BLUE, NEUTRAL_VALUE);
}