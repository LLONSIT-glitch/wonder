#ifndef THREAD_H
#define THREAD_H

typedef enum {
  THREAD_SYS_MAIN,
  THREAD_AUDIO_MGR,
  THREAD_3,
  THREAD_4
} ThreadIds;

extern ThreadIds gSysThreadIds[];
#endif /* THREAD_H */
