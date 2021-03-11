#include <systemc>
#include <iostream>
#include <cstdlib>
#include <cstddef>
#include <stdint.h>
#include "SysCFileHandler.h"
#include "ap_int.h"
#include "ap_fixed.h"
#include <complex>
#include <stdbool.h>
#include "autopilot_cbe.h"
#include "hls_stream.h"
#include "hls_half.h"
#include "hls_signal_handler.h"

using namespace std;
using namespace sc_core;
using namespace sc_dt;

// wrapc file define:
#define AUTOTB_TVIN_M_0 "../tv/cdatafile/c.matrix_vector.autotvin_M_0.dat"
#define AUTOTB_TVOUT_M_0 "../tv/cdatafile/c.matrix_vector.autotvout_M_0.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_1 "../tv/cdatafile/c.matrix_vector.autotvin_M_1.dat"
#define AUTOTB_TVOUT_M_1 "../tv/cdatafile/c.matrix_vector.autotvout_M_1.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_2 "../tv/cdatafile/c.matrix_vector.autotvin_M_2.dat"
#define AUTOTB_TVOUT_M_2 "../tv/cdatafile/c.matrix_vector.autotvout_M_2.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_3 "../tv/cdatafile/c.matrix_vector.autotvin_M_3.dat"
#define AUTOTB_TVOUT_M_3 "../tv/cdatafile/c.matrix_vector.autotvout_M_3.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_4 "../tv/cdatafile/c.matrix_vector.autotvin_M_4.dat"
#define AUTOTB_TVOUT_M_4 "../tv/cdatafile/c.matrix_vector.autotvout_M_4.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_5 "../tv/cdatafile/c.matrix_vector.autotvin_M_5.dat"
#define AUTOTB_TVOUT_M_5 "../tv/cdatafile/c.matrix_vector.autotvout_M_5.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_6 "../tv/cdatafile/c.matrix_vector.autotvin_M_6.dat"
#define AUTOTB_TVOUT_M_6 "../tv/cdatafile/c.matrix_vector.autotvout_M_6.dat"
// wrapc file define:
#define AUTOTB_TVIN_M_7 "../tv/cdatafile/c.matrix_vector.autotvin_M_7.dat"
#define AUTOTB_TVOUT_M_7 "../tv/cdatafile/c.matrix_vector.autotvout_M_7.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_0 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_0.dat"
#define AUTOTB_TVOUT_V_In_0 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_0.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_1 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_1.dat"
#define AUTOTB_TVOUT_V_In_1 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_1.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_2 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_2.dat"
#define AUTOTB_TVOUT_V_In_2 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_2.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_3 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_3.dat"
#define AUTOTB_TVOUT_V_In_3 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_3.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_4 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_4.dat"
#define AUTOTB_TVOUT_V_In_4 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_4.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_5 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_5.dat"
#define AUTOTB_TVOUT_V_In_5 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_5.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_6 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_6.dat"
#define AUTOTB_TVOUT_V_In_6 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_6.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In_7 "../tv/cdatafile/c.matrix_vector.autotvin_V_In_7.dat"
#define AUTOTB_TVOUT_V_In_7 "../tv/cdatafile/c.matrix_vector.autotvout_V_In_7.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_Out "../tv/cdatafile/c.matrix_vector.autotvin_V_Out.dat"
#define AUTOTB_TVOUT_V_Out "../tv/cdatafile/c.matrix_vector.autotvout_V_Out.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_M_0 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_1 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_2 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_3 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_4 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_4.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_5 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_5.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_6 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_6.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_M_7 "../tv/rtldatafile/rtl.matrix_vector.autotvout_M_7.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_0 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_0.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_1 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_1.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_2 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_2.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_3 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_3.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_4 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_4.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_5 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_5.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_6 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_6.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In_7 "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In_7.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_Out "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_Out.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  M_0_depth = 0;
  M_1_depth = 0;
  M_2_depth = 0;
  M_3_depth = 0;
  M_4_depth = 0;
  M_5_depth = 0;
  M_6_depth = 0;
  M_7_depth = 0;
  V_In_0_depth = 0;
  V_In_1_depth = 0;
  V_In_2_depth = 0;
  V_In_3_depth = 0;
  V_In_4_depth = 0;
  V_In_5_depth = 0;
  V_In_6_depth = 0;
  V_In_7_depth = 0;
  V_Out_depth = 0;
  trans_num =0;
}
~INTER_TCL_FILE() {
  mFile.open(mName);
  if (!mFile.good()) {
    cout << "Failed to open file ref.tcl" << endl;
    exit (1); 
  }
  string total_list = get_depth_list();
  mFile << "set depth_list {\n";
  mFile << total_list;
  mFile << "}\n";
  mFile << "set trans_num "<<trans_num<<endl;
  mFile.close();
}
string get_depth_list () {
  stringstream total_list;
  total_list << "{M_0 " << M_0_depth << "}\n";
  total_list << "{M_1 " << M_1_depth << "}\n";
  total_list << "{M_2 " << M_2_depth << "}\n";
  total_list << "{M_3 " << M_3_depth << "}\n";
  total_list << "{M_4 " << M_4_depth << "}\n";
  total_list << "{M_5 " << M_5_depth << "}\n";
  total_list << "{M_6 " << M_6_depth << "}\n";
  total_list << "{M_7 " << M_7_depth << "}\n";
  total_list << "{V_In_0 " << V_In_0_depth << "}\n";
  total_list << "{V_In_1 " << V_In_1_depth << "}\n";
  total_list << "{V_In_2 " << V_In_2_depth << "}\n";
  total_list << "{V_In_3 " << V_In_3_depth << "}\n";
  total_list << "{V_In_4 " << V_In_4_depth << "}\n";
  total_list << "{V_In_5 " << V_In_5_depth << "}\n";
  total_list << "{V_In_6 " << V_In_6_depth << "}\n";
  total_list << "{V_In_7 " << V_In_7_depth << "}\n";
  total_list << "{V_Out " << V_Out_depth << "}\n";
  return total_list.str();
}
void set_num (int num , int* class_num) {
  (*class_num) = (*class_num) > num ? (*class_num) : num;
}
void set_string(std::string list, std::string* class_list) {
  (*class_list) = list;
}
  public:
    int M_0_depth;
    int M_1_depth;
    int M_2_depth;
    int M_3_depth;
    int M_4_depth;
    int M_5_depth;
    int M_6_depth;
    int M_7_depth;
    int V_In_0_depth;
    int V_In_1_depth;
    int V_In_2_depth;
    int V_In_3_depth;
    int V_In_4_depth;
    int V_In_5_depth;
    int V_In_6_depth;
    int V_In_7_depth;
    int V_Out_depth;
    int trans_num;
  private:
    ofstream mFile;
    const char* mName;
};

