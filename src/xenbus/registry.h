/* Copyright (c) Citrix Systems Inc.
 * All rights reserved.
 * 
 * Redistribution and use in source and binary forms, 
 * with or without modification, are permitted provided 
 * that the following conditions are met:
 * 
 * *   Redistributions of source code must retain the above 
 *     copyright notice, this list of conditions and the 
 *     following disclaimer.
 * *   Redistributions in binary form must reproduce the above 
 *     copyright notice, this list of conditions and the 
 *     following disclaimer in the documentation and/or other 
 *     materials provided with the distribution.
 * 
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND 
 * CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, 
 * INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF 
 * MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE 
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR 
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, 
 * SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, 
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR 
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS 
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, 
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING 
 * NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE 
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF 
 * SUCH DAMAGE.
 */

#ifndef _XENBUS_REGISTRY_H
#define _XENBUS_REGISTRY_H

#include <ntddk.h>

extern NTSTATUS
RegistryInitialize(
    IN PUNICODE_STRING  Path
    );

extern VOID
RegistryTeardown(
    VOID
    );

extern NTSTATUS
RegistryOpenServiceKey(
    IN  ACCESS_MASK DesiredAccess,
    OUT PHANDLE     Key
    );

extern NTSTATUS
RegistryOpenSoftwareKey(
    IN  PDEVICE_OBJECT  DeviceObject,
    IN  ACCESS_MASK     DesiredAccess,
    OUT PHANDLE         Key
    );

extern NTSTATUS
RegistryOpenHardwareKey(
    IN  PDEVICE_OBJECT  DeviceObject,
    IN  ACCESS_MASK     DesiredAccess,
    OUT PHANDLE         Key
    );

extern NTSTATUS
RegistryOpenSubKey(
    IN  HANDLE      Key,
    IN  PCHAR       Name,
    IN  ACCESS_MASK DesiredAccess,
    OUT PHANDLE     SubKey
    );

extern NTSTATUS
RegistryCreateSubKey(
    IN  HANDLE      Key,
    IN  PCHAR       Name
    );

extern NTSTATUS
RegistryDeleteSubKey(
    IN  HANDLE      Key,
    IN  PCHAR       Name
    );

extern NTSTATUS
RegistryEnumerateSubKeys(
    IN  HANDLE      Key,
    IN  NTSTATUS    (*Callback)(PVOID, HANDLE, PCHAR),
    IN  PVOID       Context
    );

extern NTSTATUS
RegistryEnumerateValues(
    IN  HANDLE      Key,
    IN  NTSTATUS    (*Callback)(PVOID, HANDLE, PCHAR),
    IN  PVOID       Context
    );

extern NTSTATUS
RegistryQueryDwordValue(
    IN  HANDLE          Key,
    IN  PCHAR           Name,
    OUT PULONG          Value
    );
    
extern NTSTATUS
RegistryUpdateDwordValue(
    IN  HANDLE          Key,
    IN  PCHAR           Name,
    IN  ULONG           Value
    );
    
extern NTSTATUS
RegistryQuerySzValue(
    IN  HANDLE          Key,
    IN  PCHAR           Name,
    OUT PANSI_STRING    *Array
    );

extern NTSTATUS
RegistryQuerySystemStartOptions(
    OUT PANSI_STRING    *Options
    );

extern VOID
RegistryFreeSzValue(
    IN  PANSI_STRING    Array
    );

extern NTSTATUS
RegistryUpdateSzValue(
    IN  HANDLE          Key,
    IN  PCHAR           Name,
    IN  ULONG           Type,
    ...
    );

extern VOID
RegistryCloseKey(
    IN  HANDLE  Key
    );

#endif  // _XENBUS_REGISTRY_H
