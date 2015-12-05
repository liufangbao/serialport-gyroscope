/**
 ******************************************************************************
 * @addtogroup UAVObjects OpenPilot UAVObjects
 * @{ 
 * @addtogroup StabilizationSettings StabilizationSettings
 * @brief PID settings used by the Stabilization module to combine the @ref AttitudeActual and @ref AttitudeDesired to compute @ref ActuatorDesired
 *
 * Autogenerated files and functions for StabilizationSettings Object
 * @{ 
 *
 * @file       stabilizationsettings.c
 * @author     The OpenPilot Team, http://www.openpilot.org Copyright (C) 2010-2013.
 * @brief      Implementation of the StabilizationSettings object. This file has been 
 *             automatically generated by the UAVObjectGenerator.
 * 
 * @note       Object definition file: stabilizationsettings.xml. 
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
#include "stabilizationsettings.h"

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
int32_t StabilizationSettingsInitialize(void)
{
    // Compile time assertion that the StabilizationSettingsDataPacked and StabilizationSettingsData structs
    // have the same size (though instances of StabilizationSettingsData
    // should be placed in memory by the linker/compiler on a 4 byte alignment).
    PIOS_STATIC_ASSERT(sizeof(StabilizationSettingsDataPacked) == sizeof(StabilizationSettingsData));
    
    // Don't set the handle to null if already registered
    if (UAVObjGetByID(STABILIZATIONSETTINGS_OBJID)) {
        return -2;
    }

    // Register object with the object manager
    handle = UAVObjRegister(STABILIZATIONSETTINGS_OBJID,
        STABILIZATIONSETTINGS_ISSINGLEINST, STABILIZATIONSETTINGS_ISSETTINGS, STABILIZATIONSETTINGS_ISPRIORITY, STABILIZATIONSETTINGS_NUMBYTES, &StabilizationSettingsSetDefaults);

    // Done
    return handle ? 0 : -1;
}

/**
 * Initialize object fields and metadata with the default values.
 * If a default value is not specified the object fields
 * will be initialized to zero.
 */
