#include "iopsound.h"

typedef struct Track Track;
typedef struct QueueEntry QueueEntry;

struct QueueEntry {
    Track *trk;         /* 0x00 */
    u32 w;              /* 0x04 */
}; /* size 8 */

void func_002D20(QueueEntry *q, Track *trk) {
    QueueEntry *end = q + 144;

    do {
        if (q->trk == trk) {
            q->trk = NULL;
        }
        q++;
    } while (q < end);
}
