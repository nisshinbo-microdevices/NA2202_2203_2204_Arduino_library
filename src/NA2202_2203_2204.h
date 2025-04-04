#ifndef __NA2202_2203_2204_H__
#define __NA2202_2203_2204_H__

#include <SPI.h>

#ifndef D9
#  define D9 9
#endif

namespace NISD {

  /**
   * @class NA2202_2203_2204Class
   * @brief Base class for NA2202Class, NA2203Class and NA2204Class
   */
  class NA2202_2203_2204Class {
    public:

    /**
     * @enum Address
     * @brief Register address.
     */
    enum Address {
      CTRL      = 0x0, ///< 0x0
      ADCDATA   = 0x1, ///< 0x1
      IEXCONF   = 0x2, ///< 0x2
      AFECONF   = 0x3, ///< 0x3
      CLKCONF   = 0x4, ///< 0x4
      GPIOCTRL0 = 0x5, ///< 0x5
      GPIOCTRL1 = 0x6, ///< 0x6
      OPTION    = 0x7, ///< 0x7
      GAIN1     = 0x8, ///< 0x8
      GAIN2     = 0x9, ///< 0x9
      OFFSET1   = 0xC, ///< 0xC
      OFFSET2   = 0xD, ///< 0xD
    };

    /**
     * @enum CTRL
     * @brief CTRL register bits setting values.
     */
    enum CTRL {
      CHSELN_VIN1P                 = (0x0 << 12), ///< CHSELN: 0x0, VIN1P
      CHSELN_VIN1N                 = (0x1 << 12), ///< CHSELN: 0x1, VIN1N
      CHSELN_VIN2P                 = (0x2 << 12), ///< CHSELN: 0x2, VIN2P
      CHSELN_VIN2N                 = (0x3 << 12), ///< CHSELN: 0x3, VIN2N
      CHSELN_VIN3P                 = (0x4 << 12), ///< CHSELN: 0x4, VIN3P
      CHSELN_VIN3N                 = (0x5 << 12), ///< CHSELN: 0x5, VIN3N
      CHSELN_VIN4P                 = (0x6 << 12), ///< CHSELN: 0x6, VIN4P
      CHSELN_VIN4N                 = (0x7 << 12), ///< CHSELN: 0x7, VIN4N
      CHSELN_INTVREF               = (0x8 << 12), ///< CHSELN: 0x8, INTVREF
      CHSELN_AVSS                  = (0x9 << 12), ///< CHSELN: 0x9, AVSS
      CHSELN_VREFP                 = (0xA << 12), ///< CHSELN: 0xA, VREFP
      CHSELN_VREFN                 = (0xB << 12), ///< CHSELN: 0xB, VREFN
      CHSELN_TEMPP                 = (0xC << 12), ///< CHSELN: 0xC, TEMPP
      CHSELN_TEMPN                 = (0xD << 12), ///< CHSELN: 0xD, TEMPN
      CHSELN_AVDD                  = (0xE << 12), ///< CHSELN: 0xE, AVDD
      CHSELN_VCOM                  = (0xF << 12), ///< CHSELN: 0xF, VCOM
      CHSELP_VIN1P                 = (0x0 << 8),  ///< CHSELP: 0x0, VIN1P
      CHSELP_VIN1N                 = (0x1 << 8),  ///< CHSELP: 0x1, VIN1N
      CHSELP_VIN2P                 = (0x2 << 8),  ///< CHSELP: 0x2, VIN2P
      CHSELP_VIN2N                 = (0x3 << 8),  ///< CHSELP: 0x3, VIN2N
      CHSELP_VIN3P                 = (0x4 << 8),  ///< CHSELP: 0x4, VIN3P
      CHSELP_VIN3N                 = (0x5 << 8),  ///< CHSELP: 0x5, VIN3N
      CHSELP_VIN4P                 = (0x6 << 8),  ///< CHSELP: 0x6, VIN4P
      CHSELP_VIN4N                 = (0x7 << 8),  ///< CHSELP: 0x7, VIN4N
      CHSELP_INTVREF               = (0x8 << 8),  ///< CHSELP: 0x8, INTVREF
      CHSELP_AVSS                  = (0x9 << 8),  ///< CHSELP: 0x9, AVSS
      CHSELP_VREFP                 = (0xA << 8),  ///< CHSELP: 0xA, VREFP
      CHSELP_VREFN                 = (0xB << 8),  ///< CHSELP: 0xB, VREFN
      CHSELP_TEMPP                 = (0xC << 8),  ///< CHSELP: 0xC, TEMPP
      CHSELP_TEMPN                 = (0xD << 8),  ///< CHSELP: 0xD, TEMPN
      CHSELP_AVDD                  = (0xE << 8),  ///< CHSELP: 0xE, AVDD
      CHSELP_VCOM                  = (0xF << 8),  ///< CHSELP: 0xF, VCOM
      MODE_IDLE                    = 0x0,         ///< MODE: 0x0, Idle
      MODE_SLEEP                   = 0x1,         ///< MODE: 0x1, Sleep
      MODE_SINGLE                  = 0x2,         ///< MODE: 0x2, Single conversion
      MODE_CONTINUOUS              = 0x3,         ///< MODE: 0x3, Continuous conversion
      MODE_SINGLE_CHOP             = 0x4,         ///< MODE: 0x4, Single conversion + CHOP
      MODE_CONTINUOUS_CHOP         = 0x5,         ///< MODE: 0x5, Continuous conversion + CHOP
      MODE_SINGLE_CHOP_IEXCHOP     = 0x6,         ///< MODE: 0x6, Single conversion + CHOP + IEX CHOP
      MODE_CONTINUOUS_CHOP_IEXCHOP = 0x7,         ///< MODE: 0x7, Continuous conversion + CHOP + IEX CHOP
      MODE_CALIBRATION_OFFSET      = 0xC,         ///< MODE: 0xC, Calibration system offset
      MODE_CALIBRATION_GAIN        = 0xD,         ///< MODE: 0xD, Calibration system gain
      MODE_BOOT                    = 0xF,         ///< MODE: 0xF, Boot
    };

