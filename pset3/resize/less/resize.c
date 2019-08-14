// Resizes a BMP file by n

#include <stdio.h>
#include <stdlib.h>

#include "bmp.h"

int main(int argc, char *argv[])
{
    // ensure proper usage
    if (argc != 4)
    {
        fprintf(stderr, "Usage: ./resize n infile outfile\n");
        return 1;
    }


    // remember size multiplier
    int n = atoi(argv[1]);

    // remember filenames
    char *infile = argv[2];
    char *outfile = argv[3];


    if (n < 1 || n > 100)
    {
        fprintf(stderr, "n must be a positive integer less than or equal to 100\n");
        return 2;
    }

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 3;
    }

    // open output file
    FILE *outptr = fopen(outfile, "w");
    if (outptr == NULL)
    {
        fclose(inptr);
        fprintf(stderr, "Could not create %s.\n", outfile);
        return 4;
    }

    // read infile's BITMAPFILEHEADER
    BITMAPFILEHEADER bf;
    fread(&bf, sizeof(BITMAPFILEHEADER), 1, inptr);

    // read infile's BITMAPINFOHEADER
    BITMAPINFOHEADER bi;
    fread(&bi, sizeof(BITMAPINFOHEADER), 1, inptr);

    // ensure infile is (likely) a 24-bit uncompressed BMP 4.0
    if (bf.bfType != 0x4d42 || bf.bfOffBits != 54 || bi.biSize != 40 ||
        bi.biBitCount != 24 || bi.biCompression != 0)
    {
        fclose(outptr);
        fclose(inptr);
        fprintf(stderr, "Unsupported file format.\n");
        return 5;
    }

    // new dimensions
    int biWidthOld = bi.biWidth;
    int biHeightOld = bi.biHeight;
    int biWidthNew = biWidthOld * n;
    int biHeightNew = biHeightOld * n;

    // determine padding for scanlines
    int inPadding = (4 - (biWidthOld * sizeof(RGBTRIPLE)) % 4) % 4;
    int outPadding = (4 - (biWidthNew * sizeof(RGBTRIPLE)) % 4) % 4;    

    // reconfigure headers
    bi.biWidth = biWidthNew;
    bi.biHeight = biHeightNew;
    
    bi.biSizeImage = ((sizeof(RGBTRIPLE) * biWidthNew) + outPadding) * abs(biHeightNew);
    bf.bfSize = bi.biSizeImage + sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

    // write outfile's BITMAPFILEHEADER
    fwrite(&bf, sizeof(BITMAPFILEHEADER), 1, outptr);

    // write outfile's BITMAPINFOHEADER
    fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, outptr);

    // allocate memory to store more than one scanline
    RGBTRIPLE scanline[biWidthNew * sizeof(RGBTRIPLE)];

    // iterate over infile's scanlines
    for (int i = 0, biHeight = abs(biHeightOld); i < biHeight; i++)
    {
        // iterate over pixels in a scanline
        for (int j = 0; j < biWidthOld; j++)
        {
            // temporary storage
            RGBTRIPLE triple;

            // read RGB triple from infile
            fread(&triple, sizeof(RGBTRIPLE), 1, inptr);

            // create a new scanline in a temporary array
            for (int k = 0; k < n; k++)
            {
                scanline[(j * n) + k] = triple;
            }
        }

        // skip over padding, if any
        fseek(inptr, inPadding, SEEK_CUR);

        // write the current scanline n times
        for (int j = 0; j < n; j++)
        {
            // write a new scanline once
            fwrite(scanline, sizeof(RGBTRIPLE), biWidthNew, outptr);

            // write new padding
            for (int k = 0; k < outPadding; k++)
            {
                fputc(0x00, outptr);
            }
        }
    }

    // close infile
    fclose(inptr);

    // close outfile
    fclose(outptr);

    // success
    return 0;
}
