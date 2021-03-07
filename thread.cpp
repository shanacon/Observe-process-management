#include<syscall.h>
#include<sys/types.h>
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;

int main()
{
	int pid,r;
	cout<<"input pid:";
	cin>>pid;
	r = syscall(359,pid);
	cout<<"process in this thread group:"<<r<<endl;
}
