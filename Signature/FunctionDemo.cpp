#include <iostream>
#include <string>
#include <vector>
using namespace std;

int existSignature=0;

vector<string> signature;
string author="test";

std::hash<std::string> str_hash;



void addSign(const string document){
	signature.push_back(to_string(str_hash(to_string(str_hash(author))+document)));
	// signature.push_back(str_hash(to_string(str_hash(author))+document));
	existSignature++;
}

bool checkSign(const string document){//always check the last one 

	string sign1=signature[signature.size()-1];
	string sign2=to_string(str_hash(to_string(str_hash(author))+document));

		if(sign1==sign2){
			cout<<"Success! Document match the signature."<<std::endl;
		}
		else{
			cout<<"Wrong! Don`t match!"<<std::endl;
		}
	return sign1==sign2;

}
int main(){

string document;

document="I have 200 doller.";

addSign(document);

document="I have 300 doller.";

addSign(document);

checkSign(document);

document="I have 30000 doller.";//illegal change

checkSign(document);

// print all Sign
cout<<"order\t\tsignature"<<endl;
for(int i=0;i<signature.size();i++){
	cout<<i+1<<"\t\t\t"<<signature[i]<<std::endl;
}



}

