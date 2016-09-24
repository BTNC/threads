#ifndef TH_THREAD_INC
#define TH_THREAD_INC

#include <stdint.h>

typedef struct THThread_ THThread;
typedef struct THMutex_ THMutex;
typedef struct THCondition_ THCondition;
typedef struct THThreadState_ {
  void* data;
  int status;
} THThreadState;

THThread* THThread_new(void* (*closure)(void*), void *data);
uintptr_t THThread_id(THThread *self);
int THThread_free(THThread *self);

THMutex* THMutex_new(void);
THMutex* THMutex_newWithId(uintptr_t id);
uintptr_t THMutex_id(THMutex *self);
int THMutex_lock(THMutex *self);
int THMutex_unlock(THMutex *self);
void THMutex_free(THMutex *self);

THCondition* THCondition_new(void);
THCondition* THCondition_newWithId(uintptr_t id);
uintptr_t THCondition_id(THCondition *self);
int THCondition_signal(THCondition *self);
int THCondition_wait(THCondition *self, THMutex *mutex);
void THCondition_free(THCondition *self);

#endif
