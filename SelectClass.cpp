#include<iostream>
#include<iomanip>
#include<ctype.h>
#include<vector>
#include<algorithm>     //include for sorting, also can use bubble/heap/quick/merge/insertion/selection/radix method
#include<map>           //can use for dictionary type(key,value)
#include<stdlib.h>
#include<time.h>        //for computer produce random number

using namespace std;


const int Rank = 6;

const int CLASS_A_NUM = 36;
const int CLASS_B_NUM = 4;
const int CLASS_C_NUM = 12;
const int CLASS_D_NUM = 10;
const int CLASS_E_NUM = 8;
const int CLASS_F_NUM = 8;

vector<int> Rank1_A,Rank1_B,Rank1_C,Rank1_D,Rank1_E,Rank1_F;
vector<int> Rank2_A,Rank2_B,Rank2_C,Rank2_D,Rank2_E,Rank2_F;
vector<int> Rank3_A,Rank3_B,Rank3_C,Rank3_D,Rank3_E,Rank3_F;
vector<int> Rank4_A,Rank4_B,Rank4_C,Rank4_D,Rank4_E,Rank4_F;
vector<int> Rank5_A,Rank5_B,Rank5_C,Rank5_D,Rank5_E,Rank5_F;
vector<int> Rank6_A,Rank6_B,Rank6_C,Rank6_D,Rank6_E,Rank6_F;
vector<int>::iterator iter;

struct student{

    string name;
    char order[6];

};

double Power(double base,int exponent){

    double x = 1.0;

    if(base == 0 && exponent == 0){
        cout << "No Result." << endl;
        return -1;
    }
    else{
        int e = (exponent > 0) ? exponent:-exponent;
        while(e--){
            x *= base;
        }
        return exponent > 0 ? x:1/x;
    }

}

void Swap(int &x,int &y){

    int temp = x;
    x = y;
    y = temp;

}

void AnotherSwap(int *x,int *y){

    int temp = *x;
    *x = *y;
    *y = temp;

}

void PushVector(int Rank,char c,int num){

    switch(Rank){

    case 0:
        if(c == 'A')
            Rank1_A.push_back(num);
        else if(c == 'B')
            Rank1_B.push_back(num);
        else if(c == 'C')
            Rank1_C.push_back(num);
        else if(c == 'D')
            Rank1_D.push_back(num);
        else if(c == 'E')
            Rank1_E.push_back(num);
        else if(c == 'F')
            Rank1_F.push_back(num);

        break;

    case 1:
        if(c == 'A')
            Rank2_A.push_back(num);
        else if(c == 'B')
            Rank2_B.push_back(num);
        else if(c == 'C')
            Rank2_C.push_back(num);
        else if(c == 'D')
            Rank2_D.push_back(num);
        else if(c == 'E')
            Rank2_E.push_back(num);
        else if(c == 'F')
            Rank2_F.push_back(num);

        break;

    case 2:
        if(c == 'A')
            Rank3_A.push_back(num);
        else if(c == 'B')
            Rank3_B.push_back(num);
        else if(c == 'C')
            Rank3_C.push_back(num);
        else if(c == 'D')
            Rank3_D.push_back(num);
        else if(c == 'E')
            Rank3_E.push_back(num);
        else if(c == 'F')
            Rank3_F.push_back(num);

        break;

    case 3:
        if(c == 'A')
            Rank4_A.push_back(num);
        else if(c == 'B')
            Rank4_B.push_back(num);
        else if(c == 'C')
            Rank4_C.push_back(num);
        else if(c == 'D')
            Rank4_D.push_back(num);
        else if(c == 'E')
            Rank4_E.push_back(num);
        else if(c == 'F')
            Rank4_F.push_back(num);

        break;

    case 4:
        if(c == 'A')
            Rank5_A.push_back(num);
        else if(c == 'B')
            Rank5_B.push_back(num);
        else if(c == 'C')
            Rank5_C.push_back(num);
        else if(c == 'D')
            Rank5_D.push_back(num);
        else if(c == 'E')
            Rank5_E.push_back(num);
        else if(c == 'F')
            Rank5_F.push_back(num);

        break;

    default:
        if(c == 'A')
            Rank6_A.push_back(num);
        else if(c == 'B')
            Rank6_B.push_back(num);
        else if(c == 'C')
            Rank6_C.push_back(num);
        else if(c == 'D')
            Rank6_D.push_back(num);
        else if(c == 'E')
            Rank6_E.push_back(num);
        else if(c == 'F')
            Rank6_F.push_back(num);

        break;

    }

}

int *GetRandom(int Min,int Max,int num){    // get un-repeatable number by computer choose(by timer)

    //static int result[num];
    int *result = new int[num];
    for(int i=0; i<num; ++i){
        result[i] = rand() % (Max-Min+1) + Min;
        for(int j=0; j<i; ++j){
            if(result[j] == result[i])
            {
                i--;
                break;
            }
        }
    }

    return result;
    //for(int i=0; i<num; ++i){
    //    cout << result[i] << endl;
    //}

}

