//CODE::BLOCKS 17.12 GNU GCC COMPILER

#include <iostream>
#include <iomanip>
#include <windows.h>

using namespace std;

void czyszczenieKonsoli()
{
    system("cls");
}

void czekajNaEnter()
{
    system("pause");
}

void rysujPlansze(char tab[17][17], int gracz)
{
    char indeksy[17] = {'I',' ','H',' ','G',' ','F',' ','E',' ','D',' ','C',' ','B',' ','A'};
    cout << setw(3) << "1" << setw(2) << "2" << setw(2) << "3" << setw(2) << "4" << setw(2) << "5" << setw(2) << "6" << setw(2) << "7" << setw(2) << "8" << setw(2) << "9" << endl;
    for(int i=0;i<17;i++)
    {
        cout << indeksy[i] << " ";
        for(int j=0;j<17;j++)
        {
            cout << tab[i][j];
        }
        switch(i)
        {
        case 5:
            {
                cout << setw(17) << "gracz 1 - x";
                if(gracz == 1) cout << "<-";
                break;
            }
        case 6:
            {
                cout << setw(17) << "gracz 2 - o";
                if(gracz == -1) cout << "<-";
                break;
            }
        case 8:
            {
                cout << setw(10) << "NW" << setw(3) << "N" << setw(4) << "NE";
                break;
            }
        case 10:
            {
                cout << setw(10) << "W" << setw(3) << " " << setw(3) << "E";
                break;
            }
        case 12:
            {
                cout << setw(10) << "SW" << setw(3) << "S" << setw(4) << "SE";
                break;
            }
        }
    cout << endl;
    }
    cout << endl;
}

void nazwanieGraczy(string &jeden, string &dwa)
{
    cout << "podaj nazwe gracza 1: ";
    getline(cin,jeden);
    cout << "podaj nazwe gracza 2: ";
    getline(cin,dwa);
    cout << endl;
}

void rysujNaglowek() //function that draw headline
{
    cout << " W A R C A B Y   K R Z Y Z O W E" << endl;
    cout << setw(32) << "by: Lukasz Kaminski" << endl << endl;
}

void rysujPomoc()
{
    cout << "> Gracze poruszaja sie na zmiane," << endl;
    cout << "> W jednej turze gracz musi poruszyc sie jedna figura," << endl;
    cout << "> Figury moga poruszyc sie o jedno pole zgodnie z krawedziami narysowanymi na planszy," << endl;
    cout << "> Figury moga bic zgodnie z krawedziami narysowanymi na planszy," << endl << "  czyli przeskakiwac figure przeciwnika na wolne pole znajdujace sie tuz za nim," << endl;
    cout << "> Po biciu figura jest zdejmowana z planszy," << endl;
    cout << "> Bicie jest wymagane," << endl;
    cout << "> Gracz wygrywa jesli blokuje ruch wszystkich figur przeciwnika," << endl;
    cout << "> Gracz wygrywa jesli zbije wszystkie figury przeciwnika," << endl;
    cout << "> Gracz wygrywa jesli dojdzie jedna z figur do ostatnich pol," << endl;
    cout << "> Przebieg rundy:" << endl;
    cout << " >sprawdzenie czy mozliwe bicie:" << endl;
    cout << "  >jezeli mozliwe, to wykonujemy i koniec naszej rundy" << endl;
    cout << "  >jezeli niemozliwe, to przechodzimy do nastepnego kroku"<< endl;
    cout << " >wybranie pionka:" << endl;
    cout << "  >wybranie wiersza, przez wspianie odpowiadajacej mu litery [I,H,G,F,E,D,C,B,A]" << endl;
    cout << "  >wybranie kolumny, przez wspianie odpowiadajacej mu cyfry [1,2,3,4,5,6,7,8,9]" << endl;
    cout << " >zatwierdzenie pionka, lub wybranie innego" << endl;
    cout << " >wybranie kirunku:" << endl;
    cout << "  >wybranie kierunku, przez wpisanie odpowiadajacej mu litery [NW, N, NE, W, E, SW, S, SE]" << endl;
    cout << "  >roza wiatrow znajduje sie po prawej stronie planszy" << endl;
    cout << endl;
    cout << "nacisnij ENTER, aby zamknac" << endl << endl;
}

