#include "helpers.h"
#include <math.h>

void swap(RGBTRIPLE *a, RGBTRIPLE *b);

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // Loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Take average of red, green, and blue
            int red = image[i][j].rgbtRed;
            int green = image[i][j].rgbtGreen;
            int blue = image[i][j].rgbtBlue;
            int grey = (int) round((red + green + blue) / 3.0); // 此处应使用3.0浮点数运算，整数运算不对

            // Update pixel values 不能逗号连续赋值，只能分别. 并且不要给变量名赋值，这不会改变原图像
            image[i][j].rgbtRed = grey;
            image[i][j].rgbtGreen = grey;
            image[i][j].rgbtBlue = grey;

        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // Compute sepia values
            int originalRed = image[i][j].rgbtRed;
            int originalGreen = image[i][j].rgbtGreen;
            int originalBlue = image[i][j].rgbtBlue;

            // 保证像素不溢出: 和255取最小
            int sepiaRed = fmin((int) round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue), 255);
            int sepiaGreen = fmin((int) round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue), 255);
            int sepiaBlue = fmin((int) round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue), 255);

            // Update "pixel" with sepia values
            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0, half = width / 2 ; j < half; j++)
        {
            // Swap pixels: only the first half is enough
            int reflectval = width - j - 1;
            // 直接交换原始图像的位置
            swap(&image[i][j], &image[i][reflectval]);

        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Create a copy of image
    RGBTRIPLE copy[height][width]; // 声明一个二维数组的写法，核心是创建一个和原图像尺寸完全一致的像素副本数组
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copy[i][j] = image[i][j];

        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red_sum = 0, green_sum = 0, blue_sum = 0;
            double neighbor_count = 0;

            for (int k = -1; k <= 1; k++)
            {
                for (int l = -1; l <= 1; l++)
                {
                    // 边界检查
                    if (i+k < 0 || i+k >= height || j+l < 0 || j+l >= width) // 数组元素不是指针，不会为NULL
                    {
                        // 若越界，跳过
                        continue;
                    }

                    neighbor_count++;

                    int nbred = copy[i + k][j + l].rgbtRed;
                    int nbgreen = copy[i + k][j + l].rgbtGreen;
                    int nbblue = copy[i + k][j + l].rgbtBlue;

                    red_sum += nbred;
                    green_sum += nbgreen;
                    blue_sum += nbblue;

                }
            }

            // 注意要用浮点除法保持精度，因此将neighbor_count设置为double类型
            int red_blur = (int) round(red_sum / neighbor_count);
            int green_blur = (int) round(green_sum / neighbor_count);
            int blue_blur = (int) round(blue_sum / neighbor_count);

            image[i][j].rgbtRed = red_blur;
            image[i][j].rgbtGreen = green_blur;
            image[i][j].rgbtBlue = blue_blur;
        }
    }

    return;
}


void swap(RGBTRIPLE *a, RGBTRIPLE *b)
{
    // a, b是指针, 其指向的值是RGBTRIPLE类型
    RGBTRIPLE tmp = *a;
    *a = *b;
    *b = tmp;

}
