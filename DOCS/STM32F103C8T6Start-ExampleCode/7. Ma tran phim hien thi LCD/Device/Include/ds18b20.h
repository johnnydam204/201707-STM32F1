#ifndef __DS18B20_H
#define __DS18B20_H
#include "main.h"
#ifndef __ONE_WIRE_H  
   #error Chua khai bao thu vien 1 WIRE. Hay khai bao #include "onewire.h"
#endif
float ds18b20_read(void); 
#endif
