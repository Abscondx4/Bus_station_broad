#include "basis.h"

bitmap *createBitmapWithInit_bmp(char *bmppath)
{
	// 一、获取bmp图片的数据(第一部分的信息(bmp图片54个字节的头信息数据)和第二部分(bmp的颜色数据(BGR)))
	// 1、打开bmp图片文件
	int bmp_fd = open(bmppath,  O_RDONLY);
	if(bmp_fd == -1)
	{
		perror("打开bmp文件失败！\n");
		return (bitmap *)-1;
	}
	
	// 2、获取第一部分的信息(bmp图片54个字节的头信息数据)
    struct tagBITMAPFILEHEADER buf1;
    read(bmp_fd, &buf1, sizeof(buf1)); // 读取bmp文件的格式信息
    // printf("文件的大小:%u\n", buf1.bfSize);

    struct tagBITMAPINFOHEADER buf2;
    read(bmp_fd, &buf2, sizeof(buf2)); // 读取bmp文件的内容信息
    // printf("图片的长：%d,宽：%d\n", buf2.biWidth, buf2.biHeight);
	
	int w = buf2.biWidth;						// 获取bmp图片的宽度
	int h = buf2.biHeight;					// 获取bmp图片的高度
    // printf("图片的长：%d,宽：%d\n", w, h);
	
	// 3、获取第二部分(bmp的颜色数据(BGR))
	
	char bmp_buf[w*h*3];					// 变长数组，不能赋值
	read(bmp_fd, bmp_buf, w*h*3);			// 读取到的数据是上下翻转颠倒的
	
	// 4、关闭bmp图片文件
	close(bmp_fd);
	
	// 二、将bmp图片数据，写入画板中
	bitmap *bm = createBitmap(w, h, 4); // 200*200*4

	char new_buf[w*h*4];
	for(int i=0,n=0; i<w*h*4; i+=4, n+=3)
	{
		new_buf[i+0] = bmp_buf[n+0];
		new_buf[i+1] = bmp_buf[n+1];
		new_buf[i+2] = bmp_buf[n+2];
		new_buf[i+3] = 0x00;
	}
	char show_buf[w*h*4];
    for(int y=0;y<h;y++)
    {
        for(int x=0;x<w*4;x++)
        {
            show_buf[w*(h-1-y)*4+x] = new_buf[w*4*y+x];
		}
    }

	for(int i=0; i<w*h*4; i++)
    {
        bm->map[i] = show_buf[i];
    }

	return bm;
}