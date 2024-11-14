int pthread_mutex_init(pthread_mutex_t* mutex,          // ptr to pthread_mutex_t instance
                       const pthread_mutexattr_t *attr) // ptr to pthread_muttexattr_t 
                                                        // structure, often 0 
                                                        // (default attributes)
// returns 0 if mutex is initiated successfully


int pthread_mutex_detroy(pthread_mutex_t* mutex)    // ptr to pthread_mutex_t instance
// returns 0 if mutex is destroyed successfully


int pthread_mutex_lock(pthread_mutex_t *mutex)      // ptr to pthread_mutex_t instance
// returns 0 if mutex is locked successfully


int pthread_mutex_unlock(pthread_mutex_t* mutex)    // ptr to pthread_mutex_t instance
// returns 0 if mutex is unlocked successfully