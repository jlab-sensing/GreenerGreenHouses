// RF settings for CC1125

typedef struct {
    uint8 iocfg3;           // GPIO3 IO Pin Configuration
    uint8 iocfg2;           // GPIO2 IO Pin Configuration
    uint8 iocfg1;           // GPIO1 IO Pin Configuration
    uint8 iocfg0;           // GPIO0 IO Pin Configuration
    uint8 sync_cfg1;        // Sync Word Detection Configuration Reg. 1
    uint8 deviation_m;      // Frequency Deviation Configuration
    uint8 modcfg_dev_e;     // Modulation Format and Frequency Deviation Configur..
    uint8 dcfilt_cfg;       // Digital DC Removal Configuration
    uint8 freq_if_cfg;      // RX Mixer Frequency Configuration
    uint8 iqic;             // Digital Image Channel Compensation Configuration
    uint8 chan_bw;          // Channel Filter Configuration
    uint8 mdmcfg0;          // General Modem Parameter Configuration Reg. 0
    uint8 symbol_rate2;     // Symbol Rate Configuration Exponent and Mantissa [1..
    uint8 symbol_rate1;     // Symbol Rate Configuration Mantissa [15:8]
    uint8 symbol_rate0;     // Symbol Rate Configuration Mantissa [7:0]
    uint8 agc_ref;          // AGC Reference Level Configuration
    uint8 agc_cs_thr;       // Carrier Sense Threshold Configuration
    uint8 agc_cfg1;         // Automatic Gain Control Configuration Reg. 1
    uint8 agc_cfg0;         // Automatic Gain Control Configuration Reg. 0
    uint8 fifo_cfg;         // FIFO Configuration
    uint8 settling_cfg;     // Frequency Synthesizer Calibration and Settling Con..
    uint8 fs_cfg;           // Frequency Synthesizer Configuration
    uint8 pkt_cfg0;         // Packet Configuration Reg. 0
    uint8 pkt_len;          // Packet Length Configuration
    uint8 if_mix_cfg;       // IF Mix Configuration
    uint8 freqoff_cfg;      // Frequency Offset Correction Configuration
    uint8 freq2;            // Frequency Configuration [23:16]
    uint8 freq1;            // Frequency Configuration [15:8]
    uint8 freq0;            // Frequency Configuration [7:0]
    uint8 if_adc0;          // Analog to Digital Converter Configuration Reg. 0
    uint8 fs_dig1;          // Frequency Synthesizer Digital Reg. 1
    uint8 fs_dig0;          // Frequency Synthesizer Digital Reg. 0
    uint8 fs_cal0;          // Frequency Synthesizer Calibration Reg. 0
    uint8 fs_divtwo;        // Frequency Synthesizer Divide by 2
    uint8 fs_dsm0;          // FS Digital Synthesizer Module Configuration Reg. 0
    uint8 fs_dvc0;          // Frequency Synthesizer Divider Chain Configuration ..
    uint8 fs_pfd;           // Frequency Synthesizer Phase Frequency Detector Con..
    uint8 fs_pre;           // Frequency Synthesizer Prescaler Configuration
    uint8 fs_reg_div_cml;   // Frequency Synthesizer Divider Regulator Configurat..
    uint8 fs_spare;         // Frequency Synthesizer Spare
    uint8 xosc5;            // Crystal Oscillator Configuration Reg. 5
    uint8 xosc3;            // Crystal Oscillator Configuration Reg. 3
    uint8 xosc1;            // Crystal Oscillator Configuration Reg. 1
    uint8 partnumber;       // Part Number
    uint8 partversion;      // Part Revision
    uint8 modem_status1;    // Modem Status Reg. 1
    uint8 xosc_test1;       // Crystal Oscillator Test Reg. 1
} RF_SETTINGS;