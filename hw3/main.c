#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define UP 'w'//aşağı yukarı komutlarının tuşlara atanması
#define DOWN 's'
#define RIGHT 'd'
#define LEFT 'a'

int main() {
    int size,character,door,moves=0;
    char input;
    int selection;

    srand(time(NULL)); // random numara veren fonksiyon

    printf("******************************\n");
    printf("Welcome to the 2D puzzle game!");//başlangıç mesajı

     while (1) {// menü
        printf("\n1. New Game\n");
        printf("2. Help\n");
        printf("3. Exit\n");
        printf("Enter your selection: ");
        scanf("%d",&selection);
    
        switch (selection) {
            case 1://oyun başlangıcı
                printf("\nEnter board size (5-10): ");//oyun ekranı ebatı
                scanf("%d",&size);

                while (size<5 || size>10) { // şartlar
                    printf("Invalid board size. Enter a number between 5 and 10: ");
                    scanf("%d",&size);
                }

                character=rand()%(size*size); // karakterin random yerleştirilişi 
                door=rand()%(size*size); // kapının random yerleştirilişi

                while (character == door) { //karakterle kapı aynı hücredeyse kapıya farklı random atanıyor
                    door=rand()%(size*size);
                }

                printf("\nUse 'w', 'a', 's', 'd' to move the player. 'q' to quit.\n");//w a s d bilgilendirmesi

                while (1) { //oyun dögüsü
                    printf("\nMoves: %d\n", moves);
                    for (int i=0; i<size; i++) {//oyun ekranı üst tarafı
                        printf("--");
                    }
                    printf("-\n");//+1 çizgi

                    for (int i=0; i<size; i++) {//döngü içinde döngü yaparak size*size oyun ekranı oluşturuyor
                        for (int j=0; j<size; j++) {
                            if (i*size+j == character) {//karaktere denk gelirse çizgi yanına c yazıyor
                                printf("|C");
                            } else if (i*size+j == door) {//kapıya denk gelirse çizgi yanına d yazıyor
                                printf("|D");
                            } else {
                                printf("| ");//yoksa sadece çizgi boşluk
                            }
                        }
                        printf("|\n");
                    }

                    for (int i = 0; i < size; i++) {
                        printf("--");//oyun ekranı alt tarafı
                    }
                    printf("-\n");//+1 çizgi

                    printf("Enter move: ");
                    scanf(" %c", &input);

                    if (input == 'q') { // q oyundan çıkar
                        printf("Quitting game...\n");
                        return 0;
                        break;
                    }

                    int x = character/size;
                    int y = character%size;

                    switch (input) {
                        case UP:
                            if (x > 0) {
                                character -= size;//yukarı komutu
                                moves++;//hareket sayacı
                            }
                            else{
                                printf("you hit the wall,try again!!\n");
                            }      
                            break;
                        case DOWN:
                            if (x < size - 1) {
                                character += size;//aşağı komutu
                                moves++;//hareket sayacı
                            }
                            else{
                                printf("you hit the wall,try again!!\n");
                            }      
                            break;
                        case LEFT:
                            if (y > 0) {
                                character--;//sola gitme komutu
                                moves++;//hareket sayacı
                            }
                            else{
                                printf("you hit the wall,try again!!\n");
                            }      
                            break;
                        case RIGHT:
                            if (y < size - 1) {
                                character++;//sağa gitme komutu
                                moves++;//hareket sayacı
                            }
                            else{
                                printf("you hit the wall,try again!!\n");
                            }      
                            break;
                        default:
                            printf("Invalid move.\n");//diğer hareketleri reddediyor
                    }

                    if (character == door) { // karakter kapıya ulaşınca
                        printf("\nCongratulations! You won in %d moves.\n", moves);//tebrik mesajı
                        return 0;
                        break;
                    }
                }
                break;
            case 2:
                printf("The objective of the game is to reach the door 'D' on the board while avoiding obstacles.\n");
                printf("The player 'C' can move up, down, left, or right using 'w', 'a', 's', 'd' keys.\n");
                printf("The board size can be customized between 5 and 10.\n");
                break;//oyun tutorial'ı
            case 3:
                printf("Every new beginning comes from some other beginning's end.\n");//özlü söz
                printf("goodbye...\n");//oyundan çıkma
                return 0;
                break;
            default:
                printf("Invalid selection.\n");
        }

    } while (selection != 3);//3. seçeneği seçmezsen döngüyü tekrarlar

    return 0;
}