void podstawoweMenu(bool &koniec)
{
    rysujNaglowek();
    char wybor;
    cout << "  M E N U" << endl << "  1. graj" << endl << "  2. pomoc" << endl << "  3. wylacz" << endl << endl;
    cout << " twoj wybor: ";
    cin >> wybor;
    czyszczenieKonsoli();
    switch(wybor)
    {
        case '1':
        {
            break;
        }
        case '2':
        {
            rysujNaglowek();
            rysujPomoc();
            czekajNaEnter();
            czyszczenieKonsoli();
            podstawoweMenu(koniec);

            break;
        }
        case '3':
        {
            koniec=true;
            break;
        }
        default:
        {
            cout << "zly wybor, wybierz ponownie" << endl;
            podstawoweMenu(koniec);
        }
    }
}

void pokazKtoRusza(int gracz, string g1, string g2)
{
    czyszczenieKonsoli();
    rysujNaglowek();
    cout << endl<< endl<< endl<< endl<< endl;
    cout << "      " << setw(14) << "Ruch wykonuje:" << endl;
    if(gracz == 1)
    {
        cout << "      " << setw(14)<< g1 << endl;
    }
    else
    {
        cout << "      " << setw(14)<< g2 << endl;
    }
    cout << endl<< endl<< endl<< endl<< endl<< endl<< endl<< endl;
    czekajNaEnter();
}

void zerowanie(int tab[3][3]) //zerowanie pol malej tablicy
{
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            tab[i][j] = 0;

        }
    }
}

void gdzieMoznaRuszyc(char tab[17][17], int tab2[3][3], int w, int k, int gracz) //dla danego pola sprawdza mo¿liwoœci ruchu dooko³a niego 0-nie ma ruchu, 1-ruch, 2-bicie, dlugi ruch
{
    char prz; //pionek przeciwnika
    char grcz; //pionek aktualnego gracza
    if(gracz == 1 )
    {
      grcz = 'x';
      prz = 'o';
    }
    else
    {
        grcz = 'o';
        prz ='x';
    }
    if(tab[w][k]==grcz)
    {
        if(tab[w-1][k-1]=='\\') //NW
        {
            if(tab[w-2][k-2]==' ')
            {
                 tab2[0][0] = 1;
            }
            if((tab[w-2][k-2]==prz) && (tab[w-3][k-3]=='\\') && (tab[w-4][k-4]==' '))
            {
                 tab2[0][0] = 2;
            }
        }
        if(tab[w-1][k]=='|') //N
        {
            if(tab[w-2][k]==' ')
            {
                 tab2[0][1] = 1;
            }
            if((tab[w-2][k]==prz) && (tab[w-3][k]=='|') && (tab[w-4][k]==' '))
            {
                 tab2[0][1] = 2;
            }
            if((tab[w-2][k]=='|') && (tab[w-3][k]='|') && (tab[w-4][k]==' '))
            {
                 tab2[0][1] = 3;
            }
            if((tab[w-2][k]=='|') && (tab[w-3][k]='|') && (tab[w-4][k]==prz) && (tab[w-2][k]=='|') && (tab[w-3][k]='|') && (tab[w-4][k]==' '))
            {
                 tab2[0][1] = 3;
            }

        }
        if(tab[w-1][k+1]=='/') //NE
        {
            if(tab[w-2][k+2]==' ')
            {
                 tab2[0][2] = 1;
            }
            if((tab[w-2][k+2]==prz) && (tab[w-3][k+3]=='/') && (tab[w-4][k+4]==' '))
            {
                 tab2[0][2] = 2;
            }
        }
        if(tab[w][k-1]=='-') //W
        {
            if(tab[w][k-2]==' ')
            {
                 tab2[1][0] = 1;
            }
            if((tab[w][k-2]==prz) && (tab[w][k-3]=='-') && (tab[w][k-4]==' '))
            {
                 tab2[1][0] = 2;
            }
            if((tab[w][k-2]=='-') && (tab[w][k-3]=='-') && (tab[w][k-4]==' '))
            {
                 tab2[1][0] = 3;
            }
        }
        if(tab[w][k+1]=='-') //E
        {
            if(tab[w][k+2]==' ')
            {
                 tab2[1][2] = 1;
            }
            if((tab[w][k+2]==prz) && (tab[w][k+3]=='-') && (tab[w][k+4]==' '))
            {
                 tab2[1][2] = 2;
            }
            if((tab[w][k+2]=='-') && (tab[w][k+3]=='-') && (tab[w][k+4]==' '))
            {
                 tab2[1][2] = 3;
            }
        }
        if(tab[w+1][k-1]=='/') //SW
        {
            if(tab[w+2][k-2]==' ')
            {
                 tab2[2][0] = 1;
            }
            if((tab[w+2][k-2]==prz) && (tab[w+3][k-3]=='/') && (tab[w+4][k-4]==' '))
            {
                 tab2[2][0] = 2;
            }
        }
        if(tab[w+1][k]=='|')  //S
        {
            if(tab[w+2][k] ==' ')
            {
                 tab2[2][1] = 1;
            }
            if((tab[w+2][k]==prz) && (tab[w+3][k]=='|') && (tab[w+4][k]==' '))
            {
                 tab2[2][1] = 2;
            }
            if((tab[w+2][k]=='|') && (tab[w+3][k]=='|') && (tab[w+4][k]==' '))
            {
                 tab2[2][1] = 3;
            }
        }
        if(tab[w+1][k+1]=='\\') //SE
        {
            if(tab[w+2][k+2]==' ')
            {
                 tab2[2][2] = 1;
            }
            if((tab[w+2][k+2]==prz) && (tab[w+3][k+3]=='\\') && (tab[w+4][k+4]==' '))
            {
                 tab2[2][2] = 2;
            }
        }
    }
}

