int pthread_cond_init(pthread_cond_t* condVar,          // ptr to condition variable
                      const pthread_condattr_t *attr)   // ptr to pthread_condattr_t 
                                                        // structure, often 0 
                                                        // (default attributes)
// returns 0 if condition variable is initiated successfully


int pthread_cond_destroy(pthread_cond_t* condVar)       // ptr to condition variable
// returns 0 if condition variable is destroyed successfully


int pthread_cond_wait(pthread_cond_t* condVar,      // ptr to condition variable
                      pthread_mutex_t* mutex)       // ptr to pthread_mutex_t instance
// returns 0 if waiting (blocking) is successful


int pthread_mutex_signal(pthread_cond_t* condVar)   // ptr to condition variable
// returns 0 if signaling (unblocking) is successful