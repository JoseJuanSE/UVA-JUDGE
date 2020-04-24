/* UVA JUDGE: 11935 Through the deser */
#include<bits/stdc++.h>
using namespace std;
struct act{
	double lu,aux;
	int t;
};
int t,x;
vector<act>vec;
bool pro(double x){
	double rec=vec[0].lu,kl=vec[0].aux,tan=x;
	int leak=0;
	for(int i=1;i<vec.size();i++){
		tan-=(vec[i].lu-rec)*(kl)/100;
		tan-=(vec[i].lu-rec)*leak;
		rec=vec[i].lu;
		if(tan<0)return false;
		if(vec[i].t==1){
			kl=vec[i].aux;
		}
		else if(vec[i].t==2){
			tan=x;
		}
		else if(vec[i].t==3){
			leak++;
		}
		else if(vec[i].t==4){
			leak=0;
		}
		if(tan<0)return false;
	}
	return true;
}
double bs(double ini,double fin,int vec){
	if(vec>40)return ini;
	double mitad=(ini+fin)/2+0.0000000001;
	if(pro(mitad))return bs(ini,mitad,vec+1);
	return bs(mitad,fin,vec+1);
}
int main(){
	ios_base::sync_with_stdio(0);cin.tie(0);
	string a,b;
	while(cin>>t>>a>>b>>x){
		vec.clear();
		if(t==0 and x==0)return 0;
		act cu;
		cu.lu=t;
		cu.aux=x;
		cu.t=1;
		vec.push_back(cu);
		while(cin>>t){
			cin>>a;
			cu.lu=t;
			if(a=="Fuel"){
				cin>>a>>cu.aux;
				cu.t=1;
			}
			else if(a=="Gas"){
				cin>>a;
				cu.t=2;
			}
			else if(a=="Leak")cu.t=3;
			else if(a=="Mechanic")cu.t=4;
			else if(a=="Goal")cu.t=5;
			vec.push_back(cu);
			if(a=="Goal")break;
		}
		cout<<fixed<<setprecision(3)<<bs(0,100000000,0)<<"\n";
	}
	return 0;
}
