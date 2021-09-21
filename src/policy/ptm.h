// Copyright (c) 2021 The BitcoinVG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// ptm.h   Pay to Mine
// "Proof of Transaction (PoT)"

// ==PAY TO MINE ADDRESS (PtM)==

// Send 1000 BVG to the following address for adding the block to the blockchain:

// Va3HqzPcEqXrmosHCBRt6DWPYyNgtNZifu 

// ==COMMUNITY ADDRESS (PtA)==

// Your public key is: VoFic4mkn6zchpTuuY27MPonQ9fYKFQNc6
// Receive bitcoin to your wallet using your PUBLIC key.

// Your private key is: 7dyZt1JhdNrbJY4RybjBWYiALbHmHiV1Tz6VhLWp9Xb5s8XDEkU
// Access bitcoin in your wallet using your PRIVATE key. 

#ifndef PTM_ALLOWED_ADDRESSES
#define PTM_ALLOWED_ADDRESSES

#include <script/script.h>

static const unsigned int PTM_ALLOWED_SCRIPTS_NUMBER = 1;
static const unsigned int PTM_SCRIPT_LENGTH = 25;

const unsigned char ptmAllowedScriptsRaw[PTM_ALLOWED_SCRIPTS_NUMBER][PTM_SCRIPT_LENGTH] = {
	{0x76,0xa9,0x14,0x00,0x77,0x51,0x1c,0xcb,0x56,0x4e,0x09,0x99,0x2e,0x1c,0x18,0xf9,0xaf,0x85,0x2b,0x9b,0xa9,0x73,0x07,0x88,0xac}
};

const CScript ptmAllowedScripts[PTM_ALLOWED_SCRIPTS_NUMBER] = {
		CScript(ptmAllowedScriptsRaw[0], ptmAllowedScriptsRaw[0] + PTM_SCRIPT_LENGTH),
};

#endif //  PTM_ALLOWED_ADDRESSES
