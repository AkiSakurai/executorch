/*
 * Copyright (c) Google Inc. and affiliates.
 * All rights reserved.
 *
 * This source code is licensed under the MIT license.
 */

/*
 * Adapted from: https://code.google.com/archive/p/mman-win32/
 *
 * mman-win32
 * mman library for Windows
 *
 * A light implementation of the mmap functions for MinGW.
 *
 * The mmap-win32 library implements a wrapper for mmap functions around the
 * memory mapping Windows API.
 */

#pragma once

#ifndef _WIN32_WINNT // Allow use of features specific to Windows XP or later.
#define _WIN32_WINNT \
  0x0501 // Change this to the appropriate value to target other versions of
         // Windows.
#endif

/* All the headers include this file. */
#ifndef _MSC_VER
#include <_mingw.h>
#endif

#include <sys/types.h>

#ifdef __cplusplus
extern "C" {
#endif

#define PROT_NONE 0
#define PROT_READ 1
#define PROT_WRITE 2
#define PROT_EXEC 4

#define MAP_FILE 0
#define MAP_SHARED 1
#define MAP_PRIVATE 2
#define MAP_TYPE 0xf
#define MAP_FIXED 0x10
#define MAP_ANONYMOUS 0x20
#define MAP_ANON MAP_ANONYMOUS

#define MAP_FAILED ((void*)-1)

/* Flags for msync. */
#define MS_ASYNC 1
#define MS_SYNC 2
#define MS_INVALIDATE 4

void* mmap(void* addr, size_t len, int prot, int flags, int fildes, off_t off);
int munmap(void* addr, size_t len);
int mprotect(void* addr, size_t len, int prot);
int msync(void* addr, size_t len, int flags);
int mlock(const void* addr, size_t len);
int munlock(const void* addr, size_t len);

#ifdef __cplusplus
};
#endif
