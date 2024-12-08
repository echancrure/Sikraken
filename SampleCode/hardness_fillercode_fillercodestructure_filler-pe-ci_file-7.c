// This file is part of the SV-Benchmarks collection of verification tasks:
// https://gitlab.com/sosy-lab/benchmarking/sv-benchmarks
//
// SPDX-FileCopyrightText: 2022 Jana (Philipp) Berger
//
// SPDX-License-Identifier: GPL-3.0-or-later

// Prototype declarations of the functions used to communicate with the model checkers
extern unsigned long __VERIFIER_nondet_ulong();
extern long __VERIFIER_nondet_long();
extern unsigned char __VERIFIER_nondet_uchar();
extern char __VERIFIER_nondet_char();
extern unsigned short __VERIFIER_nondet_ushort();
extern short __VERIFIER_nondet_short();
extern float __VERIFIER_nondet_float();
extern double __VERIFIER_nondet_double();

extern void abort(void);
extern void __assert_fail(const char *, const char *, unsigned int, const char *) __attribute__ ((__nothrow__ , __leaf__)) __attribute__ ((__noreturn__));
void reach_error() { __assert_fail("0", "Req1_Prop1_Batch7Filler_PE_CI.c", 13, "reach_error"); }
void __VERIFIER_assert(int cond) { if(!(cond)) { ERROR: {reach_error();abort();} } return; }
void assume_abort_if_not(int cond) { if(!cond) { abort(); } }



#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#define abs(a) (((a) < 0 ) ? -(a) : (a))





// Function prototypes


// Internal control logic variables
unsigned char isInitial = 0;

// Signal variables
unsigned short int var_1_1 = 32;
float var_1_2 = 200.875;
float var_1_3 = 100.25;
float var_1_4 = 99999999.34;
unsigned short int var_1_5 = 10;
unsigned short int var_1_6 = 8;
unsigned long int var_1_7 = 25;
unsigned char var_1_8 = 0;
signed long int var_1_9 = -16;
unsigned short int var_1_10 = 25;
unsigned short int var_1_11 = 10000;
signed short int var_1_12 = -32;
signed char var_1_13 = 4;
signed char var_1_14 = 25;
signed short int var_1_15 = -16;
signed short int var_1_16 = 100;
signed short int var_1_17 = 8;
float var_1_18 = 5.8;
float var_1_19 = 0.19999999999999996;
float var_1_20 = 1.5;
float var_1_21 = 10000000.5;
float var_1_22 = 4.5;
float var_1_23 = 4.25;
signed short int var_1_24 = -16;
unsigned short int var_1_25 = 100;
unsigned long int var_1_27 = 8;
signed long int var_1_34 = 8;
unsigned char var_1_36 = 0;
unsigned char var_1_37 = 0;
unsigned char var_1_38 = 1;
float var_1_39 = 10000000000000.5;
float var_1_43 = 0.0;
float var_1_44 = 0.4;
signed long int var_1_45 = -128;
signed short int var_1_46 = 2;

// Calibration values

// Last'ed variables

// Additional functions


void initially(void) {
}



