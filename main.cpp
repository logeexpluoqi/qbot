/**
 * Author: luoqi
 * Created Date: 2025-09-26 22:05:24
 * Last Modified: 2025-09-26 22:33:18
 * Modified By: luoqi at <**@****>
 * Copyright (c) 2025 <*****>
 * Description:
 */

#include "src/qbot.h"
#include "qshell/qshell.h"

static QShell &cli = QShellSingleton::instance();

int main()
{
    cli.title();
    cli.start();
    while(true) {
        std::this_thread::sleep_for(std::chrono::seconds(1));
    }
    return 0;
}
