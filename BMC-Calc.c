#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* run this program using thand consoland pauser or add your own getch, system("pause") or input loop */
float BMCCalc(float weight, float height){
	float imc;
	imc=weight/pow(height,2);
	return imc;
}
void main() {
float weight, height;

	printf("type the weight: ");
	scanf ("%f", &weight);
	
	printf("type the height: ");
		scanf ("%f", &height);
	
	printf("Your BMC index is:  %.2f\n", BMCCalc(weight, height));
	printf("Less than 18.5: Underweight.\n");
	printf("Between 18.6 and 24.9: Normal weight.\n");
	printf("Between 25 and 29.9 = Light overweight.\n");
	printf("Between 30 and 34.9 = Grade 1 obesity.\n");
	printf("Between 35 and 39,9 = Grade 2 obesity.\n");
	printf("More than 40: Morbid obesity.\n");
	printf("\n"); 
}
