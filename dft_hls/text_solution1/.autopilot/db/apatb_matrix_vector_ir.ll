; ModuleID = '/home/hayden/Documents/dft_hls/dft_hls/text_solution1/.autopilot/db/a.g.ld.5.gdce.bc'
source_filename = "llvm-link"
target datalayout = "e-m:e-i64:64-i128:128-i256:256-i512:512-i1024:1024-i2048:2048-i4096:4096-n8:16:32:64-S128-v16:16-v24:32-v32:32-v48:64-v96:128-v192:256-v256:256-v512:512-v1024:1024"
target triple = "fpga64-xilinx-none"

; Function Attrs: noinline
define void @apatb_matrix_vector_ir([8 x float]* %M, float* %V_In, float* %V_Out) local_unnamed_addr #0 {
entry:
  %M_copy_0 = alloca [8 x float], align 512
  %M_copy_1 = alloca [8 x float], align 512
  %M_copy_2 = alloca [8 x float], align 512
  %M_copy_3 = alloca [8 x float], align 512
  %M_copy_4 = alloca [8 x float], align 512
  %M_copy_5 = alloca [8 x float], align 512
  %M_copy_6 = alloca [8 x float], align 512
  %M_copy_7 = alloca [8 x float], align 512
  %V_In_copy_0 = alloca float, align 512
  %V_In_copy_1 = alloca float, align 512
  %V_In_copy_2 = alloca float, align 512
  %V_In_copy_3 = alloca float, align 512
  %V_In_copy_4 = alloca float, align 512
  %V_In_copy_5 = alloca float, align 512
  %V_In_copy_6 = alloca float, align 512
  %V_In_copy_7 = alloca float, align 512
  %V_Out_copy = alloca [8 x float], align 512
  %0 = bitcast [8 x float]* %M to [8 x [8 x float]]*
  %1 = bitcast float* %V_In to [8 x float]*
  %2 = bitcast float* %V_Out to [8 x float]*
  call void @copy_in([8 x [8 x float]]* %0, [8 x float]* nonnull align 512 %M_copy_0, [8 x float]* nonnull align 512 %M_copy_1, [8 x float]* nonnull align 512 %M_copy_2, [8 x float]* nonnull align 512 %M_copy_3, [8 x float]* nonnull align 512 %M_copy_4, [8 x float]* nonnull align 512 %M_copy_5, [8 x float]* nonnull align 512 %M_copy_6, [8 x float]* nonnull align 512 %M_copy_7, [8 x float]* %1, float* nonnull align 512 %V_In_copy_0, float* nonnull align 512 %V_In_copy_1, float* nonnull align 512 %V_In_copy_2, float* nonnull align 512 %V_In_copy_3, float* nonnull align 512 %V_In_copy_4, float* nonnull align 512 %V_In_copy_5, float* nonnull align 512 %V_In_copy_6, float* nonnull align 512 %V_In_copy_7, [8 x float]* %2, [8 x float]* nonnull align 512 %V_Out_copy)
  %3 = getelementptr inbounds [8 x float], [8 x float]* %V_Out_copy, i32 0, i32 0
  call void @apatb_matrix_vector_hw([8 x float]* %M_copy_0, [8 x float]* %M_copy_1, [8 x float]* %M_copy_2, [8 x float]* %M_copy_3, [8 x float]* %M_copy_4, [8 x float]* %M_copy_5, [8 x float]* %M_copy_6, [8 x float]* %M_copy_7, float* %V_In_copy_0, float* %V_In_copy_1, float* %V_In_copy_2, float* %V_In_copy_3, float* %V_In_copy_4, float* %V_In_copy_5, float* %V_In_copy_6, float* %V_In_copy_7, float* %3)
  call void @copy_out([8 x [8 x float]]* %0, [8 x float]* nonnull align 512 %M_copy_0, [8 x float]* nonnull align 512 %M_copy_1, [8 x float]* nonnull align 512 %M_copy_2, [8 x float]* nonnull align 512 %M_copy_3, [8 x float]* nonnull align 512 %M_copy_4, [8 x float]* nonnull align 512 %M_copy_5, [8 x float]* nonnull align 512 %M_copy_6, [8 x float]* nonnull align 512 %M_copy_7, [8 x float]* %1, float* nonnull align 512 %V_In_copy_0, float* nonnull align 512 %V_In_copy_1, float* nonnull align 512 %V_In_copy_2, float* nonnull align 512 %V_In_copy_3, float* nonnull align 512 %V_In_copy_4, float* nonnull align 512 %V_In_copy_5, float* nonnull align 512 %V_In_copy_6, float* nonnull align 512 %V_In_copy_7, [8 x float]* %2, [8 x float]* nonnull align 512 %V_Out_copy)
  ret void
}

