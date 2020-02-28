#include<bits/stdc++.h>
#include<Windows.h>
using namespace std;

int main()
{
    STARTUPINFO startInfo = {0};
    PROCESS_INFORMATION processInfo = {0};

    BOOL bSuccess = CreateProcess(TEXT("C:\\Program Files (x86)\\Notepad++\\notepad++.exe"),NULL,NULL,NULL,
                    FALSE,NULL,NULL,NULL,&startInfo, &processInfo);

    if(bSuccess){
        cout<<"Process started\n";
        cout<<"Process ID :  "<<processInfo.dwProcessId<<endl;
    }
    else{
        cout<<"Error : "<<GetLastError()<<endl;
    }
    cin.get();
    return 0;
}
