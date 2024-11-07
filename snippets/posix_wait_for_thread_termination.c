int pthread_join(pthread_t* thread,					// ptr to pthread_t instance
                 const pthread_attr_t* attr);	// ptr to pthread_attr_t 
																// structure, often 0
																// (default attributes)
// returns 0 if thread terminated successfully