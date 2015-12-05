/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup AltitudeFilterSettings AltitudeFilterSettings 
 * @brief Settings for the @ref State Estimator module plugin altitudeFilter
 *
 * Autogenerated files and functions for AltitudeFilterSettings Object
 *
 * @{ 
 *
 * @file       altitudefiltersettings.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the AltitudeFilterSettings object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: altitudefiltersettings.xml. 
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

#ifndef ALTITUDEFILTERSETTINGS_H
#define ALTITUDEFILTERSETTINGS_H

/* Object constants */
#define ALTITUDEFILTERSETTINGS_OBJID 0xE611042C
#define ALTITUDEFILTERSETTINGS_ISSINGLEINST 1
#define ALTITUDEFILTERSETTINGS_ISSETTINGS 1
#define ALTITUDEFILTERSETTINGS_ISPRIORITY 0
#define ALTITUDEFILTERSETTINGS_NUMBYTES sizeof(AltitudeFilterSettingsData)

/* Generic interface functions */
int32_t AltitudeFilterSettingsInitialize();
UAVObjHandle AltitudeFilterSettingsHandle();
void AltitudeFilterSettingsSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float AccelLowPassKp;
    float AccelDriftKi;
    float InitializationAccelDriftKi;
    float BaroKp;
} __attribute__((packed)) AltitudeFilterSettingsDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef AltitudeFilterSettingsDataPacked __attribute__((aligned(4))) AltitudeFilterSettingsData;
    
/* Typesafe Object access functions */
static inline int32_t AltitudeFilterSettingsGet(AltitudeFilterSettingsData *dataOut) { return UAVObjGetData(AltitudeFilterSettingsHandle(), dataOut); }
static inline int32_t AltitudeFilterSettingsSet(const AltitudeFilterSettingsData *dataIn) { return UAVObjSetData(AltitudeFilterSettingsHandle(), dataIn); }
static inline int32_t AltitudeFilterSettingsInstGet(uint16_t instId, AltitudeFilterSettingsData *dataOut) { return UAVObjGetInstanceData(AltitudeFilterSettingsHandle(), instId, dataOut); }
static inline int32_t AltitudeFilterSettingsInstSet(uint16_t instId, const AltitudeFilterSettingsData *dataIn) { return UAVObjSetInstanceData(AltitudeFilterSettingsHandle(), instId, dataIn); }
static inline int32_t AltitudeFilterSettingsConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(AltitudeFilterSettingsHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t AltitudeFilterSettingsConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(AltitudeFilterSettingsHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t AltitudeFilterSettingsCreateInstance() { return UAVObjCreateInstance(AltitudeFilterSettingsHandle(), &AltitudeFilterSettingsSetDefaults); }
static inline void AltitudeFilterSettingsRequestUpdate() { UAVObjRequestUpdate(AltitudeFilterSettingsHandle()); }
static inline void AltitudeFilterSettingsRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(AltitudeFilterSettingsHandle(), instId); }
static inline void AltitudeFilterSettingsUpdated() { UAVObjUpdated(AltitudeFilterSettingsHandle()); }
static inline void AltitudeFilterSettingsInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(AltitudeFilterSettingsHandle(), instId); }
static inline void AltitudeFilterSettingsLogging() { UAVObjLogging(AltitudeFilterSettingsHandle()); }
static inline void AltitudeFilterSettingsInstLogging(uint16_t instId) { UAVObjInstanceLogging(AltitudeFilterSettingsHandle(), instId); }
static inline int32_t AltitudeFilterSettingsGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(AltitudeFilterSettingsHandle(), dataOut); }
static inline int32_t AltitudeFilterSettingsSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(AltitudeFilterSettingsHandle(), dataIn); }
static inline int8_t AltitudeFilterSettingsReadOnly() { return UAVObjReadOnly(AltitudeFilterSettingsHandle()); }

/* Field AccelLowPassKp information */

/* Field AccelDriftKi information */

/* Field InitializationAccelDriftKi information */

/* Field BaroKp information */



/* Set/Get functions */
extern void AltitudeFilterSettingsAccelLowPassKpSet(float *NewAccelLowPassKp);
extern void AltitudeFilterSettingsAccelLowPassKpGet(float *NewAccelLowPassKp);
extern void AltitudeFilterSettingsAccelDriftKiSet(float *NewAccelDriftKi);
extern void AltitudeFilterSettingsAccelDriftKiGet(float *NewAccelDriftKi);
extern void AltitudeFilterSettingsInitializationAccelDriftKiSet(float *NewInitializationAccelDriftKi);
extern void AltitudeFilterSettingsInitializationAccelDriftKiGet(float *NewInitializationAccelDriftKi);
extern void AltitudeFilterSettingsBaroKpSet(float *NewBaroKp);
extern void AltitudeFilterSettingsBaroKpGet(float *NewBaroKp);


#endif // ALTITUDEFILTERSETTINGS_H

/**
 * @}
 * @}
 */
