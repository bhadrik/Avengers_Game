#include<iostream>
#include<iomanip>
using namespace std;
class Villain;
class Hero{
    float health;   //Helth of the hero, if < 0 then dies
    float power_p;    //How powerful punch is, depends upon energy
    float power_k;    //How powerful kick is, depends upon energy
    float energy;   //What is the energy level, dies if < 0
    public:
    Hero(){
        health = 50;
        energy = 50;
        power_p = energy * 9 / 100; //power of punch 8% of energy
        power_k = energy * 10 / 100; //power of kick 10% of energy
    }

    bool live(){
        if(health<=0 || energy<=0)
            return 0;
        else
            return 1;
    }
    void display(){
        cout<<"Iron-Man status"<<endl;
        cout<<"Health: "<<health<<" ";
        for(int i=0;i<health;i++){
            cout<<"#";
        }
        cout<<endl;
        cout<<"Energy: "<<energy<<" ";
        for(int i=0;i<energy;i++){
            cout<<"#";
        }
        cout<<endl;
    }
    friend void punch_h(Hero&,Villain&);
    friend void kick_h(Hero&,Villain&);
    friend void punch_v(Hero&,Villain&);
    friend void kick_v(Hero&,Villain&);
};

class Villain{
    float health;
    float power_p;
    float power_k;
    float energy;
    public:
    Villain(){
        health = 50;
        energy = 50;
        power_p = energy * 7 / 100;   // 7% of energy
        power_k = energy * 11 / 100;    // 11% of energy
    }
    bool live(){
        if(health<=0 || energy<=0)
            return 0;
        else
            return 1;
    }
    void display(){
        cout<<"Thanos status"<<endl;
        cout<<"Health: "<<setw(2)<<health<<" ";
        for(int i=0;i<health;i++){
            cout<<"#";
        }
        cout<<endl;
        cout<<"Energy: "<<energy<<" ";
        for(int i=0;i<energy;i++){
            cout<<"#";
        }
        cout<<endl;
    }
    friend void punch_h(Hero&,Villain&);
    friend void kick_h(Hero&,Villain&);
    friend void punch_v(Hero&,Villain&);
    friend void kick_v(Hero&,Villain&);
};

    void punch_h(Hero& h1,Villain& v1){   //Hero punch to villain 9
        h1.energy-=3;
        v1.health-=h1.power_p;
    }
    void kick_h(Hero& h1,Villain& v1){    //Hero kick to villain 10
        h1.energy-=4;
        v1.health-=h1.power_k;
    }
    void punch_v(Hero& h1,Villain& v1){   //villain punch to hero 7
        v1.energy-=3;
        h1.health-=v1.power_p;
    }
    void kick_v(Hero& h1,Villain& v1){    //villain kick to hero 11
        v1.energy-=5;
        h1.health-=v1.power_k;
    }

int main(){
    Hero iron_man;
    Villain thanos;
    int turn=1;
    int choose;
    cout<<"+-------------------How To Play--------------------+"<<endl
        <<"|    1-->punch, 2-->kick and 0-->display status    |"<<endl
        <<"+--------------------------------------------------+"<<endl<<endl;

    iron_man.display();
            cout<<endl;
            thanos.display();
            cout<<endl<<endl;

    while(iron_man.live() && thanos.live()){
        if(turn%2==0)  cout<<"It\'s Iron Man's turn"<<endl;
        else cout<<"It\'s Thanos's turn"<<endl;
        cout<<"Punch, Kick or display : "; cin>>choose;
        cout<<endl;

        switch (choose){
        case 1:
            if(turn%2==0)
                punch_h(iron_man,thanos);//hero
            else
                punch_v(iron_man,thanos); //Villain
            turn++;
            break;
        case 2:
            if(turn%2==0)
                kick_h(iron_man,thanos);//hero
            else
                kick_v(iron_man,thanos); //Villain
            turn++;
            break;
        case 0:
            iron_man.display();
            cout<<endl;
            thanos.display();
            cout<<endl;
            break;
        default:
            cout<<"Please enter valid input"<<endl;
        }

        if(!iron_man.live()){
            cout<<endl;
            iron_man.display();
            cout<<endl;
            thanos.display();
            cout<<endl;

            cout<<"GAME OVER"<<endl;
            cout<<"================\n";
            cout<<"Ohh... Thanos won\n";
            cout<<"================\n";
        }
        else if(!thanos.live()){
            cout<<endl;
            iron_man.display();
            cout<<endl;
            thanos.display();
            cout<<endl;

            cout<<"GAME OVER"<<endl;
            cout<<"================\n";
            cout<<"Yehhh, Iron man won\n";
            cout<<"================\n";
        }
    }
    char ch;
    cin.get(ch);
    cin.get(ch);
    cin.get(ch);
    cin.get(ch);
}
