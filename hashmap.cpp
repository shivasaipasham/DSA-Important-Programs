#include<bits/stdc++.h>
using namespace std;
#define en "\n"
typedef long long ll; 

class Hashmap{
	public:
    vector<vector<int>> arr;
	string status;
	Hashmap(int size){
		vector<vector<int>> v(size,vector<int>(2,-1));
		arr=v;
		string temp="";
		for(int i=0;i<size;i++){
			temp+='e';
		}
		status=temp;
    } 
	string search(int x){
		int i=0;
		int hv=(x+(i*i))%7;
		while(hv<=arr.size() && arr[hv][0]!=x && status[hv]!='e'){
			i++;
			hv=(x+(i*i))%7;
		}
		if(status[hv]=='e' || hv>arr.size())
		   return "Element is not Present";
		return to_string(arr[hv][1]);
	}
	void insert(int x){
		int i=0;
		int hv=(x+(i*i))%7;
		while(arr[hv][0]!=x && status[hv]!='e'){
			i++;
			hv=(x+(i*i))%7;
		}
		if(arr[hv][0]==x)
		   arr[hv][1]++;
		else{
			arr[hv][0]=x;
			arr[hv][1]=1;
			status[hv]='o';
		}
	}
	void remove(int x){
		int i=0;
		int hv=(x+(i*i))%7;;
		while(arr[hv][0]!=x){
			i++;
			hv=(x+(i*i))%7;
		}
		if(arr[hv][1]>1){
			arr[hv][1]--;
		}
		else{
			arr[hv][0]=-1;
			//arr[hv][0]=-1;
			status[hv]='d';
		}
	}
};


int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Hashmap umap(10000);//=new Hashmap(10000);
	umap.insert(1);
	umap.insert(12);
	umap.insert(45);
	umap.insert(13);
	cout<<umap.search(12)<<en;
	cout<<umap.search(5)<<en;
	cout<<umap.search(23)<<en;
	cout<<umap.search(45)<<en;
	umap.remove(1);
	cout<<umap.search(1)<<en;
	return 0;
}