#ifndef NODE_H_
#define NODE_H_

#include <memory>
#include <vector>

#include "NodeId.h"
#include "../Messages/Message.h"
#include "../Messages/NewBlockIdMessage.h"
#include "../Messages/NewBlockMinedMessage.h"
#include "../../Blockchain/Blockchain.h"
#include "../../Networking/RoutingTable.h"
#include "../../../helpers/Logger/easylogging.h"

class Bandwidth;
class Event;
class Protocol;

class Node {
private:
	NodeId nodeId;
	bool isAlive;
	int region;
	std::shared_ptr<Bandwidth> maxBandwidth;
	std::shared_ptr<Bandwidth> currentBandwidth;
	std::shared_ptr<RoutingTable> routingTable;
	std::vector<std::shared_ptr<Protocol>> protocols;
	std::shared_ptr<Blockchain> blockchain;
	std::shared_ptr<BlockCache> blockCache;

public:
	Node(int _nodeId, bool _isAlive, int _region, 
		 std::shared_ptr<BlockCache> _blockCache);
	Node(int _nodeId, double _maxDownBandwidth, double _upDownBandwidth);
	int getRegion() const;
	int getNodeId() const;
	std::shared_ptr<Blockchain> getBlockchain();
	std::shared_ptr<BlockCache> getBlockCache();
	bool addProtocol(std::shared_ptr<Protocol> protocol);
	std::vector<std::shared_ptr<Protocol>> getProtocols();
	std::shared_ptr<RoutingTable> getRoutingTable();
	std::shared_ptr<Bandwidth> getCurrentBandwidth();
	std::shared_ptr<Bandwidth> getMaxBandwidth();
};

#endif /*NODE_H_*/
