package main

type Stall struct {
	n int
	k int
}

func main() {

}

func checkStalls(input int, stalls []Stall){

 for i := 1; i < input; i ++ {

 }

 	spaces := make(map[int]int)
	//for(int tc = 1; i <= t; tc++) {
		//ll n, k; scanf("%lld %lld\n", &n, &k);
		spaces.clear();
		spaces[n]++;
	
		//ll ls = -1, rs = -1;
		while(k > 0) {
		  auto it = prev(spaces.end());
		  ll size = it->first, count = it->second;
		  spaces.erase(it);
	
		  ls = (size - 1) / 2;
		  rs = size / 2;
		  spaces[ls] += count;
		  spaces[rs] += count;
		  k -= count;
		}
		printf("Case #%d: %lld %lld\n", tc, max(ls, rs), min(ls, rs));
	  }
	  return 0;
}