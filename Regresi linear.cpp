/* Tugas Metode Numerik 2
   Nama & NIM    : Mochammad Angga Fauzy (3411151162)
                   Dwi Cahya Ningrum (3411151155)
   Kelas         : SIE-C
*/
   
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <math.h>
#define nmax 100

int main  (){
	//kamus data
   int angka, jarak;
   int x[nmax+1];
   int y[nmax+1];
   float pre[nmax+1], error[nmax+1];
   float m, c, fx;
   float sigmax, sigmay, err, sigmaerror, sigmaxy=0, jumxkuadrat=0, jumykuadrat=0;
   int n, i;
   int xkuadrat[nmax+1], ykuadrat[nmax+1], xy[nmax+1];

   //banyaknya n
   printf ("\n>>>>>>>>PROGRAM REGRESI LINIER<<<<<<<<<\n");
   printf ("\nMasukkan N : "); scanf ("%d", &n);
   printf ("\n\n");

   //input nilai x
   for(i=1;i<=n;i++){
                     printf ("Masukkan nilai X : ");scanf("%d", &angka);
                       x[i]=angka;
  	                   xkuadrat[i]=pow(x[i], 2);
                       sigmax=sigmax + x[i];
                       jumxkuadrat=jumxkuadrat + xkuadrat[i];
   } 
   //tampil nilai x
   printf ("\nNILAI X\n");
   for (i=1; i<=n;i++){
	   printf ("\n X[%d] = %d \n", i, x[i]);
   } 
   printf ("\n");

  
   //input nilai y
   printf("\n*********************************\n");
   for (i=1;i<=n;i++){
	printf("Masukkan nilai Y : "); scanf("%d", &angka);
	y[i]=angka;
	sigmay=sigmay + y[i];
    ykuadrat[i]=pow(y[i], 2);
    jumykuadrat=jumykuadrat + ykuadrat[i];
    xy[i]=x[i]*y[i];
    sigmaxy=sigmaxy + xy[i];
    }
    //tampil nilai y
    printf ("\nNILAI Y\n");
    for (i=1; i<=n;i++){
	printf ("\n Y[%d] = %d \n",i, y[i]);
    } printf ("\n*********************************\n");


  
  //menghitung m
  m=((n*sigmaxy)-(sigmax*sigmay)) / ((n*jumxkuadrat)-pow(sigmax, 2));
  printf("\nNilai m = %.2f \n", m);
  
  //menghitung c
  c=((sigmay*jumxkuadrat)-(sigmax*sigmaxy)) / ((n*jumxkuadrat)-pow(sigmax, 2));
  printf("\nNilai c = %.2f \n", c);
  
   
  //menghitung prediksi
  printf ("\n*********************************");
  printf ("\n >>>>>>>>NILAI PREDIKSI<<<<<<<<<\n");
  for (i=1; i<=n;i++){
      pre[i]=(m*x[i])+c;
      printf ("\n jika f[%d] = %.2f \n", x[i], pre[i]);
  }
  
  //menghitung error
   for (i=1; i<=n;i++){
   	error[i]=y[i]-pre[i];
   	if (error[i]<0){
          error[i]=pre[i]-y[i];
	  }
          sigmaerror=sigmaerror + error[i];
   }
       	 //menghitung error
   			err=sigmaerror/n;
  
   
   //error tiap prediksi
    printf ("\n*********************************");
   printf ("\n>>>>>>>> SELISIH WAKTU (ERROR) <<<<<<<<<\n");
   for (i=1; i<=n;i++){
    	printf ("\n jika f(x)=%.2f yaitu %.2f \n", pre[i], error[i]);
}
   //tampil nilai error rata-rata
   printf ("\n*********************************");
  // printf ("\nNilai Sigma error = %f \n ", sigmaerror);
   printf ("\n>>>>>>>> RATA-RATA ERROR <<<<<<<<<\n");
   printf ("\nMaka nilai rata-rata error sebesar %.2f \n ", err);
   getch();
}


