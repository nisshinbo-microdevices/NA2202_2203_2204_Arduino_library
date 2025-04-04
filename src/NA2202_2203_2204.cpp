#include "NA2202_2203_2204.h"

namespace NISD {

  NA2202_2203_2204Class::NA2202_2203_2204Class(uint32_t sckfrq, uint32_t copi, uint32_t cipo, uint32_t sclk, uint32_t csb, uint32_t stby) {
    this->spiSettings = SPISettings(sckfrq, MSBFIRST, SPI_MODE1);
    this->copi = copi;
    this->cipo = cipo;
    this->sclk = sclk;
    this->csb  = csb;
    this->stby = stby;
  }

  NA2202_2203_2204Class::~NA2202_2203_2204Class() { }

  void NA2202_2203_2204Class::begin() {
#ifdef ARDUINO_ARCH_STM32
    SPI.setMOSI(this->copi);
    SPI.setMISO(this->cipo);
    SPI.setSCLK(this->sclk);
#endif
    pinMode(this->stby, OUTPUT);
    pinMode(this->csb, OUTPUT);
    digitalWrite(this->csb, HIGH);

    SPI.begin();
  }

  void NA2202_2203_2204Class::end() {
    SPI.end();
  }

  void NA2202_2203_2204Class::reset() {
    SPI.beginTransaction(this->spiSettings);
    digitalWrite(this->csb, LOW);
    delay(1);
    SPI.transfer(0x7F);
    SPI.transfer(0xFF);
    SPI.transfer(0xFF);
    SPI.transfer(0xFF);
    SPI.transfer(0xFF);
    delay(1);
    digitalWrite(this->csb, HIGH);
    SPI.endTransaction();
  }

  void NA2202_2203_2204Class::clearSTBY() {
    digitalWrite(this->stby, LOW);
  }

  void NA2202_2203_2204Class::setSTBY() {
    digitalWrite(this->stby, HIGH);
  }

  uint8_t NA2202_2203_2204Class::read(Address address, uint32_t* data) {
    uint8_t status;
    SPI.beginTransaction(this->spiSettings);
    digitalWrite(this->csb, LOW);
    delay(1);
    status = SPI.transfer((address << 4) | 0x08);
    *data = 0;
    const int* regLength = this->getRegLength();
    for (int n = regLength[address] - 1; n >= 0 ; n--) {
      *data |= (uint32_t)SPI.transfer(0x00) << (n * 8);
    }
    delay(1);
    digitalWrite(this->csb, HIGH);
    SPI.endTransaction();
    return status;
  }

  uint8_t NA2202_2203_2204Class::write(Address address, uint32_t data) {
    uint8_t status;
    SPI.beginTransaction(this->spiSettings);
    digitalWrite(this->csb, LOW);
    delay(1);
    status = SPI.transfer((address << 4) | 0x00);
    const int* regLength = this->getRegLength();
    for (int n = regLength[address] - 1; n >= 0 ; n--) {
      SPI.transfer((uint8_t)((data >> (n * 8)) & 0xFF));
    }
    delay(1);
    digitalWrite(this->csb, HIGH);
    SPI.endTransaction();
    return status;
  }

  uint8_t NA2202_2203_2204Class::readADCDATA(int32_t* adcdata) {
    uint8_t status = this->read(Address::ADCDATA, (uint32_t*)adcdata);
    int bitWidth = this->getBitWidth();
    const int* regLength = this->getRegLength();
    *adcdata = (*adcdata << (32 - regLength[Address::ADCDATA] * 8)) >> (32 - bitWidth);
    return status;
  }

  uint8_t NA2202_2203_2204Class::readRDYB() {
    digitalWrite(this->csb, LOW);
    uint8_t rdyb = digitalRead(this->cipo);
    digitalWrite(this->csb, HIGH);
    return rdyb;
  }

}
