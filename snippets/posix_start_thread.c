int pthread_create(pthread_t* thread,               // ptr to pthread_t instance
                   const pthread_attr_t* attr,      // ptr to pthread_attr_t 
                                                    // structure, often 0 
                                                    // (default attributes)
                   void* (*startRoutine) (void*),   // function ptr to thread routine
                   void* arg);                      // single argument that may be
                                                    // passed to startRoutine
// returns 0 if thread is started successfully