string tabNaKiedunek(int tab[3][3]) //zwraca kierunek, w ktorym mozliwe jest bicice
{
    for(int i = 0;i<3;i++)
    {
        for(int j =0; j<3;j++)
        {
            if(tab[i][j] == 2)
            {
                if(i==0 && j==0) return "NW";
                if(i==0 && j==1) return "N";
                if(i==0 && j==2) return "NE";
                if(i==1 && j==0) return "W";
                if(i==1 && j==2) return "E";
                if(i==2 && j==0) return "SW";
                if(i==2 && j==1) return "S";
                if(i==2 && j==2) return "SE";
            }
        }
    }
}

char CyferkaNaLiterke(int lit) //zamienia cyfre na litere, ktora jest uzywana do oznaczenia pola na planszy
{
    if (lit == 0) return 'I';
    if (lit == 1) return 'H';
    if (lit == 2) return 'G';
    if (lit == 3) return 'F';
    if (lit == 4) return 'E';
    if (lit == 5) return 'D';
    if (lit == 6) return 'C';
    if (lit == 7) return 'B';
    if (lit == 8) return 'A';
}
void bicie(char tab[17][17], int w, int k, string kier) // wykonanie bicia w danym kierunku
{
    if(kier=="NW")
    {
        tab[w-4][k-4] = tab[w][k];
        tab[w-2][k-2] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="N")
    {
        tab[w-4][k] = tab[w][k];
        tab[w-2][k] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="NE")
    {
        tab[w-4][k+4] = tab[w][k];
        tab[w-2][k+2] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="W")
    {
        tab[w][k-4] = tab[w][k];
        tab[w][k-2] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="E")
    {
        tab[w][k+4] = tab[w][k];
        tab[w][k+2] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="SW")
    {
        tab[w+4][k-4] = tab[w][k];
        tab[w+2][k-2] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="S")
    {
        tab[w+4][k] = tab[w][k];
        tab[w+2][k] = ' ';
        tab[w][k] = ' ';
    }
    if(kier=="SE")
    {
        tab[w+4][k+4] = tab[w][k];
        tab[w+2][k+2] = ' ';
        tab[w][k] = ' ';
    }
}

