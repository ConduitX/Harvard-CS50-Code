#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


typedef uint8_t BYTE; //Define a Byte

int main(int argc, char *argv[])
{
    if (argc != 2)  //Check for 2 arguments
    {
        printf("There's no argument\n");
        return 1;
    } 
    
    char *card = argv[1];

    FILE *file = fopen(card, "r");  //Open card

    if (file == NULL)  //Return if file is empty
    {
        printf("Can't open file\n");
        return 1;
    }
    
    int end = 0;
    
    //Move file pointer to end of card
    fseek(file, 0, SEEK_END);
    
    //Save pointer value to end
    end = ftell(file);
    
    //Reset file pointer to beginning of file
    fseek(file, 0, SEEK_SET);

    int pics = 0;  //Picture counter
    BYTE buffer[512] = {0};  //Initialize buffer
    char into[10];  //Space for setting jpg names

    FILE *newPic = fopen("junk.txt", "a");  //Initialize newPic with a junk file
    
    while (ftell(file) != end)  //While the file isnt at the end
    {
        fread(buffer, 512, 1, file);  //Put 512 bytes into buffer (make a block)
        
        //Check if block is the start of a jpg
        if ((buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0))
        {
            if (pics == 0)
            {
                sprintf(into, "%03i.jpg", pics);  //Make first jpg file
                newPic = fopen(into, "a");
                pics++;
            }
            else
            {
                fclose(newPic);  //Close last jpg file
                sprintf(into, "%03i.jpg", pics);  //Make new jpg file
                newPic = fopen(into, "a");
                pics++;
            }
        }
        
        fwrite(buffer, 512, 1, newPic); //Write block to the open file

    }
    
    fclose(newPic);  //Close last jpg file
    fclose(file);  //Close card file
    return 0;  //End program

}
