/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup PoiLocation PoiLocation 
 * @brief Contains the current Point of interest relative to @ref HomeLocation
 *
 * Autogenerated files and functions for PoiLocation Object
 *
 * @{ 
 *
 * @file       poilocation.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the PoiLocation object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: poilocation.xml. 
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

#ifndef POILOCATION_H
#define POILOCATION_H

/* Object constants */
#define POILOCATION_OBJID 0x17E829B8
#define POILOCATION_ISSINGLEINST 1
#define POILOCATION_ISSETTINGS 0
#define POILOCATION_ISPRIORITY 0
#define POILOCATION_NUMBYTES sizeof(PoiLocationData)

/* Generic interface functions */
int32_t PoiLocationInitialize();
UAVObjHandle PoiLocationHandle();
void PoiLocationSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float North;
    float East;
    float Down;
} __attribute__((packed)) PoiLocationDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef PoiLocationDataPacked __attribute__((aligned(4))) PoiLocationData;
    
/* Typesafe Object access functions */
static inline int32_t PoiLocationGet(PoiLocationData *dataOut) { return UAVObjGetData(PoiLocationHandle(), dataOut); }
static inline int32_t PoiLocationSet(const PoiLocationData *dataIn) { return UAVObjSetData(PoiLocationHandle(), dataIn); }
static inline int32_t PoiLocationInstGet(uint16_t instId, PoiLocationData *dataOut) { return UAVObjGetInstanceData(PoiLocationHandle(), instId, dataOut); }
static inline int32_t PoiLocationInstSet(uint16_t instId, const PoiLocationData *dataIn) { return UAVObjSetInstanceData(PoiLocationHandle(), instId, dataIn); }
static inline int32_t PoiLocationConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(PoiLocationHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t PoiLocationConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(PoiLocationHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t PoiLocationCreateInstance() { return UAVObjCreateInstance(PoiLocationHandle(), &PoiLocationSetDefaults); }
static inline void PoiLocationRequestUpdate() { UAVObjRequestUpdate(PoiLocationHandle()); }
static inline void PoiLocationRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(PoiLocationHandle(), instId); }
static inline void PoiLocationUpdated() { UAVObjUpdated(PoiLocationHandle()); }
static inline void PoiLocationInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(PoiLocationHandle(), instId); }
static inline void PoiLocationLogging() { UAVObjLogging(PoiLocationHandle()); }
static inline void PoiLocationInstLogging(uint16_t instId) { UAVObjInstanceLogging(PoiLocationHandle(), instId); }
static inline int32_t PoiLocationGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(PoiLocationHandle(), dataOut); }
static inline int32_t PoiLocationSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(PoiLocationHandle(), dataIn); }
static inline int8_t PoiLocationReadOnly() { return UAVObjReadOnly(PoiLocationHandle()); }

/* Field North information */

/* Field East information */

/* Field Down information */



/* Set/Get functions */
extern void PoiLocationNorthSet(float *NewNorth);
extern void PoiLocationNorthGet(float *NewNorth);
extern void PoiLocationEastSet(float *NewEast);
extern void PoiLocationEastGet(float *NewEast);
extern void PoiLocationDownSet(float *NewDown);
extern void PoiLocationDownGet(float *NewDown);


#endif // POILOCATION_H

/**
 * @}
 * @}
 */
