#ifndef _BASIS_H_
#define _BASIS_H_

#include <pthread.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <signal.h>
#include "font.h"

#define UINT  unsigned short
#define DWORD unsigned  int
#define LONG unsigned  int
#define WORD unsigned short

pthread_t touch_tid,show_time_tid, show_news_tid, show_title_tid, show_weather_tid, show_adv_tid, t_tid, show_menu_icon_tid;
pthread_t touch_sc_tid, show_search_bg_tid, set_lines_tid, show_adv_tid1, line_touch_tid;
char this_stop[20];
bool touch_flag;
bool main_flag;
bool main_flag1;
bool line_flag;


struct tagBITMAPFILEHEADER
{
    WORD bfType; // 位图文件的类型，必须为BM(1-2字节）
    DWORD bfSize; // 位图文件的大小，以字节为单位（3-6字节）
    WORD bfReserved1; // 位图文件保留字，必须为0(7-8字节）
    WORD bfReserved2; // 位图文件保留字，必须为0(9-10字节）
    DWORD bfOffBits; // 位图数据的起始位置，以相对于位图（11-14字节）
    // 文件头的偏移量表示，以字节为单位
}__attribute__((packed));

struct tagBITMAPINFOHEADER{
    DWORD biSize; // 本结构所占用字节数（15-18字节）
    LONG biWidth; // 位图的宽度，以像素为单位（19-22字节）    ------图片的宽度
    LONG biHeight; // 位图的高度，以像素为单位（23-26字节）   ------图片的高度
    WORD biPlanes; // 目标设备的级别，必须为1(27-28字节）
    WORD biBitCount;// 每个像素所需的位数，必须是1（双色），（29-30字节）  ---位深
    // 4(16色），8(256色）或24（真彩色）之一
    DWORD biCompression; // 位图压缩类型，必须是 0（不压缩），（31-34字节）
    // 1(BI_RLE8压缩类型）或2(BI_RLE4压缩类型）之一
    DWORD biSizeImage; // 位图的大小，以字节为单位（35-38字节）   ---图片颜色数据的大小
    LONG biXPelsPerMeter; // 位图水平分辨率，每米像素数（39-42字节） 
    LONG biYPelsPerMeter; // 位图垂直分辨率，每米像素数（43-46字节)
    DWORD biClrUsed;// 位图实际使用的颜色表中的颜色数（47-50字节）
    DWORD biClrImportant;// 位图显示过程中重要的颜色数（51-54字节）
}__attribute__((packed));

typedef struct lines
{
    char line_num[10];
    int start_time;
    int end_time;
    struct stops *Shead;
    struct buses *Bhead;
    struct lines *next;
    struct lines *prev;
}l_n, *l_p;

typedef struct stops
{
    int stop_num;
    char stop_name [50];
    int last_stop_time;
    struct stops *next;
}s_n, *s_p;

typedef struct buses
{
    char bus_num [20];
    char bus_posi [20];
    int stop_num;
    struct buses *next;
}b_n, *b_p;

typedef struct line_info
{
    char line_num [10];
    char dest_sta [20];
    int wait_time;
    int stop_posi;
}li_n, *li_p;

void *touch();
void *show_time();
void *show_news();
void *show_title();
void *show_weather();
void *show_adv();
void show_pic(char *name, int posi_x, int posi_y, bool flag, bool flag1);
void *show_memu_icon();
l_p line_init();
s_p stops_init();
b_p buses_init();
void add_lines_node(l_p head, char line_num[10], int start_time, int end_time);
void add_stops_node(s_p head, int stop_num, char stop_name [20], int last_stop_time);
void add_buses_node(b_p head, char bus_num [20], char bus_posi [20], int stop_num);
void show_lines(l_p head);
void show_stops(s_p head);
void show_buses(b_p head);
l_p search_line(l_p head, char line_num[10]);
void set_lines();
void add_info(l_p head);
void show_menu();
void *t();
li_n get_line_info(l_p p);
void line_info_test(l_p head);
void touch_search(l_p head);
void *touch_sc();
void *show_search_bg();
void *touch_sc_main();
int show_font_bmp_line(char *font_buf1, char *font_buf2, char *font_buf3, int pic_posi_x, int pic_posi_y, char pic_name[]);
void show_line_info_print(li_n bus_info[3]);
void show_line_info(l_p head);
bool touch_line_but();
void line_touch(l_p head);
void *line_touch_p();
void show_line_stops(l_p head);
void show_bues(l_p head);
int show_font_bmp_bus_info(char *font_buf1, char *font_buf2, int pic_posi_x, int pic_posi_y, char pic_name[], int font_size);
void clear_screen();
l_p head1;

#endif