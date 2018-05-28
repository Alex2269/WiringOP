/*
 *
 * in the beginning it is necessary to establish library
 *  https://github.com/kazukioishi/WiringOP.git
 *  gcc  -o pblinking -O3 -Wall -I/usr/local/include -Winline -pipe -L/usr/local/lib pins_blinking.c -lwiringPi -lwiringPiDev -lpthread -lm
 *
 */

#include <stdio.h>
#include <wiringPi.h>

void blink_led(int pin, int count)
{
  int decade = count / 10;
  int remainder = count % 10;

  pinMode (pin, OUTPUT) ;
  digitalWrite (pin, 1) ;
  for (int i = 0; i < decade; i++)
  {
    digitalWrite (pin, 1) ;
    delay (50) ;
    digitalWrite (pin, 0) ;
    delay (50) ;
  }
  pinMode (pin, INPUT) ;

  delay (100) ;

  pinMode (pin, OUTPUT) ;
  digitalWrite (pin, 1) ;
  for (int i = 0; i < remainder; i++)
  {
    digitalWrite (pin, 1) ;
    delay (25) ;
    digitalWrite (pin, 0) ;
    delay (25) ;
  }
  pinMode (pin, INPUT) ;

}

int main (void)
{
  printf ("blinking by the board_led\n") ;
  printf ("established on orange pi pc2\n") ;
  printf ("\n") ;
  printf ("run and watch board board_led\n") ;

  wiringPiSetup () ;

  while(1)
  {
    for(int i = 23; i<26; i++)
    {
      blink_led(i,i);
    }
  }
}
