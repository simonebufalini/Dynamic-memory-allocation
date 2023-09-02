#include <stdio.h>
#include <stdlib.h>

#define INIT_SIZE 10
#define EXT 10

int main()
{
    int *array;
    size_t arraySize;
    arraySize = INIT_SIZE;

    array = malloc(arraySize * sizeof(*array));

    if (array == NULL){
        printf("Memory allocation error.");
        return 1;
    }

    int newElement;
    int index = 0;

    int *temp;

    while(1){

        printf("Enter a number (-1 to exit): \n");
        scanf("%d", &newElement);

        if (newElement == -1){
            break;
        }

        if (index == arraySize){
            arraySize += EXT;
            temp = realloc(array, arraySize * sizeof(*array));

            if (temp == NULL){
                printf("Memory allocation error.");
                free(array);
                return 1;
            }

            array = temp;
        }

        array[index] = newElement;
        index++;
    }

    printf("Numbers entered: ");

    for (int i = 0; i < index; i++){
        printf("%d\t", array[i]);
    }

    free(array);
    return 0;
}