static void RTLOutputCheckAndReplacement(std::string &AESL_token, std::string PortName) {
  bool no_x = false;
  bool err = false;

  no_x = false;
  // search and replace 'X' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('X', 0);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'X' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
  no_x = false;
  // search and replace 'x' with '0' from the 3rd char of token
  while (!no_x) {
    size_t x_found = AESL_token.find('x', 2);
    if (x_found != string::npos) {
      if (!err) { 
        cerr << "WARNING: [SIM 212-201] RTL produces unknown value 'x' on port" 
             << PortName << ", possible cause: There are uninitialized variables in the C design."
             << endl; 
        err = true;
      }
      AESL_token.replace(x_found, 1, "0");
    } else
      no_x = true;
  }
}
extern "C" void matrix_vector_hw_stub_wrapper(volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *, volatile void *);

extern "C" void apatb_matrix_vector_hw(volatile void * __xlx_apatb_param_M_0, volatile void * __xlx_apatb_param_M_1, volatile void * __xlx_apatb_param_M_2, volatile void * __xlx_apatb_param_M_3, volatile void * __xlx_apatb_param_M_4, volatile void * __xlx_apatb_param_M_5, volatile void * __xlx_apatb_param_M_6, volatile void * __xlx_apatb_param_M_7, volatile void * __xlx_apatb_param_V_In_0, volatile void * __xlx_apatb_param_V_In_1, volatile void * __xlx_apatb_param_V_In_2, volatile void * __xlx_apatb_param_V_In_3, volatile void * __xlx_apatb_param_V_In_4, volatile void * __xlx_apatb_param_V_In_5, volatile void * __xlx_apatb_param_V_In_6, volatile void * __xlx_apatb_param_V_In_7, volatile void * __xlx_apatb_param_V_Out) {
  refine_signal_handler();
  fstream wrapc_switch_file_token;
  wrapc_switch_file_token.open(".hls_cosim_wrapc_switch.log");
  int AESL_i;
  if (wrapc_switch_file_token.good())
  {

    CodeState = ENTER_WRAPC_PC;
    static unsigned AESL_transaction_pc = 0;
    string AESL_token;
    string AESL_num;{
      static ifstream rtl_tv_out_file;
      if (!rtl_tv_out_file.is_open()) {
        rtl_tv_out_file.open(AUTOTB_TVOUT_PC_V_Out);
        if (rtl_tv_out_file.good()) {
          rtl_tv_out_file >> AESL_token;
          if (AESL_token != "[[[runtime]]]")
            exit(1);
        }
      }
  
      if (rtl_tv_out_file.good()) {
        rtl_tv_out_file >> AESL_token; 
        rtl_tv_out_file >> AESL_num;  // transaction number
        if (AESL_token != "[[transaction]]") {
          cerr << "Unexpected token: " << AESL_token << endl;
          exit(1);
        }
        if (atoi(AESL_num.c_str()) == AESL_transaction_pc) {
          std::vector<sc_bv<32> > V_Out_pc_buffer(8);
          int i = 0;

          rtl_tv_out_file >> AESL_token; //data
          while (AESL_token != "[[/transaction]]"){

            RTLOutputCheckAndReplacement(AESL_token, "V_Out");
  
            // push token into output port buffer
            if (AESL_token != "") {
              V_Out_pc_buffer[i] = AESL_token.c_str();;
              i++;
            }
  
            rtl_tv_out_file >> AESL_token; //data or [[/transaction]]
            if (AESL_token == "[[[/runtime]]]" || rtl_tv_out_file.eof())
              exit(1);
          }
          if (i > 0) {{
            int i = 0;
            for (int j = 0, e = 8; j < e; j += 1, ++i) {
            ((int*)__xlx_apatb_param_V_Out)[j] = V_Out_pc_buffer[i].to_int64();
          }}}
        } // end transaction
      } // end file is good
    } // end post check logic bolck
  
    AESL_transaction_pc++;
    return ;
  }
static unsigned AESL_transaction;
static AESL_FILE_HANDLER aesl_fh;
static INTER_TCL_FILE tcl_file(INTER_TCL);
std::vector<char> __xlx_sprintf_buffer(1024);
CodeState = ENTER_WRAPC;
//M_0
aesl_fh.touch(AUTOTB_TVIN_M_0);
aesl_fh.touch(AUTOTB_TVOUT_M_0);
//M_1
aesl_fh.touch(AUTOTB_TVIN_M_1);
aesl_fh.touch(AUTOTB_TVOUT_M_1);
//M_2
aesl_fh.touch(AUTOTB_TVIN_M_2);
aesl_fh.touch(AUTOTB_TVOUT_M_2);
//M_3
aesl_fh.touch(AUTOTB_TVIN_M_3);
aesl_fh.touch(AUTOTB_TVOUT_M_3);
//M_4
aesl_fh.touch(AUTOTB_TVIN_M_4);
aesl_fh.touch(AUTOTB_TVOUT_M_4);
//M_5
aesl_fh.touch(AUTOTB_TVIN_M_5);
aesl_fh.touch(AUTOTB_TVOUT_M_5);
//M_6
aesl_fh.touch(AUTOTB_TVIN_M_6);
aesl_fh.touch(AUTOTB_TVOUT_M_6);
//M_7
aesl_fh.touch(AUTOTB_TVIN_M_7);
aesl_fh.touch(AUTOTB_TVOUT_M_7);
//V_In_0
aesl_fh.touch(AUTOTB_TVIN_V_In_0);
aesl_fh.touch(AUTOTB_TVOUT_V_In_0);
//V_In_1
aesl_fh.touch(AUTOTB_TVIN_V_In_1);
aesl_fh.touch(AUTOTB_TVOUT_V_In_1);
//V_In_2
aesl_fh.touch(AUTOTB_TVIN_V_In_2);
aesl_fh.touch(AUTOTB_TVOUT_V_In_2);
//V_In_3
aesl_fh.touch(AUTOTB_TVIN_V_In_3);
aesl_fh.touch(AUTOTB_TVOUT_V_In_3);
//V_In_4
aesl_fh.touch(AUTOTB_TVIN_V_In_4);
aesl_fh.touch(AUTOTB_TVOUT_V_In_4);
//V_In_5
aesl_fh.touch(AUTOTB_TVIN_V_In_5);
aesl_fh.touch(AUTOTB_TVOUT_V_In_5);
//V_In_6
aesl_fh.touch(AUTOTB_TVIN_V_In_6);
aesl_fh.touch(AUTOTB_TVOUT_V_In_6);
//V_In_7
aesl_fh.touch(AUTOTB_TVIN_V_In_7);
aesl_fh.touch(AUTOTB_TVOUT_V_In_7);
//V_Out
aesl_fh.touch(AUTOTB_TVIN_V_Out);
aesl_fh.touch(AUTOTB_TVOUT_V_Out);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_M_0 = 0;
// print M_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_0, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_0 = 0*4;
  if (__xlx_apatb_param_M_0) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_0)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_0, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_0, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_1 = 0;