; Function Attrs: argmemonly nounwind
declare void @llvm.memcpy.p0i8.p0i8.i64(i8* nocapture writeonly, i8* nocapture readonly, i64, i1) #1

; Function Attrs: argmemonly noinline
define internal fastcc void @onebyonecpy_hls.p0a8f32([8 x float]* noalias align 512 "orig.arg.no"="0", [8 x float]* noalias readonly "orig.arg.no"="1") unnamed_addr #2 {
entry:
  %2 = icmp eq [8 x float]* %0, null
  %3 = icmp eq [8 x float]* %1, null
  %4 = or i1 %2, %3
  br i1 %4, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop, %copy
  %for.loop.idx3 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop ]
  %dst.addr.gep1 = getelementptr [8 x float], [8 x float]* %0, i64 0, i64 %for.loop.idx3
  %5 = bitcast float* %dst.addr.gep1 to i8*
  %src.addr.gep2 = getelementptr [8 x float], [8 x float]* %1, i64 0, i64 %for.loop.idx3
  %6 = bitcast float* %src.addr.gep2 to i8*
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %5, i8* align 1 %6, i64 4, i1 false)
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx3, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 8
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %for.loop, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a8a8f32.3.4([8 x float]* noalias align 512 "orig.arg.no"="0" %_0, [8 x float]* noalias align 512 "orig.arg.no"="0" %_1, [8 x float]* noalias align 512 "orig.arg.no"="0" %_2, [8 x float]* noalias align 512 "orig.arg.no"="0" %_3, [8 x float]* noalias align 512 "orig.arg.no"="0" %_4, [8 x float]* noalias align 512 "orig.arg.no"="0" %_5, [8 x float]* noalias align 512 "orig.arg.no"="0" %_6, [8 x float]* noalias align 512 "orig.arg.no"="0" %_7, [8 x [8 x float]]* noalias readonly "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq [8 x float]* %_0, null
  %2 = icmp eq [8 x [8 x float]]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx12 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %dst.addr57.gep9_0 = getelementptr [8 x float], [8 x float]* %_0, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_1 = getelementptr [8 x float], [8 x float]* %_1, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_2 = getelementptr [8 x float], [8 x float]* %_2, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_3 = getelementptr [8 x float], [8 x float]* %_3, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_4 = getelementptr [8 x float], [8 x float]* %_4, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_5 = getelementptr [8 x float], [8 x float]* %_5, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_6 = getelementptr [8 x float], [8 x float]* %_6, i64 0, i64 %for.loop.idx12
  %dst.addr57.gep9_7 = getelementptr [8 x float], [8 x float]* %_7, i64 0, i64 %for.loop.idx12
  %_01 = bitcast float* %dst.addr57.gep9_0 to i8*
  %_12 = bitcast float* %dst.addr57.gep9_1 to i8*
  %_23 = bitcast float* %dst.addr57.gep9_2 to i8*
  %_34 = bitcast float* %dst.addr57.gep9_3 to i8*
  %_45 = bitcast float* %dst.addr57.gep9_4 to i8*
  %_56 = bitcast float* %dst.addr57.gep9_5 to i8*
  %_67 = bitcast float* %dst.addr57.gep9_6 to i8*
  %_78 = bitcast float* %dst.addr57.gep9_7 to i8*
  br label %for.loop2

for.loop2:                                        ; preds = %.exit, %for.loop
  %for.loop.idx311 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %.exit ]
  %src.addr68.gep10 = getelementptr [8 x [8 x float]], [8 x [8 x float]]* %0, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %4 = bitcast float* %src.addr68.gep10 to i8*
  switch i64 %for.loop.idx311, label %.default [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
    i64 4, label %.case.4
    i64 5, label %.case.5
    i64 6, label %.case.6
    i64 7, label %.case.7
  ]

