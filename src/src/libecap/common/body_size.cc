#include <libecap/common/body_size.h>
#include <libecap/common/errors.h>

libecap::BodySize::BodySize(): size_(0), known_(false) {
}

libecap::BodySize::BodySize(BodySize::size_type size): size_(size), known_(true) {
}

libecap::BodySize::size_type libecap::BodySize::badSize() const {
	Must(false); // this method must always throw
	return 0; // not reached
}
