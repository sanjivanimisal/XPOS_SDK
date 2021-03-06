#pragma once

enum{
	_START_PRIO = 0,
	_SYS_TIMER_TASK_PRIO,
	_AU_TASK_PRIO,
	_ATCINIT_TASK_PRIO,
	_WU_TASK_PRIO,
	_WIFIINIT_TASK_PRIO,
	_MODEM_RECV_TASK_PRIO ,
	_MODEM_PROC_TASK_PRIO ,
	_DEV_PROC_TASK_PRIO ,
	_TMS_TASK_PRIO,
	_RPC_TASK_PRIO,
	_BLOOTHI4_TASK_PRIO,
	_TASK_TEST_TASK_PRIO,
	_TASK_REFRESH_TASK_PRIO,	

	_APP_TASK_MIN_PRIO = 30,
	_APP_TASK_MAX_PRIO = 50,
	_STK_CHK_TASK_PRIO = 60,
};

#define _MODEM_RECV_TASK_SIZE	512
#define _MODEM_PROC_TASK_SIZE	512

#ifdef LCD_320_240
#define _ATCINIT_TASK_SIZE		512  
#define _AU_TASK_SIZE			512
#else
#define _ATCINIT_TASK_SIZE		320  //256+64
#define _AU_TASK_SIZE			256
#endif

#define _WIFIINIT_TASK_SIZE		512  
#define _WU_TASK_SIZE			512

#define _TIMER_TASK_SIZE		512
#define _TMS_TASK_SIZE			512
#define _STK_CHK_TASK_SIZE		128
#define _TASK_TEST_TASK_SZIE	256