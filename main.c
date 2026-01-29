
#define _USE_MATH_DEFINES
#define MAX_ROWS 10
#define MAX_COLS 10
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>

// Structure to represent complex numbers
typedef struct {
    double real;
    double imag;
} Complex;

// Function prototypes
void matrixAddition();
void matrixMultiplication();
void inchToCm();
void cmToInch();
void cmToMeter();
void meterToCm();
void kmphToMps();
void mpsToKmph();
void footToMeter();
void meterToFoot();
void mileToKm();
void kmToMile();
void mileToMeter();
void meterToMile();
void fahrenheitToCelsius();
void celsiusToFahrenheit();
void jouleToCalories();
void caloriesToJoule();
void performSimpleoperation(int choice);
void performAdvancedOperation(int choice);
void performUnitconversion(int choice);
void showUnitConstant(int choice);
void mainmenu();
void simpleCalculatorMenu();
void advancedFunctionMenu();
void unitConversionMenu();
void performOperation(int choice);
Complex addComplex(Complex a, Complex b);
Complex multiplyComplex(Complex a, Complex b);
void printComplex(Complex c);
int factorial(int num);
void matrixoperation(int choice);
// Function to perform matrix addition
void matrixAddition() {
    int rows, cols;

    printf("Enter number of rows and columns for matrix: ");
    scanf("%d %d", &rows, &cols);

    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    } 

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Adding corresponding elements of two arrays
    for (int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            result[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    // Displaying the sum
    printf("\nSum of matrices:\n");
    for(int i = 0; i < rows; ++i){
        for (int j = 0; j < cols; ++j) {
            printf("%d\t", result[i][j]); 
        }
        printf("\n");
    }
}

// Function to perform matrix multiplication
void matrixMultiplication() {
    int rows1, cols1, rows2, cols2;

    printf("Enter number of rows and columns for first matrix: ");
    scanf("%d %d", &rows1, &cols1);

    printf("Enter number of rows and columns for second matrix: ");
    scanf("%d %d", &rows2, &cols2);

    if (cols1 != rows2) {
        printf("Invalid matrices for multiplication.\n");
        return;
    }

    int matrix1[MAX_ROWS][MAX_COLS], matrix2[MAX_ROWS][MAX_COLS], result[MAX_ROWS][MAX_COLS];

    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < rows1; ++i){
        for (int j = 0; j < cols1; ++j) {
            printf("Enter element a%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix1[i][j]);
        }
    }

    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < rows2; ++i){
        for (int j = 0; j < cols2; ++j) {
            printf("Enter element b%d%d: ", i + 1, j + 1);
            scanf("%d", &matrix2[i][j]);
        }
    }

    // Initializing elements of matrix result to 0
    for (int i = 0; i < rows1; ++i){
        for (int j = 0; j < cols2; ++j) {
            result[i][j] = 0;
        }
    }
    // Multiplying matrices
    for (int i = 0; i < rows1; ++i){
        for (int j = 0; j < cols2; ++j) {
            for (int k = 0; k < cols1; ++k) {
                result[i][j] += matrix1[i][k] * matrix2[k][j];
            }
        }
    }

    // Displaying the result
    printf("\nResult of matrix multiplication:\n");
    for(int i = 0; i < rows1; ++i){
        for (int j = 0; j < cols2; ++j) {
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
}

// Function to convert inches to centimeters
void inchToCm() {
    double inches;
    printf("Enter length in inches: ");
    scanf("%lf", &inches);
    double cm = inches * 2.54;
    printf("%.2lf inches is equal to %.2lf centimeters.\n", inches, cm);
}

// Function to convert centimeters to inches
void cmToInch() {
    double cm;
    printf("Enter length in centimeters: ");
    scanf("%lf", &cm);
    double inches = cm / 2.54;
    printf("%.2lf centimeters is equal to %.2lf inches.\n", cm, inches);
}

// Function to convert centimeters to meters
void cmToMeter() {
    double cm;
    printf("Enter length in centimeters: ");
    scanf("%lf", &cm);
    double meters = cm / 100;
    printf("%.2lf centimeters is equal to %.2lf meters.\n", cm, meters);
}

// Function to convert meters to centimeters
void meterToCm() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    double cm = meters * 100;
    printf("%.2lf meters is equal to %.2lf centimeters.\n", meters, cm);
}

// Function to convert kilometers per hour to meters per second
void kmphToMps() {
    double kmph;
    printf("Enter speed in kilometers per hour: ");
    scanf("%lf", &kmph);
    double mps = kmph * 1000 / 3600;
    printf("%.2lf kilometers per hour is equal to %.2lf meters per second.\n", kmph, mps);
}

// Function to convert meters per second to kilometers per hour
void mpsToKmph() {
    double mps;
    printf("Enter speed in meters per second: ");
    scanf("%lf", &mps);
    double kmph = mps * 3600 / 1000;
    printf("%.2lf meters per second is equal to %.2lf kilometers per hour.\n", mps, kmph);
}

// Function to convert feet to meters
void footToMeter() {
    double feet;
    printf("Enter length in feet: ");
    scanf("%lf", &feet);
    double meters = feet * 0.3048;
    printf("%.2lf feet is equal to %.2lf meters.\n", feet, meters);
}

// Function to convert meters to feet
void meterToFoot() {
    double meters;
    printf("Enter length in meters: ");
    scanf("%lf", &meters);
    double feet = meters / 0.3048;
    printf("%.2lf meters is equal to %.2lf feet.\n", meters, feet);
}

// Function to convert miles to kilometers
void mileToKm() {
    double miles;
    printf("Enter distance in miles: ");
    scanf("%lf", &miles);
    double km = miles * 1.60934;
    printf("%.2lf miles is equal to %.2lf kilometers.\n", miles, km);
}

// Function to convert kilometers to miles
void kmToMile() {
    double km;
    printf("Enter distance in kilometers: ");
    scanf("%lf", &km);
    double miles = km / 1.60934;
    printf("%.2lf kilometers is equal to %.2lf miles.\n", km, miles);
}

// Function to convert miles to meters
void mileToMeter() {
    double miles;
    printf("Enter distance in miles: ");
    scanf("%lf", &miles);
    double meters = miles * 1609.34;
    printf("%.2lf miles is equal to %.2lf meters.\n", miles, meters);
}

// Function to convert meters to miles
void meterToMile() {
    double meters;
    printf("Enter distance in meters: ");
    scanf("%lf", &meters);
    double miles = meters / 1609.34;
    printf("%.2lf meters is equal to %.2lf miles.\n", meters, miles);
}

// Function to convert Fahrenheit to Celsius
void fahrenheitToCelsius() {
    double fahrenheit;
    printf("Enter temperature in Fahrenheit: ");
    scanf("%lf", &fahrenheit);
    double celsius = (fahrenheit - 32) * 5 / 9;
    printf("%.2lf Fahrenheit is equal to %.2lf Celsius.\n", fahrenheit, celsius);
}

// Function to convert Celsius to Fahrenheit
void celsiusToFahrenheit() {
    double celsius;
    printf("Enter temperature in Celsius: ");
    scanf("%lf", &celsius);
    double fahrenheit = (celsius * 9 / 5) + 32;
    printf("%.2lf Celsius is equal to %.2lf Fahrenheit.\n", celsius, fahrenheit);
}

// Function to convert joules to calories
void jouleToCalories() {
    double joules;
    printf("Enter energy in joules: ");
    scanf("%lf", &joules);
    double calories = joules / 4.184;
    printf("%.2lf joules is equal to %.2lf calories.\n", joules, calories);
}

// Function to convert calories to joules
void caloriesToJoule() {
    double calories;
    printf("Enter energy in calories: ");
    scanf("%lf", &calories);
    double joules = calories * 4.184;
    printf("%.2lf calories is equal to %.2lf joules.\n", calories, joules);
}

// Function to perform simple mathematical operations
void performSimpleoperation(int choice) {
    double num1, num2, result;
        switch (choice) {
            case 0:
                printf("Returning to main menu");
                break;
            case 1:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 + num2;
                printf("Sum of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
                break;
            case 2:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 - num2;
                printf("Difference of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
                break;
            case 3:
                printf("Enter first number: ");
                scanf("%lf", &num1);
                printf("Enter second number: ");
                scanf("%lf", &num2);
                result = num1 * num2;
                printf("Product of %.2lf and %.2lf is %.2lf.\n", num1, num2, result);
                break;
            case 4:
                printf("Enter dividend: ");
                scanf("%lf", &num1);
                printf("Enter divisor: ");
                scanf("%lf", &num2);
                if (num2 != 0) {
                    result = num1 / num2;
                    printf("Division result: %.2lf.\n", result);
                } else {
                    printf("Cannot divide by zero.\n");
                }
                break;
            default:
                printf("Invalid choice.\n");
        }
}
// Function to calculate factorial of a number
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
//Function to perform matrix operation
void matrixoperation(int choice){

            switch(choice){
        case 1:
            matrixAddition();
            break;
        case 2:
            matrixMultiplication();
            break;
        case 0:
            printf("Returning to main menu\n");
            break;
        default:
            printf("Invalid Input,please try again\n");
        }


}
// Function to perform trigonometric operations
void performTrigonometricOperation(int choice) {
    double angle, result;
            switch (choice) {
        case 1:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = sin(angle *M_PI/180);
            printf("Sine of %.2lf degrees is %.2lf.\n", angle, result);
            break;
        case 2:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = cos(angle *M_PI/180);
            printf("Cosine of %.2lf degrees is %.2lf.\n", angle, result);
            break;
        case 3:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = tan(angle *M_PI/180);
            printf("Tangent of %.2lf degrees is %.2lf.\n", angle, result);
            break;
        case 4:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            if (angle > -1 && angle < 1) {
                result = asin(angle) * 180 / M_PI;
                printf("Arcsine of %.2lf is %.2lf degrees.\n", angle, result);
            } else {
                printf("Input value out of range for arcsine function.\n");
            }
            break;
        case 5:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            if (angle > -1 && angle < 1) {
                result = acos(angle) * 180 / M_PI;
                printf("Arccosine of %.2lf is %.2lf degrees.\n", angle, result);
            } else {
                printf("Input value out of range for arccosine function.\n");
            }
            break;
        case 6:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = atan(angle) * 180 / M_PI;
            printf("Arctangent of %.2lf is %.2lf degrees.\n", angle, result);
            break;
        case 7:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = sinh(angle *M_PI / 180);
            printf("Hyperbolic sine of %.2lf degrees is %.2lf.\n", angle, result);
            break;
        case 8:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            result = cosh(angle *M_PI / 180);
            printf("Hyperbolic cosine of %.2lf degrees is %.2lf.\n", angle, result);
            break;
        case 9:
            printf("Enter angle in degrees: ");
            scanf("%lf", &angle);
            if (angle != 0) {
                result = tanh(angle *M_PI / 180);
                printf("Hyperbolic tangent of %.2lf degrees is %.2lf.\n", angle, result);
            } else {
                printf("Tanh is undefined for %.2lf degrees.\n", angle);
            }
            break;
        case 0:
            printf("Returning to main menu:\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    
}

// Function to calculate power of a number
double power(double base, double exponent) {
    if (exponent != 0) {
        return base * power(base, exponent - 1);
    } else {
        return 1;
    }
}

// Function to calculate square of a number
double square(double x) {
    return x * x;
}

// Function to perform exponential operation
double exponent(double x) {
    return exp(x);
}

// Function to calculate square root of a number
double squareRoot(double x) {
    if (x >= 0) {
        return sqrt(x);
    } else {
        printf("Square root of negative number is undefined.\n");
        return 0;
    }
}

// Function to perform logarithmic operations
void performLogarithmicOperation(int choice) {

    double x, result;
            switch (choice) {
        case 1:
            printf("Enter positive number: ");
            scanf("%lf", &x);
            if (x > 0) {
                result = log(x);
                printf("Natural logarithm of %.2lf is %.2lf.\n", x, result);
            } else {
                printf("Input value should be positive.\n");
            }
            break;
        case 2:
            printf("Enter positive number: ");
            scanf("%lf", &x);
            if (x > 0) {
                result = log10(x);
                printf("Common logarithm of %.2lf is %.2lf.\n", x, result);
            } else {
                printf("Input value should be positive.\n");
            }
            break;
        case 3:
            printf("Enter number: ");
            scanf("%lf", &x);
            if (x > 0) {
                result = log(x) / log(2);
                printf("Logarithm base 2 of %.2lf is %.2lf.\n", x, result);
            } else {
                printf("Input value should be positive.\n");
            }
            break;
        case 0:
            printf("Returning to main menu\n");
            break;
        default:
            printf("Invalid choice.\n");
    }

}

// Function to calculate cube of a number
double cube(double x) {
    return x * x * x;
}

// Function to calculate factorial of a number iteratively
int factorialIterative(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

// Function to calculate permutation
int permutation(int n, int r) {
    return factorial(n) / factorial(n - r);
}

// Function to calculate combination
int combination(int n, int r) {
    return factorial(n) / (factorial(r) * factorial(n - r));
}

// Function to calculate percentage
double percentage(double num, double total) {
    return (num / total) * 100;
}

// Function to calculate average of numbers
double average(double numbers[], int count) {
    double sum = 0;
    for (int i = 0; i < count; ++i) {
        sum += numbers[i];
    }
    return sum / count;
}

// Function to calculate mean deviation
double meanDeviation(double numbers[], int count) {
    double mean = average(numbers, count);
    double deviation = 0;
    for (int i = 0; i < count; ++i) {
        deviation += fabs(numbers[i] - mean);
    }
    return deviation / count;
}

// Function to calculate variance
double variance(double numbers[], int count) {
    double mean = average(numbers, count);
    double var = 0;
    for (int i = 0; i < count; ++i) {
        var += pow(numbers[i] - mean, 2);
    }
    return var / count;
}

// Function to calculate standard deviation
double standardDeviation(double numbers[], int count) {
    return sqrt(variance(numbers, count));
}

// Function to perform advanced mathematical operations
void performAdvancedOperation(int choice) {
    int n, r;
    double x,y,numbers[100], result;
    switch (choice) {
        case 1:
            printf("Enter number: ");
            scanf("%lf", &x);
            result=cube(x);
            printf("Cube of %.2lf is %.2lf.\n", x,result);
            break;
        case 2:
            printf("Enter positive number: ");
            scanf("%lf", &x);
            result=pow(x, 1.0 / 3);
            printf("Cube root of %.2lf is %.2lf.\n",x,result);
            break;
        case 3:
            printf("Enter number: ");
            scanf("%lf", &x);
            result= exponent(x);
            printf("Exponential of %.2lf is %.2lf.\n", x,result);
            break;
        case 4:
            printf("Enter number: ");
            scanf("%lf", &x);
            result= squareRoot(x);
            printf("Square root of %.2lf is %.2lf.\n", x,result);
            break;
        case 5:
            printf("Enter base: ");
            scanf("%lf", &x);
                printf("Enter exponent: ");
                scanf("%lf", &y);
                result= pow(x,y);
                printf("%.2lf raised to the power %.2lf is %.2lf.\n", x,y,result);
                break;
            case 6:
                printf("Enter number: ");
                scanf("%lf", &x);
                result= factorialIterative((int)x);
                printf("Factorial of %.2lf is %.2lf.\n", x,result);
                break;
            case 7:
                printf("Enter number: ");
                scanf("%lf", &x);
                result= percentage(x, 100);
                printf("Percentage of %.2lf is %.2lf%%.\n", x,result);
                break;
            case 8:
                printf("Enter total number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%lf", &numbers[i]);
                }
                result= average(numbers, n);
                printf("Average: %.2lf\n",result);
                break;
            case 9:
                printf("Enter total number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%lf", &numbers[i]);
                }
                result= meanDeviation(numbers, n);
                printf("Mean deviation: %lf\n",result);
                break;
            case 10:
                printf("Enter total number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%lf", &numbers[i]);
                }
                result= variance(numbers, n);
                printf("Variance: %.2lf\n",result);
                break;
            case 11:
                printf("Enter total number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%lf", &numbers[i]);
                }
                result= standardDeviation(numbers, n);
                printf("Standard deviation: %.2lf\n",result);
                break;
            case 12:
                printf("Enter total number of elements: ");
                scanf("%d", &n);
                printf("Enter %d elements: ", n);
                for (int i = 0; i < n; ++i) {
                    scanf("%lf", &numbers[i]);
                }
                result=  average(numbers, n);
                printf("Sum of %d elements is %lf.\n", n,result);
                break;
            case 13:
                printf("Enter value of n: ");
                scanf("%d", &n);
                printf("Enter value of r: ");
                scanf("%d", &r);
                result= permutation(n, r);
                printf("Permutation of %d and %d is %.2lf.\n", n, r , result);
                break;
            case 14:
                printf("Enter value of n: ");
                scanf("%d", &n);
                printf("Enter value of r: ");
                scanf("%d", &r);
                result=combination(n, r);
                printf("Combination of %d and %d is %.2lf.\n", n, r, result);
                break;
            case 0:
                printf("Returning to main menu\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
}

// Function to perform unit conversion
void performUnitconversion(int choice) {
    switch (choice) {
        case 1:
            inchToCm();
            break;
        case 2:
            cmToInch();
            break;
        case 3:
            cmToMeter();
            break;
        case 4:
            meterToCm();
            break;
        case 5:
            kmphToMps();
            break;
        case 6:
            mpsToKmph();
            break;
        case 7:
            footToMeter();
            break;
        case 8:
            meterToFoot();
            break;
        case 9:
            mileToKm();
            break;
        case 10:
            kmToMile();
            break;
        case 11:
            mileToMeter();
            break;
        case 12:
            meterToMile();
            break;
        case 13:
            fahrenheitToCelsius();
            break;
        case 14:
            celsiusToFahrenheit();
            break;
        case 15:
            jouleToCalories();
            break;
        case 16:
            caloriesToJoule();
            break;
        case 0:
            printf("Returning to main menu\n");
            break;
        default:
            printf("Invalid choice.\n");
    }
    
    
}

int main() {
    int choice;
    do {
       
        printf("\n");
        printf("1. Perform basic mathematical operation\n");
        printf("2. Perform trigonometric operation\n");
        printf("3. Perform logarithmic operation\n");
        printf("4. Perform advanced mathematical operation\n");
        printf("5. Perform unit conversion\n");
        printf("6. Matrix operations\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\n");
                printf("1. Addition\n");
                printf("2. Subtraction\n");
                printf("3. Multiplication\n");
                printf("4. Division\n");
                printf("0. Exit\n");
                do{
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    performSimpleoperation(choice);
                } while (choice!=0);
                break;
            case 2:
                printf("\n");
                printf("1. Sine\n");
                printf("2. Cosine\n");
                printf("3. Tangent\n");
                printf("4. Arcsine\n");
                printf("5. Arccosine\n");
                printf("6. Arctangent\n");
                printf("7. Hyperbolic Sine\n");
                printf("8. Hyperbolic Cosine\n");
                printf("9. Hyperbolic Tangent\n");
                printf("0. Exit\n");
                do{
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    performTrigonometricOperation(choice);
                } while (choice!=0);
                break;
            case 3:
                printf("\n");
                printf("1. Natural Logarithm\n");
                printf("2. Common Logarithm\n");
                printf("3. Logarithm base 2\n");
                printf("0. Exit\n");
                do
                {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    performLogarithmicOperation(choice);
                } while (choice!=0);
                break;
            case 4:
                printf("\n");
                printf("1. Cube\n");
                printf("2. Cube root\n");
                printf("3. Exponential\n");
                printf("4. Square root\n");
                printf("5. Power\n");
                printf("6. Factorial\n");
                printf("7. Percentage\n");
                printf("8. Average\n");
                printf("9. Mean deviation\n");
                printf("10. Variance\n");
                printf("11. Standard deviation\n");
                printf("12. Sum of elements\n");
                printf("13. Permutation\n");
                printf("14. Combination\n");
                printf("0. Exit\n");
                do
                {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    performAdvancedOperation(choice);
                } while (choice!=0);
                break;
            case 5:
                printf("\n");
                printf("1. Inch to Centimeter\n");
                printf("2. Centimeter to Inch\n");
                printf("3. Centimeter to Meter\n");
                printf("4. Meter to Centimeter\n");
                printf("5. Kilometer per hour to Meter per second\n");
                printf("6. Meter per second to Kilometer per hour\n");
                printf("7. Foot to Meter\n");
                printf("8. Meter to Foot\n");
                printf("9. Mile to Kilometer\n");
                printf("10. Kilometer to Mile\n");
                printf("11. Mile to Meter\n");
                printf("12. Meter to Mile\n");
                printf("13. Fahrenheit to Celsius\n");
                printf("14. Celsius to Fahrenheit\n");
                printf("15. Joule to Calories\n");
                printf("16. Calories to Joule\n");
                printf("0. Exit\n");
                do
                {
                    printf("Enter your choice: ");
                    scanf("%d", &choice);
                    performUnitconversion(choice); 
                } while (choice!=0);
                break;
            case 6:
                printf("\n");
                printf("1. Matrix Addition\n");
                printf("2. Matrix Multiplication\n");
                printf("0. Main Menu\n");
                do
                {
                    printf("Enter your choice: ");
                    scanf("%d",&choice);
                    matrixoperation(choice);
                } while (choice!=0);
                break;
            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
                continue;
        }
    } while (choice != 7);

    return 0;
}
