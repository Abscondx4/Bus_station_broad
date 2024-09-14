#include "font.h"

// 编译命令：arm-linux-gcc show_font.c -o main -L ./ -lfont -lm
//1、初始化Lcd
struct LcdDevice *init_lcd(const char *device)
{
	//申请空间
	struct LcdDevice* lcd = malloc(sizeof(struct LcdDevice));
	if(lcd == NULL)
	{
		return NULL;
	} 

	//1打开设备
	lcd->fd = open(device, O_RDWR);
	if(lcd->fd < 0)
	{
		perror("open lcd fail");
		free(lcd);
		return NULL;
	}
	
	//映射
	lcd->mp = mmap(NULL,800*480*4,PROT_READ|PROT_WRITE,MAP_SHARED,lcd->fd,0);

	return lcd;
}

int show_font(char *font_buf, int x, int y)
{
    //1、打开Lcd屏幕(以读写的形式打开)
	struct LcdDevice* lcd = init_lcd("/dev/fb0");	

	//2、要有字(找到字库并打开)
	font *f = fontLoad("/usr/share/fonts/DroidSansFallback.ttf");
	//字体大小的设置 48是字体的大小
	fontSetSize(f,48);
	
	//3、创建一个画板
	//								画板长度，宽度，字节像素，画板颜色
	bitmap *bm = createBitmapWithInit(600,60,4,getColor(0,0,0,0));
										            //A  B   G   R
	
	//4、将字写到画板上，形成了一幅画(bm)
	//字在画板的起始位置（X:100，Y:0）
	fontPrint(f,bm,0,0,font_buf,getColor(0,0,0,255),0);
							 			//A  B   G   R
							 
	//5、将这幅画显示到lcd显示屏上
	//画板在显示屏上的起始位置（X:0，Y:100）
	show_font_to_lcd(lcd->mp,x,y,bm);

	//6、关闭字体，关闭画板
	fontUnload(f);
	destroyBitmap(bm);

}

int main(int argc, char const *argv[])
{
    char news[][20] = {"从化客运站","广州客运站","深圳客运站","珠海客运站"};

	for (int i = 0; i < 4; i++)
    {
        char *news_buf = news[i];
        show_font(news_buf, 0, 419);
        sleep(5);	
    }
    
	return 0;
}