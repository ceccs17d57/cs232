#!/usr/bin/env bash

ifconfig
sudo ifconfig eth0 down
ifconfig
sudo ifconfig eth0 up
sudo ifconfig
sudo ifconfig eth0 192.168.1.22
