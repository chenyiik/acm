#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
double x;
const int T=200;
double a[T]={//������
0.707106781187,
1.000000000000,
0.000000000354,
2828427121.917762756348,
34.985711369072,
1.019546313624,
50.159744815938,
24.592943830122,
12.529964086142,
10.803106091615,
30.413812651491,
13.947496378714,
27.586228448267,
23.769728648009,
29.017219544521,
22.198115484214,
17.515101642820,
5.398021556080,
3.801609835618,
46.615448083227,
52.399868664625,
15.094403449759,
58.694122363317,
25.632011235953,
7.538859643836,
10.838479539014,
13.451063841298,
8.924419072767,
31.016124838542,
17.769931381430,
203.022166277478,
286.769942636951,
83.638156084643,
56.400348797245,
120.747670784989,
568.979788744732,
299.082880119280,
140.719579305795,
426.378560984599,
142.077443670697,
278.772308524358,
20.261185074560,
143.596992059163,
248.169297053443,
33.961861516333,
297.405447159261,
569.899113878939,
256.844310818830,
128.724512040248,
299.816610613888,
77.620812665167,
212.207542553401,
78.068295501057,
66.294771299740,
318.662831218202,
62.999073287345,
352.567723990725,
165.109054869804,
274.869059735722,
49.383274022413,
664.206293255341,
2298.793161639385,
2090.274862308783,
1262.413957464032,
2382.290704343196,
303.639975746518,
1442.316026210910,
1145.709387235699,
1862.493819156532,
210.737810427004,
2704.193225344668,
2068.742613279864,
1561.307785159608,
1869.404718085412,
3191.159820504138,
2396.487846829189,
914.343539760836,
1064.472169669081,
1108.259897316509,
5405.703007010282,
2698.817889373049,
1084.197860171288,
568.043132165155,
1113.881950657250,
791.344492187226,
1324.227321874911,
1115.377066287451,
5098.302168369388,
2448.657183029099,
4190.963731649321,
15714.985109760684,
25624.182727615462,
7358.224582057821,
5872.493123570100,
12229.062315701993,
25271.767620685507,
42923.379934483259,
12456.402891685866,
5906.949105356563,
19544.906344109200,
31961.166289206889,
2894.205268096247,
26030.689656634149,
13731.888207703541,
32199.965621099658,
9754.372036887609,
34388.935796573358,
20668.001669247078,
47142.912086548065,
23062.626931900017,
18790.606722508990,
38205.134537127335,
5778.210968803406,
22592.449048299302,
38320.789096781395,
15780.447205323428,
16282.812116042507,
22028.288836030883,
18084.595931344444,
11166.219145261301,
170533.994783049333,
182463.875616517587,
68317.246087646126,
274270.207498007338,
123122.327544600936,
290409.892436535272,
171498.206069334730,
83931.200330985375,
54750.899946941514,
236703.066995339119,
123079.716879062398,
309979.772904620331,
103363.855739827472,
30023.749016403664,
116599.211047931196,
154386.045935496542,
100932.640731331310,
157247.904819110379,
87401.127085625310,
356299.275216776179,
328548.104728213453,
336988.935604716826,
162801.123489415011,
40704.627071132832,
295605.006853740546,
444596.344565494626,
188780.776926571620,
181528.519040320680,
93586.325496837409,
416872.001075869834,
1321605.243948265444,
359766.548859808594,
168087.637576452835,
541666.921216350398,
451394.123488554091,
560669.963669358753,
1314318.098335200921,
852042.764324068441,
241430.091450920852,
1311504.197805409553,
705639.917087773792,
973674.267009136267,
415287.075370731880,
814604.481051098905,
854112.441175048123,
524416.660719463718,
1143547.728938171174,
147936.588915656699,
425207.552979536122,
860017.423279900802,
605582.222592221224,
1102165.203355537727,
558966.515477447887,
1132171.560198221356,
247764.534240294830,
726525.212140175165,
582539.876043166500,
558278.630071042571,
280959.277740204299,
746860.802363727707,
242012.505414493004,
112.058020685714,
51.948355497004,
40.647028736298,
575.884039971563,
654.159766417960,
1500.801452557932,
215.688822198726,
2337.743356316086,
5137.017033259672,
4301.377686276805,
5428.744237850960,
39478.037349898739,
74917.296354046310,
41338.828732802773,
26216.756931397904,
79816.370048513942,
80648.471694800755,
63698.225108710838,
59414.397042367833
};
int main(int argc, char** argv){
  for(int i=0;i<T;i++){//������
    if(scanf("%lf",&x)!=1){
      puts("WA");
      return 0;
    }
    if(isnan(x)){
      puts("WA");
      return 0;
    }
    if(!(fabs(x-a[i])<=(1e-6)*max(1.0,fabs(a[i])))){//�޸�<=����ľ���
      puts("WA");
      return 0;
    }
  }
  puts("AC");
  return 0;
}