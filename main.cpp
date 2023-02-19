#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // for system()
#include <ctime>   // for time() in srand( time(NULL) );
#include <iomanip> // for setw()
using namespace std;

class Mars
{
private:
    vector<vector<char>> map_; // convention to put trailing underscore
    int dimX_, dimY_;          // to indicate private data
public:
    int dimX, dimY;
    Mars(int dimX = 15, int dimY = 5, int setnozombie=1); //Size of Mars Rows and Columns
    void init(int dimX, int dimY, int setnozombie);
    void display(int &dimX, int &dimY);
    void DefaultMenu();
    void helpguide();
    void MatchStart();
    void setObject4(int col, int row) ;
    void boardsetting(int dimX, int dimY,int setnozombie);

    void setObject3(int col, int row, char object);
    int getDimX();
    int getDimY();
    char getObject(int col, int row);
    void setObject(int col, int row, char object);
    void setObject(int col, int row, int dimY, char ch);
    void setObject2(int col, int row);
    bool isEmpty(int o,int q);
};

int Pause()
    {
        #if defined(_WIN32)
            return std::system("pause");
        #elif defined(linux) || defined(APPLE)
            return std::system(R"(read -p "Press any key to continue . . . " dummy)");
        #endif
    }

int ClearScreen()
    {
        #if defined(_WIN32)
            return std::system("cls");
        #elif defined(linux) || defined(APPLE)
            return std::system("clear");
        #endif
    }

// class zombie
// {
// private:
//     int dimY,dimX,setnozombie;
// public:
//     zombie();
//     int  getzomY(int dimY);
//     int  getzomX(int dimX);
//     int  getnoz(int setnozombie);
// };

//Zombie Class
class Zombie
{
private:
    int zx, zy;
    char zheading;
public:
    Zombie();
    void ground(Mars &mars);
    void grounds(Mars &mars);
    int getZX() const;
    int getZY() const;
    char Zheading() const;
    void moveUp(Mars &mars);
    void moveDown(Mars &mars);
    void moveRight(Mars &mars);
    void moveLeft(Mars &mars);
};

Zombie::Zombie()
{
}

void Zombie::ground(Mars &mars)
{
    char zombheading[] = {'Z'};

    zx = rand() % mars.getDimX() + 1;
    zy = rand() % mars.getDimY() + 1;
    zheading = zombheading[0];
    mars.setObject(zx, zy, zheading);
}

//Zombie movement
void Zombie::moveUp(Mars &mars)
{
    Zombie charlie;
    mars.setObject4(zx, zy);
    char zombheading[] = {'Z'};
    zx;
    zy++;
    
    if(zy>5)
    {
            zx;
            zy--;
            int random_move = (rand() % 3);
            if (random_move == 0)
            {
                char zombheading[] = {'Z'};
                zx;
                zy--;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 1)
            {
                char zombheading[] = {'Z'};
                zx--;
                zy;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 2)
            {
                char zombheading[] = {'Z'};
                zx++;
                zy;
                mars.setObject3(zx, zy, zheading);
            }

    }
    if(zy<=5)
    {
            mars.setObject3(zx, zy, zheading);
    }

}

void Zombie::moveDown(Mars &mars)
{
    Zombie charlie;
    mars.setObject4(zx, zy);
    char zombheading[] = {'Z'};
    zx;
    zy--;
    
    if(zy<=0)
    {   
            zx;
            zy++;
            int random_move = (rand() % 3);           

            if (random_move == 0)
            {
                    char zombheading[] = {'Z'};
                    zx;
                    zy++;
                    mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 1)
            {
                char zombheading[] = {'Z'};
                zx--;
                zy;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 2)
            {
                char zombheading[] = {'Z'};
                zx++;
                zy;
                mars.setObject3(zx, zy, zheading);
            }
            

    }
    if(zy>0)
    {
            mars.setObject3(zx, zy, zheading);
    }
}

