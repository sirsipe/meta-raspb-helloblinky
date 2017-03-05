#include <stdio.h>


#define LED_TRIGGER "/sys/classes/leds/led0/trigger"
#define LED "/sys/classes/leds/led0/brightness"

char* readFile(char* filename)
{
  // todo: obvious
}

void writeToFile(char* filename, char* value)
{
  // todo: obvious
}

void removeTriggers()
{
  writeToFile(LED_TRIGGER, "none");
}

void setOnOff(bool on)
{

  removeTriggers();
 
  if (on)
    writeToFile(LED, "1");
  else
    writeToFile(LED, "0");

}

void printLedStatus()
{
  printf("Status: ");
 
  char* val = readFile(RED);

  if (val && val[0] == '1')
    printf("on");
  else if (val && val[0] == '0')
    printf("off");
  else
    printf("unknown");

  printf("\n");

 }

int main(int argc, char **argv)
{

  if (argc == 2)
  {
    if (argv[1][0] == '1')
      setOnOff(true);
    else if (argv[1][0] == '0')
      setOnOff(false);
  }

  printLedStatus();

  return 0;
}
