// Copyright (c) 2018 The Bitcoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file license.txt or http://www.opensource.org/licenses/mit-license.php.

#ifndef __INCLUDED_COIN_H__
#define __INCLUDED_COIN_H__

#include <string>

static const std::string mainnet_seeds[] = {"seed.bitcoin.sipa.be", // Pieter Wuille, only supports x1, x5, x9, and xd
                                            "dnsseed.bluematt.me", // Matt Corallo, only supports x9
                                            "dnsseed.bitcoin.dashjr.org", // Luke Dashjr
                                            "seed.bitcoinstats.com", // Christian Decker, supports x1 - xf
                                            "seed.bitcoin.jonasschnelli.ch", // Jonas Schnelli, only supports x1, x5, x9, and xd
                                            "seed.btc.petertodd.org", // Peter Todd, only supports x1, x5, x9, and xd
                                            ""};

static const std::string testnet_seeds[] = {"testnet-seed.bitcoin.jonasschnelli.ch",
                                            "seed.tbtc.petertodd.org",
                                            "seed.testnet.bitcoin.sprovoost.nl",
                                            "testnet-seed.bluematt.me",
                                            ""};

static const int mainnet_port = 8333;
static const int testnet_port = 18333;

static unsigned char pchMessageStart[4] = { 0xf9, 0xbe, 0xb4, 0xd9 };
static unsigned char pchMessageStart_testnet[4] = { 0x0b, 0x11, 0x09, 0x07 };

#endif // __INCLUDED_COIN_H__