void step(void) {
	// From: Req3Batch7Filler_PE_CI
	var_1_9 = (max (var_1_5 , var_1_6));


	// From: Req4Batch7Filler_PE_CI
	signed long int stepLocal_1 = 56016 - var_1_11;
	signed long int stepLocal_0 = 10;
	if (var_1_6 < stepLocal_0) {
		if (var_1_5 < stepLocal_1) {
			var_1_10 = var_1_5;
		}
	}


	// From: Req5Batch7Filler_PE_CI
	if ((var_1_13 - var_1_14) > (var_1_10 + var_1_11)) {
		if (! var_1_8) {
			var_1_12 = var_1_13;
		}
	} else {
		var_1_12 = var_1_14;
	}


	// From: Req6Batch7Filler_PE_CI
	var_1_15 = (var_1_14 - (max ((var_1_16 + var_1_17) , 4)));


	// From: Req7Batch7Filler_PE_CI
	if (var_1_4 > var_1_2) {
		var_1_18 = ((abs (var_1_19 + var_1_20)) - var_1_21);
	} else {
		if (! ((var_1_17 - var_1_11) < 128)) {
			var_1_18 = (abs (var_1_21));
		} else {
			var_1_18 = (min ((max (9.75f , var_1_19)) , (max ((var_1_21 - var_1_22) , (max (var_1_20 , var_1_23))))));
		}
	}


	// From: Req8Batch7Filler_PE_CI
	var_1_24 = 16;


	// From: Req1Batch7Filler_PE_CI
	if (var_1_18 <= (var_1_3 - var_1_4)) {
		var_1_1 = var_1_5;
	} else {
		var_1_1 = (max (var_1_5 , var_1_6));
	}


	// From: Req2Batch7Filler_PE_CI
	if (var_1_8) {
		if (var_1_5 < 16) {
			var_1_7 = (var_1_6 + var_1_24);
		}
	}


	// From: CodeObject1
	if ((var_1_5 >> var_1_27) > ((var_1_10 ^ var_1_14) + (abs (var_1_16)))) {
		var_1_25 = (max ((abs (var_1_27)) , 0));
	} else {
		if ((abs (var_1_18)) >= (var_1_4 - var_1_3)) {
			var_1_25 = var_1_27;
		}
	}


	// From: CodeObject2
	if (var_1_16 >= (abs (var_1_5 | var_1_27))) {
		var_1_34 = ((max ((abs (var_1_11)) , var_1_16)) - (abs (var_1_14)));
	} else {
		if (var_1_11 >= var_1_27) {
			if (var_1_3 > var_1_3) {
				var_1_34 = (abs (var_1_14));
			}
		}
	}


	// From: CodeObject3
	if ((-10 & var_1_5) <= var_1_6) {
		if (var_1_4 != var_1_4) {
			var_1_36 = var_1_37;
		}
	}


	// From: CodeObject4
	var_1_38 = var_1_37;


	// From: CodeObject5
	if (var_1_27 == (var_1_6 ^ var_1_17)) {
		var_1_39 = ((min (var_1_22 , (min (var_1_22 , var_1_21)))) - (var_1_43 - var_1_44));
	} else {
		var_1_39 = ((min ((abs (var_1_21)) , var_1_43)) - 255.4f);
	}


	// From: CodeObject6
	var_1_45 = var_1_27;


	// From: CodeObject7
	var_1_46 = var_1_27;
}



