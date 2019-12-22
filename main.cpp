/*
Student Name:
Student Number:
Project Number: 5
Compile Status: [SUCCESS/FAIL]
Running Status: [SUCCESS/FAIL]
Notes: Anything you want to say about your code that will be helpful in the grading process.
*/

#include <iostream>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;

int main(int argc, char* argv[]){
    if (argc != 3) {
        cerr << "Run the code with the following command: ./cmpe250-assignment3 [input_file] [output_file]" << endl;
        return 1;
    }

    ifstream inFile(argv[1]);
    if (!inFile) {
        cerr << "There was a problem opening \"" << argv[1] << "\" as input file" << endl;
        return 1;
    }

    ofstream outFile(argv[2]);
    if (!outFile) {
        cerr << "There was a problem opening \"" << argv[2] << "\" as output file" << endl;
        return 1;
    }
    int N,M;
    inFile>>N;
    inFile>>M;
    int chocolate[N];
    for(int i=0;i<N;i++){
        int t;
        inFile>>t;
        chocolate[i]=t;
    }
    sort(chocolate,chocolate+N);
    long long int table[N];
    for(int k=0;k<N;k++){
        if(k==0){
            table[k]=chocolate[k];
        }
        else{
            table[k]=0;
        }
    }
    for(int t=1;t<M;t++){
       table[t]=table[t-1]+chocolate[t];
    }
    for(int K=M;K<N;K++){
        if(K-M-1<0){
            table[K]=table[K-1]+table[K-M]+chocolate[K];
        }
        else{
            table[K]=table[K-1]+table[K-M]-table[K-M-1]+chocolate[K];
        }
    }
    for (int (i) = 0; (i) <N ; ++(i)) {
        outFile<<table[i];
        outFile<<" ";
    }
    return 0;
}
