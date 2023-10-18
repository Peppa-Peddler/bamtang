#include <iostream>
#include <algorithm>

using namespace std;

string input(){
	return
		"Bgc-bfufb tegaedppqna ql aggv zge xof tegaedppfe\'l lgjb.\n"
		"Xof adpf vflqanfe logjbvn\'x hf pdwqna d cgebv qn coqro xof tbdkfe ql mjlx d lpdbb tdex. Xof tbdkfe QL XOF HGLL; qx\'l kgje vjxk xg fnxfexdqn oqp ge ofe.\n"
		"Zgrjl ql d pdxxfe gz vfrqvqna codx xoqnal kgj def ngx agqna xg vg.\n"
		"Xof rglx gz dvvqna d zfdxjef qln\'x mjlx xof xqpf qx xdwfl xg rgvf qx. Xof rglx dblg qnrbjvfl xof dvvqxqgn gz dn ghlxdrbf xg zjxjef fstdnlqgn. Xof xeqrw ql xg tqrw xof zfdxjefl xodx vgn\'x zqaox fdro gxofe. - Mgon Rdepdrw.\n"
		"(ccc.adpdljxed.rgp/uqfc/nfcl/234346?utkjpvbjr)\n"
		"(ccc.hedqnkijgxf.rgp/ijgxfl/djxogel/m/mgon_rdepdrw.oxpb)";
}

string decryptMessage(string message, string freqLang){

	int n_Lang = 'z' - 'a' + 1;

	pair<int, int> freq[ n_Lang ];

	for(int i = 0; i < n_Lang ; i++)
		freq[ i ] = make_pair(0, i);

	for(char c: message)
		if(isalpha(c))
			freq[ tolower(c) - 'a' ].first--;

	sort(freq, freq + n_Lang);

	int map[ n_Lang ];
	for(int i = 0; i < freqLang.length() ; i++)
		map[ freq[ i ].second ] = freqLang[ i ] - 'A';

	for( int i = 0; i < message.length() ; i++ ){
		char c = message[ i ];
		if( !isalpha(c) ) continue;
		char a = isupper(c) ? 'A':'a';
		message[ i ] = map[ c - a ] + a;
	}
	return message;
}

int main(){
	string message = input();
	string freqLang = "TEOAISRHNUCMDLGWFPYKJBVQX";
	cout << decryptMessage(message, freqLang) << endl;
}
