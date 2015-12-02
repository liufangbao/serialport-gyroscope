#ifndef UAVOBJHANDLE_H
#define UAVOBJHANDLE_H

#include <QString>

typedef quint32 uint32_t;
typedef quint16 uint16_t;
typedef quint8 uint8_t;

typedef void * xQueueHandle;
#define PIOS_STATIC_ASSERT(test) ((void)sizeof(int[1 - 2 * !(test)]))
#include "uavobjectmanager.h"
/*
   how to generate include as following:
   cd src/flight
   sudo grep "_OBJID" -R *.h |awk -F : '{print "#include\"flight/"$1"\""}' >$PWD/../ObjIdIncludeList
   cp ObjIdIncludeList HERE
*/
#include"flight/accelgyrosettings.h"
#include"flight/accelsensor.h"
#include"flight/accelstate.h"
#include"flight/accessorydesired.h"
#include"flight/actuatorcommand.h"
#include"flight/actuatordesired.h"
#include"flight/actuatorsettings.h"
#include"flight/airspeedsensor.h"
#include"flight/airspeedsettings.h"
#include"flight/airspeedstate.h"
#include"flight/altitudefiltersettings.h"
#include"flight/altitudeholdsettings.h"
#include"flight/altitudeholdstatus.h"
#include"flight/attitudesettings.h"
#include"flight/attitudesimulated.h"
#include"flight/attitudestate.h"
#include"flight/auxmagsensor.h"
#include"flight/auxmagsettings.h"
#include"flight/barosensor.h"
#include"flight/callbackinfo.h"
#include"flight/cameradesired.h"
#include"flight/camerastabsettings.h"
#include"flight/debuglogcontrol.h"
#include"flight/debuglogentry.h"
#include"flight/debuglogsettings.h"
#include"flight/debuglogstatus.h"
#include"flight/ekfconfiguration.h"
#include"flight/ekfstatevariance.h"
#include"flight/faultsettings.h"
#include"flight/firmwareiapobj.h"
#include"flight/fixedwingpathfollowersettings.h"
#include"flight/fixedwingpathfollowerstatus.h"
#include"flight/flightbatterysettings.h"
#include"flight/flightbatterystate.h"
#include"flight/flightmodesettings.h"
#include"flight/flightplancontrol.h"
#include"flight/flightplansettings.h"
#include"flight/flightplanstatus.h"
#include"flight/flightstatus.h"
#include"flight/flighttelemetrystats.h"
#include"flight/gcsreceiver.h"
#include"flight/gcstelemetrystats.h"
#include"flight/gpsextendedstatus.h"
#include"flight/gpspositionsensor.h"
#include"flight/gpssatellites.h"
#include"flight/gpssettings.h"
#include"flight/gpstime.h"
#include"flight/gpsvelocitysensor.h"
#include"flight/groundtruth.h"
#include"flight/gyrosensor.h"
#include"flight/gyrostate.h"
#include"flight/homelocation.h"
#include"flight/hwsettings.h"
#include"flight/i2cstats.h"
#include"flight/magsensor.h"
#include"flight/magstate.h"
#include"flight/manualcontrolcommand.h"
#include"flight/manualcontrolsettings.h"
#include"flight/mixersettings.h"
#include"flight/mixerstatus.h"
#include"flight/mpu6000settings.h"
#include"flight/nedaccel.h"
#include"flight/objectpersistence.h"
#include"flight/oplinkreceiver.h"
#include"flight/oplinksettings.h"
#include"flight/oplinkstatus.h"
#include"flight/osdsettings.h"
#include"flight/overosyncsettings.h"
#include"flight/overosyncstats.h"
#include"flight/pathaction.h"
#include"flight/pathdesired.h"
#include"flight/pathplan.h"
#include"flight/pathstatus.h"
#include"flight/pathsummary.h"
#include"flight/perfcounter.h"
#include"flight/poilearnsettings.h"
#include"flight/poilocation.h"
#include"flight/positionstate.h"
#include"flight/radiocombridgestats.h"
#include"flight/ratedesired.h"
#include"flight/receiveractivity.h"
#include"flight/revocalibration.h"
#include"flight/revosettings.h"
#include"flight/sonaraltitude.h"
#include"flight/stabilizationbank.h"
#include"flight/stabilizationdesired.h"
#include"flight/stabilizationsettingsbank1.h"
#include"flight/stabilizationsettingsbank2.h"
#include"flight/stabilizationsettingsbank3.h"
#include"flight/stabilizationsettings.h"
#include"flight/stabilizationstatus.h"
#include"flight/systemalarms.h"
#include"flight/systemsettings.h"
#include"flight/systemstats.h"
#include"flight/takeofflocation.h"
#include"flight/taskinfo.h"
#include"flight/txpidsettings.h"
#include"flight/velocitydesired.h"
#include"flight/velocitystate.h"
#include"flight/vtolpathfollowersettings.h"
#include"flight/vtolselftuningstats.h"
#include"flight/watchdogstatus.h"
#include"flight/waypointactive.h"
#include"flight/waypoint.h"

class UAVObjGyroscopeHandler
{
    QString mPacketName;
    uint32_t mObjId;
    uint32_t mPacketLength;
public:
    UAVObjGyroscopeHandler();
    UAVObjGyroscopeHandler( uint32_t objId);
    QString getPacketName();
    uint32_t getObjId();
    uint32_t getPacketLength();
};

#endif // UAVOBJHANDLE_H
