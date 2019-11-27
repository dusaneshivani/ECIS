/** 
Group 1: Electronically Controlled Intelligent Systems
Team Members: Priyank Kalgaonkar, Sahil Kumar, Linknath Balasubramanian
ECE53301 - Final Project - Fall 2019
**/
#include "mbed.h"
#include "hcsr04.h"
 
DigitalOut RLed(LED1);                  //Onboard Red LED = Warning
DigitalOut GLed(LED2);                  //Onboard Green LED = All OK
DigitalOut BLed(LED3);                  //Onboard Blue LED = Wifi Tx
HCSR04 usensor1(D8,D9);                 //ECHO Pin=D9, TRIG Pin=D8

float distance;                  //distance=int for faster program exec.
float dist_remaining;
float dist_percent;

int main()
{
    int a = 30;
    while(1) {
        usensor1.start();
        wait_ms(1000); 
        distance = usensor1.get_dist_cm();
        dist_remaining = a-distance;
        dist_percent = (dist_remaining/30)*100;
        
        if (distance<30) {
            RLed = 1;
            BLed = 1;
            GLed = 0;
            printf("\rPercent remaining: %f\r", dist_percent);
        } else {
            GLed = 1;
            BLed = 1;
            RLed = 0;
            printf("\rShelf Empty. Replenish Stock!\r");
        }
    }
}