set moduleName matrix_vector
set isTopModule 1
set isCombinational 0
set isDatapathOnly 0
set isPipelined 0
set pipeline_type none
set FunctionProtocol ap_ctrl_hs
set isOneStateSeq 0
set ProfileFlag 0
set StallSigGenFlag 0
set isEnableWaveformDebug 1
set C_modelName {matrix_vector}
set C_modelType { void 0 }
set C_modelArgList {
	{ M_0 int 32 regular {array 32 { 1 3 } 1 1 }  }
	{ M_1 int 32 regular {array 32 { 1 3 } 1 1 }  }
	{ V_In_0 int 32 regular {array 4 { 1 3 } 1 1 }  }
	{ V_In_1 int 32 regular {array 4 { 1 3 } 1 1 }  }
	{ V_Out int 32 regular {array 8 { 0 3 } 0 1 }  }
}
set C_modelArgMapList {[ 
	{ "Name" : "M_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "M_0","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "M_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "M_1","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "V_In_0", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "V_In_0","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "V_In_1", "interface" : "memory", "bitwidth" : 32, "direction" : "READONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "V_In_1","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} , 
 	{ "Name" : "V_Out", "interface" : "memory", "bitwidth" : 32, "direction" : "WRITEONLY", "bitSlice":[{"low":0,"up":0,"cElement": [{"cName": "V_Out","cData": "int","bit_use": { "low": 0,"up": 0},"cArray": [{"low" : 0,"up" : 0,"step" : 0}]}]}]} ]}
# RTL Port declarations: 
set portNum 22
set portList { 
	{ ap_clk sc_in sc_logic 1 clock -1 } 
	{ ap_rst sc_in sc_logic 1 reset -1 active_high_sync } 
	{ ap_start sc_in sc_logic 1 start -1 } 
	{ ap_done sc_out sc_logic 1 predone -1 } 
	{ ap_idle sc_out sc_logic 1 done -1 } 
	{ ap_ready sc_out sc_logic 1 ready -1 } 
	{ M_0_address0 sc_out sc_lv 5 signal 0 } 
	{ M_0_ce0 sc_out sc_logic 1 signal 0 } 
	{ M_0_q0 sc_in sc_lv 32 signal 0 } 
	{ M_1_address0 sc_out sc_lv 5 signal 1 } 
	{ M_1_ce0 sc_out sc_logic 1 signal 1 } 
	{ M_1_q0 sc_in sc_lv 32 signal 1 } 
	{ V_In_0_address0 sc_out sc_lv 2 signal 2 } 
	{ V_In_0_ce0 sc_out sc_logic 1 signal 2 } 
	{ V_In_0_q0 sc_in sc_lv 32 signal 2 } 
	{ V_In_1_address0 sc_out sc_lv 2 signal 3 } 
	{ V_In_1_ce0 sc_out sc_logic 1 signal 3 } 
	{ V_In_1_q0 sc_in sc_lv 32 signal 3 } 
	{ V_Out_address0 sc_out sc_lv 3 signal 4 } 
	{ V_Out_ce0 sc_out sc_logic 1 signal 4 } 
	{ V_Out_we0 sc_out sc_logic 1 signal 4 } 
	{ V_Out_d0 sc_out sc_lv 32 signal 4 } 
}
set NewPortList {[ 
	{ "name": "ap_clk", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "clock", "bundle":{"name": "ap_clk", "role": "default" }} , 
 	{ "name": "ap_rst", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "reset", "bundle":{"name": "ap_rst", "role": "default" }} , 
 	{ "name": "ap_start", "direction": "in", "datatype": "sc_logic", "bitwidth":1, "type": "start", "bundle":{"name": "ap_start", "role": "default" }} , 
 	{ "name": "ap_done", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "predone", "bundle":{"name": "ap_done", "role": "default" }} , 
 	{ "name": "ap_idle", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "done", "bundle":{"name": "ap_idle", "role": "default" }} , 
 	{ "name": "ap_ready", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "ready", "bundle":{"name": "ap_ready", "role": "default" }} , 
 	{ "name": "M_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "M_0", "role": "address0" }} , 
 	{ "name": "M_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "M_0", "role": "ce0" }} , 
 	{ "name": "M_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "M_0", "role": "q0" }} , 
 	{ "name": "M_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":5, "type": "signal", "bundle":{"name": "M_1", "role": "address0" }} , 
 	{ "name": "M_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "M_1", "role": "ce0" }} , 
 	{ "name": "M_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "M_1", "role": "q0" }} , 
 	{ "name": "V_In_0_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "V_In_0", "role": "address0" }} , 
 	{ "name": "V_In_0_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "V_In_0", "role": "ce0" }} , 
 	{ "name": "V_In_0_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "V_In_0", "role": "q0" }} , 
 	{ "name": "V_In_1_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":2, "type": "signal", "bundle":{"name": "V_In_1", "role": "address0" }} , 
 	{ "name": "V_In_1_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "V_In_1", "role": "ce0" }} , 
 	{ "name": "V_In_1_q0", "direction": "in", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "V_In_1", "role": "q0" }} , 
 	{ "name": "V_Out_address0", "direction": "out", "datatype": "sc_lv", "bitwidth":3, "type": "signal", "bundle":{"name": "V_Out", "role": "address0" }} , 
 	{ "name": "V_Out_ce0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "V_Out", "role": "ce0" }} , 
 	{ "name": "V_Out_we0", "direction": "out", "datatype": "sc_logic", "bitwidth":1, "type": "signal", "bundle":{"name": "V_Out", "role": "we0" }} , 
 	{ "name": "V_Out_d0", "direction": "out", "datatype": "sc_lv", "bitwidth":32, "type": "signal", "bundle":{"name": "V_Out", "role": "d0" }}  ]}

set RtlHierarchyInfo {[
	{"ID" : "0", "Level" : "0", "Path" : "`AUTOTB_DUT_INST", "Parent" : "", "Child" : ["1", "2"],
		"CDFG" : "matrix_vector",
		"Protocol" : "ap_ctrl_hs",
		"ControlExist" : "1", "ap_start" : "1", "ap_ready" : "1", "ap_done" : "1", "ap_continue" : "0", "ap_idle" : "1", "real_start" : "0",
		"Pipeline" : "None", "UnalignedPipeline" : "0", "RewindPipeline" : "0", "ProcessNetwork" : "0",
		"II" : "0",
		"VariableLatency" : "1", "ExactLatency" : "-1", "EstimateLatencyMin" : "265", "EstimateLatencyMax" : "265",
		"Combinational" : "0",
		"Datapath" : "0",
		"ClockEnable" : "0",
		"HasSubDataflow" : "0",
		"InDataflowNetwork" : "0",
		"HasNonBlockingOperation" : "0",
		"Port" : [
			{"Name" : "M_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "M_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "V_In_0", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "V_In_1", "Type" : "Memory", "Direction" : "I"},
			{"Name" : "V_Out", "Type" : "Memory", "Direction" : "O"}]},
	{"ID" : "1", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fadd_32ns_32ns_32_5_full_dsp_1_U1", "Parent" : "0"},
	{"ID" : "2", "Level" : "1", "Path" : "`AUTOTB_DUT_INST.fmul_32ns_32ns_32_4_max_dsp_1_U2", "Parent" : "0"}]}


set ArgLastReadFirstWriteLatency {
	matrix_vector {
		M_0 {Type I LastRead 1 FirstWrite -1}
		M_1 {Type I LastRead 1 FirstWrite -1}
		V_In_0 {Type I LastRead 1 FirstWrite -1}
		V_In_1 {Type I LastRead 1 FirstWrite -1}
		V_Out {Type O LastRead -1 FirstWrite 12}}}

set hasDtUnsupportedChannel 0

set PerformanceInfo {[
	{"Name" : "Latency", "Min" : "265", "Max" : "265"}
	, {"Name" : "Interval", "Min" : "266", "Max" : "266"}
]}

set PipelineEnableSignalInfo {[
	{"Pipeline" : "0", "EnableSignal" : "ap_enable_pp0"}
]}

set Spec2ImplPortList { 
	M_0 { ap_memory {  { M_0_address0 mem_address 1 5 }  { M_0_ce0 mem_ce 1 1 }  { M_0_q0 mem_dout 0 32 } } }
	M_1 { ap_memory {  { M_1_address0 mem_address 1 5 }  { M_1_ce0 mem_ce 1 1 }  { M_1_q0 mem_dout 0 32 } } }
	V_In_0 { ap_memory {  { V_In_0_address0 mem_address 1 2 }  { V_In_0_ce0 mem_ce 1 1 }  { V_In_0_q0 mem_dout 0 32 } } }
	V_In_1 { ap_memory {  { V_In_1_address0 mem_address 1 2 }  { V_In_1_ce0 mem_ce 1 1 }  { V_In_1_q0 mem_dout 0 32 } } }
	V_Out { ap_memory {  { V_Out_address0 mem_address 1 3 }  { V_Out_ce0 mem_ce 1 1 }  { V_Out_we0 mem_we 1 1 }  { V_Out_d0 mem_din 1 32 } } }
}

set busDeadlockParameterList { 
}

# RTL port scheduling information:
set fifoSchedulingInfoList { 
}

# RTL bus port read request latency information:
set busReadReqLatencyList { 
}

# RTL bus port write response latency information:
set busWriteResLatencyList { 
}

# RTL array port load latency information:
set memoryLoadLatencyList { 
}
