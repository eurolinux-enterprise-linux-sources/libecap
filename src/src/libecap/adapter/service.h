/* (C) 2008  The Measurement Factory */

#ifndef ECAP__ADAPTER__SERVICE_H
#define ECAP__ADAPTER__SERVICE_H

#include <libecap/common/forward.h>
#include <libecap/common/memory.h>
#include <string>
#include <iosfwd>

namespace libecap {
namespace adapter {

class Service {
	public:
		virtual ~Service();

		// About
		virtual std::string uri() const = 0; // unique across all vendors
		virtual std::string tag() const = 0; // changes with version and config
		virtual void describe(std::ostream &os) const = 0; // free-format info

		// Configuration
		virtual void configure(const Options &cfg) = 0;
		virtual void reconfigure(const Options &cfg) = 0;

		// Lifecycle
		virtual void start(); // expect makeXaction() calls
		virtual void stop(); // no more makeXaction() calls until start()
		virtual void retire(); // no more makeXaction() calls

		// Scope (TODO: Should we add an extendable parameter?)
		virtual bool wantsUrl(const char *url) const = 0;

		// Work
		virtual Xaction *makeXaction(host::Xaction *hostx) = 0;

		shared_ptr<Service> self;
};

} // namespace adapter
} // namespace libecap

#endif
