/* (C) 2008 The Measurement Factory */

#ifndef LIBECAP__COMMON_REGISTRY_H
#define LIBECAP__COMMON_REGISTRY_H

#include <libecap/common/forward.h>
#include <libecap/common/memory.h>

namespace libecap {

// services call this to register upon creation
extern void RegisterService(adapter::Service *s);

// the host calls this to receive registered services (past and future)
extern void RegisterHost(const shared_ptr<host::Host> &host);

// returns registered host or throws if no host was registered
extern host::Host &MyHost();

} // namespace libecap

#endif
