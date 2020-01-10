#include <libecap/common/registry.h>
#include <libecap/common/errors.h>
#include <libecap/adapter/service.h>
#include <libecap/host/host.h>
#include <list>

namespace libecap {

typedef std::list< libecap::weak_ptr<adapter::Service> > StagingArea;
static StagingArea TheStagingArea;

static shared_ptr<host::Host> TheHost;

static
void drainStagingArea() {
	while (TheHost && !TheStagingArea.empty()) {
		StagingArea::value_type s = TheStagingArea.front();
		TheStagingArea.pop_front();
		TheHost->noteService(s);
	}
}

} // namespace libecap

void libecap::RegisterService(adapter::Service *s) {
	s->self.reset(s); // avoids creation of shared pointer inside ctor
	TheStagingArea.push_back(s->self);
	drainStagingArea();
}

void libecap::RegisterHost(const shared_ptr<host::Host> &host) {
	Must(host);
	Must(!TheHost);
	TheHost = host;
	drainStagingArea();
}

libecap::host::Host &libecap::MyHost() {
	Must(TheHost);
	return *TheHost;
}
