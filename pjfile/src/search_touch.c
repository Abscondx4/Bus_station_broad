#include "basis.h"

void touch_search(l_p head){
    show_pic("line_search.bmp", 0, 0, false, false);
    int fd = open("/dev/input/event0", O_RDWR);
    if(fd == -1){
        perror("open");
        return;
    }

    struct input_event ev;
    int ret;
    int x,y;
    char line_num[10] = {0};
    int i = 0;
    show_pic("line_search.bmp", 0, 0, false, false);
    while (1)
    {
        ret = read(fd, &ev, sizeof(ev));
        if(ret == sizeof(ev)){
            if(ev.type == EV_ABS && ev.code == ABS_X){
                x = ev.value;
                printf("%d ", x);
            }
            if(ev.type == EV_ABS && ev.code == ABS_Y){
                y = ev.value;
                printf("%d\n", y);
            }
        }
        if (ev.type == EV_KEY && ev.code == BTN_TOUCH && ev.value == 0)
        {
            if (x > 0 && x < 160 && y > 0 && y < 65)
            {
                printf("buttom Back!\n");
                main_flag = true;
                close(fd);
                break;
            }
            
            if (x > 367 && x < 433 && y > 233 && y <296)
            {
                printf("button 1!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '1';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }
            
            if (x > 480 && x < 544 && y > 233 && y <296)
            {
                printf("button 2!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '2';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 590 && x < 654 && y > 233 && y <296)
            {
                printf("button 3!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '3';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }
            
            if (x > 367 && x < 433 && y > 327 && y <406)
            {
                printf("button 4!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '4';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }
            
            if (x > 480 && x < 544 && y > 327 && y <406)
            {
                printf("button 5!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '5';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }
            
            if (x > 590 && x < 654 && y > 327 && y <406)
            {
                printf("button 6!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '6';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 367 && x < 433 && y > 421 && y <483)
            {
                printf("button 7!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '7';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 480 && x < 544 && y > 421 && y <483)
            {
                printf("button 8!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '8';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 590 && x < 654 && y > 421 && y <483)
            {
                printf("button 9!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '9';
                
                
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 480 && x < 544 && y > 515 && y <577)
            {
                printf("button 0!\n");
                if (i == 9)
                {
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                }
                line_num[i] = '0';
                i++;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }

            if (x > 367 && x < 433 && y > 515 && y <577)
            {
                printf("button OK!\n");
                if (i == 0)
                {
                    show_pic("warning_icon.bmp", 300, 150, false, false);
                    break;
                }
                
                l_p n = search_line(head, line_num);
                if (n == NULL)
                {
                    printf("no this line!\n");
                    show_pic("warning_icon.bmp", 300, 150, false, false);
                    for (; i >= 0; i--)
                    {
                        line_num[i] = '\0';
                    }
                    sleep(3);
                    show_pic("line_search.bmp", 0, 0, false, false);
                    
                }
                else
                {
                    close(fd);
                    head1 = n;
                    line_flag = true;
                    main_flag1 = false;
                    
                }
                break;
                
            }
            
            if (x > 590 && x < 654 && y > 515 && y <577)
            {
                printf("button BACK!\n");
                line_num[i-1] = '\0';
                i--;
                show_font_bmp(line_num, 0, 0, "line_search.bmp", 310, 123, 32, 0, 0, 0);
            }
        }
        
        
    }

    close(fd);
}

void *touch_sc(){
    
    l_p head = line_init();
    if (head == NULL)
    {
        perror("init node failed");
    }
    add_lines_node(head, "11", 6, 22);
    add_lines_node(head, "1", 6 ,20);
    add_lines_node(head, "2", 7, 21);
    add_lines_node(head, "3", 7, 21);
    add_lines_node(head, "4", 7, 21);
    add_info(head);
    printf("初始化成功\n");
    while (1)
    {
        // printf("touch_sc\n");
       if (main_flag == false && main_flag1 == true)
       {
        
        printf("touch_sc1\n");
        touch_search(head);
        // printf("touch_sc\n");
       }
       sleep(1);
    //    printf("1\n");
    }
}
