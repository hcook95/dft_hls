############################################################
## This file is generated automatically by Vitis HLS.
## Please DO NOT edit it.
## Copyright 1986-2020 Xilinx, Inc. All Rights Reserved.
############################################################
set_directive_top -name matrix_vector "matrix_vector"
set_directive_array_partition -type complete -dim 2 "matrix_vector" M
set_directive_array_partition -type complete -dim 1 "matrix_vector" V_In
set_directive_pipeline -II 1 "matrix_vector/data_loop"
set_directive_unroll -factor 8 -skip_exit_check "matrix_vector/dot_product_loop"
