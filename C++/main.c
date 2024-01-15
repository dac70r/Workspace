#include <stdio.h>
#include <stdbool.h>
#include "circular_buffer.h"

bool Is_BufferFull(void){
    return false;
}

void API_WriteToBuffer(int data_element, int* pBuffer, int BufferSize){
    if(Is_BufferFull()){
        printf("\nBuffer is Full!");
    }
    else
        for (int k = 0; k<BufferSize; k++){
            if (data_element > pBuffer[k]){
                pBuffer[k] = data_element;
                printf("\nAPI_WriteToBuffer: %d",pBuffer[k]);
                break;
            }
            
        }
        
        
        //HEAD = (HEAD+1) % BUFFER_SIZE;
}



int main(){
    int pBuffer[10] = {0};
    printf("Hello World\n");
    printf("Size of pBuffer is: %d\n",sizeof(pBuffer));
    API_WriteToBuffer(1,pBuffer,10);

    for (int k = 0; k<10; k++){
        printf("\nAPI_WriteToBuffer: %d",pBuffer[k]);
    }
            
    return 0;
}