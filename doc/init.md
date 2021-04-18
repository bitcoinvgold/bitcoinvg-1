Sample init scripts and service configuration for bitcoinvgd
==========================================================

Sample scripts and configuration files for systemd, Upstart and OpenRC
can be found in the contrib/init folder.

    contrib/init/bitcoinvgd.service:    systemd service unit configuration
    contrib/init/bitcoinvgd.openrc:     OpenRC compatible SysV style init script
    contrib/init/bitcoinvgd.openrcconf: OpenRC conf.d file
    contrib/init/bitcoinvgd.conf:       Upstart service configuration file
    contrib/init/bitcoinvgd.init:       CentOS compatible SysV style init script

Service User
---------------------------------

All three Linux startup configurations assume the existence of a "bitcoinvg" user
and group.  They must be created before attempting to use these scripts.
The macOS configuration assumes bitcoinvgd will be set up for the current user.

Configuration
---------------------------------

Running bitcoinvgd as a daemon does not require any manual configuration. You may
set the `rpcauth` setting in the `bitcoinvg.conf` configuration file to override
the default behaviour of using a special cookie for authentication.

This password does not have to be remembered or typed as it is mostly used
as a fixed token that bitcoinvgd and client programs read from the configuration
file, however it is recommended that a strong and secure password be used
as this password is security critical to securing the wallet should the
wallet be enabled.

If bitcoinvgd is run with the "-server" flag (set by default), and no rpcpassword is set,
it will use a special cookie file for authentication. The cookie is generated with random
content when the daemon starts, and deleted when it exits. Read access to this file
controls who can access it through RPC.

By default the cookie is stored in the data directory, but it's location can be overridden
with the option '-rpccookiefile'.

This allows for running bitcoinvgd without having to do any manual configuration.

`conf`, `pid`, and `wallet` accept relative paths which are interpreted as
relative to the data directory. `wallet` *only* supports relative paths.

For an example configuration file that describes the configuration settings,
see `share/examples/bitcoinvg.conf`.

Paths
---------------------------------

### Linux

All three configurations assume several paths that might need to be adjusted.

Binary:              `/usr/bin/bitcoinvgd`
Configuration file:  `/etc/bitcoinvg/bitcoinvg.conf`
Data directory:      `/var/lib/bitcoinvgd`
PID file:            `/var/run/bitcoinvgd/bitcoinvgd.pid` (OpenRC and Upstart) or `/run/bitcoinvgd/bitcoinvgd.pid` (systemd)
Lock file:           `/var/lock/subsys/bitcoinvgd` (CentOS)

The PID directory (if applicable) and data directory should both be owned by the
bitcoinvg user and group. It is advised for security reasons to make the
configuration file and data directory only readable by the bitcoinvg user and
group. Access to bitcoinvg-cli and other bitcoinvgd rpc clients can then be
controlled by group membership.

NOTE: When using the systemd .service file, the creation of the aforementioned
directories and the setting of their permissions is automatically handled by
systemd. Directories are given a permission of 710, giving the bitcoinvg group
access to files under it _if_ the files themselves give permission to the
bitcoinvg group to do so (e.g. when `-sysperms` is specified). This does not allow
for the listing of files under the directory.

NOTE: It is not currently possible to override `datadir` in
`/etc/bitcoinvg/bitcoinvg.conf` with the current systemd, OpenRC, and Upstart init
files out-of-the-box. This is because the command line options specified in the
init files take precedence over the configurations in
`/etc/bitcoinvg/bitcoinvg.conf`. However, some init systems have their own
configuration mechanisms that would allow for overriding the command line
options specified in the init files (e.g. setting `BITCOINVGD_DATADIR` for
OpenRC).

### macOS

Binary:              `/usr/local/bin/bitcoinvgd`
Configuration file:  `~/Library/Application Support/BitcoinVG/bitcoinvg.conf`
Data directory:      `~/Library/Application Support/BitcoinVG`
Lock file:           `~/Library/Application Support/BitcoinVG/.lock`

Installing Service Configuration
-----------------------------------

### systemd

Installing this .service file consists of just copying it to
/usr/lib/systemd/system directory, followed by the command
`systemctl daemon-reload` in order to update running systemd configuration.

To test, run `systemctl start bitcoinvgd` and to enable for system startup run
`systemctl enable bitcoinvgd`

NOTE: When installing for systemd in Debian/Ubuntu the .service file needs to be copied to the /lib/systemd/system directory instead.

### OpenRC

Rename bitcoinvgd.openrc to bitcoinvgd and drop it in /etc/init.d.  Double
check ownership and permissions and make it executable.  Test it with
`/etc/init.d/bitcoinvgd start` and configure it to run on startup with
`rc-update add bitcoinvgd`

### Upstart (for Debian/Ubuntu based distributions)

Upstart is the default init system for Debian/Ubuntu versions older than 15.04. If you are using version 15.04 or newer and haven't manually configured upstart you should follow the systemd instructions instead.

Drop bitcoinvgd.conf in /etc/init.  Test by running `service bitcoinvgd start`
it will automatically start on reboot.

NOTE: This script is incompatible with CentOS 5 and Amazon Linux 2014 as they
use old versions of Upstart and do not supply the start-stop-daemon utility.

### CentOS

Copy bitcoinvgd.init to /etc/init.d/bitcoinvgd. Test by running `service bitcoinvgd start`.

Using this script, you can adjust the path and flags to the bitcoinvgd program by
setting the BITCOINVGD and FLAGS environment variables in the file
/etc/sysconfig/bitcoinvgd. You can also use the DAEMONOPTS environment variable here.

### macOS

Copy org.bitcoinvg.bitcoinvgd.plist into ~/Library/LaunchAgents. Load the launch agent by
running `launchctl load ~/Library/LaunchAgents/org.bitcoinvg.bitcoinvgd.plist`.

This Launch Agent will cause bitcoinvgd to start whenever the user logs in.

NOTE: This approach is intended for those wanting to run bitcoinvgd as the current user.
You will need to modify org.bitcoinvg.bitcoinvgd.plist if you intend to use it as a
Launch Daemon with a dedicated bitcoinvg user.

Auto-respawn
-----------------------------------

Auto respawning is currently only configured for Upstart and systemd.
Reasonable defaults have been chosen but YMMV.
