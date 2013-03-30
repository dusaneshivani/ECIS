/* Copyright (c) 2013 Prabhu Desai
 * pdtechworld@gmail.com
 *
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 * and associated documentation files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge, publish, distribute,
 * sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all copies or
 * substantial portions of the Software.
 *
 * For more details on the sensor :
 * http://www.elecfreaks.com/store/hcsr04-ultrasonic-sensor-distance-measuring-module-p-91.html?zenid=pgm8pgnvaodbe36dibq5s1soi3
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef MBED_HCSR04_H
#define MBED_HCSR04_H

#include "mbed.h"

/** Distance Measure Class(es)
 */

class DistMeasure
{
public:
    /** Create a DistMeasure object connected to the specified pin
    * @param pin i/o pin to connect to
    */
    DistMeasure(PinName TrigPin,PinName EchoPin);
    ~DistMeasure();

    /** Return the distance from obstacle in cm
    * @param distance in cms and returns -1, in case of failure
    */
 
    unsigned int get_dist_cm(void);
    unsigned int get_pulse_us(void);
    void start_measurement(void );
    void isr_rise(void);
    void isr_fall(void);
    void fall (void (*fptr)(void));
    void rise (void (*fptr)(void));
    


private:

    Timer pulsetime;
    DigitalOut  trigger;
    InterruptIn echo;
    unsigned int pulsedur;
    unsigned int distance;    
};

#endif