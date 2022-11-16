/* 1, 2 */
#include <stdio.h>
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

int factorial(int count){
    int vlfct=1;
    for (int i=1;i<=count;i++)
        vlfct=vlfct*i;
    return vlfct;
}

struct Point{
    int x, y;
};


int* point_distance(struct Point* points_array, int size) {
    int distance_size = factorial(size) / (factorial(2) * (factorial(size - 2)));
    int *distance_array = malloc(pow(distance_size, 2));
    int index = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            printf("(%d %d; %d %d)\n", points_array[i].x, points_array[i].y, points_array[j].x, points_array[j].y);
            distance_array[index++] = sqrt(pow(points_array[j].x - points_array[i].x, 2) +
                                           pow(points_array[j].y - points_array[i].y, 2));
        }
    }
}


int main(){
    int a, b;
    printf("Enter a and b: ");
    scanf("%d %d", &a, &b);
    printf("Least common multiple: %d.\nGreatest Common Divisor: %d", nok(a, b), nod(a, b));
    return 0;
}