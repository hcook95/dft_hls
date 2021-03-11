############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
open_project dft_hls
set_top matrix_vector
add_files simple_dft.cpp
add_files -tb dft_test.cpp
open_solution "my_solution" -flow_target vivado
set_part {xc7z020clg484-1}
create_clock -period 10 -name default
source "./dft_hls/my_solution/directives.tcl"
csim_design
csynth_design
cosim_design
export_design -format ip_catalog