void czyMozliweBicie(char tab[17][17],int tab2[3][3], int gracz, bool &zbito) //sprawdza czy mozliwe bicie, jesli tak to je wykonuje
{
    int bicieW, bicieK;
    bool czyBicie=false;
        for(int i=0;i<17;i += 2)
        {
            for(int j=0;j<17;j+=2)
            {
                zerowanie(tab2);
                gdzieMoznaRuszyc(tab,tab2,i,j,gracz);
                for(int k=0;k<3;k++)
                {
                    for(int y=0;y<3;y++)
                    {
                        if(tab2[k][y]==2) //czy mozliwe bicie
                        {
                            czyBicie=true;
                            bicieW = i;
                            bicieK = j;
                            i = 20;
                            j = 20;
                            k = 4;
                            y = 4;
                        }
                    }
                }
            }
        }
    if(czyBicie) //wykonanie bicia
    {
        string kierunek = tabNaKiedunek(tab2);
        czyszczenieKonsoli();
        rysujNaglowek();
        rysujPlansze(tab,gracz);
        cout << setw(14) << "Mozliwe bicie:" << endl;
        cout << "Pole: " << CyferkaNaLiterke(bicieW/2) << " " << (bicieK/2)+1 << endl;
        cout << "Kierunek:" << kierunek <<  endl;
        cout << "Nacisnij ENTER, aby wykonac" << endl;
        bicie(tab,bicieW,bicieK,kierunek);
        zbito = true;
        czekajNaEnter();
        zerowanie(tab2);
    }
}

void podanieWartosci(char &cliterka, int &cyferka) //zwraca literke i cyferke
{
    cout << "literka: ";
    cin >> cliterka;
    cliterka = toupper(cliterka);
    cout << "cyferka: ";
    cin >> cyferka;
}

void literkaNaCyferke(char clit, int &lit) //zamiana literki cyferke
{
    if(clit=='I') lit = 0;
    if(clit=='H') lit = 1;
    if(clit=='G') lit = 2;
    if(clit=='F') lit = 3;
    if(clit=='E') lit = 4;
    if(clit=='D') lit = 5;
    if(clit=='C') lit = 6;
    if(clit=='B') lit = 7;
    if(clit=='A') lit = 8;
}

void wyborNaIndeks(int lit, int cyf, int &w, int &k) //zamienia podane wartosci na indeksy tabeli
{
    w = lit*2;
    k = (cyf-1)*2;
}

void wyborPionka(int &w, int &k) //wybranie pionka za pomoca literki i cyferki, zwraca indeksy planszy
{
    char clit;
    int lit,cyf;
    podanieWartosci(clit, cyf);
    literkaNaCyferke(clit,lit);
    wyborNaIndeks(lit,cyf,w,k);
}

