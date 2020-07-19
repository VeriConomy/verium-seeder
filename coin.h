// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#ifndef __INCLUDED_COIN_H__
#define __INCLUDED_COIN_H__

#include <string>

static const int FIRST_PROTOCOL_VERSION = 80001;
static const int PROTOCOL_VERSION = 80002;
static const int REQUIRE_PROTOCOL_VERSION = 80001;

static const int MAINNET_MIN_HEIGHT = 180000;
static const int TESTNET_MIN_HEIGHT = 50000;

static const std::string seeder_version = "/verium-seeder:1.11/";

static const std::string mainnet_seeds[] = {"206.189.59.89",
                                            "206.189.209.81",
                                            "206.189.145.110",
                                            "emea.vrm.vericonomy.com",
                                            "amer.vrm.vericonomy.com",
                                            "apac.vrm.vericonomy.com",
                                            "seed.vrm.mining-pool.ovh",
                                            ""};

static const std::string testnet_seeds[] = {"", ""};

static const int mainnet_port = 32988;
static const int testnet_port = 36988;

static unsigned char pchMessageStart[4] = { 0x70, 0x35, 0x22, 0x05 };
static unsigned char pchMessageStart_testnet[4] = { 0x70, 0x35, 0x22, 0x05 };

#endif // __INCLUDED_COIN_H__