    /**
     * @enum IEXCONF
     * @brief IEXCONF register bits setting values.
     */
    enum IEXCONF {
      IEX2SLP_IEXC = (0x0 << 15), ///< IEX2SLP: 0x0, IEX2 current depends on IEX2C
      IEX2SLP_OFF  = (0x1 << 15), ///< IEX2SLP: 0x1, IEX2 OFF
      IEX2C_100UA  = (0x0 << 12), ///< IEX2C: 0x0, IEX2 current 100uA
      IEX2C_250UA  = (0x1 << 12), ///< IEX2C: 0x1, IEX2 current 250uA
      IEX2C_500UA  = (0x2 << 12), ///< IEX2C: 0x2, IEX2 current 500uA
      IEX2C_1MA    = (0x3 << 12), ///< IEX2C: 0x3, IEX2 current 1mA
      IEX2EN_OFF   = (0x0 << 11), ///< IEX2EN: 0x0, IEX2 OFF (Open)
      IEX2EN_ON    = (0x1 << 11), ///< IEX2EN: 0x1, IEX2 ON
      IEX2SW_VIN1P = (0x0 << 8),  ///< IEX2SW: 0x0, IEX2 connection VIN1P
      IEX2SW_VIN1N = (0x1 << 8),  ///< IEX2SW: 0x1, IEX2 connection VIN1N
      IEX2SW_VIN2P = (0x2 << 8),  ///< IEX2SW: 0x2, IEX2 connection VIN2P
      IEX2SW_VIN2N = (0x3 << 8),  ///< IEX2SW: 0x3, IEX2 connection VIN2N
      IEX2SW_VIN3P = (0x4 << 8),  ///< IEX2SW: 0x4, IEX2 connection VIN3P
      IEX2SW_VIN3N = (0x5 << 8),  ///< IEX2SW: 0x5, IEX2 connection VIN3N
      IEX2SW_VIN4P = (0x6 << 8),  ///< IEX2SW: 0x6, IEX2 connection VIN4P
      IEX2SW_VIN4N = (0x7 << 8),  ///< IEX2SW: 0x7, IEX2 connection VIN4N
      IEX1SLP_IEXC = (0x0 << 7),  ///< IEX1SLP: 0x0, IEX1 current depends on IEX1C
      IEX1SLP_OFF  = (0x1 << 7),  ///< IEX1SLP: 0x1, IEX1 OFF
      IEX1C_100UA  = (0x0 << 4),  ///< IEX1C: 0x0, IEX1 current 100uA
      IEX1C_250UA  = (0x1 << 4),  ///< IEX1C: 0x1, IEX1 current 250uA
      IEX1C_500UA  = (0x2 << 4),  ///< IEX1C: 0x2, IEX1 current 500uA
      IEX1C_1MA    = (0x3 << 4),  ///< IEX1C: 0x3, IEX1 current 1mA
      IEX1EN_OFF   = (0x0 << 3),  ///< IEX1EN: 0x0, IEX1 OFF (Open)
      IEX1EN_ON    = 0x1,         ///< IEX1EN: 0x1, IEX1 ON
      IEX1SW_VIN1P = 0x0,         ///< IEX1SW: 0x0, IEX1 connection VIN1P
      IEX1SW_VIN1N = 0x1,         ///< IEX1SW: 0x1, IEX1 connection VIN1N
      IEX1SW_VIN2P = 0x2,         ///< IEX1SW: 0x2, IEX1 connection VIN2P
      IEX1SW_VIN2N = 0x3,         ///< IEX1SW: 0x3, IEX1 connection VIN2N
      IEX1SW_VIN3P = 0x4,         ///< IEX1SW: 0x4, IEX1 connection VIN3P
      IEX1SW_VIN3N = 0x5,         ///< IEX1SW: 0x5, IEX1 connection VIN3N
      IEX1SW_VIN4P = 0x6,         ///< IEX1SW: 0x6, IEX1 connection VIN4P
      IEX1SW_VIN4N = 0x7,         ///< IEX1SW: 0x7, IEX1 connection VIN4N
    };

