What is BitcoinVirtualGold?
----------------

Coin symbol: BVG


Coin max supply: 21 Million


Bitcoin Virtual Gold was created as a result of failure and persistence to find an improved approach to spreading the control of what determines Bitcoin's best chain. Originally, bitcoinVBR submitted the VBR code as a pull request to the Bitcoin core team.The original developer created BitcoinVG to give the community a form of Bitcoin that doesn't suffer from mining centraliztion.
After a Recent Abstract in our Community, founding member @wow92 decided to continue the project with a clean start. We are hoping that we will continue the legacy of the creator NullFunctor and grow our community to the fullest. This time With the Help of the community, we are going to decide our members who will have specific tasks with the target of growing Bitcoin Virtual Gold.

Website: www.bitcoinvg.net


Discord: https://discord.com/invite/YUgtB4d4


Twitter: https://twitter.com/BitcoinVG


Mining Pools: https://miningpoolstats.stream/bitcoinvg


Telegram: https://t.me/BitcoinVG

For more information, as well as an immediately usable, binary version of
the BitcoinVG Core software, see https://www.bitcoinvg.net, or read the
[original whitepaper](https://www.bitcoinvg.net/WhitePaper.pdf).

License
-------

BitcoinVG Core is released under the terms of the MIT license. See [COPYING](COPYING) for more
information or see https://opensource.org/licenses/MIT.

Development Process
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/BitcoinVG/bitcoinvg) are created
regularly to indicate new official, stable release versions of BitcoinV PoS Core.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md)
and useful hints for developers can be found in [doc/developer-notes.md](doc/developer-notes.md).

Testing
-------

Testing and code review is the bottleneck for development; we get more pull
requests than we can review and test on short notice. Please be patient and help out by testing
other people's pull requests, and remember this is a security-critical project where any mistake might cost people
lots of money.

### Automated Testing

Developers are strongly encouraged to write [unit tests](src/test/README.md) for new code, and to
submit new unit tests for old code. Unit tests can be compiled and run
(assuming they weren't disabled in configure) with: `make check`. Further details on running
and extending unit tests can be found in [/src/test/README.md](/src/test/README.md).

There are also [regression and integration tests](/test), written
in Python, that are run automatically on the build server.
These tests can be run (if the [test dependencies](/test) are installed) with: `test/functional/test_runner.py`

The Travis CI system makes sure that every pull request is built for Windows, Linux, and macOS, and that unit/sanity tests are run automatically.

### Manual Quality Assurance (QA) Testing

Changes should be tested by somebody other than the developer who wrote the
code. This is especially important for large or high-risk changes. It is useful
to add a test plan to the pull request description if testing the changes is
not straightforward.

