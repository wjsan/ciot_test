/**
 * @file ciot_custom_config.h
 * @author your name (you@domain.com)
 * @brief
 * @version 0.1
 * @date 2023-11-02
 *
 * @copyright Copyright (c) 2023
 *
 */

#ifndef __CIOT_CUSTOM_CONFIG__H__
#define __CIOT_CUSTOM_CONFIG__H__

#define CIOT_CONFIG_LOG_LEVEL CIOT_LOG_LEVEL_INFO
#define CIOT_TARGET_MONGOOSE
#define CIOT_CONFIG_APP_VER 0, 1, 0
#define CIOT_CONFIG_HARDWARE_NAME "CIOT BOARD"
#define CIOT_CONFIG_FEATURE_STORAGE 1       ///!< Enable Storage
#define CIOT_CONFIG_FEATURE_SYSTEM 1        ///!< Enable System
#define CIOT_CONFIG_FEATURE_UART 0          ///!< Enable UART
#define CIOT_CONFIG_FEATURE_USB 0           ///!< Enable USB
#define CIOT_CONFIG_FEATURE_BLE 0           ///!< Enable Bluetooth
#define CIOT_CONFIG_FEATURE_BLE_SCN 0       ///!< Enable Bluetooth Scanner
#define CIOT_CONFIG_FEATURE_ETHERNET 0      ///!< Enable Ethernet
#define CIOT_CONFIG_FEATURE_WIFI 0          ///!< Enable WiFi
#define CIOT_CONFIG_FEATURE_NTP 0           ///!< Enable NTP
#define CIOT_CONFIG_FEATURE_OTA 0           ///!< Enable OTA
#define CIOT_CONFIG_FEATURE_HTTPS 1         ///!< Enable HTTP Server
#define CIOT_CONFIG_FEATURE_HTTPC 1         ///!< Enable HTTP Client
#define CIOT_CONFIG_FEATURE_MQTTC 1         ///!< Enable MQTT Client
#define CIOT_CONFIG_FEATURE_BRIDGE 0        ///!< Enable Bridge Implementation
#define CIOT_CONFIG_MESSAGE_LEN 330         ///!< CIOT expected message size
#define CIOT_CONFIG_MESSAGE_PAYLOAD_LEN 256 ///< CIOT expected message payload size

#endif //!__CIOT_CUSTOM_CONFIG__H__