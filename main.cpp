#include "mbed.h"
#include "hcsr04.h"

 
DigitalOut myled(LED1);
HCSR04  usensor(D8,D9);
unsigned int dist;
int main()
{
 
    while(1) {
        usensor.start();
        wait_ms(500); 
        dist=usensor.get_dist_cm();
        printf("\n\r cm:%ld",dist );
 
    }
}