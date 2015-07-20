// ic.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdint.h>
#include <conio.h>
#include "StopWatch.h"
#include "mmio.h"



int _tmain(int argc, _TCHAR* argv[])
{
	
     _ASSERTE(create_very_big_file(L"big.txt", 500));

	/*
	StopWatch sw;
    sw.Start();
    _ASSERTE(file_copy_using_read_write(L"big.txt", L"byReadfile.txt"));
    sw.Stop();
    print("info] ReadFile's time elapsed = %f", sw.GetDurationSecond());

    StopWatch sw2;
    sw2.Start();
    _ASSERTE(file_copy_using_memory_map(L"big.txt", L"byMemoryIO.txt"));
    sw2.Stop();
    print("info] Memory I/O's time elapsed = %f", sw2.GetDurationSecond());
  ////////////////////////////////////////////////////////////////////////////
  */
	StopWatch sw3;
    sw3.Start();

	LARGE_INTEGER sizeFile;
	sizeFile.QuadPart= 5120000000; //FIle Size: 5G

	FileIoHelper * FIO;
	FIO= new FileIoHelper();
	print("%d \n", sizeFile.QuadPart);
	FIO->FIOpenForRead(L"big.txt");
	FIO->FIOCreateFile(L"byFIH.txt", sizeFile);

	LARGE_INTEGER sizeTotal;
	DWORD sizeCopy=4000000; 
	PUCHAR fileBuf=(PUCHAR)malloc(sizeCopy);
	sizeTotal.QuadPart=0;

	while( ((DWORD)sizeTotal.QuadPart+sizeCopy) < sizeFile.QuadPart)
	{
		FIO->FIOReadFromFile(sizeTotal, sizeCopy, fileBuf);
		FIO->FIOWriteToFile(sizeTotal, sizeCopy, fileBuf);
		sizeTotal.QuadPart+=sizeCopy;
		print("Total copy len's : %d \n", sizeTotal.QuadPart);
	
	}

	FIO->FIOReadFromFile(sizeTotal,sizeFile.QuadPart-sizeTotal.QuadPart, fileBuf);
	FIO->FIOWriteToFile(sizeTotal, sizeFile.QuadPart-sizeTotal.QuadPart, fileBuf);
		
	sw3.Stop();
    
	delete FIO;

	return 0;
}

