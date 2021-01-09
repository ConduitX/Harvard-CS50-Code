#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    int v = 0.00;
    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            //Average three values
            v = (int)round((float)(image[i][j].rgbtBlue + image[i][j].rgbtRed + image[i][j].rgbtGreen) / 3);

            //Assign new value to all
            image[i][j].rgbtBlue = v;
            image[i][j].rgbtRed = v;
            image[i][j].rgbtGreen = v;
        }
    }
    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    int temp = 0;
    int oriRed = 0;
    int oriGreen = 0;
    int oriBlue = 0;
    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            oriRed = image[i][j].rgbtRed;
            oriGreen = image[i][j].rgbtGreen;
            oriBlue = image[i][j].rgbtBlue;

            //Calulate New Red
            temp = round(.393 * oriRed + .769 * oriGreen + .189 * oriBlue);
            if (temp > 255)
            {
                image[i][j].rgbtRed = 255;
            }
            else
            {
                image[i][j].rgbtRed = temp;
            }

            //Calulate New Green
            temp = round(.349 * oriRed + .686 * oriGreen + .168 * oriBlue);
            if (temp > 255)
            {
                image[i][j].rgbtGreen = 255;
            }
            else
            {
                image[i][j].rgbtGreen = temp;
            }

            //Calculate New Blue
            temp = round(.272 * oriRed + .534 * oriGreen + .131 * oriBlue);
            if (temp > 255)
            {
                image[i][j].rgbtBlue = 255;
            }
            else
            {
                image[i][j].rgbtBlue = temp;
            }
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    int temp = 0;
    
    int wid = width;

    if (wid % 2 == 1)
    {
        wid -= 1;
    }
    

    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = wid / 2; j < m; j++)
        {
            //Swap Red Values
            temp = image[i][j].rgbtRed;
            image[i][j].rgbtRed = image[i][width - j - 1].rgbtRed;
            image[i][width - j - 1].rgbtRed = temp;

            //Swap Green Values
            temp = image[i][j].rgbtGreen;
            image[i][j].rgbtGreen = image[i][width - j - 1].rgbtGreen;
            image[i][width - j - 1].rgbtGreen = temp;

            //Swap Blue Values
            temp = image[i][j].rgbtBlue;
            image[i][j].rgbtBlue = image[i][width - j - 1].rgbtBlue;
            image[i][width - j - 1].rgbtBlue = temp;

        }
    }
    

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    int newRed = 0;
    int newGreen = 0;
    int newBlue = 0;
    int avec = 0;
    
    RGBTRIPLE copyImage[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            copyImage[i][j] = image[i][j];
        }
    }
    
    
    for (int i = 0, n = height; i < n; i++)
    {
        for (int j = 0, m = width; j < m; j++)
        {
            newRed = 0;
            newGreen = 0;
            newBlue = 0;
            avec = 0;
            //Add surrounding boxes to the current point
            for (int ii = -1; ii < 2; ii++)
            {
                for (int jj = -1; jj < 2; jj++)
                {
                    if (i + ii != -1 && i + ii != height && j + jj != -1 && j + jj != width)  
                        //Dont add if the surrounding box is out of bounds. Otherwise, add
                    {
                        newRed += copyImage[i + ii][j + jj].rgbtRed;
                        newGreen += copyImage[i + ii][j + jj].rgbtGreen;
                        newBlue += copyImage[i + ii][j + jj].rgbtBlue;
                        
                        avec++;
                    }
                }
            }
            
            //Average and replace with new value
            image[i][j].rgbtRed = (int)round((float)newRed / avec);
            image[i][j].rgbtGreen = (int)round((float)newGreen / avec);
            image[i][j].rgbtBlue = (int)round((float)newBlue / avec);
            
        }
    }
    return;
}