int *ProduceFinalList(int total_people,int Limit,int *num,int Rank,vector<int> rank1,vector<int> rank2,vector<int> rank3,vector<int> rank4,vector<int> rank5,vector<int> rank6){

    int *Temp;
    int length = (Limit > total_people)? total_people:Limit;   //decide array length
    int *Final = new int[length];

    if(num[0] > Limit){

        Temp = GetRandom(0,num[0]-1,Limit); //put index into computer

        for(int i=0; i<Limit; ++i){
            Final[i] = rank1[Temp[i]];
            //cout << Final[i] << " ";
        }

        return Final;
    }
    else if(num[0] == Limit){  //rank1 full
        for(int i=0; i<Limit; ++i){
            Final[i] = rank1[i];
        }
        return Final;
    }
    else if(num[0] + num[1] > Limit){  //rank1<limit, rank1+rank2>limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        Limit -= rank1.size();

        Temp = GetRandom(0,num[1]-1,Limit);

        for(int i=rank1.size(); i<rank1.size()+Limit; ++i){
            Final[i] = rank2[Temp[i-rank1.size()]];
        }
        return Final;
    }
    else if(num[0] + num[1] == Limit){  //rank1 + rank2 full
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<Limit; ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] > Limit){  //rank1+rank2<limit, rank1+rank2+rank3>limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }

        Limit -= (rank1.size()+rank2.size());

        Temp = GetRandom(0,num[2]-1,Limit);

        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+Limit; ++i){
            Final[i] = rank3[Temp[i-rank1.size()-rank2.size()]];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] == Limit){  //rank1 + rank2 + rank3 full
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<Limit; ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] > Limit){  //rank1+rank2+rank3<limit, rank1+rank2+rank3+rank4>limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }

        Limit -= (rank1.size()+rank2.size()+rank3.size());

        Temp = GetRandom(0,num[3]-1,Limit);

        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+Limit; ++i){
            Final[i] = rank4[Temp[i-rank1.size()-rank2.size()-rank3.size()]];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] == Limit){  //rank1 + rank2 + rank3 + rank4 full
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<Limit; ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] + num[4] > Limit){  //rank1+rank2+rank3+rank4<limit, rank1+rank2+rank3+rank4+rank5>limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size(); ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }

        Limit -= (rank1.size()+rank2.size()+rank3.size()+rank4.size());

        Temp = GetRandom(0,num[4]-1,Limit);

        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size()+Limit; ++i){
            Final[i] = rank5[Temp[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()]];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] + num[4] == Limit){  //rank1 + rank2 + rank3 + rank4 + rank5 full
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size(); ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size(); i<Limit; ++i){
            Final[i] = rank5[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] + num[4] + num[5] > Limit){  //rank1+rank2+rank3+rank4+rank5<limit, rank1+rank2+rank3+rank4+rank5+rank6>limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size(); ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); ++i){
            Final[i] = rank5[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()];
        }

        Limit -= (rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size());

        Temp = GetRandom(0,num[5]-1,Limit);

        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size()+Limit; ++i){
            Final[i] = rank6[Temp[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()-rank5.size()]];
        }
        return Final;
    }
    else if(num[0] + num[1] + num[2] + num[3] + num[4] + num[5] == Limit){  //rank1 + rank2 + rank3 + rank4 + rank5 + rank6 full
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size(); ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); ++i){
            Final[i] = rank5[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); i<Limit; ++i){
            Final[i] = rank6[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()-rank5.size()];
        }
        return Final;
    }
    else{ //total < Limit
        for(int i=0; i<rank1.size(); ++i){
            Final[i] = rank1[i];
        }
        for(int i=rank1.size(); i<rank1.size()+rank2.size(); ++i){
            Final[i] = rank2[i-rank1.size()];
        }
        for(int i=rank1.size()+rank2.size(); i<rank1.size()+rank2.size()+rank3.size(); ++i){
            Final[i] = rank3[i-rank1.size()-rank2.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size(); ++i){
            Final[i] = rank4[i-rank1.size()-rank2.size()-rank3.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size(); i<rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); ++i){
            Final[i] = rank5[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()];
        }
        for(int i=rank1.size()+rank2.size()+rank3.size()+rank4.size()+rank5.size(); i<num[0]+num[1]+num[2]+num[3]+num[4]+num[5]; ++i){
            Final[i] = rank6[i-rank1.size()-rank2.size()-rank3.size()-rank4.size()-rank5.size()];
        }
        return Final;
    }
}

