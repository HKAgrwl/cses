#include <iostream>
#include <vector>
using namespace std;
 
int ans=0;
 
void getRooms(vector<vector<char>> &rooms,int i,int j){
    if(i<0 || j<0 || i>=int(rooms.size()) || j>=int(rooms[0].size()) || rooms[i][j]=='#') return;
    rooms[i][j]='#';
    getRooms(rooms,i+1,j);
    getRooms(rooms,i,j+1);
    getRooms(rooms,i-1,j);
    getRooms(rooms,i,j-1);
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
            if(rooms[i][j]=='.'){
                ans++;
                getRooms(rooms,i,j);
            }    
        }
    }
    cout<<ans;
    return 0;
}