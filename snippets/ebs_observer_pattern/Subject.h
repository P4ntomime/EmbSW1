// Subject.h -> Server, Model, Subject

#ifndef SUBJECT_H__
#define SUBJECT_H__

class Observer; // forward declaration

class Subject
{
  public:
		enum {ok = 0,       // return value for good
					failed = -1   // return value for error/failure
				 };
		
		int attach(const Observer& ob);   // attaches observer 'ob'
    // return: ok: success or failed: no success

    int detach(const Observer& ob);   // detaches observer 'ob'
    // return: ok: success or failed: no success

		void notify() const;  // notifies all attached observers (read-only)

  private:
		enum {size = 4};                              // may use template parameter
    const Observer* observers[size] = {nullptr};  // may use vector<> instead
};
#endif