#include <stdio.h>

#define BUILTIN_LED_TRIGGER "/sys/class/leds/led0/trigger"
#define BUILTIN_LED "/sys/class/leds/led0/brightness"

void writeToFile(char* filename, char* value)
{
  FILE * pFile;
  pFile = fopen (filename, "w");
  if (pFile!=NULL)
  {
    fputs (value ,pFile);
    fclose (pFile);
  }
}

int main(int argc, char **argv)
{

  // First arg is program name; second is only valid if (startswith) 0 or 1
  if (argc == 2 && (argv[1][0] == '0' || argv[1][0] == '1'))
  {
    
    // Remove possible triggers from led
    // so it is now under our control. 
    // This only needs to be done for built-in led0. 
    writeToFile(BUILTIN_LED_TRIGGER, "none");

    // Set value
    if (argv[1][0] == '1')
      writeToFile(BUILTIN_LED, "1"); // On
    else if (argv[1][0] == '0')
      writeToFile(BUILTIN_LED, "0"); // Off
    
  }
  else
    printf("Usage: %s [0|1]\n", argv[0]);



  return 0;
}