    /**
     * @enum AFECONF
     * @brief AFECONF register bits setting values.
     */
    enum AFECONF {
      LPWEN_NORMAL     = (0x0 << 15), ///< LPWEN: 0x0, Normal mode
      LPWEN_LOWPOWER   = (0x1 << 15), ///< LPWEN: 0x1, Low power mode.<br>ADC operating clock frequency (Fmod) becomes 1/4  of normal mode
      BCDIR_INP_TO_INN = (0x0 << 11), ///< BCDIR: 0x0, INPUTP:Source, INPUTN:Sink
      BCDIR_INN_TO_INP = (0x1 << 11), ///< BCDIR: 0x1, INPUTP:Sink,   INPUTN:Source
      BCEN_OFF         = (0x0 << 10), ///< BCEN: 0x0, OFF
      BCEN_ON          = (0x1 << 10), ///< BCEN: 0x1, Burn out current direction depends on BCDIR
      TEMPEN_OFF       = (0x0 << 9),  ///< TEMPEN: 0x0, Internal TEMP OFF
      TEMPEN_ON        = (0x1 << 9),  ///< TEMPEN: 0x1, Internal TEMP ON, TEMPP and TEMPN input are valid
      INTVREFEN_OFF    = (0x0 << 8),  ///< INTVREFEN: 0x0, External reference voltage VREFP / VREFN
      INTVREFEN_ON     = (0x1 << 8),  ///< INTVREFEN: 0x1, Internal reference voltage INTVREF / AVSS
      VREFSEL_VREF     = (0x0 << 6),  ///< VREFSEL: 0x0, REFP:VREFP, REFN:VREFN
      VREFSEL_INTVREF  = (0x1 << 6),  ///< VREFSEL: 0x1, REFP:INTVREF, REFN: AVSS
      VREFSEL_VIN4     = (0x2 << 6),  ///< VREFSEL: 0x2, REFP:VIN4P, REFN: VIN4N
      VREFSEL_AVDD     = (0x3 << 6),  ///< VREFSEL: 0x3, REFP:AVDD, REFN: AVSS
      PGA2GAIN_X1      = (0x0 << 4),  ///< PGA2GAIN: 0x0, PGA2 Gain x1
      PGA2GAIN_X2      = (0x1 << 4),  ///< PGA2GAIN: 0x1, PGA2 Gain x2
      PGA2GAIN_X4      = (0x2 << 4),  ///< PGA2GAIN: 0x2, PGA2 Gain x4
      PGA1EN_OFF       = (0x0 << 3),  ///< PGA1EN: 0x0, PGA1 OFF. Inputs are bypassed to ADC
      PGA1EN_ON        = (0x1 << 3),  ///< PGA1EN: 0x1, PGA1 ON
      PGA1GAIN_X1      = 0x0,         ///< PGA1GAIN: 0x0, PGA1 Gain x1
      PGA1GAIN_X2      = 0x1,         ///< PGA1GAIN: 0x1, PGA1 Gain x2
      PGA1GAIN_X4      = 0x2,         ///< PGA1GAIN: 0x2, PGA1 Gain x4
      PGA1GAIN_X8      = 0x3,         ///< PGA1GAIN: 0x3, PGA1 Gain x8
      PGA1GAIN_X16     = 0x4,         ///< PGA1GAIN: 0x4, PGA1 Gain x16
      PGA1GAIN_X21p33  = 0x5,         ///< PGA1GAIN: 0x5, PGA1 Gain x21.33
      PGA1GAIN_X32     = 0x6,         ///< PGA1GAIN: 0x6, PGA1 Gain x32
    };

