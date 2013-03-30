/* Copyright (c) 2013 Prabhu Desai
 * pdtechworld@gmail.com
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
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 * NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 * DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */


#include "hcsr04.h"


DistMeasure::DistMeasure(PinName TrigPin,PinName EchoPin,unsigned int maxtime):
    trigger(TrigPin), echo(EchoPin), timeout(maxtime)
{
    pulsetime.stop();
    pulsetime.reset();
   // this.rise(&DistMeasure::isr_rise);
   // this.fall(&DistMeasure::isr_fall);    
}


DistMeasure::~DistMeasure()
{
}

 
void DistMeasure::isr_rise(void)
{
    pulsetime.start();
}

void DistMeasure::isr_fall(void)
{
    pulsetime.stop();
    pulsedur = pulsetime.read_us();
    distance= (pulsedur*343)/20000;
    pulsetime.reset();
}
void DistMeasure::rise (void (*fptr)(void))
{
    echo.rise(fptr);
}
void DistMeasure::fall (void (*fptr)(void))
{
    echo.fall(fptr);
}

unsigned int DistMeasure::get_distance_cm()
{
    if(distance > 65530) {
        return -1;
    } else {
        return distance;
    }
}
