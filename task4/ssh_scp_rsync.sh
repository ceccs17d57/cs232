#!/usr/bin/env bash

ssh cs17d57@192.168.0.30
ls
rsync -a student_details cs17d57@192.168.0.30:~/test
scp student_details cs17d57@192.168.0.30:~/test
ls
exit
