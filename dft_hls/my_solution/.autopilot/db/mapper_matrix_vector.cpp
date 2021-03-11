#include <systemc>
#include <vector>
#include <iostream>
#include "hls_stream.h"
#include "ap_int.h"
#include "ap_fixed.h"
using namespace std;
using namespace sc_dt;
class AESL_RUNTIME_BC {
  public:
    AESL_RUNTIME_BC(const char* name) {
      file_token.open( name);
      if (!file_token.good()) {
        cout << "Failed to open tv file " << name << endl;
        exit (1);
      }
      file_token >> mName;//[[[runtime]]]
    }
    ~AESL_RUNTIME_BC() {
      file_token.close();
    }
    int read_size () {
      int size = 0;
      file_token >> mName;//[[transaction]]
      file_token >> mName;//transaction number
      file_token >> mName;//pop_size
      size = atoi(mName.c_str());
      file_token >> mName;//[[/transaction]]
      return size;
    }
  public:
    fstream file_token;
    string mName;
};
extern "C" void matrix_vector(int*, int*, int*, int*, int*, int*, int*, int*, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, int*);
extern "C" void apatb_matrix_vector_hw(volatile void * __xlx_apatb_param_M_0, volatile void * __xlx_apatb_param_M_1, volatile void * __xlx_apatb_param_M_2, volatile void * __xlx_apatb_param_M_3, volatile void * __xlx_apatb_param_M_4, volatile void * __xlx_apatb_param_M_5, volatile void * __xlx_apatb_param_M_6, volatile void * __xlx_apatb_param_M_7, volatile void * __xlx_apatb_param_V_In_0, volatile void * __xlx_apatb_param_V_In_1, volatile void * __xlx_apatb_param_V_In_2, volatile void * __xlx_apatb_param_V_In_3, volatile void * __xlx_apatb_param_V_In_4, volatile void * __xlx_apatb_param_V_In_5, volatile void * __xlx_apatb_param_V_In_6, volatile void * __xlx_apatb_param_V_In_7, volatile void * __xlx_apatb_param_V_Out) {
  // Collect __xlx_M_0__tmp_vec
  vector<sc_bv<32> >__xlx_M_0__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_0__tmp_vec.push_back(((int*)__xlx_apatb_param_M_0)[j]);
  }
  int __xlx_size_param_M_0 = 8;
  int __xlx_offset_param_M_0 = 0;
  int __xlx_offset_byte_param_M_0 = 0*4;
  int* __xlx_M_0__input_buffer= new int[__xlx_M_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_0__tmp_vec.size(); ++i) {
    __xlx_M_0__input_buffer[i] = __xlx_M_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_1__tmp_vec
  vector<sc_bv<32> >__xlx_M_1__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_1__tmp_vec.push_back(((int*)__xlx_apatb_param_M_1)[j]);
  }
  int __xlx_size_param_M_1 = 8;
  int __xlx_offset_param_M_1 = 0;
  int __xlx_offset_byte_param_M_1 = 0*4;
  int* __xlx_M_1__input_buffer= new int[__xlx_M_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_1__tmp_vec.size(); ++i) {
    __xlx_M_1__input_buffer[i] = __xlx_M_1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_2__tmp_vec
  vector<sc_bv<32> >__xlx_M_2__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_2__tmp_vec.push_back(((int*)__xlx_apatb_param_M_2)[j]);
  }
  int __xlx_size_param_M_2 = 8;
  int __xlx_offset_param_M_2 = 0;
  int __xlx_offset_byte_param_M_2 = 0*4;
  int* __xlx_M_2__input_buffer= new int[__xlx_M_2__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_2__tmp_vec.size(); ++i) {
    __xlx_M_2__input_buffer[i] = __xlx_M_2__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_3__tmp_vec
  vector<sc_bv<32> >__xlx_M_3__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_3__tmp_vec.push_back(((int*)__xlx_apatb_param_M_3)[j]);
  }
  int __xlx_size_param_M_3 = 8;
  int __xlx_offset_param_M_3 = 0;
  int __xlx_offset_byte_param_M_3 = 0*4;
  int* __xlx_M_3__input_buffer= new int[__xlx_M_3__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_3__tmp_vec.size(); ++i) {
    __xlx_M_3__input_buffer[i] = __xlx_M_3__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_4__tmp_vec
  vector<sc_bv<32> >__xlx_M_4__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_4__tmp_vec.push_back(((int*)__xlx_apatb_param_M_4)[j]);
  }
  int __xlx_size_param_M_4 = 8;
  int __xlx_offset_param_M_4 = 0;
  int __xlx_offset_byte_param_M_4 = 0*4;
  int* __xlx_M_4__input_buffer= new int[__xlx_M_4__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_4__tmp_vec.size(); ++i) {
    __xlx_M_4__input_buffer[i] = __xlx_M_4__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_5__tmp_vec
  vector<sc_bv<32> >__xlx_M_5__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_5__tmp_vec.push_back(((int*)__xlx_apatb_param_M_5)[j]);
  }
  int __xlx_size_param_M_5 = 8;
  int __xlx_offset_param_M_5 = 0;
  int __xlx_offset_byte_param_M_5 = 0*4;
  int* __xlx_M_5__input_buffer= new int[__xlx_M_5__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_5__tmp_vec.size(); ++i) {
    __xlx_M_5__input_buffer[i] = __xlx_M_5__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_6__tmp_vec
  vector<sc_bv<32> >__xlx_M_6__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_6__tmp_vec.push_back(((int*)__xlx_apatb_param_M_6)[j]);
  }
  int __xlx_size_param_M_6 = 8;
  int __xlx_offset_param_M_6 = 0;
  int __xlx_offset_byte_param_M_6 = 0*4;
  int* __xlx_M_6__input_buffer= new int[__xlx_M_6__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_6__tmp_vec.size(); ++i) {
    __xlx_M_6__input_buffer[i] = __xlx_M_6__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_7__tmp_vec
  vector<sc_bv<32> >__xlx_M_7__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_M_7__tmp_vec.push_back(((int*)__xlx_apatb_param_M_7)[j]);
  }
  int __xlx_size_param_M_7 = 8;
  int __xlx_offset_param_M_7 = 0;
  int __xlx_offset_byte_param_M_7 = 0*4;
  int* __xlx_M_7__input_buffer= new int[__xlx_M_7__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_7__tmp_vec.size(); ++i) {
    __xlx_M_7__input_buffer[i] = __xlx_M_7__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_V_Out__tmp_vec
  vector<sc_bv<32> >__xlx_V_Out__tmp_vec;
  for (int j = 0, e = 8; j != e; ++j) {
    __xlx_V_Out__tmp_vec.push_back(((int*)__xlx_apatb_param_V_Out)[j]);
  }
  int __xlx_size_param_V_Out = 8;
  int __xlx_offset_param_V_Out = 0;
  int __xlx_offset_byte_param_V_Out = 0*4;
  int* __xlx_V_Out__input_buffer= new int[__xlx_V_Out__tmp_vec.size()];
  for (int i = 0; i < __xlx_V_Out__tmp_vec.size(); ++i) {
    __xlx_V_Out__input_buffer[i] = __xlx_V_Out__tmp_vec[i].range(31, 0).to_uint64();
  }
  // DUT call
  matrix_vector(__xlx_M_0__input_buffer, __xlx_M_1__input_buffer, __xlx_M_2__input_buffer, __xlx_M_3__input_buffer, __xlx_M_4__input_buffer, __xlx_M_5__input_buffer, __xlx_M_6__input_buffer, __xlx_M_7__input_buffer, __xlx_apatb_param_V_In_0, __xlx_apatb_param_V_In_1, __xlx_apatb_param_V_In_2, __xlx_apatb_param_V_In_3, __xlx_apatb_param_V_In_4, __xlx_apatb_param_V_In_5, __xlx_apatb_param_V_In_6, __xlx_apatb_param_V_In_7, __xlx_V_Out__input_buffer);
// print __xlx_apatb_param_M_0
  sc_bv<32>*__xlx_M_0_output_buffer = new sc_bv<32>[__xlx_size_param_M_0];
  for (int i = 0; i < __xlx_size_param_M_0; ++i) {
    __xlx_M_0_output_buffer[i] = __xlx_M_0__input_buffer[i+__xlx_offset_param_M_0];
  }
  for (int i = 0; i < __xlx_size_param_M_0; ++i) {
    ((int*)__xlx_apatb_param_M_0)[i] = __xlx_M_0_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_1
  sc_bv<32>*__xlx_M_1_output_buffer = new sc_bv<32>[__xlx_size_param_M_1];
  for (int i = 0; i < __xlx_size_param_M_1; ++i) {
    __xlx_M_1_output_buffer[i] = __xlx_M_1__input_buffer[i+__xlx_offset_param_M_1];
  }
  for (int i = 0; i < __xlx_size_param_M_1; ++i) {
    ((int*)__xlx_apatb_param_M_1)[i] = __xlx_M_1_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_2
  sc_bv<32>*__xlx_M_2_output_buffer = new sc_bv<32>[__xlx_size_param_M_2];
  for (int i = 0; i < __xlx_size_param_M_2; ++i) {
    __xlx_M_2_output_buffer[i] = __xlx_M_2__input_buffer[i+__xlx_offset_param_M_2];
  }
  for (int i = 0; i < __xlx_size_param_M_2; ++i) {
    ((int*)__xlx_apatb_param_M_2)[i] = __xlx_M_2_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_3
  sc_bv<32>*__xlx_M_3_output_buffer = new sc_bv<32>[__xlx_size_param_M_3];
  for (int i = 0; i < __xlx_size_param_M_3; ++i) {
    __xlx_M_3_output_buffer[i] = __xlx_M_3__input_buffer[i+__xlx_offset_param_M_3];
  }
  for (int i = 0; i < __xlx_size_param_M_3; ++i) {
    ((int*)__xlx_apatb_param_M_3)[i] = __xlx_M_3_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_4
  sc_bv<32>*__xlx_M_4_output_buffer = new sc_bv<32>[__xlx_size_param_M_4];
  for (int i = 0; i < __xlx_size_param_M_4; ++i) {
    __xlx_M_4_output_buffer[i] = __xlx_M_4__input_buffer[i+__xlx_offset_param_M_4];
  }
  for (int i = 0; i < __xlx_size_param_M_4; ++i) {
    ((int*)__xlx_apatb_param_M_4)[i] = __xlx_M_4_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_5
  sc_bv<32>*__xlx_M_5_output_buffer = new sc_bv<32>[__xlx_size_param_M_5];
  for (int i = 0; i < __xlx_size_param_M_5; ++i) {
    __xlx_M_5_output_buffer[i] = __xlx_M_5__input_buffer[i+__xlx_offset_param_M_5];
  }
  for (int i = 0; i < __xlx_size_param_M_5; ++i) {
    ((int*)__xlx_apatb_param_M_5)[i] = __xlx_M_5_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_6
  sc_bv<32>*__xlx_M_6_output_buffer = new sc_bv<32>[__xlx_size_param_M_6];
  for (int i = 0; i < __xlx_size_param_M_6; ++i) {
    __xlx_M_6_output_buffer[i] = __xlx_M_6__input_buffer[i+__xlx_offset_param_M_6];
  }
  for (int i = 0; i < __xlx_size_param_M_6; ++i) {
    ((int*)__xlx_apatb_param_M_6)[i] = __xlx_M_6_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_M_7
  sc_bv<32>*__xlx_M_7_output_buffer = new sc_bv<32>[__xlx_size_param_M_7];
  for (int i = 0; i < __xlx_size_param_M_7; ++i) {
    __xlx_M_7_output_buffer[i] = __xlx_M_7__input_buffer[i+__xlx_offset_param_M_7];
  }
  for (int i = 0; i < __xlx_size_param_M_7; ++i) {
    ((int*)__xlx_apatb_param_M_7)[i] = __xlx_M_7_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_V_Out
  sc_bv<32>*__xlx_V_Out_output_buffer = new sc_bv<32>[__xlx_size_param_V_Out];
  for (int i = 0; i < __xlx_size_param_V_Out; ++i) {
    __xlx_V_Out_output_buffer[i] = __xlx_V_Out__input_buffer[i+__xlx_offset_param_V_Out];
  }
  for (int i = 0; i < __xlx_size_param_V_Out; ++i) {
    ((int*)__xlx_apatb_param_V_Out)[i] = __xlx_V_Out_output_buffer[i].to_uint64();
  }
}
