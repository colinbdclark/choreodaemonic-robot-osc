#include "joint-listener.h"

#define ADDRESS "0.0.0.0"
#define PORT 7600

int main() {
    JointListener listener;

    UdpListeningReceiveSocket s(IpEndpointName(ADDRESS, PORT), &listener);

    std::cout << "listening on " << ADDRESS << ":" << PORT << std::endl;

    s.RunUntilSigInt();
    return 0;
}
