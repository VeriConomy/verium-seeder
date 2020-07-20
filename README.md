Verium-seeder
==============

[![Build Status](https://travis-ci.com/VeriConomy/verium-seeder.svg?branch=master)](https://travis-ci.com/VeriConomy/verium-seeder)

Verium-seeder is a crawler for the Verium network, which exposes a list
of reliable nodes via a built-in DNS server, or instead
just generates that list to push to a remote CloudFlare server.

Features:
* CloudFlare DNS integration
* regularly revisits known nodes to check their availability
* bans nodes after enough failures, or bad behaviour
* accepts nodes down to v1.0.4 to request new IP addresses from,
  but only reports good post-v1.0.4 nodes.
* keeps statistics over (exponential) windows of 2 hours, 8 hours,
  1 day and 1 week, to base decisions on.
* very low memory (a few tens of megabytes) and cpu requirements.
* crawlers run in parallel (by default 24 threads simultaneously).

DEVELOPMENT PROCESS
-------------------

The `master` branch is regularly built and tested, but is not guaranteed to be
completely stable. [Tags](https://github.com/VeriConomy/verium-seeder/tags) are created
regularly to indicate new official, stable release versions of Verium.

Current official Verium-Seeder release is on branch 1.3.0.

The contribution workflow is described in [CONTRIBUTING.md](CONTRIBUTING.md).

Developer are on Slack. Join us: https://slack.vericoin.info

Testing
-------

The Travis CI system makes sure that every pull request is built for Windows, Linux (x86, x64, arm)  are run automatically.


REQUIREMENTS
------------

$ sudo apt-get install build-essential libboost-all-dev libssl-dev


USAGE: LOCAL DNS SERVER MODE
-----

Assuming you want to run a dns seed on dnsseed.example.com, you will
need an authorative NS record in example.com's domain record, pointing
to for example vps.example.com:

$ dig -t NS dnsseed.example.com

;; ANSWER SECTION
dnsseed.example.com.   86400    IN      NS     vps.example.com.

On the system vps.example.com, you can now run dnsseed:

./dnsseed -h dnsseed.example.com -n vps.example.com

If you want the DNS server to report SOA records, please provide an
e-mail address (with the @ part replaced by .) using -m.


USAGE: CLOUDFLARE API MODE
--------------------------

Have the seeder above running all the time, but with no NS record.

Fill in CloudFlare API config and have the CloudFlare upload run on a
cron job.


COMPILING
---------

Compiling will require boost and ssl.  On debian systems, these are provided
by `libboost-dev` and `libssl-dev` respectively.

$ make

This will produce the `dnsseed` binary.

TESTING
-------

It's sometimes useful to test `dnsseed` locally to ensure it's giving good
output (either as part of development or sanity checking). You can inspect
`dnsseed.dump` to inspect all nodes being tracked for crawling, or you can
issue DNS requests directly. Example:

$ dig @:: -p 15353 dnsseed.example.com
       ^       ^    ^
       |       |    |__ Should match the host (-h) argument supplied to dnsseed
       |       |
       |       |_______ Port number (example uses the user space port; see below)
       |
       |_______________ Explicitly call the DNS server on localhost


RUNNING AS NON-ROOT
-------------------

Typically, you'll need root privileges to listen to port 53 (name service).

One solution is using an iptables rule (Linux only) to redirect it to
a non-privileged port:

$ iptables -t nat -A PREROUTING -p udp --dport 53 -j REDIRECT --to-port 15353

If properly configured, this will allow you to run dnsseed in userspace, using
the -p 15353 option.

Another solution is allowing a binary to bind to ports < 1024 with setcap (IPv6 access-safe)

$ setcap 'cap_net_bind_service=+ep' /path/to/dnsseed
