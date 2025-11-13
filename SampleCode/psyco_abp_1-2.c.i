# 0 "/home/chris/Sikraken/SampleCode/psyco_abp_1-2.c"
# 0 "<built-in>"
# 0 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 0 "<command-line>" 2
# 1 "/home/chris/Sikraken/SampleCode/psyco_abp_1-2.c"
int __VERIFIER_nondet_int();
extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "psyco_abp_1-2.c", 4, "reach_error"); }


int m_Protocol = 1;
int m_msg_2 = 2;
int m_recv_ack_2 = 3;
int m_msg_1_1 = 4;
int m_msg_1_2 = 5;
int m_recv_ack_1_1 = 6;
int m_recv_ack_1_2 = 7;


int main() {

  int q = 0;
  int method_id;


    int this_expect = 0;
    int this_buffer_empty = 0;


  while (1) {


        int P1=__VERIFIER_nondet_int();
        int P2=__VERIFIER_nondet_int();
        int P3=__VERIFIER_nondet_int();
        int P4=__VERIFIER_nondet_int();
        int P5=__VERIFIER_nondet_int();
        int P6=__VERIFIER_nondet_int();
        int P7=__VERIFIER_nondet_int();
        int P8=__VERIFIER_nondet_int();
        int P9=__VERIFIER_nondet_int();



        if (q == 0){
                if(__VERIFIER_nondet_int()){

                  if ( 1 ){

                    method_id = 1;

                    if ( 0 ) {
                      goto ERROR;
                    }

                    q = 1;

                    this_expect=0; this_buffer_empty=1;
                  }
                  continue;
                }

          continue;
        }
        if (q == 1){
                if(__VERIFIER_nondet_int()){

                  if ( !((P1 % 2) != (0 % 2)) ){

                    method_id = 2;

                    if ( (((((P1 % 2) != (this_expect % 2)) && (this_buffer_empty == 1)) && !((P1 % 2) != (0 % 2))) || ((this_buffer_empty != 1) && !((P1 % 2) != (0 % 2)))) ) {
                      goto ERROR;
                    }

                    q = 3;

                    this_expect=(this_expect + 1); this_buffer_empty=(1 - this_buffer_empty);
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( !(P1 != (((0 + 1) - 1) % 2)) ){

                    method_id = 3;

                    if ( (((P3 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && !(P3 != (((0 + 1) - 1) % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && (((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 4;

                    if ( (((((P4 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P4 % 2) != (0 % 2))) && (((P4 % 2) != (0 % 2)) && (((P4 % 2) != ((0 + 1) % 2)) && ((P4 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && !(((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 5;

                    if ( (((((P6 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && ((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 6;

                    if ( ((((P8 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P8 != (((0 + 1) - 1) % 2))) && ((P8 != (((0 + 1) - 1) % 2)) && ((P8 != ((((0 + 1) + 1) - 1) % 2)) && (P8 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && !((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 7;

                    if ( ((((P9 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }

          continue;
        }
        if (q == 2){
                if(__VERIFIER_nondet_int()){

                  if ( !((P1 % 2) != (0 % 2)) ){

                    method_id = 2;

                    if ( ((((P1 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && !((P1 % 2) != (0 % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( !(P1 != (((0 + 1) - 1) % 2)) ){

                    method_id = 3;

                    if ( (((P3 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && !(P3 != (((0 + 1) - 1) % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && (((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 4;

                    if ( (((((P4 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P4 % 2) != (0 % 2))) && (((P4 % 2) != (0 % 2)) && (((P4 % 2) != ((0 + 1) % 2)) && ((P4 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && !(((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 5;

                    if ( (((((P6 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && ((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 6;

                    if ( ((((P8 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P8 != (((0 + 1) - 1) % 2))) && ((P8 != (((0 + 1) - 1) % 2)) && ((P8 != ((((0 + 1) + 1) - 1) % 2)) && (P8 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && !((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 7;

                    if ( ((((P9 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }

          continue;
        }
        if (q == 3){
                if(__VERIFIER_nondet_int()){

                  if ( !((P1 % 2) != (0 % 2)) ){

                    method_id = 2;

                    if ( ((((P1 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && !((P1 % 2) != (0 % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( !(P1 != (((0 + 1) - 1) % 2)) ){

                    method_id = 3;

                    if ( (((this_buffer_empty == 1) && !(P3 != (((0 + 1) - 1) % 2))) || (((P3 != ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && !(P3 != (((0 + 1) - 1) % 2)))) ) {
                      goto ERROR;
                    }

                    q = 4;

                    this_expect=this_expect; this_buffer_empty=(1 - this_buffer_empty);
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && (((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 4;

                    if ( (((((P4 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P4 % 2) != (0 % 2))) && (((P4 % 2) != (0 % 2)) && (((P4 % 2) != ((0 + 1) % 2)) && ((P4 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && !(((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 5;

                    if ( (((((P6 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && ((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 6;

                    if ( ((((P8 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P8 != (((0 + 1) - 1) % 2))) && ((P8 != (((0 + 1) - 1) % 2)) && ((P8 != ((((0 + 1) + 1) - 1) % 2)) && (P8 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && !((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 7;

                    if ( ((((P9 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }

          continue;
        }
        if (q == 4){
                if(__VERIFIER_nondet_int()){

                  if ( !((P1 % 2) != (0 % 2)) ){

                    method_id = 2;

                    if ( ((((P1 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && !((P1 % 2) != (0 % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( !(P1 != (((0 + 1) - 1) % 2)) ){

                    method_id = 3;

                    if ( (((P3 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && !(P3 != (((0 + 1) - 1) % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && (((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 4;

                    if ( (((((P4 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P4 % 2) != (0 % 2))) && (((P4 % 2) != (0 % 2)) && (((P4 % 2) != ((0 + 1) % 2)) && ((P4 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && !(((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 5;

                    if ( ((((((P6 % 2) != (this_expect % 2)) && (this_buffer_empty == 1)) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2))))) || (((this_buffer_empty != 1) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2)))))) ) {
                      goto ERROR;
                    }

                    q = 5;

                    this_expect=(this_expect + 1); this_buffer_empty=(1 - this_buffer_empty);
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && ((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 6;

                    if ( ((((P8 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P8 != (((0 + 1) - 1) % 2))) && ((P8 != (((0 + 1) - 1) % 2)) && ((P8 != ((((0 + 1) + 1) - 1) % 2)) && (P8 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && !((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 7;

                    if ( ((((P9 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }

          continue;
        }
        if (q == 5){
                if(__VERIFIER_nondet_int()){

                  if ( !((P1 % 2) != (0 % 2)) ){

                    method_id = 2;

                    if ( ((((P1 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && !((P1 % 2) != (0 % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( !(P1 != (((0 + 1) - 1) % 2)) ){

                    method_id = 3;

                    if ( (((P3 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && !(P3 != (((0 + 1) - 1) % 2))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && (((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 4;

                    if ( (((((P4 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P4 % 2) != (0 % 2))) && (((P4 % 2) != (0 % 2)) && (((P4 % 2) != ((0 + 1) % 2)) && ((P4 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( (((P1 % 2) != (0 % 2)) && !(((P1 % 2) != ((0 + 1) % 2)) && ((P1 % 2) != (0 % 2)))) ){

                    method_id = 5;

                    if ( (((((P6 % 2) == (this_expect % 2)) && (this_buffer_empty == 1)) && ((P6 % 2) != (0 % 2))) && (((P6 % 2) != (0 % 2)) && !(((P6 % 2) != ((0 + 1) % 2)) && ((P6 % 2) != (0 % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && ((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 6;

                    if ( ((((P8 == ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P8 != (((0 + 1) - 1) % 2))) && ((P8 != (((0 + 1) - 1) % 2)) && ((P8 != ((((0 + 1) + 1) - 1) % 2)) && (P8 != (((0 + 1) - 1) % 2))))) ) {
                      goto ERROR;
                    }

                    q = 2;

                    break;
                  }
                  continue;
                }
                if(__VERIFIER_nondet_int()){

                  if ( ((P1 != (((0 + 1) - 1) % 2)) && !((P1 != ((((0 + 1) + 1) - 1) % 2)) && (P1 != (((0 + 1) - 1) % 2)))) ){

                    method_id = 7;

                    if ( ((((this_buffer_empty == 1) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2))))) || ((((P9 != ((this_expect - 1) % 2)) && (this_buffer_empty != 1)) && (P9 != (((0 + 1) - 1) % 2))) && ((P9 != (((0 + 1) - 1) % 2)) && !((P9 != ((((0 + 1) + 1) - 1) % 2)) && (P9 != (((0 + 1) - 1) % 2)))))) ) {
                      goto ERROR;
                    }

                    q = 1;

                    this_expect=this_expect; this_buffer_empty=(1 - this_buffer_empty);
                  }
                  continue;
                }

          continue;
        }


  }

  return 0;

 ERROR: {reach_error();abort();}
}
