/* Generated by            cobc 1.1.0 */
/* Generated from          hello.cob */
/* Generated at            Mar 09 2022 22:44:04 EST */
/* OpenCOBOL build date    Mar 09 2022 22:21:43 */
/* OpenCOBOL package date  Feb 06 2009 10:30:55 CET */
/* Compile command         cobc -free -C hello.cob */

/* Frame stack declaration */
struct cob_frame {
	int	perform_through;
	void	*return_address;
};

/* Union for CALL statement */
union cob_call_union {
	void *(*funcptr)();
	int  (*funcint)();
	void *func_void;
};
union cob_call_union	cob_unifunc;


/* Storage */

/* PROGRAM-ID : TEST-PROGRAM */
static unsigned char b_1[4] __attribute__((aligned));	/* RETURN-CODE */

/* End of storage */


/* Attributes */

static const cob_field_attr a_1 = {33, 0, 0, 0, NULL};
/* Constants */
static cob_field c_1	= {5, (unsigned char *)"Ciao!", &a_1};
