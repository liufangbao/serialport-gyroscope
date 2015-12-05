/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup Mpu6000Settings Mpu6000Settings 
 * @brief Settings for the @ref MPU6000 sensor used on CC3D and Revolution. Reboot the board for this to takes effect
 *
 * Autogenerated files and functions for Mpu6000Settings Object
 *
 * @{ 
 *
 * @file       mpu6000settings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the Mpu6000Settings object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: mpu6000settings.xml. 
 *             This is an automatically generated file.
 *             DO NOT modify manually.
 *
 * @see        The GNU Public License (GPL) Version 3
 *
 *****************************************************************************/
/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
 * or FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License
 * for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program; if not, write to the Free Software Foundation, Inc.,
 * 59 Temple Place, Suite 330, Boston, MA 02111-1307 USA
 */

#ifndef MPU6000SETTINGS_H
#define MPU6000SETTINGS_H

/* Object constants */
#define MPU6000SETTINGS_OBJID 0xA909AE7C
#define MPU6000SETTINGS_ISSINGLEINST 1
#define MPU6000SETTINGS_ISSETTINGS 1
#define MPU6000SETTINGS_ISPRIORITY 0
#define MPU6000SETTINGS_NUMBYTES sizeof(Mpu6000SettingsData)

/* Generic interface functions */
int32_t Mpu6000SettingsInitialize();
UAVObjHandle Mpu6000SettingsHandle();
void Mpu6000SettingsSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    uint8_t GyroScale;
    uint8_t AccelScale;
    uint8_t FilterSetting;
} __attribute__((packed)) Mpu6000SettingsDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef Mpu6000SettingsDataPacked __attribute__((aligned(4))) Mpu6000SettingsData;
    
/* Typesafe Object access functions */
static inline int32_t Mpu6000SettingsGet(Mpu6000SettingsData *dataOut) { return UAVObjGetData(Mpu6000SettingsHandle(), dataOut); }
static inline int32_t Mpu6000SettingsSet(const Mpu6000SettingsData *dataIn) { return UAVObjSetData(Mpu6000SettingsHandle(), dataIn); }
static inline int32_t Mpu6000SettingsInstGet(uint16_t instId, Mpu6000SettingsData *dataOut) { return UAVObjGetInstanceData(Mpu6000SettingsHandle(), instId, dataOut); }
static inline int32_t Mpu6000SettingsInstSet(uint16_t instId, const Mpu6000SettingsData *dataIn) { return UAVObjSetInstanceData(Mpu6000SettingsHandle(), instId, dataIn); }
static inline int32_t Mpu6000SettingsConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(Mpu6000SettingsHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t Mpu6000SettingsConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(Mpu6000SettingsHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t Mpu6000SettingsCreateInstance() { return UAVObjCreateInstance(Mpu6000SettingsHandle(), &Mpu6000SettingsSetDefaults); }
static inline void Mpu6000SettingsRequestUpdate() { UAVObjRequestUpdate(Mpu6000SettingsHandle()); }
static inline void Mpu6000SettingsRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(Mpu6000SettingsHandle(), instId); }
static inline void Mpu6000SettingsUpdated() { UAVObjUpdated(Mpu6000SettingsHandle()); }
static inline void Mpu6000SettingsInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(Mpu6000SettingsHandle(), instId); }
static inline void Mpu6000SettingsLogging() { UAVObjLogging(Mpu6000SettingsHandle()); }
static inline void Mpu6000SettingsInstLogging(uint16_t instId) { UAVObjInstanceLogging(Mpu6000SettingsHandle(), instId); }
static inline int32_t Mpu6000SettingsGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(Mpu6000SettingsHandle(), dataOut); }
static inline int32_t Mpu6000SettingsSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(Mpu6000SettingsHandle(), dataIn); }
static inline int8_t Mpu6000SettingsReadOnly() { return UAVObjReadOnly(Mpu6000SettingsHandle()); }

/* Field GyroScale information */

// Enumeration options for field GyroScale
typedef enum {
    MPU6000SETTINGS_GYROSCALE_SCALE_250=0,
    MPU6000SETTINGS_GYROSCALE_SCALE_500=1,
    MPU6000SETTINGS_GYROSCALE_SCALE_1000=2,
    MPU6000SETTINGS_GYROSCALE_SCALE_2000=3
} Mpu6000SettingsGyroScaleOptions;

/* Field AccelScale information */

// Enumeration options for field AccelScale
typedef enum {
    MPU6000SETTINGS_ACCELSCALE_SCALE_2G=0,
    MPU6000SETTINGS_ACCELSCALE_SCALE_4G=1,
    MPU6000SETTINGS_ACCELSCALE_SCALE_8G=2,
    MPU6000SETTINGS_ACCELSCALE_SCALE_16G=3
} Mpu6000SettingsAccelScaleOptions;

/* Field FilterSetting information */

// Enumeration options for field FilterSetting
typedef enum {
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_256_HZ=0,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_188_HZ=1,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_98_HZ=2,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_42_HZ=3,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_20_HZ=4,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_10_HZ=5,
    MPU6000SETTINGS_FILTERSETTING_LOWPASS_5_HZ=6
} Mpu6000SettingsFilterSettingOptions;



/* Set/Get functions */
extern void Mpu6000SettingsGyroScaleSet(uint8_t *NewGyroScale);
extern void Mpu6000SettingsGyroScaleGet(uint8_t *NewGyroScale);
extern void Mpu6000SettingsAccelScaleSet(uint8_t *NewAccelScale);
extern void Mpu6000SettingsAccelScaleGet(uint8_t *NewAccelScale);
extern void Mpu6000SettingsFilterSettingSet(uint8_t *NewFilterSetting);
extern void Mpu6000SettingsFilterSettingGet(uint8_t *NewFilterSetting);


#endif // MPU6000SETTINGS_H

/**
 * @}
 * @}
 */
