#include <stdio.h>
#include <locale.h>

int main(){
	setlocale(LC_ALL,"Turkish");
	float gizli=10;
	float tahmin=0;
	float sayac=1;
	printf("1 ile 100 arasýnda tutulan gizli sayýyý tahmin ederek bulmaya çalýþýn.\n");
	printf("Tahmininizi giriniz.\n");
	scanf(" %f", &tahmin);
	while(gizli>tahmin){
	printf("Tahmininiz gizli sayýdan küçük.\n");
	sayac++;
	printf("Yeni tahmininizi girin.\n");
	scanf(" %f", &tahmin);	
    }
    while(tahmin>gizli){
    printf("Tahmininiz gizli sayýdan büyük.\n");
	sayac++;
	printf("Yeni tahmininizi girin.\n");
	scanf(" %f", &tahmin);	
	}
	if(tahmin==gizli)
	printf("Tahmininiz doðru. toplam %.f defada buldunuz.", sayac);
    return 0;
}
