#ifndef THREAD_H
#define THREAD_H

typedef enum {
  THREAD_ID_SYS_MAIN,
  THREAD_ID_AUDIO_MGR,
  THREAD_ID_3,
  THREAD_ID_IDLE
} ThreadIds;

extern ThreadIds gSysThreadIds[];
#endif /* THREAD_H */
