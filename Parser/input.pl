prolog_c([
declaration([extern, void], [function(Abort, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(UC___assert_fail, [param_no_decl([const, char], dummy_abstract_declarator), param_no_decl([const, char], dummy_abstract_declarator), param_no_decl([unsigned, int], []), param_no_decl([const, char], dummy_abstract_declarator)])]), 
function([void], function(Reach_error, []), [], 
cmp_stmts([
stmt(function_call(UC___assert_fail, ["0", "floppy_simpl3.cil-1.c", int(3), "reach_error"]))
])), 

declaration([extern, char], [function(UC___VERIFIER_nondet_char, [param_no_decl([void], [])])]), 

declaration([extern, int], [function(UC___VERIFIER_nondet_int, [param_no_decl([void], [])])]), 

declaration([extern, long], [function(UC___VERIFIER_nondet_long, [param_no_decl([void], [])])]), 

declaration([int], [function(UC_FlAcpiConfigureFloppy, [param([int], UC_DisketteExtension), param([int], UC_FdcInfo)])]), 

declaration([int], [function(UC_FlQueueIrpToThread, [param([int], UC_Irp), param([int], UC_DisketteExtension)])]), 

declaration([int], [function(UC_FloppyPnp, [param([int], UC_DeviceObject), param([int], UC_Irp)])]), 

declaration([int], [function(UC_FloppyStartDevice, [param([int], UC_DeviceObject), param([int], UC_Irp)])]), 

declaration([int], [function(UC_FloppyPnpComplete, [param([int], UC_DeviceObject), param([int], UC_Irp), param([int], UC_Context)])]), 

declaration([int], [function(UC_FlFdcDeviceIo, [param([int], UC_DeviceObject), param([int], UC_Ioctl), param([int], UC_Data)])]), 

declaration([int], [function(UC_IoBuildDeviceIoControlRequest, [param([int], UC_IoControlCode), param([int], UC_DeviceObject), param([int], UC_InputBuffer), param([int], UC_InputBufferLength), param([int], UC_OutputBuffer), param([int], UC_OutputBufferLength), param([int], UC_InternalDeviceIoControl), param([int], UC_Event), param([int], UC_IoStatusBlock)])]), 

declaration([int], [function(UC_IoDeleteSymbolicLink, [param([int], UC_SymbolicLinkName)])]), 

declaration([int], [function(UC_IoQueryDeviceDescription, [param([int], UC_BusType), param([int], UC_BusNumber), param([int], UC_ControllerType), param([int], UC_ControllerNumber), param([int], UC_PeripheralType), param([int], UC_PeripheralNumber), param([int], UC_CalloutRoutine), param([int], UC_Context)])]), 

declaration([int], [function(UC_IoRegisterDeviceInterface, [param([int], UC_PhysicalDeviceObject), param([int], UC_InterfaceClassGuid), param([int], UC_ReferenceString), param([int], UC_SymbolicLinkName)])]), 

declaration([int], [function(UC_IoSetDeviceInterfaceState, [param([int], UC_SymbolicLinkName), param([int], UC_Enable)])]), 

declaration([int], [function(UC_IofCallDriver, [param([int], UC_DeviceObject), param([int], UC_Irp)])]), 

declaration([int], [function(UC_KeSetEvent, [param([int], UC_Event), param([int], UC_Increment), param([int], UC_Wait)])]), 

declaration([int], [function(UC_KeWaitForSingleObject, [param([int], UC_Object), param([int], UC_WaitReason), param([int], UC_WaitMode), param([int], UC_Alertable), param([int], UC_Timeout)])]), 

declaration([int], [function(UC_ObReferenceObjectByHandle, [param([int], UC_Handle), param([int], UC_DesiredAccess), param([int], UC_ObjectType), param([int], UC_AccessMode), param([int], UC_Object), param([int], UC_HandleInformation)])]), 

declaration([int], [function(UC_PsCreateSystemThread, [param([int], UC_ThreadHandle), param([int], UC_DesiredAccess), param([int], UC_ObjectAttributes), param([int], UC_ProcessHandle), param([int], UC_ClientId), param([int], UC_StartRoutine), param([int], UC_StartContext)])]), 

declaration([int], [function(UC_ZwClose, [param([int], UC_Handle)])]), 

declaration([int], [function(UC_IofCompleteRequest, [param([int], UC_Irp), param([int], UC_PriorityBoost)])]), 

declaration([extern, int], [function(UC___VERIFIER_nondet_int, [])]), 

declaration([int], [UC_FloppyThread]), 

declaration([int], [UC_KernelMode]), 

declaration([int], [UC_Suspended]), 

declaration([int], [UC_Executive]), 

declaration([int], [UC_DiskController]), 

declaration([int], [UC_FloppyDiskPeripheral]), 

declaration([int], [UC_FlConfigCallBack]), 

declaration([int], [UC_MaximumInterfaceType]), 

declaration([int], [UC_MOUNTDEV_MOUNTED_DEVICE_GUID]), 

declaration([int], [MyStatus]), 

declaration([int], [S]), 

declaration([int], [UC_UNLOADED]), 

declaration([int], [UC_NP]), 

declaration([int], [UC_DC]), 

declaration([int], [UC_SKIP1]), 

declaration([int], [UC_SKIP2]), 

declaration([int], [UC_MPR1]), 

declaration([int], [UC_MPR3]), 

declaration([int], [UC_IPC]), 

declaration([int], [Pended]), 

declaration([int], [CompRegistered]), 

declaration([int], [LowerDriverReturn]), 

declaration([int], [SetEventCalled]), 

declaration([int], [CustomIrp]), 
function([void], function(ErrorFn, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([label_stmt(ERROR, 
cmp_stmts([
stmt(function_call(Reach_error, [])), 
stmt(function_call(Abort, []))
])), 
return_stmt

])
])), 
function([void], function(UC__BLAST_init, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
stmt(assign(UC_UNLOADED, int(0))), 
stmt(assign(UC_NP, int(1))), 
stmt(assign(UC_DC, int(2))), 
stmt(assign(UC_SKIP1, int(3))), 
stmt(assign(UC_SKIP2, int(4))), 
stmt(assign(UC_MPR1, int(5))), 
stmt(assign(UC_MPR3, int(6))), 
stmt(assign(UC_IPC, int(7))), 
stmt(assign(S, UC_UNLOADED)), 
stmt(assign(Pended, int(0))), 
stmt(assign(CompRegistered, int(0))), 
stmt(assign(LowerDriverReturn, int(0))), 
stmt(assign(SetEventCalled, int(0))), 
stmt(assign(CustomIrp, int(0))), 
return_stmt

])
])), 

