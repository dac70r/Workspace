#include "circular_buffer.h" 

void API_WriteToBuffer(int data_element, int* pBuffer, int BufferSize){
    if(Is_BufferFull()){
        printf("\nBuffer is Full!");
    }
    else
        for (int k = 0; k<BufferSize; k++){
            if (data_element > pBuffer[k]){
                pBuffer[k] = data_element;
                printf("\nAPI_WriteToBuffer: %d",pBuffer[k]);
            }
            
        }
        
        
        //HEAD = (HEAD+1) % BUFFER_SIZE;
}

