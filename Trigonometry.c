#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main(void) {
	double degrees, radius, base, exponent, x;
	printf("Trigonometry\nEnter the angle in degrees: ");
	scanf("%lf", &degrees);
	printf("Geometry\nEnter the radius of the circle: ");
	scanf("%lf", &radius);
	printf("Exponentiation\nEnter the base: ");
	scanf("%lf", &base);
	printf("Enter the exponent: ");
	scanf("%lf", &exponent);
	x = pow(base, exponent);

	printf("The sine of %.2lf is %.2lf\n", degrees, sin(degrees));
	printf("The cosine of %.2lf is %.2lf\n", degrees, cos(degrees));
	printf("The tangent of %.2lf is %.2lf\n", degrees, tan(degrees));
	printf("%.2lf raised to the power of %.2lf is %.2lf\n", base, exponent, x);
	printf("The square root of %.2lf is %.2lf\n", x, sqrt(x));
	printf("The base-2 logarithm of %.2lf is %.2lf\n", x, log(x));
	printf("The base-10 logarithm of %.2lf is %lf\n", x, log10(x));
	printf("The ceiling of %.2lf is %.2lf\n", x, ceil(x));
	printf("The floor of %.2lf is %lf\n", x, floor(x));
	printf("A circle with a radius of %.2lf cm has:\n", radius);
	printf("%.2lf cm circumference and\n", radius * 2 * M_PI);
	printf("%.2lf cm area.", pow(radius, 2) * M_PI);

	//system("pause");
	return EXIT_SUCCESS;
}


/*
#include <cmath> // ou <math.h>
#include <iostream>
#include <cstdlib>
using namespace std;

int main (void){
    double graus, raio, base, expoente, x;
    cout << "Trigonometria\nDigite o numero dos graus -> ";
    cin >> graus;
    cout << "Geometria\nDigite a distancia do raio do circulo -> ";
    cin >> raio;
    cout << "Potenciacao\nDigite a base -> ";
    cin >> base;
    cout << "Digite o expoente -> ";
    cin >> expoente;
    cin.ignore();
    system ("cls");
    x = pow (base, expoente);
    cout << "O seno de "<<graus<<" e "<<sin(graus)<<endl;
    cout << "O co-seno de "<<graus<<" e "<<cos(graus)<<endl;
    cout << "A tangente de "<<graus<<" e "<<tan(graus)<<endl;
    cout << base<<" elevado a "<<expoente<<" e "<<x<<endl;
    cout << "A raiz quadrada de "<<x<<" e "<<sqrt(x)<<endl;
    cout << "O log2 de "<<x<<" e "<<log(x)<<endl;
    cout << "O log10 de "<<x<<" e "<<log10(x)<<endl;
    cout << "O teto de "<<x<<" e "<<ceil(x)<<endl;
    cout << "A parte inteira de "<<x<<" e "<<floor(x)<<endl;
    cout << "Um circulo com "<<raio<<"cm de raio tem: ";
    cout << raio*2*M_PI<<"cm de comprimento e ";
    cout << pow(raio,2)*M_PI<<"cm de area.\n"<<endl;
    system ("pause");
    return EXIT_SUCCESS;
}*/

