#ifndef __MUTEX_H__
#define __MUTEX_H__
#include <pthread.h>

class Mutex {
    pthread_mutex_t m;

  public:
    Mutex()
    {
        pthread_mutex_init(&m, NULL);
    }
    void lock()
    {
        pthread_mutex_lock(&m);
    }
    void unlock()
    {
        pthread_mutex_unlock(&m);
    }
};

class MutexLock {
    Mutex& m;

  public:
    MutexLock(Mutex& _m) : m(_m)
    {
        m.lock();
    }
    ~MutexLock()
    {
        m.unlock();
    };
};
#endif /* __MUTEX_H__ */
