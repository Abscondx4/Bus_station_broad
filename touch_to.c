#include "font.h"

int main(){
    int fd = open("/dev/input/event0", O_RDWR);
    if(fd == -1){
        perror("open");
        return -1;
    }

    struct input_event ev;
    int ret;
    int x,y;
    while (1)
    {
        ret = read(fd, &ev, sizeof(ev));
        if(ret == sizeof(ev)){
            if(ev.type == EV_ABS && ev.code == ABS_X){
                x = ev.value;
                printf("x = %d", x);
            }
            if(ev.type == EV_ABS && ev.code == ABS_Y){
                y = ev.value;
                printf(" y = %d\n", y);
            }
        }
        if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
        {
            if (x > 682 && y > 400)
            {
                printf("touch success!\n");
            }
        }
        
        
    }

    close(fd);
    return 0;
}