/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup MagState MagState 
 * @brief The filtered magnet vector.
 *
 * Autogenerated files and functions for MagState Object
 *
 * @{ 
 *
 * @file       magstate.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the MagState object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: magstate.xml. 
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

#ifndef MAGSTATE_H
#define MAGSTATE_H

/* Object constants */
#define MAGSTATE_OBJID 0x9FFEAA0C
#define MAGSTATE_ISSINGLEINST 1
#define MAGSTATE_ISSETTINGS 0
#define MAGSTATE_ISPRIORITY 0
#define MAGSTATE_NUMBYTES sizeof(MagStateData)

/* Generic interface functions */
int32_t MagStateInitialize();
UAVObjHandle MagStateHandle();
void MagStateSetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float x;
    float y;
    float z;
    uint8_t Source;
} __attribute__((packed)) MagStateDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef MagStateDataPacked __attribute__((aligned(4))) MagStateData;
    
/* Typesafe Object access functions */
static inline int32_t MagStateGet(MagStateData *dataOut) { return UAVObjGetData(MagStateHandle(), dataOut); }
static inline int32_t MagStateSet(const MagStateData *dataIn) { return UAVObjSetData(MagStateHandle(), dataIn); }
static inline int32_t MagStateInstGet(uint16_t instId, MagStateData *dataOut) { return UAVObjGetInstanceData(MagStateHandle(), instId, dataOut); }
static inline int32_t MagStateInstSet(uint16_t instId, const MagStateData *dataIn) { return UAVObjSetInstanceData(MagStateHandle(), instId, dataIn); }
static inline int32_t MagStateConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(MagStateHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t MagStateConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(MagStateHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t MagStateCreateInstance() { return UAVObjCreateInstance(MagStateHandle(), &MagStateSetDefaults); }
static inline void MagStateRequestUpdate() { UAVObjRequestUpdate(MagStateHandle()); }
static inline void MagStateRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(MagStateHandle(), instId); }
static inline void MagStateUpdated() { UAVObjUpdated(MagStateHandle()); }
static inline void MagStateInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(MagStateHandle(), instId); }
static inline void MagStateLogging() { UAVObjLogging(MagStateHandle()); }
static inline void MagStateInstLogging(uint16_t instId) { UAVObjInstanceLogging(MagStateHandle(), instId); }
static inline int32_t MagStateGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(MagStateHandle(), dataOut); }
static inline int32_t MagStateSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(MagStateHandle(), dataIn); }
static inline int8_t MagStateReadOnly() { return UAVObjReadOnly(MagStateHandle()); }

/* Field x information */

/* Field y information */

/* Field z information */

/* Field Source information */

// Enumeration options for field Source
typedef enum {
    MAGSTATE_SOURCE_INVALID=0,
    MAGSTATE_SOURCE_ONBOARD=1,
    MAGSTATE_SOURCE_AUX=2
} MagStateSourceOptions;



/* Set/Get functions */
extern void MagStatexSet(float *Newx);
extern void MagStatexGet(float *Newx);
extern void MagStateySet(float *Newy);
extern void MagStateyGet(float *Newy);
extern void MagStatezSet(float *Newz);
extern void MagStatezGet(float *Newz);
extern void MagStateSourceSet(uint8_t *NewSource);
extern void MagStateSourceGet(uint8_t *NewSource);


#endif // MAGSTATE_H

/**
 * @}
 * @}
 */
