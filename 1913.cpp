#include <bits/stdc++.h>

using namespace std; 


struct cilindro{
  
  int base, altura, cor;
  
  cilindro(){ }
  cilindro(int base, int altura, int cor) : base(base), altura(altura), cor(cor) {} 
  bool operator < (const cilindro &other) const{
    return base > other.base;
  } 
};

bool check(int cor1, int cor2, int base1, int base2){
  if(base1 == base2 || (cor1 == 2 && cor2 == 1) || 
    (cor1 == 3 && cor2 == 2) || 
    (cor1 == 4 && cor2 == 3) ||
    (cor1 == 1 && cor2 == 4)){
    return false;
  }
  return true;
}

vector<cilindro> v;
map<string,int> s;
#define INF 0x3F3F3F3F
int n;
const int N = 1e3 + 10;
int pd[N][N]; 



int f(int at, int last){
  if(at == n){
    return 0;
  }
  
  if(pd[at][last] != -1){
    return pd[at][last];
  }
  int ans = 0;
  ans = f(at + 1, last);
  if(last == 1001 || check(v[last].cor, v[at].cor, v[at].base, v[last].base)){
    ans = max(ans, f(at + 1, at) + v[at].altura);
  }
  return pd[at][last] = ans;
}

int main(){
  
  s["VERMELHO"] = 1;
  s["LARANJA"] = 2;
  s["AZUL"] = 3;
  s["VERDE"] = 4;
  
  
  while(scanf("%d",&n), n){
    char str[22];
    memset(pd,-1,sizeof pd);
    for(int i = 0; i < n; ++i){
      int x, y;
      scanf("%d %d %s ", &x, &y, &str);
      v.push_back(cilindro(y,x,s[(string) str]));
    }
    sort(v.begin(), v.end());
  
    printf("%d centimetro(s)\n", f(0,1001));
    v.clear();
  }
    
  return 0;
}
