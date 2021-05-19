#include <iostream>
#include <time.h>
#include <string.h>

using namespace std;


class Robot{
    public:
        int x;
        int y;
        string order;


        Robot(int absis, int ordinat){
            Robot::x = absis;
            Robot::y = ordinat;
        }

        void ShowCoordinate(){
            if(x<=100 && x >= 0 && y <= 100 && y >= 0){
                cout <<"("<< x <<"," << y << ")" << endl;
            }
            else{
                cout <<"Luar Arena";
            }
        }

        void InputChoice(char choice){ 
            switch (choice){
            case 'W':
                y++;
                break;
            case 'w':
                y++;
                break;
            case 'S':
                y--;
                break;
            case 's':
                y--;
                break;
            case 'D':
                x++;
                break;
            case 'd':
                x++;
                break;
            case 'A':
                x--;
                break;
            case 'a':
                x--;
                break;          
            default:
                cout << "Masukkan salah";
                break;
            }
        ShowCoordinate();
        }

        
        void InitializeCoordinate(){
            x = 0; y = 0;
            ShowCoordinate();
        }

        int RandomizeGenerator(){
            srand(time(NULL));
            return rand()%100 + 1;
        }
        
        void RandomizeCoordinate(){
            while(x < 10){
                int a = RandomizeGenerator();
                x = a;
            }
            while(y < 10){
                int b = RandomizeGenerator();
                y = b;
            }
            if (x <= 100 && x >= 10|| y <= 100 && y >= 10){
                ShowCoordinate();
            }
            else if (x < 10 || y < 10){
                ShowCoordinate();
                cout << "***WARNING! ROBOT AKAN MELEDAK"<< endl;
            }
        }           
};


int main(){
    int x;
    int y;
    int p;
    int q;
    char b;

    cout << "Masukkan Koordinat x: ";
    cin >> x;         
    cout << "Masukkan Koordinat y: ";
    cin >> y;
    Robot robot = Robot(x,y);
    Robot infrared = Robot(p,q);

    robot.ShowCoordinate();
    infrared.InitializeCoordinate();

    while(x>=0 || y >=0){
        cout << "Masukkan perintah: ";
        cin >> b;
        if (b == 'x' || b == 'X'){
            goto end;
        }
        else{
            robot.InputChoice(b);
            infrared.RandomizeCoordinate();
        }
    }
    if(x< 0 || y < 0){
        cout << "ROBOT DIDISKUALIFIKASI!";
    }
    end:
        cout << """ROBOT TERDETERMINASI""";
    return 0;
}
