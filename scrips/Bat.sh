
Bat(){
	CHARGE=`cat /sys/class/power_supply/BAT0/capacity`
	STATUS=`cat /sys/class/power_supply/BAT0/status`
	if [ ${STATUS} = "Charging" ];then
		echo " ${CHARGE}%"
	else
		if [ $CHARGE -ge 90 ]&&[ $CHARGE -le 100 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 80 ]&&[ $CHARGE -lt 90 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 70 ]&&[ $CHARGE -lt 80 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 60 ]&&[ $CHARGE -lt 70 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 50 ]&&[ $CHARGE -lt 60 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 40 ]&&[ $CHARGE -lt 50 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 30 ]&&[ $CHARGE -lt 40 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 20 ]&&[ $CHARGE -lt 30 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 10 ]&&[ $CHARGE -lt 20 ];then
			echo " ${CHARGE}%"
		fi
		if [ $CHARGE -ge 0 ]&&[ $CHARGE -lt 10 ];then
			echo " ${CHARGE}%"
		fi
	fi
}

Bat
