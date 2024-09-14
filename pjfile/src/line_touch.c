#include "basis.h"

void line_touch(l_p head){
    
    int fd = open("/dev/input/event0", O_RDWR);
    if(fd == -1){
        perror("open");
        return;
    }
    show_line_stops(head);
    struct input_event ev;
    int ret;
    int x,y;
    char line_num[10] = {0};
    int i = 0;
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
            if (x > 0 && x < 160 && y > 0 && y < 65)
            {
                printf("buttom Back!\n");
                main_flag == false;
                main_flag1 = true;
                line_flag = false;
                close(fd);
                break;
            }
            
            if(x > 0 && x < 154 && y > 300 && y < 450)
            {
                printf("buttom 1!\n");
                clear_screen();
                show_line_stops(head);
            }

            if(x > 0 && x < 154 && y > 450 && y < 600)
            {
                printf("buttom 2!\n");
                clear_screen();
                show_bues(head);
            }

        }
    }

    close(fd);
}

void *line_touch_p()
{
    
    // printf("line_touch_p\n");
    while (1)
    {
        sleep(1);
        printf("line_touch_p\n");
        if (line_flag)
        {   
            printf("line_touch_p2\n");
            show_pic("line_info_bg.bmp", 0, 0, false, false);
            line_touch(head1);
        }
        printf("line_touch_p1\n");
    }
    
}

void show_line_stops(l_p head)
{
    int pic_posi_x = 120;
    int pic_posi_y = 0;
    s_p stops = head->Shead->next;
    for (int i = 0; i < 12; i++)
    {
        char stop_name[50];
        strcpy(stop_name, stops->stop_name);
        show_font_bmp(stops->stop_name, pic_posi_x, pic_posi_y, "line_lable.bmp", 50, 22, 40, 0, 0, 0);
        if (stops->next == head->Shead)
        {
            break;
        }
        
        stops = stops->next;
        pic_posi_y += 80;
        if (i == 5)
        {
            pic_posi_x += 340;
        }
        
    }
    
}

void show_bues(l_p head)
{
    int pic_posi_x = 120;
    int pic_posi_y = 00;
    b_p buses = head->Bhead->next;
    for (int i = 0; i < 14; i++)
    {
        char bus_num[20];
        char bus_posi[80];
        printf("车牌号\n", buses->bus_num);
        sprintf(bus_num, "车牌号：%s", buses->bus_num);
        sprintf(bus_posi, "车辆位置：%s", buses->bus_posi);
        show_font_bmp_bus_info(bus_num, bus_posi, pic_posi_x, pic_posi_y, "bus_lable.bmp", 30);
        if (buses->next == head->Bhead)
        {
            break;
        }
        
        buses = buses->next;
        pic_posi_y += 80;
        if (i == 6)
        {
            pic_posi_x += 340;
        }
        
    }
    
}