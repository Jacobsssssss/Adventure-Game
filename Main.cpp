#include <iostream>
#include <cstdlib>
#include <ctime>
#include <Windows.h>
using namespace std;

int basehealth = 10;
int attack = 0;
int block = 0;
int turns = 0;
int charclass = 4;
int randnum = rand();
int Martialstat[4] = {0,11,6,5}; //Shield, Damage, Health Modifier, armor 
int Swordmaststat[4] = {5,16,4,5};
int Barbstat[4] = {0,16,10,8};
string userinpword;
int Dragstat[3];//Damage, Health, Natural armor
int Shieldopts[3] = {Martialstat[0],Swordmaststat[0],Barbstat[0]};
int Damageopts[3] = {Martialstat[1],Swordmaststat[1],Barbstat[1]};
int Healthopts[3] = {Martialstat[2],Swordmaststat[2],Barbstat[2]};
int armoropts[3] = {Martialstat[3],Swordmaststat[3],Barbstat[3]};
int userinpnumber;
int charhealth;
int armor;
bool Game = false;
bool Round = false;

void Dragoncreate(){
    srand(static_cast<unsigned int>(time(0)));
    int Damage = (randnum % 6) + 4;
    int Health = (randnum % 10) + 10;
    int natarm = (randnum % 6) + 5;
    Dragstat[0] = Damage;
    Dragstat[1] = Health;
    Dragstat[2] = natarm;
}


int main(){
    srand(static_cast<unsigned int>(time(0)));
    cout << "Welcome to Dragons and More Dragons" << endl;
    Sleep(5);
    while (charclass == 4){
        cout << "What Class would you like"<< endl;
        Sleep(5);
        cout<< "1 - Martialist" << endl;
        Sleep(5);
        cout << "2 - Sword Master" << endl;
        Sleep(5);
        cout << "3 - Barbarian" << endl;
        cin >> userinpnumber;
        cout << endl;
        Sleep(5);
        switch (userinpnumber){
        case 1:
            cout << "Your stats as a Martialist will be:" << endl;
            cout << "Armor: " << Martialstat[3] << endl;
            Sleep(2);
            cout << "Health: " << Martialstat[2] + basehealth << endl;
            Sleep(2);
            cout << "Damage: " << Martialstat[1] << endl;
            Sleep(2);
            cout << "Shield: " << Martialstat[0] << endl;
            Sleep(2);
            cout << "would you like to continue?" << endl << "- Yes" << endl << "- No" << endl;
            Sleep(2);
            cin >> userinpword;
            cout << endl;
            if (userinpword == "Yes"){
                charclass = 0;
                break;
            }else if(userinpword == "yes"){
                charclass = 0;
                break;
            }else{
                break;
            }
            case 2: 
            cout << "Your stats as a Sword Master will be:" << endl;
            Sleep(2);
            cout << "Armor: " << Swordmaststat[3] << endl;
            Sleep(2);
            cout << "Health: " << Swordmaststat[2] + basehealth << endl;
            Sleep(2);
            cout << "Damage: " << Swordmaststat[1] << endl;
            Sleep(2);
            cout << "Shield: " << Swordmaststat[0] << endl;
            Sleep(2);
            cout << "would you like to continue?" << endl << "- Yes" << endl << "- No" << endl;
            Sleep(2);
            cin >> userinpword;
            cout << endl;
            if (userinpword == "Yes"){
                charclass = 1;
                break;
            }else if(userinpword == "yes"){
                charclass = 1;
                break;
            }else{
                break;
            }
        case 3:
            cout << "Your stats as a Barbarian will be:" << endl;
            Sleep(2);
            cout << "Armor: " << Barbstat[3] << endl;
            Sleep(2);
            cout << "Health: " << Barbstat[2] + basehealth << endl;
            Sleep(2);
            cout << "Damage: " << Barbstat[1] << endl;
            Sleep(2);
            cout << "Shield: " << Barbstat[0] << endl;
            Sleep(2);
            cout << "would you like to continue?" << endl << "- Yes" << endl << "- No" << endl;
            Sleep(2);
            cin >> userinpword;
            cout << endl;
            if (userinpword == "Yes"){
                charclass = 2;
                break;
            }else if(userinpword == "yes"){
                charclass = 2;
                break;
            }else{
                break;
            }
        default:
            cout << "This class does not exist" << endl;
            Sleep(25);
            break;
        }
    }
    cout << endl;
    charhealth = Healthopts[charclass]+basehealth;
    Sleep(30);
    cout << endl;
    Game = true;
    Sleep(30);
    while (Game == true){
        Dragoncreate();
        Round = true;
        cout << "A dragon has appeared what will you do?" << endl;
        while (Round == true){
            armor = armoropts[charclass];
            srand(static_cast<unsigned int>(time(0)));
            cout << "1 - Attack" << endl;
            if (Shieldopts[charclass] > 0){
            cout << "2 - Shield" << endl;
            cout << "3 - Run/ End Game" << endl;

            }else{
            cout << "2 - Run/ End Game" << endl;
        }
            cin >> userinpnumber;
            cout << endl;
            Sleep(5);
            switch (userinpnumber){
            case 1:
                if (Damageopts[charclass] > Dragstat[2]){
                    Dragstat[1] =- Damageopts[charclass];
                }else{
                    cout << "The scales are strong you dealt half damage." << endl;
                    Dragstat[1] =- Damageopts[charclass]/2;
                }
                break;
            case 2:
                if (Shieldopts[charclass] > 0){
                    cout << "your armor got a boost of " << Shieldopts[charclass] << endl;
                    armor = Shieldopts[charclass] + armoropts[charclass];
                }else{
                    cout << "you ran away" << endl;
                    return(0);
                    break;
                }
                break;
            case 3:
                cout << "you ran away" << endl;
                return(0);
                break;
            default:
                cout << "Please type a shown Number" << endl;
            }
            if (Dragstat[1] <= 0){
                cout << "The Dragon is Dead you win :)" << endl;
                int gainhealth = (randnum % 5) + 3;
                cout << "You found a potion that gave you " << gainhealth << " Health."<< endl;
                charhealth += gainhealth;
                cout << "You have " << charhealth << " health" <<endl;
                Round = false;
                cout << endl;
                cout << endl;
                break;
            }
        
            if (Dragstat[0] >= armor){
                charhealth -= Dragstat[0];
                cout << "you lost " << Dragstat[0] << " Health" <<endl;
            }else{
                charhealth -= Dragstat[0]/2;
                cout << "you lost " << Dragstat[0]/2 << " Health" <<endl;
            }

            if (charhealth <= 0){
                cout << "You died :(" << endl;
                Game = false;
                break;
            }
            cout << "You have " << charhealth << " health" <<endl;
            cout << endl;
            cout << "what will you do?" << endl;
        }
    }
}