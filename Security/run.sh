#!/system/bin/sh
# Checking ID shell
if [ "$(id -u)" -ne 2000 ]; then
    echo "[ Error |@UnixeID(Yeye)]"
    exit 1
fi
# Cheking cpu.abi
   if [ ! -f /sdcard/Display/lib/sos ]; then
	    architecture=$(getprop ro.product.cpu.abi)
	  if [ "$architecture" = "arm64-v8a" ]; then
		cp /sdcard/Display/lib/arm64 /sdcard/Display/sos
	elif [ "$architecture" = "armeabi-v7a" ]; then
		cp /sdcard/Display/lib/arm /sdcard/Display/sos
	fi
  fi
# Smart Notification
shell() {
    sor="$1"
    cmd notification post -S bigtext -t '♨️ Charger Efisen' 'Tag' "$sor" > /dev/null 2>&1
}
# Style display Terminal
    echo
    echo "     ☆================================☆"
    echo
    echo "       ~ Description. Charger Efisen .... "
    echo
    echo "       - Author                   :  @UnixeID"
    echo "       - Point                      :  1.0"
    echo "       - Release                 :  18 - April - 2025"
    echo "       - Name Shell          :  Charger Efisen "
    echo
    echo "    |_______________________________________|"
    echo "    \______________________________________/"
    echo
    echo "   Priority Charger Efisen Mode Custem. "
    sleep 2
    echo
    echo
     pkill -f src
     rm -rf /data/local/tmp/*
     cp /sdcard/Security/src /data/local/tmp 
     chmod +x /data/local/tmp/src
     if [ "$1" = "-d" ]; then
          shell "Applying Profile Charger Efisen 85% . Please wait 1-6 seconds..."
        nohup /data/local/tmp/src -d >/dev/null 2>&1
     elif [ "$1" = "-L" ]; then
          shell "Applying Profile Charger Efisen 80% . Please wait 1-6 seconds..."
        nohup /data/local/tmp/src -L >/dev/null 2>&1
     elif [ "$1" = "-O" ]; then
          shell "Applying Profile Charger Efisen 70% . Please wait 1-6 seconds..."
        nohup /data/local/tmp/src -O >/dev/null 2>&1
     elif [ "$1" = "-R" ]; then
          shell "Applying Reset Profile Charger Efisen  . Please wait 1-6 seconds..."
          /data/local/tmp/src -R
     elif [ "$1" = "-h" ] || [ "$1" = "--help" ]; then
           /data/local/tmp/src --help
        else
          printf "Failed to apply requested profile. Unknown option: %s\n" "$1"
         fi