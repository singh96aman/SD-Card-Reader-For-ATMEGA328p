#include <sd.h>
#include <stdio.h>

const int chipSelect = 4;
int a[100], i=0;
unsigned long CurrentTime;
unsigned long ElapsedTime;
unsigned long StartTime;

int main() {
  // Open serial communications and wait for port to open:

  printf("intializing SD card");

  // see if the card is present and can be initialized:
  if (!sd_init(chipSelect)) {
    printf("Card failed, or not present");
    // don't do anything more:
    return 0;
  }
  printf("card initialized.");

  // open the file. note that only one file can be open at a time,
  // so you have to close this one before opening another.
  File dataFile = SD.open("test.txt");

  // if the file is available, write to it:
  if (dataFile) {
    while (dataFile.available()) {
      //Serial.write(dataFile.read());
      a[i]=dataFile.read();
      printf("%d",a[i]);
      i++;
      if(i==100)
        i=0;
    }
    dataFile.close();
  }
  // if the file isn't open, pop up an error:
  else {
    printf("error opening datalog.txt");
  }
///int d[]={34,56,23,76,23};
//LinearRegression(a);
}