void Zombie::moveLeft(Mars &mars)
{
    Zombie charlie;
    mars.setObject4(zx, zy);
    char zombheading[] = {'Z'};
    zx--;
    zy;
    if(zx<0)
    {       
            zx++;
            zy;
            int random_move = (rand() % 3);
            if (random_move == 0)
            {
                char zombheading[] = {'Z'};
                zx;
                zy--;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 1)
            {
                char zombheading[] = {'Z'};
                zx;
                zy++;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 2)
            {
                char zombheading[] = {'Z'};
                zx++;
                zy;
                mars.setObject3(zx, zy, zheading);
            }

    }
    if(zx>=0)
    {
            mars.setObject3(zx, zy, zheading);
    }
}

void Zombie::moveRight(Mars &mars)
{
    Zombie charlie;
    mars.setObject4(zx, zy);
    char zombheading[] = {'Z'};
    zx++;
    zy;
    if(zx>15)
    {   
            zx--;
            zy;
            int random_move = (rand() % 3);
            
            if (random_move == 0)
            {
                char zombheading[] = {'Z'};
                zx;
                zy--;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 1)
            {
                char zombheading[] = {'Z'};
                zx--;
                zy;
                mars.setObject3(zx, zy, zheading);
            }
            if (random_move == 2)
            {
                char zombheading[] = {'Z'};
                zx;
                zy++;
                mars.setObject3(zx, zy, zheading);
            }

    }
    if(zx<=15)
    {
            mars.setObject3(zx, zy, zheading);
    }
}

int Zombie::getZX() const
{
    return zx;
}

int Zombie::getZY() const
{
    return zy;
}

char Zombie::Zheading() const
{
    return zheading;
}

/*void test2_1()
{
    int dimX_ = 15;
    int dimY_ = 5;
    Mars mars;
    Zombie charlie;
    charlie.ground(mars);
    mars.display(dimX_, dimY_);
    cout << "Status of the zombie:" << endl
    << "    Location: (" << charlie.getZX() << "," << charlie.getZY() << ")"
    << endl
    << "    Heading: " << charlie.Zheading() << endl;


}
*/
class Alien
{
private:
    int x_, y_;
    char heading_; // either '^', '>', '<' or 'v'
public:
    Alien();
    void land(Mars &mars);
    void moveUp(Mars &mars);
    void moveRight(Mars &mars);
    void moveLeft(Mars &mars);
    void moveDown(Mars &mars);
    int getX() const;
    int getY() const;
    char getHeading() const;
};

Alien::Alien()
{
}

void Alien::land(Mars &mars)
{
    char possibleHeading[] = {'A'};

    x_ =  (mars.getDimX() - 1)/2;
    y_ =  (mars.getDimY() + 1)/2;
    heading_ = possibleHeading[0];

    mars.setObject(x_, y_, heading_);
}

void Alien::moveRight(Mars &mars)
{
    mars.setObject2(x_,y_);
    char possibleHeading[] = {'A'};
    x_++;
    y_;
    heading_ = possibleHeading[0];
    mars.setObject(x_, y_, heading_);
}

void Alien::moveUp(Mars &mars)
{
    mars.setObject2(x_,y_);
    char possibleHeading[] = {'A'};
    x_;
    y_++;
    heading_ = possibleHeading[0];

    mars.setObject(x_, y_, heading_);
}

void Alien::moveLeft(Mars &mars)
{
    mars.setObject2(x_,y_);
    char possibleHeading[] = {'A'};
    x_--;
    y_;
    heading_ = possibleHeading[0];

    mars.setObject(x_, y_, heading_);
}

void Alien::moveDown(Mars &mars)
{
    mars.setObject2(x_,y_);
    char possibleHeading[] = {'A'};
    x_;
    y_--;
    heading_ = possibleHeading[0];
    mars.setObject(x_, y_, heading_);
}


int Alien::getX() const
{
    return x_;
}

int Alien::getY() const
{
    return y_;
}

char Alien::getHeading() const
{
    return heading_;
}


// bool Mars::isEmpty(int o,int q)
// {
//     Mars mars;
//     Alien curiosity;
    
