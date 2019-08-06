#ifndef __EMV_INTERFACE__
#define __EMV_INTERFACE__

#include "define.h"
#include "pub/pub.h"
#include "ex_crypto.h"
//#include "pub_define.h"

#ifdef __cplusplus
extern "C"{
#endif

	//#pragma pack(1)

	/**< ---------------------------------------------------------------------------------------------------*/
	/*ͨ�ú궨��*/
	#define OFFLINE_PIN_NOMAL		0x03	/**<��ʾ�����ѻ�PIN*/
	#define OFFLINE_PIN_AGAIN		0x02	/**<��ʾ�ٴ������ѻ�PIN*/
	#define OFFLINE_PIN_LAST		0x01	/**<���һ�������ѻ�PIN*/
	#define	ONLINE_PIN			0x00

	#define MAXLEN_AID 			16
	#define MAXLEN_DOL 			(252 + 4) 
	#define MAXLEN_MODULUS 		248
#ifdef WIN32
	#define MAXLEN_FILENAME		256
#else
	#define MAXLEN_FILENAME		32
#endif
	/**< ---------------------------------------------------------------------------------------------------*/



	/**< ---------------------------------------------------------------------------------------------------*/
	/**< ICS����*/
	/**< ICS�ṹcKernelS�ں����Ͳ���*/
	#define KERNEL_QPBOC		0x01		/*QPBOC*/
	#define KERNEL_QUICS		0x02		//QUICS
	#define KERNEL_DISCOVER		0x04		
	#define KERNEL_VISA			0x08		
	#define KERNEL_MASTER		0x10		
	#define KERNEL_JCB 			0x20		
	#define KERNEL_AMEX			0x40		
	#define KERNEL_RUPAY		0x80		
	/**< ICS�ṹcPackType������Ͳ���*/
	#define EMV_PACK_ONLINE (1)
	#define EMV_PACK_BATCH	(2)
	typedef struct{
		/**<Ӧ��ѡ��*/
		YESORNO bPSE;				/**<֧��PSEӦ��ѡ�񷽷�*/
		YESORNO bCardHConfirm;		/**<֧�ֳֿ���ȷ��*/
		YESORNO bPriorDisp;			/**<���Զ����������ʾ˳��*/
		YESORNO bPaticalMatch;		/**<֧��AID����ƥ��*/
		YESORNO bMultiLangu;		/**<֧�ֶ�����*/
		YESORNO bPubChar;			/**<֧�ֹ����ַ���*/	
		/**<��ѡ�ں�����*/
		YESORNO bConfigureKenal;	/**<֧�ֿ�ѡ�ں�����*/
		char cAmtStandard;			/**<���ѡ���׼(CVM�б�)*/		
		/**<������֤*/
		int nCAPKMAXLen;			/**<CAPK��󳤶�*/
		char cCAPKExpoMode;		/**<֧�ֵĹ�Կָ��*/
		YESORNO bCheckTCRecycle;	/**<��鷢���й�Կ֤��Ļ���*/
		/**<���ո�ʽ?*/
		YESORNO bDDOL;				/**<����Ĭ��DDOL*/
		YESORNO bOperAct;			/**<CA��Կװ��ʧ��ʱ����Ա��Ϊ�Ƿ�Ҫ��*/
		YESORNO bCheckSum;		/**<CA��ԿУ��ͨ��У���*/
		/**<�����ͨ��CA��ԿУ���У��,ʹ�õ�У�鷽��*/
		/**<�ֿ�����֤*/
		YESORNO bByPassPin;			/**<֧���ƹ�pin����*/
		/**<��ѡ���ƹ�pin����,��������pin���뷽���Ƿ�Ҳ����Ϊ���ƹ�*/
		YESORNO bGetPinTime;				/**<GET DATA ȡPIN���Դ���*/
		YESORNO bCVMFail;			/**<֧��CVMʧ��*/
		YESORNO bAMTBeforeCVM;	/**<CVM����ǰ�Ƿ�֪�����*/
		/**<�ն˷��չ���*/
		YESORNO bFloorLimit;			/**<����޶���*/
		YESORNO bRanSel;			/**<�������ѡ��*/
		YESORNO bVelocityCheck;		/**<Ƶ�ȼ��*/
		YESORNO bTransLog;			/**<������־*/
		YESORNO bExceptionFile;		/**<�쳣�ļ�*/
		YESORNO bBaseAIP;			/**<���չ����Ƿ����AIP*/
		/**<�ն���Ϊ����*/
		YESORNO bTA;				/**<֧���ն���Ϊ����*/
		YESORNO bTAEmpty;			/**<�ն���Ϊ�����Ƿ�Ϊ��*/
		/**<���ѻ��������ն�֧��*/
		YESORNO bDACBefoer1stGAC;	/**<�Ƿ�ȱʡ��Ϊ�����ڵ�һ��Genarate AC֮ǰ*/
		YESORNO bDACAfter1stGAC;	/**<�Ƿ�ȱʡ��Ϊ�����ڵ�һ��Genarate AC֮��*/	
		/**<�������������ն�֧��*/
		YESORNO bNoDACtoAAC;		/**<����������ʱ�Ƿ�����ȱʡ��Ϊ����,ֱ������AAC*/
		YESORNO bDetectCDAFailBeforeTAA;/**<�ն���Ϊ����ǰ�Ƿ�������̽�⵽CDAʧ��*/
		/**<֧��CDA���ն�*/
		YESORNO bCDA1stGACforARQC;	/**<�ڵ�һ��GAC����ARQCʱ�Ƿ�����CDA*/
		YESORNO bCDA2ndGACforTC;	/**<�ڵڶ���GAC����TCʱ�Ƿ�����CDA*/
		/**<��ɴ���*/
		YESORNO bForceOnline;		/**<����ǿ����������*/
		YESORNO bForceAccept;		/**<����ǿ�ƽ�������*/
		YESORNO bAdvices;			/**<֧��֪ͨ*/
		YESORNO bIISVoiceRef;		/**<֧�ַ����з�������Բο�*/
		YESORNO bBatchData;			/**<֧�������ݻ�ȡ*/
		YESORNO bOnlineData;		/**<�ն��Ƿ�֧���������ݻ�ȡ*/
		YESORNO bDefaultTDOL;		/**<�Ƿ�֧��һ��ȱʡ��TDOL*/
		/**<�쳣����*/
		char szFallBackEntryModo[2];	/**<���IC���ܶ�ȡ,��ת����������ʱ��POS����ģʽ*/
		/**<����*/
		YESORNO bPinPad;			/**<�ն��Ƿ�����������*/
		YESORNO bAMTPinSameKeypad;/**<����pin�Ƿ���ͬһ����������*/
		YESORNO bCombinedReader;	/**<�Ƿ�ΪIC�������϶�����(����)*/
		YESORNO bSelAccount;		/**<�Ƿ�֧���˻�����ѡ��*/
		YESORNO bISSScriptGreater128;/**<�����нű�����128�ֽ�*/
		int nIssScriptMaxLen;			/**<�����нű�����󳤶�(���ֶ��ڽű����ȴ���128�ֽ�Ϊ��ʱ��Ч)*/
		YESORNO bReadDetail;		/**<�Ƿ��������ϸ(��PBOC ICS�и�ѡ��)*/
		YESORNO bInteralDataMana;	/**<֧���ڲ����ڹ���*/
		char cKernelS;				/**<(TERM)������Ŀ*/
		char cIsApprove;			/**<��֤����>**/
		char cPackType;				/**<(TERM)��������*/
		/**< SM�㷨*/
		YESORNO bSm;
		YESORNO bOda;
		YESORNO bASRPD;				//Application Selection Registered Proprietary DataӦ��ѡ��ע��ר������
		/**< ��������*/
		YESORNO bDualInterface;
	}STICS;
	/**<����ICS����*/
	LIB_EXPORT extern int Emv_SetICS(STICS stTermIcs);
	LIB_EXPORT extern int Emv_GetICS(STICS *stTermIcs);
	LIB_EXPORT extern int Emv_SetICSRam(STICS *stTermIcs);

	/**< -----------------------------------------------------------------------------------------------------*/




	/**< -----------------------------------------------------------------------------------------------------*/
	/**<�ն˲���*/
	/**<�ն˲���ST_TERMPARA�ṹEntryMode���뷽ʽ����*/
	#define POSENTMODE_MAG		0x02
	#define POSENTMODE_FALLBACK 0x04
	#define POSENTMODE_IC		0x05
	#define POSENTMODE_QPBOC	0x07
	#define POSENTMODE_RF		0x98
	/**<�ն˲���*/
	typedef struct {
		char szAcqID_n_9F01[6];				/**<(TERM)�յ��б�ʶ*/	
		char szAddTermCap_b_9F40[5];		/**<(TERM)�����ն�����*/	
		char szMerCateCode_n_9F15[2];		/**<(TERM)�̻�������*/
		char szMerID_ans_9F16[15];			/**<(TERM)�̻���ʶ*/
		char szMerNameLoc_ans[40];			/**<(TERM)�̻����ƺ�λ��*/
		//char cMessageType_n;				/**<(TERM)�������*/
		char cEntryMode_n_9F39;				/**<(TERM)���۵㣨POS�����뷽ʽ*/
		char szTermCap_b_9F33[3];			/**<(TERM)�ն�����*/
		char szTermCountryCode_b_9F1A[2];	/**<(TERM)�ն˹��Ҵ���*/
		char szTermId_an_9F1C[8];			/**<(TERM)�ն˺�*/
		char cTypeTerm_n_9F35;				/**<(TERM)�ն�����*/
		char szCurCode_n_5F2A[2];			/**<(TERM)���׻��Ҵ���*/
		char cCurExp_n_5F36;				/**<(TERM)���׻���ָ��*/
		char szRefCurrCode_n_9F3C[2];		/**<(TERM)���ײο����Ҵ���*/
		char cRefCurrExp_n_9F3D;			/**<(TERM)���ײο�����ָ��*/
		char szIFD_an_9F1E[8];				/**<(TERM)�ӿ��豸��IFD�����к�*/
		char szTDOL_b[252];					/**<ȱʡ����֤�����ݶ����б�*/
		char cTDOLLen;
		/**< �����ֽ�qPboc����*/
		char cDF19Check;				/**< (EC)�����ֽ�ָʾ��*/
		char szTransProp_9F66[4+1];			/**< (RF TERM) �ն˽�������*/
		char c9F1BCheck;
		char cRfStatusCheck;				/**< (RF TERM) �ǽӴ��ն�״̬���*/
		/**< ���0�Ƿ�֧��*/
		char bZeroAmtAllowed;
	}ST_TERMPARA;
	/**<�����ն˲���*/
	LIB_EXPORT extern int Emv_SetTerminalParam(const ST_TERMPARA *stTermPara);
	LIB_EXPORT extern int Emv_GetTerminalParam(ST_TERMPARA *stTermPara);
	LIB_EXPORT extern int Emv_SetTerminalParamRam(ST_TERMPARA *stTermPara);
	/**< -----------------------------------------------------------------------------------------------------*/





	/**< -----------------------------------------------------------------------------------------------*/
	/**<�ṹ��STEMVPROC����cTransType��������*/
#define EMV_GOODS_SERVICES 		0x00
#define EMV_CASH           		0x01
#define EMV_CASHBACK       		0x09
#define EMV_INQUIRY        		0x31
#define EMV_TRANFER        		0x40
#define EMV_ADMIN          		0x66		/**<?�Զ���*/
#define EMV_CASH_DISBUERSE		0x17		//�ֽ�֧��
#define EMV_CASHDEPOSIT    		0x21
#define VISA_REFUND    			0x20
#define RUPAY_MONEY_ADD			0x28		//Ȧ��
#define RUPAY_VOID				0x34		//����
#define EMV_PAYMENT        		0x50
	/**< ���������н�������*/
#define EMV_SALE				EMV_GOODS_SERVICES	/**< ����*/
#define PBOC_READLOG      		0x0A		/**< PBOC��LOG*/
#define UPLOAD_READLOG      	0x0B		/**< Ȧ���LOG*/
#define EMV_QPBOC_SIMPLE		0x20		/**< qpboc��������*/
#define EMV_SIMPLE_PROC			0x99		/**< ��������*/
#define EMV_PREAUTH				0x03		/**< Ԥ��Ȩ*/
#define PBOC_EC_BALANCE			EMV_INQUIRY		/**< �����ֽ�����ѯ*/
	/**< �����ֽ�*/
#define EC_TRANS				EMV_GOODS_SERVICES
#define EC_INQUIRE				0x67		/**< �����ֽ�����ѯ ?�Զ���*/
#define EC_BINDLOAD				0x60		/*�����ֽ�ָ���˻�Ȧ��*/
#define EC_NOBINDLOAD			0x62		/*�����ֽ��ָ���˻�Ȧ��*/
#define EC_CASHLOAD				0x63		/*�����ֽ��ֽ�Ȧ��*/
#define EC_AMOUNT				0x64
#define EC_UPLOAD				0x65
#define EC_CASHLOAD_VOID		0x17		/*�����ֽ��ֽ�Ȧ�泷��*/

	/*�ṹ��STEMVPROC,RFӦ��ѡ���,���׷�ʽ*/
#define MODE_RF_TYPE_UNKNOW		0x00
#define	MODE_RF_TYPE_PBOC		0x01
#define MODE_RF_TYPE_VCPS		0x02
#define MODE_RF_TYPE_QPBOC		MODE_RF_TYPE_VCPS
#define MODE_RF_TYPE_MSD		0x04
#define MODE_TYPE_EC			0x10		/*�����ֽ���*/
#define	MODE_TYPE_RF			0x20		/*�ǽӴ�*/
#define	MODE_TYPE_DPAS			0x22		/*�ǽӴ�d-pas*/
#define	MODE_TYPE_MS			0x24		/*�ǽӴ�d-pas ms*/
#define	MODE_TYPE_ZIP			0x34		/*�ǽӴ�zip*/
	
/**<�ṹ��STEMVPROC����nEmvRet��ֵ*/
#define EMV_RES_TRY_AGAIN		(-4)		/**< �����»ӿ�*/
#define EMV_RES_UNKNOW			(-3)		/**< δ֪���*/
#define EMV_RES_AAR				(-2)		/**< */
#define EMV_RES_REFUSE			(-1)		/**< ���׾ܾ�*/
#define EMV_RES_ACCEPT			(0)			/**< ���׽���*/
#define EMV_RES_REQ_ONLINE		(1)			/**< ��������*/
#define EMV_RES_2GACAAC			(2)			/**< �ڶ���GAC����AAC*/

	/**<�ṹ��STEMVPROC����nOnlineRes��ֵ*/
#define EMV_ONLINE_SUCC			(0)			/**< �����ɹ�*/
#define EMV_ONLINE_FAIL			(-1)		/**< ����ʧ��*/

	/**< STEMVPROC �ṹ��eInputAMT����*/
	typedef enum {
		AMT_NO = 0,				/**< ��������*/
		AMT_BEFORESEL,			/**< Ӧ��ѡ��ǰ������*/
		AMT_AFTERSEL			/**< Ӧ��ѡ���������*/
	}E_INPUTAMT;

	/*	EMV����ѡ��ṹ��*/
	typedef struct {
		unsigned char cTransType;  		/**<��������,in*/
		char cTransMode;		/**<����ģʽout*/
		char *pszEmvData;		/**<EMV����*/
		int nEmvDataLen;		/**<EMV���ݳ���*/
		int nEmvTransSerial;	/**<�������,in*/
		char bForceOnline;		/**<����ǿ������in*/
		E_INPUTAMT eInputAMT;	/**<�Ƿ���Ӧ��ѡ��ǰ������*/
		char szPin[8+1];      	/**<����pin,out*/
		YESORNO bSignatrue;		/**<ǩ��out*/	
		YESORNO bAdvice;		/**<֪ͨout*/
		int nCvmFlag;			/*�ں˷���CVM����*/
		int nEmvRet;			/**<���ؽ��out*/
		int nOnlineRes;			/**<�������in*/
		char *pszField55; 		/**<55������in*/
		int nField55Len;		/**<���ݳ���in*/
		char szResponse[2+1];	/**<��Ȩ��Ӧ��in*/
		char *pszOtherTlvParam;	//��������
		int iOtherTlvParamLen;	
	}STEMVPROC;
	/**< -----------------------------------------------------------------------------------------------*/





	/**< -----------------------------------------------------------------------------------------------*/
	/**<AID�ṹ��,�ṹ�峤��Ϊ400�ֽ�,ĿǰԤ��42�ֽ�*/
	typedef struct {
		char szAID_b_9F06[MAXLEN_AID];		/**<(AID)Ӧ�ñ�ʶAID����(����5-16)*/
		char cAIDLen;						/**<AID����*/							
		char szLable_50[MAXLEN_AID];        /**< Ӧ�ñ�ǩ50(ICC), ans, 1-16 bytes*/
		char cLableLen;						
		char szPreName_9F12[MAXLEN_AID];	/**< Ӧ�������� */
		char cPreNameLen;					
		unsigned char cPriority_87; 		/**< Ӧ������Ȩ��ʶ��*/
		char cASI_b_DF01;					/**<(AID)Ӧ��ѡ��ָʾ��,ָ���ն��Ƿ�֧��AID����ƥ�䷽ʽ0x00:����ƥ�� 0x01��ȫƥ��*/
		char szAppVer_b_9F09[2];			/**<(AID)Ӧ�ð汾��(9F08?9F09?)*/
		char szTACDefault_b_DF11[5];		/**<(AID)�ն���Ϊ���룭Ĭ��*/
		char szTACRefuse_b_DF13[5];			/**<(AID)�ն���Ϊ���룭�ܾ�*/
		char szTACOnline_b_DF12[5];			/**<(AID)�ն���Ϊ���룭����*/
		char szFloorLimit_b_9F1B[4];		/**<(AID)�ն�����޶�*/
		char szRanhold_b_DF15[4];			/**<(AID)ƫ�����ѡ�����ֵ*/
		char cRanMaxPer_b_DF16;				/**<(AID)ƫ�����ѡ������Ŀ��ٷ���*/
		char cRanTarPer_b_DF17;				/**<(AID)���ѡ���Ŀ��ٷ���*/
		char cOnlinePinCap_b_DF18;			/**<(AID)�ն�����pin����*/
		char szDDOL_b_DF14[252];			/**<(AID)ȱʡ��̬������֤���ݶ����б�(�䳤)*/
		char cDDOLLen;						/**< DDOL����*/
		char sEcLimit_9F7B[6];				/**< (EC)�����ֽ��ն˽����޶�*/
#ifdef DPAS
		char cDF19len;
#endif
		char sRf_OfflineLimit_DF19[6];		/**< (RF TERM) �ǽ��ѻ�����޶�*/
#ifdef DPAS
		char cDF20len;
#endif
		char sRF_TxnLimit_DF20[6];			/**< (RF TERM) �ǽӽ����޶�*/
		char sRf_CVMLimit_DF21[6];			/**< (RF TERM) �ǽ�CVM�޶�*/
#ifdef AUTO_APPROVE
		char szCurCode_aid_5F2A[2];			/**<(TERM)���׻��Ҵ���*/
		char c5F36_len;
		char cCurExp_aid_5F36;				/**<(TERM)���׻���ָ��*/
		char c9F3C_len;				 
		char szRefCurrCode_aid_9F3C[2];		/**<(TERM)���ײο����Ҵ���*/
		char c9F3D_len;
		char cRefCurrExp_aid_9F3D;			/**<(TERM)���ײο�����ָ��*/
		char c9F1D_len;
		char cRiskManage_aid_9F1D;			/**<(TERM)�ն˷��չ�������*/
		char c9F01len;
		char szAcqID_n_9F01[6];				/**<(TERM)�յ��б�ʶ*/
		char c9F15len;
		char szMerCateCode_n_9F15[2];		/**<(TERM)�̻�������*/
		char c9F16len;
		char szMerID_ans_9F16[15];			/**<(TERM)�̻���ʶ*/
		char c9F4Elen;
		char szMerNameLoc_ans_9F4E[40];		/**<(TERM)�̻����ƺ�λ��*/
		char c9F1Clen;
		char szTermId_an_9F1C[8];			/**<(TERM)�ն˺�*/
		char cTDOLLen;
		char szTDOL_b[50];					/**<ȱʡ����֤�����ݶ����б���Ӧ DF8102*/
		//Transaction Reference Currency Conversion �ο�����ת������ DF8101�ݲ����棬Ŀǰδ�õ�
		char cResv[15];	
#else
		char szCurCode_aid_5F2A[2];			/**<(TERM)���׻��Ҵ���*/
		char c5F36_len;
		char cCurExp_aid_5F36;				/**<(TERM)���׻���ָ��*/
		char c9F3C_len;				 
		char szRefCurrCode_aid_9F3C[2];		/**<(TERM)���ײο����Ҵ���*/
		char c9F3D_len;
		char cRefCurrExp_aid_9F3D;			/**<(TERM)���ײο�����ָ��*/
		char c9F1D_len;
		char cRiskManage_aid_9F1D;			/**<(TERM)�ն˷��չ�������*/
#ifdef DPAS
		char cResv[29];		
#else
		char cResv[31+111];	
#endif
#endif
	}ST_TERMAID;

#define TERMAID_SIZE	(sizeof(ST_TERMAID))

	typedef struct{
		int adicount;//aid��
		char* st_aidlist;//aid��������
		int matchi[10];//ƥ������
		int nmatch;//ƥ�����
		int nindex;//����ѡ��AID
	}ST_TERMAID_LIST;
	LIB_EXPORT int read_aid_list(ST_TERMAID_LIST *stadilist);
	LIB_EXPORT void FreeAidList();
	LIB_EXPORT ST_TERMAID_LIST * get_aid_list(void);
	/**<AID�ӿ�*/
	LIB_EXPORT extern int Init_AID(void);
	LIB_EXPORT extern int EMV_GetAid(const char *pszAID, int nLen, ST_TERMAID *stAID,int *nRecNum);
	LIB_EXPORT extern int Emv_AddAID(ST_TERMAID *stAID,YESORNO cCoverFlag);
	LIB_EXPORT extern void Emv_GetAIDNum(int *nNum);
	LIB_EXPORT extern int EMV_GetAidByIndex(ST_TERMAID *stAID,int nRecNum);
	LIB_EXPORT extern int Emv_DelAID(const char *pszAID, int nLen);
	/**< -----------------------------------------------------------------------------------------------*/




	/**< -----------------------------------------------------------------------------------------------*/
	/**<��Կ����CAPK�ṹ��,�ṹ�峤��Ϊ228�ֽ�*/
	typedef struct {
		char szRID_b_9F06[5];				/**<ע���Ӧ���ṩ�߱�ʶ*/
		char cCAPKIndex_b_9F22;				/**<(CAPK)��֤���Ĺ�Կ����*/
		char szCAPKExpire_n_DF05[4];		/**<(CAPK)��֤���Ĺ�Կ��Ч��*/
		char cCAPKHashFlag_b_DF06;			/**<(CAPK)��֤���Ĺ�Կ��ϣ�㷨��ʶ*/
		char cCAPKFlag_b_DF07;				/**<(CAPK)��֤���Ĺ�Կ�㷨��ʶ*/
		char szCAPKMod_b_DF02[MAXLEN_MODULUS];/**<(CAPK)��֤����ģ(���Ϊ248)*/
		uchar cCAPKModLen;					/**<��Կģ��*/
		char szCAPKExponent_b_DF04[3];		/**<(CAPK)��֤���Ĺ�Կָ��(����1��3)*/
		uchar cCapkExpLen;
		char szCAPKCheckSum_b_DF03[20];		/**<(CAPK)��֤���Ĺ�ԿУ���(�䳤)*/
		char cCheckSumLen;	
#if AUTO_APPROVE
		char szCAPKCaindex_DF08[3];			/*��֤���Ĺ�Կ���к�*/
		char cDf08_len;
#endif
	}ST_CAPK;
	/**<��Կ����CAPK�ӿ�*/
	LIB_EXPORT extern int Init_CAPK(void);
	LIB_EXPORT extern int EMV_GetCAPK(const char *pszRID, char *cIndex,ST_CAPK *stCAPK,int *nRecNum);
	LIB_EXPORT extern int Emv_AddCAPK(ST_CAPK*stCAPK,YESORNO cCoverFlag);
	LIB_EXPORT extern void Emv_GetCAPKNum(int *nNum);
	LIB_EXPORT extern int EMV_GetCAPKByIndex(ST_CAPK *stCapk,int nRecNum);
	LIB_EXPORT extern int Emv_DelCAPK(const char *pszRID, int nLen, char *cCAPKIndex);
	LIB_EXPORT extern int VerifyCAPK(const ST_CAPK *stCAPK);
	/**< -----------------------------------------------------------------------------------------------*/





	/**< -----------------------------------------------------------------------------------------------*/
	/**< �ļ��洢·��*/
	typedef struct {
		char szFile_Terminal[MAXLEN_FILENAME];			/*�ն˲����ļ���*/
		char szFile_Ics[MAXLEN_FILENAME];				/**<ICS�ļ���*/
		char szFile_CAPK[MAXLEN_FILENAME];				/*��Կ�ļ���*/
		char szFile_AID[MAXLEN_FILENAME];				/*AID�ļ���*/
		char szFile_Card_BlackList[MAXLEN_FILENAME];	/*���������ļ���*/
		char szFile_Cert_BlackList[MAXLEN_FILENAME];	/*֤��������ļ���*/
		char szFile_Log[MAXLEN_FILENAME];				/*LOG�ļ���*/
		char szFile_RfFail[MAXLEN_FILENAME];			/*������¼�ļ�*/
		char szFile_BinA[MAXLEN_FILENAME];				/*BIN A�б�*/
		char szFile_BinB[MAXLEN_FILENAME];				/*BIN B�б�*/
		char szFile_BinC[MAXLEN_FILENAME];				/*���ܿ�BIN C�к�����*/
	}STEMV_FILE;
	/**< �����ļ��洢·��*/
	LIB_EXPORT extern int EMV_SetFileName(STEMV_FILE *stEmvFileName);
	/**< -----------------------------------------------------------------------------------------------*/


	/**< -----------------------------------------------------------------------------------------------*/
	/**<���������ṹ*/
	typedef struct
	{
		char cLen;			/**<���ų���*/
		char szCardNo[10];	/**<����*/
		char cIndex;		/**<����*/
		char cResv;
	}STBlackCard;
	typedef struct{
		int blkcount;//aid��
		char* st_blklist;//aid��������
	}ST_BLC_LIST;
	/**<���������ӿ�*/
	LIB_EXPORT extern int Init_CardBL(void);
	LIB_EXPORT extern int EMV_FindCardBL(STBlackCard stBlackCard,int ntype);//ntypeΪ0��ʾ�洢�ж� ����Ϊ�������ж�
	LIB_EXPORT extern int Emv_AddCardBL(STBlackCard stBlackCard,YESORNO cCoverFlag);
	LIB_EXPORT extern int Emv_DelCardBL(STBlackCard stBlackCard);
	/**< --------------------------------------------------------------------------------------------------*/





	/**< --------------------------------------------------------------------------------------------------*/
	/**<������֤��������ṹ��*/
	typedef struct
	{
		char szRID[5];		
		char cIndex;			/**<��Կ����*/
		char szSerialNum[3];	/**<֤�����*/
		char cResv;
	}STBlackCert;
	/**<֤�����������*/
	LIB_EXPORT extern int Init_CertBL(void);
	LIB_EXPORT extern int EMV_FindCertBL(STBlackCert stBlackCert);
	LIB_EXPORT extern int Emv_AddCertBL(STBlackCert stBlackCert,YESORNO cCoverFlag);
	LIB_EXPORT extern int Emv_DelCertBL(STBlackCert stBlackCert);
	/**< ---------------------------------------------------------------------------------------------------*/




	/**< ---------------------------------------------------------------------------------------------------*/
	/**<���׽��溯��ָ��*/
	/*	AID��ѡ�б��ṹ��,���к�ѡ�б�ѡ��ʱ�õ�,�μ�ADFĿ¼��ڸ�ʽ*/
	typedef struct {
		unsigned char szAID_4F[16+1];			/**<AID	Ӧ�ñ�ʶ��*/
		int nAIDLen;							
		unsigned char szLable_50[16+1];         /**< Ӧ�ñ�ǩ50(ICC), ans, 1-16 bytes*/
		int nLableLen;						
		unsigned char szPreName_9F12[16+1];		/**< Ӧ�������� */
		int nPreNameLen;					
		unsigned char cPriority_87; 		    /**< Ӧ������Ȩ��ʶ��*/
		int  nIndex;							/**<���ն�AID�б��е�����*/
		int nKernelId;							//KernelId
		uchar ucExtendSelect[11+1];				//��չӦ��ѡ��
		int nExtendSelectLen;					//���11�ֽ�
		unsigned char szResv[3];				/**<*/
	}ST_ICCAID;

	typedef struct {
		int (*InputAmount)(char *,char);													/**<��������溯��ָ��*/
		int (*InputOfflinePin)( XM_RSA_PUBLIC_KEY *pk, int nMethod,char cMsgType,char *sw);	/**<����������溯��ָ��*/	
		int (*InputOnlinePin)(char *,char *);												/*����������溯��ָ��*/	
		int (*SelectApp)(ST_ICCAID stICCAID[],int nAIDNum,int *nChoice);					/**<Ӧ��ѡ����溯��ָ��*/
		int (*SelectAccount)(int *nChoice);													/**<�˻�����ѡ����溯��ָ��*/
		int (*ConfirmCert)(char *pszCertNO,char cCertType);
		int (*DispCard)(char *);															/**<��ʾ���ź���ָ��*/
		int (*DispWarn)(char *,...);														/**<��ʾ������溯��ָ��*/
		void (*DispMesg)(char *,...);
		int (*IssVoiceRef)(char *);															/**<�����������ο�*/
		int (*SelectEC)(void);																/**< �Ƿ�ʹ�õ����ֽ�*/
		int (*RfGetCard)(int);																/**< �ǽӴ�������ʾ�û��ÿ�*/
		int (*CardStatus)(void);
		int (*InputPin)(char *psCardNo,char *psAmt,char cMsgType,char *psPin);
		int (*GetOnlinePin)(char *psCardNo,char *psAmt,char *psCiphertext);
		int (*GetAmount)(char *);
		int (*Beep)(int nMillisecond);
		int (*ShankaDel)(int);
		int (*SelectLan)(char *);					/**<����ѡ����溯��ָ��*/
	}ST_UI;
	/**<IC������ָ��*/
	typedef struct 
	{
		int (*PowerUp)(void) ;											/**<�ϵ纯��ָ��*/
		int (*PowerDown)(void);											/**<�µ纯��ָ��*/
		int (*CommRW)(const unsigned char *,int,unsigned char *,int *);	/*��д����ָ��*/
	}STCOMM ;

	/**�ں˽���API�ص��б�*/
	typedef struct
	{
		void (*EXE_vSendOut)(char cIns,  int uiDataLen, char *pauData);		//�ں����		
		void (*EXE_vObtain)(char cIns,  int uiDataLen, char *pauData);		//�ں����� 
	}ST_EMV_EXPAND_INTERFACE;

	/**< ���ú���ָ��ӿ�*/
	LIB_EXPORT extern int EMV_SetFunP(ST_UI *stEMVUI,STCOMM *stEMVICComm,ST_EMV_EXPAND_INTERFACE*stInterface);
	/**< ----------------------------------------------------------------------------------------------------*/



	/**< --------------------------------------------------------------------------------------------------*/
	/*log��bug��λ*/
	typedef struct {
		int tick1[10];
		int count;
	}ST_TICK;
	LIB_EXPORT void init_tick(void);
	LIB_EXPORT void get_tick(ST_TICK*tickt);
	LIB_EXPORT void set_tick(int count,int ntype);
	LIB_EXPORT int get_count(void);
	/**<log�ļ�*/
	LIB_EXPORT extern int Init_TransLog(void);
	/**< --------------------------------------------------------------------------------------------------*/



	/**< --------------------------------------------------------------------------------------------------*/
	/**< ��ȡEMV����*/
	LIB_EXPORT extern int GetEmvData(char *pszTag,char *pszData,int *nDataLen);
	LIB_EXPORT extern int PackEmvData(char * packData, char * psTag,int nFlag,int * pnLen);
	
	/**< ��ȡEMV������*/
	LIB_EXPORT extern unsigned int Emv_GetErrCode(void);
	LIB_EXPORT extern int EmvGetErrCode(char cErrcode);
	/**< TVR TSI*/
	LIB_EXPORT extern YESORNO GetTVRIsSet(int nMask);
	LIB_EXPORT extern YESORNO GetTSIIsSet(int nMask);
	/**< --------------------------------------------------------------------------------------------------*/


	/**< --------------------------------------------------------------------------------------------------*/
	/*�ǽ��ں�ͨ�ú궨�弰API�ӿ�*/
	//�ǽ��ƿ������
	#define RF_GETCARD_POWERDOWN	1
	#define RF_GETCARD_REMOVE		2

	/* �ں����� / Kernel ID */	
	#define  EMV_KERNELID_DEFAULT          0x00 //Ĭ�ϳ�ʼֵ
	#define  EMV_KERNELID_MASTER           0x02 //�ǽ�EMV kernel2 / Master Card 
	#define  EMV_KERNELID_VISA             0x03 //�ǽ�EMV kernel3 / VISA
	#define  EMV_KERNELID_AMEX				0x04 //�ǽ�EMV kernel4 / AMEX
	#define  EMV_KERNELID_JCB				0x05 //�ǽ�EMV kernel5 / JCB 
	#define  EMV_KERNELID_DISCOVER			0x06 //�ǽ�EMV kernel6 / DISCOVER	 
	#define  EMV_KERNELID_UNIONPAY			0x07 //�ǽ�EMV kernel7 / UNIONPAY	
	//#define  EMV_KERNELID_RUPAY			0x08 //�ǽ�EMV RUPAY
	#define  EMV_KERNELID_RUPAY				0x0D //�ǽ�EMV RUPAY--�淶����
	/*	AID��ѡ�б��ṹ��*/
	typedef struct {
		unsigned char szAID_4F[16+1];			/**<AID	Ӧ�ñ�ʶ��*/
		int nAIDLen;							
		int nKernelId;							//KernelId
		unsigned char cPriority_87; 		    /**< Ӧ������Ȩ��ʶ��*/
		uchar ucExtendSelect[11+1];				//��չӦ��ѡ��
		int nExtendSelectLen;					//���11�ֽ�
	}ST_RF_ICCAID;
	
	/*�����⿨API�ӿ�*/
	/* AIDƥ��ṹ��*/
	typedef struct
	{
		uchar ucAid[MAXLEN_AID];	// AID
		uchar ucAidLen;				// AID����
		uchar ucPartSelect;			// ����ƥ���ʶ  0x00--��ȫƥ��  0x01-����ƥ��
		uchar ucKernelId;			// KernelId
		uchar ucCheckKernelIdSign;	// 0--ƥ�䲻У���ں�ID   1--ƥ��У���ں�ID	
	}EMV_stTermAIDList;
	/**< --------------------------------------------------------------------------------------------------*/

	/**< ---------------------------����API�ӿ� add by rsjian at 180417--------------------------------------------------------------------------*/
	/*paypass������ר�ò���*/
	//����ģʽ
	#define  EMV_FLOWTYPE_M_CHIP			0x21	//PayPass MchipоƬģʽ
	#define  EMV_FLOWTYPE_M_STRIPE			0x22	//PayPass Stripe����ģʽ
	#define  EMV_FLOWTYPE_RUPAY_LONG_TAP	0x23	//RUPAY Long Tap
	#define  EMV_FLOWTYPE_RUPAY_2_TAP		0x24	//RUPAY 2 Tap

	#define  EMV_FLAG_ADD					     0x01 //���� 
	#define  EMV_FLAG_DELETE				     0x02 //ɾ�� 
	#define  EMV_FLAG_CLEAR				     0x03 //�������	

	#define EMV_INS_SET_TORN					 0xA1 // ����������������
	#define EMV_INS_GET_TORN                    0xA2 // ��ȡ������������
	#define EMV_INS_DEL_TORN					 0xA3 // ֪ͨɾ��������¼
	#define EMV_INS_GET_TRAN_PARAM              0xA4 // ��ȡ���ײ���		
	#define EMV_INS_OUT_TLVDATA                 0xA5 // PAYPASS OUT�ź�����
	#define EMV_INS_MSG_TLVDATA				 0xA6 // PAYPASS MSG�ź�����
	#define EMV_INS_GET_CAPK					 0xA7 // ��ȡ��֤��Կ����
	#define EMV_INS_DISPLAY                     0xA8 // ���ͽ�����ʾ��Ϣ
	#define EMV_INS_SEND_DISC                   0xA9 // ���ʹ�TornRecord���Զ�������(PAYPASS)	
	#define EMV_INS_DISP_LED_BEEP				 0xB1 // paypass�ǽ����ܿ�Ƭ��������,��ʾ�̵�
	#define EMV_INS_ISS_CERT_RECOVER_CHECK			 0xB2 // �����л���֤����
	#define EMV_INS_ISS_PAN_BLACKLIST_CHECK		 0XB3	//���������
	#define EMV_INS_GET_TRAN_PARAM_FORM_ICS       0xB4  //��������config,���AMEX���ӵ�   
		/*�˿�����֤���ͱ�ʶ / CVM Flag*/
	#define  EMV_CVMFLAG_NOCVM              0x00 //����CVM��֤
	#define  EMV_CVMFLAG_OFFLINEPIN         0x01 //�ѻ�PIN
	#define  EMV_CVMFLAG_ONLINEPIN          0x02 //����PIN
	#define  EMV_CVMFLAG_SIGNATURE          0x03 //ǩ��
	#define  EMV_CVMFLAG_OLPIN_SIGN         0x04 //����PIN��ǩ��
	#define  EMV_CVMFLAG_ODV                0x05 //On device cardholder verification

		/* ��Ϣ��ʶ / Message ID*/
	#define EMV_MSGID_CARD_READ_OK				 0x17 // ������ɣ������߿�Ƭ�����������׳ɹ��� / Read card finished
	#define EMV_MSGID_TRY_AGAIN					 0x21 // ������ /  Try again
	#define EMV_MSGID_APPROVED					 0x03 // ������׼ /  Transaction approved
	#define EMV_MSGID_APPROVED_SIGN			 	 0x1A // ������׼������ǩ�� / Transaction approved and requesting signature
	#define EMV_MSGID_DECLINED				     0x07 // ���׾ܾ� / Transaction declined
	#define EMV_MSGID_ERR_OTH_CARD			     0x1C // ������ֹ���볢��������Ƭ / Transaction error, please try other card.
	#define EMV_MSGID_INSERT_CARD				 0x1D // ����뿨Ƭ /  Please insert IC card
	#define EMV_MSGID_SEE_PHONE					 0x20 // ��鿴�ֻ� /  Please check cell phone
	#define EMV_MSGID_AUTH_WAIT					 0x1B // ��Ȩ�ȴ� /  Waiting authorization
	#define EMV_MSGID_CLEAR_DISPLAY				 0x1E // �����ʾ /  Clear screen display

	typedef enum{	
		OUT_APDU_ERROR,				//APDU ͨѶ����
		OUT_APDU_STATUS_ERROR,		//APDU ��9000
		OUT_CARD_DATA_PARSING_ERROR, //��Ƭ���ݽ�������	
		OUT_CARD_DATA_MISSING_ERROR, //��Ƭ����ȱʧ
		OUT_CANDIDATE_LIST_EMPTY,	//��ѡ�б�Ϊ��
		OUT_USER_STOP,				//�û���ֹ
	}OUTCOME_ERR_TYPE;

	/*������Ϣ��ʾ�ṹ*/
	typedef struct
	{
		uchar ucMsgID;        // Message ID �ο��궨��
		uchar ucDataLen;      // ��Ϣ����
		uchar auData[30];     // ��Ϣ����
	}EMV_tDisplayMsg;


	//�����ն�֧�ֵ�AID��֧�����ӡ�ɾ��������0x01-����AID��0x02-ɾ��AID; 0x03-���AID
	//LIB_EXPORT extern int EMV_iManageAID(char cAction, EMV_stTermAIDList *pstAIDMatch);	
	LIB_EXPORT EMV_stTermAIDList * EMV_pGetTermAidist(void);
	
	/* ���չ�Կ֤��ṹ��*/
	typedef struct
	{
		char ucIndex;      // ��Կ����
		char auRID[5];     // RID
		char auSN[3];      // ֤�����к�
	}EMV_stRecCert;

	//�����ն�TLV��ǩ����
	LIB_EXPORT extern int SaveEmvListData(char *pszTLVList,int nDataLen);
	LIB_EXPORT extern int SaveEmvData(char *pszTag,char *pszData,int nLen,YESORNO bOverride);
	LIB_EXPORT extern int EMV_iSetCAPubKey(ST_CAPK*stCAPK);
	/**< --------------------------------------------------------------------------------------------------*/

#ifdef __cplusplus
}
#endif

#endif