// print M_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_1, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_1 = 0*4;
  if (__xlx_apatb_param_M_1) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_1)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_1, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_1, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_2 = 0;
// print M_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_2, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_2 = 0*4;
  if (__xlx_apatb_param_M_2) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_2)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_2, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_2, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_3 = 0;
// print M_3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_3, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_3 = 0*4;
  if (__xlx_apatb_param_M_3) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_3)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_3, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_3, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_4 = 0;
// print M_4 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_4, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_4 = 0*4;
  if (__xlx_apatb_param_M_4) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_4)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_4, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_4_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_4, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_5 = 0;
// print M_5 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_5, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_5 = 0*4;
  if (__xlx_apatb_param_M_5) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_5)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_5, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_5_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_5, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_6 = 0;
// print M_6 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_6, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_6 = 0*4;
  if (__xlx_apatb_param_M_6) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_6)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_6, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_6_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_6, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_M_7 = 0;
// print M_7 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M_7, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M_7 = 0*4;
  if (__xlx_apatb_param_M_7) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M_7)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M_7, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.M_7_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M_7, __xlx_sprintf_buffer.data());
}
// print V_In_0 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_0, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_0);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_0, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_0_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_0, __xlx_sprintf_buffer.data());
}
// print V_In_1 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_1, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_1);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_1, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_1_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_1, __xlx_sprintf_buffer.data());
}
// print V_In_2 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_2, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_2);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_2, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_2_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_2, __xlx_sprintf_buffer.data());
}
// print V_In_3 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_3, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_3);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_3, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_3_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_3, __xlx_sprintf_buffer.data());
}
// print V_In_4 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_4, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_4);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_4, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_4_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_4, __xlx_sprintf_buffer.data());
}
// print V_In_5 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_5, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_5);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_5, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_5_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_5, __xlx_sprintf_buffer.data());
}
// print V_In_6 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_6, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_6);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_6, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_6_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_6, __xlx_sprintf_buffer.data());
}
// print V_In_7 Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In_7, __xlx_sprintf_buffer.data());
  {
    sc_bv<32> __xlx_tmp_lv = *((int*)__xlx_apatb_param_V_In_7);

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In_7, __xlx_sprintf_buffer.data()); 
  }
  tcl_file.set_num(1, &tcl_file.V_In_7_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In_7, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_V_Out = 0;
// print V_Out Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_Out, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_V_Out = 0*4;
  if (__xlx_apatb_param_V_Out) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_V_Out)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_Out, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.V_Out_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_Out, __xlx_sprintf_buffer.data());
}
CodeState = CALL_C_DUT;
matrix_vector_hw_stub_wrapper(__xlx_apatb_param_M_0, __xlx_apatb_param_M_1, __xlx_apatb_param_M_2, __xlx_apatb_param_M_3, __xlx_apatb_param_M_4, __xlx_apatb_param_M_5, __xlx_apatb_param_M_6, __xlx_apatb_param_M_7, __xlx_apatb_param_V_In_0, __xlx_apatb_param_V_In_1, __xlx_apatb_param_V_In_2, __xlx_apatb_param_V_In_3, __xlx_apatb_param_V_In_4, __xlx_apatb_param_V_In_5, __xlx_apatb_param_V_In_6, __xlx_apatb_param_V_In_7, __xlx_apatb_param_V_Out);
CodeState = DUMP_OUTPUTS;
// print V_Out Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVOUT_V_Out, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_V_Out = 0*4;
  if (__xlx_apatb_param_V_Out) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_V_Out)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVOUT_V_Out, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.V_Out_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVOUT_V_Out, __xlx_sprintf_buffer.data());
}
CodeState = DELETE_CHAR_BUFFERS;
AESL_transaction++;
tcl_file.set_num(AESL_transaction , &tcl_file.trans_num);
}