bool poprawneDane(char tab[17][17], int w, int k, int gracz) //sprawdzanie czy gracz wybral swoj pionek, a nie jakies inne pole na planszy
{
    if(((gracz == 1) && (tab[w][k] == 'x'))||((gracz == -1) &&(tab[w][k] == 'o')))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

bool czyMozliwyRuch(int tab[3][3])
{
    int mozliweRuchy = 0;
    for(int i=0;i<3;i++)
    {
        for(int j =0;j<3;j++)
        {
            if(tab[i][j] != 0)
            {
                mozliweRuchy += 1;
            }
        }
    }
    if(mozliweRuchy != 0) return true;
    else return false;

}

void wybraniePionka(char tab[17][17], int tab2[3][3], int gracz, int &tabw, int &tabk)
{
    bool poprawne, jestRuch;
    while(1)     //wybor i sprawdzanie poprawnosci wyboru
    {
        czyszczenieKonsoli();
        rysujNaglowek();
        rysujPlansze(tab,gracz);
        zerowanie(tab2);
        cout << endl << "wybierz pionek V" << endl;
        wyborPionka(tabw, tabk);                            //wybieramy pionek, otrzymujemy tabw i tabk
        poprawne = poprawneDane(tab, tabw,tabk,gracz);              //sprawdzamy czy wybrano odpowiedni pionek dla konkretnego gracza
        gdzieMoznaRuszyc(tab,tab2,tabw,tabk, gracz);        //tutaj wiemy w jakich kierunkach jakie sa mozliwosci
        jestRuch = czyMozliwyRuch(tab2);
        if(poprawne)
        {
            if(jestRuch)
            {
                break;       //poprawne dane i jest ruch
            }
            else
            {
                cout <<endl<< "wybrany pionek nie moze sie ruszyc" << endl;
                czekajNaEnter();
            }
        }
        else
        {
            cout<<endl<< "zle dane, podaj ponownie: " << endl;
            czekajNaEnter();
        }
    }
}

void menuPionek(char plansza[17][17], int tab2[3][3], int gracz,int tabw, int tabk) //mozliwosc zmiany pionka
{
    czyszczenieKonsoli();
    rysujNaglowek();
    char wybor;
    rysujPlansze(plansza,gracz);
    cout << "  M E N U" << endl << "  1. wybierz gdzie chcesz ruszyc" << endl << "  2. wybierz inny pionek" << endl << endl;
    cout << " twoj wybor: ";
    cin >> wybor;
    czyszczenieKonsoli();
    switch(wybor)
    {
        case '1':
        {
            break;
        }
        case '2':
        {
            wybraniePionka(plansza,tab2, gracz, tabw, tabk);
            menuPionek(plansza,tab2,gracz, tabw, tabk);
            break;
        }
        default:
        {
            cout << "zly wybor, wybierz ponownie" << endl;
            menuPionek(plansza, tab2, gracz, tabw, tabk);
        }
    }
}

bool czyDobryKierunek(int tab[3][3], string kierunek) //sprawdzenie czy w danym kierunku dostepne jest bicie
{
    if(((kierunek=="NW")||(kierunek=="nw")||(kierunek=="Nw")||(kierunek=="nW"))&&(tab[0][0]==1)) return 1;
    if(((kierunek=="N")||(kierunek=="n"))&&((tab[0][1]==1)||(tab[0][1]==3))) return 1;
    if(((kierunek=="NE")||(kierunek=="ne")||(kierunek=="Ne")||(kierunek=="nE"))&&(tab[0][2]==1)) return 1;
    if(((kierunek=="W")||(kierunek=="w"))&&((tab[1][0]==1)||(tab[1][0]==3))) return 1;
    if(((kierunek=="E")||(kierunek=="e"))&&((tab[1][2]==1)||(tab[1][2]==3))) return 1;
    if(((kierunek=="SW")||(kierunek=="sw")||(kierunek=="Sw")||(kierunek=="sW"))&&(tab[2][0]==1)) return 1;
    if(((kierunek=="S")||(kierunek=="s"))&&((tab[2][1]==1)||(tab[2][1]==3))) return 1;
    if(((kierunek=="SE")||(kierunek=="se")||(kierunek=="Se")||(kierunek=="sE"))&&(tab[2][2]==1)) return 1;
    else  return 0;
}

void posuniece(char tab[17][17],int w, int k, string kier)
{
    if((kier=="NW")||(kier=="nw")||(kier=="Nw")||(kier=="nW"))
    {
        tab[w-2][k-2] = tab[w][k];
        tab[w][k] = ' ';
    }
    if((kier=="N")||(kier=="n"))
    {
        if(tab[w-2][k]==' ')
        {
            tab[w-2][k] = tab[w][k];
            tab[w][k] = ' ';
        }
        if(tab[w-2][k]=='|')
        {
            tab[w-4][k] = tab[w][k];
            tab[w][k] = ' ';
        }

    }
    if((kier=="NE")||(kier=="ne")||(kier=="Ne")||(kier=="nE"))
    {
        tab[w-2][k+2] = tab[w][k];
        tab[w][k] = ' ';
    }
    if((kier=="W")||(kier=="w"))
    {
        if(tab[w][k-2] == ' ')
        {
            tab[w][k-2] = tab[w][k];
            tab[w][k] = ' ';
        }
        if(tab[w][k-2] == '-')
        {
            tab[w][k-4] = tab[w][k];
            tab[w][k] = ' ';
        }
    }
    if((kier=="E")||(kier=="e"))
    {
        if(tab[w][k+2] == ' ')
        {
            tab[w][k+2] = tab[w][k];
            tab[w][k] = ' ';
        }
        if(tab[w][k+2] == '-')
        {
            tab[w][k+4] = tab[w][k];
            tab[w][k] = ' ';
        }
    }
    if((kier=="SW")||(kier=="sw")||(kier=="Sw")||(kier=="sW"))
    {
        tab[w+2][k-2] = tab[w][k];
        tab[w][k] = ' ';
    }
    if((kier=="S")||(kier=="s"))
    {
        if(tab[w+2][k]==' ')
        {
            tab[w+2][k] = tab[w][k];
            tab[w][k] = ' ';
        }
        if(tab[w+2][k]=='|')
        {
            tab[w+4][k] = tab[w][k];
            tab[w][k] = ' ';
        }
    }
    if((kier=="SE")||(kier=="se")||(kier=="Se")||(kier=="sE"))
    {
        tab[w+2][k+2] = tab[w][k];
        tab[w][k] = ' ';
    }
}

void wykonanieRuchu(char tab[17][17], int tab2[3][3], int tabw, int tabk, int gracz)
{
    bool poprawne;
    string kier;
    rysujNaglowek();
    rysujPlansze(tab,gracz);
    cout << "wybrany pionek: " << CyferkaNaLiterke(tabw/2) << (tabk/2)+1;
    while(1)
    {
        cout << endl << "w jaka strone chcesz sie ruszyc: " << endl;
        cin >> kier;
        poprawne=czyDobryKierunek(tab2,kier);
        if(poprawne)
        {https://cleant.it/pages/animalpack_zebra
            break;
        }
        else
        {
            cout << "nie mozna sie ruszyc w wybranym kierunku, podaj ponownie!" << endl;
        }
    }
    posuniece(tab,tabw,tabk,kier);
    czyszczenieKonsoli();
    rysujPlansze(tab,gracz);

}

void czyPionekNaKoncu(char tab[17][17], string g1, string g2, bool &koniec)
{
    if((tab[0][4]=='o')||(tab[0][8]=='o')||(tab[0][12]=='o'))
    {
        cout << "wygral " << g2 << ", jego pionek doszedl na drugi koniec planszy" << endl;
        koniec = true;
    }
    if((tab[16][4]=='x')||(tab[16][8]=='x')||(tab[16][12]=='x'))
    {
        cout << "wygral " << g1 << ", jego pionek doszedl na drugi koniec planszy" << endl;
        koniec = true;
    }
}

void czyZbitePionki(char tab[17][17], string g1, string g2, bool &koniec)
{
    int iksy=0;
    int kolka=0;
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<17;j++)
        {
            if(tab[i][j]=='x') iksy++;
            if(tab[i][j]=='o') kolka++;

        }

    }
    if(iksy==0)
    {
        cout << "wygral " << g2 << ", zbil wszystkie pionki przeciwnika" << endl;
        koniec = true;
    }
    if(kolka==0)
    {
        cout << "wygral " << g1 << ", zbil wszystkie pionki przeciwnika" << endl;
        koniec = true;
    }

}

