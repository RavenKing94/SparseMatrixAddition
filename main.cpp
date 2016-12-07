#include <iostream>
using namespace std;

int c[100][3];
int ca,cb,cc=0;

void SortC(void);

int main(int argc, char** argv) {
	
	int wh=0;
	
	cout<<"Size e Matrix ha ra vared konid : ";
	cin>>wh;

	cout<<"\nTedad e gheir e 0 baraye M1 : ";
	cin>>ca;
	int a[ca][3];
	for (int i=0;i<ca;i++){
		cout<< i+1 <<" - (X , Y , value) : ";
		cin >> a[i][0] >> a[i][1] >> a[i][2];		
	}
	
	cout<<"\nTedad e gheir e 0 baraye M2 : ";
	cin>>cb;
	int b[cb][3];
	for (int i=0;i<cb;i++){
		cout<< i+1 <<" - (X , Y , value) : ";
		cin >> b[i][0] >> b[i][1] >> b[i][2];
	}
	bool found=false;
	for (int i=0;i<wh;i++){ // Check Num
		
		for (int j=0;j<ca;j++){ // Search A
			
			if (a[j][0]==i) { // Found in A !!!!!!!!!!!
				
				c[cc][0]=a[j][0];
				c[cc][1]=a[j][1];
						
				for (int k=0;k<cb;k++){ // Match in B ?
					
					if ( (b[k][0]==i) && (b[k][1]==a[j][1]) ) // Matched c <= a + b !!!!!!!
					{
						c[cc][2]=a[j][2]+b[k][2];
						if (c[cc][2]!=0) cc++;
						found=true;
						break;
					}
					
				}
				if (!found) { // Not Matched c <= a
					c[cc][2]=a[j][2];
					cc++;
				}
			}		
		}
		
		for (int j=0;j<cb;j++){
			
			if (b[j][0]==i) { // Found in B !!!!!
				found=false;
				for (int k=0;k<=cc;k++) { // Match in C ?
					
					if ( (c[k][0]==i) && (c[k][1]==b[j][1]) ) {
						found=true;
						break;	
					}
				}
				
				if (!found) { // If it does not Exist , copy it
					c[cc][0]=b[j][0];
					c[cc][1]=b[j][1];
					c[cc][2]=b[j][2];
					cc++;
				}
				
			}
		}
	}
	
	cout<<"\n Matrix Sum : \n";
	SortC();
	for (int i=0;i<cc;i++){
		cout<<"  "<<c[i][0]<<" - "<<c[i][1]<<" - "<<c[i][2]<<endl;
	}	
	
	system("PAUSE");
	return 0;
}

void SortC(void){
	int tmp;
	for (int t=0;t<cc/2;t++)
		for (int i=0;i<cc-1;i++){
			if (c[i][0]==c[i+1][0] && c[i][1]>c[i+1][1]){
				
				tmp=c[i][0];
				c[i][0]=c[i+1][0];
				c[i+1][0]=tmp;
				
				tmp=c[i][1];
				c[i][1]=c[i+1][1];
				c[i+1][1]=tmp;
				
				tmp=c[i][2];
				c[i][2]=c[i+1][2];
				c[i+1][2]=tmp;
			}
		}
	//
}

