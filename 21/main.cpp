#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

void write(int arr[], int size, string path);
int* read(string path, int& size);
int maxk(string path, int k);
double average(string path){
    ifstream file(path);
    if(!file.is_open()){
        throw logic_error("File cannot be open");
    }
    int x;
    double avg = 0;
    double count = 0;
    while(file >> x){
        avg = count / (count + 1) * avg + x / (count + 1);
        count++;
    }
    return avg;
}

int main(){
    // int arr[] = {3, 45, 487, 1, 98};
    // int size = (sizeof arr) / (sizeof arr[0]);
    // write(arr, size, "in.txt"); 

    // int size2;
    // int* arr2 = read("in.txt", size2);
    // for(int i = 0; i < size2; ++i){
    //     cout << arr2[i] << endl;
    // }
    // delete[] arr2;

    
    cout << "Max 100d: " << maxk("my.txt", 3) << endl;
    cout << "Average: " << average("my.txt", 3) << endl;
}

void write(int arr[], int size, string path){
    ofstream file(path);
    file.is_open();
    if(!file.is_open()){
        throw logic_error("Error, file cannot be open");
    }
    for(int i = 0; i < size; ++i){
        file << arr[i] << endl;
    }
}
int* read(string path, int& size){
    ifstream file(path);
    if(!file.is_open()){
        throw logic_error("Error, file cannot be open");
    }
    int* arr = new int[1000];
    size = 0;
    int x;
    while(file >> x){
        arr[size] = x;
        size++;
    }
    return arr;
}
int maxk(string path, int k){
    ifstream file(path);
    if(!file.is_open()){
        throw logic_error("File cannot be open");
    }
    int x;
    priority_queue<int, vector<int>, greater<int>> maxT;
    while(file >> x){
        maxT.push(x);
        if(maxT.size() > k){
            maxT.pop();
        }
    }
    return maxk;
}