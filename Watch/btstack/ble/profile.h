
// profile.h generated from kreyos.gatt for BTstack

// binary representation
// attribute size in bytes (16), flags(16), handle (16), uuid (16/128), value(...)

#include <stdint.h>

const uint8_t profile_data[] =
{
    // 0x0001 PRIMARY_SERVICE-GAP_SERVICE
    0x0a, 0x00, 0x02, 0x00, 0x01, 0x00, 0x00, 0x28, 0x00, 0x18, 
//CHARACTERISTIC, GAP_DEVICE_NAME, READ, "Kreyos LE"
    // 0x0002 CHARACTERISTIC-GAP_APPEARANCE-READ
    0x0d, 0x00, 0x02, 0x00, 0x02, 0x00, 0x03, 0x28, 0x02, 0x03, 0x00, 0x01, 0x2a, 
    // 0x0003 VALUE-GAP_APPEARANCE-READ-00 00
    0x0a, 0x00, 0x02, 0x00, 0x03, 0x00, 0x01, 0x2a, 0x00, 0x00, 

    // 0x0004 PRIMARY_SERVICE-GATT_SERVICE
    0x0a, 0x00, 0x02, 0x00, 0x04, 0x00, 0x00, 0x28, 0x01, 0x18, 
    // 0x0005 CHARACTERISTIC-GATT_SERVICE_CHANGED-READ
    0x0d, 0x00, 0x02, 0x00, 0x05, 0x00, 0x03, 0x28, 0x02, 0x06, 0x00, 0x05, 0x2a, 
    // 0x0006 VALUE-GATT_SERVICE_CHANGED-READ-
    0x08, 0x00, 0x02, 0x00, 0x06, 0x00, 0x05, 0x2a, 

    // 0x0007 PRIMARY_SERVICE-FFF0
    0x0a, 0x00, 0x02, 0x00, 0x07, 0x00, 0x00, 0x28, 0xf0, 0xff, 
    // 0x0008 CHARACTERISTIC-FFF1-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x08, 0x00, 0x03, 0x28, 0x0a, 0x09, 0x00, 0xf1, 0xff, 
    // 0x0009 VALUE-FFF1-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x09, 0x00, 0xf1, 0xff, 
    // 0x000a CHARACTERISTIC-FFF2-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x0a, 0x00, 0x03, 0x28, 0x0a, 0x0b, 0x00, 0xf2, 0xff, 
    // 0x000b VALUE-FFF2-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x0b, 0x00, 0xf2, 0xff, 
    // 0x000c CHARACTERISTIC-FFF3-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x0c, 0x00, 0x03, 0x28, 0x0a, 0x0d, 0x00, 0xf3, 0xff, 
    // 0x000d VALUE-FFF3-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x0d, 0x00, 0xf3, 0xff, 
    // 0x000e CHARACTERISTIC-FFF4-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x0e, 0x00, 0x03, 0x28, 0x0a, 0x0f, 0x00, 0xf4, 0xff, 
    // 0x000f VALUE-FFF4-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x0f, 0x00, 0xf4, 0xff, 
    // 0x0010 CHARACTERISTIC-FFF5-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x10, 0x00, 0x03, 0x28, 0x0a, 0x11, 0x00, 0xf5, 0xff, 
    // 0x0011 VALUE-FFF5-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x11, 0x00, 0xf5, 0xff, 
    // 0x0012 CHARACTERISTIC-FFF6-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x12, 0x00, 0x03, 0x28, 0x0a, 0x13, 0x00, 0xf6, 0xff, 
    // 0x0013 VALUE-FFF6-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x13, 0x00, 0xf6, 0xff, 
    // 0x0014 CHARACTERISTIC-FFF7-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x14, 0x00, 0x03, 0x28, 0x0a, 0x15, 0x00, 0xf7, 0xff, 
    // 0x0015 VALUE-FFF7-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x15, 0x00, 0xf7, 0xff, 
    // 0x0016 CHARACTERISTIC-FFF8-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x16, 0x00, 0x03, 0x28, 0x0a, 0x17, 0x00, 0xf8, 0xff, 
    // 0x0017 VALUE-FFF8-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x17, 0x00, 0xf8, 0xff, 
    // 0x0018 CHARACTERISTIC-FFF9-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x18, 0x00, 0x03, 0x28, 0x0a, 0x19, 0x00, 0xf9, 0xff, 
    // 0x0019 VALUE-FFF9-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x19, 0x00, 0xf9, 0xff, 
    // 0x001a CHARACTERISTIC-FF10-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x1a, 0x00, 0x03, 0x28, 0x0a, 0x1b, 0x00, 0x10, 0xff, 
    // 0x001b VALUE-FF10-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x1b, 0x00, 0x10, 0xff, 
    // 0x001c CHARACTERISTIC-FF11-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x1c, 0x00, 0x03, 0x28, 0x0a, 0x1d, 0x00, 0x11, 0xff, 
    // 0x001d VALUE-FF11-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x1d, 0x00, 0x11, 0xff, 
    // 0x001e CHARACTERISTIC-FF12-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x1e, 0x00, 0x03, 0x28, 0x0a, 0x1f, 0x00, 0x12, 0xff, 
    // 0x001f VALUE-FF12-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x1f, 0x00, 0x12, 0xff, 
    // 0x0020 CHARACTERISTIC-FF13-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x20, 0x00, 0x03, 0x28, 0x0a, 0x21, 0x00, 0x13, 0xff, 
    // 0x0021 VALUE-FF13-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x21, 0x00, 0x13, 0xff, 
    // 0x0022 CHARACTERISTIC-FF14-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x22, 0x00, 0x03, 0x28, 0x0a, 0x23, 0x00, 0x14, 0xff, 
    // 0x0023 VALUE-FF14-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x23, 0x00, 0x14, 0xff, 
    // 0x0024 CHARACTERISTIC-FF15-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x24, 0x00, 0x03, 0x28, 0x0a, 0x25, 0x00, 0x15, 0xff, 
    // 0x0025 VALUE-FF15-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x25, 0x00, 0x15, 0xff, 
    // 0x0026 CHARACTERISTIC-FF16-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x26, 0x00, 0x03, 0x28, 0x0a, 0x27, 0x00, 0x16, 0xff, 
    // 0x0027 VALUE-FF16-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x27, 0x00, 0x16, 0xff, 
    // 0x0028 CHARACTERISTIC-FF17-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x28, 0x00, 0x03, 0x28, 0x0a, 0x29, 0x00, 0x17, 0xff, 
    // 0x0029 VALUE-FF17-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x29, 0x00, 0x17, 0xff, 
    // 0x002a CHARACTERISTIC-FF18-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x2a, 0x00, 0x03, 0x28, 0x0a, 0x2b, 0x00, 0x18, 0xff, 
    // 0x002b VALUE-FF18-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x2b, 0x00, 0x18, 0xff, 
    // 0x002c CHARACTERISTIC-FF19-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x2c, 0x00, 0x03, 0x28, 0x0a, 0x2d, 0x00, 0x19, 0xff, 
    // 0x002d VALUE-FF19-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x2d, 0x00, 0x19, 0xff, 
    // 0x002e CHARACTERISTIC-FF20-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x2e, 0x00, 0x03, 0x28, 0x0a, 0x2f, 0x00, 0x20, 0xff, 
    // 0x002f VALUE-FF20-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x2f, 0x00, 0x20, 0xff, 
    // 0x0030 CHARACTERISTIC-FF21-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x30, 0x00, 0x03, 0x28, 0x0a, 0x31, 0x00, 0x21, 0xff, 
    // 0x0031 VALUE-FF21-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x31, 0x00, 0x21, 0xff, 
    // 0x0032 CHARACTERISTIC-FF22-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x32, 0x00, 0x03, 0x28, 0x0a, 0x33, 0x00, 0x22, 0xff, 
    // 0x0033 VALUE-FF22-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x33, 0x00, 0x22, 0xff, 
    // 0x0034 CHARACTERISTIC-FF23-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x34, 0x00, 0x03, 0x28, 0x0a, 0x35, 0x00, 0x23, 0xff, 
    // 0x0035 VALUE-FF23-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x35, 0x00, 0x23, 0xff, 
    // 0x0036 CHARACTERISTIC-FF24-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x36, 0x00, 0x03, 0x28, 0x0a, 0x37, 0x00, 0x24, 0xff, 
    // 0x0037 VALUE-FF24-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x37, 0x00, 0x24, 0xff, 
    // 0x0038 CHARACTERISTIC-FF25-READ | WRITE | DYNAMIC
    0x0d, 0x00, 0x02, 0x00, 0x38, 0x00, 0x03, 0x28, 0x0a, 0x39, 0x00, 0x25, 0xff, 
    // 0x0039 VALUE-FF25-READ | WRITE | DYNAMIC-
    0x08, 0x00, 0x0a, 0x01, 0x39, 0x00, 0x25, 0xff, 
    // END
    0x00, 0x00, 
}; // total size 383 bytes 


