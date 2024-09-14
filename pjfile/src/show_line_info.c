#include "basis.h"

void show_line_info(l_p head)
{
    printf("show_line\n");
    char *pic_name = "line_but.bmp";
    l_p p = head->next;
    li_n bus_info [4];
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        bus_info[i] = get_line_info(p);
        // printf("%s\n", bus_info[i].line_num);
        // printf("%s\n", bus_info[i].dest_sta);
        // printf("%d\n", bus_info[i].wait_time);
        p = p->next;
        if (p->next == head)
        {
            break;
        }
    }
    show_line_info_print(bus_info);
    // touch_flag = touch_line_but();
    // printf("touch_flag = %d\n", touch_flag);
    while (touch_flag == false)
    {
        /* code */
    }
    
}

// bool touch_line_but()
// {
//     int fd = open("/dev/input/event0", O_RDWR);
//     if(fd == -1){
//         perror("open");
//         return -1;
//     }

//     struct input_event ev;
//     int ret;
//     int x,y;
//     // while (1)
//     // {
//         ret = read(fd, &ev, sizeof(ev));
//         if(ret == sizeof(ev)){
//             if(ev.type == EV_ABS && ev.code == ABS_X){
//                 x = ev.value;
//                 printf("%d ", x);
//             }
//             if(ev.type == EV_ABS && ev.code == ABS_Y){
//                 y = ev.value;
//                 printf("%d\n", y);
//             }
//         }
//         if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
//         {
//             if (x > 682 && y > 400 && y < 500)
//             {
//                 return true;
//             }
//         }
        
        
//     // }

// }

void show_line_info_print(li_n bus_info[3])
{
    char pic_name[] = "line_bg.bmp";
    int pic_posi_x = 0;
    int pic_posi_y = 61;
    for (int i = 0; i < 4; i++)
    {
        // printf("%s\n", bus_info[i].line_num);
        printf("%s\n", bus_info[i].dest_sta);
        // printf("%d\n", bus_info[i].wait_time);
        char *line_name = bus_info[i].line_num;
        char end_station[50];
        sprintf(end_station, "终点站：%s", bus_info[i].dest_sta);
        char *end_station_p = end_station;
        char wait_time[30];
        sprintf(wait_time, "等待时间：%d分钟", bus_info[i].wait_time);
        char *wait_time_p = wait_time;
        show_font_bmp_line(line_name, end_station_p, wait_time_p, pic_posi_x, pic_posi_y, pic_name);
        pic_posi_y += 90;
    }
    
}
