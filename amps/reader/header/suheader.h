/*
 * Header: suheader.h
 *
 * Arquivo de header definindo o tipo <trace_t>.
 */

#ifndef _SUHD_HEADER_H
#define _SUHD_HEADER_H 1

#define SIZEOF_SEGYHDR    240

#ifndef SU_NFLTS
#define SU_NFLTS        32768

/*void null_su_header( trace_t* header );*/
#endif

/*
 * Typedef: trace_t
 *
 * Tra�o s�smico.
 *
 * O tipo trace_t difere do segy do SU apenas pelo fato das amostras
 * serem armazenadas em um vetor alocado dinamicamente. Dessa forma
 * uma vari�vel do tipo trace_t necessita explicitamente ser
 * inicializada como um c�digo do tipo
 * (start code)
 * trace_t tr;
 * tr.data = (float *) malloc( ns * sizeof(float) );
 * (end)
 */


typedef struct {

	int tracl;
	int tracr;
	int fldr;
	int tracf;
	int ep;
	int cdp;
	int cdpt;
	short trid;
	short nvs;
	short nhs;
	short duse;
	int offset;
	int gelev;
	int selev;
	int sdepth;
	int gdel;
	int sdel;
	int swdep;
	int gwdep;
	short scalel;
	short scalco;
	int  sx;
	int  sy;
	int  gx;
	int  gy;

	short counit;
	short wevel;
	short swevel;
	short sut;
	short gut;
	short sstat;
	short gstat;
	short tstat;
	short laga;
	short lagb;
	short delrt;
	short muts;
	short mute;
	unsigned short ns;
	unsigned short dt;
	short gain;
	short igc;
	short igi;
	short corr;
	short sfs;
	short sfe;
	short slen;
	short styp;
	short stas;
	short stae;
	short tatyp;
	short afilf;
	short afils;
	short nofilf;
	short nofils;
	short lcf;
	short hcf;
	short lcs;
	short hcs;
	short year;
	short day;
	short hour;
	short minute;
	short sec;
	short timbas;
	short trwf;
	short grnors;
	short grnofr;
	short grnlof;
	short gaps;
	short otrav;
	float d1;
	float f1;
	float d2;
	float f2;
	float ungpow;
	float unscale;
	int ntr;
	short mark;
        short shortpad;
	short unass[14];
        float* data;

} trace_t;

void null_su_header( trace_t* header );

#endif