.default:                                         ; preds = %for.loop2
  unreachable

.case.0:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_01, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.1:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_12, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.2:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_23, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.3:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_34, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.4:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_45, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.5:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_56, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.6:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_67, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.7:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_78, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.exit:                                            ; preds = %.case.7, %.case.6, %.case.5, %.case.4, %.case.3, %.case.2, %.case.1, %.case.0
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx311, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 8
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx12, 1
  %exitcond13 = icmp ne i64 %for.loop.idx.next, 8
  br i1 %exitcond13, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a8f32.5.6(float* noalias align 512 "orig.arg.no"="0" %_0, float* noalias align 512 "orig.arg.no"="0" %_1, float* noalias align 512 "orig.arg.no"="0" %_2, float* noalias align 512 "orig.arg.no"="0" %_3, float* noalias align 512 "orig.arg.no"="0" %_4, float* noalias align 512 "orig.arg.no"="0" %_5, float* noalias align 512 "orig.arg.no"="0" %_6, float* noalias align 512 "orig.arg.no"="0" %_7, [8 x float]* noalias readonly "orig.arg.no"="1") #2 {
entry:
  %1 = icmp eq float* %_0, null
  %2 = icmp eq [8 x float]* %0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  %_01 = bitcast float* %_0 to i8*
  %_12 = bitcast float* %_1 to i8*
  %_23 = bitcast float* %_2 to i8*
  %_34 = bitcast float* %_3 to i8*
  %_45 = bitcast float* %_4 to i8*
  %_56 = bitcast float* %_5 to i8*
  %_67 = bitcast float* %_6 to i8*
  %_78 = bitcast float* %_7 to i8*
  br label %for.loop

for.loop:                                         ; preds = %.exit, %copy
  %for.loop.idx3 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %.exit ]
  %src.addr.gep2 = getelementptr [8 x float], [8 x float]* %0, i64 0, i64 %for.loop.idx3
  %4 = bitcast float* %src.addr.gep2 to i8*
  switch i64 %for.loop.idx3, label %.default [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
    i64 4, label %.case.4
    i64 5, label %.case.5
    i64 6, label %.case.6
    i64 7, label %.case.7
  ]

.default:                                         ; preds = %for.loop
  unreachable

.case.0:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_01, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.1:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_12, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.2:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_23, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.3:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_34, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.4:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_45, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.5:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_56, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.6:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_67, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.case.7:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %_78, i8* align 1 %4, i64 4, i1 false)
  br label %.exit

