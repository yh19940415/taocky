#!/bin/bash
mkdir -p /home/dji/.dji/version
cp product_tda.xml /home/dji/.dji/version/

set -e

if [ x$1 == x ];then
   echo "please input need update tda4 name: such as master or slave"
   exit 1
fi

echo "input information $1"

if [ $1 == "--master" ];then
	echo "------------------------------->"
	echo "upgrade tda4 master firmware is to be done..."

	cp ./master/j7-* /lib/firmware/
	sync

	echo "upgrade rtos firmware success!!!"
fi


if [ $1 == "--slave" ];then
	echo "------------------------------->"
	echo "upgrade tda4 slave firmware is to be done..."

	cp  ./slave/j7-*  /lib/firmware/
	sync

	echo "upgrade rtos firmware success!!!"
fi


echo "------------------------------->"
echo "upgrade djisyslog.out is to be done..."

cp ./djisyslog.out /usr/sbin/
sync

echo "upgrade djisyslog.out success!!!"


if [ $1 == "--master" ];then
echo "------------------------------->"
echo "upgrade dji_perception.out is to be done..."

cp ./dji_perception.out /usr/sbin/
sync

echo "upgrade dji_perception.out success!!!"


echo "------------------------------->"
echo "upgrade dji_vision_sensor.out is to be done..."

cp ./dji_vision_sensor.out /usr/sbin/
sync

echo "upgrade dji_vision_sensor.out success!!!"
fi


mkdir -p /home/dji/.dji/version
cp ./bsp/bsp_version.h /home/dji/.dji/version/

set -e

echo "------------------------------->"
echo "begin to upgrade libbsp.so:"

BSP_LIB_DIR=/usr/local/lib/dji/bsp/
BSP_LD_FILE=/etc/ld.so.conf.d/

if [ ! -d ${BSP_LIB_DIR} ]; then
    mkdir -p ${BSP_LIB_DIR}
    echo "mkdir "${BSP_LIB_DIR}
fi

rm -rf $BSP_LIB_DIR/*

cp -rf ./bsp/libbsp.so ${BSP_LIB_DIR}

cp -rf ./bsp/dji-bsp.conf ${BSP_LD_FILE}

ldconfig

echo "upgrade libbsp.so ok!"
echo "<-------------------------------"




exit 0
