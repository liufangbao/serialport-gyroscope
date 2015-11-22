#include "uavobjhandle.h"

UAVObjHandle::UAVObjHandle()
{
}

 UAVObjHandle::UAVObjHandle( uint32_t objId)
{
        switch(objId)
        {
            case ATTITUDESTATE_OBJID:
                    mObjId = objId;
                    mPacketLength = sizeof(AttitudeStateDataPacked);
                break;
            default:
                    mObjId = 0;
                     mPacketLength = 0;
                break;
        }
}

uint32_t UAVObjHandle::getPacketLength()
{
    return this->mPacketLength;
}

uint32_t UAVObjHandle::getObjId()
{
    return this->mObjId;
}
