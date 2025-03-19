#include <iostream>
#include <cstring>
#include "../lib/oscpack/osc/OscReceivedElements.h"
#include "../lib/oscpack/osc/OscPacketListener.h"
#include "../lib/oscpack/ip/UdpSocket.h"

class JointListener: public osc::OscPacketListener  {
    public:
    virtual void ProcessMessage(const osc::ReceivedMessage& m,
        const IpEndpointName& remoteEndpoint ) {
            (void) remoteEndpoint;
        try {
            std::cout << "received message with address " << m.AddressPattern()
                << std::endl;

        } catch(osc::Exception& e) {
            std::cout << "error while parsing message: "
                << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};
