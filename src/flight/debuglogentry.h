/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup DebugLogEntry DebugLogEntry 
 * @brief Log Entry in Flash
 *
 * Autogenerated files and functions for DebugLogEntry Object
 *
 * @{ 
 *
 * @file       debuglogentry.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the DebugLogEntry object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: debuglogentry.xml. 
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

#ifndef DEBUGLOGENTRY_H
#define DEBUGLOGENTRY_H

/* Object constants */
#define DEBUGLOGENTRY_OBJID 0x233CDCC0
#define DEBUGLOGENTRY_ISSINGLEINST 1
#define DEBUGLOGENTRY_ISSETTINGS 0
#define DEBUGLOGENTRY_ISPRIORITY 0
#define DEBUGLOGENTRY_NUMBYTES sizeof(DebugLogEntryData)

/* Generic interface functions */
int32_t DebugLogEntryInitialize();
UAVObjHandle DebugLogEntryHandle();
void DebugLogEntrySetDefaults(UAVObjHandle obj, uint16_t instId);


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    uint32_t FlightTime;
    uint32_t ObjectID;
    uint16_t Flight;
    uint16_t Entry;
    uint16_t InstanceID;
    uint16_t Size;
    uint8_t Type;
    uint8_t Data[200];
} __attribute__((packed)) DebugLogEntryDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef DebugLogEntryDataPacked __attribute__((aligned(4))) DebugLogEntryData;
    
/* Typesafe Object access functions */
static inline int32_t DebugLogEntryGet(DebugLogEntryData *dataOut) { return UAVObjGetData(DebugLogEntryHandle(), dataOut); }
static inline int32_t DebugLogEntrySet(const DebugLogEntryData *dataIn) { return UAVObjSetData(DebugLogEntryHandle(), dataIn); }
static inline int32_t DebugLogEntryInstGet(uint16_t instId, DebugLogEntryData *dataOut) { return UAVObjGetInstanceData(DebugLogEntryHandle(), instId, dataOut); }
static inline int32_t DebugLogEntryInstSet(uint16_t instId, const DebugLogEntryData *dataIn) { return UAVObjSetInstanceData(DebugLogEntryHandle(), instId, dataIn); }
static inline int32_t DebugLogEntryConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(DebugLogEntryHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t DebugLogEntryConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(DebugLogEntryHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t DebugLogEntryCreateInstance() { return UAVObjCreateInstance(DebugLogEntryHandle(), &DebugLogEntrySetDefaults); }
static inline void DebugLogEntryRequestUpdate() { UAVObjRequestUpdate(DebugLogEntryHandle()); }
static inline void DebugLogEntryRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(DebugLogEntryHandle(), instId); }
static inline void DebugLogEntryUpdated() { UAVObjUpdated(DebugLogEntryHandle()); }
static inline void DebugLogEntryInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(DebugLogEntryHandle(), instId); }
static inline void DebugLogEntryLogging() { UAVObjLogging(DebugLogEntryHandle()); }
static inline void DebugLogEntryInstLogging(uint16_t instId) { UAVObjInstanceLogging(DebugLogEntryHandle(), instId); }
static inline int32_t DebugLogEntryGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(DebugLogEntryHandle(), dataOut); }
static inline int32_t DebugLogEntrySetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(DebugLogEntryHandle(), dataIn); }
static inline int8_t DebugLogEntryReadOnly() { return UAVObjReadOnly(DebugLogEntryHandle()); }

/* Field FlightTime information */

/* Field ObjectID information */

/* Field Flight information */

/* Field Entry information */

/* Field InstanceID information */

/* Field Size information */

/* Field Type information */

// Enumeration options for field Type
typedef enum {
    DEBUGLOGENTRY_TYPE_EMPTY=0,
    DEBUGLOGENTRY_TYPE_TEXT=1,
    DEBUGLOGENTRY_TYPE_UAVOBJECT=2,
    DEBUGLOGENTRY_TYPE_MULTIPLEUAVOBJECTS=3
} DebugLogEntryTypeOptions;

/* Field Data information */

// Number of elements for field Data
#define DEBUGLOGENTRY_DATA_NUMELEM 200



/* Set/Get functions */
extern void DebugLogEntryFlightTimeSet(uint32_t *NewFlightTime);
extern void DebugLogEntryFlightTimeGet(uint32_t *NewFlightTime);
extern void DebugLogEntryObjectIDSet(uint32_t *NewObjectID);
extern void DebugLogEntryObjectIDGet(uint32_t *NewObjectID);
extern void DebugLogEntryFlightSet(uint16_t *NewFlight);
extern void DebugLogEntryFlightGet(uint16_t *NewFlight);
extern void DebugLogEntryEntrySet(uint16_t *NewEntry);
extern void DebugLogEntryEntryGet(uint16_t *NewEntry);
extern void DebugLogEntryInstanceIDSet(uint16_t *NewInstanceID);
extern void DebugLogEntryInstanceIDGet(uint16_t *NewInstanceID);
extern void DebugLogEntrySizeSet(uint16_t *NewSize);
extern void DebugLogEntrySizeGet(uint16_t *NewSize);
extern void DebugLogEntryTypeSet(uint8_t *NewType);
extern void DebugLogEntryTypeGet(uint8_t *NewType);
extern void DebugLogEntryDataSet(uint8_t *NewData);
extern void DebugLogEntryDataGet(uint8_t *NewData);


#endif // DEBUGLOGENTRY_H

/**
 * @}
 * @}
 */
