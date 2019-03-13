// https://dsa.cs.tsinghua.edu.cn/oj/problem.shtml?id=1144
// 输入
// 共n+1行。
// 第1行为1个整数n，表示灯塔的总数。
// 第2到n+1行每行包含2个整数x, y，分别表示各灯塔的横、纵坐标。
// 输出
// 1个整数，表示可照亮彼此的灯塔对的数量。
// 样例
// 见英文题面
// 限制
// 对于90%的测例：1 ≤ n ≤ 3×105
// 对于95%的测例：1 ≤ n ≤ 106
// 全部测例：1 ≤ n ≤ 4×106
// 灯塔的坐标x, y是整数，且不同灯塔的x, y坐标均互异
// 1 ≤ x, y ≤ 10^8
// 时间：2 sec
// 内存：256 MB
// 提示
// 注意机器中整型变量的范围，C/C++中的int类型通常被编译成32位整数，
// 其范围为[-2^31, 2^31 - 1]，不一定足够容纳本题的输出。

#include<cstdio>
#define MAXSIZE 4000000
using namespace std;
typedef unsigned int u_int;
long long count;

// 定义点结构体
struct Point {
	u_int x, y;
};

// 输入点
Point* points = new Point[MAXSIZE];
// 辅助
Point* aux = new Point[MAXSIZE];
void MergeStruct(Point *elem, int lo, int mi, int hi) {
  Point* a = elem + lo;
  Point* c = elem + mi;
	int lb = mi - lo, lc = hi - mi;
	for(int i = 0; i < lb; aux[i] = a[i++]);
  // 如果j >= lb, 就到a中了
	for(int i = 0, j = 0, k = 0; j < lb;) {
		if(lc<=k || aux[j].x < c[k].x) a[i++] = aux[j++];
		if(k<lc && c[k].x < aux[j].x) a[i++] = c[k++];
	}
}
void Mergell(Point *elem, int lo, int mi, int hi) {
	Point* a = elem + lo;
  Point* c = elem + mi;
	int lb = mi - lo, lc = hi - mi;
	for(int i = 0; i < lb; aux[i] = a[i++]);
	for(int i = 0, j = 0, k = 0; j < lb;) {
		if(lc <= k || aux[j].y < c[k].y) {
			a[i++] = aux[j++];
			if(k<lc)count+=lc-k;//只要k不越界，那么k之后的元素个数+1就是顺序对数
		}
		if(k<lc&&c[k]<=b[j])a[i++]=c[k++];
	}
}
void MergeSort_X(Point *elem,int lo,int hi)
{
	if(hi-lo<2)return;
	int mi=(hi+lo)>>1;
	MergeSort_X(elem,lo,mi);
	MergeSort_X(elem,mi,hi);
	MergeStruct(elem,lo,mi,hi);
}
 
void MergeSort_Y(ll *elem,int lo,int hi)
{
	if(hi-lo<2)return;
	int mi=(hi+lo)>>1;
	MergeSort_Y(elem,lo,mi);
	MergeSort_Y(elem,mi,hi);
	Mergell(elem,lo,mi,hi);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	scanf("%lld %lld",&points[i].x,&points[i].y);//输入，注意lld 
	MergeSort_X(points,0,n);
	for(int i=0;i<n;i++)
	y[i]=points[i].y;//保留y值 
	MergeSort_Y(y,0,n);
	printf("%lld\n",count);//输出，注意lld 
	return 0;
}