    /**
     * @enum CLKCONF
     * @brief CLKCONF register bits setting values.
     *
     * Any value is selectable for OSR. Defined values are leading example.
     */
    enum CLKCONF {
      CLKSEL_INTERNAL = (0x0 << 14), ///< CLKSEL: 0x0, Internal oscillator
      CLKSEL_EXTERNAL = (0x1 << 14), ///< CLKSEL: 0x1, External clock
      CLKDIV_DIV2     = (0x0 << 12), ///< CLKDIV: 0x0, Fmod = Fsys/2 (Fsys/8 if LPWEN)
      CLKDIV_DIV4     = (0x1 << 12), ///< CLKDIV: 0x1, Fmod = Fsys/4 (Fsys/16 if LPWEN)
      CLKDIV_DIV8     = (0x2 << 12), ///< CLKDIV: 0x2, Fmod = Fsys/8
      CLKDIV_DIV16    = (0x3 << 12), ///< CLKDIV: 0x3, Fmod = Fsys/16
      REJ_NORMAL      = (0x0 << 10), ///< REJ: 0x0, Normal operation
      REJ_50_60HZ     = (0x1 << 10), ///< REJ: 0x1, 50Hz,60Hz rejection mode
      OSR_000         = 0x000,       ///< OSR: 0x000, Minimum: ( 0 + 1 ) * 64 = 64
      OSR_0BF         = 0x0BF,       ///< OSR: 0x0BF, 50Hz, 60Hz rejection mode selectable
      OSR_17F         = 0x17F,       ///< OSR: 0x17F, 50Hz, 60Hz rejection mode selectable
      OSR_2FF         = 0x2FF,       ///< OSR: 0x2FF, 50Hz, 60Hz rejection mode selectable
      OSR_3FF         = 0x3FF,       ///< OSR: 0x3FF Maximum: ( 1023 + 1 ) * 64 = 65536
    };

    /**
     * @enum GPIOCTRL0
     * @brief GPIOCTRL0 register bits setting values.
     */
    enum GPIOCTRL0 {
      DR_VIN4N_HIZ     = (0x0 << 15), ///< DR[7]: 0x0, Set the output driver to Hi-Z
      DR_VIN4N_PORTOUT = (0x1 << 15), ///< DR[7]: 0x1, Output the PORTOUT register level from output driver
      DR_VIN4P_HIZ     = (0x0 << 14), ///< DR[6]: 0x0, Set the output driver to Hi-Z
      DR_VIN4P_PORTOUT = (0x1 << 14), ///< DR[6]: 0x1, Output the PORTOUT register level from output driver
      DR_VIN3N_HIZ     = (0x0 << 13), ///< DR[5]: 0x0, Set the output driver to Hi-Z
      DR_VIN3N_PORTOUT = (0x1 << 13), ///< DR[5]: 0x1, Output the PORTOUT register level from output driver
      DR_VIN3P_HIZ     = (0x0 << 12), ///< DR[4]: 0x0, Set the output driver to Hi-Z
      DR_VIN3P_PORTOUT = (0x1 << 12), ///< DR[4]: 0x1, Output the PORTOUT register level from output driver
      PORTOUT_VIN4N_L  = (0x0 << 7),  ///< PORTOUT[7]: 0x0, Low
      PORTOUT_VIN4N_H  = (0x1 << 7),  ///< PORTOUT[7]: 0x1, Hight
      PORTOUT_VIN4P_L  = (0x0 << 6),  ///< PORTOUT[6]: 0x0, Low
      PORTOUT_VIN4P_H  = (0x1 << 6),  ///< PORTOUT[6]: 0x1, Hight
      PORTOUT_VIN3N_L  = (0x0 << 5),  ///< PORTOUT[5]: 0x0, Low
      PORTOUT_VIN3N_H  = (0x1 << 5),  ///< PORTOUT[5]: 0x1, Hight
      PORTOUT_VIN3P_L  = (0x0 << 4),  ///< PORTOUT[4]: 0x0, Low
      PORTOUT_VIN3P_H  = (0x1 << 4),  ///< PORTOUT[4]: 0x1, Hight
    };