.exit:                                            ; preds = %.case.7, %.case.6, %.case.5, %.case.4, %.case.3, %.case.2, %.case.1, %.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx3, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 8
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @copy_in([8 x [8 x float]]* readonly "orig.arg.no"="0", [8 x float]* noalias align 512 "orig.arg.no"="1" %_0, [8 x float]* noalias align 512 "orig.arg.no"="1" %_1, [8 x float]* noalias align 512 "orig.arg.no"="1" %_2, [8 x float]* noalias align 512 "orig.arg.no"="1" %_3, [8 x float]* noalias align 512 "orig.arg.no"="1" %_4, [8 x float]* noalias align 512 "orig.arg.no"="1" %_5, [8 x float]* noalias align 512 "orig.arg.no"="1" %_6, [8 x float]* noalias align 512 "orig.arg.no"="1" %_7, [8 x float]* readonly "orig.arg.no"="2", float* noalias align 512 "orig.arg.no"="3" %_01, float* noalias align 512 "orig.arg.no"="3" %_12, float* noalias align 512 "orig.arg.no"="3" %_23, float* noalias align 512 "orig.arg.no"="3" %_34, float* noalias align 512 "orig.arg.no"="3" %_45, float* noalias align 512 "orig.arg.no"="3" %_56, float* noalias align 512 "orig.arg.no"="3" %_67, float* noalias align 512 "orig.arg.no"="3" %_78, [8 x float]* readonly "orig.arg.no"="4", [8 x float]* noalias align 512 "orig.arg.no"="5") #3 {
entry:
  call void @onebyonecpy_hls.p0a8a8f32.3.4([8 x float]* align 512 %_0, [8 x float]* align 512 %_1, [8 x float]* align 512 %_2, [8 x float]* align 512 %_3, [8 x float]* align 512 %_4, [8 x float]* align 512 %_5, [8 x float]* align 512 %_6, [8 x float]* align 512 %_7, [8 x [8 x float]]* %0)
  call void @onebyonecpy_hls.p0a8f32.5.6(float* align 512 %_01, float* align 512 %_12, float* align 512 %_23, float* align 512 %_34, float* align 512 %_45, float* align 512 %_56, float* align 512 %_67, float* align 512 %_78, [8 x float]* %1)
  call fastcc void @onebyonecpy_hls.p0a8f32([8 x float]* align 512 %3, [8 x float]* %2)
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a8a8f32.11.12([8 x [8 x float]]* noalias "orig.arg.no"="0", [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_0, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_1, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_2, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_3, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_4, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_5, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_6, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_7) #2 {
entry:
  %1 = icmp eq [8 x [8 x float]]* %0, null
  %2 = icmp eq [8 x float]* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  br label %for.loop

for.loop:                                         ; preds = %for.loop.split, %copy
  %for.loop.idx12 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %for.loop.split ]
  %src.addr68.gep10_0 = getelementptr [8 x float], [8 x float]* %_0, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_1 = getelementptr [8 x float], [8 x float]* %_1, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_2 = getelementptr [8 x float], [8 x float]* %_2, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_3 = getelementptr [8 x float], [8 x float]* %_3, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_4 = getelementptr [8 x float], [8 x float]* %_4, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_5 = getelementptr [8 x float], [8 x float]* %_5, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_6 = getelementptr [8 x float], [8 x float]* %_6, i64 0, i64 %for.loop.idx12
  %src.addr68.gep10_7 = getelementptr [8 x float], [8 x float]* %_7, i64 0, i64 %for.loop.idx12
  %_01 = bitcast float* %src.addr68.gep10_0 to i8*
  %_12 = bitcast float* %src.addr68.gep10_1 to i8*
  %_23 = bitcast float* %src.addr68.gep10_2 to i8*
  %_34 = bitcast float* %src.addr68.gep10_3 to i8*
  %_45 = bitcast float* %src.addr68.gep10_4 to i8*
  %_56 = bitcast float* %src.addr68.gep10_5 to i8*
  %_67 = bitcast float* %src.addr68.gep10_6 to i8*
  %_78 = bitcast float* %src.addr68.gep10_7 to i8*
  br label %for.loop2

for.loop2:                                        ; preds = %.exit, %for.loop
  %for.loop.idx311 = phi i64 [ 0, %for.loop ], [ %for.loop.idx3.next, %.exit ]
  %dst.addr57.gep9 = getelementptr [8 x [8 x float]], [8 x [8 x float]]* %0, i64 0, i64 %for.loop.idx12, i64 %for.loop.idx311
  %4 = bitcast float* %dst.addr57.gep9 to i8*
  switch i64 %for.loop.idx311, label %.default [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
    i64 4, label %.case.4
    i64 5, label %.case.5
    i64 6, label %.case.6
    i64 7, label %.case.7
  ]

.default:                                         ; preds = %for.loop2
  unreachable

.case.0:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_01, i64 4, i1 false)
  br label %.exit

.case.1:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_12, i64 4, i1 false)
  br label %.exit

.case.2:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_23, i64 4, i1 false)
  br label %.exit

.case.3:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_34, i64 4, i1 false)
  br label %.exit

.case.4:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_45, i64 4, i1 false)
  br label %.exit

.case.5:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_56, i64 4, i1 false)
  br label %.exit

.case.6:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_67, i64 4, i1 false)
  br label %.exit

.case.7:                                          ; preds = %for.loop2
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_78, i64 4, i1 false)
  br label %.exit

