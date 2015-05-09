#include <bits/stdc++.h>

#define gcd 						__gcd
#define rbit						__builtin_ffs // returns 1 + index of least significant 1-bit of x
#define lzero 						__builtin_clz // returns number of leading 0-bits of x
#define tzero   					__builtin_ctz // returns number of trailing 0-bits of x
#define	on_bits						__builtin_popcount //returns number of 1-bits of x
#define s(n)                        scanf("%d",&n)
#define p(n)						printf("%d",n)
#define sc(n)                       scanf("%c",&n)
#define maX(a,b)                    ( (a) > (b) ? (a) : (b))
#define miN(a,b)                    ( (a) < (b) ? (a) : (b))

#define w(t)						while(t--)
#define c(n)						cin>>n
#define co(n)						cout<<n<<"\n"
#define ss(n)                       scanf("%s",n)
#define sl(n)                       scanf("%lld",&n)
#define sf(n)                       scanf("%lf",&n)

#define pb(n)						push_back(n)

#define vi							vector<int>
#define si							stack<int>
#define mp 							map<int, int>
#define mp_cf						map<char, vector<int> > // char frequency map
#define l(n)						n.length()
#define f(i, n)						for(int i = 0; i < n; i++)


using namespace std;

int main(){
	int test;
	s(test);
	string word;
	int alphabets[26];
	fill(alphabets + 0, alphabets + 26, 0);
	int count = 0;
	mp_cf my_map;
	mp_cf::iterator itr;
	vector<int>::iterator vitr;
	w(test){
		c(word);
		int wlen = l(word);
		f(i, wlen){
			alphabets[word[i] - 'a']++;
			my_map[word[i]].pb(i);
		}
		for(itr = my_map.begin(); itr != my_map.end(); itr++){
			if(itr->second.size() > 1){
				int temp_arr[itr->second.size()];
				int i = 0;
				for(vitr = itr->second.begin(); vitr != itr->second.end(); vitr++){
					temp_arr[i] = *vitr;
					i++;	
				}
				//co(i);
				for(int j = 0; j < i; j++){
					for(int k = j + 1; k < i; k++){
						if(temp_arr[k] - temp_arr[j] > 1){
							string p_check = word.substr(temp_arr[j], (temp_arr[k] - temp_arr[j]) + 1);
							//co(p_check);
							if(p_check == string(p_check.rbegin(), p_check.rend()))
								count += p_check.length() - 2;
							else{
								count++;
								int i = 1;
								int pos_1 = temp_arr[j];
								int pos_2 = temp_arr[k];
								int sum_1 = word[pos_1];
								//cout<<sum_1<<":"<<word[pos_1]<<"\n";
								int sum_2 = word[pos_2];
								//cout<<sum_2<<":"<<word[pos_2]<<"\n";
								while(1){
									if(pos_2 + i >= wlen)
										break;
									else{
										sum_1 += word[pos_1 + i];
										//cout<<sum_1<<":"<<word[pos_1 + i]<<"\n";
										sum_2 += word[pos_2 + i];
										//cout<<sum_2<<":"<<word[pos_2 + i]<<"\n";
										if(sum_1 == sum_2)
											count++;
									}
									i++;
								}
								sum_1 = word[pos_1];
								sum_2 = word[pos_2];
								while(1){
									pos_1 += 1;
									pos_2 -= 1;
									if(pos_1 >= pos_2)
										break;
									sum_1 += word[pos_1];
									sum_2 += word[pos_2];
									if(sum_1 == sum_2)
										count++;
								}
							}
						}
					}
				}
			}
		}
		f(i, 26){
			if(alphabets[i] == 2)
				count++;
			else if(alphabets[i] > 2)
				count += (alphabets[i] * (alphabets[i] - 1)) / 2;
		}
		co(count);
		count = 0;
		my_map.clear();
		fill(alphabets + 0, alphabets + 26, 0);
	}
	return 0;
}

/*
10
ifailuhkqqhucpoltgtyovarjsnrbfpvmupwjjjfiwwhrlkpekxxnebfrwibylcvkfealgonjkzwlyfhhkefuvgndgdnbelgruel
gffryqktmwocejbxfidpjfgrrkpowoxwggxaknmltjcpazgtnakcfcogzatyskqjyorcftwxjrtgayvllutrjxpbzggjxbmxpnde
mqmtjwxaaaxklheghvqcyhaaegtlyntxmoluqlzvuzgkwhkkfpwarkckansgabfclzgnumdrojexnrdunivxqjzfbzsodycnsnmw
ofeqjnqnxwidhbuxxhfwargwkikjqwyghpsygjxyrarcoacwnhxyqlrviikfuiuotifznqmzpjrxycnqktkryutpqvbgbgthfges
zjekimenscyiamnwlpxytkndjsygifmqlqibxxqlauxamfviftquntvkwppxrzuncyenacfivtigvfsadtlytzymuwvpntngkyhw
ioqfhajbwdfnudqfsjhikzdjcbdymoecaokeomuimlzcaqkfmvquarmvlnrurdblzholugvwtkunirmnmsatrtbqlioauaxbcehl
kaggklnwxoigxncgxnkrtdjnoeblhlxsblnqitdkoiftxnsafukbdhasdeihlhfrqkfzqhvnsmsgnrayhsyjsniutmgpfjmssfsg
fhithnigqftuzzgpdiquhlsozksxxfreddmsmvqgfgzntphmgggszwtkcbmjsllwtukgqvpvxvmatuanbeossqwtpgzbagaukmta
rqjfiszbigkdqxkfwtsbvksmfrffoanseuenvmxzsugidncvtifqesgreupsamtsyfrsvwlvhtyzgjgnmsowjwhovsmfvwuniasw
dxskilnpkkdxwpeefvgkyohnwxtrrtxtckkdgnawrdjtcpzplywyxmwtemwmtklnclqccklotbpsrkazqolefprenwaozixvlxhu
399
471
370
403
428
412
472
457
467
447
5
ifailuhkqqhucpoltgtyovarjsnrbfpvmupwjjjfiwwhrlkpekxxnebfrwibylcvkfealgonjkzwlyfhhkefuvgndgdnbelgruel
gffryqktmwocejbxfidpjfgrrkpowoxwggxaknmltjcpazgtnakcfcogzatyskqjyorcftwxjrtgayvllutrjxpbzggjxbmxpnde
mqmtjwxaaaxklheghvqcyhaaegtlyntxmoluqlzvuzgkwhkkfpwarkckansgabfclzgnumdrojexnrdunivxqjzfbzsodycnsnmw
ofeqjnqnxwidhbuxxhfwargwkikjqwyghpsygjxyrarcoacwnhxyqlrviikfuiuotifznqmzpjrxycnqktkryutpqvbgbgthfges
zjekimenscyiamnwlpxytkndjsygifmqlqibxxqlauxamfviftquntvkwppxrzuncyenacfivtigvfsadtlytzymuwvpntngkyhw
399
471
370
403
428

7
pvmupwjjjf
aaabbb
ovarjsnrbf
ifailuhkqq
abba
abcd
aocddcoa
6
8
2
3
4
0
16
*/