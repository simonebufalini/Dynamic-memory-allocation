#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define EXT 10

int main()
{
    int *array;
    size_t arraySize;
    arraySize = INIT_SIZE;

    array = (int*)malloc(arraySize * sizeof(int));

    int newElement;
    int index = 0;

    while(1){

        printf("Enter a number (-1 to exit): \n");
        scanf("%d", &newElement);

        if (newElement == -1){
            break;
        }

        if (index == arraySize){
            arraySize += EXT;
            array = (int*)realloc(array, arraySize * sizeof(int));

            if (array == NULL){
                printf("Memory allocation error.")
                free(array);
                return 1;
            }
        }

        array[index] = newElement;
        index++;
    }

    for (int i = 0; i < index; i++){
        printf("%d\n", array[i]);
    }

    free(array);
    return 0;
}
