/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup GPSPositionSensor GPSPositionSensor
 * @brief Raw GPS data from @ref GPSModule.
 *
 * Autogenerated files and functions for GPSPositionSensor Object
 * @{ 
 *
 * @file       gpspositionsensor.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the GPSPositionSensor object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: gpspositionsensor.xml. 
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
#include "gpspositionsensor.h"

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
int32_t GPSPositionSensorInitialize(void)
{
    // Compile time assertion that the GPSPositionSensorDataPacked and GPSPositionSensorData structs
    // have the same size (though instances of GPSPositionSensorData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(GPSPositionSensorDataPacked) == sizeof(GPSPositionSensorData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(GPSPOSITIONSENSOR_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(GPSPOSITIONSENSOR_OBJID,
        GPSPOSITIONSENSOR_ISSINGLEINST, GPSPOSITIONSENSOR_ISSETTINGS, GPSPOSITIONSENSOR_ISPRIORITY, GPSPOSITIONSENSOR_NUMBYTES, &GPSPositionSensorSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void GPSPositionSensorSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    GPSPositionSensorData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(GPSPositionSensorData));
    data.SensorType = 0;
    data.AutoConfigStatus = 0;

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
UAVObjHandle GPSPositionSensorHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void GPSPositionSensorLatitudeSet(int32_t *NewLatitude)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewLatitude, offsetof(GPSPositionSensorData, Latitude), sizeof(int32_t));
}
void GPSPositionSensorLatitudeGet(int32_t *NewLatitude)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewLatitude, offsetof(GPSPositionSensorData, Latitude), sizeof(int32_t));
}
void GPSPositionSensorLongitudeSet(int32_t *NewLongitude)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewLongitude, offsetof(GPSPositionSensorData, Longitude), sizeof(int32_t));
}
void GPSPositionSensorLongitudeGet(int32_t *NewLongitude)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewLongitude, offsetof(GPSPositionSensorData, Longitude), sizeof(int32_t));
}
void GPSPositionSensorAltitudeSet(float *NewAltitude)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewAltitude, offsetof(GPSPositionSensorData, Altitude), sizeof(float));
}
void GPSPositionSensorAltitudeGet(float *NewAltitude)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewAltitude, offsetof(GPSPositionSensorData, Altitude), sizeof(float));
}
void GPSPositionSensorGeoidSeparationSet(float *NewGeoidSeparation)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewGeoidSeparation, offsetof(GPSPositionSensorData, GeoidSeparation), sizeof(float));
}
void GPSPositionSensorGeoidSeparationGet(float *NewGeoidSeparation)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewGeoidSeparation, offsetof(GPSPositionSensorData, GeoidSeparation), sizeof(float));
}
void GPSPositionSensorHeadingSet(float *NewHeading)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewHeading, offsetof(GPSPositionSensorData, Heading), sizeof(float));
}
void GPSPositionSensorHeadingGet(float *NewHeading)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewHeading, offsetof(GPSPositionSensorData, Heading), sizeof(float));
}
void GPSPositionSensorGroundspeedSet(float *NewGroundspeed)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewGroundspeed, offsetof(GPSPositionSensorData, Groundspeed), sizeof(float));
}
void GPSPositionSensorGroundspeedGet(float *NewGroundspeed)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewGroundspeed, offsetof(GPSPositionSensorData, Groundspeed), sizeof(float));
}
void GPSPositionSensorPDOPSet(float *NewPDOP)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewPDOP, offsetof(GPSPositionSensorData, PDOP), sizeof(float));
}
void GPSPositionSensorPDOPGet(float *NewPDOP)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewPDOP, offsetof(GPSPositionSensorData, PDOP), sizeof(float));
}
void GPSPositionSensorHDOPSet(float *NewHDOP)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewHDOP, offsetof(GPSPositionSensorData, HDOP), sizeof(float));
}
void GPSPositionSensorHDOPGet(float *NewHDOP)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewHDOP, offsetof(GPSPositionSensorData, HDOP), sizeof(float));
}
void GPSPositionSensorVDOPSet(float *NewVDOP)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewVDOP, offsetof(GPSPositionSensorData, VDOP), sizeof(float));
}
void GPSPositionSensorVDOPGet(float *NewVDOP)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewVDOP, offsetof(GPSPositionSensorData, VDOP), sizeof(float));
}
void GPSPositionSensorStatusSet(uint8_t *NewStatus)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewStatus, offsetof(GPSPositionSensorData, Status), sizeof(uint8_t));
}
void GPSPositionSensorStatusGet(uint8_t *NewStatus)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewStatus, offsetof(GPSPositionSensorData, Status), sizeof(uint8_t));
}
void GPSPositionSensorSatellitesSet(int8_t *NewSatellites)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewSatellites, offsetof(GPSPositionSensorData, Satellites), sizeof(int8_t));
}
void GPSPositionSensorSatellitesGet(int8_t *NewSatellites)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewSatellites, offsetof(GPSPositionSensorData, Satellites), sizeof(int8_t));
}
void GPSPositionSensorSensorTypeSet(uint8_t *NewSensorType)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewSensorType, offsetof(GPSPositionSensorData, SensorType), sizeof(uint8_t));
}
void GPSPositionSensorSensorTypeGet(uint8_t *NewSensorType)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewSensorType, offsetof(GPSPositionSensorData, SensorType), sizeof(uint8_t));
}
void GPSPositionSensorAutoConfigStatusSet(uint8_t *NewAutoConfigStatus)
{
    UAVObjSetDataField(GPSPositionSensorHandle(), (void *)NewAutoConfigStatus, offsetof(GPSPositionSensorData, AutoConfigStatus), sizeof(uint8_t));
}
void GPSPositionSensorAutoConfigStatusGet(uint8_t *NewAutoConfigStatus)
{
    UAVObjGetDataField(GPSPositionSensorHandle(), (void *)NewAutoConfigStatus, offsetof(GPSPositionSensorData, AutoConfigStatus), sizeof(uint8_t));
}


/**
 * @}
 */
