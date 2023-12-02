#include <stdio.h>

int main() {
 
    float width = 0.0f;
    float height = 0.0f;
    
    printf("Type the width: ");
    scanf("%f", &width);
    printf("Type the height: ");
    scanf("%f", &height);

    double perimeter = (width + height) * 2.0;
    double area = width * height;
    
    printf("-------------------------");

    printf("Perimeter: %g\n", perimeter);
    printf("Area: %g\n", area);

    return 0;

}
