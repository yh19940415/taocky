#!/bin/bash
local_ip=dji@10.60.123.72
ip1=dji@10.60.123.133
ip2=dji@10.60.123.24
pack=1
while getopts ":t:n:p:" opt
do
    case $opt in
        t)
            case $OPTARG in
                "dcos")
                    type=debug_br1609_dcos
                    ;;
                "product")
                    type=debug_br1609_product_tda
                    ;;
                esac
        ;;
        n)
            case $OPTARG in
                1)
                    ip=${ip1}
                    ;;
                2)
                    ip=${ip2}
                    ;;
                esac
        ;;
        p)
            package=$OPTARG
        ;;
        ?)
        echo "未知参数"
        exit 1;;
    esac
done
echo ip:$ip
echo type:$type
echo package:${package}".zip"



ssh ${ip} > /dev/null 2>&1 << eeooff

mkdir /home/dji/haocky/package/${package}
exit
eeooff
echo done!

cd ~/Downloads
rm ${package} -rf
unzip ${package}.zip

echo "dji" | sudo -S scp /home/dji/Downloads/${package}/* ${ip}:~/haocky/package/${package}

if [ $type == debug_br1609_dcos ]
then
ssh ${ip} > /dev/null 2>&1 << eeooff
cd ~/haocky/package/${package}
sudo tar -zxvf ${type}*
sudo ./${type}*/upgrade.sh
exit
eeooff
echo done!
fi

if [ $type == debug_br1609_product_tda ]
then
ssh ${ip} > /dev/null 2>&1 << eeooff
cd ~/haocky/package/${package}
sudo tar -zxvf ${type}*
sudo cp -v debug_br1609_product*/dcos_test* /lib/firmware
sudo mv -v debug_br1609_product*/djisyslog.out ~/haocky/package/${package}/
sudo chmod 777 ~/haocky/package/${package}/djisyslog.out
exit
eeooff
echo done!
fi