.exit:                                            ; preds = %.case.7, %.case.6, %.case.5, %.case.4, %.case.3, %.case.2, %.case.1, %.case.0
  %for.loop.idx3.next = add nuw nsw i64 %for.loop.idx311, 1
  %exitcond = icmp ne i64 %for.loop.idx3.next, 8
  br i1 %exitcond, label %for.loop2, label %for.loop.split

for.loop.split:                                   ; preds = %.exit
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx12, 1
  %exitcond13 = icmp ne i64 %for.loop.idx.next, 8
  br i1 %exitcond13, label %for.loop, label %ret

ret:                                              ; preds = %for.loop.split, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @onebyonecpy_hls.p0a8f32.13.14([8 x float]* noalias "orig.arg.no"="0", float* noalias readonly align 512 "orig.arg.no"="1" %_0, float* noalias readonly align 512 "orig.arg.no"="1" %_1, float* noalias readonly align 512 "orig.arg.no"="1" %_2, float* noalias readonly align 512 "orig.arg.no"="1" %_3, float* noalias readonly align 512 "orig.arg.no"="1" %_4, float* noalias readonly align 512 "orig.arg.no"="1" %_5, float* noalias readonly align 512 "orig.arg.no"="1" %_6, float* noalias readonly align 512 "orig.arg.no"="1" %_7) #2 {
entry:
  %1 = icmp eq [8 x float]* %0, null
  %2 = icmp eq float* %_0, null
  %3 = or i1 %1, %2
  br i1 %3, label %ret, label %copy

copy:                                             ; preds = %entry
  %_01 = bitcast float* %_0 to i8*
  %_12 = bitcast float* %_1 to i8*
  %_23 = bitcast float* %_2 to i8*
  %_34 = bitcast float* %_3 to i8*
  %_45 = bitcast float* %_4 to i8*
  %_56 = bitcast float* %_5 to i8*
  %_67 = bitcast float* %_6 to i8*
  %_78 = bitcast float* %_7 to i8*
  br label %for.loop

for.loop:                                         ; preds = %.exit, %copy
  %for.loop.idx3 = phi i64 [ 0, %copy ], [ %for.loop.idx.next, %.exit ]
  %dst.addr.gep1 = getelementptr [8 x float], [8 x float]* %0, i64 0, i64 %for.loop.idx3
  %4 = bitcast float* %dst.addr.gep1 to i8*
  switch i64 %for.loop.idx3, label %.default [
    i64 0, label %.case.0
    i64 1, label %.case.1
    i64 2, label %.case.2
    i64 3, label %.case.3
    i64 4, label %.case.4
    i64 5, label %.case.5
    i64 6, label %.case.6
    i64 7, label %.case.7
  ]

.default:                                         ; preds = %for.loop
  unreachable

.case.0:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_01, i64 4, i1 false)
  br label %.exit

.case.1:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_12, i64 4, i1 false)
  br label %.exit

.case.2:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_23, i64 4, i1 false)
  br label %.exit

.case.3:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_34, i64 4, i1 false)
  br label %.exit

.case.4:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_45, i64 4, i1 false)
  br label %.exit

.case.5:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_56, i64 4, i1 false)
  br label %.exit

.case.6:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_67, i64 4, i1 false)
  br label %.exit

.case.7:                                          ; preds = %for.loop
  call void @llvm.memcpy.p0i8.p0i8.i64(i8* align 1 %4, i8* align 1 %_78, i64 4, i1 false)
  br label %.exit

.exit:                                            ; preds = %.case.7, %.case.6, %.case.5, %.case.4, %.case.3, %.case.2, %.case.1, %.case.0
  %for.loop.idx.next = add nuw nsw i64 %for.loop.idx3, 1
  %exitcond = icmp ne i64 %for.loop.idx.next, 8
  br i1 %exitcond, label %for.loop, label %ret

ret:                                              ; preds = %.exit, %entry
  ret void
}

