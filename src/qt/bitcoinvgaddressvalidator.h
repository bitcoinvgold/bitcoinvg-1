// Copyright (c) 2011-2014 The Bitcoin Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCOINVG_QT_BITCOINVGADDRESSVALIDATOR_H
#define BITCOINVG_QT_BITCOINVGADDRESSVALIDATOR_H

#include <QValidator>

/** Base58 entry widget validator, checks for valid characters and
 * removes some whitespace.
 */
class BitcoinVGAddressEntryValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinVGAddressEntryValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

/** BitcoinVG address widget validator, checks for a valid bitcoinvg address.
 */
class BitcoinVGAddressCheckValidator : public QValidator
{
    Q_OBJECT

public:
    explicit BitcoinVGAddressCheckValidator(QObject *parent);

    State validate(QString &input, int &pos) const override;
};

#endif // BITCOINVG_QT_BITCOINVGADDRESSVALIDATOR_H
