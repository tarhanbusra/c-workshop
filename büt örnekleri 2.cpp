#include <stdio.h>

/*2) Tam say� tutabilen bir dizi i�in istenilen miktarda (1 ile 10 aras�nda olmas� sa�lans�n) klavyeden tam 
say� girilmesini isteyiniz. Daha sonra klavyeden girilen indeks (0 ile dizinin eleman say�s�-1 aras�nda 
olmas� sa�lans�n) b�lgesinden dizi ikiye ayr�ls�n ve ikiye ayr�lan b�lmeler yer de�i�tirsin.*/
int ikiyeayrilma(int size);
int sizekontrol();

int sizekontrol() {
	int size;
	
	printf("Olu�turlacak dizi ka� elemanl� olsun?(En az 1, en fazla 10)\n");
	scanf("%d", &size);
    
	if(size<1 || size>10){
	    size = sizekontrol();
}
	return size;
}

int ikiyeayrilma(int size){
	int a;
	
	printf("dizi hangi indeksten ikiye ayr�ls�n?(en az 0 en fazla %d):", size-1);	
    scanf("%d", &a);
    
    if(a<0 || a>=size){
    	a = ikiyeayrilma(size);
    }
	return a;
}

int main(){
	int size,i,a;
		
    size=sizekontrol();
	 
	int dizi[size];
	 
	printf("Dizinin elemanlar�n� giriniz.\n");
	for(i=0;i<size;i++)
	scanf("%d", &dizi[i]);
	
	a=ikiyeayrilma(size);
	
	int dizi2[a];
	
	for(i=0;i<a;i++){
		dizi2[i]=dizi[i];
	}
	
	for(i=0;i<size-a;i++){
	dizi[i]=dizi[i+a];
	}
	
	for(i=0;i<a;i++){ // ben burda size dan k���kken demi�tim bak tekrar buraya
		dizi[i+size-a]=dizi2[i];
	}
	
	printf(" dizi = ");
	for(i=0;i<size;i++)
	printf("%d ", dizi[i]);
	
	return 0;
}

