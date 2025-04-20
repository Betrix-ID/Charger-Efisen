#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstdio>
#include "Battery.h"

// #include "Battery.h" // Tidak perlu jika tidak dipakai
using namespace std;

void shell(const char* message) {
    string cmd = "cmd notification post -S bigtext -t '♨️ Charger Efisen' 'Tag' '" + string(message) + "' > /dev/null 2>&1";
    system(cmd.c_str());
}

int get_battery_level() {
    FILE* pipe = popen("cat /sys/class/power_supply/battery/capacity", "r");
    if (!pipe) {
        cout << "Error: Gagal membaca level baterai.\n";
        return -1;
    }
    char buffer[128];
    int level = -1;
    if (fgets(buffer, sizeof(buffer), pipe) != nullptr) {
        sscanf(buffer, "%d", &level); // FIX parsing
    }
    pclose(pipe);
    return level;
}

void security_80() {
    bool unplugged = false;
    while (true) {
        int level = get_battery_level();
        if (level >= 80 && !unplugged) {
            cout << "Battery level is " << level << "%. Stopping charge...\n";
            fflush(stdout);
            system("cmd battery unplug");
            shell("Battery 80% reached: Charging stopped.");
            unplugged = true;
        }
        else if (level < 75 && unplugged) {
            cout << "Battery level dropped to " << level << "%. Reset charging...\n";
            fflush(stdout);
            system("cmd battery reset -f unplug");
            shell("Battery dropped below 75%, charging allowed again.");
            unplugged = false;
        }
        else {
            cout << "Battery level now " << level << "%.\n";
            fflush(stdout);
        }
        sleep(5);
    }
}

void security_70() {
    bool unplugged = false;
    while (true) {
        int level = get_battery_level();
        if (level >= 70 && !unplugged) {
            cout << "Battery level is " << level << "%. Stopping charge...\n";
            fflush(stdout);
            system("cmd battery unplug");
            shell("Battery 70% reached: Charging stopped.");
            unplugged = true;
        }
        else if (level < 65 && unplugged) {
            cout << "Battery level dropped to " << level << "%. Reset charging...\n";
            fflush(stdout);
            system("cmd battery reset -f unplug");
            shell("Battery dropped below 65%, charging allowed again.");
            unplugged = false;
        }
        else {
            cout << "Battery level now " << level << "%.\n";
            fflush(stdout);
        }
        sleep(5);
    }
}

void security_85() {
    bool unplugged = false;
    while (true) {
        int level = get_battery_level();
        if (level >= 85 && !unplugged) {
            cout << "Battery level is " << level << "%. Stopping charge...\n";
            fflush(stdout);
            system("cmd battery unplug");
            shell("Battery 85% reached: Charging stopped.");
            unplugged = true;
        }
        else if (level < 80 && unplugged) {
            cout << "Battery level dropped to " << level << "%. Reset charging...\n";
            fflush(stdout);
            system("cmd battery reset -f unplug");
            shell("Battery dropped below 80%, charging allowed again.");
            unplugged = false;
        }
        else {
            cout << "Battery level now " << level << "%.\n";
            fflush(stdout);
        }
        sleep(5);
    }
}

void kill() {
    cout << "Description:\n"
         << "  Reset battery settings to default.\n\n";
    fflush(stdout);

    int result = system(
        "dumpsys battery reset >/dev/null 2>&1 && "
        "cmd battery reset >/dev/null 2>&1 && "
        "rm -rf /data/local/tmp/src >/dev/null 2>&1 && "
        "pkill -f src >/dev/null 2>&1 && "
        "pkill -f sh >/dev/null 2>&1"
    );
    if (result != 0) {
        cout << "Error: Gagal menerapkan pengaturan.\n";
    }
    shell("Scripting: success reset to default");
}