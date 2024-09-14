#include "basis.h"


void *show_time(){
    int font_size = 38;
    int red = 229;
	int green = 229;
	int blue = 229;
	int pic_posi_x = 599;
	int pic_posi_y = 0;
	int bm_size_x = 200;
	int bm_size_y = 30;

    while (1)
    {
        while (main_flag == false)
        {
            /* code */
        }
        
        time_t t = time(NULL);
        struct tm *curtime = localtime(&t);
        char date[20];
        char time[20];
        sprintf(date, "%d-%d-%d", curtime->tm_year + 1900, curtime->tm_mon + 1, curtime->tm_mday);
        sprintf(time, "%d:%d:%d", curtime->tm_hour, curtime->tm_min, curtime->tm_sec);
        // char *date_buf = date;
        // char *time_buf = time;
        char total[strlen(date)+strlen(time)];
        sprintf(total, "%s\n%s", date, time);
        char *total_buf = total;
        // show_font(date_buf, posi_x, posi_y, bm_size_x, bm_size_y, font_size, red, green, blue);
        // show_font(time_buf, posi_x, 29, bm_size_x, bm_size_y, font_size, red, green, blue);
        show_font_bmp(total_buf, pic_posi_x, pic_posi_y, "time_icon.bmp", 11, 40 ,font_size, red, blue,green);
        // show_font_bmp(time_buf, pic_posi_x, pic_posi_y, "time_icon.bmp", 5, 20 ,font_size, red, blue,green);
        sleep(1);
    }
}