void czyZablokowany(char tab[17][17], string g1, string g2, bool &koniec)
{
    int gracz;
    bool iksy=false;
    bool kolka=false;
    int tab2[3][3]={{0,0,0},{0,0,0},{0,0,0}};
    bool ruch;
    for(int i=0;i<17;i++)
    {
        for(int j=0;j<17;j++)
        {

            if(tab[i][j]=='x')
            {
                gracz = 1;
                zerowanie(tab2);
                ruch=false;
                gdzieMoznaRuszyc(tab,tab2,i,j,gracz);
                ruch=czyMozliwyRuch(tab2);
                if(ruch)
                {
                    iksy = true;
                }
            }
            if(tab[i][j]=='o')
            {
                gracz = -1;
                ruch=false;
                gdzieMoznaRuszyc(tab,tab2,i,j,gracz);
                ruch=czyMozliwyRuch(tab2);
                if(ruch)
                {
                    kolka = true;
                }
            }
        }
        cout << endl;
    }
    if(iksy==false)
    {
        cout << "wygral " << g2 << ", zablokowal ruchy przeciwnika" << endl;
        koniec = true;
    }
    if(kolka==false)
    {
        cout << "wygral " << g1 << ", zablokowal przeciwnika" << endl;
        koniec = true;
    }

}

