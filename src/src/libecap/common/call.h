/* (C) 2008 The Measurement Factory */

#ifndef LIBECAP__COMMON__CALL_H
#define LIBECAP__COMMON__CALL_H

#include <libecap/common/memory.h>

namespace libecap {

/* remote call maintenance */

// interface for those accepting remote calls; 
// sometimes the callee has to reject calls before the object is destroyed,
// making weak_ptr-based checks ineffective
class Callable {
	public:
		virtual ~Callable() {}

		// returns false if the object is not accepting any calls
		virtual bool callable() const = 0;
};


// a weak_ptr::lock() wrapper that returns a null pointer
// when the object is not callable.
template <typename C>
shared_ptr<C> LockToCall(const weak_ptr<C> &w) {
	if (const shared_ptr<C> p = w.lock()) {
        if (p->callable())
            return p;
	}
    return shared_ptr<C>();
}

} // namespace libecap

#endif
