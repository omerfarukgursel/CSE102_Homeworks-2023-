#include <stdio.h>
#include <math.h>

int leap_year();
int calculator();
int final_grade();

int main(){
    
    leap_year();
    calculator();
    final_grade();
    
}

int leap_year(){
    int year;
    printf("****************************\n");
    printf("Please enter a year: ");
    scanf("%d",&year);

    if (year%4==0){//yıl 4e bölünüyor mu?
        if(year%100==0){//eğer 4 ve yüze kalansız bölünüyorsa artık yıl değil
            if(year%400==0){//400e de kalansız bölünüyorsa artık yıl
                printf("%d is a lap year",year);
            }
            else{
               printf("%d is not a lap year",year); 
            }
        }
        else{
            printf("%d is a lap year",year);
        }
    }
    else{
        printf("%d is not a lap year",year);
    }
    return 0;
}

double calculateResult(double n1, double n2, char operator) {
    double result;

    switch(operator) {
        case '+'://toplama komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            result = n1 + n2;
            break;
        case '-'://çıkarma komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            result = n1 - n2;
            break;
        case '*'://çarpma komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            result = n1 * n2;
            break;
        case '/'://bölme komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            if (n2 == 0) {//0a bölünürse tanımsız olur
                printf("Error: Division by zero.\n");
                return 0;
            } else {
                result = n1 / n2;
            }
            break;
        case '!'://faktoriyel komutu
            printf("Enter the number: ");//program tek sayı talep ediyor
            scanf("%lf",&n1);
            if (n1 < 0 || n1 != (int)n1) {//burada n1 sıfırdan küçük olmamalı ya da ondalık sayı olmamalı
                printf("Error: Invalid input for factorial.\n");//öyle olursa kabul etmiyor
                return 0;
            } else {
                int i;
                result = 1;
                for (i = 1; i <= n1; i++) {//n1e kadar i sürekli artıp çarpılıyor sonuç çıkana kadar
                    result *= i;
                }
            }
            break;
        case '^'://üs alma komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            result = pow(n1, n2);//math.h kütüphanesinin fonksiyonu
            break;
        case '%'://mod alma komutu
            printf("Enter the numbers: ");
            scanf("%lf %lf",&n1,&n2);
            if (n2 == 0) {//mod alan sayı 0a eşit olmamalı
                printf("Error: Division by zero.\n");//öyle olursa kabul etmiyor
                return 0;
            } else {
                result = fmod(n1, n2);//math.h kütüphanesinin fonksiyonu
            }
            break;
        default:
            printf("Error: Invalid operator.\n");//farklı bir komutta bu hata veriliyor
            return 0;
    }

    return result;
}

void formatResult(double result, char format) {
    if (format == 'S') {//kullanıcı S formatı girerse m ve n değerleri isteniyor
        int n, m;
        printf("Enter n and m (n <= m): ");//n m'den küçük ya da eşit olmak zorunda
        scanf("%d %d", &n, &m);
        if (n > m) {//n m'den büyük olursa hata veriliyor
            printf("Error: n cannot be greater than m.\n");
            return;
        }
        double power = log10(result);// logaritma kullanarak sonucun kaç basamaklı olduğunu hesaplıyor
        if (power < m - n) {//eğer sonuç, m-n'den daha az basamak içeriyorsa, sayı n basamağa kadar kesilir
            printf("%.*f\n", n, result);//bu formatta hesaplanır
        } else if (power >= m) {
            printf("%.*e\n", n, result);//eğer sonuç m'den daha büyük veya eşitse, sayı bilimsel nota dönüştürülür
        } else {
            int zeros = m - (int)power - 1;//sonuç m-n ve m arasında bir değerde ise, sonucun kaç tane sıfır içereceği hesaplanır
            printf("%.*f", n, result * pow(10, zeros));//sonucun o kadar sıfır eklenmiş hali hesaplanır ve bilimsel nota dönüştürülerek yazdırılır
            printf("e%d\n", zeros);//burada zeros değişkeni sonucun kaç tane sıfır içerdiğini temsil eder
        }
    } else if (format == 'I') {//I formatında düz işlem yaparız
        printf("%d\n", (int)result);
    } else {// S ya da I formatı haricindekiler kabul edilmiyor
        printf("Error: Invalid format.\n");
    }
}

int calculator() {
    double n1, n2, result;
    char operator, format;
    printf("\n************************\n");
    printf("Enter the format of output (S or I): ");//format isteniyor
    scanf(" %c",&format);
    printf("Enter the operation:(+, -, *, /,!,^, %%): ");//operatör isteniyor
    scanf(" %c",&operator);



    result = calculateResult(n1, n2, operator);//alınan datalara göre sonuç hesaplanıyor
    if (result != 0) {
        formatResult(result, format);//sonuç 0 değilse formata göre yazdırılıyor
    }

    return 0;
}

#include<stdio.h>

int final_grade(){
    float e1,e2,e3,a1,a2,fg;
    printf("\n**********************************\n");
    printf("Enter 3 exam grades of student (between 0-100): ");//3 sınav sonucu isteniyor
    scanf("%f %f %f",&e1,&e2,&e3);
    printf("Enter 2 assignment grades of student (between 0-100): ");//2 ödev sonucu isteniyor
    scanf("%f %f",&a1,&a2);
    fg=(e1+e2+e3)/3.0*0.6 +(a1+a2)/2.0*0.4;//final notu formülü
    if(fg>=60){
        printf("Final grade: %.1f Passed!",fg);//final notu 60 ya da 60'tan yüksekse geçtiniz mesajı
    }//aynı zamanda noktadan sonra tek basamak olacak şekilde final notu yazdırılıyor 
    if(fg<60)
        printf("Final grade: %.1f Failed!",fg);{//final notu 60'tan düşükse kaldınız mesajı
    }
    return 0;
}