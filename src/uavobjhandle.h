#ifndef UAVOBJHANDLE_H
#define UAVOBJHANDLE_H

typedef unsigned int uint32_t;

/*
 * Packed Object data (unaligned).
 * Should only be used where 4 byte alignment can be guaranteed
 * (eg a single instance on the heap)
 */
typedef struct {
    float q1;
    float q2;
    float q3;
    float q4;
    float Roll;
    float Pitch;
    float Yaw;
} __attribute__((packed)) AttitudeStateDataPacked;
#define ATTITUDESTATE_OBJID 0xD7E0D964

class UAVObjHandle
{
    uint32_t mObjId;
    uint32_t mPacketLength;
public:
    UAVObjHandle();
    UAVObjHandle( uint32_t objId);
    uint32_t getObjId();
    uint32_t getPacketLength();
};

#endif // UAVOBJHANDLE_H
