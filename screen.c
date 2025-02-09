#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <linux/input.h>
#include <sys/mman.h>

#define UINT  unsigned short
#define DWORD unsigned  int
#define LONG unsigned  int
#define WORD unsigned short

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

int main(int argc, char const *argv[])
{
    // bmp图片部分的处理
    int bmp_fd = open("add-2.bmp", O_RDONLY);
    if (bmp_fd == -1)
    {
        perror("open bmp");
        return -1;
    }
    
    struct tagBITMAPFILEHEADER buf1;
    read(bmp_fd, &buf1, sizeof(buf1)); // 读取bmp文件的格式信息
    printf("文件的大小:%u\n", buf1.bfSize);

    struct tagBITMAPINFOHEADER buf2;
    read(bmp_fd, &buf2, sizeof(buf2)); // 读取bmp文件的内容信息
    printf("图片的长：%d,宽：%d\n", buf2.biWidth, buf2.biHeight);
    // 显示任意大小的图片： 需要注意我们的长必须是4的倍数
    
    char buf[buf2.biWidth*buf2.biHeight*3];
    bzero(buf, sizeof(buf));
    read(bmp_fd, buf, sizeof(buf)); // 读取颜色数据
    
    close(bmp_fd);

    // 处理屏幕文件
    int lcd_fd = open("/dev/fb0", O_RDWR);
    if (lcd_fd == -1)
    {
        perror("open lcd");
        return -2;
    }
    
    // 申请映射空间
    int *mmap_start = mmap(NULL, 800*480*4, PROT_READ|PROT_WRITE, MAP_SHARED, lcd_fd, 0);
    if (mmap_start == MAP_FAILED)
    {
        perror("mmap error");
        return -3;
    }

    int *new_start = mmap_start+59*800; // 起点是(100,100)

    int n=0;
    for(int y=0;y<buf2.biHeight;y++)
    {
        for(int x=0;x<buf2.biWidth;x++,n+=3)
        {
            new_start[800*(buf2.biHeight-1-y)+x] = buf[n+0]<<0|buf[n+1]<<8|buf[n+2]<<16;
        }
    }

    // 撤销映射空间
    munmap(mmap_start, 800*480*4);

    // 关闭lcd文件
    close(lcd_fd);
    return 0;
}
