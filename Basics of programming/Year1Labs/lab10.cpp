/* 1, 2 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int nod(int a, int b){
    while (a != b){
        if (a > b){
            a -= b;
        } else {
            b -= a;
        }
    }
    return a;
}

int nok(int a, int b){
    return abs(a * b)/nod(a, b);
}

struct Point{
    int x, y;
};

int factorial(int count){
    int result = 1;
    for (int i = 1; i <= count; i++)
        result = result * i;
    return result;
}

int* point_distance(struct Point* points_array, int size) {
    int distance_size = factorial(size)/(factorial(2)*(factorial(size - 2)));
    int* distance_array = (int*)malloc(pow(distance_size, 2));
    int index = 0;

    for (int i = 0; i < size - 1; i++){
        for (int j = i+1; j < size; j++){
            printf("(%d %d; %d %d)\n", points_array[i].x, points_array[i].y, points_array[j].x, points_array[j].y);
            distance_array[index++] = sqrt(pow(points_array[j].x - points_array[i].x, 2) +
                                           pow(points_array[j].y - points_array[i].y, 2));

        }
    }
    printf("\n");
    return distance_array;
}

int main(){
    int array_size = 4;
    struct Point array[4] = {{1, 5}, {6, 8}, {2, 1}, {3, 4}};
    int size = factorial(array_size)/(factorial(2)*(factorial(array_size - 2)));
    int* new_array = point_distance(array, array_size);

    for (int k = 0; k < size; k++){
        printf("%d ", new_array[k]);
    }

    printf("\n");
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    printf("Least common multiple: %d.\nGreatest Common Divisor: %d", nok(a, b), nod(a, b));
    return 0;
}