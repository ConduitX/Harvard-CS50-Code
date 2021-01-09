
int x = 0;
            x = images[i][j].rgbtRed;

            if (i == 0)
            {
                if (j == 0)  //Top Left Corner
                {
                    x += images[i+1][j+1].rgbtRed + images[i][j+1].rgbtRed + images[i+1][j].rgbtRed;

                    images[i][j].rgbtRed = x / 4;
                }
                else if (j == width - 1)  //Top Right Corner
                {
                    x += images[i+1][j-1].rgbtRed + images[i][j-1].rgbtRed + images[i+1][j].rgbtRed;

                    images[i][j].rgbtRed = x / 4;
                }
                else  //Top Row ->
                {
                    x += images[i][j-1].rgbtRed + images[i][j+1].rgbtRed + images[i+1][j+1].rgbtRed;
                    x += images[i+1][j].rgbtRed + images[i+1][j-1].rgbtRed;

                    images[i][j].rgbtRed = x / 6;
                }

            }
            else if (i == height - 1)
            {
                if (j == 0)  //Bottom Left Corner
                {

                }
                else if (j == width - 1)  //Bottom Right Corner
                {

                }
                else  //Bottom Row
                {

                }
            }
