#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Transcoder{
public:
    virtual void EncodeToH264(char *inData, char *outData) = 0;
    virtual void EncodeToVP8(char *inData, char *outData) = 0;
    virtual void DecodeToH264(char *inData, char *outData) = 0;
    virtual void DecodeToVP8(char *inData, char *outData) = 0;
};




class Vehicle : public Transcoder {
public:
    //default Constructor
    Vehicle(){

        numberOfWheels = 4;
        type = "Earth";
    }
    Vehicle(int wheels, string t){
        numberOfWheels = wheels;
        type = t;
    }

    void EncodeToH264(char *inData, char *outData){

    }

    void EncodeToVP8(char *inData, char *outData){

    }

    void DecodeToH264(char *inData, char *outData){

    }

private:
    int numberOfWheels;
    string type;

    
};

class Car : public Vehicle{
public:
    Car(int wheels, string t, string m) : Vehicle(wheels, t){
        model = m;
    }
private:
    string model;
};

class Coordinate{
public:
    //constructor
    Coordinate(int a, int b){
        x = a;
        y = b;
    }

    //method
    int getX(){
        return x;
    }

    int getY(){
        return y;
    }

    void setX(int a){
        x = a;
    }

    void setY(int b){
        y = b;
    }

    
private:
    int x;
    int y;
};

ostream& operator << (ostream& os, Coordinate point) {
    cout<<"("<<point.getX()<<", "<<point.getY()<<")";
    return os;
}

//examples related vector
template<class T>
void print_vector(vector<T> v){
    cout<<"Size: "<<v.size()<< " ==> ";
     //c++ -std=11
    for(auto x : v){
        cout<<x<<" ";
    }
    cout<<endl;
}

bool comp(int a, int b){
    if(a > b){
        return true;
    }
    
    return false;
}

bool comp_for_coordinate(Coordinate p1, Coordinate p2){
    int p1_dist = p1.getX()*p1.getX() + p1.getY() * p1.getY();
    int p2_dist = p2.getX()*p2.getX() + p2.getY() * p2.getY();

    if(p1_dist == p2_dist){
        if(p1.getX() == p2.getX()){
            return p1.getY() < p2.getY();
        }
        return p1.getX() < p2.getX();
    }
    return p1_dist < p2_dist;
}

void learn_Vector()
{
    vector<int> list;
    

    list.push_back(5);
    list.push_back(10);
    list.push_back(89);
    list.push_back(11);
    list.push_back(55);
    print_vector<int>(list);

    vector<string> list2;
    list2.push_back("Rajib");
    list2.push_back("Zakee");
    print_vector<string>(list2);


    //sort vector
    sort(list.begin(), list.end(), comp);
    print_vector<int>(list);

    vector<Coordinate> points;
    points.push_back(Coordinate(1,5));
    points.push_back(Coordinate(2,5));
    points.push_back(Coordinate(8,5));
    points.push_back(Coordinate(1,2));
    points.push_back(Coordinate(-1,3));
    print_vector<Coordinate>(points);
    sort(points.begin(), points.end(), comp_for_coordinate);
    print_vector<Coordinate>(points);

    //merge two vector
    //deep copy
    vector<int> merged_list;
    copy(list.begin(), list.end(), back_inserter(merged_list) );

    copy(list.begin(), list.end(), back_inserter(merged_list) );

    print_vector<int>(merged_list);


    vector<vector<int>> matrix;
    vector<vector<vector<int>>> model3d;
    matrix.push_back(list);
    matrix.push_back(list);
    matrix[1].push_back(45);
    matrix[1].push_back(90);
    matrix.push_back(list);


    //traverse it
    for(int i=0; i<matrix.size(); i++){
        //row
        for(int j=0; j<matrix[i].size(); j++){
            //column
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    
}


int main()
{
    cout<<"Hello world"<<endl;
    learn_Vector();


    Car c(4, "Earth", "BMW");

    //List of STL
    // i) vector (done)
    // ii) string
    // iii) map
    // iv) set
    // v) queue
    // vi) stack
    // vii) priority_queue
    // viii) multiset
    // ix) dequeue
    // x) multimap
    // xi) forward_list
    // xii) arrays


    return 0;
}