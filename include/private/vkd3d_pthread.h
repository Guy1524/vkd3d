#ifndef __VKD3D_PTHREAD_WINDOWS_H
#define __VKD3D_PTHREAD_WINDOWS_H

#include "vkd3d_windows.h"

#ifdef _WIN32

typedef CRITICAL_SECTION pthread_mutex_t;
typedef struct pthread_mutex_attr* pthread_mutexattr_t;

inline int pthread_mutex_init(pthread_mutex_t *mutex, const pthread_mutexattr_t *attr)
{
    InitializeCriticalSection(mutex);
    return 0;
}

inline int pthread_mutex_lock(pthread_mutex_t *mutex)
{
    EnterCriticalSection(mutex);
    return 0;
}

int pthread_mutex_unlock(pthread_mutex_t *mutex)
{
    LeaveCriticalSection(mutex);
    return 0;
}

int pthread_mutex_destroy(pthread_mutex_t *mutex)
{
    DeleteCriticalSection(mutex);
    return 0;
}

typedef CONDITION_VARIABLE pthread_cond_t;
typedef struct pthread_condattr* pthread_condattr_t;

int pthread_cond_init(pthread_cond_t *cond, const pthread_condattr_t *attr)
{
    InitializeConditionVariable(cond);
    return 0;
}

int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex)
{
   return !(SleepConditionVariableCS(cond, mutex, INFINITE));
}

int pthread_cond_signal(pthread_cond_t *cond)
{
    WakeConditionVariable(cond);
    return 0;
}

int pthread_cond_broadcast(pthread_cond_t *cond)
{
    WakeAllConditionVariable(cond);
    return 0;
}

int pthread_cond_destroy(pthread_cond_t *cond)
{
    return 0;
}

#else

#include <pthread.h>

#endif /* _WIN32 */

#endif /* __VKD3D_PTHREAD_WINDOWS_H */