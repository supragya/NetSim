#include <cstdio>
#include <map>

//#include "SubnetTest.h"
//#include "GnpLatencyModelTest.h"
//#include "NetworkLayerTest.h"
#include "TransportLayerTest.h"
#include "../helpers/Logger/easylogging.h"

using namespace std;

INITIALIZE_EASYLOGGINGPP

void configureLogger() {
	// Load configuration from file
    el::Configurations conf1("./config/Logger-conf1.conf");
    el::Configurations networkTopologyConf("./config/Logger-networkTopology.conf");
    // Reconfigure default logger
    el::Loggers::reconfigureLogger("default", conf1);
    // Register another logger apart from default
    el::Logger* networkTopologyLogger = el::Loggers::getLogger("networkTopology");
    // Reconfigure networkTopology logger
    el::Loggers::reconfigureLogger("networkTopology", networkTopologyConf);
}

int main() {
	configureLogger();

	LOG(INFO) << "[Test started]";
	
	// Subnet Test
	//	SubnetTest st;
	//	st.test();

	// GnpLatencyModel Test
//	GnpLatencyModelTest gt;
//	gt.test();

	// NetworkLayer Test
//	NetworkLayerTest nt;
//	nt.test();

	// TransportLayer Test
	TransportLayerTest tt;
	tt.test();

    LOG(INFO) << "[Test stopped]";

    // Flush all loggers otherwise sometimes program closes and not every log gets printed
    el::Loggers::flushAll();

	return 0;
}
