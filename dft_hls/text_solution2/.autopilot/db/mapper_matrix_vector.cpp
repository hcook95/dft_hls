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
extern "C" void matrix_vector(int*, int*, int*, int*, int*);
extern "C" void apatb_matrix_vector_hw(volatile void * __xlx_apatb_param_M_0, volatile void * __xlx_apatb_param_M_1, volatile void * __xlx_apatb_param_V_In_0, volatile void * __xlx_apatb_param_V_In_1, volatile void * __xlx_apatb_param_V_Out) {
  // Collect __xlx_M_0__tmp_vec
  vector<sc_bv<32> >__xlx_M_0__tmp_vec;
  for (int j = 0, e = 32; j != e; ++j) {
    __xlx_M_0__tmp_vec.push_back(((int*)__xlx_apatb_param_M_0)[j]);
  }
  int __xlx_size_param_M_0 = 32;
  int __xlx_offset_param_M_0 = 0;
  int __xlx_offset_byte_param_M_0 = 0*4;
  int* __xlx_M_0__input_buffer= new int[__xlx_M_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_0__tmp_vec.size(); ++i) {
    __xlx_M_0__input_buffer[i] = __xlx_M_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_M_1__tmp_vec
  vector<sc_bv<32> >__xlx_M_1__tmp_vec;
  for (int j = 0, e = 32; j != e; ++j) {
    __xlx_M_1__tmp_vec.push_back(((int*)__xlx_apatb_param_M_1)[j]);
  }
  int __xlx_size_param_M_1 = 32;
  int __xlx_offset_param_M_1 = 0;
  int __xlx_offset_byte_param_M_1 = 0*4;
  int* __xlx_M_1__input_buffer= new int[__xlx_M_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_M_1__tmp_vec.size(); ++i) {
    __xlx_M_1__input_buffer[i] = __xlx_M_1__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_V_In_0__tmp_vec
  vector<sc_bv<32> >__xlx_V_In_0__tmp_vec;
  for (int j = 0, e = 4; j != e; ++j) {
    __xlx_V_In_0__tmp_vec.push_back(((int*)__xlx_apatb_param_V_In_0)[j]);
  }
  int __xlx_size_param_V_In_0 = 4;
  int __xlx_offset_param_V_In_0 = 0;
  int __xlx_offset_byte_param_V_In_0 = 0*4;
  int* __xlx_V_In_0__input_buffer= new int[__xlx_V_In_0__tmp_vec.size()];
  for (int i = 0; i < __xlx_V_In_0__tmp_vec.size(); ++i) {
    __xlx_V_In_0__input_buffer[i] = __xlx_V_In_0__tmp_vec[i].range(31, 0).to_uint64();
  }
  // Collect __xlx_V_In_1__tmp_vec
  vector<sc_bv<32> >__xlx_V_In_1__tmp_vec;
  for (int j = 0, e = 4; j != e; ++j) {
    __xlx_V_In_1__tmp_vec.push_back(((int*)__xlx_apatb_param_V_In_1)[j]);
  }
  int __xlx_size_param_V_In_1 = 4;
  int __xlx_offset_param_V_In_1 = 0;
  int __xlx_offset_byte_param_V_In_1 = 0*4;
  int* __xlx_V_In_1__input_buffer= new int[__xlx_V_In_1__tmp_vec.size()];
  for (int i = 0; i < __xlx_V_In_1__tmp_vec.size(); ++i) {
    __xlx_V_In_1__input_buffer[i] = __xlx_V_In_1__tmp_vec[i].range(31, 0).to_uint64();
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
  matrix_vector(__xlx_M_0__input_buffer, __xlx_M_1__input_buffer, __xlx_V_In_0__input_buffer, __xlx_V_In_1__input_buffer, __xlx_V_Out__input_buffer);
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
// print __xlx_apatb_param_V_In_0
  sc_bv<32>*__xlx_V_In_0_output_buffer = new sc_bv<32>[__xlx_size_param_V_In_0];
  for (int i = 0; i < __xlx_size_param_V_In_0; ++i) {
    __xlx_V_In_0_output_buffer[i] = __xlx_V_In_0__input_buffer[i+__xlx_offset_param_V_In_0];
  }
  for (int i = 0; i < __xlx_size_param_V_In_0; ++i) {
    ((int*)__xlx_apatb_param_V_In_0)[i] = __xlx_V_In_0_output_buffer[i].to_uint64();
  }
// print __xlx_apatb_param_V_In_1
  sc_bv<32>*__xlx_V_In_1_output_buffer = new sc_bv<32>[__xlx_size_param_V_In_1];
  for (int i = 0; i < __xlx_size_param_V_In_1; ++i) {
    __xlx_V_In_1_output_buffer[i] = __xlx_V_In_1__input_buffer[i+__xlx_offset_param_V_In_1];
  }
  for (int i = 0; i < __xlx_size_param_V_In_1; ++i) {
    ((int*)__xlx_apatb_param_V_In_1)[i] = __xlx_V_In_1_output_buffer[i].to_uint64();
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
