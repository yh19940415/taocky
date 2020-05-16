while getopts ":c:t:" opt
do
    case $opt in
        t)
            case $OPTARG in
                s|1)
                    echo "1 tail -f tda4_log_MCU2_0_log*"
                    tail -f tda4_log_MCU2_0_log*
                    ;;
                2)
                    echo "2 tail -f tda4_log_MCU2_1_log*"
                    tail -f tda4_log_MCU2_1_log*
                    ;;
                3)
                    echo "3 tail -f tda4_log_MCU3_0_log*"
                    tail -f tda4_log_MCU3_0_log*
                    ;;
                4)
                    echo "4 tail -f tda4_log_MCU3_1_log*"
                    tail -f tda4_log_MCU3_1_log*
                    ;;
                5)
                    echo "5 tail -f tda4_log_C6x_1_log*"
                    tail -f tda4_log_C6x_1_log*
                    ;;
                6)
                    echo "6 tail -f tda4_log_C6x_2_log*"
                    tail -f tda4_log_C6x_2_log*
                    ;;
                7)
                    echo "7 ail -f tda4_log_C7x_1_log*"
                    tail -f tda4_log_C7x_1_log*
                    ;;                         
                *)
                    echo "not support $OPTAR"
                    exit 1
                    ;;
                esac
        ;;
        c)
            case $OPTARG in
                s|1)
                    echo "1 cat tda4_log_MCU2_0_log*"
                    cat tda4_log_MCU2_0_log*
                    ;;
                2)
                    echo "2 cat tda4_log_MCU2_1_log*"
                    cat tda4_log_MCU2_1_log*
                    ;;
                3)
                    echo "3 cat tda4_log_MCU3_0_log*"
                    cat tda4_log_MCU3_0_log*
                    ;;
                4)
                    echo "4 cat tda4_log_MCU3_1_log*"
                    cat tda4_log_MCU3_1_log*
                    ;;
                5)
                    echo "5 cat tda4_log_C6x_1_log*"
                    cat tda4_log_C6x_1_log*
                    ;;
                6)
                    echo "6 cat tda4_log_C6x_2_log*"
                    cat tda4_log_C6x_2_log*
                    ;;
                7)
                    echo "7 cat tda4_log_C7x_1_log*"
                    cat tda4_log_C7x_1_log*
                    ;;                         
                *)
                    echo "not support $OPTAR"
                    exit 1
                    ;;
                esac
        ;;           
        ?)
        echo "未知参数"
        exit 1;;
    esac
done


exit 0

