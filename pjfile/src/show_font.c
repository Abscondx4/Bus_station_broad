#include "basis.h"

int show_font(char *font_buf, int posi_x, int posi_y, int size_x, int size_y, int font_size, int red, int green, int blue){
    //1、打开Lcd屏幕(以读写的形式打开)
	struct LcdDevice* lcd = init_lcd("/dev/fb0");	

	//2、要有字(找到字库并打开)
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置 48是字体的大小
	fontSetSize(f,font_size);
	
	//3、创建一个画板
	//								画板长度，宽度，字节像素，画板颜色
	bitmap *bm = createBitmapWithInit(size_x,size_y,4,getColor(255,227,103,41));
										            //A  B   G   R
	
	//4、将字写到画板上，形成了一幅画(bm)
	//字在画板的起始位置（X:100，Y:0）
	fontPrint(f,bm,0,0,font_buf,getColor(0, blue, green, red),0);
							 			//A  B   G   R
							 
	//5、将这幅画显示到lcd显示屏上
	//画板在显示屏上的起始位置（X:0，Y:100）
	show_font_to_lcd(lcd->mp, posi_x, posi_y, bm);

	//6、关闭字体，关闭画板
	fontUnload(f);

	destroyBitmap(bm);

}