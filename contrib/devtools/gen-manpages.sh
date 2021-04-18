#!/usr/bin/env bash
# Copyright (c) 2016-2019 The Bitcoin Core developers
# Distributed under the MIT software license, see the accompanying
# file COPYING or http://www.opensource.org/licenses/mit-license.php.

export LC_ALL=C
TOPDIR=${TOPDIR:-$(git rev-parse --show-toplevel)}
BUILDDIR=${BUILDDIR:-$TOPDIR}

BINDIR=${BINDIR:-$BUILDDIR/src}
MANDIR=${MANDIR:-$TOPDIR/doc/man}

BITCOINVGD=${BITCOINVGD:-$BINDIR/bitcoinvgd}
BITCOINVGCLI=${BITCOINVGCLI:-$BINDIR/bitcoinvg-cli}
BITCOINVGTX=${BITCOINVGTX:-$BINDIR/bitcoinvg-tx}
WALLET_TOOL=${WALLET_TOOL:-$BINDIR/bitcoinvg-wallet}
BITCOINVGQT=${BITCOINVGQT:-$BINDIR/qt/bitcoinvg-qt}

[ ! -x $BITCOINVGD ] && echo "$BITCOINVGD not found or not executable." && exit 1

# The autodetected version git tag can screw up manpage output a little bit
read -r -a BVGVER <<< "$($BITCOINVGCLI --version | head -n1 | awk -F'[ -]' '{ print $6, $7 }')"

# Create a footer file with copyright content.
# This gets autodetected fine for bitcoinvgd if --version-string is not set,
# but has different outcomes for bitcoinvg-qt and bitcoinvg-cli.
echo "[COPYRIGHT]" > footer.h2m
$BITCOINVGD --version | sed -n '1!p' >> footer.h2m

for cmd in $BITCOINVGD $BITCOINVGCLI $BITCOINVGTX $WALLET_TOOL $BITCOINVGQT; do
  cmdname="${cmd##*/}"
  help2man -N --version-string=${BVGVER[0]} --include=footer.h2m -o ${MANDIR}/${cmdname}.1 ${cmd}
  sed -i "s/\\\-${BVGVER[1]}//g" ${MANDIR}/${cmdname}.1
done

rm -f footer.h2m