void StabilizationSettingsSetDefaults(UAVObjHandle obj, uint16_t instId)
{
    StabilizationSettingsData data;

    // Initialize object fields to their default values
    UAVObjGetInstanceData(obj, instId, &data);
    memset(&data, 0, sizeof(StabilizationSettingsData));
    data.VbarSensitivity.Roll = 5.000000e-01f;
    data.VbarSensitivity.Pitch = 5.000000e-01f;
    data.VbarSensitivity.Yaw = 5.000000e-01f;
    data.VbarRollPI.Kp = 5.000000e-03f;
    data.VbarRollPI.Ki = 2.000000e-03f;
    data.VbarPitchPI.Kp = 5.000000e-03f;
    data.VbarPitchPI.Ki = 2.000000e-03f;
    data.VbarYawPI.Kp = 5.000000e-03f;
    data.VbarYawPI.Ki = 2.000000e-03f;
    data.VbarTau = 5.000000e-01f;
    data.GyroTau = 5.000000e-03f;
    data.DerivativeGamma = 1.000000e+00f;
    data.AxisLockKp = 2.500000e+00f;
    data.WeakLevelingKp = 1.000000e-01f;
    data.CruiseControlMaxPowerFactor = 3.000000e+00f;
    data.CruiseControlPowerTrim = 1.000000e+02f;
    data.CruiseControlPowerDelayComp = 2.500000e-01f;
    data.ScaleToAirspeed = 0.000000e+00f;
    data.ScaleToAirspeedLimits.Min = 5.000000e-02f;
    data.ScaleToAirspeedLimits.Max = 3.000000e+00f;
    data.FlightModeMap[0] = 0;
    data.FlightModeMap[1] = 0;
    data.FlightModeMap[2] = 0;
    data.FlightModeMap[3] = 0;
    data.FlightModeMap[4] = 0;
    data.FlightModeMap[5] = 0;
    data.VbarGyroSuppress = 30;
    data.VbarPiroComp = 0;
    data.VbarMaxAngle = 10;
    data.DerivativeCutoff = 20;
    data.MaxAxisLock = 30;
    data.MaxAxisLockRate = 2;
    data.MaxWeakLevelingRate = 5;
    data.RattitudeModeTransition = 80;
    data.CruiseControlMinThrust = 5;
    data.CruiseControlMaxThrust = 90;
    data.CruiseControlMaxAngle = 105;
    data.CruiseControlFlightModeSwitchPosEnable[0] = 0;
    data.CruiseControlFlightModeSwitchPosEnable[1] = 0;
    data.CruiseControlFlightModeSwitchPosEnable[2] = 0;
    data.CruiseControlFlightModeSwitchPosEnable[3] = 0;
    data.CruiseControlFlightModeSwitchPosEnable[4] = 0;
    data.CruiseControlFlightModeSwitchPosEnable[5] = 0;
    data.CruiseControlInvertedThrustReversing = 0;
    data.CruiseControlInvertedPowerOutput = 0;
    data.LowThrottleZeroIntegral = 1;
    data.FlightModeAssistMap[0] = 0;
    data.FlightModeAssistMap[1] = 0;
    data.FlightModeAssistMap[2] = 0;
    data.FlightModeAssistMap[3] = 0;
    data.FlightModeAssistMap[4] = 0;
    data.FlightModeAssistMap[5] = 0;

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
UAVObjHandle StabilizationSettingsHandle()
{
    return handle;
}

/**
 * Get/Set object Functions
 */
void StabilizationSettingsVbarSensitivitySet( StabilizationSettingsVbarSensitivityData *NewVbarSensitivity )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarSensitivity, offsetof(StabilizationSettingsData, VbarSensitivity), 3*sizeof(float));
}
void StabilizationSettingsVbarSensitivityGet( StabilizationSettingsVbarSensitivityData *NewVbarSensitivity )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarSensitivity, offsetof(StabilizationSettingsData, VbarSensitivity), 3*sizeof(float));
}
void StabilizationSettingsVbarSensitivityArraySet( float *NewVbarSensitivity )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarSensitivity, offsetof(StabilizationSettingsData, VbarSensitivity), 3*sizeof(float));
}
void StabilizationSettingsVbarSensitivityArrayGet( float *NewVbarSensitivity )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarSensitivity, offsetof(StabilizationSettingsData, VbarSensitivity), 3*sizeof(float));
}
void StabilizationSettingsVbarRollPISet( StabilizationSettingsVbarRollPIData *NewVbarRollPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarRollPI, offsetof(StabilizationSettingsData, VbarRollPI), 2*sizeof(float));
}
void StabilizationSettingsVbarRollPIGet( StabilizationSettingsVbarRollPIData *NewVbarRollPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarRollPI, offsetof(StabilizationSettingsData, VbarRollPI), 2*sizeof(float));
}
void StabilizationSettingsVbarRollPIArraySet( float *NewVbarRollPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarRollPI, offsetof(StabilizationSettingsData, VbarRollPI), 2*sizeof(float));
}
void StabilizationSettingsVbarRollPIArrayGet( float *NewVbarRollPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarRollPI, offsetof(StabilizationSettingsData, VbarRollPI), 2*sizeof(float));
}
void StabilizationSettingsVbarPitchPISet( StabilizationSettingsVbarPitchPIData *NewVbarPitchPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarPitchPI, offsetof(StabilizationSettingsData, VbarPitchPI), 2*sizeof(float));
}
void StabilizationSettingsVbarPitchPIGet( StabilizationSettingsVbarPitchPIData *NewVbarPitchPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarPitchPI, offsetof(StabilizationSettingsData, VbarPitchPI), 2*sizeof(float));
}
void StabilizationSettingsVbarPitchPIArraySet( float *NewVbarPitchPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarPitchPI, offsetof(StabilizationSettingsData, VbarPitchPI), 2*sizeof(float));
}
void StabilizationSettingsVbarPitchPIArrayGet( float *NewVbarPitchPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarPitchPI, offsetof(StabilizationSettingsData, VbarPitchPI), 2*sizeof(float));
}
void StabilizationSettingsVbarYawPISet( StabilizationSettingsVbarYawPIData *NewVbarYawPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarYawPI, offsetof(StabilizationSettingsData, VbarYawPI), 2*sizeof(float));
}
void StabilizationSettingsVbarYawPIGet( StabilizationSettingsVbarYawPIData *NewVbarYawPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarYawPI, offsetof(StabilizationSettingsData, VbarYawPI), 2*sizeof(float));
}
void StabilizationSettingsVbarYawPIArraySet( float *NewVbarYawPI )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarYawPI, offsetof(StabilizationSettingsData, VbarYawPI), 2*sizeof(float));
}
void StabilizationSettingsVbarYawPIArrayGet( float *NewVbarYawPI )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarYawPI, offsetof(StabilizationSettingsData, VbarYawPI), 2*sizeof(float));
}
void StabilizationSettingsVbarTauSet(float *NewVbarTau)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarTau, offsetof(StabilizationSettingsData, VbarTau), sizeof(float));
}
void StabilizationSettingsVbarTauGet(float *NewVbarTau)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarTau, offsetof(StabilizationSettingsData, VbarTau), sizeof(float));
}
void StabilizationSettingsGyroTauSet(float *NewGyroTau)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewGyroTau, offsetof(StabilizationSettingsData, GyroTau), sizeof(float));
}
void StabilizationSettingsGyroTauGet(float *NewGyroTau)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewGyroTau, offsetof(StabilizationSettingsData, GyroTau), sizeof(float));
}
void StabilizationSettingsDerivativeGammaSet(float *NewDerivativeGamma)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewDerivativeGamma, offsetof(StabilizationSettingsData, DerivativeGamma), sizeof(float));
}
void StabilizationSettingsDerivativeGammaGet(float *NewDerivativeGamma)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewDerivativeGamma, offsetof(StabilizationSettingsData, DerivativeGamma), sizeof(float));
}
void StabilizationSettingsAxisLockKpSet(float *NewAxisLockKp)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewAxisLockKp, offsetof(StabilizationSettingsData, AxisLockKp), sizeof(float));
}
void StabilizationSettingsAxisLockKpGet(float *NewAxisLockKp)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewAxisLockKp, offsetof(StabilizationSettingsData, AxisLockKp), sizeof(float));
}
void StabilizationSettingsWeakLevelingKpSet(float *NewWeakLevelingKp)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewWeakLevelingKp, offsetof(StabilizationSettingsData, WeakLevelingKp), sizeof(float));
}
void StabilizationSettingsWeakLevelingKpGet(float *NewWeakLevelingKp)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewWeakLevelingKp, offsetof(StabilizationSettingsData, WeakLevelingKp), sizeof(float));
}
void StabilizationSettingsCruiseControlMaxPowerFactorSet(float *NewCruiseControlMaxPowerFactor)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxPowerFactor, offsetof(StabilizationSettingsData, CruiseControlMaxPowerFactor), sizeof(float));
}
void StabilizationSettingsCruiseControlMaxPowerFactorGet(float *NewCruiseControlMaxPowerFactor)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxPowerFactor, offsetof(StabilizationSettingsData, CruiseControlMaxPowerFactor), sizeof(float));
}
void StabilizationSettingsCruiseControlPowerTrimSet(float *NewCruiseControlPowerTrim)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlPowerTrim, offsetof(StabilizationSettingsData, CruiseControlPowerTrim), sizeof(float));
}
void StabilizationSettingsCruiseControlPowerTrimGet(float *NewCruiseControlPowerTrim)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlPowerTrim, offsetof(StabilizationSettingsData, CruiseControlPowerTrim), sizeof(float));
}
void StabilizationSettingsCruiseControlPowerDelayCompSet(float *NewCruiseControlPowerDelayComp)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlPowerDelayComp, offsetof(StabilizationSettingsData, CruiseControlPowerDelayComp), sizeof(float));
}
void StabilizationSettingsCruiseControlPowerDelayCompGet(float *NewCruiseControlPowerDelayComp)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlPowerDelayComp, offsetof(StabilizationSettingsData, CruiseControlPowerDelayComp), sizeof(float));
}
void StabilizationSettingsScaleToAirspeedSet(float *NewScaleToAirspeed)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeed, offsetof(StabilizationSettingsData, ScaleToAirspeed), sizeof(float));
}
void StabilizationSettingsScaleToAirspeedGet(float *NewScaleToAirspeed)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeed, offsetof(StabilizationSettingsData, ScaleToAirspeed), sizeof(float));
}
void StabilizationSettingsScaleToAirspeedLimitsSet( StabilizationSettingsScaleToAirspeedLimitsData *NewScaleToAirspeedLimits )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeedLimits, offsetof(StabilizationSettingsData, ScaleToAirspeedLimits), 2*sizeof(float));
}
void StabilizationSettingsScaleToAirspeedLimitsGet( StabilizationSettingsScaleToAirspeedLimitsData *NewScaleToAirspeedLimits )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeedLimits, offsetof(StabilizationSettingsData, ScaleToAirspeedLimits), 2*sizeof(float));
}
void StabilizationSettingsScaleToAirspeedLimitsArraySet( float *NewScaleToAirspeedLimits )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeedLimits, offsetof(StabilizationSettingsData, ScaleToAirspeedLimits), 2*sizeof(float));
}
void StabilizationSettingsScaleToAirspeedLimitsArrayGet( float *NewScaleToAirspeedLimits )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewScaleToAirspeedLimits, offsetof(StabilizationSettingsData, ScaleToAirspeedLimits), 2*sizeof(float));
}
void StabilizationSettingsFlightModeMapSet( uint8_t *NewFlightModeMap )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewFlightModeMap, offsetof(StabilizationSettingsData, FlightModeMap), 6*sizeof(uint8_t));
}
void StabilizationSettingsFlightModeMapGet( uint8_t *NewFlightModeMap )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewFlightModeMap, offsetof(StabilizationSettingsData, FlightModeMap), 6*sizeof(uint8_t));
}
void StabilizationSettingsVbarGyroSuppressSet(int8_t *NewVbarGyroSuppress)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarGyroSuppress, offsetof(StabilizationSettingsData, VbarGyroSuppress), sizeof(int8_t));
}
void StabilizationSettingsVbarGyroSuppressGet(int8_t *NewVbarGyroSuppress)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarGyroSuppress, offsetof(StabilizationSettingsData, VbarGyroSuppress), sizeof(int8_t));
}
void StabilizationSettingsVbarPiroCompSet(uint8_t *NewVbarPiroComp)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarPiroComp, offsetof(StabilizationSettingsData, VbarPiroComp), sizeof(uint8_t));
}
void StabilizationSettingsVbarPiroCompGet(uint8_t *NewVbarPiroComp)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarPiroComp, offsetof(StabilizationSettingsData, VbarPiroComp), sizeof(uint8_t));
}
void StabilizationSettingsVbarMaxAngleSet(uint8_t *NewVbarMaxAngle)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewVbarMaxAngle, offsetof(StabilizationSettingsData, VbarMaxAngle), sizeof(uint8_t));
}
void StabilizationSettingsVbarMaxAngleGet(uint8_t *NewVbarMaxAngle)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewVbarMaxAngle, offsetof(StabilizationSettingsData, VbarMaxAngle), sizeof(uint8_t));
}
void StabilizationSettingsDerivativeCutoffSet(uint8_t *NewDerivativeCutoff)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewDerivativeCutoff, offsetof(StabilizationSettingsData, DerivativeCutoff), sizeof(uint8_t));
}
void StabilizationSettingsDerivativeCutoffGet(uint8_t *NewDerivativeCutoff)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewDerivativeCutoff, offsetof(StabilizationSettingsData, DerivativeCutoff), sizeof(uint8_t));
}
void StabilizationSettingsMaxAxisLockSet(uint8_t *NewMaxAxisLock)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewMaxAxisLock, offsetof(StabilizationSettingsData, MaxAxisLock), sizeof(uint8_t));
}
void StabilizationSettingsMaxAxisLockGet(uint8_t *NewMaxAxisLock)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewMaxAxisLock, offsetof(StabilizationSettingsData, MaxAxisLock), sizeof(uint8_t));
}
void StabilizationSettingsMaxAxisLockRateSet(uint8_t *NewMaxAxisLockRate)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewMaxAxisLockRate, offsetof(StabilizationSettingsData, MaxAxisLockRate), sizeof(uint8_t));
}
void StabilizationSettingsMaxAxisLockRateGet(uint8_t *NewMaxAxisLockRate)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewMaxAxisLockRate, offsetof(StabilizationSettingsData, MaxAxisLockRate), sizeof(uint8_t));
}
void StabilizationSettingsMaxWeakLevelingRateSet(uint8_t *NewMaxWeakLevelingRate)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewMaxWeakLevelingRate, offsetof(StabilizationSettingsData, MaxWeakLevelingRate), sizeof(uint8_t));
}
void StabilizationSettingsMaxWeakLevelingRateGet(uint8_t *NewMaxWeakLevelingRate)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewMaxWeakLevelingRate, offsetof(StabilizationSettingsData, MaxWeakLevelingRate), sizeof(uint8_t));
}
void StabilizationSettingsRattitudeModeTransitionSet(uint8_t *NewRattitudeModeTransition)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewRattitudeModeTransition, offsetof(StabilizationSettingsData, RattitudeModeTransition), sizeof(uint8_t));
}
void StabilizationSettingsRattitudeModeTransitionGet(uint8_t *NewRattitudeModeTransition)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewRattitudeModeTransition, offsetof(StabilizationSettingsData, RattitudeModeTransition), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlMinThrustSet(int8_t *NewCruiseControlMinThrust)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMinThrust, offsetof(StabilizationSettingsData, CruiseControlMinThrust), sizeof(int8_t));
}
void StabilizationSettingsCruiseControlMinThrustGet(int8_t *NewCruiseControlMinThrust)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMinThrust, offsetof(StabilizationSettingsData, CruiseControlMinThrust), sizeof(int8_t));
}
void StabilizationSettingsCruiseControlMaxThrustSet(uint8_t *NewCruiseControlMaxThrust)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxThrust, offsetof(StabilizationSettingsData, CruiseControlMaxThrust), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlMaxThrustGet(uint8_t *NewCruiseControlMaxThrust)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxThrust, offsetof(StabilizationSettingsData, CruiseControlMaxThrust), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlMaxAngleSet(uint8_t *NewCruiseControlMaxAngle)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxAngle, offsetof(StabilizationSettingsData, CruiseControlMaxAngle), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlMaxAngleGet(uint8_t *NewCruiseControlMaxAngle)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlMaxAngle, offsetof(StabilizationSettingsData, CruiseControlMaxAngle), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlFlightModeSwitchPosEnableSet( uint8_t *NewCruiseControlFlightModeSwitchPosEnable )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlFlightModeSwitchPosEnable, offsetof(StabilizationSettingsData, CruiseControlFlightModeSwitchPosEnable), 6*sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlFlightModeSwitchPosEnableGet( uint8_t *NewCruiseControlFlightModeSwitchPosEnable )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlFlightModeSwitchPosEnable, offsetof(StabilizationSettingsData, CruiseControlFlightModeSwitchPosEnable), 6*sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlInvertedThrustReversingSet(uint8_t *NewCruiseControlInvertedThrustReversing)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlInvertedThrustReversing, offsetof(StabilizationSettingsData, CruiseControlInvertedThrustReversing), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlInvertedThrustReversingGet(uint8_t *NewCruiseControlInvertedThrustReversing)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlInvertedThrustReversing, offsetof(StabilizationSettingsData, CruiseControlInvertedThrustReversing), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlInvertedPowerOutputSet(uint8_t *NewCruiseControlInvertedPowerOutput)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlInvertedPowerOutput, offsetof(StabilizationSettingsData, CruiseControlInvertedPowerOutput), sizeof(uint8_t));
}
void StabilizationSettingsCruiseControlInvertedPowerOutputGet(uint8_t *NewCruiseControlInvertedPowerOutput)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewCruiseControlInvertedPowerOutput, offsetof(StabilizationSettingsData, CruiseControlInvertedPowerOutput), sizeof(uint8_t));
}
void StabilizationSettingsLowThrottleZeroIntegralSet(uint8_t *NewLowThrottleZeroIntegral)
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewLowThrottleZeroIntegral, offsetof(StabilizationSettingsData, LowThrottleZeroIntegral), sizeof(uint8_t));
}
void StabilizationSettingsLowThrottleZeroIntegralGet(uint8_t *NewLowThrottleZeroIntegral)
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewLowThrottleZeroIntegral, offsetof(StabilizationSettingsData, LowThrottleZeroIntegral), sizeof(uint8_t));
}
void StabilizationSettingsFlightModeAssistMapSet( uint8_t *NewFlightModeAssistMap )
{
    UAVObjSetDataField(StabilizationSettingsHandle(), (void *)NewFlightModeAssistMap, offsetof(StabilizationSettingsData, FlightModeAssistMap), 6*sizeof(uint8_t));
}
void StabilizationSettingsFlightModeAssistMapGet( uint8_t *NewFlightModeAssistMap )
{
    UAVObjGetDataField(StabilizationSettingsHandle(), (void *)NewFlightModeAssistMap, offsetof(StabilizationSettingsData, FlightModeAssistMap), 6*sizeof(uint8_t));
}


/**
 * @}
 */
