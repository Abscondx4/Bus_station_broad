#ifndef __FONT_H
#define __FONT_H

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <linux/input.h>
#include <time.h>


//===========================五、字库的变量和函数===========================//
#define color u32
#define getColor(a, b, c, d) (a|b<<8|c<<16|d<<24)
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;

typedef char s8;
typedef short s16;
typedef int s32;
typedef long long s64;

typedef struct stbtt_fontinfo
{
   void           * userdata;
   unsigned char  * data;              // pointer to .ttf file
   int              fontstart;         // offset of start of font

   int numGlyphs;                     // number of glyphs, needed for range checking

   int loca,head,glyf,hhea,hmtx,kern; // table locations as offset from start of .ttf
   int index_map;                     // a cmap mapping for our chosen character encoding
   int indexToLocFormat;              // format needed to map from glyph index to glyph
} stbtt_fontinfo;


typedef struct{
	u32 height;
	u32 width;
	u32 byteperpixel;
	u8 *map;
}bitmap;

typedef struct{
	stbtt_fontinfo *info;
	u8 *buffer;
	float scale;
}font;


//lcd设备结构体
struct LcdDevice
{
	int fd;
	unsigned int *mp; //保存映射首地址

};
//1.初始化字库 
font *fontLoad(char *fontPath);
//2.设置字体的大小 
void fontSetSize(font *f, s32 pixels);
//3.设置字体输出框的大小
bitmap *createBitmap(u32 width, u32 height, u32 byteperpixel);
//可以指定输出框的颜色
bitmap *createBitmapWithInit(u32 width, u32 height, u32 byteperpixel, color c);
//4.把字体输出到输出框中
void fontPrint(font *f, bitmap *screen, s32 x, s32 y, char *text, color c, s32 maxWidth);
//5.把输出框的所有信息显示到LCD屏幕中 
void show_font_to_lcd(unsigned int *p,int px,int py,bitmap *bm);
//6、关闭字体库
void fontUnload(font *f);
//7、关闭bitmap
void destroyBitmap(bitmap *bm);
//8、初始化Lcd
struct LcdDevice *init_lcd(const char *device);
//9、显示字,	x,y是起点坐标
// int show_font(char *font_buf, int x, int y);
int show_font(char *font_buf, int posi_x, int posi_y, int size_x, int size_y, int font_size, int red, int green, int blue);

bitmap *createBitmapWithInit_bmp(char *bmppath);

int show_font_bmp(char *font_buf, int pic_posi_x, int pic_posi_y, char pic_name[], int font_posi_x, int font_posi_y, int font_size, int red, int green, int blue);


#endif