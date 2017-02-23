#include<iostream>
#include<sstream>
#include<string>
using namespace std;

int wtoi(string s) {
  if(s=="negative") return -1;
  else if(s=="zero") return 0;
  else if(s=="one") return 1;
  else if(s=="two") return 2;
  else if(s=="three") return 3;
  else if(s=="four") return 4;
  else if(s=="five") return 5;
  else if(s=="six") return 6;
  else if(s=="seven") return 7;
  else if(s=="eight") return 8;
  else if(s=="nine") return 9;
  else if(s=="ten") return 10;
  else if(s=="eleven") return 11;
  else if(s=="twelve") return 12;
  else if(s=="thirteen") return 13;
  else if(s=="fourteen") return 14;
  else if(s=="fifteen") return 15;
  else if(s=="sixteen") return 16;
  else if(s=="seventeen") return 17;
  else if(s=="eighteen") return 18;
  else if(s=="nineteen") return 19;
  else if(s=="twenty") return 20;
  else if(s=="thirty") return 30;
  else if(s=="forty") return 40;
  else if(s=="fifty") return 50;
  else if(s=="sixty") return 60;
  else if(s=="seventy") return 70;
  else if(s=="eighty") return 80;
  else if(s=="ninety") return 90;
  else if(s=="hundred") return 100;
  else if(s=="thousand") return 1000;
  else if(s=="million") return 1000000;
}

int main()
{
  string in, word;
  while(getline(cin, in)) {
    stringstream ss(in);
    int sum = 0;
    int tsum = 0;
    int neg = false;
    while(ss >> word) {
      int n = wtoi(word);
      if(n == -1) neg = true;
      else if(n == 100 || n == 1000 || n == 1000000) {
        sum += tsum*n;
        tsum = 0;
      }
      else tsum += n;
    }
    sum += tsum;
    if(neg) sum = -sum;
    cout << sum << '\n';
  }
}
