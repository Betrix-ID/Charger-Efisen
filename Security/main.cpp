#include <iostream>
#include <cstdlib>
#include <cstring>
#include <unistd.h>
#include <sys/stat.h>
#include <errno.h>
#include <cstdio>
#include "Battery.h"
using namespace std;

#define SCRIPT_VERSION "1.0 [ Battery Custom ]"

void Usage() {
    cout << "Charger Efisen " << SCRIPT_VERSION << " - Automatic Battery Protection Utility\n\n"
         << "Usage:\n"
         << "  ChargerEfisen [OPTION]\n\n"
         << "Options:\n"
         << "  -d           Activate battery protection to stop charging at 85%.\n"
         << "  -L           Activate battery protection to stop charging at 80%.\n"
         << "  -O           Activate battery protection to stop charging at 70%.\n"
         << "  -R           Reset Profile Battery to default.\n"
         << "  -h, --help   Show this help message and exit.\n\n"
         << "Description:\n"
         << "  Charger Efisen is a battery health tool for Android devices.\n"
         << "  It automatically stops the charging process once the battery\n"
         << "  reaches a specific percentage (70%, 80%, or 85%) to help extend\n"
         << "  the overall lifespan of the battery.\n\n"
         << "Examples:\n"
         << "  Activate protection at 85%:\n"
         << "      ChargerEfisen -d\n\n"
         << "  Activate protection at 80%:\n"
         << "      ChargerEfisen -L\n\n"
         << "  Activate protection at 70%:\n"
         << "      ChargerEfisen -O\n\n"
         << "  Reset battery profile to default:\n"
         << "      ChargerEfisen -R\n\n"
         << "Requirements:\n"
         << "  - Root access may be needed to modify charging behavior.\n"
         << "  - Device must support 'adb shell' and related commands.\n\n"
         << "More Info:\n"
         << "  Android Developer Docs : https://developer.android.com/studio/command-line/adb\n"
         << "  Community Support     : https://forum.xda-developers.com\n"
         << "  Help & Q&A             : https://stackoverflow.com/questions/tagged/android\n\n";
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        Usage();
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-d") == 0) {
            sleep(1);
            cout << "- Apply battery protection 85%\n"
                 << "Description:\n"
                 << "  Enables automatic charging stop when the\n"
                 << "  battery reaches 85%.\n\n";
            fflush(stdout);
            security_85();
        }
        else if (strcmp(argv[i], "-L") == 0) {
            sleep(1);
            cout << "- Apply battery protection 80%\n"
                 << "Description:\n"
                 << "  Enables automatic charging stop when the\n"
                 << "  battery reaches 80%.\n\n";
            fflush(stdout);
            security_80();
        }
        else if (strcmp(argv[i], "-O") == 0) {
            sleep(1);
            cout << "- Apply battery protection 70%\n"
                 << "Description:\n"
                 << "  Enables automatic charging stop when the\n"
                 << "  battery reaches 70%.\n\n";
            fflush(stdout);
            security_70();
        }
        else if (strcmp(argv[i], "-R") == 0) {
            sleep(1);
            cout << "- Reset battery profile to default.\n";
            fflush(stdout);
            kill();
        }
        else if (strcmp(argv[i], "-h") == 0 || strcmp(argv[i], "--help") == 0) {
            Usage();
        }
        else {
            cout << "Unknown option: " << argv[i] << "\n";
            return 1;
        }
    }

    sleep(1);
    cout << "\n"
         << " ⚠️ This module is protected by copyright and is\n"
         << " intended for use by regular users only. Any use of\n"
         << " this module, including its code, design, or features,\n"
         << " by other developers without written permission from\n"
         << " the copyright owner is strictly prohibited.\n"
         << "______________________________________________(+)\n\n";
    fflush(stdout);

    return 0;
}