void updateVariables() {
	var_1_2 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_2 >= -922337.2036854776000e+13F && var_1_2 <= -1.0e-20F) || (var_1_2 <= 9223372.036854776000e+12F && var_1_2 >= 1.0e-20F ));
	var_1_3 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_3 >= 0.0F && var_1_3 <= -1.0e-20F) || (var_1_3 <= 9223372.036854776000e+12F && var_1_3 >= 1.0e-20F ));
	var_1_4 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_4 >= 0.0F && var_1_4 <= -1.0e-20F) || (var_1_4 <= 9223372.036854776000e+12F && var_1_4 >= 1.0e-20F ));
	var_1_5 = __VERIFIER_nondet_ushort();
	assume_abort_if_not(var_1_5 >= 0);
	assume_abort_if_not(var_1_5 <= 65534);
	var_1_6 = __VERIFIER_nondet_ushort();
	assume_abort_if_not(var_1_6 >= 0);
	assume_abort_if_not(var_1_6 <= 65534);
	var_1_8 = __VERIFIER_nondet_uchar();
	assume_abort_if_not(var_1_8 >= 0);
	assume_abort_if_not(var_1_8 <= 1);
	var_1_11 = __VERIFIER_nondet_ushort();
	assume_abort_if_not(var_1_11 >= 0);
	assume_abort_if_not(var_1_11 <= 32767);
	var_1_13 = __VERIFIER_nondet_char();
	assume_abort_if_not(var_1_13 >= -1);
	assume_abort_if_not(var_1_13 <= 127);
	var_1_14 = __VERIFIER_nondet_char();
	assume_abort_if_not(var_1_14 >= 0);
	assume_abort_if_not(var_1_14 <= 127);
	var_1_16 = __VERIFIER_nondet_short();
	assume_abort_if_not(var_1_16 >= 0);
	assume_abort_if_not(var_1_16 <= 16383);
	var_1_17 = __VERIFIER_nondet_short();
	assume_abort_if_not(var_1_17 >= 0);
	assume_abort_if_not(var_1_17 <= 16383);
	var_1_19 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_19 >= -461168.6018427382800e+13F && var_1_19 <= -1.0e-20F) || (var_1_19 <= 4611686.018427382800e+12F && var_1_19 >= 1.0e-20F ));
	var_1_20 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_20 >= -461168.6018427382800e+13F && var_1_20 <= -1.0e-20F) || (var_1_20 <= 4611686.018427382800e+12F && var_1_20 >= 1.0e-20F ));
	var_1_21 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_21 >= 0.0F && var_1_21 <= -1.0e-20F) || (var_1_21 <= 9223372.036854765600e+12F && var_1_21 >= 1.0e-20F ));
	var_1_22 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_22 >= 0.0F && var_1_22 <= -1.0e-20F) || (var_1_22 <= 9223372.036854765600e+12F && var_1_22 >= 1.0e-20F ));
	var_1_23 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_23 >= -922337.2036854765600e+13F && var_1_23 <= -1.0e-20F) || (var_1_23 <= 9223372.036854765600e+12F && var_1_23 >= 1.0e-20F ));
	var_1_27 = __VERIFIER_nondet_ulong();
	assume_abort_if_not(var_1_27 >= 0);
	assume_abort_if_not(var_1_27 <= 17);
	var_1_37 = __VERIFIER_nondet_uchar();
	assume_abort_if_not(var_1_37 >= 0);
	assume_abort_if_not(var_1_37 <= 0);
	var_1_43 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_43 >= 4611686.018427382800e+12F && var_1_43 <= -1.0e-20F) || (var_1_43 <= 9223372.036854765600e+12F && var_1_43 >= 1.0e-20F ));
	var_1_44 = __VERIFIER_nondet_float();
	assume_abort_if_not((var_1_44 >= 0.0F && var_1_44 <= -1.0e-20F) || (var_1_44 <= 4611686.018427382800e+12F && var_1_44 >= 1.0e-20F ));
}



void updateLastVariables() {
}

int property() {
	return ((((((((var_1_18 <= (var_1_3 - var_1_4)) ? (var_1_1 == ((unsigned short int) var_1_5)) : (var_1_1 == ((unsigned short int) (max (var_1_5 , var_1_6))))) && (var_1_8 ? ((var_1_5 < 16) ? (var_1_7 == ((unsigned long int) (var_1_6 + var_1_24))) : 1) : 1)) && (var_1_9 == ((signed long int) (max (var_1_5 , var_1_6))))) && ((var_1_6 < 10) ? ((var_1_5 < (56016 - var_1_11)) ? (var_1_10 == ((unsigned short int) var_1_5)) : 1) : 1)) && (((var_1_13 - var_1_14) > (var_1_10 + var_1_11)) ? ((! var_1_8) ? (var_1_12 == ((signed short int) var_1_13)) : 1) : (var_1_12 == ((signed short int) var_1_14)))) && (var_1_15 == ((signed short int) (var_1_14 - (max ((var_1_16 + var_1_17) , 4)))))) && ((var_1_4 > var_1_2) ? (var_1_18 == ((float) ((abs (var_1_19 + var_1_20)) - var_1_21))) : ((! ((var_1_17 - var_1_11) < 128)) ? (var_1_18 == ((float) (abs (var_1_21)))) : (var_1_18 == ((float) (min ((max (9.75f , var_1_19)) , (max ((var_1_21 - var_1_22) , (max (var_1_20 , var_1_23))))))))))) && (var_1_24 == ((signed short int) 16))
;
}
int main(void) {
	isInitial = 1;
	initially();

	while (1) {
		updateLastVariables();

		updateVariables();
		step();
		__VERIFIER_assert(property());
		isInitial = 0;
	}

	return 0;
}
