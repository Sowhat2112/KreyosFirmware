
#ifndef _BLE_HANDLER_H_
#define _BLE_HANDLER_H_

#include "stdint.h"
    // 0x000b VALUE-FFF1-READ | WRITE | DYNAMIC-
    // 0x000d VALUE-FFF2-READ | WRITE | DYNAMIC-
    // 0x000f VALUE-FFF3-READ | WRITE | DYNAMIC-
    // 0x0011 VALUE-FFF4-READ | WRITE | DYNAMIC-
    // 0x0013 VALUE-FFF5-READ | WRITE | DYNAMIC-
    // 0x0015 VALUE-FFF6-READ | WRITE | DYNAMIC-
    // 0x0017 VALUE-FFF7-READ | WRITE | DYNAMIC-
    // 0x0019 VALUE-FFF8-READ | WRITE | DYNAMIC-
    // 0x001b VALUE-FFF9-READ | WRITE | DYNAMIC-
    // 0x001d VALUE-FF10-READ | WRITE | DYNAMIC-
    // 0x001f VALUE-FF11-READ | WRITE | DYNAMIC-
    // 0x0021 VALUE-FF12-READ | WRITE | DYNAMIC-
    // 0x0023 VALUE-FF13-READ | WRITE | DYNAMIC-
    // 0x0025 VALUE-FF14-READ | WRITE | DYNAMIC-
    // 0x0027 VALUE-FF15-READ | WRITE | DYNAMIC-
    // 0x0029 VALUE-FF16-READ | WRITE | DYNAMIC-
    // 0x002b VALUE-FF17-READ | WRITE | DYNAMIC-
    // 0x002d VALUE-FF18-READ | WRITE | DYNAMIC-
    // 0x002f VALUE-FF19-READ | WRITE | DYNAMIC-
    // 0x0031 VALUE-FF20-READ | WRITE | DYNAMIC-
    // 0x0033 VALUE-FF21-READ | WRITE | DYNAMIC-
    // 0x0035 VALUE-FF22-READ | WRITE | DYNAMIC-
    // 0x0037 VALUE-FF23-READ | WRITE | DYNAMIC-
    // 0x0039 VALUE-FF24-READ | WRITE | DYNAMIC-
    // 0x003b VALUE-FF25-READ | WRITE | DYNAMIC-

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

#define BLE_HANDLE_UNLOCK_WATCH      ATT_CHARACTERISTIC_FFF1_01_VALUE_HANDLE
#define BLE_HANDLE_FW_VERSION        ATT_CHARACTERISTIC_FFF2_01_VALUE_HANDLE
#define BLE_HANDLE_DATETIME          ATT_CHARACTERISTIC_FFF3_01_VALUE_HANDLE
#define BLE_HANDLE_ALARM_0           ATT_CHARACTERISTIC_FFF4_01_VALUE_HANDLE
#define BLE_HANDLE_ALARM_1           ATT_CHARACTERISTIC_FFF5_01_VALUE_HANDLE
#define BLE_HANDLE_ALARM_2           ATT_CHARACTERISTIC_FFF6_01_VALUE_HANDLE
#define BLE_HANDLE_SPORTS_GRID       ATT_CHARACTERISTIC_FFF7_01_VALUE_HANDLE
#define BLE_HANDLE_SPORTS_DATA       ATT_CHARACTERISTIC_FFF8_01_VALUE_HANDLE
#define BLE_HANDLE_SPORTS_DESC       ATT_CHARACTERISTIC_FFF9_01_VALUE_HANDLE
#define BLE_HANDLE_DEVICE_ID         ATT_CHARACTERISTIC_FF10_01_VALUE_HANDLE
#define BLE_HANDLE_FILE_DESC         ATT_CHARACTERISTIC_FF11_01_VALUE_HANDLE
#define BLE_HANDLE_FILE_DATA         ATT_CHARACTERISTIC_FF12_01_VALUE_HANDLE
#define BLE_HANDLE_GPS_INFO          ATT_CHARACTERISTIC_FF13_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_GESTURE      ATT_CHARACTERISTIC_FF14_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_0 ATT_CHARACTERISTIC_FF15_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_1 ATT_CHARACTERISTIC_FF16_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_2 ATT_CHARACTERISTIC_FF17_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_3 ATT_CHARACTERISTIC_FF18_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_4 ATT_CHARACTERISTIC_FF19_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WORLDCLOCK_5 ATT_CHARACTERISTIC_FF20_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_WATCHFACE    ATT_CHARACTERISTIC_FF21_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_GOALS        ATT_CHARACTERISTIC_FF22_01_VALUE_HANDLE
#define BLE_HANDLE_CONF_USER_PROFILE ATT_CHARACTERISTIC_FF23_01_VALUE_HANDLE
#define BLE_HANDLE_TODAY_ACTIVITY    ATT_CHARACTERISTIC_FF24_01_VALUE_HANDLE
#define BLE_HANDLE_RESERVED_1        ATT_CHARACTERISTIC_FF25_01_VALUE_HANDLE

#define BLE_HANDLE_TYPE_INT8_ARR   0
#define BLE_HANDLE_TYPE_INT16_ARR  1
#define BLE_HANDLE_TYPE_INT32_ARR  2
#define BLE_HANDLE_TYPE_STRING     3

#define DEF_BLE_HANDLE(uuid, name, type, size) {uuid, #name, name, type, size}

typedef struct _ble_handle_t
{
    const char* characteristic;
    const char* name;
    const uint8_t handle;
    const uint8_t type;
    const uint8_t size;
}ble_handle_t;

const ble_handle_t* get_ble_handle(uint16_t handle);
uint8_t get_type_unit_size(uint8_t type);

#define ATT_HANDLE_MODE_READ  0x00
#define ATT_HANDLE_MODE_WRITE 0x01
uint16_t att_handler(uint16_t handle, uint16_t offset, uint8_t * buffer, uint16_t buffer_size, uint8_t mode);

#define SPORTS_SYNC_MODE_IDEL   0x00
#define SPORTS_SYNC_MODE_SPORTS 0x01
#define SPORTS_SYNC_MODE_SYNC   0x02
void ble_start_sync(uint8_t mode, uint8_t sports_type);
void ble_send_sports_data(uint32_t data[], uint8_t size);
void ble_stop_sync();

uint16_t BLE_READ_INT16(uint8_t* buf);
void BLE_WRITE_INT16(uint8_t* buf, uint16_t value);
#endif

