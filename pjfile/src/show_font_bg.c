#include "basis.h"

int show_font_bmp(char *font_buf, int pic_posi_x, int pic_posi_y, char pic_name[], int font_posi_x, int font_posi_y, int font_size, int red, int green, int blue)
{
    //1、打开Lcd屏幕(以读写的形式打开)
	struct LcdDevice* lcd = init_lcd("/dev/fb0");	

	//2、要有字(找到字库并打开)
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置 48是字体的大小
	fontSetSize(f,font_size);
	
	//3、创建一个画板
	//								画板长度，宽度，字节像素，画板颜色
	bitmap *bm = createBitmapWithInit_bmp(pic_name);
										            //A  B   G   R
	
	//4、将字写到画板上，形成了一幅画(bm)
	//字在画板的起始位置（X:100，Y:0）
	fontPrint(f,bm,font_posi_x,font_posi_y,font_buf,getColor(0, blue, green, red),0);
							 			//A  B   G   R
							 
	//5、将这幅画显示到lcd显示屏上
	//画板在显示屏上的起始位置（X:0，Y:100）
	show_font_to_lcd(lcd->mp,pic_posi_x, pic_posi_y,bm);

	//6、关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);

}

int show_font_bmp_line(char *font_buf1, char *font_buf2, char *font_buf3, int pic_posi_x, int pic_posi_y, char pic_name[])
{
    //1、打开Lcd屏幕(以读写的形式打开)
	struct LcdDevice* lcd = init_lcd("/dev/fb0");	

	//2、要有字(找到字库并打开)
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置 48是字体的大小
	fontSetSize(f,48);
	
	//3、创建一个画板
	//								画板长度，宽度，字节像素，画板颜色
	bitmap *bm = createBitmapWithInit_bmp(pic_name);
										            //A  B   G   R
	
	//4、将字写到画板上，形成了一幅画(bm)
	//字在画板的起始位置（X:100，Y:0）
	fontPrint(f,bm,0,0,font_buf1,getColor(0, 0, 0, 255),0);
	fontPrint(f,bm,50,0,font_buf2,getColor(0, 255, 255, 255),0);
	fontPrint(f,bm,50,40,font_buf3,getColor(0, 255, 255, 255),0);
							 			//A  B   G   R
							 
	//5、将这幅画显示到lcd显示屏上
	//画板在显示屏上的起始位置（X:0，Y:100）
	show_font_to_lcd(lcd->mp,pic_posi_x, pic_posi_y,bm);

	//6、关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);

}

int show_font_bmp_bus_info(char *font_buf1, char *font_buf2, int pic_posi_x, int pic_posi_y, char pic_name[], int font_size)
{
    //1、打开Lcd屏幕(以读写的形式打开)
	struct LcdDevice* lcd = init_lcd("/dev/fb0");	

	//2、要有字(找到字库并打开)
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置 48是字体的大小
	fontSetSize(f,30);
	
	//3、创建一个画板
	//								画板长度，宽度，字节像素，画板颜色
	bitmap *bm = createBitmapWithInit_bmp(pic_name);
										            //A  B   G   R
	
	//4、将字写到画板上，形成了一幅画(bm)
	//字在画板的起始位置（X:100，Y:0）
	fontPrint(f,bm,45,12,font_buf1,getColor(0, 0, 0, 0),0);
	fontPrint(f,bm,45,37,font_buf2,getColor(0, 0, 0, 0),0);
							 			//A  B   G   R
							 
	//5、将这幅画显示到lcd显示屏上
	//画板在显示屏上的起始位置（X:0，Y:100）
	show_font_to_lcd(lcd->mp,pic_posi_x, pic_posi_y,bm);

	//6、关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);

}