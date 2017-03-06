#include <stdio.h>


#define LED_TRIGGER "/sys/classes/leds/led0/trigger"
#define LED "/sys/classes/leds/led0/brightness"

char readFirstCharFromFile(char* filename)
{
  // todo: obvious
}

void writeToFile(char* filename, char* value)
{
  // todo: obvious
}

void printLedStatus()
{
  printf("Status: ");
 
  char val = readFirstCharFromFile(LED);

  if (val == '1')
    printf("on");
  else if (val == '0')
    printf("off");
  else
    printf("unknown");

  printf("\n");

 }

int main(int argc, char **argv)
{

  if (argc == 2)
  {
    
    // If valid argument, remove possible triggers from led
    // so it is now under our control.
    if (argv[1][0] == '0' || argv[1][0] == '1')
      writeToFile(LED_TRIGGER, "none");
 
    if (argv[1][0] == '1')
      writeToFile(LED, "1");
    else if (argv[1][0] == '0')
      writeToFile(LED, "0");
    else
      printf("Unknown argument. Use 0 or 1.\n"); 
}

  printLedStatus();

  return 0;
}
