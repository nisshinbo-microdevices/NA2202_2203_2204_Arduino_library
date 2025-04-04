#include <NA2204.h>

using NISD::NA2204;
using NISD::NA2204Class;

int32_t adcdata = 0;
uint8_t status = 0;
double VREFN = 0.0;
double VREFP = 3.3;
double v25 = 0.74;
double tslope = -1.7e-3;
double tnom = 25.0;

static double codeToVoltage(int32_t adcdata, double vrefn, double vrefp) {
  return adcdata * (vrefp - vrefn) * 2 / ((uint32_t)1 << NA2204Class::bitWidth);
}

static double voltageToTemperature(double v) {
  return (v - v25) / tslope + tnom;
}

char strbuf[256];

void setup() {
  Serial.begin(9600);
  Serial.println("// begin setup");

  NA2204.begin();
  NA2204.clearSTBY();
  NA2204.reset();

  uint32_t rd;
  NA2204.read(NA2204Class::Address::OPTION, &rd);
  sprintf(strbuf, "// NA220%0d\n", (rd >> 8) - 0xA1 + 2);
  Serial.print(strbuf);

  uint32_t wd = NA2204Class::AFECONF::TEMPEN_ON |
                NA2204Class::AFECONF::PGA2GAIN_X1 | NA2204Class::AFECONF::PGA1EN_ON | NA2204Class::AFECONF::PGA1GAIN_X1;
  NA2204.write(NA2204Class::Address::AFECONF, wd);

  Serial.println("// end setup");
}

void loop() {
  NA2204.write(NA2204Class::Address::CTRL, NA2204Class::CTRL::CHSELN_TEMPN | NA2204Class::CTRL::CHSELP_TEMPP |
                                           NA2204Class::CTRL::MODE_SINGLE);
  delay(1000);
  status = NA2204.readADCDATA(&adcdata);
  double v = codeToVoltage(adcdata, VREFN, VREFP);
  double temp = voltageToTemperature(v);
  // double to string
  char buf[9];
  dtostrf(temp, -1, 3, buf);
  sprintf(strbuf, "Temperature[°C]:%0s\n", buf);
  Serial.print(strbuf);
}

