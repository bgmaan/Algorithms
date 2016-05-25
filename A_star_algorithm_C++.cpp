#include <iostream>
#include <math.h>
#include <iomanip>
#include <vector>
using namespace std;

 int plansza[10][10] =
{
{ 0,0,0,0,0,0,0,0,5,5 },
{ 0,0,5,0,0,0,0,0,0,0 },
{ 0,0,5,0,0,0,0,0,0,5 },
{ 0,0,5,0,0,0,0,0,0,0 },
{ 0,0,5,5,5,0,0,0,0,0 },
{ 0,0,0,0,0,5,0,0,0,0 },
{ 0,0,0,0,0,5,5,5,5,5 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
{ 0,0,0,0,0,0,0,0,0,0 },
};
int poczX = 1;
int poczY = 9;
int kolX;
int kolY;
int celX  = 9;
int celY  = 0;
bool zakoncz = false;
vector< vector<double> > tabOtw;
vector< vector<double> > tabZam;

void wypiszOtwarte() {

cout<<"Tablica otwarte"<<endl;
for (int i=0; i<tabOtw.size(); ++i) {
           for (int j=0; j<5; ++j) {
             std::cout << "  "<< tabOtw[i][j];

                       }
                       cout<<endl;}
//wypisz zamkniete

cout<<"_____________________"<<endl;

}

int obliczKoszt (int pozrX, int pozrY,int index,int koszt) {




           for(int i=index;i>-1;i--) {

            if (tabZam[i][0]==pozrX && tabZam[i][1]==pozrY) {
             if(pozrX==2 && pozrY==1) {
                 koszt++;
                break;

            }
            pozrX = tabZam[i][2];
            pozrY = tabZam[i][3];

            koszt +=1;
            }
            else {

            }
            }
 return koszt;
}

void wypiszZamkniete() {


for (int i=0; i<tabZam.size(); ++i) {
           for (int j=0; j<5; ++j) {
             std::cout << "  "<< tabZam[i][j];

                       }
                       cout<<endl;}

}


double obliczH (int pozX,int pozY,int pozrX,int pozrY ) {

    double koszt;

    koszt = obliczKoszt(pozrX,pozrY,tabZam.size()-1,0);

    double wynikH = koszt + sqrt(pow((pozY-celY),2)+pow((pozX-celX),2));


    return wynikH;
}


void dodajZamkniete(double zamX,double zamY,double zamrX,double zamrY,double h) {
       std::vector<double> nowyZam;
       nowyZam.push_back(zamX);
       nowyZam.push_back(zamY);
       nowyZam.push_back(zamrX);
       nowyZam.push_back(zamrY);
       nowyZam.push_back(h);
       tabZam.push_back(nowyZam);

}
void wybierzOtwarte() {

if(tabOtw.size()==0) {

    zakoncz = true;

}
else
{


double hNaj = tabOtw[tabOtw.size()-1][4];
double indexNaj = tabOtw.size()-1;


for(int i = tabOtw.size()-1; i>-1; i-- ) {

     if(tabOtw[i][4]<hNaj) {
        hNaj = tabOtw[i][4];
        indexNaj = i;

     }




}
dodajZamkniete(tabOtw[indexNaj][0],tabOtw[indexNaj][1],tabOtw[indexNaj][2],tabOtw[indexNaj][3],tabOtw[indexNaj][4]);
tabOtw.erase(tabOtw.begin()+indexNaj);
}
}

bool sprawdzZamkniete(int sprX,int sprY) {
 bool czyZnaleziono;
 int i = 0;

czyZnaleziono = false;
   for (int i=tabZam.size()-1; i>-1; i--) {

             if(tabZam[i][0]==sprX && tabZam[i][1]==sprY) {

                czyZnaleziono = true;
                break;
             }
                    cout<<endl;}

  return czyZnaleziono;

}

bool sprawdzOtwarte(int sprX,int sprY) {
 bool czyZnaleziono;
 int i = 0;



czyZnaleziono = false;
   for (int i=tabOtw.size()-1; i>-1; i--) {
             if(tabOtw[i][0]==sprX && tabOtw[i][1]==sprY) {
                czyZnaleziono = true;
                break;
             } cout<<endl;}

  return czyZnaleziono;


}

void znajdzOtwarte(int pozX,int pozY) {




//lewy
  if(pozY>0 && plansza[pozX][pozY-1]!= 5 && sprawdzZamkniete(pozX,pozY-1)!=true && sprawdzOtwarte(pozX,pozY-1)!=true) {


     //dodawanie do otwartych

       std::vector<double> nowyOtwarty;

       nowyOtwarty.push_back(pozX);
       nowyOtwarty.push_back(pozY-1);
        nowyOtwarty.push_back(pozX);
        nowyOtwarty.push_back(pozY);
        double h = obliczH(pozX,pozY-1,pozX,pozY);
        nowyOtwarty.push_back(h);
        tabOtw.push_back(nowyOtwarty);
  }
//dol
 if(pozX<9 && plansza[pozX+1][pozY]!= 5 && sprawdzZamkniete(pozX+1,pozY)!=true &&sprawdzOtwarte(pozX+1,pozY)!=true ) {


     //dodawanie do otwartych
       std::vector<double> nowyOtwarty;

       nowyOtwarty.push_back(pozX+1);
       nowyOtwarty.push_back(pozY);
        nowyOtwarty.push_back(pozX);
        nowyOtwarty.push_back(pozY);
        double h = obliczH(pozX+1,pozY,pozX,pozY);
        nowyOtwarty.push_back(h);
        tabOtw.push_back(nowyOtwarty);
  }
//prawy
 if(pozY<9 && plansza[pozX][pozY+1]!= 5 && sprawdzZamkniete(pozX,pozY+1)!=true && sprawdzOtwarte(pozX,pozY+1)!=true ) {


     //dodawanie do otwartych
     std::vector<double> nowyOtwarty;

       nowyOtwarty.push_back(pozX);
       nowyOtwarty.push_back(pozY+1);
        nowyOtwarty.push_back(pozX);
        nowyOtwarty.push_back(pozY);
        double h = obliczH(pozX,pozY+1,pozX,pozY);
        nowyOtwarty.push_back(h);
        tabOtw.push_back(nowyOtwarty);
  }

//gora
 if(pozX>0 && plansza[pozX-1][pozY]!= 5 && sprawdzZamkniete(pozX-1,pozY)!=true &&sprawdzOtwarte(pozX-1,pozY)!=true) {


     //dodawanie do otwartych
     std::vector<double> nowyOtwarty;

       nowyOtwarty.push_back(pozX-1);
       nowyOtwarty.push_back(pozY);
        nowyOtwarty.push_back(pozX);
        nowyOtwarty.push_back(pozY);
        double h = obliczH(pozX-1,pozY,pozX,pozY);
        nowyOtwarty.push_back(h);
        tabOtw.push_back(nowyOtwarty);
  }


}


int main()
{

// stworz tablice z plansza
plansza[poczX][poczY] = 3;


for(int i =0;i<10;i++) {

    for(int j =0;j<10;j++) {
    cout <<plansza[i][j]<<"\t";

}
cout<<endl;
cout<<endl;

}
cout<<"________________________________________________"<<endl;
//dodaj poczatek do zamknietych

dodajZamkniete(poczX,poczY,poczX,poczY,0);
//pêtla

for(int i = 0; i>-1;i++) {




kolX = tabZam[tabZam.size()-1][0];
kolY = tabZam[tabZam.size()-1][1];

if(kolX==celX && kolY==celY) {
    break;
}

if(zakoncz==true) {
    break;
}
znajdzOtwarte(kolX,kolY);

wybierzOtwarte();

cout<<endl;
cout<<endl;
cout<<endl;

}

cout<<"_________________________________________________________"<<endl;
if(zakoncz==true) {
    cout<<"Nie ma trasy!"<<endl;
}


int porrX,porrY;

porrX = kolX;
porrY = kolY;

if(zakoncz!=true) {
cout<<"OTO TWOJA TRASA"<<endl;
cout<<endl;
for(int i=tabZam.size()-1;i>-1;i--) {


            if (tabZam[i][0]==porrX && tabZam[i][1]==porrY) {

             if(porrX==poczX && porrY==poczY ) {

                break;

            }
            plansza[porrX][porrY] = 3;
            porrX = tabZam[i][2];
            porrY = tabZam[i][3];
            }
            else {

            }
}

   for(int i =0;i<10;i++) {

    for(int j =0;j<10;j++) {
    cout <<plansza[i][j]<<" "<<"\t";

}
cout<<endl;
cout<<endl;
   }
cout<<endl;
cout<<endl;


}
    return 0;
}




