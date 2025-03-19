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
            osc::ReceivedMessageArgumentStream args = m.ArgumentStream();
            float x1, y1;
            float x2, y2;
            float x3, y3;
            float x4, y4;
            float x5, y5;
            float x6, y6;
            float x7, y7;

            args >> x1 >> y1
                >> x2 >> y2
                >> x3 >> y3
                >> x4 >> y4
                >> x5 >> y5
                >> x6 >> y6
                >> x7 >> y7
                >> osc::EndMessage;

            std::cout << m.AddressPattern()
                << " [" << x1 << ", " << y1 << "],"
                << "[" << x2 << ", " << y2 << "],"
                << "[" << x3 << ", " << y3 << "],"
                << "[" << x4 << ", " << y4 << "],"
                << "[" << x5 << ", " << y5 << "],"
                << "[" << x6 << ", " << y6 << "],"
                << "[" << x7 << ", " << y7 << "]"
                << std::endl;
        } catch(osc::Exception& e) {
            std::cout << "error while parsing message: "
                << m.AddressPattern() << ": " << e.what() << "\n";
        }
    }
};
