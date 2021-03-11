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
#define AUTOTB_TVIN_M "../tv/cdatafile/c.matrix_vector.autotvin_M.dat"
#define AUTOTB_TVOUT_M "../tv/cdatafile/c.matrix_vector.autotvout_M.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_In "../tv/cdatafile/c.matrix_vector.autotvin_V_In.dat"
#define AUTOTB_TVOUT_V_In "../tv/cdatafile/c.matrix_vector.autotvout_V_In.dat"
// wrapc file define:
#define AUTOTB_TVIN_V_Out "../tv/cdatafile/c.matrix_vector.autotvin_V_Out.dat"
#define AUTOTB_TVOUT_V_Out "../tv/cdatafile/c.matrix_vector.autotvout_V_Out.dat"

#define INTER_TCL "../tv/cdatafile/ref.tcl"

// tvout file define:
#define AUTOTB_TVOUT_PC_M "../tv/rtldatafile/rtl.matrix_vector.autotvout_M.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_In "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_In.dat"
// tvout file define:
#define AUTOTB_TVOUT_PC_V_Out "../tv/rtldatafile/rtl.matrix_vector.autotvout_V_Out.dat"

class INTER_TCL_FILE {
  public:
INTER_TCL_FILE(const char* name) {
  mName = name; 
  M_depth = 0;
  V_In_depth = 0;
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
  total_list << "{M " << M_depth << "}\n";
  total_list << "{V_In " << V_In_depth << "}\n";
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
    int M_depth;
    int V_In_depth;
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
extern "C" void matrix_vector_hw_stub_wrapper(volatile void *, volatile void *, volatile void *);

extern "C" void apatb_matrix_vector_hw(volatile void * __xlx_apatb_param_M, volatile void * __xlx_apatb_param_V_In, volatile void * __xlx_apatb_param_V_Out) {
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
//M
aesl_fh.touch(AUTOTB_TVIN_M);
aesl_fh.touch(AUTOTB_TVOUT_M);
//V_In
aesl_fh.touch(AUTOTB_TVIN_V_In);
aesl_fh.touch(AUTOTB_TVOUT_V_In);
//V_Out
aesl_fh.touch(AUTOTB_TVIN_V_Out);
aesl_fh.touch(AUTOTB_TVOUT_V_Out);
CodeState = DUMP_INPUTS;
unsigned __xlx_offset_byte_param_M = 0;
// print M Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_M, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_M = 0*4;
  if (__xlx_apatb_param_M) {
    for (int j = 0  - 0, e = 64 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_M)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_M, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(64, &tcl_file.M_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_M, __xlx_sprintf_buffer.data());
}
unsigned __xlx_offset_byte_param_V_In = 0;
// print V_In Transactions
{
  sprintf(__xlx_sprintf_buffer.data(), "[[transaction]] %d\n", AESL_transaction);
  aesl_fh.write(AUTOTB_TVIN_V_In, __xlx_sprintf_buffer.data());
  {  __xlx_offset_byte_param_V_In = 0*4;
  if (__xlx_apatb_param_V_In) {
    for (int j = 0  - 0, e = 8 - 0; j != e; ++j) {
sc_bv<32> __xlx_tmp_lv = ((int*)__xlx_apatb_param_V_In)[j];

    sprintf(__xlx_sprintf_buffer.data(), "%s\n", __xlx_tmp_lv.to_string(SC_HEX).c_str());
    aesl_fh.write(AUTOTB_TVIN_V_In, __xlx_sprintf_buffer.data()); 
      }
  }
}
  tcl_file.set_num(8, &tcl_file.V_In_depth);
  sprintf(__xlx_sprintf_buffer.data(), "[[/transaction]] \n");
  aesl_fh.write(AUTOTB_TVIN_V_In, __xlx_sprintf_buffer.data());
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
matrix_vector_hw_stub_wrapper(__xlx_apatb_param_M, __xlx_apatb_param_V_In, __xlx_apatb_param_V_Out);
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
