#include <iostream>
using namespace std;
// class Student{
//     char num[12];
//     char name[50];
//     int scores[3];
// public:
//     void getStudent1();//与构造函数？
//     void modStudent2();
//     // void delStudent3();
//     // void seekStudentNum4();
//     void show();
//     // void seekStudentName5();
//     // void numUp6();
//     // void scoredown7();
//     friend int seekStudent(char * p, Student * ps, int size);
//     friend bool frontLow(const Student * p1, const Student * p2);

// };
// using namespace std;

// void Student::getStudent1(){
//     for (int i = 0; i < 12; i++)
//         cin.get(num[i]);
//     for (int i = 0; i < 3; i++)
//         cin >> scores[i];
//     cin.getline(name, 50);
// }

// void Student::modStudent2(){
//     for (int i = 0; i < 3; i++)
//         cin >> scores[i];
//     cin.getline(name, 50); 
// }

// void Student::show()
// {
//     for (int i = 0; i < 12; i++)
//         cout << num[i];
//     cout << name;
//     for (int i = 0; i < 3; i++)
//         cout << scores;
// }

// int seekStudent(char * p, Student * ps, int size){
//     int i;
//     for (i = 0; i < size; i++){
//         bool isGot = true;
//         for (int j = 0; j < 12; j++)
//             if(ps[i].num[j] != p[i])
//                 isGot = false;
//         if (isGot)
//             return i;
//     }
// }

// bool frontLow(const Student * p1, const Student * p2){
//     for (int i = 0; i < 12; i++)
//         if (p1->num[i] < p2->num[i])
//             return true;
//         else if (p1->num[i] > p2->num[i])
//             return false;
// }

// int main()
// {
//     char ch;
//     Student * pst;
//     int s = 0;
//     Student * tmp;
//     while((ch = cin.get()) != '0'){
//         switch(ch)
//         {
//             case '1': tmp = new Student[++s];
//                     tmp->[s-1].getStudent1();
//                     break;
//         }
//     }
// }
class Student{
public:
    char num[12];
    char name[50];
    int scores[3];
    int tot;
    
};
class Students{
    Student * ps = nullptr;
    int count = 0;
    void show(int index);
    int seeknum();
    void up();
public:
    void add1();
    void modi2();
    void del3();
    void seeknum4();
    void seekname5();
    void up6();
    void down7();
};

int Students::seeknum(){
    char tmpc[12];
    for (int i = 0; i < 12; i++)
        cin.get(tmpc[i]);
    cin.get();
    int i;
    bool isGot;
    for (i = 0; i < count; i++){
        isGot = true;
        for (int j = 0; j < 12; j++)
            if(ps[i].num[j] != tmpc[j])
                isGot = false;
        if (isGot)
            return i;
    }
    return count;
}

void Students::show(int index){
    for (int i = 0; i < 12; i++)
        cout << ps[index].num[i];
    cout << " " << ps[index].name;
    for (int i = 0; i < 3; i++)
        cout << " " << ps[index].scores[i];
    cout << endl;
}

void Students::add1(){
    Student * tp;
    tp = new Student[++count];

    tp[count-1].tot = 0;
    for (int i = 0; i < 12; i++)
        cin.get(tp[count-1].num[i]);
    for (int i =0; i < 3; i++){
        cin >> tp[count-1].scores[i];
        tp[count-1].tot += tp[count-1].scores[i];
    }
    cin.get();
    cin.getline(tp[count-1].name, 50);
    

    if (ps != nullptr){
        for (int i = 0; i < count-1; i++)
            tp[i] = ps[i];
        delete [] ps;
    }
    ps = tp;
}

void Students::modi2()
{
    int ans = seeknum();
    if (ans == count)
        return;
    for (int i =0; i < 3; i++)
        cin >> ps[ans].scores[i];
    ps[ans].tot = ps[ans].scores[0] + ps[ans].scores[1] + ps[ans].scores[2];
    cin.get();
    cin.getline(ps[ans].name, 50);
}

void Students::del3(){
    int ans = seeknum();
    if (ans == count)
        return;
    for (int i = ans; i < count; i++)
        ps[i] = ps[i+1];
    count--;
}

void Students::seeknum4(){
    int ans = seeknum();
    if (ans == count)
        return;
    show(ans);
}

void Students::seekname5(){
    char tpname[50];
    cin.getline(tpname, 50);
    int anscount = 0;
    int * pans = new int[count];
    for (int i = 0; i < count; i++){
        bool isFound = true;
        for (int j = 0; !(tpname[j] == '\0' && ps[i].name[j] == '\0'); j++){
            if (tpname[j] == '\0' && ps[i].name[j] != '\0')
                isFound = false;
            else if (ps[i].name[j] == '\0' && tpname[j] != '\0')
                isFound = false;
            else if (ps[i].name[j] != tpname[j])
                isFound = false;
            if (!isFound)
                break;
        }
        if (isFound){
            pans[anscount++] = i;
        }
    }
    for (int i = 0; i < anscount; i++)
        for (int j = i + 1; j < anscount; j++)
        {
            bool frontLow = true;
            for (int m = 0; m < 12; m++)
                if (ps[pans[i]].num[m] > ps[pans[j]].num[m]){
                    frontLow = false;
                    break;
                }
                else if (ps[i].num[m] < ps[j].num[m]){
                    frontLow = true;
                    break;
                }
            if (!frontLow){
                Student tmp = ps[pans[i]];
                ps[pans[i]] = ps[pans[j]];
                ps[pans[j]] = tmp;
            }
        }
    for (int i = 0; i < anscount; i++)
        show(pans[i]);
}


void Students::up(){
    for (int i = 0; i < count; i++){
        for (int j = i + 1; j < count; j++){
            bool frontLow = true;
            for (int m = 0; m < 12; m++)
                if (ps[i].num[m] > ps[j].num[m]){
                    frontLow = false;
                    break;
                }
                else if (ps[i].num[m] < ps[j].num[m]){
                    frontLow = true;
                    break;
                }
            if (!frontLow){
                Student tmp = ps[i];
                ps[i] = ps[j];
                ps[j] = tmp;
            }
        }
    }
}

void Students::down7(){
    for (int i = 0; i < count; i++)
        for (int j = i + 1; j < count; j++){
            if (ps[i].tot < ps[j].tot){
                Student tmp = ps[i];
                ps[i] = ps[j];
                ps[j] = tmp;
            }
            else if (ps[i].tot == ps[j].tot){
                bool frontLow = true;
                for (int m = 0; m < 12; m++)
                    if (ps[i].num[m] > ps[j].num[m]){
                        frontLow = false;
                        break;
                    }
                    else if (ps[i].num[m] < ps[j].num[m]){
                        frontLow = true;
                        break;
                    }
                if (!frontLow){
                    Student tmp = ps[i];
                    ps[i] = ps[j];
                    ps[j] = tmp;
                }
            }
        }
    for (int i = 0; i < count; i++)
        show(i);
}

void Students::up6(){
    for (int i = 0; i < count; i++)
        show(i);
}

int main(){
    Students cl;
    char ch;
    cin.get(ch);
    cin.get();
    while (ch != '0'){
        switch(ch){
            case '1': cl.add1();
                    break;
            case '2': cl.modi2();
                    break;
            case '3': cl.del3();
                    break;
            case '4': cl.seeknum4();
                    break;
            case '5': cl.seekname5();
                    break;
            case '6': cl.up6();
                    break;
            case '7': cl.down7();
                    break;
        }
        cin.get(ch);
        cin.get();
    }
    return 0;
}