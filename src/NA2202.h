#ifndef __NA2202_H__
#define __NA2202_H__

#include <NA2202_2203_2204.h>

namespace NISD {

  /**
   * @class NA2202Class
   * @brief Subclass for providing parameters
   */
  class NA2202Class : public NA2202_2203_2204Class {

    using NA2202_2203_2204Class::NA2202_2203_2204Class;

    public:

    /**
     * @brief ADCDATA bit width.
     */
    static constexpr int bitWidth = 16;

    private:

    const int getBitWidth() override {
      return bitWidth;
    }

    const int* getRegLength() override {
      static constexpr int regLength[16] = {
        2, // 0x0
        2, // 0x1
        2, // 0x2
        2, // 0x3
        2, // 0x4
        2, // 0x5
        2, // 0x6
        2, // 0x7
        2, // 0x8
        2, // 0x9
        2, // 0xA
        2, // 0xB
        2, // 0xC
        2, // 0xD
        2, // 0xE
        2, // 0xF
      };
      return &regLength[0];
    }

  };

  NA2202Class NA2202(5e6, MOSI, MISO, SCK, SS, D9);

}

#endif // __NA2202_H__
