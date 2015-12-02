#include "UAVObjGyroscopeHandler.h"

UAVObjGyroscopeHandler::UAVObjGyroscopeHandler()
{
}

UAVObjGyroscopeHandler::UAVObjGyroscopeHandler( uint32_t objId)
{
    switch(objId)
    {
    case ATTITUDESTATE_OBJID:
        mPacketName = "ATTITUDESTATE_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(AttitudeStateDataPacked);
        break;
    case GCSTELEMETRYSTATS_OBJID:
        mPacketName = "GCSTELEMETRYSTATS_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(GCSTelemetryStatsDataPacked);
        break;
    case FLIGHTTELEMETRYSTATS_OBJID:
        mPacketName = "FLIGHTTELEMETRYSTATS_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(FlightTelemetryStatsDataPacked);
        break;
    case SYSTEMSTATS_OBJID:
        mPacketName = "SYSTEMSTATS_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(SystemStatsDataPacked);
        break;
    case RATEDESIRED_OBJID:
        mPacketName = "RATEDESIRED_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(RateDesiredDataPacked);
        break;
    case ACCESSORYDESIRED_OBJID:
        mPacketName = "ACCESSORYDESIRED_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(AccessoryDesiredDataPacked);
        break;
    case STABILIZATIONSTATUS_OBJID:
        mPacketName = "STABILIZATIONSTATUS_OBJID";
        mObjId = objId;
        mPacketLength = sizeof(StabilizationStatusDataPacked);
        break;
    default:
        mObjId = 0;
        mPacketLength = 0;
        break;
    }
}

QString UAVObjGyroscopeHandler::getPacketName()
{
    return mPacketName;
}

uint32_t UAVObjGyroscopeHandler::getPacketLength()
{
    return mPacketLength;
}

uint32_t UAVObjGyroscopeHandler::getObjId()
{
    return mObjId;
}
