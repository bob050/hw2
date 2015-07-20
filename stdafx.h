// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>



// TODO: reference additional headers your program requires here
#include <Windows.h>
#include <stdint.h>
#include <crtdbg.h>
#include <strsafe.h>
#include "FileIoHelperClass.h"

void print(_In_ const char* fmt, _In_ ...);
bool is_file_existsW(_In_ const wchar_t* file_path);
wchar_t* get_current_directory(void);

#define LL_DEBG		0
#define LL_INFO		1
#define LL_ERRR		2
#define LL_NONE		3
#define log_err		write_to_console( LL_ERRR, __FUNCTIONW__, 
#define log_info	write_to_console( LL_INFO, __FUNCTIONW__, 
#define log_dbg		write_to_console( LL_DEBG, __FUNCTIONW__, 
#define log_msg		write_to_console( LL_NONE, __FUNCTIONW__, 
#define log_end		);
