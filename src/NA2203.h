#ifndef __NA2203_H__
#define __NA2203_H__

#include <NA2202_2203_2204.h>

namespace NISD {

  /**
   * @class NA2203Class
   * @brief Subclass for providing parameters
   */
  class NA2203Class : public NA2202_2203_2204Class {

    using NA2202_2203_2204Class::NA2202_2203_2204Class;

    public:

    /**
     * @brief ADCDATA bit width.
     */
    static constexpr int bitWidth = 20;

    private:

    const int getBitWidth() override {
      return bitWidth;
    }

    const int* getRegLength() override {
      static constexpr int regLength[16] = {
        2, // 0x0
        3, // 0x1
        2, // 0x2
        2, // 0x3
        2, // 0x4
        2, // 0x5
        2, // 0x6
        2, // 0x7
        3, // 0x8
        3, // 0x9
        3, // 0xA
        3, // 0xB
        3, // 0xC
        3, // 0xD
        3, // 0xE
        3, // 0xF
      };
      return &regLength[0];
    }

  };

  NA2203Class NA2203(5e6, MOSI, MISO, SCK, SS, D9);

}

#endif // __NA2203_H__
