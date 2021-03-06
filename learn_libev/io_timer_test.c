#include <stdio.h>
#include <ev.h>

static ev_io stdin_watcher;
static ev_timer timeout_watcher;

static void stdin_cb(EV_P_ ev_io *w, int revents) {
    puts("stdin ready");
    char buf[100];
    scanf("%s", buf);
    printf("stdin is :%s\n", buf);
    //ev_io_stop(EV_A_ w);
    //ev_break(EV_A_ EVBREAK_ALL);
}

static void timeout_cb(EV_P_ ev_timer *w, int revents) {
    puts("timeout");
    ev_timer_stop(EV_A_ w);
    ev_break(EV_A_ EVBREAK_ALL);
}

int main() {
    struct ev_loop *loop = EV_DEFAULT;

    ev_io_init(&stdin_watcher, stdin_cb, 0, EV_READ);
    ev_io_start(loop, &stdin_watcher);

    ev_timer_init(&timeout_watcher, timeout_cb, 5.5, 0);
    ev_timer_start(loop, &timeout_watcher);

    ev_run(loop, 0);
    printf("hello world\n"); 
    return 0;
}
