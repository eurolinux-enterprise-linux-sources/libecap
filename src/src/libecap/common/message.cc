#include <libecap/common/message.h>
#include <libecap/common/errors.h>

void libecap::Message::addTrailer() {
    Must(false); // no trailer support by default
}
