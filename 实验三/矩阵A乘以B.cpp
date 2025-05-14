#include<iostream>
using namespace std;
int main(){
    int Ca,Ra;
    cin>>Ra>>Ca;
    int **A=new int*[Ra];
    for(int i=0;i<Ra;i++){
        A[i]=new int[Ca];
        for(int j=0;j<Ca;j++){
            cin>>A[i][j];
        }
    }
    int Cb,Rb;
    cin>>Rb>>Cb;
    if (Ca!=Rb){
        cout<<"Error: "<<Ca<<" != "<<Rb<<endl;
        exit(EXIT_SUCCESS);
    }
    int **B=new int*[Rb];
    for(int i=0;i<Rb;i++){
        B[i]=new int[Cb];
        for(int j=0;j<Cb;j++){
            cin>>B[i][j];
        }
    }
    cout<<Ra<<" "<<Cb<<endl;
    for (int i=0;i<Ra;i++){
        for(int j=0;j<Cb;j++){
            int sum=0;
            for(int k=0;k<Ca;k++){
                sum+=A[i][k]*B[k][j];
            }
            cout<<sum;
            if(j!=Cb-1){
                cout<<" ";
            }
        }
        cout<<endl;
    }
    return 0;
}