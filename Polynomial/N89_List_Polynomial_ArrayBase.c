#include <stdio.h>

#define MAX_DEGREE 100

struct PolynomialInfo {
	double C[MAX_DEGREE+1];
	int high_power;
};

typedef struct PolynomialInfo *POLYNOMIAL;

void zero_polynomial(POLYNOMIAL poly) {
	for (int i=0;i<=MAX_DEGREE;i++)
		poly->C[i] = 0;
	poly->high_power = 0;
}

POLYNOMIAL createPolynomial() {
	POLYNOMIAL poly = malloc(sizeof(struct PolynomialInfo));
	zero_polynomial(poly);
	return poly;
}

void initialize_coefs(POLYNOMIAL poly, int high_power,double coef[]) {
	for (int i = 0;i<=high_power;i++)
		poly->C[i] = coef[i];
	poly->high_power = high_power;
}
void add_polynomial(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL SUM) {
	int high_power = A->high_power>B->high_power?A->high_power:B->high_power;
	for (int i = 0;i<=high_power;i++)
		SUM->C[i] = A->C[i]+B->C[i];
	SUM->high_power = high_power;
}

void mult_polynomial(POLYNOMIAL A, POLYNOMIAL B, POLYNOMIAL MULT) {
	int high_power = A->high_power+B->high_power;
	MULT->high_power = high_power;
	for (int i = 0;i<=A->high_power;i++)
		for (int j=0;j<=B->high_power;j++)		
			MULT->C[i+j] += A->C[i]*B->C[j];	
}

void show_polynomial(POLYNOMIAL poly) {
	for (int i=poly->high_power;i>=0;i--)
		if (poly->C[i]!=0)			
			if (poly->C[i] - (int)poly->C[i] == 0){
				if (i!=0)
					printf("%.0fx^%d ",poly->C[i],i);
				else
					printf("%.0f ",poly->C[i]);
			} else {
				if (i!=0)
					printf("%.1fx^%d ",poly->C[i],i);
				else
					printf("%.1f ",poly->C[i]);
			}
				
	printf("\n");
}

int main() {
	POLYNOMIAL A = createPolynomial();
	POLYNOMIAL B = createPolynomial();
	POLYNOMIAL SUM = createPolynomial();
	POLYNOMIAL MULT = createPolynomial();
	double A_Coef[] = {10.5,4,0,7};
	double B_Coef[] = {7,-4,5};
	initialize_coefs(A,3,A_Coef);
	initialize_coefs(B,2,B_Coef);
	show_polynomial(A);
	show_polynomial(B);
	add_polynomial(A,B,SUM);
	printf("SUM = ");
	show_polynomial(SUM);
	mult_polynomial(A,B,MULT);
	printf("MULT = ");
	show_polynomial(MULT);
	return 0;	
}