int main()
{
    struct gra
    {
        char plansza[17][17] =  {{' ',' ',' ',' ','x','-','-','-','x','-','-','-','x',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ','\\',' ',' ','|',' ',' ','/',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ','x','-','x','-','x',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' ','\\','|','/',' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ','x','-','x','-','x','-','x','-','x',' ',' ',' ',' '},
                                {'|','\\',' ',' ','|','\\','|','/','|','\\','|','/','|',' ',' ','/','|'},
                                {'|',' ',' ',' ','x','-','x','-','x','-','x','-','x',' ',' ',' ','|'},
                                {'|',' ','|','\\','|','/','|','\\','|','/','|','\\','|','/','|',' ','|'},
                                {' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' ','-',' '},
                                {'|',' ','|','/','|','\\','|','/','|','\\','|','/','|','\\','|',' ','|'},
                                {'|',' ',' ',' ','o','-','o','-','o','-','o','-','o',' ',' ',' ','|'},
                                {'|','/',' ',' ','|','/','|','\\','|','/','|','\\','|',' ',' ','\\','|'},
                                {' ',' ',' ',' ','o','-','o','-','o','-','o','-','o',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ',' ','/','|','\\',' ',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ',' ','o','-','o','-','o',' ',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ',' ','/',' ',' ','|',' ',' ','\\',' ',' ',' ',' ',' '},
                                {' ',' ',' ',' ','o','-','-','-','o','-','-','-','o',' ',' ',' ',' '}};
        int ruchy[3][3];
        int aktualnyGracz = 1;
        string gr1;
        string gr2;
        bool koniecGry = false;
    };

    gra warcaby;
    bool byloBicie=false;

    rysujNaglowek();
    nazwanieGraczy(warcaby.gr1,warcaby.gr2);
    czyszczenieKonsoli();
    podstawoweMenu(warcaby.koniecGry);

    while(!warcaby.koniecGry) //glowna petla gry
    {
        int w, k;
        byloBicie=false;
        pokazKtoRusza(warcaby.aktualnyGracz, warcaby.gr1, warcaby.gr2);
        czyMozliweBicie(warcaby.plansza, warcaby.ruchy, warcaby.aktualnyGracz, byloBicie);
        if(!byloBicie)
        {
            wybraniePionka(warcaby.plansza, warcaby.ruchy, warcaby.aktualnyGracz,w,k);
            menuPionek(warcaby.plansza, warcaby.ruchy,  warcaby.aktualnyGracz,w,k);
            wykonanieRuchu(warcaby.plansza, warcaby.ruchy,w,k,warcaby.aktualnyGracz);
        }
        czyPionekNaKoncu(warcaby.plansza, warcaby.gr1,warcaby.gr2,warcaby.koniecGry);
        czyZbitePionki(warcaby.plansza, warcaby.gr1,warcaby.gr2,warcaby.koniecGry);
        czyZablokowany(warcaby.plansza, warcaby.gr1,warcaby.gr2,warcaby.koniecGry);
        warcaby.aktualnyGracz = warcaby.aktualnyGracz * -1;

    }
    return 0;
}
