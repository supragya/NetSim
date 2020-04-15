#ifndef BTCMODEL_H_
#define BTCMODEL_H_

#include <random>

#include "./BlockchainManagementModel.h"
#include "../../core/Network/Network.h"
#include "../../helpers/Logger/easylogging.h"

class BitcoinModel : public BlockchainManagementModel {
	std::mt19937_64 rng;
	std::exponential_distribution<double> exp;
	std::uniform_real_distribution<double> unif;
	Network &network;
	uint64_t getRandomNumFromExponentialDistribution();

public:
	BitcoinModel(Network &network);
	void OnOutOfRangeNewBlockArrival();
	uint64_t getNextBlockTime();
	std::shared_ptr<Node> getNextBlockProducer();
	std::shared_ptr<Block> createGenesisBlock();
};

#endif /*BTCMODEL_H_*/
