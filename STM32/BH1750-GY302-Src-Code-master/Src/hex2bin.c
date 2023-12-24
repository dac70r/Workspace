#include "hex2bin.h" 

// function to convert Hexadecimal to Binary Number
void HexToBin(char* hexdec, char* buffer)
{
 
    uint8_t i = 0;
 
    while (hexdec[i]) {
 
        switch (hexdec[i]) {
        case '0':
            strcat(buffer,"0000");
            break;
        case '1':
            strcat(buffer,"0001");
            break;
        case '2':
            strcat(buffer,"0010");
            break;
        case '3':
            strcat(buffer,"0011");
            break;
        case '4':
            strcat(buffer,"0100");
            break;
        case '5':
            strcat(buffer,"0101");
            break;
        case '6':
            strcat(buffer,"0110");
            break;
        case '7':
            strcat(buffer,"0111");
            break;
        case '8':
            strcat(buffer,"1000");
            break;
        case '9':
            strcat(buffer,"1001");
            break;
        case 'A':
        case 'a':
            strcat(buffer,"1010");
            break;
        case 'B':
        case 'b':
            strcat(buffer,"1011");
            break;
        case 'C':
        case 'c':
            strcat(buffer,"1100");
            break;
        case 'D':
        case 'd':
            strcat(buffer,"1101");
            break;
        case 'E':
        case 'e':
            strcat(buffer,"1110");
            break;
        case 'F':
        case 'f':
            strcat(buffer,"1111");
            break;
        default:
            strcpy(buffer,"Error detected!");
        }
        i++;
    }
}