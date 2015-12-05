/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup SystemAlarms SystemAlarms
 * @brief Alarms from OpenPilot to indicate failure conditions or warnings.  Set by various modules.  Some modules may have a module defined Status and Substatus fields that details its condition.
 *
 * Autogenerated files and functions for SystemAlarms Object
 * @{ 
 *
 * @file       systemalarms.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the SystemAlarms object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: systemalarms.xml. 
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

#include <openpilot.h>
#include "systemalarms.h"

// Private variables
#if (defined(__MACH__) && defined(__APPLE__))
static UAVObjHandle handle __attribute__((section("__DATA,_uavo_handles")));
#else
static UAVObjHandle handle __attribute__((section("_uavo_handles")));
#endif

/**
 * Initialize object.
 * \return 0 Success
 * \return -1 Failure to initialize or -2 for already initialized
 */
int32_t SystemAlarmsInitialize(void)
{
    // Compile time assertion that the SystemAlarmsDataPacked and SystemAlarmsData structs
    // have the same size (though instances of SystemAlarmsData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(SystemAlarmsDataPacked) == sizeof(SystemAlarmsData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(SYSTEMALARMS_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(SYSTEMALARMS_OBJID,
        SYSTEMALARMS_ISSINGLEINST, SYSTEMALARMS_ISSETTINGS, SYSTEMALARMS_ISPRIORITY, SYSTEMALARMS_NUMBYTES, &SystemAlarmsSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void SystemAlarmsSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    SystemAlarmsData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(SystemAlarmsData));
    data.Alarm.SystemConfiguration = 0;
    data.Alarm.BootFault = 0;
    data.Alarm.OutOfMemory = 0;
    data.Alarm.StackOverflow = 0;
    data.Alarm.CPUOverload = 0;
    data.Alarm.EventSystem = 0;
    data.Alarm.Telemetry = 0;
    data.Alarm.Receiver = 0;
    data.Alarm.ManualControl = 0;
    data.Alarm.Actuator = 0;
    data.Alarm.Attitude = 0;
    data.Alarm.Sensors = 0;
    data.Alarm.Magnetometer = 0;
    data.Alarm.Airspeed = 0;
    data.Alarm.Stabilization = 0;
    data.Alarm.Guidance = 0;
    data.Alarm.PathPlan = 0;
    data.Alarm.Battery = 0;
    data.Alarm.FlightTime = 0;
    data.Alarm.I2C = 0;
    data.Alarm.GPS = 0;
    data.ExtendedAlarmStatus.SystemConfiguration = 0;
    data.ExtendedAlarmStatus.BootFault = 0;
    data.ExtendedAlarmSubStatus.SystemConfiguration = 0;
    data.ExtendedAlarmSubStatus.BootFault = 0;

    UAVObjSetInstanceData(obj, instId, &data);

    // Initialize object metadata to their default values
    if ( instId == 0 ) {
        UAVObjMetadata metadata;
        metadata.flags =
            ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
            ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
            0 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
            0 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
            UPDATEMODE_PERIODIC << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
        metadata.telemetryUpdatePeriod = 1000;
        metadata.gcsTelemetryUpdatePeriod = 0;
        metadata.loggingUpdatePeriod = 0;
        UAVObjSetMetadata(obj, &metadata);
    }
}

/**
 * Get object handle
 */
UAVObjHandle SystemAlarmsHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void SystemAlarmsAlarmSet( SystemAlarmsAlarmData *NewAlarm )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewAlarm, offsetof(SystemAlarmsData, Alarm), 21*sizeof(uint8_t));
}
void SystemAlarmsAlarmGet( SystemAlarmsAlarmData *NewAlarm )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewAlarm, offsetof(SystemAlarmsData, Alarm), 21*sizeof(uint8_t));
}
void SystemAlarmsAlarmArraySet( uint8_t *NewAlarm )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewAlarm, offsetof(SystemAlarmsData, Alarm), 21*sizeof(uint8_t));
}
void SystemAlarmsAlarmArrayGet( uint8_t *NewAlarm )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewAlarm, offsetof(SystemAlarmsData, Alarm), 21*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmStatusSet( SystemAlarmsExtendedAlarmStatusData *NewExtendedAlarmStatus )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmStatus, offsetof(SystemAlarmsData, ExtendedAlarmStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmStatusGet( SystemAlarmsExtendedAlarmStatusData *NewExtendedAlarmStatus )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmStatus, offsetof(SystemAlarmsData, ExtendedAlarmStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmStatusArraySet( uint8_t *NewExtendedAlarmStatus )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmStatus, offsetof(SystemAlarmsData, ExtendedAlarmStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmStatusArrayGet( uint8_t *NewExtendedAlarmStatus )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmStatus, offsetof(SystemAlarmsData, ExtendedAlarmStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmSubStatusSet( SystemAlarmsExtendedAlarmSubStatusData *NewExtendedAlarmSubStatus )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmSubStatus, offsetof(SystemAlarmsData, ExtendedAlarmSubStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmSubStatusGet( SystemAlarmsExtendedAlarmSubStatusData *NewExtendedAlarmSubStatus )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmSubStatus, offsetof(SystemAlarmsData, ExtendedAlarmSubStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmSubStatusArraySet( uint8_t *NewExtendedAlarmSubStatus )
{
    UAVObjSetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmSubStatus, offsetof(SystemAlarmsData, ExtendedAlarmSubStatus), 2*sizeof(uint8_t));
}
void SystemAlarmsExtendedAlarmSubStatusArrayGet( uint8_t *NewExtendedAlarmSubStatus )
{
    UAVObjGetDataField(SystemAlarmsHandle(), (void *)NewExtendedAlarmSubStatus, offsetof(SystemAlarmsData, ExtendedAlarmSubStatus), 2*sizeof(uint8_t));
}


/**
 * @}
 */