//
// list mapping between characteristics and handles
//
#define ATT_CHARACTERISTIC_GAP_APPEARANCE_01_VALUE_HANDLE 0x0003
#define ATT_CHARACTERISTIC_GATT_SERVICE_CHANGED_01_VALUE_HANDLE 0x0006
#define ATT_CHARACTERISTIC_FFF1_01_VALUE_HANDLE 0x0009
#define ATT_CHARACTERISTIC_FFF2_01_VALUE_HANDLE 0x000b
#define ATT_CHARACTERISTIC_FFF3_01_VALUE_HANDLE 0x000d
#define ATT_CHARACTERISTIC_FFF4_01_VALUE_HANDLE 0x000f
#define ATT_CHARACTERISTIC_FFF5_01_VALUE_HANDLE 0x0011
#define ATT_CHARACTERISTIC_FFF6_01_VALUE_HANDLE 0x0013
#define ATT_CHARACTERISTIC_FFF7_01_VALUE_HANDLE 0x0015
#define ATT_CHARACTERISTIC_FFF8_01_VALUE_HANDLE 0x0017
#define ATT_CHARACTERISTIC_FFF9_01_VALUE_HANDLE 0x0019
#define ATT_CHARACTERISTIC_FF10_01_VALUE_HANDLE 0x001b
#define ATT_CHARACTERISTIC_FF11_01_VALUE_HANDLE 0x001d
#define ATT_CHARACTERISTIC_FF12_01_VALUE_HANDLE 0x001f
#define ATT_CHARACTERISTIC_FF13_01_VALUE_HANDLE 0x0021
#define ATT_CHARACTERISTIC_FF14_01_VALUE_HANDLE 0x0023
#define ATT_CHARACTERISTIC_FF15_01_VALUE_HANDLE 0x0025
#define ATT_CHARACTERISTIC_FF16_01_VALUE_HANDLE 0x0027
#define ATT_CHARACTERISTIC_FF17_01_VALUE_HANDLE 0x0029
#define ATT_CHARACTERISTIC_FF18_01_VALUE_HANDLE 0x002b
#define ATT_CHARACTERISTIC_FF19_01_VALUE_HANDLE 0x002d
#define ATT_CHARACTERISTIC_FF20_01_VALUE_HANDLE 0x002f
#define ATT_CHARACTERISTIC_FF21_01_VALUE_HANDLE 0x0031
#define ATT_CHARACTERISTIC_FF22_01_VALUE_HANDLE 0x0033
#define ATT_CHARACTERISTIC_FF23_01_VALUE_HANDLE 0x0035
#define ATT_CHARACTERISTIC_FF24_01_VALUE_HANDLE 0x0037
#define ATT_CHARACTERISTIC_FF25_01_VALUE_HANDLE 0x0039