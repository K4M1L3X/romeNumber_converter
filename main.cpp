#include <iostream>
#include <string>
#include <cstdlib>

int ileLiczb(int n) {
    std::string i = std::to_string(n);
    return i.length();
}

int potegowanie(int p, int w) {
    if (w==0 || p==1) return 1;
    else return p*potegowanie(p,w-1);
}

int main() {

    int cyfra;

    while(true) {
        std::cout<<"Podaj cyfre w systemie arabskim (nie moze byc wieksza niz 3'999 oraz mniejsza niz 1): ";
        std::cin>>cyfra;

        if ( (cyfra<1) || (cyfra>3999) ) {
            while( (cyfra<1) || (cyfra>3999) ) {
            std::cout<<"Nie moze byc to cyfra wieksza od 3'999 oraz mniejsza od 1. Wprowadz ponownie: ";
            std::cin>>cyfra;
            }
        }
        


        //Tworze tablice, gdzie kazda liczba bedzie w niej przechowywana
        int tablica[ileLiczb(cyfra)];
        int p = potegowanie(10,ileLiczb(cyfra)) / 10;
        for (int i=0; i<ileLiczb(cyfra); i++) {
            tablica[i] = (cyfra%(p*10))/p;
            p/=10;
        }


        //Konwersja pojedynczych liczb w systemie arabskich do systemu rzymskiego

        std::string poRzymsku = "";

        int checking = ileLiczb(cyfra) - 1;
        for (int i=0; i<ileLiczb(cyfra); i++) {
            switch(checking) {
                
                //Konwersja dla pierwszch liczb
                case 0: 


                    //kiedy liczba -> 0
                    if (tablica[i]==0) poRzymsku +="";
                    //kiedy liczba -> <1;3>
                    else if (tablica[i]>=1 && tablica[i]<=3) {
                        for (int j=0; j<tablica[i]; j++) {
                            poRzymsku += "I";
                        }
                    }
                    //kiedy liczba -> 4
                    else if (tablica[i]==4) poRzymsku += "IV";
                    //kiedy liczba -> 5
                    else if (tablica[i]==5) poRzymsku += "V";
                    //kiedy liczba -> <6;8>
                    else if (tablica[i]>=6 && tablica[i]<=8) {
                        poRzymsku += "V";
                        for (int j=0; j<tablica[i]%5; j++) {
                            poRzymsku += "I";
                        }
                    }
                    //kiedy liczba -> 9
                    else if (tablica[i]==9) poRzymsku += "IX";
                    //kiedy nastapi jakis blad w konwersji
                    else poRzymsku += "?";
                    break;


                //Konwersja dla liczb dziesiętnych
                case 1: 

                    //kiedy liczba -> 00
                    if (tablica[i]==0) poRzymsku +="";
                    //kiedy liczba -> <10;30>
                    else if (tablica[i]>=1 && tablica[i]<=3) {
                        for (int j=0; j<tablica[i]/1; j++) {
                            poRzymsku += "X";
                        }
                    }
                    //kiedy liczba -> 40
                    else if (tablica[i]==4) poRzymsku += "XL";
                    //kiedy liczba -> 50
                    else if (tablica[i]==5) poRzymsku += "L";
                    //kiedy liczba -> <60;80>
                    else if (tablica[i]>=6 && tablica[i]<=8) {
                        poRzymsku += "L";
                        for (int j=0; j<(tablica[i])%5; j++) {
                            poRzymsku += "X";
                        }
                    }
                    //kiedy liczba -> 90
                    else if (tablica[i]==9) poRzymsku += "XC";
                    //kiedy nastapi jakis blad w konwersji
                    else poRzymsku += "??";
                    break;


                //Konwersja dla liczb setnych
                case 2:

                    //kiedy liczba -> 000
                    if (tablica[i]==0) poRzymsku +="";
                    //kiedy liczba -> <100;300>
                    else if (tablica[i]>=1 && tablica[i]<=3) {
                        for (int j=0; j<tablica[i]; j++) {
                            poRzymsku += "C";
                        }
                    }
                    //kiedy liczba -> 400
                    else if (tablica[i]==4) poRzymsku += "CD";
                    //kiedy liczba -> 500
                    else if (tablica[i]==5) poRzymsku += "D";
                    //kiedy liczba -> <600;800>
                    else if (tablica[i]>=6 && tablica[i]<=8) {
                        poRzymsku += "D";
                        for (int j=0; j<(tablica[i])%5; j++) {
                            poRzymsku += "C";
                        }
                    }
                    //kiedy liczba -> 900
                    else if (tablica[i]==9) poRzymsku += "CM";
                    //kiedy nastapi jakis blad w konwersji
                    else poRzymsku += "??";
                    break; 
                    

                //Konwersja dla liczb tysięcznych
                case 3:  
                    //kiedy liczba -> 0000
                    if (tablica[i]==0) poRzymsku +="";
                    //kiedy liczba -> <1000;3000>
                    else if (tablica[i]>=1 && tablica[i]<=3) {
                        for (int j=0; j<tablica[i]; j++) {
                            poRzymsku += "M";
                        }
                    }
                    break;


                default:

                    std::cout<<"Nie mozna skonwertowac wiekszej cyfry niz 3'999"<<std::endl;
                    break;
            }
            checking--;
        }

        std::cout << "Cyfra -> " << cyfra << " w systemie rzymskim: " << poRzymsku << std::endl << std::endl;
    }
    system("pause");
    
    return 1;
}
