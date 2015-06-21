#include <bits/stdc++.h>
using namespace std;

int minuto,sec,micr,flag;
string minutes,seconds,micro,aux;


void read_input(){

	cin>>aux;


	flag = 0;
	for (int i = 0; i < aux.length(); ++i)
	{
		if ((aux[i]!='m') && (flag<1))
		{
			minutes = minutes+aux[i];
		} 
		else if	((aux[i]!='m') && (aux[i]!='.') && (flag<2))
		{
			seconds = seconds+aux[i];
		}
		else if ((aux[i]!='m') && (aux[i]!='.') && (aux[i]!='s') && (flag<3))
		{
			micro = micro+aux[i];
		}
		if ((aux[i]=='m') || (aux[i]=='s') || (aux[i]=='.'))
		{
			flag++;
		}
	}

	sec = (atoi(minutes.c_str()) * 60) + (atoi(seconds.c_str()));

	stringstream convert; //stringstream used for the conversion

	convert << sec; //add the value of Number to the characters in the stream

	seconds = convert.str();

	
	cout<<seconds + "." + micro<<"\n";
}

int main(){

	for (int i = 0; i < 30; ++i)
	{
		minutes = "";
		seconds	= "";
		micro 	= "";
		aux		= "";

		minuto	= 0;
		sec 	= 0;
		micr 	= 0;
		flag	= 0;
		read_input();
	}

	return 0;
}