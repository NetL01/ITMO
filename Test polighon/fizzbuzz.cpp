void fizzbuzz(int a) {
    if ((a % 15) == 0 && a > 0) {
        printf("fizzbuzz");
    }
    else if ((a % 3) == 0 && a > 0) {
        printf("fizz");
    }
    else if ((a % 5) == 0 && a > 0) {
        printf("buzz");
    }
    else if (a <= 0){
        printf("no");
    }
}
