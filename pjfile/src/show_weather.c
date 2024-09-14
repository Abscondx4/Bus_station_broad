#include "basis.h"

void *show_weather(){
    while (1)
    {
    while (main_flag == false)
    {
        /* code */
    }

    int font_size = 40;
    int red = 229;
    int green = 229;
	int blue = 229;
    int pic_posi_x = 599;
    int pic_posi_y = 159;
    int bm_size_x = 200;
    int bm_size_y = 160;

    FILE *fp = fopen("./weather.txt", "r");
    if(fp == NULL){
        printf("File open error\n");
        return NULL;
    }

    char weather[20];
    fgets(weather, 20, fp);
    fclose(fp);

    char *w = weather;
    // printf("%s\n", weather);
    // show_font(w, posi_x, posi_y, bm_size_x, bm_size_y, font_size, red, green, blue);
	// show_font(w, 599, 159, 200, 160, 40, 255, 0, 0);
    show_font_bmp(w, pic_posi_x, pic_posi_y, "weather_icon.bmp", 11, 40, font_size, red, green, blue);
    while (main_flag)
    {
        /* code */
    }
    
    }
    
}