#!/usr/bin/env bash

sftp cs17d57@192.168.0.30
put -r student_details
get -r student_details
rm -r student_details