    /**
     * @enum GPIOCTRL1
     * @brief GPIOCTRL1 register bits setting values.
     */
    enum GPIOCTRL1 {
      PORTIE_VIN4N_ANALOG = (0x0 << 15),  ///< PORTIE[7]: 0x0, Analog input
      PORTIE_VIN4N_LOGIC  = (0x1 << 15),  ///< PORTIE[7]: 0x1, Logic input
      PORTIE_VIN4P_ANALOG = (0x0 << 14),  ///< PORTIE[6]: 0x0, Analog input
      PORTIE_VIN4P_LOGIC  = (0x1 << 14),  ///< PORTIE[6]: 0x1, Logic input
      PORTIE_VIN3N_ANALOG = (0x0 << 13),  ///< PORTIE[5]: 0x0, Analog input
      PORTIE_VIN3N_LOGIC  = (0x1 << 13),  ///< PORTIE[5]: 0x1, Logic input
      PORTIE_VIN3P_ANALOG = (0x0 << 12),  ///< PORTIE[4]: 0x0, Analog input
      PORTIE_VIN3P_LOGIC  = (0x1 << 12),  ///< PORTIE[4]: 0x1, Logic input
    };

    /**
     * @enum OPTION
     * @brief OPTION register bits setting values.
     */
    enum OPTION {
      CEMODE_OFF    = (0x0 << 2), ///< CEMODE: 0x0, Disable error detection mode
      CEMODE_CRC8   = (0x2 << 2), ///< CEMODE: 0x2, CRC8 error detection mode
      CEMODE_CHKSUM = (0x3 << 2), ///< CEMODE: 0x3, Checksum error detection mode
      CE_CLEAR      = (0x1 << 1), ///< CE: Write 1 to this bit and this error detection flag is cleared
      AUTOSLP_IDLE  = 0x0,        ///< AUTOSLP: 0x0, Disable auto sleep
      AUTOSLP_SLEEP = 0x1,        ///< AUTOSLP: 0x1, Enable auto sleep
    };

    /**
     * @brief Constructor with specified SPI settings and pins.
     * @param sckfrq SPI clock frequency.
     * @param copi SPI MOSI pin.
     * @param cipo SPI MISO pin.
     * @param sclk SPI clock pin.
     * @param csb Chip select pin.
     * @param stby Standby pin.
     */
    NA2202_2203_2204Class(uint32_t sckfrq, uint32_t copi, uint32_t cipo, uint32_t sclk, uint32_t csb, uint32_t stby);

    /**
     * @brief Destructor.
     */
    ~NA2202_2203_2204Class();

    /**
     * @brief Initialize the interface and configure the pins.
     */
    void begin();

    /**
     * @brief End the communication.
     */
    void end();

    /**
     * @brief Reset using SPI reset command.
     */
    void reset();

    /**
     * @brief Clear the standby mode.
     */
    void clearSTBY();

    /**
     * @brief Set the standby mode.
     */
    void setSTBY();

    /**
     * @brief Read data from the specified register.
     * @param address Register address to read from.
     * @param data Pointer to store the read data.
     * @return Status byte.
     */
    uint8_t read(Address address, uint32_t* data);

    /**
     * @brief Write data to the specified register.
     * @param address Register address to write to.
     * @param data Data to write.
     * @return Status byte.
     */
    uint8_t write(Address address, uint32_t data);

    /**
     * @brief Read ADC data from the sensor.
     * @param adcdata Pointer to store the read ADC data.
     * @return Status byte.
     */
    uint8_t readADCDATA(int32_t* adcdata);

    /**
     * @brief Read the RDYB status.
     * @return RDYB status (0 or 1).
     */
    uint8_t readRDYB();

    private:

    SPISettings spiSettings; ///< Define SPI settings instance.

    uint32_t copi; ///< Define SPI COPI pin.
    uint32_t cipo; ///< Define SPI CIPO pin.
    uint32_t sclk; ///< Define SPI clock pin.
    uint32_t csb;  ///< Define chip select pin.
    uint32_t stby; ///< Define standby pin.

    virtual const int getBitWidth() = 0;
    virtual const int* getRegLength() = 0;

  };

}

#endif // __NA2202_2203_2204_H__
