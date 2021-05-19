#include <iostream>
#include <ctime>
#include "headerprogram2.hpp"

using namespace std;

int main(){ // Main Programm
    int x,y,p,q; // global int
    char b; // deklarasi char

    // Menerima input koordinat integer
    cout << "Masukkan Koordinat x: ";
    cin >> x;         
    cout << "Masukkan Koordinat y: ";
    cin >> y;
    Robot robot = Robot(x,y);
    Robot infrared = Robot(p,q);

    infrared.InitializeCoordinate();
    Instruction();
    while(x>= 0 || y >= 0){ // kondisi looping while
        robot.ShowCoordinate();
        if (x >= 0 && y >= 0){ 
            infrared.ShowCoordinate();
        }
        else if(x < 0 || y < 0){
            exit;
        }
        cout << "\n";
        cout << "Masukkan perintah: ";
        cin >> b;
        if (b == 'x' || b == 'X'){ // kondisi ketika inputan menerima karakter 'x' atau 'X
            goto turnoff; //penunjuk arah program setelah terpenuhinya kondisi
        }
        else{
            robot.InputChoice(b);
            infrared.RandomizeCoordinate();
            infrared.Warning();
            Crash(robot.horizontal,robot.vertikal,infrared.horizontal,infrared.vertikal);
        }
    }
    turnoff: //program dihentikan setelah ditekannya huruf X
        cout << "||ROBOT TERDETERMINASI||" << endl;
        cout << "\n";
    return 0;
}