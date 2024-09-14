#include "basis.h"

bool touch_to(){
    int fd = open("/dev/input/event0", O_RDWR);
    if(fd == -1){
        perror("open");
        return false;
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
                // printf("%d ", x);
            }
            if(ev.type == EV_ABS && ev.code == ABS_Y){
                y = ev.value;
                // printf("%d\n", y);
            }
        }
        if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
        {
            if (x > 682 && y > 400 && y < 500)
            {
                printf("touch success but1!\n");
                // pthread_cancel(show_time_tid);
                // pthread_cancel(show_news_tid);
                // pthread_kill(show_adv_tid, SIGUSR1);
                // pthread_cancel(show_title_tid);
                // pthread_cancel(show_weather_tid);
                if (touch_flag == false)
                {
                    touch_flag = true;
                    printf("okok\n");
                }
                else
                {
                    touch_flag = false;
                }
                
                // pthread_continue(show_adv_tid);
                
                // return true;
            }
            
            if (x > 600 && y > 500)
            {
                touch_flag = true;
                main_flag = false;
                show_menu();
                return true;
            }
        }
        
        
    }

    close(fd);
}

void *touch(){
    while (1)
    {
        while (main_flag == false)
        {
            /* code */
        }
        printf("touch_to\n");
        touch_to();
        
    }
}