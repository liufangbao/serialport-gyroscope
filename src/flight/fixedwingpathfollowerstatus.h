/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup FixedWingPathFollowerStatus FixedWingPathFollowerStatus 
 * @brief Object Storing Debugging Information on PID internals
 *
 * Autogenerated files and functions for FixedWingPathFollowerStatus Object
 *
 * @{ 
 *
 * @file       fixedwingpathfollowerstatus.h
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the FixedWingPathFollowerStatus object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: fixedwingpathfollowerstatus.xml. 
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

#ifndef FIXEDWINGPATHFOLLOWERSTATUS_H
#define FIXEDWINGPATHFOLLOWERSTATUS_H

/* Object constants */
#define FIXEDWINGPATHFOLLOWERSTATUS_OBJID 0x35ED0888
#define FIXEDWINGPATHFOLLOWERSTATUS_ISSINGLEINST 1
#define FIXEDWINGPATHFOLLOWERSTATUS_ISSETTINGS 0
#define FIXEDWINGPATHFOLLOWERSTATUS_ISPRIORITY 0
#define FIXEDWINGPATHFOLLOWERSTATUS_NUMBYTES sizeof(FixedWingPathFollowerStatusData)

/* Generic interface functions */
int32_t FixedWingPathFollowerStatusInitialize();
UAVObjHandle FixedWingPathFollowerStatusHandle();
void FixedWingPathFollowerStatusSetDefaults(UAVObjHandle obj, uint16_t instId);

typedef struct __attribute__ ((__packed__)) {
    float Course;
    float Speed;
    float Power;
}  FixedWingPathFollowerStatusErrorData ;
typedef struct __attribute__ ((__packed__)) {
    float array[3];
}  FixedWingPathFollowerStatusErrorDataArray ;
#define FixedWingPathFollowerStatusErrorToArray( var ) UAVObjectFieldToArray( FixedWingPathFollowerStatusErrorData, var )

typedef struct __attribute__ ((__packed__)) {
    float Course;
    float Speed;
    float Power;
}  FixedWingPathFollowerStatusErrorIntData ;
typedef struct __attribute__ ((__packed__)) {
    float array[3];
}  FixedWingPathFollowerStatusErrorIntDataArray ;
#define FixedWingPathFollowerStatusErrorIntToArray( var ) UAVObjectFieldToArray( FixedWingPathFollowerStatusErrorIntData, var )

typedef struct __attribute__ ((__packed__)) {
    float Course;
    float Speed;
    float Power;
}  FixedWingPathFollowerStatusCommandData ;
typedef struct __attribute__ ((__packed__)) {
    float array[3];
}  FixedWingPathFollowerStatusCommandDataArray ;
#define FixedWingPathFollowerStatusCommandToArray( var ) UAVObjectFieldToArray( FixedWingPathFollowerStatusCommandData, var )

typedef struct __attribute__ ((__packed__)) {
    uint8_t Wind;
    uint8_t Stallspeed;
    uint8_t Lowspeed;
    uint8_t Highspeed;
    uint8_t Overspeed;
    uint8_t Lowpower;
    uint8_t Highpower;
    uint8_t Pitchcontrol;
}  FixedWingPathFollowerStatusErrorsData ;
typedef struct __attribute__ ((__packed__)) {
    uint8_t array[8];
}  FixedWingPathFollowerStatusErrorsDataArray ;
#define FixedWingPathFollowerStatusErrorsToArray( var ) UAVObjectFieldToArray( FixedWingPathFollowerStatusErrorsData, var )


/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    FixedWingPathFollowerStatusErrorData Error;
    FixedWingPathFollowerStatusErrorIntData ErrorInt;
    FixedWingPathFollowerStatusCommandData Command;
    FixedWingPathFollowerStatusErrorsData Errors;
} __attribute__((packed)) FixedWingPathFollowerStatusDataPacked;

/*
 * Packed Object data.
 * Alignment is forced to 4 bytes so as to avoid the potential for CPU usage faults
 * on Cortex M4F during load/store of float UAVO fields
 */
typedef FixedWingPathFollowerStatusDataPacked __attribute__((aligned(4))) FixedWingPathFollowerStatusData;
    
