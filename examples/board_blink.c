/*
 * 
 * in the beginning it is necessary to establish library
 *  https://github.com/kazukioishi/WiringOP.git
 *  gcc  -o bblink -O3 -Wall -I/usr/local/include -Winline -pipe -L/usr/local/lib board_blink.c -lwiringPi -lwiringPiDev -lpthread -lm
 * 
 */

#include <stdio.h>
#include <wiringPi.h>

int main (void)
{
  int board_led = 25;

  printf ("blinking by the board_led\n") ;
  printf ("established on orange pi pc2\n") ;
  printf ("\n") ;
  printf ("run and watch board board_led\n") ;

  wiringPiSetup () ;

  pinMode (board_led, OUTPUT) ;

  for (;;)
  {
    digitalWrite (board_led, 1) ;
    delay (300) ;
    digitalWrite (board_led, 0) ;
    delay (300) ;
  }
}
