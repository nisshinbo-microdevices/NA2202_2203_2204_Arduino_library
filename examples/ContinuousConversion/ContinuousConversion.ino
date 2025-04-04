#include <NA2204.h>

using NISD::NA2204;
using NISD::NA2204Class;

uint32_t prev = 0;

char strbuf[256];

void setup() {
  Serial.begin(115200);
  Serial.println("// begin setup");

  NA2204.begin();
  NA2204.clearSTBY();
  NA2204.reset();

  uint32_t rd;
  NA2204.read(NA2204Class::Address::OPTION, &rd);
  sprintf(strbuf, "// NA220%0d\n", (rd >> 8) - 0xA1 + 2);
  Serial.print(strbuf);

  uint32_t wd = NA2204Class::AFECONF::PGA2GAIN_X2 | NA2204Class::AFECONF::PGA1EN_ON | NA2204Class::AFECONF::PGA1GAIN_X2;
  NA2204.write(NA2204Class::Address::AFECONF, wd);
  wd = NA2204Class::CLKCONF::OSR_0BF;
  NA2204.write(NA2204Class::Address::CLKCONF, wd);
  wd = NA2204Class::CTRL::CHSELN_VIN1N | NA2204Class::CTRL::CHSELP_VIN1P |
       NA2204Class::CTRL::MODE_CONTINUOUS;
  NA2204.write(NA2204Class::Address::CTRL, wd);

  Serial.println("// end setup");

  prev = micros();
}

int32_t adcdata = 0;

void loop() {
  while (NA2204.readRDYB()) yield();
  uint32_t current = micros();
  uint8_t status = NA2204.readADCDATA(&adcdata);
  uint8_t rdycnt = (status >> 2) & 0x3;
  div_t t = div(current - prev, 1000);
  sprintf(strbuf, "RDYCNT:%0d,ADCDATA:%0ld,ConversionTime[ms]:%0d.%03d\n", rdycnt, adcdata, t.quot, t.rem);
  Serial.print(strbuf);
  prev = current;
}

