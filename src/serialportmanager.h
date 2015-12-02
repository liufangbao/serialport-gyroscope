#ifndef SERIALPORTMANAGER_H
#define SERIALPORTMANAGER_H
#include <QString>
#include <QTimer>
#include "qextserialport/qextserialport.h"
#include "qextserialport/qextserialenumerator.h"

// Private types and constants

// min header : sync(1), type (1), size(2), object ID(4), instance ID(2)
#define UAVTALK_MIN_HEADER_LENGTH  10

// max header : sync(1), type (1), size(2), object ID(4), instance ID(2), timestamp(2)
#define UAVTALK_MAX_HEADER_LENGTH  12

#define UAVTALK_CHECKSUM_LENGTH    1
#define UAVOBJECTS_LARGEST 217
#define UAVTALK_MAX_PAYLOAD_LENGTH (UAVOBJECTS_LARGEST + 1)

#define UAVTALK_MIN_PACKET_LENGTH  UAVTALK_MAX_HEADER_LENGTH + UAVTALK_CHECKSUM_LENGTH
#define UAVTALK_MAX_PACKET_LENGTH  UAVTALK_MIN_PACKET_LENGTH + UAVTALK_MAX_PAYLOAD_LENGTH

#define UAVTALK_CANARI          0xCA
#define UAVTALK_SYNC_VAL        0x3C

#define UAVTALK_TYPE_MASK       0x78
#define UAVTALK_TYPE_VER        0x20
#define UAVTALK_TIMESTAMPED     0x80
#define UAVTALK_TYPE_OBJ        (UAVTALK_TYPE_VER | 0x00)
#define UAVTALK_TYPE_OBJ_REQ    (UAVTALK_TYPE_VER | 0x01)
#define UAVTALK_TYPE_OBJ_ACK    (UAVTALK_TYPE_VER | 0x02)
#define UAVTALK_TYPE_ACK        (UAVTALK_TYPE_VER | 0x03)
#define UAVTALK_TYPE_NACK       (UAVTALK_TYPE_VER | 0x04)
#define UAVTALK_TYPE_OBJ_TS     (UAVTALK_TIMESTAMPED | UAVTALK_TYPE_OBJ)
#define UAVTALK_TYPE_OBJ_ACK_TS (UAVTALK_TIMESTAMPED | UAVTALK_TYPE_OBJ_ACK)

typedef short int16_t;
typedef int int32_t;
typedef unsigned char uint8_t;
typedef unsigned short uint16_t;
typedef unsigned int uint32_t;

typedef enum {
    UAVTALK_STATE_ERROR = 0,
               UAVTALK_STATE_SYNC,
               UAVTALK_STATE_TYPE,
               UAVTALK_STATE_SIZE,
               UAVTALK_STATE_OBJID,
               UAVTALK_STATE_INSTID,
               UAVTALK_STATE_TIMESTAMP,
               UAVTALK_STATE_DATA,
               UAVTALK_STATE_CS,
               UAVTALK_STATE_COMPLETE
             } UAVTalkRxState;

typedef struct {
    uint8_t  type;
    uint16_t packet_size;
    uint32_t objId;
    uint16_t instId;
    uint32_t length;
    uint8_t  timestampLength;
    uint8_t  cs;
    uint16_t timestamp;
    uint32_t rxCount;
    UAVTalkRxState state;
    uint16_t rxPacketLength;
} UAVTalkInputProcessor;

class SerialPortManager: public QObject
{
    Q_OBJECT
    QTimer *mTimer;
    QString mPortName;
    PortSettings mSettings;
    QextSerialPort *mPort;
    QString mReceivedString;
    QByteArray mReceivedArray;
    UAVTalkInputProcessor *iproc;

public:
    SerialPortManager(QString *portName);
    uint8_t PIOS_CRC_updateByte(uint8_t crc, const uint8_t data);
    UAVTalkRxState UAVTalkProcessInputStreamQuiet(uint8_t rxbyte);
signals:
    void dataReady(uint32_t objId,QByteArray s);
public slots:
    void onReadyRead();

};

#endif // SERIALPORTMANAGER_H
