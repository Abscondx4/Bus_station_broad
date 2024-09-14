#include "basis.h"

void *show_news(){
    while (1)
    {
    
    while (main_flag == false)
    {
        /* code */
    }
    
    int font_size = 45;
    int red = 229;
    int green = 229;
	int blue = 229;
    int pic_posi_x = 0;
    int pic_posi_y = 419;
    int bm_size_x = 600;
    int bm_size_y = 60;

    char news[][500] = {"从化区发布暴雨红色预警","从10路今日停运","小孩骑行被碾身亡案司机被移送检方","习近平点赞奥运健儿赤子情怀"};

    while (main_flag == false);

    for (int i = 0; i < 4; i++)
    {
        char *news_buf = news[i];
        if (main_flag == 0)
        {
            break;
        }
        // show_font(news_buf, posi_x, posi_y, bm_size_x, bm_size_y, font_size, red, green, blue);
		// show_font(news_buf, 0, 419, 600, 60, 48, 255 ,0, 0);
        show_font_bmp(news_buf, pic_posi_x, pic_posi_y, "news_icon.bmp", 50, 8, font_size, red, green, blue);
        sleep(5);
        
        
        if (i + 1 == 4)
        {
            i = 0;
        }
    }
    }
    
    
}