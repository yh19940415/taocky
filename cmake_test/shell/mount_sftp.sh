#!/bin/bash

#install sshfs
if [ -z "`dpkg -l | grep sshfs`" ]; then
  sudo apt install sshfs
fi

if [ ! -d "/mnt/sftp" ]; then
  sudo mkdir /mnt/sftp
fi

#mount sftp
sftp_mntpoint=`mount | grep /mnt/sftp`
if [ -z "$sftp_mntpoint" ]; then
  echo "now, need to mount to /mnt/sftp, passowrd is: [ PwsA@4d! ] "
  sudo sshfs -p 8022 -o allow_other sftp@10.10.250.52:/ /mnt/sftp
fi

echo "mount successful!"
cd /mnt/sftp
pwd
echo "the tftp file server is mounted on /mnt/sftp"
