#include <sysutil/sysutil.h>
#include <unistd.h>

static int exit_requested = 0;

static void system_callback(u64 status, u64 param, void *userdata)
{
    (void)param;
    (void)userdata;

    if (status == SYSUTIL_EXIT_GAME)
        exit_requested = 1;
}

int main(void)
{
    sysUtilRegisterCallback(
        SYSUTIL_EVENT_SLOT0,
        system_callback,
        NULL
    );

    while (!exit_requested)
    {
        sysUtilCheckCallback();
        usleep(10000);
    }

    sysUtilUnregisterCallback(SYSUTIL_EVENT_SLOT0);

    return 0;
}
