#!/bin/bash

#mount 10.10.249.40:/volume6/BR1609SSD /mnt
sudo ./mountnas1.sh
rm tda4_*

#./djisyslog.out &

dcos_init

dji_sys &

sleep 10

dji_log &

sleep 1

diag &

sleep 3

dji_hal --offline &

sleep 3

#dji_bag play -d /mnt/dailyRawdata/20190320_car11_v20.0.3_jira11056_fugang.zhen_yanjianggaosu_day_cloudy/AIPC_DATA0 --local --loop_mode
#dji_bag play -d /nas1/dailyRawdata/20190719_car3_21.4.0_jira14461_Hunterlew.Liu_chiwanD3_day_sunny_tpv1/AIPC_DATA0/ --local



#sudo dji_bag play -d /var/dlog/keith/AIPC_DATA_LEON --local --loop_mode --is_send_mail true --mail_rev_addr_lst haocky.yu@dji.com --mail_title autotest
dcos_debug topic list | grep /gpu/h264_cam_2/v1
dcos_debug topic msg -topic_name /gpu/h264_cam_7/v1

dcos_debug topic msg -topic_name test_topic_6_2