/* Typesafe Object access functions */
static inline int32_t FixedWingPathFollowerStatusGet(FixedWingPathFollowerStatusData *dataOut) { return UAVObjGetData(FixedWingPathFollowerStatusHandle(), dataOut); }
static inline int32_t FixedWingPathFollowerStatusSet(const FixedWingPathFollowerStatusData *dataIn) { return UAVObjSetData(FixedWingPathFollowerStatusHandle(), dataIn); }
static inline int32_t FixedWingPathFollowerStatusInstGet(uint16_t instId, FixedWingPathFollowerStatusData *dataOut) { return UAVObjGetInstanceData(FixedWingPathFollowerStatusHandle(), instId, dataOut); }
static inline int32_t FixedWingPathFollowerStatusInstSet(uint16_t instId, const FixedWingPathFollowerStatusData *dataIn) { return UAVObjSetInstanceData(FixedWingPathFollowerStatusHandle(), instId, dataIn); }
static inline int32_t FixedWingPathFollowerStatusConnectQueue(xQueueHandle queue) { return UAVObjConnectQueue(FixedWingPathFollowerStatusHandle(), queue, EV_MASK_ALL_UPDATES); }
static inline int32_t FixedWingPathFollowerStatusConnectCallback(UAVObjEventCallback cb) { return UAVObjConnectCallback(FixedWingPathFollowerStatusHandle(), cb, EV_MASK_ALL_UPDATES); }
static inline uint16_t FixedWingPathFollowerStatusCreateInstance() { return UAVObjCreateInstance(FixedWingPathFollowerStatusHandle(), &FixedWingPathFollowerStatusSetDefaults); }
static inline void FixedWingPathFollowerStatusRequestUpdate() { UAVObjRequestUpdate(FixedWingPathFollowerStatusHandle()); }
static inline void FixedWingPathFollowerStatusRequestInstUpdate(uint16_t instId) { UAVObjRequestInstanceUpdate(FixedWingPathFollowerStatusHandle(), instId); }
static inline void FixedWingPathFollowerStatusUpdated() { UAVObjUpdated(FixedWingPathFollowerStatusHandle()); }
static inline void FixedWingPathFollowerStatusInstUpdated(uint16_t instId) { UAVObjInstanceUpdated(FixedWingPathFollowerStatusHandle(), instId); }
static inline void FixedWingPathFollowerStatusLogging() { UAVObjLogging(FixedWingPathFollowerStatusHandle()); }
static inline void FixedWingPathFollowerStatusInstLogging(uint16_t instId) { UAVObjInstanceLogging(FixedWingPathFollowerStatusHandle(), instId); }
static inline int32_t FixedWingPathFollowerStatusGetMetadata(UAVObjMetadata *dataOut) { return UAVObjGetMetadata(FixedWingPathFollowerStatusHandle(), dataOut); }
static inline int32_t FixedWingPathFollowerStatusSetMetadata(const UAVObjMetadata *dataIn) { return UAVObjSetMetadata(FixedWingPathFollowerStatusHandle(), dataIn); }
static inline int8_t FixedWingPathFollowerStatusReadOnly() { return UAVObjReadOnly(FixedWingPathFollowerStatusHandle()); }

/* Field Error information */

// Array element names for field Error
typedef enum {
    FIXEDWINGPATHFOLLOWERSTATUS_ERROR_COURSE=0,
    FIXEDWINGPATHFOLLOWERSTATUS_ERROR_SPEED=1,
    FIXEDWINGPATHFOLLOWERSTATUS_ERROR_POWER=2
} FixedWingPathFollowerStatusErrorElem;

// Number of elements for field Error
#define FIXEDWINGPATHFOLLOWERSTATUS_ERROR_NUMELEM 3

/* Field ErrorInt information */

// Array element names for field ErrorInt
typedef enum {
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORINT_COURSE=0,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORINT_SPEED=1,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORINT_POWER=2
} FixedWingPathFollowerStatusErrorIntElem;

// Number of elements for field ErrorInt
#define FIXEDWINGPATHFOLLOWERSTATUS_ERRORINT_NUMELEM 3

/* Field Command information */

// Array element names for field Command
typedef enum {
    FIXEDWINGPATHFOLLOWERSTATUS_COMMAND_COURSE=0,
    FIXEDWINGPATHFOLLOWERSTATUS_COMMAND_SPEED=1,
    FIXEDWINGPATHFOLLOWERSTATUS_COMMAND_POWER=2
} FixedWingPathFollowerStatusCommandElem;

// Number of elements for field Command
#define FIXEDWINGPATHFOLLOWERSTATUS_COMMAND_NUMELEM 3

/* Field Errors information */

// Array element names for field Errors
typedef enum {
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_WIND=0,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_STALLSPEED=1,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_LOWSPEED=2,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_HIGHSPEED=3,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_OVERSPEED=4,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_LOWPOWER=5,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_HIGHPOWER=6,
    FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_PITCHCONTROL=7
} FixedWingPathFollowerStatusErrorsElem;

// Number of elements for field Errors
#define FIXEDWINGPATHFOLLOWERSTATUS_ERRORS_NUMELEM 8



/* Set/Get functions */
extern void FixedWingPathFollowerStatusErrorSet(FixedWingPathFollowerStatusErrorData *NewError);
extern void FixedWingPathFollowerStatusErrorGet(FixedWingPathFollowerStatusErrorData *NewError);
extern void FixedWingPathFollowerStatusErrorArraySet(float *NewError);
extern void FixedWingPathFollowerStatusErrorArrayGet(float *NewError);
extern void FixedWingPathFollowerStatusErrorIntSet(FixedWingPathFollowerStatusErrorIntData *NewErrorInt);
extern void FixedWingPathFollowerStatusErrorIntGet(FixedWingPathFollowerStatusErrorIntData *NewErrorInt);
extern void FixedWingPathFollowerStatusErrorIntArraySet(float *NewErrorInt);
extern void FixedWingPathFollowerStatusErrorIntArrayGet(float *NewErrorInt);
extern void FixedWingPathFollowerStatusCommandSet(FixedWingPathFollowerStatusCommandData *NewCommand);
extern void FixedWingPathFollowerStatusCommandGet(FixedWingPathFollowerStatusCommandData *NewCommand);
extern void FixedWingPathFollowerStatusCommandArraySet(float *NewCommand);
extern void FixedWingPathFollowerStatusCommandArrayGet(float *NewCommand);
extern void FixedWingPathFollowerStatusErrorsSet(FixedWingPathFollowerStatusErrorsData *NewErrors);
extern void FixedWingPathFollowerStatusErrorsGet(FixedWingPathFollowerStatusErrorsData *NewErrors);
extern void FixedWingPathFollowerStatusErrorsArraySet(uint8_t *NewErrors);
extern void FixedWingPathFollowerStatusErrorsArrayGet(uint8_t *NewErrors);


#endif // FIXEDWINGPATHFOLLOWERSTATUS_H

/**
 * @}
 * @}
 */