//     // cout << "o= "<< o<< " q= "<<q<<endl;
//     if(map_[5-o][q-1] == 'v')
//     {
//         cout << "o= "<< o<< " q= "<<q<<endl;
//         cout << "\ndamn" << endl; 
//         q = curiosity.getX();
//         o = curiosity.getY();
//         return 0;
        
//     }
//     else
//     {
//         cout << o;
//         cout << "bruh" << q << endl;

//         return 1;
//         //continue;  
//     } 
            
//     }  

void Mars::MatchStart() //Control the movement of the alien
{
    int dimX_, dimY_;
    void helpguide();
    
    srand(1);
    Mars mars;
    Alien curiosity;
    Zombie charlie;
    int q;
    int o;
    int zx;
    int zy;
    char Z;
    int health = 100;
    int alien_attack = 0;

    //zombie attributes
    int zomb_health = 100;
    int zomb_attack = 20;

    charlie.ground(mars);
    curiosity.land(mars);
    mars.display(dimX_, dimY_);
    cout <<"Alien:  Health: " << health << " " << "Attack: " << alien_attack << endl;
    cout <<"Zombie: Health: " << zomb_health << " " << "Attack: " << zomb_attack << endl;
    char choice;
    char command;
    q = curiosity.getX();
    o = curiosity.getY();
    zx = charlie.getZX();
    zy = charlie.getZY();
    Z = charlie.Zheading();
    int dimSum = 5;
    cout << "Command: ";
    do
    {
        cin >> choice;
        choice = toupper(choice);
        switch(choice)
        {
        case 'U':
            //charlie.moveUp(mars);
            //zx = charlie.getZX();
            //zy = charlie.getZY();
            //Randomize alien movement test
            {
            int random_move = (rand() % 4);
            zx = charlie.getZX();
            zy = charlie.getZY();
            if (random_move == 0)
            {
                charlie.moveUp(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                //PLEASE WORK [ALIEN RANGE 1 ATTACK TEST]
                /*if(map_[zx][zy + 1] == 'A')
                {
                    zx = charlie.getZX();
                    zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 1)
            {
                charlie.moveDown(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx][zy - 1] == 'A')
                {
                    zx = charlie.getZX();
                    zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 2)
            {
                charlie.moveLeft(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx - 1][zy] == 'A')
                {
                    zx = charlie.getZX();
                    zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 3)
            {
                charlie.moveRight(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx + 1][zy] == 'A')
                {
                    zx = charlie.getZX();
                    zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            }
            //Test Range between Alien and Zombie
            /*do
            {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zx - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zy - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
            } while (health>=100);
            */
            //Testing to move the alien one step at the time
            for (int i=o; i < 5 ;i++)
            {
                curiosity.moveUp(mars);
                q = curiosity.getX();
                o = curiosity.getY();
                if(map_[dimSum - o][q-1] == 'v')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='<')
                {   
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                 }
                if(map_[dimSum - o][q-1] == '>')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='^')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'h')
                { 
                    cout << "Alien founds a health pack! 20 health points has been to Alien" << endl;
                    health = health + 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum-o][q-1] == 'Z')
                {
                    do
                {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zx - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zy - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                } while (health>=100);
                    //zx=charlie.getZX();
                    //zy=charlie.getZY();
                    //health -= 20;
                    cout<<"zombie bro"<<endl;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'r')
                {
                    cout << "Alien stumbled a Rock, Alien discovered a Pod!" << endl;
                    cout << "Pod has been used by Alien to inflict damage on Zombie" << endl;
                    alien_attack += 10;
                    zomb_health -= alien_attack;
                    if (zomb_health <= 0)
                    {
                        cout << "Game Over: Alien Wins! " << endl;
                        abort();
                    }
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'p')
                { 
                    cout << "A pod has been found by Alien, Damage is inflicted on Zombies" << endl;
                    alien_attack += 10;
                    zomb_health =zomb_health -alien_attack;
                    if (zomb_health < 0)
                    {
                        char zombheading[] = {' '};
                        char zheading = zombheading[0];
                        mars.setObject3(zx, zy, zheading);
                        cout << "Game Over: Alien wins! " << endl;
                        abort();
                    }
                    cout<<"You're finish"<<endl;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                else
                {
                    q = curiosity.getX();
                    o = curiosity.getY();
                    continue;  
                } 
            }
            mars.display(dimX_, dimY_);
            q = curiosity.getX();
            o = curiosity.getY();
            cout <<"Alien:  Health: " << health << " " << "Attack: " << alien_attack << endl;
            cout <<"Zombie: Health: " << zomb_health << " " << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            
            break;
//CASE ALIEN MOVE DOWN
        case 'D':
            //charlie.moveDown(mars);
            //zx = charlie.getZX();
            //zy = charlie.getZY();
            //random alien movement test
            {
            int random_move = (rand() % 4);
            zx = charlie.getZX();
            zy = charlie.getZY();
            if (random_move == 0)
            {
                charlie.moveUp(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx][zy + 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 1)
            {
                charlie.moveDown(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 2)
            {
                charlie.moveLeft(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx - 1][zy] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 3)
            {
                charlie.moveRight(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx + 1][zy] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            }
            //Test Range between Alien and Zombie
            /*do
            {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zy - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zx - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
            } while (health>=100);
            */
            //
            for (int i=o; i > 1 ;i--)
            {
                curiosity.moveDown(mars);
                q = curiosity.getX();
                o = curiosity.getY();
                if(map_[dimSum - o][q-1] == 'v')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='<')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == '>')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='^')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    cout<<"pls";
                    cout<<o<<"."<<q;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'h')
                { 
                    cout << "Alien founds a health pack! 20 health points has been to Alien" << endl;
                    health = health + 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='p')
                {
                    cout << "A pod has been found by Alien, Damage is inflicted on Zombies" << endl;
                    alien_attack += 10;
                    zomb_health =zomb_health- alien_attack;
                    if (zomb_health <= 0)
                    {
                        char zombheading[] = {' '};
                        char zheading = zombheading[0];
                        mars.setObject3(zx, zy, zheading);
                        cout << "Game Over: Alien Wins! " << endl;
                        abort();
                    }
                    cout<<"walao";
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'r')
                { 
                    cout << "Alien stumbled a Rock, Congratulations! Alien discovered nothing" << endl;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if(map_[dimSum-o][q-1] == 'Z')
                { 
                    do
                {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zx - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zy - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                } while (health>=100);
                    //zx=charlie.getZX();
                    //zy=charlie.getZY();
                    //health -= 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                else
                {
                    // cout<<o<<","<<q<<endl;
                    continue;  
                }
            }
            mars.display(dimX_, dimY_);
            q = curiosity.getX();
            o = curiosity.getY();
            cout <<"Alien: Health: " << health << " " << "Attack: " << alien_attack << endl;
            cout <<"Zombie: Health: " << zomb_health << " " << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            break;
        //CASE ALIEN MOVE LEFT
        case 'L':
            //charlie.moveLeft(mars);
            //zx = charlie.getZX();
            //zy = charlie.getZY();
            //random alien movement test
            {
            int random_move = (rand() % 4);
            zx = charlie.getZX();
            zy = charlie.getZY();
            if (random_move == 0)
            {
                charlie.moveUp(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                //if(map_[zx][zy + 1] == 'A')
                //{
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                //}
            }
            if (random_move == 1)
            {
                charlie.moveDown(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 2)
            {
                charlie.moveLeft(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx - 1][zy] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 3)
            {
                charlie.moveRight(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[zx + 1][zy] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            }
            //Test Range between Alien and Zombie
            /*do
            {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zy - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zx - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
            } while (health>=100);
            */
            // curiosity.moveLeft(mars);
            // q = curiosity.getX();
            // o = curiosity.getY();
            // mars.isEmpty(o,q);
            for (int i=q;i>1;i--)
            {
            curiosity.moveLeft(mars);
            q = curiosity.getX();
            o = curiosity.getY();
            // if (mars.isEmpty(o,q) == 0)
            // {
            //     break;
            // }
            // else
            // {
            //     curiosity.moveLeft(mars);
            //     continue;
            // }
                if(map_[dimSum - o][q-1] == 'v')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='<')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == '>')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='^')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    cout << "pls";
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'h')
                { 
                    cout << "Alien founds a health pack! 20 health points has been to Alien" << endl;
                    health = health + 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='p')
                {
                    cout << "A pod has been found by Alien, Damage is inflicted on Zombies" << endl;
                    alien_attack += 10;
                    zomb_health =zomb_health- alien_attack;
                    if (zomb_health <= 0)
                    {
                        char zombheading[] = {' '};
                        char zheading = zombheading[0];
                        mars.setObject3(zx, zy, zheading);
                        cout << "Game Over: Alien wins! " << endl;
                        abort();
                    }
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'r')
                {
                    cout << "Alien stumbled a Rock, Alien discovered a Pod!" << endl;
                    cout << "Pod has been used by Alien to inflict damage on Zombie" << endl;
                    alien_attack += 10;
                    zomb_health -= alien_attack;
                    if (zomb_health <= 0)
                    {
                        cout << "Game Over: Alien Wins! " << endl;
                        abort();
                    } 
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if(map_[dimSum-o][q-1] == 'Z') //testing
                { 
                    do
                {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zx - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zy - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                } while (health>=100);
                    //zx=charlie.getZX();
                    //zy=charlie.getZY();
                    //health -= 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                else
                {
                    continue;  
                }         
            }
            mars.display(dimX_, dimY_);
            //cout << curiosity.getY() << "," << curiosity.getX() << ' ';
            cout <<"Alien: Health: " << health << " " << "Attack: " << alien_attack << endl;
            cout <<"Zombie: Health: " << zomb_health << " " << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            q = curiosity.getX();
            o = curiosity.getY();
            break;
            
//CASE ALIEN MOVE RIGHT
        case 'R':
            //charlie.moveRight(mars);
            //zx = charlie.getZX();
            //zy = charlie.getZY();
            //random alien movement test 
            {
            int random_move = (rand() % 4);
            zx = charlie.getZX();
            zy = charlie.getZY();
            if (random_move == 0)
            {
                charlie.moveUp(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[dimSum - zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 1)
            {
                charlie.moveDown(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[dimSum - zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 2)
            {
                charlie.moveLeft(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[dimSum - zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            if (random_move == 3)
            {
                charlie.moveRight(mars);
                zx = charlie.getZX();
                zy = charlie.getZY();
                /*if(map_[dimSum - zx][zy - 1] == 'A')
                {
                    //zx = charlie.getZX();
                    //zy = charlie.getZY();
                    health -= 20;
                }*/
            }
            }
            //Test Range between Alien and Zombie
            /*do
            {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zy - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zx - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
            } while (health>=100);*/
            for (int i=q;i<15;i++)
            {
                curiosity.moveRight(mars);
                q = curiosity.getX();
                o = curiosity.getY();
                if(map_[dimSum - o][q-1] == 'v')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1]=='<')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == '>')
                { 
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum - o][q-1] == '^')
                {
                    cout << "Alien found an arrow, 20 attack damage has been added to Alien" << endl;
                    alien_attack += 10;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'h')
                { 
                    cout << "Alien founds a health pack! 20 health points has been to Alien" << endl;
                    health = health + 20;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if (map_[dimSum-o][q-1]== 'Z')
                {
                    do
                {
                q = curiosity.getX();
                o = curiosity.getY();
                zy = charlie.getZY();
                zx = charlie.getZX();
                int x_range = zx - q;
                if (x_range >= 1 || x_range <= 5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                int y_range = zy - o;
                if (y_range >= 1 ||y_range <=5)
                {
                    cout << "Zombie attacked Alien" << endl;
                    health -= 20;
                }
                else
                {
                    health += 0;
                }
                } while (health>=100);
                    //zx=charlie.getZX();
                    //zy=charlie.getZY();
                    //health -= 20;
                    q=curiosity.getX();
                    o=curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'r')
                { 
                    cout << "Alien stumbled a Rock, Congratulations! Alien discovered nothing" << endl;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                if(map_[dimSum - o][q-1] == 'p')
                { 
                    cout << "A pod has been found by Alien, Damage is inflicted on Zombies" << endl;
                    alien_attack += 10;
                    zomb_health =zomb_health- alien_attack;
                    if (zomb_health <= 0)
                    {
                         char zombheading[] = {' '};
                        char zheading = zombheading[0];
                        mars.setObject3(zx, zy, zheading);
                        cout << "Game Over: Alien wins! " << endl;
                        abort();   
                    }
                    cout <<"pee"<<endl;
                    q = curiosity.getX();
                    o = curiosity.getY();
                    break;
                }
                else
                {
                    continue;  
                }
            }
            mars.display(dimX_, dimY_);
            cout <<"Alien: Health: " << health << " " << "Attack: " << alien_attack << endl;
            cout <<"Zombie: Health: " << zomb_health << " " << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            q = curiosity.getX();
            o = curiosity.getY();
            break;

        case 'Q':
            cout << "Quitting game....."<<endl;
            Pause();
            abort();
            break;

        case 'H':
            cout << "Showing game control......." << endl;
            Pause();
            helpguide();
            mars.display(dimX_, dimY_);
            cout << "Command: ";
            break;

        default:
            cout << "Please insert correct input"<< endl;
            cout << "Type 'H' for the guidance of the movement control" <<endl;
            Pause();
            cout << "Command: ";
            break;
    }
    }while(true);
}



// zombie::zombie()
// {
// }
// int getzomY(int dimY)
// {
//     return dimY;
// }
// int getzomX(int dimX)
// {
//     return dimX;
// }
// int getsetz(int setnozombie)
// {
//     return setnozombie;
// }
// void Rover::land(zombie &zombies)
// {
//     Mars mars;
//     char possibleHeading[] = {'A'};
//     int dimX;
//     int dimY;
//     x_ =  (zombies.getzomX(dimX) - 1)/2;
//     y_ =  (zombies.getzomY(dimY) + 1)/2;
//     heading_ = possibleHeading[0];
//     mars.setObject(x_, y_, heading_);
// }



void Mars::setObject(int col, int dimY, int row, char ch)
{
    map_[dimY - row][col - 1] = ch;
}

Mars::Mars(int dimX, int dimY, int setnozombie)
{
    init(dimX, dimY,setnozombie);
}

void Mars::init(int dimX, int dimY, int setnozombie)
{
    dimX_ = dimX;
    dimY_ = dimY;
    char objects[] = {' ', ' ', ' ', ' ', ' ', ' ', '^', '<', '>', 'v', 'h', 'p', 'r'};
    int noOfObjects = 13; // number of objects in the objects array
    // create dynamic 2D array using vector
    //char zombie[] = {'Z'}; //testing only one zombie
    map_.resize(dimY_); // create empty rows
    for (int i = 0; i < dimY_; ++i)
    {
        map_[i].resize(dimX_); // resize each row
    }

    // put random characters into the vector array
    for (int i = 0; i < dimY_; ++i)
    {
        for (int j = 0; j < dimX_; ++j)
        {
            int objNo = rand() % noOfObjects;
            map_[i][j] = objects[objNo];
        }
    }
    /*for (int k = 0; k < setnozombie; ++k) //testing for only one zombie
        
    {
        int i = rand() % dimX;
        int j = rand() % dimY;
        map_[j][i] = zombie[0];
    }
    */
}

void Mars::display(int &dimX, int &dimY)
{
    // comment this out during testing
    // system("cls"); // OR system("clear"); for Linux / MacOS
    cout << "  =--------------------=" << endl;
    cout << "  = Alien, Gambatte ne =" << endl;
    cout << "  =--------------------=" << endl;
    // for each row
    for (int i = 0; i < dimY_; ++i)
    {
        // display upper border of the row
        cout << "  ";
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "+-";
        }
        cout << "+" << endl;
        // display row number
        cout << setw(2) << (dimY_ - i);
        // display cell content and border of each column
        for (int j = 0; j < dimX_; ++j)
        {
            cout << "|" << map_[i][j];
        }
        cout << "|" << endl;
    }
    // display lower border of the last row
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << "+-";
    }
    cout << "+" << endl;
    // display column number
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        int digit = (j + 1) / 10;
        cout << " ";
        if (digit == 0)
            cout << " ";
        else
            cout << digit;
    }
    cout << endl;
    cout << "  ";
    for (int j = 0; j < dimX_; ++j)
    {
        cout << " " << (j + 1) % 10;
    }
    cout << endl
         << endl;
}

int Mars::getDimX()
{
    return dimX_;
}

int Mars::getDimY()
{
    return dimY_;
}

char Mars::getObject(int col, int row)
{
    // This is wrong
    return map_[dimY_ - row][col - 1];
}
void Mars::setObject2(int col, int row) //Display trail of the alien
{
    map_[dimY_ - row][col - 1] = '.';
}
void Mars::setObject(int col, int row, char object)
{
    map_[dimY_ - row][col - 1] = object;
}
void Mars::setObject3(int col, int row, char object)
{
    map_[dimY_-row][col-1] = object;
}
void Mars::setObject4(int col, int row) 
{
    map_[dimY_ - row][col - 1] = ' ';
}
// void Zombie::grounds(Mars &mars)
// {
//     int setnozombie;
//     cout << "Enter number of zombie => "; cin  >> setnozombie;
//     for (int k = 0; k < setnozombie; ++k)
        
//     {
//         int i = rand() % dimX;
//         int j = rand() % dimY;
//         map_[j][i] = zombie[0];
//         mars.display(dimX_, dimY_);
//     }
// }

void Mars::boardsetting(int dimX, int dimY, int setnozombie)
{
    void helpguide();
    int dimX_, dimY_;
    cout << "   Game Settings   " << endl;
    cout << "===================" << endl;
    cout << "Enter number of rows => ";
    cin >> dimX;
    cout << "Enter number of columns => ";
    cin >> dimY;
    cout << endl;
    cout << "   Zombie settings   " << endl;
    cout << "---------------------" << endl;
    dimX_ = dimX;
    dimY_ = dimY;
    srand(1);
    Mars mars;
    mars.init(dimX, dimY, setnozombie);

    Alien curiosity;
    curiosity.land(mars);

    int Xaxis;
    int Yaxis;
    int o;
    int q;
    q = curiosity.getX();
    o = curiosity.getY();
    cout << "Enter number of zombie => "; cin  >> setnozombie;
    for (int k = 0; k < setnozombie; ++k)
        
    {
        char zombheading[] = {'Z'};
        int zx;
        int zy;
        char zheading;
        zx = rand() % mars.getDimX() + 1;
        zy = rand() % mars.getDimY() + 1;
        zheading = zombheading[0];
        mars.setObject(zx, zy, zheading);
        mars.display(dimX, dimY);
        ClearScreen();

    } 
    mars.display(dimX_, dimY_);
    char choice;
    char command;
    int health = 100;
    int alien_attack = 0;

    // zombie attributes
    int zomb_health = 100;
    int zomb_attack = 20;
    cout << "Alien:  Health: " << health << " "
         << "Attack: " << alien_attack << endl;
    cout << "Zombie: Health: " << zomb_health << " "
         << "Attack: " << zomb_attack << endl;
    cout << "\nCommand: ";
    do
    {
        cin >> choice;
        choice = toupper(choice);
        int mapy = mars.getDimY();
        int mapx = mars.getDimX();
        switch (choice)
        {
        case 'U':
            for (int i = o; i < mapy; i++)
            {
                curiosity.moveUp(mars);
            }
            mars.display(dimX_, dimY_);
            q = curiosity.getX();
            o = curiosity.getY();
            cout << "Alien:  Health: " << health << " "
                 << "Attack: " << alien_attack << endl;
            cout << "Zombie: Health: " << zomb_health << " "
                 << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            break;

        case 'D':
            for (int i = o; i > 1; i--)
            {
                curiosity.moveDown(mars);
            }
            mars.display(dimX_, dimY_);
            q = curiosity.getX();
            o = curiosity.getY();
            cout << "Alien:  Health: " << health << " "
                 << "Attack: " << alien_attack << endl;
            cout << "Zombie: Health: " << zomb_health << " "
                 << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            break;

        case 'L':
            for (int i = q; i > 1; i--)
            {
                curiosity.moveLeft(mars);
            }
            mars.display(dimX_, dimY_);
            cout << "Alien:  Health: " << health << " "
                 << "Attack: " << alien_attack << endl;
            cout << "Zombie: Health: " << zomb_health << " "
                 << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            q = curiosity.getX();
            o = curiosity.getY();
            break;

        case 'R':
            for (int i = q; i < mapx; i++)
            {
                curiosity.moveRight(mars);
            }
            mars.display(dimX_, dimY_);
            cout << "Alien:  Health: " << health << " "
                 << "Attack: " << alien_attack << endl;
            cout << "Zombie: Health: " << zomb_health << " "
                 << "Attack: " << zomb_attack << endl;
            cout << "Command: ";
            q = curiosity.getX();
            o = curiosity.getY();
            break;

        case 'Q':
            cout << "Quitting game....." << endl;
            Pause();
            abort();
            break;

        case 'H':
            cout << "Showing game control......." << endl;
            Pause();
            helpguide();
            mars.display(dimX_, dimY_);
            cout << "Command: ";
            break;

        default:
            cout << "Please insert the correct input" << endl;
            cout << "Type 'H' for the guidance of the movement control" << endl;
            Pause();
            cout << "Command: ";
            break;
        }
    } while (true);
}

void DefaultMenu()
{
    char response;
    int dimX_ = 15;
    int dimY_ = 5;
    int setnozombie = 1;

    cout << " -------------------------------------" << endl;
    cout << " |           Game Setting             |" << endl;
    cout << " -------------------------------------" << endl;
    cout << "Board Rows: " << dimX_ << endl;
    cout << "Board Columns: " << dimY_ << endl;
    cout << "Number of Zombie: " << setnozombie << endl;
    cout << "Do you wish to change the game settings (y/n)? => ";
    cin >> response;
    response = toupper(response);
    if (response == 'Y')
    {
        Mars mars;
        mars.boardsetting(dimX_, dimY_, setnozombie);
    }

    else if (response == 'N')
    {
        Mars mars;
        Alien curiosity;
        mars.MatchStart();
    }

    else
    {
        cout << "Please insert y/n" << endl;
        return DefaultMenu();
    }
}

void helpguide()
{
    cout << "+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << "+     Game Control    +" << endl;
    cout << "+-+-+-+-+-+-+-+-+-+-+-+" << endl;
    cout << " " << endl;
    cout << "1. U - move upward" << endl;
    cout << "2. D - move downward" << endl;
    cout << "3. L - move left" << endl;
    cout << "4. R - move right" << endl;
    cout << "5. H - display movement control" << endl;
    cout << "6. Arrow - Change the direction of an arrow" << endl;
    cout << "7. S - save the current game progress" << endl;
    cout << "8. L - load a game" << endl;
    cout << "9. Q - quit the game" << endl;
    cout << "Continue to game......" << endl;
    Pause();
}

int main()
{
    char ans;

    cout << "+-+-+-+-+-+-+-+-+" << endl;
    cout << "+     Menu      +" << endl;
    cout << "+-+-+-+-+-+-+-+-+" << endl;
    cout << "+               +" << endl;
    cout << "+ 1. Start Game +" << endl; 
    cout << "+ 2. Help       +" << endl;
    cout << "+ 3. Quit       +" << endl;
    cout << "+-+-+-+-+-+-+-+-+" << endl << endl;

    cout << "command:";
    cin >> ans;

    if (ans == '1')
    {
        DefaultMenu();
        
    }
    else if (ans == '2')
    {
        helpguide();
        return main();
    }

    else if (ans == '3')
    {
       cout << "Bye Bye\n";
       Pause();
       ClearScreen();
    }

    else
    {
        cout << "Please insert the correct input" << endl;
        Pause();
        return main();

    }
}