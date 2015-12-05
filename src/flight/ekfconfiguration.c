/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup EKFConfiguration EKFConfiguration
 * @brief Extended Kalman Filter initialisation
 *
 * Autogenerated files and functions for EKFConfiguration Object
 * @{ 
 *
 * @file       ekfconfiguration.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the EKFConfiguration object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: ekfconfiguration.xml. 
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
#include "ekfconfiguration.h"

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
int32_t EKFConfigurationInitialize(void)
{
    // Compile time assertion that the EKFConfigurationDataPacked and EKFConfigurationData structs
    // have the same size (though instances of EKFConfigurationData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(EKFConfigurationDataPacked) == sizeof(EKFConfigurationData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(EKFCONFIGURATION_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(EKFCONFIGURATION_OBJID,
        EKFCONFIGURATION_ISSINGLEINST, EKFCONFIGURATION_ISSETTINGS, EKFCONFIGURATION_ISPRIORITY, EKFCONFIGURATION_NUMBYTES, &EKFConfigurationSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void EKFConfigurationSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    EKFConfigurationData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(EKFConfigurationData));
    data.P.PositionNorth = 1.000000e+01f;
    data.P.PositionEast = 1.000000e+01f;
    data.P.PositionDown = 1.000000e+01f;
    data.P.VelocityNorth = 1.000000e+00f;
    data.P.VelocityEast = 1.000000e+00f;
    data.P.VelocityDown = 1.000000e+00f;
    data.P.AttitudeQ1 = 7.000000e-03f;
    data.P.AttitudeQ2 = 7.000000e-03f;
    data.P.AttitudeQ3 = 7.000000e-03f;
    data.P.AttitudeQ4 = 7.000000e-03f;
    data.P.GyroDriftX = 1.000000e-06f;
    data.P.GyroDriftY = 1.000000e-06f;
    data.P.GyroDriftZ = 1.000000e-06f;
    data.Q.GyroX = 1.000000e-02f;
    data.Q.GyroY = 1.000000e-02f;
    data.Q.GyroZ = 1.000000e-02f;
    data.Q.AccelX = 1.000000e-02f;
    data.Q.AccelY = 1.000000e-02f;
    data.Q.AccelZ = 1.000000e-02f;
    data.Q.GyroDriftX = 1.000000e-06f;
    data.Q.GyroDriftY = 1.000000e-06f;
    data.Q.GyroDriftZ = 1.000000e-06f;
    data.R.GPSPosNorth = 1.000000e+00f;
    data.R.GPSPosEast = 1.000000e+00f;
    data.R.GPSPosDown = 1.000000e+06f;
    data.R.GPSVelNorth = 1.000000e-03f;
    data.R.GPSVelEast = 1.000000e-03f;
    data.R.GPSVelDown = 1.000000e-03f;
    data.R.MagX = 1.000000e+01f;
    data.R.MagY = 1.000000e+01f;
    data.R.MagZ = 1.000000e+01f;
    data.R.BaroZ = 1.000000e-02f;
    data.FakeR.FakeGPSPosIndoor = 1.000000e+01f;
    data.FakeR.FakeGPSVelIndoor = 1.000000e+00f;
    data.FakeR.FakeGPSVelAirspeed = 1.000000e+03f;

    UAVObjSetInstanceData(obj, instId, &data);

    // Initialize object metadata to their default values
    if ( instId == 0 ) {
        UAVObjMetadata metadata;
        metadata.flags =
            ACCESS_READWRITE << UAVOBJ_ACCESS_SHIFT |
            ACCESS_READWRITE << UAVOBJ_GCS_ACCESS_SHIFT |
            1 << UAVOBJ_TELEMETRY_ACKED_SHIFT |
            1 << UAVOBJ_GCS_TELEMETRY_ACKED_SHIFT |
            UPDATEMODE_ONCHANGE << UAVOBJ_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_ONCHANGE << UAVOBJ_GCS_TELEMETRY_UPDATE_MODE_SHIFT |
            UPDATEMODE_MANUAL << UAVOBJ_LOGGING_UPDATE_MODE_SHIFT;
        metadata.telemetryUpdatePeriod = 0;
        metadata.gcsTelemetryUpdatePeriod = 0;
        metadata.loggingUpdatePeriod = 0;
        UAVObjSetMetadata(obj, &metadata);
    }
}

/**
 * Get object handle
 */
UAVObjHandle EKFConfigurationHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void EKFConfigurationPSet( EKFConfigurationPData *NewP )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewP, offsetof(EKFConfigurationData, P), 13*sizeof(float));
}
void EKFConfigurationPGet( EKFConfigurationPData *NewP )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewP, offsetof(EKFConfigurationData, P), 13*sizeof(float));
}
void EKFConfigurationPArraySet( float *NewP )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewP, offsetof(EKFConfigurationData, P), 13*sizeof(float));
}
void EKFConfigurationPArrayGet( float *NewP )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewP, offsetof(EKFConfigurationData, P), 13*sizeof(float));
}
void EKFConfigurationQSet( EKFConfigurationQData *NewQ )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewQ, offsetof(EKFConfigurationData, Q), 9*sizeof(float));
}
void EKFConfigurationQGet( EKFConfigurationQData *NewQ )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewQ, offsetof(EKFConfigurationData, Q), 9*sizeof(float));
}
void EKFConfigurationQArraySet( float *NewQ )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewQ, offsetof(EKFConfigurationData, Q), 9*sizeof(float));
}
void EKFConfigurationQArrayGet( float *NewQ )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewQ, offsetof(EKFConfigurationData, Q), 9*sizeof(float));
}
void EKFConfigurationRSet( EKFConfigurationRData *NewR )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewR, offsetof(EKFConfigurationData, R), 10*sizeof(float));
}
void EKFConfigurationRGet( EKFConfigurationRData *NewR )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewR, offsetof(EKFConfigurationData, R), 10*sizeof(float));
}
void EKFConfigurationRArraySet( float *NewR )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewR, offsetof(EKFConfigurationData, R), 10*sizeof(float));
}
void EKFConfigurationRArrayGet( float *NewR )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewR, offsetof(EKFConfigurationData, R), 10*sizeof(float));
}
void EKFConfigurationFakeRSet( EKFConfigurationFakeRData *NewFakeR )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewFakeR, offsetof(EKFConfigurationData, FakeR), 3*sizeof(float));
}
void EKFConfigurationFakeRGet( EKFConfigurationFakeRData *NewFakeR )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewFakeR, offsetof(EKFConfigurationData, FakeR), 3*sizeof(float));
}
void EKFConfigurationFakeRArraySet( float *NewFakeR )
{
    UAVObjSetDataField(EKFConfigurationHandle(), (void *)NewFakeR, offsetof(EKFConfigurationData, FakeR), 3*sizeof(float));
}
void EKFConfigurationFakeRArrayGet( float *NewFakeR )
{
    UAVObjGetDataField(EKFConfigurationHandle(), (void *)NewFakeR, offsetof(EKFConfigurationData, FakeR), 3*sizeof(float));
}


/**
 * @}
 */
