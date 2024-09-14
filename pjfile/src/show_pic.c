#include "basis.h"

void show_pic(char *name, int posi_x, int posi_y, bool flag, bool flag1){
    if (touch_flag)
    {
        int bmp_fd = open(name, O_RDONLY);
        if (bmp_fd == -1)
        {
            perror("open bmp");
            return;
        }
    
    struct tagBITMAPFILEHEADER buf1;
    read(bmp_fd, &buf1, sizeof(buf1)); // 读取bmp文件的格式信息

    struct tagBITMAPINFOHEADER buf2;
    read(bmp_fd, &buf2, sizeof(buf2)); // 读取bmp文件的内容信息
    // 显示任意大小的图片： 需要注意我们的长必须是4的倍数
    
    char buf[buf2.biWidth*buf2.biHeight*3];
    bzero(buf, sizeof(buf));
    read(bmp_fd, buf, sizeof(buf)); // 读取颜色数据
    
    close(bmp_fd);

    // 处理屏幕文件
    printf("%s", name);
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd");
        return;
    }
    
    // 申请映射空间
    int *mmap_start = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mmap_start == MAP_FAILED)
    {
        perror("mmap error");
        return;
    }

    int *new_start = mmap_start+posi_y*800+posi_x; // 起点是(100,100)

    // int random = 1+(rand()%2);
    // printf("random=%d", random);
    // switch (random)
    // {
    // case 1:
    // {
    //     int n=0;
    //     for(int y=0; y<buf2.biHeight; y++)
    //     {
    //         for(int x=0; x<buf2.biWidth; x++, n+=3)
    //         {
    //             new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
    //         }
    //         usleep(1000);
    //     }
    // }
    // case 2:
    // {
    //     int n=0;
    //     for(int y = buf2.biHeight-1; y >= 0; y--)
    //     {
    //         for(int x=0; x<buf2.biWidth; x++, n+=3)
    //         {
    //             new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
    //         }
    //         usleep(1000);
    //     }
    // }
    // case 3:
    // {
    //     int n=0;
    //     for(int x=0; x<buf2.biWidth; x++, n+=3)
    //     {
    //         for(int y=0; y<buf2.biHeight; y++)
    //         {
    //             new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
    //         }
    //         usleep(1000);
    //     }
    // }
    // case 4:
    // {
    //     int n=0;
    //     for(int x = buf2.biWidth-1; x >= 0; x++, n+=3)
    //     {
    //         for(int y=0; y<buf2.biHeight; y++)
    //         {
    //             new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
    //         }
    //         usleep(1000);
    //     }
    // }
    // case 5:
    // {
    //     int n=0;
    //     for(int r=350;r>=0;r-=5)
    //     {
    //         for(int y=0;y<buf2.biHeight;y++)
    //         {
    //             for(int x=0;x<buf2.biWidth;x++)
    //             {
    //                 if ((x-300)*(x-300)+(y-180)*(y-180)>=r*r)
    //                 {
    //                     new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
    //                 }
    //             }
    //         }
    //     }
    // }
    // default:
    //     break;
    // }
    if (touch_flag == false)
    {
        close(lcd_fd);
        return;
    }

    // if (main_flag == false)
    // {
    //     return;
    // }
    
    
    int n=0;
        for(int y=0; y<buf2.biHeight; y++)
        {
            for(int x=0; x<buf2.biWidth; x++, n+=3)
            {
                new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
                if (touch_flag == false)
                {
                    close(lcd_fd);
                    return;
                }
            }
           if (flag)
           {
                usleep(1000);
           }
           
        }

    if (flag1)
    {
        sleep(1);
        if (touch_flag == false)
            {
                close(lcd_fd);
                return;
            }
        sleep(1);
        if (touch_flag == false)
            {
                close(lcd_fd);
                return;
            }
        sleep(1);
        if (touch_flag == false)
            {
                close(lcd_fd);
                return;
            }
        sleep(1);
        if (touch_flag == false)
            {
                close(lcd_fd);
                return;
            }
        sleep(1);
    for(int y=61;y<421;y++)
    {
        for(int x=0;x<601;x++)
        {
            mmap_start[800*y+x] = 0x000000;
            if (touch_flag == false)
            {
                close(lcd_fd);
                return;
            }
            if (main_flag == false)
            {
                close(lcd_fd);
                return;
            }
        }
        if (flag)
        {
            usleep(1000);
        }
    }
    }
    

    // 撤销映射空间
    munmap(mmap_start, 800*480*4);

    // 关闭lcd文件
    close(lcd_fd);
    }
    
}

void clear_screen()
{
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd");
        return;
    }
    int *mmap_start = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mmap_start == MAP_FAILED)
    {
        perror("mmap error");
        return;
    }

    for(int y=0;y<480;y++)
    {
        for(int x=119;x<800;x++)
        {
            mmap_start[800*y+x] = 0xcccccc;
        }
    }
    munmap(mmap_start, 800*480*4);

    // 关闭lcd文件
    close(lcd_fd);
}