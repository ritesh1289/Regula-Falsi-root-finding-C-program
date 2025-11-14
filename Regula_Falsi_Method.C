#include <stdio.h>
#include <math.h>

float f(float x) {
    return x*x*x - x - 2;  // Example: f(x) = x³ - x - 2
}

int main() {
    float x0, x1, x2, f0, f1, f2;
    int max_iter = 100, iter = 0;
    float tolerance = 0.0001;

    // Initial guesses
    x0 = 1.0;
    x1 = 2.0;

    f0 = f(x0);
    f1 = f(x1);

    if (f0 * f1 > 0) {
        printf("Invalid initial guesses. f(x0) and f(x1) must have opposite signs.\n");
        return -1;
    }
printf("Iter\t x0\t x1\t x2\t f(x2)\n");
    do {
        x2 = x1 - (f1 * (x1 - x0)) / (f1 - f0);
        f2 = f(x2);

        printf("%d\t %.4f\t %.4f\t %.4f\t %.4f\n", iter+1, x0, x1, x2, f2);

        if (fabs(f2) < tolerance)
            break;
       
 if (f0 * f2 < 0) {
            x1 = x2;
            f1 = f2;
        } else {
            x0 = x2;
            f0 = f2;
        }

        iter++;
    } while (iter < max_iter);

    printf("\nApproximate root: %.4f\n", x2);
    return 0;
} 

