//Shift Cipher 
//code by Bipin Timalsina
#include<iostream>
using namespace std;
class Shift{
	public:
		int key;
		string plainText,cipherText;
		string getPlainText(){
			cout<<"Enter plain Text "<<endl;
			cin>>plainText;
			return plainText;
		}
		string getCipherText(){
			cout<<"Enter Ciphertext "<<endl;
			cin>>cipherText;
			return cipherText;
		}
		int getKey(){
			cout<<"Enter the Key "<<endl;
			cin>>key;
			return key;
		}
		//function to handle negative module since c++ cant do as we need
			int mod(int a, int b) {
  				int	c = a % b;
  				return (c < 0) ? c + b : c;
			}
		//functon for encryption 
		void encrypt(string msg,int k){
			int len = msg.length();
			char p[len],c[len];
			
			for(int i = 0; i<len;i++){
				//converting into lowercase and storing in char array
				
				p[i]=tolower(msg[i]);
				int index= int(p[i])-97;
				int  e= mod((index+key),26);
				char ca= e+97;
				c[i]=ca;
	
			}
			cout<<"The encrypted message is :"<<endl;
			for(int i=0;i<len;i++){
					c[i]=c[i]-32;
					cout<<c[i];
			} 		
		}
		//functon for decryption 
		void decrypt(string msg,int k){
			int len = msg.length();
			char p[len],c[len];
			
			for(int i = 0; i<len;i++){
				//converting into uppercase and storing in char array
				
				p[i]=toupper(msg[i]);
				int index= int(p[i])-65;
				int  e= mod((index-key),26);
				char ca= e+65;
				cout<<e<<"\t"<<ca;
				c[i]=ca;
			}
			cout<<"The plaintext after decryption:"<<endl;
				for(int i=0;i<len;i++){
						c[i]=c[i]+32;
						cout<<c[i];
				} 		
		}
};

int main(){
	Shift s;
	int k;
	string text;
	char choice;
	char more;
	//repeat till user want to encrypt/decrypt
	do{
		cout<<"Do you want to encrypt or decrypt?(press e or d)"<<endl;
		cin>>choice;
		k = s.getKey();
		if(choice=='e')
		{
		text = s.getPlainText();
		s.encrypt(text,k);	
		}
		else{
		text = s.getCipherText();
		s.decrypt(text,k);
		}
	cout<<"\n \n Want to perform more encryption/decryption?(press y or n) \n";
	cin>>more;
	}while(more=='y');
	return 0;
}
