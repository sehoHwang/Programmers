/** 문제설명 **/

/*
    가로가 Wcm, 세로가 Hcm인 직사각형이 있다.
    모든 격자 칸은 1*1 크기이며 이를 절반으로 자른다.
    자른 후에 사용할 수 있는 격자의 갯수를 반환하라.
*/

/** 솔루션 **/

/*
    처음에는 도형의 모양과 규칙성에 대해 접근을 하였으나 최대 공약수를 이용해야 하는 것 외에는 큰 수확이 없었다.
    그러다가 식으로 표현을 해보았다.

    * 각 종이 크기에 대한 잘려나가는 종이 수

    2*2 => 2개      3*2 => 4개
    2*3 => 3개      3*3 => 3개
    2*4 => 4개      3*4 => 6개

    위에서 알 수 있듯이 w와 h를 더한 수에 최대공약수를 빼주니까 식이 성립하였다.

    
*/

using namespace std;

long long getCommon(int a, int b)
{
	long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}

long long solution(int w,int h) {
    long long W = w;    
    long long H = h;
    long long tmp=(w+h)-getCommon(w,h);
    
    return (W*H)-tmp;
}