declaration([int], [initialised(UC_PagingReferenceCount, int(0))]), 

declaration([int], [initialised(UC_PagingMutex, int(0))]), 
function([int], function(UC_FlAcpiConfigureFloppy, [param([int], UC_DisketteExtension), param([int], UC_FdcInfo)]), [], 
cmp_stmts([
cmp_stmts([
return_stmt((int(0)))

])
])), 
function([int], function(UC_FlQueueIrpToThread, [param([int], UC_Irp), param([int], UC_DisketteExtension)]), [], 
cmp_stmts([
declaration([int], [Status]), 
declaration([int], [initialised(ThreadHandle, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_DisketteExtension__PoweringDown, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_DisketteExtension__ThreadReferenceCount, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_DisketteExtension__FloppyThread, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC_Irp__IoStatus__Status]), 
declaration([int], [UC_Irp__IoStatus__Information]), 
declaration([int], [UC_Irp__Tail__Overlay__CurrentStackLocation__Control]), 
declaration([int], [initialised(UC_ObjAttributes, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC___cil_tmp12]), 
declaration([int], [UC___cil_tmp13]), 
cmp_stmts([
if_stmt(branch(1, equal_op(UC_DisketteExtension__PoweringDown, int(1))), 
cmp_stmts([
stmt(assign(MyStatus, minus_op(int(1073741101)))), 
stmt(assign(UC_Irp__IoStatus__Status, minus_op(int(1073741101)))), 
stmt(assign(UC_Irp__IoStatus__Information, int(0))), 
return_stmt((minus_op(int(1073741101))))

]) ), 
stmt(postfix_inc_op(UC_DisketteExtension__ThreadReferenceCount)), 
if_stmt(branch(6, equal_op(UC_DisketteExtension__ThreadReferenceCount, int(0))), 
cmp_stmts([
stmt(postfix_inc_op(UC_DisketteExtension__ThreadReferenceCount)), 
stmt(postfix_inc_op(UC_PagingReferenceCount)), 
if_stmt(branch(2, equal_op(UC_PagingReferenceCount, int(1))), 
cmp_stmts([]) ), 
cmp_stmts([
stmt(assign(Status, function_call(UC_PsCreateSystemThread, [ThreadHandle, int(0), UC_ObjAttributes, int(0), int(0), UC_FloppyThread, UC_DisketteExtension])))
]), 
cmp_stmts([
if_stmt(branch(4, less_op(Status, int(0))), 
cmp_stmts([
stmt(assign(UC_DisketteExtension__ThreadReferenceCount, minus_op(int(1)))), 
stmt(postfix_dec_op(UC_PagingReferenceCount)), 
if_stmt(branch(3, equal_op(UC_PagingReferenceCount, int(0))), 
cmp_stmts([]) ), 
return_stmt((Status))

]) )
]), 
cmp_stmts([
stmt(assign(Status, function_call(UC_ObReferenceObjectByHandle, [ThreadHandle, int(1048576), int(0), UC_KernelMode, UC_DisketteExtension__FloppyThread, int(0)]))), 
stmt(function_call(UC_ZwClose, [ThreadHandle]))
]), 
cmp_stmts([
if_stmt(branch(5, less_op(Status, int(0))), 
cmp_stmts([
return_stmt((Status))

]) )
])
]) ), 
if_stmt(branch(7, equal_op(Pended, int(0))), 
cmp_stmts([
stmt(assign(Pended, int(1)))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
return_stmt((int(259)))

])
])), 
function([int], function(UC_FloppyPnp, [param([int], UC_DeviceObject), param([int], UC_Irp)]), [], 
cmp_stmts([
declaration([int], [initialised(UC_DeviceObject__DeviceExtension, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_Irp__Tail__Overlay__CurrentStackLocation, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC_Irp__IoStatus__Information]), 
declaration([int], [UC_Irp__IoStatus__Status]), 
declaration([int], [initialised(UC_Irp__CurrentLocation, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__IsRemoved, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__IsStarted, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__TargetObject, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [DisketteExtension__HoldNewRequests]), 
declaration([int], [initialised(DisketteExtension__FloppyThread, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__InterfaceString__Buffer, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__InterfaceString, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__ArcName__Length, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__ArcName, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(IrpSp__MinorFunction, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_IoGetConfigurationInformation__FloppyCount, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [IrpSp]), 
declaration([int], [DisketteExtension]), 
declaration([int], [NtStatus]), 
declaration([int], [initialised(DoneEvent, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [IrpSp___0]), 
declaration([int], [NextIrpSp]), 
declaration([int], [NextIrpSp__Control]), 
declaration([int], [IrpSp___1]), 
declaration([int], [IrpSp__Context]), 
declaration([int], [IrpSp__Control]), 
declaration([long], [UC___cil_tmp29]), 
declaration([long], [UC___cil_tmp30]), 
cmp_stmts([
stmt(assign(NtStatus, int(0))), 
stmt(postfix_inc_op(UC_PagingReferenceCount)), 
if_stmt(branch(8, equal_op(UC_PagingReferenceCount, int(1))), 
cmp_stmts([]) ), 
stmt(assign(DisketteExtension, UC_DeviceObject__DeviceExtension)), 
stmt(assign(IrpSp, UC_Irp__Tail__Overlay__CurrentStackLocation)), 
if_stmt(branch(9, DisketteExtension__IsRemoved), 
cmp_stmts([
cmp_stmts([
stmt(assign(UC_Irp__IoStatus__Information, int(0))), 
stmt(assign(UC_Irp__IoStatus__Status, minus_op(int(1073741738)))), 
stmt(assign(MyStatus, minus_op(int(1073741738)))), 
stmt(function_call(UC_IofCompleteRequest, [UC_Irp, int(0)]))
]), 
return_stmt((minus_op(int(1073741738))))

]) ), 
if_stmt(branch(34, equal_op(IrpSp__MinorFunction, int(0))), 
cmp_stmts([
goto_stmt(switch_0_0, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(33, equal_op(IrpSp__MinorFunction, int(5))), 
cmp_stmts([
goto_stmt(switch_0_5, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(32, equal_op(IrpSp__MinorFunction, int(1))), 
cmp_stmts([
goto_stmt(switch_0_5, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(31, equal_op(IrpSp__MinorFunction, int(6))), 
cmp_stmts([
goto_stmt(switch_0_6, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(30, equal_op(IrpSp__MinorFunction, int(3))), 
cmp_stmts([
goto_stmt(switch_0_6, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(29, equal_op(IrpSp__MinorFunction, int(4))), 
cmp_stmts([
goto_stmt(switch_0_4, UC_FloppyPnp)

]) , 
cmp_stmts([
if_stmt(branch(28, equal_op(IrpSp__MinorFunction, int(2))), 
cmp_stmts([
goto_stmt(switch_0_2, UC_FloppyPnp)

]) , 
cmp_stmts([
goto_stmt(switch_0_default, UC_FloppyPnp)
, 
if_stmt(branch(27, int(0)), 
cmp_stmts([label_stmt(switch_0_0, 
cmp_stmts([
stmt(assign(NtStatus, function_call(UC_FloppyStartDevice, [UC_DeviceObject, UC_Irp])))
])), 
goto_stmt(switch_0_break, UC_FloppyPnp)
, label_stmt(switch_0_5, 
if_stmt(branch(10, equal_op(IrpSp__MinorFunction, int(5))), 
cmp_stmts([]) )), 
if_stmt(branch(12, not_op(DisketteExtension__IsStarted)), 
cmp_stmts([
if_stmt(branch(11, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
]), 
return_stmt((NtStatus))

]) ), 
cmp_stmts([
stmt(assign(DisketteExtension__HoldNewRequests, int(1))), 
stmt(assign(NtStatus, function_call(UC_FlQueueIrpToThread, [UC_Irp, DisketteExtension])))
]), 
cmp_stmts([
stmt(assign(UC___cil_tmp29, cast([long], NtStatus))), 
if_stmt(branch(15, equal_op(UC___cil_tmp29, long(259))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_KeWaitForSingleObject, [DisketteExtension__FloppyThread, UC_Executive, UC_KernelMode, int(0), int(0)]))
]), 
if_stmt(branch(13, not_equal_op(DisketteExtension__FloppyThread, int(0))), 
cmp_stmts([]) ), 
stmt(assign(DisketteExtension__FloppyThread, int(0))), 
stmt(assign(UC_Irp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
if_stmt(branch(14, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
])
]) , 
cmp_stmts([
cmp_stmts([
stmt(assign(NtStatus, minus_op(int(1073741823)))), 
stmt(assign(UC_Irp__IoStatus__Status, NtStatus)), 
stmt(assign(MyStatus, NtStatus)), 
stmt(assign(UC_Irp__IoStatus__Information, int(0))), 
stmt(function_call(UC_IofCompleteRequest, [UC_Irp, int(0)]))
])
]))
]), 
goto_stmt(switch_0_break, UC_FloppyPnp)
, label_stmt(switch_0_6, 
if_stmt(branch(16, equal_op(IrpSp__MinorFunction, int(6))), 
cmp_stmts([]) )), 
if_stmt(branch(21, not_op(DisketteExtension__IsStarted)), 
cmp_stmts([
stmt(assign(UC_Irp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
if_stmt(branch(17, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
])
]) , 
cmp_stmts([
stmt(assign(UC_Irp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
stmt(assign(IrpSp___0, UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NextIrpSp, minus_op(UC_Irp__Tail__Overlay__CurrentStackLocation, int(1)))), 
stmt(assign(NextIrpSp__Control, int(0))), 
if_stmt(branch(19, not_equal_op(S, UC_NP)), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) , 
cmp_stmts([
if_stmt(branch(18, not_equal_op(CompRegistered, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) , 
cmp_stmts([
stmt(assign(CompRegistered, int(1)))
]))
])), 
cmp_stmts([
stmt(assign(IrpSp___1, minus_op(UC_Irp__Tail__Overlay__CurrentStackLocation, int(1)))), 
stmt(assign(IrpSp__Context, DoneEvent)), 
stmt(assign(IrpSp__Control, int(224))), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
]), 
cmp_stmts([
stmt(assign(UC___cil_tmp30, cast([long], NtStatus))), 
if_stmt(branch(20, equal_op(UC___cil_tmp30, long(259))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_KeWaitForSingleObject, [DoneEvent, UC_Executive, UC_KernelMode, int(0), int(0)])), 
stmt(assign(NtStatus, MyStatus))
])
]) )
]), 
cmp_stmts([
stmt(assign(DisketteExtension__HoldNewRequests, int(0))), 
stmt(assign(UC_Irp__IoStatus__Status, NtStatus)), 
stmt(assign(MyStatus, NtStatus)), 
stmt(assign(UC_Irp__IoStatus__Information, int(0))), 
stmt(function_call(UC_IofCompleteRequest, [UC_Irp, int(0)]))
])
])), 
goto_stmt(switch_0_break, UC_FloppyPnp)
, label_stmt(switch_0_4, 
stmt(assign(DisketteExtension__IsStarted, int(0)))), 
stmt(assign(UC_Irp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
if_stmt(branch(22, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
]), 
goto_stmt(switch_0_break, UC_FloppyPnp)
, label_stmt(switch_0_2, 
stmt(assign(DisketteExtension__HoldNewRequests, int(0)))), 
stmt(assign(DisketteExtension__IsStarted, int(0))), 
stmt(assign(DisketteExtension__IsRemoved, int(1))), 
if_stmt(branch(23, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(UC_Irp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
]), 
if_stmt(branch(24, not_equal_op(DisketteExtension__InterfaceString__Buffer, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_IoSetDeviceInterfaceState, [DisketteExtension__InterfaceString, int(0)]))
])
]) ), 
if_stmt(branch(25, not_equal_op(DisketteExtension__ArcName__Length, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_IoDeleteSymbolicLink, [DisketteExtension__ArcName]))
])
]) ), 
stmt(postfix_dec_op(UC_IoGetConfigurationInformation__FloppyCount)), 
goto_stmt(switch_0_break, UC_FloppyPnp)
, label_stmt(switch_0_default, stmt([])), 
if_stmt(branch(26, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_SKIP1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
cmp_stmts([
stmt(postfix_inc_op(UC_Irp__CurrentLocation)), 
stmt(postfix_inc_op(UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
])
]) , 
cmp_stmts([label_stmt(switch_0_break, stmt([]))
]))
]))
]))
]))
]))
]))
]))
])), 
stmt(postfix_dec_op(UC_PagingReferenceCount)), 
if_stmt(branch(35, equal_op(UC_PagingReferenceCount, int(0))), 
cmp_stmts([]) ), 
return_stmt((NtStatus))

])
])), 
function([int], function(UC_FloppyStartDevice, [param([int], UC_DeviceObject), param([int], UC_Irp)]), [], 
cmp_stmts([
declaration([int], [initialised(UC_DeviceObject__DeviceExtension, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(UC_Irp__Tail__Overlay__CurrentStackLocation, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC_Irp__IoStatus__Status]), 
declaration([int], [initialised(DisketteExtension__TargetObject, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [DisketteExtension__MaxTransferSize]), 
declaration([int], [initialised(DisketteExtension__DriveType, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [DisketteExtension__PerpendicularMode]), 
declaration([int], [DisketteExtension__DeviceUnit]), 
declaration([int], [DisketteExtension__DriveOnValue]), 
declaration([int], [initialised(DisketteExtension__UnderlyingPDO, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(DisketteExtension__InterfaceString, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [DisketteExtension__IsStarted]), 
declaration([int], [DisketteExtension__HoldNewRequests]), 
declaration([int], [NtStatus]), 
declaration([int], [PnpStatus]), 
declaration([int], [initialised(DoneEvent, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [FdcInfo__BufferCount]), 
declaration([int], [FdcInfo__BufferSize]), 
declaration([int], [initialised(FdcInfo__MaxTransferSize, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo__AcpiBios, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo__AcpiFdiSupported, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo__PeripheralNumber, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [FdcInfo__BusType]), 
declaration([int], [initialised(FdcInfo__ControllerNumber, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo__UnitNumber, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(FdcInfo__BusNumber, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC_Dc]), 
declaration([int], [UC_Fp]), 
declaration([int], [DisketteExtension]), 
declaration([int], [IrpSp]), 
declaration([int], [IrpSp___0]), 
declaration([int], [NextIrpSp]), 
declaration([int], [NextIrpSp__Control]), 
declaration([int], [IrpSp___1]), 
declaration([int], [IrpSp__Control]), 
declaration([int], [IrpSp__Context]), 
declaration([int], [UC_InterfaceType]), 
declaration([int], [initialised(UC_KUSER_SHARED_DATA__AlternativeArchitecture_NEC98x86, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([long], [UC___cil_tmp42]), 
declaration([int], [UC___cil_tmp43]), 
declaration([int], [UC___cil_tmp44]), 
declaration([int], [UC___cil_tmp45]), 
declaration([int], [UC___cil_tmp46]), 
declaration([int], [UC___cil_tmp47]), 
declaration([int], [UC___cil_tmp48]), 
declaration([int], [UC___cil_tmp49]), 
cmp_stmts([
stmt(assign(UC_Dc, UC_DiskController)), 
stmt(assign(UC_Fp, UC_FloppyDiskPeripheral)), 
stmt(assign(DisketteExtension, UC_DeviceObject__DeviceExtension)), 
stmt(assign(IrpSp, UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(IrpSp___0, UC_Irp__Tail__Overlay__CurrentStackLocation)), 
stmt(assign(NextIrpSp, minus_op(UC_Irp__Tail__Overlay__CurrentStackLocation, int(1)))), 
stmt(assign(NextIrpSp__Control, int(0))), 
if_stmt(branch(37, not_equal_op(S, UC_NP)), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) , 
cmp_stmts([
if_stmt(branch(36, not_equal_op(CompRegistered, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) , 
cmp_stmts([
stmt(assign(CompRegistered, int(1)))
]))
])), 
cmp_stmts([
stmt(assign(IrpSp___1, minus_op(UC_Irp__Tail__Overlay__CurrentStackLocation, int(1)))), 
stmt(assign(IrpSp__Context, DoneEvent)), 
stmt(assign(IrpSp__Control, int(224))), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [DisketteExtension__TargetObject, UC_Irp])))
]), 
cmp_stmts([
stmt(assign(UC___cil_tmp42, cast([long], NtStatus))), 
if_stmt(branch(38, equal_op(UC___cil_tmp42, long(259))), 
cmp_stmts([
cmp_stmts([
stmt(assign(NtStatus, function_call(UC_KeWaitForSingleObject, [DoneEvent, UC_Executive, UC_KernelMode, int(0), int(0)]))), 
stmt(assign(NtStatus, MyStatus))
])
]) )
]), 
cmp_stmts([
stmt(assign(FdcInfo__BufferCount, int(0))), 
stmt(assign(FdcInfo__BufferSize, int(0))), 
stmt(assign(UC___cil_tmp43, int(3080))), 
stmt(assign(UC___cil_tmp44, int(458752))), 
stmt(assign(UC___cil_tmp45, int(461832))), 
stmt(assign(UC___cil_tmp46, int(461835))), 
stmt(assign(NtStatus, function_call(UC_FlFdcDeviceIo, [DisketteExtension__TargetObject, UC___cil_tmp46, FdcInfo])))
]), 
if_stmt(branch(49, greater_or_eq_op(NtStatus, int(0))), 
cmp_stmts([
stmt(assign(DisketteExtension__MaxTransferSize, FdcInfo__MaxTransferSize)), 
if_stmt(branch(45, FdcInfo__AcpiBios), 
cmp_stmts([
if_stmt(branch(40, FdcInfo__AcpiFdiSupported), 
cmp_stmts([
cmp_stmts([
stmt(assign(NtStatus, function_call(UC_FlAcpiConfigureFloppy, [DisketteExtension, FdcInfo])))
]), 
if_stmt(branch(39, equal_op(DisketteExtension__DriveType, int(4))), 
cmp_stmts([]) )
]) , 
cmp_stmts([
goto_stmt(_L, UC_FloppyStartDevice)

]))
]) , 
cmp_stmts([label_stmt(_L, 
if_stmt(branch(41, equal_op(DisketteExtension__DriveType, int(4))), 
cmp_stmts([]) )), 
stmt(assign(UC_InterfaceType, int(0))), 
cmp_stmts([
do_while_stmt(int(1), branch(44, 
cmp_stmts([label_stmt(while_0_continue, stmt([])), 
if_stmt(branch(42, greater_or_eq_op(UC_InterfaceType, UC_MaximumInterfaceType)), 
cmp_stmts([
goto_stmt(while_1_break, UC_FloppyStartDevice)

]) ), 
cmp_stmts([
stmt(assign(FdcInfo__BusType, UC_InterfaceType)), 
stmt(assign(NtStatus, function_call(UC_IoQueryDeviceDescription, [FdcInfo__BusType, FdcInfo__BusNumber, UC_Dc, FdcInfo__ControllerNumber, UC_Fp, FdcInfo__PeripheralNumber, UC_FlConfigCallBack, DisketteExtension])))
]), 
if_stmt(branch(43, greater_or_eq_op(NtStatus, int(0))), 
cmp_stmts([
goto_stmt(while_1_break, UC_FloppyStartDevice)

]) ), 
stmt(postfix_inc_op(UC_InterfaceType))
]))), label_stmt(while_0_break, stmt([]))
]), label_stmt(while_1_break, stmt([]))
])), 
if_stmt(branch(48, greater_or_eq_op(NtStatus, int(0))), 
cmp_stmts([
if_stmt(branch(46, not_equal_op(UC_KUSER_SHARED_DATA__AlternativeArchitecture_NEC98x86, int(0))), 
cmp_stmts([
stmt(assign(DisketteExtension__DeviceUnit, FdcInfo__UnitNumber))
]) , 
cmp_stmts([
stmt(assign(DisketteExtension__DeviceUnit, FdcInfo__PeripheralNumber))
])), 
cmp_stmts([
stmt(assign(PnpStatus, function_call(UC_IoRegisterDeviceInterface, [DisketteExtension__UnderlyingPDO, UC_MOUNTDEV_MOUNTED_DEVICE_GUID, int(0), DisketteExtension__InterfaceString])))
]), 
if_stmt(branch(47, greater_or_eq_op(PnpStatus, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(PnpStatus, function_call(UC_IoSetDeviceInterfaceState, [DisketteExtension__InterfaceString, int(1)])))
])
]) ), 
stmt(assign(DisketteExtension__IsStarted, int(1))), 
stmt(assign(DisketteExtension__HoldNewRequests, int(0)))
]) )
]) ), 
cmp_stmts([
stmt(assign(UC_Irp__IoStatus__Status, NtStatus)), 
stmt(assign(MyStatus, NtStatus)), 
stmt(function_call(UC_IofCompleteRequest, [UC_Irp, int(0)]))
]), 
return_stmt((NtStatus))

])
])), 
function([int], function(UC_FloppyPnpComplete, [param([int], UC_DeviceObject), param([int], UC_Irp), param([int], UC_Context)]), [], 
cmp_stmts([
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_KeSetEvent, [UC_Context, int(1), int(0)]))
]), 
return_stmt((minus_op(int(1073741802))))

])
])), 
function([int], function(UC_FlFdcDeviceIo, [param([int], UC_DeviceObject), param([int], UC_Ioctl), param([int], UC_Data)]), [], 
cmp_stmts([
declaration([int], [NtStatus]), 
declaration([int], [Irp]), 
declaration([int], [IrpStack]), 
declaration([int], [initialised(DoneEvent, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(IoStatus, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(Irp__Tail__Overlay__CurrentStackLocation, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [IrpStack__Parameters__DeviceIoControl__Type3InputBuffer]), 
declaration([long], [UC___cil_tmp11]), 
cmp_stmts([
cmp_stmts([
stmt(assign(Irp, function_call(UC_IoBuildDeviceIoControlRequest, [UC_Ioctl, UC_DeviceObject, int(0), int(0), int(0), int(0), int(1), DoneEvent, IoStatus])))
]), 
if_stmt(branch(50, equal_op(Irp, int(0))), 
cmp_stmts([
return_stmt((minus_op(int(1073741670))))

]) ), 
cmp_stmts([
stmt(assign(IrpStack, minus_op(Irp__Tail__Overlay__CurrentStackLocation, int(1)))), 
stmt(assign(IrpStack__Parameters__DeviceIoControl__Type3InputBuffer, UC_Data)), 
stmt(assign(NtStatus, function_call(UC_IofCallDriver, [UC_DeviceObject, Irp])))
]), 
cmp_stmts([
stmt(assign(UC___cil_tmp11, cast([long], NtStatus))), 
if_stmt(branch(51, equal_op(UC___cil_tmp11, long(259))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(UC_KeWaitForSingleObject, [DoneEvent, UC_Suspended, UC_KernelMode, int(0), int(0)])), 
stmt(assign(NtStatus, MyStatus))
])
]) )
]), 
return_stmt((NtStatus))

])
])), 
function([void], function(UC_FloppyProcessQueuedRequests, [param([int], UC_DisketteExtension)]), [], 
cmp_stmts([
cmp_stmts([
return_stmt

])
])), 
function([void], function(Stub_driver_init, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
stmt(assign(S, UC_NP)), 
stmt(assign(Pended, int(0))), 
stmt(assign(CompRegistered, int(0))), 
stmt(assign(LowerDriverReturn, int(0))), 
stmt(assign(SetEventCalled, int(0))), 
stmt(assign(CustomIrp, int(0))), 
return_stmt

])
])), 
function([int], function(Main, [param_no_decl([void], [])]), [], 
cmp_stmts([
declaration([int], [Status]), 
declaration([int], [initialised(Irp, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [Pirp]), 
declaration([int], [Pirp__IoStatus__Status]), 
declaration([int], [initialised(Irp_choice, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [initialised(Devobj, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([int], [UC___cil_tmp8]), 
stmt(assign(UC_FloppyThread, int(0))), 
stmt(assign(UC_KernelMode, int(0))), 
stmt(assign(UC_Suspended, int(0))), 
stmt(assign(UC_Executive, int(0))), 
stmt(assign(UC_DiskController, int(0))), 
stmt(assign(UC_FloppyDiskPeripheral, int(0))), 
stmt(assign(UC_FlConfigCallBack, int(0))), 
stmt(assign(UC_MaximumInterfaceType, int(0))), 
stmt(assign(UC_MOUNTDEV_MOUNTED_DEVICE_GUID, int(0))), 
stmt(assign(MyStatus, int(0))), 
stmt(assign(S, int(0))), 
stmt(assign(UC_UNLOADED, int(0))), 
stmt(assign(UC_NP, int(0))), 
stmt(assign(UC_DC, int(0))), 
stmt(assign(UC_SKIP1, int(0))), 
stmt(assign(UC_SKIP2, int(0))), 
stmt(assign(UC_MPR1, int(0))), 
stmt(assign(UC_MPR3, int(0))), 
stmt(assign(UC_IPC, int(0))), 
stmt(assign(Pended, int(0))), 
stmt(assign(CompRegistered, int(0))), 
stmt(assign(LowerDriverReturn, int(0))), 
stmt(assign(SetEventCalled, int(0))), 
stmt(assign(CustomIrp, int(0))), 
cmp_stmts([
cmp_stmts([
stmt(assign(Status, int(0))), 
stmt(assign(Pirp, Irp)), 
stmt(function_call(UC__BLAST_init, []))
]), 
if_stmt(branch(56, greater_or_eq_op(Status, int(0))), 
cmp_stmts([
stmt(assign(S, UC_NP)), 
stmt(assign(CustomIrp, int(0))), 
stmt(assign(SetEventCalled, CustomIrp)), 
stmt(assign(LowerDriverReturn, SetEventCalled)), 
stmt(assign(CompRegistered, LowerDriverReturn)), 
stmt(assign(Pended, CompRegistered)), 
stmt(assign(Pirp__IoStatus__Status, int(0))), 
stmt(assign(MyStatus, int(0))), 
if_stmt(branch(52, equal_op(Irp_choice, int(0))), 
cmp_stmts([
stmt(assign(Pirp__IoStatus__Status, minus_op(int(1073741637)))), 
stmt(assign(MyStatus, minus_op(int(1073741637))))
]) ), 
cmp_stmts([
stmt(function_call(Stub_driver_init, []))
]), 
cmp_stmts([
if_stmt(branch(53, less_op(Status, int(0))), 
cmp_stmts([
return_stmt((minus_op(int(1))))

]) )
]), 
declaration([int], [Tmp_ndt_1]), 
stmt(assign(Tmp_ndt_1, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(55, equal_op(Tmp_ndt_1, int(3))), 
cmp_stmts([
goto_stmt(switch_2_3, Main)

]) , 
cmp_stmts([
goto_stmt(switch_2_default, Main)
, 
if_stmt(branch(54, int(0)), 
cmp_stmts([label_stmt(switch_2_3, 
cmp_stmts([
stmt(assign(Status, function_call(UC_FloppyPnp, [Devobj, Pirp])))
])), 
goto_stmt(switch_2_break, Main)
, label_stmt(switch_2_default, stmt([])), 
return_stmt((minus_op(int(1))))

]) , 
cmp_stmts([label_stmt(switch_2_break, stmt([]))
]))
]))
]) ), 
if_stmt(branch(70, equal_op(Pended, int(1))), 
cmp_stmts([
if_stmt(branch(57, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_NP))
]) , 
cmp_stmts([
goto_stmt(_L___2, Main)

]))
]) , 
cmp_stmts([label_stmt(_L___2, 
if_stmt(branch(69, equal_op(Pended, int(1))), 
cmp_stmts([
if_stmt(branch(58, equal_op(S, UC_MPR3)), 
cmp_stmts([
stmt(assign(S, UC_MPR3))
]) , 
cmp_stmts([
goto_stmt(_L___1, Main)

]))
]) , 
cmp_stmts([label_stmt(_L___1, 
if_stmt(branch(68, not_equal_op(S, UC_UNLOADED)), 
cmp_stmts([
if_stmt(branch(67, not_equal_op(Status, minus_op(int(1)))), 
cmp_stmts([
if_stmt(branch(66, not_equal_op(S, UC_SKIP2)), 
cmp_stmts([
if_stmt(branch(60, not_equal_op(S, UC_IPC)), 
cmp_stmts([
if_stmt(branch(59, not_equal_op(S, UC_DC)), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) , 
cmp_stmts([
goto_stmt(_L___0, Main)

]))
]) , 
cmp_stmts([
goto_stmt(_L___0, Main)

]))
]) , 
cmp_stmts([label_stmt(_L___0, 
if_stmt(branch(65, equal_op(Pended, int(1))), 
cmp_stmts([
if_stmt(branch(61, not_equal_op(Status, int(259))), 
cmp_stmts([
stmt(function_call(ErrorFn, []))
]) )
]) , 
cmp_stmts([
if_stmt(branch(64, equal_op(S, UC_DC)), 
cmp_stmts([
if_stmt(branch(62, equal_op(Status, int(259))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) )
]) , 
cmp_stmts([
if_stmt(branch(63, not_equal_op(Status, LowerDriverReturn)), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) )
]))
])))
]))
]) )
]) ))
])))
])), 
stmt(assign(Status, int(0))), 
return_stmt((Status))

])
])), 
function([int], function(UC_IoBuildDeviceIoControlRequest, [param([int], UC_IoControlCode), param([int], UC_DeviceObject), param([int], UC_InputBuffer), param([int], UC_InputBufferLength), param([int], UC_OutputBuffer), param([int], UC_OutputBufferLength), param([int], UC_InternalDeviceIoControl), param([int], UC_Event), param([int], UC_IoStatusBlock)]), [], 
cmp_stmts([
declaration([int], [initialised(Malloc, function_call(UC___VERIFIER_nondet_int, []))]), 
cmp_stmts([
stmt(assign(CustomIrp, int(1))), 
declaration([int], [Tmp_ndt_2]), 
stmt(assign(Tmp_ndt_2, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(72, equal_op(Tmp_ndt_2, int(0))), 
cmp_stmts([
goto_stmt(switch_3_0, UC_IoBuildDeviceIoControlRequest)

]) , 
cmp_stmts([
goto_stmt(switch_3_default, UC_IoBuildDeviceIoControlRequest)
, 
if_stmt(branch(71, int(0)), 
cmp_stmts([label_stmt(switch_3_0, 
return_stmt((Malloc))
), label_stmt(switch_3_default, stmt([])), 
return_stmt((int(0)))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_IoDeleteSymbolicLink, [param([int], UC_SymbolicLinkName)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_3]), 
stmt(assign(Tmp_ndt_3, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(74, equal_op(Tmp_ndt_3, int(0))), 
cmp_stmts([
goto_stmt(switch_4_0, UC_IoDeleteSymbolicLink)

]) , 
cmp_stmts([
goto_stmt(switch_4_default, UC_IoDeleteSymbolicLink)
, 
if_stmt(branch(73, int(0)), 
cmp_stmts([label_stmt(switch_4_0, 
return_stmt((int(0)))
), label_stmt(switch_4_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_IoQueryDeviceDescription, [param([int], UC_BusType), param([int], UC_BusNumber), param([int], UC_ControllerType), param([int], UC_ControllerNumber), param([int], UC_PeripheralType), param([int], UC_PeripheralNumber), param([int], UC_CalloutRoutine), param([int], UC_Context)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_4]), 
stmt(assign(Tmp_ndt_4, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(76, equal_op(Tmp_ndt_4, int(0))), 
cmp_stmts([
goto_stmt(switch_5_0, UC_IoQueryDeviceDescription)

]) , 
cmp_stmts([
goto_stmt(switch_5_default, UC_IoQueryDeviceDescription)
, 
if_stmt(branch(75, int(0)), 
cmp_stmts([label_stmt(switch_5_0, 
return_stmt((int(0)))
), label_stmt(switch_5_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_IoRegisterDeviceInterface, [param([int], UC_PhysicalDeviceObject), param([int], UC_InterfaceClassGuid), param([int], UC_ReferenceString), param([int], UC_SymbolicLinkName)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_5]), 
stmt(assign(Tmp_ndt_5, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(78, equal_op(Tmp_ndt_5, int(0))), 
cmp_stmts([
goto_stmt(switch_6_0, UC_IoRegisterDeviceInterface)

]) , 
cmp_stmts([
goto_stmt(switch_6_default, UC_IoRegisterDeviceInterface)
, 
if_stmt(branch(77, int(0)), 
cmp_stmts([label_stmt(switch_6_0, 
return_stmt((int(0)))
), label_stmt(switch_6_default, stmt([])), 
return_stmt((minus_op(int(1073741808))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_IoSetDeviceInterfaceState, [param([int], UC_SymbolicLinkName), param([int], UC_Enable)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_6]), 
stmt(assign(Tmp_ndt_6, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(80, equal_op(Tmp_ndt_6, int(0))), 
cmp_stmts([
goto_stmt(switch_7_0, UC_IoSetDeviceInterfaceState)

]) , 
cmp_stmts([
goto_stmt(switch_7_default, UC_IoSetDeviceInterfaceState)
, 
if_stmt(branch(79, int(0)), 
cmp_stmts([label_stmt(switch_7_0, 
return_stmt((int(0)))
), label_stmt(switch_7_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([void], function(StubMoreProcessingRequired, [param_no_decl([void], [])]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(81, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_MPR1))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
return_stmt

])
])), 
function([int], function(UC_IofCallDriver, [param([int], UC_DeviceObject), param([int], UC_Irp)]), [], 
cmp_stmts([
declaration([int], [ReturnVal2]), 
declaration([int], [CompRetStatus1]), 
declaration([int], [initialised(Lcontext, function_call(UC___VERIFIER_nondet_int, []))]), 
declaration([unsigned, long], [UC___cil_tmp7]), 
cmp_stmts([
if_stmt(branch(83, CompRegistered), 
cmp_stmts([
cmp_stmts([
stmt(assign(CompRetStatus1, function_call(UC_FloppyPnpComplete, [UC_DeviceObject, UC_Irp, Lcontext])))
]), 
cmp_stmts([
stmt(assign(UC___cil_tmp7, cast([unsigned, long], CompRetStatus1))), 
if_stmt(branch(82, equal_op(UC___cil_tmp7, minus_op(int(1073741802)))), 
cmp_stmts([
cmp_stmts([
stmt(function_call(StubMoreProcessingRequired, []))
])
]) )
])
]) ), 
declaration([int], [Tmp_ndt_12]), 
stmt(assign(Tmp_ndt_12, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(86, equal_op(Tmp_ndt_12, int(0))), 
cmp_stmts([
goto_stmt(switch_8_0, UC_IofCallDriver)

]) , 
cmp_stmts([
declaration([int], [Tmp_ndt_7]), 
stmt(assign(Tmp_ndt_7, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(85, equal_op(Tmp_ndt_7, int(1))), 
cmp_stmts([
goto_stmt(switch_8_1, UC_IofCallDriver)

]) , 
cmp_stmts([
goto_stmt(switch_8_default, UC_IofCallDriver)
, 
if_stmt(branch(84, int(0)), 
cmp_stmts([label_stmt(switch_8_0, 
stmt(assign(ReturnVal2, int(0)))), 
goto_stmt(switch_8_break, UC_IofCallDriver)
, label_stmt(switch_8_1, 
stmt(assign(ReturnVal2, minus_op(int(1073741823))))), 
goto_stmt(switch_8_break, UC_IofCallDriver)
, label_stmt(switch_8_default, 
stmt(assign(ReturnVal2, int(259)))), 
goto_stmt(switch_8_break, UC_IofCallDriver)

]) , 
cmp_stmts([label_stmt(switch_8_break, stmt([]))
]))
]))
])), 
if_stmt(branch(90, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_IPC)), 
stmt(assign(LowerDriverReturn, ReturnVal2))
]) , 
cmp_stmts([
if_stmt(branch(89, equal_op(S, UC_MPR1)), 
cmp_stmts([
if_stmt(branch(87, equal_op(ReturnVal2, int(259))), 
cmp_stmts([
stmt(assign(S, UC_MPR3)), 
stmt(assign(LowerDriverReturn, ReturnVal2))
]) , 
cmp_stmts([
stmt(assign(S, UC_NP)), 
stmt(assign(LowerDriverReturn, ReturnVal2))
]))
]) , 
cmp_stmts([
if_stmt(branch(88, equal_op(S, UC_SKIP1)), 
cmp_stmts([
stmt(assign(S, UC_SKIP2)), 
stmt(assign(LowerDriverReturn, ReturnVal2))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]))
]))
])), 
return_stmt((ReturnVal2))

])
])), 
function([void], function(UC_IofCompleteRequest, [param([int], UC_Irp), param([int], UC_PriorityBoost)]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(91, equal_op(S, UC_NP)), 
cmp_stmts([
stmt(assign(S, UC_DC))
]) , 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
])), 
return_stmt

])
])), 
function([int], function(UC_KeSetEvent, [param([int], UC_Event), param([int], UC_Increment), param([int], UC_Wait)]), [], 
cmp_stmts([
declaration([int], [initialised(L, function_call(UC___VERIFIER_nondet_int, []))]), 
cmp_stmts([
stmt(assign(SetEventCalled, int(1))), 
return_stmt((L))

])
])), 
function([int], function(UC_KeWaitForSingleObject, [param([int], UC_Object), param([int], UC_WaitReason), param([int], UC_WaitMode), param([int], UC_Alertable), param([int], UC_Timeout)]), [], 
cmp_stmts([
cmp_stmts([
if_stmt(branch(95, equal_op(S, UC_MPR3)), 
cmp_stmts([
if_stmt(branch(92, equal_op(SetEventCalled, int(1))), 
cmp_stmts([
stmt(assign(S, UC_NP)), 
stmt(assign(SetEventCalled, int(0)))
]) , 
cmp_stmts([
goto_stmt(_L, UC_KeWaitForSingleObject)

]))
]) , 
cmp_stmts([label_stmt(_L, 
if_stmt(branch(94, equal_op(CustomIrp, int(1))), 
cmp_stmts([
stmt(assign(S, UC_NP)), 
stmt(assign(CustomIrp, int(0)))
]) , 
cmp_stmts([
if_stmt(branch(93, equal_op(S, UC_MPR3)), 
cmp_stmts([
cmp_stmts([
stmt(function_call(ErrorFn, []))
])
]) )
])))
])), 
declaration([int], [Tmp_ndt_8]), 
stmt(assign(Tmp_ndt_8, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(97, equal_op(Tmp_ndt_8, int(0))), 
cmp_stmts([
goto_stmt(switch_9_0, UC_KeWaitForSingleObject)

]) , 
cmp_stmts([
goto_stmt(switch_9_default, UC_KeWaitForSingleObject)
, 
if_stmt(branch(96, int(0)), 
cmp_stmts([label_stmt(switch_9_0, 
return_stmt((int(0)))
), label_stmt(switch_9_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_ObReferenceObjectByHandle, [param([int], UC_Handle), param([int], UC_DesiredAccess), param([int], UC_ObjectType), param([int], UC_AccessMode), param([int], UC_Object), param([int], UC_HandleInformation)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_9]), 
stmt(assign(Tmp_ndt_9, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(99, equal_op(Tmp_ndt_9, int(0))), 
cmp_stmts([
goto_stmt(switch_10_0, UC_ObReferenceObjectByHandle)

]) , 
cmp_stmts([
goto_stmt(switch_10_default, UC_ObReferenceObjectByHandle)
, 
if_stmt(branch(98, int(0)), 
cmp_stmts([label_stmt(switch_10_0, 
return_stmt((int(0)))
), label_stmt(switch_10_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_PsCreateSystemThread, [param([int], UC_ThreadHandle), param([int], UC_DesiredAccess), param([int], UC_ObjectAttributes), param([int], UC_ProcessHandle), param([int], UC_ClientId), param([int], UC_StartRoutine), param([int], UC_StartContext)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_10]), 
stmt(assign(Tmp_ndt_10, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(101, equal_op(Tmp_ndt_10, int(0))), 
cmp_stmts([
goto_stmt(switch_11_0, UC_PsCreateSystemThread)

]) , 
cmp_stmts([
goto_stmt(switch_11_default, UC_PsCreateSystemThread)
, 
if_stmt(branch(100, int(0)), 
cmp_stmts([label_stmt(switch_11_0, 
return_stmt((int(0)))
), label_stmt(switch_11_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
])), 
function([int], function(UC_ZwClose, [param([int], UC_Handle)]), [], 
cmp_stmts([
cmp_stmts([
declaration([int], [Tmp_ndt_11]), 
stmt(assign(Tmp_ndt_11, function_call(UC___VERIFIER_nondet_int, []))), 
if_stmt(branch(103, equal_op(Tmp_ndt_11, int(0))), 
cmp_stmts([
goto_stmt(switch_12_0, UC_ZwClose)

]) , 
cmp_stmts([
goto_stmt(switch_12_default, UC_ZwClose)
, 
if_stmt(branch(102, int(0)), 
cmp_stmts([label_stmt(switch_12_0, 
return_stmt((int(0)))
), label_stmt(switch_12_default, stmt([])), 
return_stmt((minus_op(int(1073741823))))

]) , 
cmp_stmts([]))
]))
])
]))
]).