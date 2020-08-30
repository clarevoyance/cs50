#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        fprintf(stderr, "Usage: ./recover image\n");
        return 1;
    }

    // remember filenames
    char *raw_file = argv[1];
    FILE *file_ptr = fopen(raw_file, "r");

    // if raw file could not be opened
    if (file_ptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", raw_file);
        return 2;
    }

    // memory allocation
    unsigned char *buffer = malloc(512);
    int jpg_number = 0;
    FILE *img;

    // read raw file
    while (fread(buffer, 512, 1, file_ptr))
    {
        // new jpg found
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
 
            // close previous jpg
            if (jpg_number > 0)
            {
                fclose(img);
            }

            // create filename
            char filename[7];
            sprintf(filename, "%03i.jpg", jpg_number);

            // open new image file
            img = fopen(filename, "w");             

            // check if jpg is created
            if (img == NULL)
            {
                fclose(file_ptr);
                free(buffer);
                fprintf(stderr, "Could not create output JPG %s", filename);
                return 3;
            }

            // check for every jpg file
            jpg_number++;
        }

        // if first jpg not found, then skip
        if (!jpg_number)
        {
            continue;
        }

        // write jpg info to current file
        fwrite(buffer, 512, 1, img);
    }

    // close image 
    fclose(file_ptr);
    fclose(img);

    // free memory
    free(buffer);

    return 0;
}