int BinarySearch(int* A,int des,int len){  //O(n)=logN

    int Low = 0;
    int mid,Up;

    Up = len-1;

    while(Low <= Up) {
        mid = (Low+Up) / 2;
        if(A[mid] < des)
            Low = mid + 1;
        else if(A[mid] > des)
            Up = mid - 1;
        else{
            return mid;  //mid always >=0
        }

    }
    return -1;

}

int main(){

    map<char,int> Map_1;
    int total,Long,Count = 0;

    int *FinalListA = NULL,
        *FinalListB = NULL,
        *FinalListC = NULL,
        *FinalListD = NULL,
        *FinalListE = NULL,
        *FinalListF = NULL; //show final list

    srand(time(NULL));

/*
    int a = 3,b = 10,c[3] = {2,4,6};

    Swap(a,b);
    cout << "a=" << a << ",b=" << b << endl;
    Swap(c[0],c[2]);
    cout << "c[0]=" << c[0] << ",c[2]=" << c[2] << endl;

    AnotherSwap(&a,&b);
    cout << "a=" << a << ",b=" << b << endl;
    AnotherSwap(&c[0],&c[2]);
    cout << "c[0]=" << c[0] << ",c[2]=" << c[2] << endl;
*/

    cout << "Input how many students:";
    cin >> total;

    student Array[total];

    int *ptr_total_A = new int[Rank]();
    int *ptr_total_B = new int[Rank]();
    int *ptr_total_C = new int[Rank]();
    int *ptr_total_D = new int[Rank]();
    int *ptr_total_E = new int[Rank]();
    int *ptr_total_F = new int[Rank]();

    for(int i=0; i<total; ++i){

        cout << "Input " << i+1 << " student name:";
        cin >> Array[i].name;

        cout << "Input " << i+1 << " student order=>" << endl;
        Map_1.clear();

        for(int j=0; j<sizeof(Array[0].order)/sizeof(Array[0].order[0]); ++j){

            switch(j){
            case 0:
                cout << "1st order:";
                break;

            case 1:
                cout << "2nd order:";
                break;

            case 2:
                cout << "3rd order:";
                break;

            case 3:
                cout << "4th order:";
                break;

            case 4:
                cout << "5th order:";
                break;

            default:
                cout << "6rd order:";
                break;
            }

            cin >> Array[i].order[j];
            Map_1[Array[i].order[j]] = j;

            while (toupper(Array[i].order[j]) < 'A' || toupper(Array[i].order[j]) > 'F'){  //check whether input is reasonable(A~F, can't repeat)
                cout << "Wrong input!! Please input again." << endl;

                switch(j){
                case 0:
                    cout << "1st order:";
                    break;

                case 1:
                    cout << "2nd order:";
                    break;

                case 2:
                    cout << "3rd order:";
                    break;

                case 3:
                    cout << "4th order:";
                    break;

                case 4:
                    cout << "5th order:";
                    break;

                default:
                    cout << "6rd order:";
                    break;
                }

                cin >> Array[i].order[j];
                Map_1[Array[i].order[j]] = j;

            }
            cout << endl;
        }

        if(Map_1.size() != Rank){  //hash table one by one,if it repeat and its count will less than 6
            cout << "Class can't be repeatable, please input again!" << endl;
            i--;
            continue;
        }

        for(int k=0; k<Rank; ++k){
            if(toupper(Array[i].order[k]) == 'A')
                ptr_total_A[k]++;
            else if(toupper(Array[i].order[k]) == 'B')
                ptr_total_B[k]++;
            else if(toupper(Array[i].order[k]) == 'C')
                ptr_total_C[k]++;
            else if(toupper(Array[i].order[k]) == 'D')
                ptr_total_D[k]++;
            else if(toupper(Array[i].order[k]) == 'E')
                ptr_total_E[k]++;
            else if(toupper(Array[i].order[k]) == 'F')
                ptr_total_F[k]++;

            PushVector(k,toupper(Array[i].order[k]),i);
        }

        cout << setw(1) << "#" << i+1 << ".name:" << Array[i].name << "," << "rank:" << (char)toupper(Array[i].order[0]) << (char)toupper(Array[i].order[1]) << (char)toupper(Array[i].order[2]) << (char)toupper(Array[i].order[3]) << (char)toupper(Array[i].order[4]) << (char)toupper(Array[i].order[5]) << endl;  //print again
    }


    for(int i=0; i<Rank; ++i){
        cout << "Rank" << i+1 << " " << "total A:" << ptr_total_A[i] << " ,total B:" << ptr_total_B[i] << " ,total C:" << ptr_total_C[i] << " ,total D:" << ptr_total_D[i] << " ,total E:" << ptr_total_E[i] << " ,total F:" <<ptr_total_F[i] << endl;
    }
/*
    for(iter = Rank1_A.begin(); iter != Rank1_A.end(); ++iter){  //display for every rank people
        cout << *iter << " " << endl;
    }
*/
    FinalListA = ProduceFinalList(total,CLASS_A_NUM,ptr_total_A,Rank,Rank1_A,Rank2_A,Rank3_A,Rank4_A,Rank5_A,Rank6_A);
    FinalListB = ProduceFinalList(total,CLASS_B_NUM,ptr_total_B,Rank,Rank1_B,Rank2_B,Rank3_B,Rank4_B,Rank5_B,Rank6_B);
    FinalListC = ProduceFinalList(total,CLASS_C_NUM,ptr_total_C,Rank,Rank1_C,Rank2_C,Rank3_C,Rank4_C,Rank5_C,Rank6_C);
    FinalListD = ProduceFinalList(total,CLASS_D_NUM,ptr_total_D,Rank,Rank1_D,Rank2_D,Rank3_D,Rank4_D,Rank5_D,Rank6_D);
    FinalListE = ProduceFinalList(total,CLASS_E_NUM,ptr_total_E,Rank,Rank1_E,Rank2_E,Rank3_E,Rank4_E,Rank5_E,Rank6_E);
    FinalListF = ProduceFinalList(total,CLASS_F_NUM,ptr_total_F,Rank,Rank1_F,Rank2_F,Rank3_F,Rank4_F,Rank5_F,Rank6_F);


    cout << "Publish Class A List:" << endl;
    Long = (CLASS_A_NUM >= total) ? total:CLASS_A_NUM;  //ternary operator
    sort(FinalListA,FinalListA + Long);                 //auto sorting
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListA[i]].name << "(" << FinalListA[i] << ")" << " ";
    }
    cout << endl << endl;

    cout << "Publish Class B List:" << endl;
    Long = (CLASS_B_NUM >= total) ? total:CLASS_B_NUM;
    sort(FinalListB,FinalListB + Long);
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListB[i]].name << "(" << FinalListB[i] << ")" << " ";
    }
    cout << endl << endl;

    cout << "Publish Class C List:" << endl;
    Long = (CLASS_C_NUM >= total) ? total:CLASS_C_NUM;
    sort(FinalListC,FinalListC + Long);
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListC[i]].name << "(" << FinalListC[i] << ")" << " ";
    }
    cout << endl << endl;

    cout << "Publish Class D List:" << endl;
    Long = (CLASS_D_NUM >= total) ? total:CLASS_D_NUM;
    sort(FinalListD,FinalListD + Long);
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListD[i]].name << "(" << FinalListD[i] << ")" << " ";
    }
    cout << endl << endl;

    cout << "Publish Class E List:" << endl;
    Long = (CLASS_E_NUM >= total) ? total:CLASS_E_NUM;
    sort(FinalListE,FinalListE + Long);
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListE[i]].name << "(" << FinalListE[i] << ")" << " ";
    }
    cout << endl << endl;

    cout << "Publish Class F List:" << endl;
    Long = (CLASS_F_NUM >= total) ? total:CLASS_F_NUM;
    sort(FinalListF,FinalListF + Long);
    for(int i=0; i<Long; ++i){
        cout << Array[FinalListF[i]].name << "(" << FinalListF[i] << ")" << " ";
    }
    cout << endl << endl;





    cout << "Print every student class(fetch first 3 class):" << endl;
    for(int i=0; i<total; ++i){
        Count = 0;
        cout << setw(8) << Array[i].name << ":";

        for(int k=0; k<Rank && Count<3; ++k){ //up limit is 3

            switch(toupper(Array[i].order[k])){
            case 'A':
                Long = (CLASS_A_NUM >= total) ? total:CLASS_A_NUM;
                if(BinarySearch(FinalListA,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;

            case 'B':
                Long = (CLASS_B_NUM >= total) ? total:CLASS_B_NUM;
                if(BinarySearch(FinalListB,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;

            case 'C':
                Long = (CLASS_C_NUM >= total) ? total:CLASS_C_NUM;
                if(BinarySearch(FinalListC,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;

            case 'D':
                Long = (CLASS_D_NUM >= total) ? total:CLASS_D_NUM;
                if(BinarySearch(FinalListD,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;

            case 'E':
                Long = (CLASS_E_NUM >= total) ? total:CLASS_E_NUM;
                if(BinarySearch(FinalListE,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;

            default:
                Long = (CLASS_F_NUM >= total) ? total:CLASS_F_NUM;
                if(BinarySearch(FinalListF,i,Long) >= 0)
                {
                    cout << setw(1) << (char)toupper(Array[i].order[k]);
                    Count++;
                }
                break;
            }
        }

        cout << endl;
    }



    delete [] ptr_total_A;  //release memory
    delete [] ptr_total_B;
    delete [] ptr_total_C;
    delete [] ptr_total_D;
    delete [] ptr_total_E;
    delete [] ptr_total_F;

    system("pause");
    return 0;
}