; Function Attrs: argmemonly noinline
define internal void @copy_out([8 x [8 x float]]* "orig.arg.no"="0", [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_0, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_1, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_2, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_3, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_4, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_5, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_6, [8 x float]* noalias readonly align 512 "orig.arg.no"="1" %_7, [8 x float]* "orig.arg.no"="2", float* noalias readonly align 512 "orig.arg.no"="3" %_01, float* noalias readonly align 512 "orig.arg.no"="3" %_12, float* noalias readonly align 512 "orig.arg.no"="3" %_23, float* noalias readonly align 512 "orig.arg.no"="3" %_34, float* noalias readonly align 512 "orig.arg.no"="3" %_45, float* noalias readonly align 512 "orig.arg.no"="3" %_56, float* noalias readonly align 512 "orig.arg.no"="3" %_67, float* noalias readonly align 512 "orig.arg.no"="3" %_78, [8 x float]* "orig.arg.no"="4", [8 x float]* noalias readonly align 512 "orig.arg.no"="5") #4 {
entry:
  call void @onebyonecpy_hls.p0a8a8f32.11.12([8 x [8 x float]]* %0, [8 x float]* align 512 %_0, [8 x float]* align 512 %_1, [8 x float]* align 512 %_2, [8 x float]* align 512 %_3, [8 x float]* align 512 %_4, [8 x float]* align 512 %_5, [8 x float]* align 512 %_6, [8 x float]* align 512 %_7)
  call void @onebyonecpy_hls.p0a8f32.13.14([8 x float]* %1, float* align 512 %_01, float* align 512 %_12, float* align 512 %_23, float* align 512 %_34, float* align 512 %_45, float* align 512 %_56, float* align 512 %_67, float* align 512 %_78)
  call fastcc void @onebyonecpy_hls.p0a8f32([8 x float]* %2, [8 x float]* align 512 %3)
  ret void
}

declare void @apatb_matrix_vector_hw([8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, float*, float*, float*, float*, float*, float*, float*, float*, float*)

define void @matrix_vector_hw_stub_wrapper([8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, [8 x float]*, float*, float*, float*, float*, float*, float*, float*, float*, float*) #5 {
entry:
  %17 = alloca [8 x [8 x float]]
  %18 = alloca [8 x float]
  %19 = bitcast float* %16 to [8 x float]*
  call void @copy_out([8 x [8 x float]]* %17, [8 x float]* %0, [8 x float]* %1, [8 x float]* %2, [8 x float]* %3, [8 x float]* %4, [8 x float]* %5, [8 x float]* %6, [8 x float]* %7, [8 x float]* %18, float* %8, float* %9, float* %10, float* %11, float* %12, float* %13, float* %14, float* %15, [8 x float]* null, [8 x float]* %19)
  %20 = bitcast [8 x [8 x float]]* %17 to [8 x float]*
  %21 = bitcast [8 x float]* %18 to float*
  %22 = bitcast [8 x float]* %19 to float*
  call void @matrix_vector_hw_stub([8 x float]* %20, float* %21, float* %22)
  call void @copy_in([8 x [8 x float]]* %17, [8 x float]* %0, [8 x float]* %1, [8 x float]* %2, [8 x float]* %3, [8 x float]* %4, [8 x float]* %5, [8 x float]* %6, [8 x float]* %7, [8 x float]* %18, float* %8, float* %9, float* %10, float* %11, float* %12, float* %13, float* %14, float* %15, [8 x float]* null, [8 x float]* %19)
  ret void
}

declare void @matrix_vector_hw_stub([8 x float]*, float*, float*)

attributes #0 = { noinline "fpga.wrapper.func"="wrapper" }
attributes #1 = { argmemonly nounwind }
attributes #2 = { argmemonly noinline "fpga.wrapper.func"="onebyonecpy_hls" }
attributes #3 = { argmemonly noinline "fpga.wrapper.func"="copyin" }
attributes #4 = { argmemonly noinline "fpga.wrapper.func"="copyout" }
attributes #5 = { "fpga.wrapper.func"="stub" }

!llvm.dbg.cu = !{}
!llvm.ident = !{!0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0, !0}
!llvm.module.flags = !{!1, !2, !3}
!blackbox_cfg = !{!4}

!0 = !{!"clang version 7.0.0 "}
!1 = !{i32 2, !"Dwarf Version", i32 4}
!2 = !{i32 2, !"Debug Info Version", i32 3}
!3 = !{i32 1, !"wchar_size", i32 4}
!4 = !{}
