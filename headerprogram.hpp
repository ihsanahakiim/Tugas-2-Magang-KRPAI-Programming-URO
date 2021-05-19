#ifndef HEADERPROGRAM_H
#define HEADERPROGRAM_H
#include <iostream>
#include <ctime>


using namespace std;


class Robot{ //Deklarasi OOP
    private: 
        int x; //Variabel koordinat disimpan secara private
        int y;
        int Muhammad_Ihsan_Abdul_Hakim = 16020129;
    
    public: //Function berparamater dan tidak berparameter disimpan secara publik agar accessible
        Robot(int absis, int ordinat){ // constructor
            Robot::x = absis;
            Robot::y = ordinat;
        }

        void ShowCoordinate(){ // menunjukkan posisi koordinat robot maupun infrared
            if (x >= 0 && y >= 0){
                cout <<"("<< x <<"," << y << ")" << endl;
            }
            else if (x < 0 || y < 0){ // string ketika robot di luar zona positif
                cout << "---ROBOT DIDISKUALIFIKASI!---" << endl;
                cout << "---SILAKAN MATIKAN SISTEM---" << endl;
                cout << "\n";
                exit;
            }                               
        }    

        void InputChoice(char choice){  //operasi program penerima inputan pergeseran robot
            switch (choice){
            case 'W': // Tekan W sehingga robot maju
                y++;
                break;
            case 'w': // Tekan w sehingga robot maju
                y++;
                break;
            case 'S': // Tekan S sehingga robot mundur
                y--;
                break;
            case 's': // Tekan S sehingga robot mundur
                y--;
                break;
            case 'D': // Tekan D sehingga robot bergeser ke kanan
                x++;
                break;
            case 'd': // Tekan d sehingga robot bergeser ke kanan
                x++;
                break;
            case 'A': // Tekan A sehingga robot bergeser ke kiri
                x--;
                break;
            case 'a': // Tekan a sehingga robot bergeser ke kiri
                x--;
                break;          
            default:
                cout << "Masukan salah"; // String peringatan inputan salah
                cout << "\n";
                break;
            }
        }
        
        void InitializeCoordinate(){ // Inisiasi koordinat inframerah
            x = 0; y = 0;
        }
        
        void RandomizeCoordinate(){ // Program pengacakan koordinat acak dari 1 sampai 100 
            srand(time(NULL)); 
            x = rand() %100+1; 
            y = rand() %100+1;        
            if(x>= 10 && y >= 10){
            }
        exit;
        }
        
        void Warning(){ // Program pengirim string peringatan sensor inframerah
            if (x < 10 || y < 10){
            cout << "***ALERT! ROBOT AKAN MENABRAK***"<< endl;
            }
        }

        int horizontal = x;
        int vertikal = y;
};        
void Instruction(){ // function berupa string petunjuk pengisian input
    cout <<"\n----------PETUNJUK-------------";
    cout <<"\nInput menerima perintah berupa:";
    cout << "\nW untuk maju";
    cout << "\nS untuk mundur";
    cout << "\nD untuk ke kanan";
    cout << "\nA untuk ke kiri";
    cout << "\nX untuk mendeterminasi program";
    cout << "\nKoordinat atas merupakan posisi robot";
    cout << "\nKoordinat bawah merupakan posisi robot";
    cout << "\n" << endl;
}

void Crash(int x, int y, int p, int q){ // posisi robot dan objek terdeteksi sensor sama
    if(x==p || y == q){
        cout << "~~~ROBOT MENABRAK~~~";
    }
}

#endif
