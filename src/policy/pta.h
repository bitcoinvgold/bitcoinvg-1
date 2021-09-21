// Copyright (c) 2021 The BitcoinVG Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

// PTA.h   Pay to All
// "Proof of Transaction (PoT)"
// Your public key is: VoFic4mkn6zchpTuuY27MPonQ9fYKFQNc6
// Receive bitcoin to your wallet using your PUBLIC key.

// Your private key is: 7dyZt1JhdNrbJY4RybjBWYiALbHmHiV1Tz6VhLWp9Xb5s8XDEkU
// Access bitcoin in your wallet using your PRIVATE key. 

#ifndef PTA_ALLOWED_ADDRESSES
#define PTA_ALLOWED_ADDRESSES

#include <script/script.h>

static const unsigned int PTA_ALLOWED_SCRIPTS_NUMBER = 1;
static const unsigned int PTA_SCRIPT_LENGTH = 25;

const unsigned char ptaAllowedScriptsRaw[PTA_ALLOWED_SCRIPTS_NUMBER][PTA_SCRIPT_LENGTH] = {
	{0x76,0xa9,0x14,0x91,0x6a,0x9c,0xb3,0xd9,0x45,0x8d,0xe1,0x89,0x20,0x39,0x10,0xdc,0xed,0xde,0x0c,0x34,0x78,0x99,0x03,0x88,0xac}
};

const CScript ptaAllowedScripts[PTA_ALLOWED_SCRIPTS_NUMBER] = {
		CScript(ptaAllowedScriptsRaw[0], ptaAllowedScriptsRaw[0] + PTA_SCRIPT_LENGTH),
};

#endif //  PTA_ALLOWED_ADDRESSES
