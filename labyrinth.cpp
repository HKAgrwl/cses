#include <iostream>
#include <vector>
#include <climits>
using namespace std;
 
int ans = INT_MAX;
string ansString = " ";
int found = 0;

void getPath(vector<vector<char>> &rooms,int i,int j,int len,string path){
    if(i<0 || j<0 || i>=int(rooms.size()) || j>=int(rooms[0].size()) || rooms[i][j]=='#' || (rooms[i][j]=='A' && len!=0)) return;
    if(rooms[i][j] =='B'){
        ans = min(ans,len);
        ansString = path;
        found = 1;
        return;
    }
    if(!found){
        getPath(rooms,i+1,j,len+1,path+'D');
        getPath(rooms,i,j+1,len+1,path+'R');
        getPath(rooms,i-1,j,len+1,path+'U');
        getPath(rooms,i,j-1,len+1,path+'L');
    }
    
}
 
void printMatrix(vector<vector<char>> v,int n,int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<v[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
 
int main()
{
    int n,m;
    cin>>n>>m;
    vector<vector<char>> rooms(n,vector<char>(m,'#'));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>rooms[i][j];
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(rooms[i][j]=='A'){
                getPath(rooms,i,j,0,"");
                break;
            }    
        }
    }
    if(ans == INT_MAX){
        cout<<"NO";
    }else{
        cout<<"YES"<<endl;
        cout<<ans<<endl;
        cout<<ansString<<endl;

    }
    return 0;
}